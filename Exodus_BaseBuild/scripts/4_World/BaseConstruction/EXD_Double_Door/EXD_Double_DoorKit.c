class EXD_BB_Kit_Double_Door extends EXD_BaseKit
{	
	void EXD_BB_Kit_Double_Door()
	{
		DefineEncaixeVertical(true);
	}
	
	override string RequiredHologram()
    {
        return "EXD_Double_Door_Hologram"; 
    }
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			EXD_Double_Door exddoubledoor = EXD_Double_Door.Cast( GetGame().CreateObjectEx( "EXD_Double_Door", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			exddoubledoor.SetPosition( position );
			exddoubledoor.SetOrientation( orientation );
			exddoubledoor.SetAnimationPhase( "Hologram", 0 );

			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
	}
}
