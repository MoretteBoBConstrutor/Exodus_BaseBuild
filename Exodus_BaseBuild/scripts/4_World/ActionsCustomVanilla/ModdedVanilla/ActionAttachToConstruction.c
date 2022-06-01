modded class ActionAttachToConstruction
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		
		if ( target_entity && target_entity.CanUseConstruction() )
		{
			string selection = target_entity.GetActionComponentName( target.GetComponentIndex() );
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			int slot_id  = construction_action_data.GetAttachmentSlotFromSelection( player, target_entity, item, selection );
			BaseBuildingBase base_building;
			
			if ( slot_id != -1 )
			{
				base_building = BaseBuildingBase.Cast( target_entity );
				if ( base_building.CheckSlotVerticalDistance( slot_id, player ) && base_building.IsPlayerInside(player,"") )
				{
					construction_action_data.SetSlotId( slot_id );
					
					return true;
				}
				
				EXD_Base exdbase = EXD_Base.Cast( target_entity );
				if (  exdbase )
				{
					construction_action_data.SetSlotId( slot_id );
					
					return true;
				}
			}
			else if ( item.IsKindOf("CombinationLock") )
			{
				base_building = BaseBuildingBase.Cast( target_entity );
				
				//simpler hack
				/*construction_action_data.SetSlotId( InventorySlots.GetSlotIdFromString("Att_CombinationLock") );
				return true;*/
				
				InventoryLocation loc = new InventoryLocation;
				bool found = base_building.GetInventory().FindFreeLocationFor(item,FindInventoryLocationType.ATTACHMENT,loc);
				
				if (found)
				{
					//Print("slot name: " + InventorySlots.GetSlotName(loc.GetSlot()) );
					construction_action_data.SetSlotId( loc.GetSlot() );
					
					return true;
				}
			}
		}
		
		return false;
	}
}
