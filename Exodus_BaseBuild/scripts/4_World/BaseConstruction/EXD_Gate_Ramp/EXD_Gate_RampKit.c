class EXD_BB_Kit_GateRamp extends EXD_BaseKit
{	
	void EXD_BB_Kit_GateRamp()
	{
		DefineEncaixeVertical(true);
	}
	
	override string RequiredHologram()
    {
        return "EXD_Gate_Ramp_Hologram"; 
    }
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
	}
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			EXD_Gate_Ramp exdgateramp = EXD_Gate_Ramp.Cast( GetGame().CreateObjectEx( "EXD_Gate_Ramp", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			exdgateramp.SetPosition( position );
			exdgateramp.SetOrientation( orientation );
			exdgateramp.SetAnimationPhase( "Hologram", 0 );

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
