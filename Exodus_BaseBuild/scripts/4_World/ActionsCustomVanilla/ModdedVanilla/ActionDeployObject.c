modded class ActionDeployObject
{

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		//Action not allowed if player has broken legs
		if (player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
			return false;
		
        ItemBase item_in_hands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());

		//Client
		if ( !GetGame().IsDedicatedServer() )
		{
			if ( player.IsPlacingLocal() )
			{
				if ( !player.GetHologramLocal().IsColliding() )
				{
					if ( item.CanBePlaced(player, player.GetHologramLocal().GetProjectionEntity().GetPosition()) )
					{
						return true;
					}
				}
			}
			return false;
		}
        if (item_in_hands.GetType() == "EXD_BB_Kit_UnderGroud")
        {
			if ( player.IsPlacingLocal() )
			{
				string surface_type;
				vector position;
				position = player.GetHologramLocal().GetProjectionEntity().GetPosition();
				
				GetGame().SurfaceGetType3D( position[0], position[1], position[2], surface_type );
				
				if ( GetGame().IsSurfaceDigable(surface_type) )
				{
					return true;
				}
            }
        }
        //TESTE
        Object targetObject = target.GetObject();
        if (player)
		{
            if (targetObject)
		    {
		    	Object UG_base = targetObject;
		    }
		    else if (item)
		    {
		    	UG_base = item;
		    }

            int UG_baseradius = 150;
            if (UG_base)
			{
				float distanciaUG_b;
				array<Object> objetoUB_g_regiao = new array<Object>; 
				array<CargoBase> cargoUB_g = new array<CargoBase>;
				
				GetGame().GetObjectsAtPosition(UG_base.GetPosition(), UG_baseradius, objetoUB_g_regiao, cargoUB_g);
				
				for (int a = 0; a < objetoUB_g_regiao.Count(); a++)
				{
					Object objectAdmin = objetoUB_g_regiao.Get(a);
					if (objectAdmin.GetType() == "EXD_UnderGroud")
					{
						EXD_UnderGroud under_base = EXD_UnderGroud.Cast(objectAdmin);
						GetGame().GetObjectsAtPosition(UG_base.GetPosition(), UG_baseradius, objetoUB_g_regiao, cargoUB_g);
						distanciaUG_b = vector.Distance(UG_base.GetPosition(), under_base.GetPosition());
                        if (item_in_hands.UnrestrictedItem())
                        {
                            return true;
                        } 
                        else if ( !item_in_hands.UnrestrictedItem() )
                        {
                            Param1<string> Msgparam4 = new Param1<string>(string.Format("Item restrito na região. Mova se para trás %1 metros.", UG_baseradius-Math.Round(distanciaUG_b)));
						    GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam4, true, player.GetIdentity());
                            return false;
                        }
						return false;
					}
				}
			}
        }
        //END TEST
		//Server
		return true;
	}

    override void OnEndServer(ActionData action_data)
    {
        if ( action_data.m_MainItem.IsKindOf("EXD_BaseKit") )
        {
            PlaceObjectActionData poActionData = PlaceObjectActionData.Cast(action_data);
            if (poActionData && !poActionData.m_AlreadyPlaced)
            {
                EntityAI entity_for_placing = action_data.m_MainItem;
                GetGame().ClearJuncture(action_data.m_Player, entity_for_placing);
                action_data.m_MainItem.SetIsBeingPlaced(false);
            
                if (GetGame().IsMultiplayer())
                {
                    action_data.m_Player.PlacingCancelServer();
                    action_data.m_MainItem.SoundSynchRemoteReset();
                }
                else
                {
                    //local singleplayer
                    action_data.m_Player.PlacingCancelLocal();
                    action_data.m_Player.LocalTakeEntityToHands(entity_for_placing);
                }
            }
            else
            {
                action_data.m_MainItem.SetIsDeploySound(false);
                action_data.m_MainItem.SetIsPlaceSound(false);
                action_data.m_MainItem.SoundSynchRemoteReset();
                /* Essa funçao permite nao ter que fazer vezes a funçao abaixo
                action_data.m_MainItem.IsKindOf( "M_Kit_Gun_Rack" )
                Ainda em teste */
                GetGame().ObjectDelete(action_data.m_MainItem);
                /* Funçao vanilla nao funcionaria pois temos a mini escada
                e ela nao é considerada um kit de construção */
                //if ( action_data.m_MainItem.IsBasebuildingKit() )
			    //{
			    //	action_data.m_MainItem.Delete();
			    //}
			    //else
			    //{
			    //	GetGame().ClearJuncture( action_data.m_Player, action_data.m_MainItem );
			    //}
            }
        }
        else
        {
            super.OnEndServer(action_data);
        }
    }
}
