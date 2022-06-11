class EXD_Door extends EXD_Base
{
	override string GetConstructionKitType()
	{
		return "EXD_BB_Kit_Door";
	}
	
	override bool IsNormalPart()
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
			output = "Door";
			output.ToUpper();
			return true;
		}
		return false;
	}

	override void OpenFence()
	{
		//server or single player
		if ( GetGame().IsServer() )
		{
			float value = GATE_ROTATION_ANGLE_DEG;
			SetAnimationPhase( "Wall_Interact_Rotate", 				value );
			SetAnimationPhase( "Exd_door_t1_Rotate", 				value );
			SetAnimationPhase( "GateCamonet_Rotate", 				value );
			
			SetOpenedState( true );
			
			//regenerate navmesh
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, GATE_ROTATION_TIME_APPROX, false );
			
			//synchronize
			SynchronizeBaseState();
		}
		
		//client or single player
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			//play sound
			SoundGateOpenStart();
		}
	}
	
	override void CloseFence()
	{
		//server or single player
		if ( GetGame().IsServer() )
		{		
			float value = 0;
			SetAnimationPhase( "Wall_Interact_Rotate", 				value );
			SetAnimationPhase( "Exd_door_t1_Rotate", 				value );
			SetAnimationPhase( "GateCamonet_Rotate", 				value );

			SetOpenedState( false );
			
			//regenerate navmesh
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, GATE_ROTATION_TIME_APPROX, false );
			
			//synchronize
			SynchronizeBaseState();
		}
		
		//client or single player
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			//play sound
			SoundGateCloseStart();
			
			//add check
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( CheckFenceClosed, 0, true );
		}
	}
	
	protected void CheckFenceClosed()
	{
		if ( GetAnimationPhase( "Exd_door_t1_Rotate" ) == 0 )			//animation finished - closed
		{
			//client or single player
			if ( !GetGame().IsDedicatedServer() )
			{
				//play sound
				if ( this ) SoundGateCloseEnd();
			}
			UpdateBarbedWireAreaDamagePos(GetAnimationPhase( "Exd_door_t1_Rotate" ));
			//remove check
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Remove( CheckFenceClosed );
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDialCombinationLockOnTarget);
		AddAction(ActionNextCombinationLockDialOnTarget);
		AddAction(ActionOpenFence);
		AddAction(ActionCloseFence);
	}
}
