class EXD_BB_Kit_Door extends EXD_BaseKit
{	
	void EXD_BB_Kit_Door()
	{
		DefineEncaixeVertical(true);
	}
	
	override string RequiredHologram()
    {
        return "EXD_Door_Hologram"; 
    }
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
	}
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			EXD_Door exddoor = EXD_Door.Cast( GetGame().CreateObjectEx( "EXD_Door", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			exddoor.SetPosition( position );
			exddoor.SetOrientation( orientation );
			exddoor.SetAnimationPhase( "Hologram", 0 );

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
