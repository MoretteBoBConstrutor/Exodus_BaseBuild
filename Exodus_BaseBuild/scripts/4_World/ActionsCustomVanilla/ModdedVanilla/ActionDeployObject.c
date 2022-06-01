modded class ActionDeployObject
{
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
