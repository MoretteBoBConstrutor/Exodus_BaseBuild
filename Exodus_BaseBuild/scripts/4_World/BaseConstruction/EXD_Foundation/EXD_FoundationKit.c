class EXD_BB_Kit_Foundation extends EXD_BaseKit
{	
	
	void EXD_BB_Kit_Foundation()
	{
		DefineEncaixeHorizontalFundacao(true);
	}
	
	override string RequiredHologram()
    {
        return "EXD_Foundation_Hologram"; 
    }
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			EXD_Foundation exdfoundation = EXD_Foundation.Cast( GetGame().CreateObjectEx( "EXD_Foundation", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			exdfoundation.SetPosition( position );
			exdfoundation.SetOrientation( orientation );
			exdfoundation.SetAnimationPhase( "Hologram", 0 );

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
