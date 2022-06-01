modded class ActionTakeMaterialToHandsSwitch
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		if ( target_entity && target_entity.CanUseConstruction() )
		{
			BaseBuildingBase base_building = BaseBuildingBase.Cast( target_entity );
			if(!base_building.IsPlayerInside(player,""))
				return false;

			ConstructionActionData construction_action_data = player.GetConstructionActionData();

			string main_part_name = target_entity.GetActionComponentName( target.GetComponentIndex() );
			construction_action_data.RefreshAttachmentsToDetach( target_entity, main_part_name );
			
			if ( construction_action_data.GetAttachmentsToDetachCount() > 1 )
			{
				EXD_Base exdbase = EXD_Base.Cast( target.GetObject() );
				if ( exdbase )
				{
					if ( !exdbase.IsIrregularPart() /* == false */ && exdbase.IsFacingPlayer( player, "EXD_Base" ) )
					{
						return false;
					}
				}
			}
		}
		return super.ActionCondition(player, target, item);
	}
}
