class EXD_BB_Kit_Wall_Window extends EXD_BaseKit
{	
	void EXD_BB_Kit_Wall_Window()
	{
		DefineEncaixeVertical(true);
	}
	
	override string RequiredHologram()
    {
        return "EXD_Wall_Window_Hologram"; 
    }
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			EXD_Wall_Window exdwall_w = EXD_Wall_Window.Cast( GetGame().CreateObjectEx( "EXD_Wall_Window", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			exdwall_w.SetPosition( position );
			exdwall_w.SetOrientation( orientation );
			exdwall_w.SetAnimationPhase( "Hologram", 0 );

			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();
		}
	}
	
	override bool IsDeployable()
	{
		return true;
	}	
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
	}
}
