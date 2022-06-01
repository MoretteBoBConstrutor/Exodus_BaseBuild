class EXD_BB_Kit_Floor_Delta extends EXD_BaseKit
{	
	void EXD_BB_Kit_Floor_Delta()
	{
		DefineEncaixeHotizontal(true);
	}
	
	override string RequiredHologram()
    {
        return "EXD_Floor_Delta_Hologram"; 
    }
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
	}
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			EXD_Floor_Delta exdfloordelta = EXD_Floor_Delta.Cast( GetGame().CreateObjectEx( "EXD_Floor_Delta", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			exdfloordelta.SetPosition( position );
			exdfloordelta.SetOrientation( orientation );
			exdfloordelta.SetAnimationPhase( "Hologram", 0 );

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
