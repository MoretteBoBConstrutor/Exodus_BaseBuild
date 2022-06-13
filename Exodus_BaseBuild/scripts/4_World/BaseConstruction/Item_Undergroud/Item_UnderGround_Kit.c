class EXD_BB_Kit_UnderGroud extends EXD_BaseKit
{	
	protected Object								Land_underground;
	protected Object								Land_underground_lockedpart;

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
			/*
			//Object CreateObject( string type, vector pos, bool create_local = false, bool init_ai = false, bool create_physics = true );
			//GetGame().CreateObjectEx(item.name, vector.ArrayToVec(item.pos), ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS);
			//Furniture_Shelf_Kit1 = GetGame().CreateObject("Land_UnderGroud_Part", GetPosition(), false, false, true );
			//Land_underground = GetGame().CreateObjectEx("Land_UnderGroud_Part", GetPosition(), ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS );
			Land_Tisy_Garages Land_UnderGroud_Part
			*/
			Land_underground = GetGame().CreateObject("Land_UnderGroud_Part", GetPosition() );
			Land_underground.SetPosition( position + "0 1200 0" );
			Land_underground.SetOrientation( orientation );

			Land_underground_lockedpart = GetGame().CreateObject("Land_UnderGroud_LockPart", GetPosition() );
			Land_underground_lockedpart.SetPosition( position + "0 1200 0" );
			Land_underground_lockedpart.SetOrientation( orientation );

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


