class EXD_Brourette extends Container_Base
{
	override bool CanPutIntoHands(EntityAI parent)
	{
		return true;
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		if (!super.CanPutInCargo(parent))
		{
			return false;
		}
		if ( GetHealthLevel() == GameConstants.STATE_RUINED )
		{
			return false;
		}
		if ( GetNumberOfItems() == 0 && IsEmpty())
        {
            return true;
        }
		return false;
	}

	override bool CanReceiveItemIntoCargo( EntityAI item )
	{
		if ( GetHealthLevel() == GameConstants.STATE_RUINED )
			return false;

		return super.CanReceiveItemIntoCargo( item );
	}

	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		if ( GetHealthLevel() == GameConstants.STATE_RUINED )
			return false;
		
		return super.CanReceiveAttachment(attachment, slotId);
	}

	override bool CanLoadAttachment( EntityAI attachment )
	{
		if ( GetHealthLevel() == GameConstants.STATE_RUINED )
			return false;
		
		return super.CanLoadAttachment(attachment);
	}

    bool ShowPlank()
    {
        int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString("Material_WoodenPlanks");
		ItemBase materials_plank = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
        if ( materials_plank )
		{
			return true;
		}
        return false;
    }

    bool ShowLog()
    {
        int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString("Material_L1_WoodenLogs");
		ItemBase materials_logs = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
        if ( materials_logs )
		{
			return true;
		}
        return false;
    }

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
	
		if (ShowLog() == true)
		{
			SetAnimationPhase("ShowLog", 0);
		}
		if (ShowPlank() == true)
		{
			SetAnimationPhase("ShowPlank", 0);
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if (ShowLog() == false)
		{
			SetAnimationPhase("ShowLog", 1);
		}
		if (ShowPlank() == false)
		{
			SetAnimationPhase("ShowPlank", 1);
		}
	}

}