class EXD_Floor_CarKit extends EXD_BaseKit
{	
	
	void EXD_Floor_CarKit()
	{
		DefineEncaixeHotizontal(true);
	}
	
	override string RequiredHologram()
    {
        return "EXD_Floor_Car_Hologram"; 
    }
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			EXD_Floor_Car exdfloorcar = EXD_Floor_Car.Cast( GetGame().CreateObjectEx( "EXD_Floor_Car", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			exdfloorcar.SetPosition( position );
			exdfloorcar.SetOrientation( orientation );
			exdfloorcar.SetAnimationPhase( "Hologram", 0 );

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
