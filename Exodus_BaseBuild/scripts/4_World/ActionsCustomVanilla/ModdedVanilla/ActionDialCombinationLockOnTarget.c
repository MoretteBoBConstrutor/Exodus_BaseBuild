modded class ActionDialCombinationLockOnTarget
{
	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
    {
        EXD_Base exdbase = EXD_Base.Cast( target.GetObject());
        
        if ( exdbase && exdbase.IsLocked() )
        {
            string selection = exdbase.GetActionComponentName( target.GetComponentIndex() );
            
            ConstructionActionData construction_action_data = player.GetConstructionActionData();
            construction_action_data.SetCombinationLock( exdbase.GetCombinationLock() );
            
            return true;
        }

		return false;
    }
}
