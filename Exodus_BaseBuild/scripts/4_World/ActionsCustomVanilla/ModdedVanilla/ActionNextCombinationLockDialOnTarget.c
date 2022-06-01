//Mesmo script do Doors and Barricades, porem essa verçao é uma Modded da original e nao uma nova açao
modded class ActionNextCombinationLockDialOnTarget
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		if ( targetObject && targetObject.CanUseConstruction() )
		{
			EXD_Base exdbase = EXD_Base.Cast( targetObject);
			
			if ( exdbase && exdbase.IsLocked() && !player.GetItemInHands() )
			{
				string selection = exdbase.GetActionComponentName( target.GetComponentIndex() );
				
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				construction_action_data.SetCombinationLock( exdbase.GetCombinationLock() );
				
				return true;
			}
		}
		return super.ActionCondition ( player, target, item );
	}
}
