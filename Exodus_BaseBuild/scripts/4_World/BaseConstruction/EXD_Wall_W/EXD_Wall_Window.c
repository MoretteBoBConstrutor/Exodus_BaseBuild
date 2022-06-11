class EXD_Wall_Window extends EXD_Base
{
	override string GetConstructionKitType()
	{
		return "EXD_BB_Kit_Wall_Window";
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
			output = "Window";
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
			SetAnimationPhase( "Exd_wall_w_door_t1_Rotate", 				value );

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
			SetAnimationPhase( "Exd_wall_w_door_t1_Rotate", 				value );

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
		if ( GetAnimationPhase( "Exd_wall_w_door_t1_Rotate" ) == 0 )			//animation finished - closed
		{
			//client or single player
			if ( !GetGame().IsDedicatedServer() )
			{
				//play sound
				if ( this ) SoundGateCloseEnd();
			}
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
