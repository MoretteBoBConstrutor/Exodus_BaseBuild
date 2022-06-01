class EXD_BB_Kit_Stair_Mini extends EXD_BaseKit
{	
	override string RequiredHologram()
    {
        return "EXD_Stair_Mini"; 
    }
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			EXD_Stair_Mini exd_stairmini = EXD_Stair_Mini.Cast( GetGame().CreateObjectEx( "EXD_Stair_Mini", position, ECE_PLACE_ON_SURFACE ) );
			exd_stairmini.SetPosition( position );
			exd_stairmini.SetOrientation( orientation );
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