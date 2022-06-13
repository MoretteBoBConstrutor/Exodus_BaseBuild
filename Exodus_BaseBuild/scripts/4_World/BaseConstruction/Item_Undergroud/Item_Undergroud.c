class EXD_UnderGroud extends EXD_Base
{
	override string GetConstructionKitType()
	{
		return "EXD_BB_Kit_UnderGroud";
	}
	
	override bool IsNormalPart()
    {
        return true;
    }
	
	override bool IsIrregularPart()
	{
		return true;
	}

	override bool IsUnderGroud()
	{
		return true;
	}

	override bool GatePartConstruct()
	{
		return true;
	}

	override bool NameOverride(out string output)
	{
		if ( m_GateState != GATE_STATE_NONE )
		{
			output = "Porta";
			output.ToUpper();
			return true;
		}
		return false;
	}

	override bool DistanceNormalPart( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance >= 3 )
			{
				return false;
			}
		}
		return true;
	}

	override bool RaidDistanceIrregularPart( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance >= 5 )
			{
				return false;
			}
		}
		return true;
	}

 	override bool IsFacingPlayer( PlayerBase player, string selection )
	{
		return false;
	}
	
	override bool IsFacingCamera( string selection )
	{
		return false;
	}
	
	override bool HasProperDistance( string selection, PlayerBase player )
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDialCombinationLockOnTarget);
		AddAction(ActionNextCombinationLockDialOnTarget);
		AddAction(ActionOpenFence);
		AddAction(ActionCloseFence);
		AddAction(ActionTeleportUnderGroud);
		//AddAction(ActionTeleportUnderGroudLeave);
	}

	override bool CanBePlaced( Man player, vector position )
	{
		string surface_type;
		GetGame().SurfaceGetType3D( position[0], position[1], position[2], surface_type );
		
		return GetGame().IsSurfaceDigable(surface_type);
	}


	override void OpenFence()
	{
		//server or single player
		if ( GetGame().IsServer() )
		{
			float value = GATE_ROTATION_ANGLE_DEG;
			SetAnimationPhase( "Under_Door_Rotate", 				value );
			SetAnimationPhase( "GateCamonet_Rotate", 				value );
			
			SetOpenedState( true );
			
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, GATE_ROTATION_TIME_APPROX, false );
			
			SynchronizeBaseState();
		}
	}
	
	override void CloseFence()
	{
		if ( GetGame().IsServer() )
		{		
			float value = 0;
			SetAnimationPhase( "Under_Door_Rotate", 				value );
			SetAnimationPhase( "GateCamonet_Rotate", 				value );
			SetOpenedState( false );
		
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, GATE_ROTATION_TIME_APPROX, false );

			SynchronizeBaseState();
		}
	}
	
	protected void CheckFenceClosed()
	{
		if ( GetAnimationPhase( "Under_Door_Rotate" ) == 0 )			//animation finished - closed
		{	
			UpdateBarbedWireAreaDamagePos(GetAnimationPhase( "Under_Door_Rotate" ));
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Remove( CheckFenceClosed );
		}
	}
}


class Land_UnderGroud_Part extends Container_Base
{
	override bool CanPutInCargo( EntityAI parent )
    {
        if( !super.CanPutInCargo(parent) ) {return false;}        
        if ( GetNumberOfItems() == 0)
        {
            return false;
        }
        return false;
    }
    
    override bool CanPutIntoHands(EntityAI parent)
    {
        if( !super.CanPutIntoHands( parent ) )
        {
            return false;
        }
        if ( GetNumberOfItems() == 0 )
        {
            return false;
        }
        return false;
    }

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTeleportUnderGroudLeave);
	}
};

class Land_UnderGroud_LockPart extends Container_Base
{
	override bool CanPutInCargo( EntityAI parent )
    {
        if( !super.CanPutInCargo(parent) ) {return false;}        
        if ( GetNumberOfItems() == 0)
        {
            return false;
        }
        return false;
    }
    
    override bool CanPutIntoHands(EntityAI parent)
    {
        if( !super.CanPutIntoHands( parent ) )
        {
            return false;
        }
        if ( GetNumberOfItems() == 0 )
        {
            return false;
        }
        return false;
    }
};

