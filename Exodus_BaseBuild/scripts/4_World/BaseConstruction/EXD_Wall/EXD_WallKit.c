class EXD_BB_Kit_Wall extends EXD_BaseKit
{	
	
	void EXD_BB_Kit_Wall()
	{
		DefineEncaixeVertical(true);
	}
	
	override string RequiredHologram()
    {
        return "EXD_Wall_Hologram"; 
    }
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			EXD_Wall exdwall = EXD_Wall.Cast( GetGame().CreateObjectEx( "EXD_Wall", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			exdwall.SetPosition( position );
			exdwall.SetOrientation( orientation );
			exdwall.SetAnimationPhase( "Hologram", 0 );

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
