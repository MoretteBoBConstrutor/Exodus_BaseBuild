modded class PlayerBase
{
    ref CraftClasses m_CraftClasses;
    ref array<EntityAI> CargoItems;
    ref map<string, int> DeletItems;
    ItemBase m_Workbench;

    bool        CanCraft;

    void PlayerBase()
    {
        CargoItems = new array<EntityAI>();
        DeletItems = new map<string, int>();

        CanCraft = true;
    }

    bool CanCraft()
    {
        return CanCraft;
    }

    void SetCraftDelay()
    {
        CanCraft = false;
        GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( AllowCraft, 2000, false);
    }

    void AllowCraft()
    {
        CanCraft = true;
    }

    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
        if (GetGame().IsClient())
        {
            if (rpc_type == CRPc.SERVER_SEND_MAIN_DATA)
            {ApplyServerData(ctx);}
            else if (rpc_type == CRPc.SERVER_SEND_CLOSE_MENU)
            {g_CraftManager.CloseCraft();}
        }
        if (GetGame().IsServer())
        {
            if (rpc_type == CRPc.CLIENT_REQUEST_CRAFT_ITEMS)
            CraftItems(ctx);
        }
    }

    void ApplyServerData(ParamsReadContext ctx)
    {
        Param1<ref CraftClasses> rpb;
        if (!ctx.Read(rpb)) return;

        m_CraftClasses = rpb.param1;
    }

    void CraftItems(ParamsReadContext ctx)
    {
        Param2<CraftItem, ItemBase> rpb;
        if (!ctx.Read(rpb)) return;
        m_Workbench = rpb.param2;
        if (!ScanItems(rpb.param1)) return;
        DeleteIngredients(rpb.param1, rpb.param2);
    }

    void DeleteIngredients(CraftItem arr, ItemBase work)
    {
        CraftItem crtItems = arr;
        ItemBase workbench = work;
        ItemBase cargoItemIB;
        CargoBase cargoBase;
        int cargoCount;

        cargoBase = workbench.GetInventory().GetCargo();
        cargoCount = cargoBase.GetItemCount();

        for (int k = 0; k < cargoCount; k++)
        {
            EntityAI crgEnt = cargoBase.GetItem(k);
            if (crgEnt && (!crgEnt.IsRuined() || crgEnt.IsWeapon()))
            {
                CargoItems.Insert(crgEnt);
            }
        }

        for (int i = 0; i < crtItems.CraftComponents.Count(); i++)
        {
            CraftComponent cc = crtItems.CraftComponents.Get(i);
            cargoItemIB = ItemBase.Cast(GetGame().CreateObject(cc.Classname, vector.Zero, false));
            if (cargoItemIB)
            {
                if ((QuantityConversions.HasItemQuantity(cargoItemIB) == 0) || cargoItemIB.IsInherited(Magazine))
                {
                    ItemWithoutQuantity(cc);
                }
                else
                {
                    ItemWithCount(cc, workbench);
                }

                GetGame().ObjectDelete(cargoItemIB);
            }
        }
        CargoItems.Clear();
        DeletItems.Clear();
        GiveResults(arr);
    }

    void GiveResults(CraftItem itemData)
    {
        CraftItem cragtItem = itemData;
        ItemBase itemReward;
        ItemBase tempIB;
        Magazine pileReward;
        string resultType;
        float needQuantity;
        float q_cur, q_min, q_max;

        resultType = cragtItem.Result;
        needQuantity = cragtItem.ResultCount;

        tempIB = ItemBase.Cast(GetGame().CreateObject(resultType, vector.Zero, false));
        if (!tempIB)
            return;

        QuantityConversions.GetItemQuantity(tempIB, q_cur, q_min, q_max)
        tempIB.Delete();

		if (!q_max) q_max = 1;

        while (needQuantity)
        {
            if (q_max < needQuantity)
            {
                itemReward = ItemBase.Cast(GetGame().CreateObject(resultType, this.GetPosition(), false));
                needQuantity -= q_max;
            }
            else
            {
                itemReward = ItemBase.Cast(GetGame().CreateObject(resultType, this.GetPosition(), false));
                if (Class.CastTo(pileReward, itemReward))
                {
                    pileReward.ServerSetAmmoCount(needQuantity);
                }
                else
                {
                    itemReward.SetQuantity(needQuantity);
                }
                needQuantity = 0;
            }
        }

    }

    void ItemWithoutQuantity(CraftComponent cc)
    {
        int amount = cc.Amount;
        string name = cc.Classname;
        int count = CargoItems.Count();
        for (int i = 0; i < count; i++)
        {
            EntityAI ent = CargoItems.Get(i);
            if (ent && (ent.GetType() == name))
            {
                ItemBase item = ItemBase.Cast(ent);
                if (item)
                {
                    if (cc.Destroy)
                    GetGame().ObjectDelete(item);    
                    else
                    item.AddHealth(cc.Changehealth);

                    amount--;
                    if (!amount) break;
                }
            }
        }
    }

    void ItemWithCount(CraftComponent cc, ItemBase workbench)
    {
        int amount = cc.Amount;
        string name = cc.Classname;
        int count = CargoItems.Count();
        for (int i = 0; i < count; i++)
        {
            EntityAI ent = CargoItems.Get(i);
            if (ent && (ent.GetType() == name))
            {
                ItemBase item = ItemBase.Cast(ent);
                if (item)
                {
                    if (cc.Destroy)
                    {
                        if (item.GetQuantity() > amount)
                        {
                            item.AddQuantity(-amount);
                            break;
                        }
                        else
                        {
                            amount -= item.GetQuantity();
                            GetGame().ObjectDelete(item); 
                        }
                    }
                    else
                    {
                        if (item.GetQuantity() > amount)
                        {
                            item.AddQuantity(-amount);
                            ItemBase tempItm = ItemBase.Cast(workbench.GetInventory().CreateInInventory(item.GetType()));
                            if (!tempItm)
                            tempItm = ItemBase.Cast(GetGame().CreateObject(item.GetType(), workbench.GetPosition(), false));
                            tempItm.SetQuantity(amount);
                            tempItm.AddHealth(cc.Changehealth);
                            break;
                        }
                        else
                        {
                            amount -= item.GetQuantity();
                            item.AddHealth(cc.Changehealth); 
                        }
                    }
                }
            }
        }
    }

    bool ScanItems(CraftItem arr)
    {
        if (!m_Workbench)
        {
            return false;
        }

        if (!m_Workbench.HasAnyCargo())
        {
            return false;
        }

        CargoBase cargoBase;
        int cargoCount;
        int quant;
        
        cargoBase = m_Workbench.GetInventory().GetCargo();
        cargoCount = cargoBase.GetItemCount();
        for (int c = 0; c < cargoCount; c++)
        {
            ItemBase cargoItemIB;
			if ( Class.CastTo(cargoItemIB, cargoBase.GetItem(c)) && cargoItemIB.IsItemBase() )
            {
                if (cargoItemIB.IsRuined()) continue;
                
                if (cargoItemIB.HasQuantity())
                {
                    quant = cargoItemIB.GetQuantity();
                }
                else
                {
                    quant = 1;
                }

                if (!DeletItems.Contains(cargoItemIB.GetType()))
                {
                    DeletItems.Insert(cargoItemIB.GetType(), quant);
                }
                else
                {
                    int nowQuant = DeletItems.Get(cargoItemIB.GetType());
                    DeletItems.Set(cargoItemIB.GetType(), (nowQuant + quant));
                }
            }
        }

        for (int i = 0; i < arr.CraftComponents.Count(); i++)
        {
            CraftComponent cc = arr.CraftComponents.Get(i);
            int count = DeletItems.Get(cc.Classname);
            if ( count < cc.Amount )
            {return false;}
        }
        DeletItems.Clear();
        return true;
    }

    /*override void Init()
    {
		if ( !GetGame().IsServer() || !GetGame().IsMultiplayer() )
		{
			DayzPlayerItemBehaviorCfg     toolsOneHanded = new DayzPlayerItemBehaviorCfg;
			toolsOneHanded.SetToolsOneHanded();

			DayzPlayerItemBehaviorCfg   heavyItemBehaviour = new DayzPlayerItemBehaviorCfg;
			heavyItemBehaviour.SetHeavyItems();

			DayzPlayerItemBehaviorCfg     twoHanded = new DayzPlayerItemBehaviorCfg;
			twoHanded.SetTwoHanded();

			//GetDayZPlayerType().AddItemInHandsProfileIK("BPGrinder", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", twoHanded,		"dz/anims/anm/player/ik/two_handed/BatteryCar.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("Exodus_Workbench", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,               "dz/anims/anm/player/ik/heavy/55galDrum.anm");
			//GetDayZPlayerType().AddItemInHandsProfileIK("BPDrill", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,                      "dz/anims/anm/player/ik/heavy/tent_party_packed.anm");
			//GetDayZPlayerType().AddItemInHandsProfileIK("BPCutting_saw", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,                      "dz/anims/anm/player/ik/heavy/tent_party_packed.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("", "dz/anims/workspaces/player/player_main/player_main_2h.asi", twoHanded,                           "dz/anims/anm/player/ik/two_handed/tent_medium_packed.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("", "dz/anims/workspaces/player/player_main/player_main_2h.asi", twoHanded,                           "dz/anims/anm/player/ik/two_handed/tent_medium_packed.anm");
        }
        super.Init();         
    }*/
}