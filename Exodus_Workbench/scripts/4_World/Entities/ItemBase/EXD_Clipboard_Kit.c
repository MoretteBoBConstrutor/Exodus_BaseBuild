class EXD_BB_Kit_Clipboard extends EXD_BaseKit
{    
    override string RequiredHologram()
    {
        return "EXD_Clipboard_Hologram"; 
    }
    
    override void OnVariablesSynchronized()
    {
        super.OnVariablesSynchronized();
    }
    
    override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
    {
        if ( GetGame().IsServer() )
        {
            Exodus_Workbench exd_wb = Exodus_Workbench.Cast( GetGame().CreateObjectEx( "Exodus_Workbench", GetPosition(), ECE_PLACE_ON_SURFACE ) );
            exd_wb.SetPosition( position );
            exd_wb.SetOrientation( orientation );
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
		AddAction(ActionPlaceObject);
	}
}

class EXD_Clipboard_Hologram extends ItemBase{};