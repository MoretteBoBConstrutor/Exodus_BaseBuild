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

            int UG_baseradius = 30;
            if (UG_base)
			{
				float distanceAdmin;
				array<Object> nearest_objects_admin = new array<Object>;
				array<CargoBase> proxy_cargos_admin = new array<CargoBase>;
				
				GetGame().GetObjectsAtPosition(UG_base.GetPosition(), UG_baseradius, nearest_objects_admin, proxy_cargos_admin);
				
				for (int a = 0; a < nearest_objects_admin.Count(); a++)
				{
					Object objectAdmin = nearest_objects_admin.Get(a);
					if (objectAdmin.GetType() == "EXD_UnderGroud")
					{
						EXD_UnderGroud under_base = EXD_UnderGroud.Cast(objectAdmin);
						GetGame().GetObjectsAtPosition(UG_base.GetPosition(), UG_baseradius, nearest_objects_admin, proxy_cargos_admin);
						distanceAdmin = vector.Distance(UG_base.GetPosition(), under_base.GetPosition());
						//Param1<string> Msgparam4 = new Param1<string>(string.Format("Building here is prohibited. Move back %1 meters.", UG_baseradius-Math.Round(distanceAdmin)));
						//GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam4, true, player.GetIdentity());
                        if (item_in_hands.UnrestrictedItem())
                        {
                            return true;
                        } 
                        else if ( !item_in_hands.UnrestrictedItem() )
                        {
                            Param1<string> Msgparam4 = new Param1<string>(string.Format("Item restrito na região. Mova se para trás %1 metros.", UG_baseradius-Math.Round(distanceAdmin)));
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
