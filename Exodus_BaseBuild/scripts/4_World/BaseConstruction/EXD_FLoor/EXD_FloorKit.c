class EXD_BB_Kit_Floor extends EXD_BaseKit
{	
	
	void EXD_BB_Kit_Floor()
	{
		DefineEncaixeHotizontal(true);
	}
	
	override string RequiredHologram()
    {
        return "EXD_Floor_Hologram"; 
    }
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			EXD_Floor exdfloor = EXD_Floor.Cast( GetGame().CreateObjectEx( "EXD_Floor", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			exdfloor.SetPosition( position );
			exdfloor.SetOrientation( orientation );
			exdfloor.SetAnimationPhase( "Hologram", 0 );

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
