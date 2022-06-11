class EXD_BB_Kit_UnderGroud extends EXD_BaseKit
{	
	void EXD_BB_Kit_Pillar()
	{
	}
	
    override bool IsUnderGroudProject()
    {
        return true;
    }

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}

	override string RequiredHologram()
    {
        return "EXD_UnderGroud_Hologram"; 
    }
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}
	
	override bool CanBePlaced( Man player, vector position )
	{
		string surface_type;
		GetGame().SurfaceGetType3D( position[0], position[1], position[2], surface_type );
		
		return GetGame().IsSurfaceDigable(surface_type);
	}

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			EXD_UnderGroud exdunderG = EXD_UnderGroud.Cast( GetGame().CreateObjectEx( "EXD_UnderGroud", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			exdunderG.SetPosition( position );
			exdunderG.SetOrientation( orientation );
			exdunderG.SetAnimationPhase( "Hologram", 0 );

			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();
		}
	}
	
	override bool IsDeployable()
	{
		return true;
	}	

	override bool UnrestrictedItem()
	{
		return false;
	}
};

class EXD_UnderGroud_Hologram extends ItemBase{};


