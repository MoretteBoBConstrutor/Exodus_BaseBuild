modded class ActionOpenFence
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if ( targetObject && targetObject.CanUseConstruction() )
		{
			Fence fence = Fence.Cast( targetObject );
			
			if ( fence && fence.CanOpenFence() )
			{
				array<string> selections = new array<string>;
				targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);
				
				for ( int i = 0; i < selections.Count(); i++ )
				{
					if ( selections[i] == SELECTION_INTERACT )
						return true;
				}
			}

			EXD_Base exdbase = EXD_Base.Cast( targetObject );

			if ( exdbase && exdbase.CanOpenFence() )
			{
				return true;
			}
		}
		return super.ActionCondition(player, target, item);
	}

	//override void OnStartServer( ActionData action_data )
	//{
	//	Fence fence = Fence.Cast( action_data.m_Target.GetObject() );
	//	fence.OpenFence();
	//	//Nao necessario pois estamos usando como base a fence
	//	/* EXD_Base exdbase = EXD_Base.Cast( action_data.m_Target.GetObject() );
	//	exdbase.OpenFence(); */
	//}
}

modded class ActionCloseFence
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if ( targetObject && targetObject.CanUseConstruction() )
		{
			EXD_Base exdbase = EXD_Base.Cast( target.GetObject() );

			if ( exdbase && exdbase.CanCloseFence() )
			{
				return true;
			}
		}
		
		return super.ActionCondition(player, target, item);
	};
};
