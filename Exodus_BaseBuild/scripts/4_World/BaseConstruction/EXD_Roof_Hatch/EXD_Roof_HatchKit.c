class EXD_BB_Kit_Roof_Hatch extends EXD_BaseKit
{	
	
	void EXD_BB_Kit_Roof_Hatch()
	{
		DefineEncaixeHotizontal(true);
	}
	
	override string RequiredHologram()
    {
        return "EXD_Roof_Hatch_Hologram"; 
    }
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			EXD_Roof_Hatch exdfloorh = EXD_Roof_Hatch.Cast( GetGame().CreateObjectEx( "EXD_Roof_Hatch", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			exdfloorh.SetPosition( position );
			exdfloorh.SetOrientation( orientation );
			exdfloorh.SetAnimationPhase( "Hologram", 0 );

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
