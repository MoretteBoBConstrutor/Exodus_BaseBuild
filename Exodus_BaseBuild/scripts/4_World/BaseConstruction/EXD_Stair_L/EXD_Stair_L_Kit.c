class EXD_BB_Kit_Stair_L extends EXD_BaseKit
{	
	void EXD_BB_Kit_Stair_L()
	{
		DefineEncaixeHotizontal(true);
	}
	
	override string RequiredHologram()
    {
        return "EXD_Stair_L_Hologram"; 
    }
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			EXD_Stair_L exdstairl = EXD_Stair_L.Cast( GetGame().CreateObjectEx( "EXD_Stair_L", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			exdstairl.SetPosition( position );
			exdstairl.SetOrientation( orientation );
			exdstairl.SetAnimationPhase( "Hologram", 0 );

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
