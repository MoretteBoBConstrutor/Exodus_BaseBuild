modded class MiscGameplayFunctions
{
	override static bool ComplexBuildCollideCheckClient( PlayerBase player, ActionTarget target, ItemBase item, string partName = "" )
	{
		BaseBuildingBase base_building = BaseBuildingBase.Cast( target.GetObject() );
		if (base_building && !base_building.IsNormalPart() /* == false */)
		{
			Construction construction = base_building.GetConstruction();

			if ( construction && BuildCondition( player, target, item, false ))
			{
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				if (partName == "")
					partName = construction_action_data.GetCurrentBuildPart().GetPartName();
				return !construction.IsColliding( partName );
			}
		}
		if (base_building && base_building.IsNormalPart())
		{
			Construction constructionEXD = base_building.GetConstruction();
			if ( constructionEXD && BuildCondition( player, target, item, false ))
			{
				ConstructionActionData construction_action_dataEXD = player.GetConstructionActionData();
				if (partName == "")
					partName = construction_action_dataEXD.GetCurrentBuildPart().GetPartName();
				return true;
			}
		}
		return false;
	}

	override static bool BuildCondition( PlayerBase player, ActionTarget target, ItemBase item, bool camera_check )
	{
		if ( player && !player.IsLeaning() )
		{
			Object targetObject = target.GetObject();
			if ( targetObject && targetObject.CanUseConstruction() )
			{
				BaseBuildingBase base_building = BaseBuildingBase.Cast( targetObject );
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				construction_action_data.SetTarget( targetObject );

				string main_part_name = targetObject.GetActionComponentName( target.GetComponentIndex() );

				if ( GetGame().IsMultiplayer() || GetGame().IsServer() )
				{
					construction_action_data.RefreshPartsToBuild( main_part_name, item, !targetObject.CanUseHandConstruction() );
				}
				ConstructionPart construction_part = construction_action_data.GetCurrentBuildPart();

				//Debug
				/*
				if ( construction_part )
				{
					Construction construction = base_building.GetConstruction();	
					construction.IsColliding( construction_part.GetPartName() );
				}
				*/

				if ( base_building && !base_building.IsNormalPart() && construction_part )
				{
					//camera and position checks
					bool position_check = ( base_building.MustBeBuiltFromOutside() && !base_building.IsPlayerInside(player, construction_part.GetMainPartName()) ) || ( !base_building.MustBeBuiltFromOutside() && base_building.IsPlayerInside(player, construction_part.GetMainPartName()) );
					if ( position_check && !player.GetInputController().CameraIsFreeLook() )
					{
						//Camera check (client-only)
						if ( camera_check )
						{
							if ( GetGame() && ( !GetGame().IsDedicatedServer() ) )
							{
								return !base_building.IsFacingCamera( construction_part.GetMainPartName() );
							}
						}

						return true;
					}
				}
				if ( base_building && base_building.IsNormalPart() && construction_part )
				{
					return true;
				}
			}
		}
		return false;
	}
};