modded class ActionRepairPart: ActionDismantlePart
{

	void ActionRepairPart()
	{
		m_CallbackClass = ActionRepairPartCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;	
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "#repair";
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ConstructionActionData construction_action_data = player.GetConstructionActionData();	
		ConstructionPart construction_part = construction_action_data.GetTargetPart();
		if ( player )
		{	
			if ( construction_part )
			{
				m_Text = "#repair" + " " + construction_part.GetName();
			}
		}
		else
		{
			m_Text = "#repair " + construction_action_data.GetTargetPart();
		}
	}

	override string GetText()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if ( player )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			ConstructionPart construction_part = construction_action_data.GetTargetPart();
			
			if ( construction_part )
			{
				return "#repair" + " " + construction_part.GetName();
			}
		}
		
		return "";
	}

    protected bool RepairCondition( PlayerBase player, ActionTarget target, ItemBase item, bool camera_check )
	{
		string zone_name;
		
		Object target_object = target.GetObject();
		if ( target_object && target_object.CanUseConstruction() )
		{
			string part_name = target_object.GetActionComponentName( target.GetComponentIndex() );
			
			BaseBuildingBase base_building = BaseBuildingBase.Cast( target_object );
			Construction construction = base_building.GetConstruction();
			ConstructionPart construction_part = construction.GetConstructionPart( part_name );
            EXD_Base exdbase = EXD_Base.Cast( target.GetObject() );
			ConstructionActionData construction_action_data = player.GetConstructionActionData();

			if ( construction_part )
			{
                if ( base_building.IsNormalPart() )
				{
                    if (!base_building.IsIrregularPart() )
					{
				        //camera and position checks
				        if ( !base_building.IsFacingPlayer( player, part_name ) && !player.GetInputController().CameraIsFreeLook() && base_building.HasProperDistance( construction_part.GetMainPartName(), player ) )
				        {
				        	//Camera check (client-only)
				        	if ( camera_check )
				        	{
				        		if ( GetGame() && ( !GetGame().IsDedicatedServer() ) )
				        		{
				        			if ( base_building.IsFacingCamera( part_name ) )
				        			{
				        				return false;
				        			}
				        		}
				        	}

				        	//damage check
				        	DamageSystem.GetDamageZoneFromComponentName(base_building,part_name,zone_name);
				        	if ( base_building.GetHealthLevel(zone_name) < GameConstants.STATE_WORN || base_building.GetHealthLevel(zone_name) == GameConstants.STATE_RUINED )
				        	{
				        		return false;
				        	}

				        	//materials check
				        	if ( !construction.HasMaterials(part_name,true) )
				        	{
				        		return false;
				        	}

				        	//ConstructionActionData construction_action_data = player.GetConstructionActionData();
				        	construction_action_data.SetTargetPart( construction_part );
				        	return true;
				        }
                    }
                    if( base_building.IsIrregularPart() )
					{
						if( exdbase )
						{
							if ( exdbase.DistanceNormalPart( "center", player ) )
							{
							    //damage check
				        	    DamageSystem.GetDamageZoneFromComponentName(base_building,part_name,zone_name);
				        	    if ( base_building.GetHealthLevel(zone_name) < GameConstants.STATE_WORN || base_building.GetHealthLevel(zone_name) == GameConstants.STATE_RUINED )
				        	    {
				        	    	return false;
				        	    }

				        	    //materials check
				        	    if ( !construction.HasMaterials(part_name,true) )
				        	    {
				        	    	return false;
				        	    }

				        	    //ConstructionActionData construction_action_data = player.GetConstructionActionData();
				        	    construction_action_data.SetTargetPart( construction_part );
				        	    return true;
							}
						}
						return false;
					}                  
                }
				if (!base_building.IsNormalPart())
				{
					if ( !base_building.IsFacingPlayer( player, part_name ) && !player.GetInputController().CameraIsFreeLook() && base_building.HasProperDistance( construction_part.GetMainPartName(), player ) )
				    {
				    	//Camera check (client-only)
				    	if ( camera_check )
				    	{
				    		if ( GetGame() && ( !GetGame().IsDedicatedServer() ) )
				    		{
				    			if ( base_building.IsFacingCamera( part_name ) )
				    			{
				    				return false;
				    			}
				    		}
				    	}
				    	//damage check
				    	DamageSystem.GetDamageZoneFromComponentName(base_building,part_name,zone_name);
				    	if ( base_building.GetHealthLevel(zone_name) < GameConstants.STATE_WORN || base_building.GetHealthLevel(zone_name) == GameConstants.STATE_RUINED )
				    	{
				    		return false;
				    	}
				    	//materials check
				    	if ( !construction.HasMaterials(part_name,true) )
				    	{
				    		return false;
				    	}
				    	//ConstructionActionData construction_action_data = player.GetConstructionActionData();
				    	construction_action_data.SetTargetPart( construction_part );
				    	return true;
				    }
				}				
			}
		}
		
		return false;
	}

};