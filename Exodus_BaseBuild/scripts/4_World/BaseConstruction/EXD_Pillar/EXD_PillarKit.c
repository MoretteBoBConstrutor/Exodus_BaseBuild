class EXD_BB_Kit_Pillar extends EXD_BaseKit
{	
	void EXD_BB_Kit_Pillar()
	{
		DefineEncaixeVerticalPilares(true);
	}
	
	override string RequiredHologram()
    {
        return "EXD_Pillar_Hologram"; 
    }
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			EXD_Pillar exdpillar = EXD_Pillar.Cast( GetGame().CreateObjectEx( "EXD_Pillar", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			exdpillar.SetPosition( position );
			exdpillar.SetOrientation( orientation );
			exdpillar.SetAnimationPhase( "Hologram", 0 );

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
