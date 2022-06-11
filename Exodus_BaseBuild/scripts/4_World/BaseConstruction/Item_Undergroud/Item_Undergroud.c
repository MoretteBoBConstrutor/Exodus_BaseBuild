class EXD_UnderGroud extends EXD_Base
{		
	override string GetConstructionKitType()
	{
		return "";
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
		
		RemoveAction(ActionDialCombinationLockOnTarget);
		RemoveAction(ActionNextCombinationLockDialOnTarget);
		RemoveAction(ActionOpenFence);
		RemoveAction(ActionCloseFence);
		AddAction(ActionTeleportUnderGroud);
		AddAction(ActionTeleportUnderGroudLeave);
	}

	override bool CanBePlaced( Man player, vector position )
	{
		string surface_type;
		GetGame().SurfaceGetType3D( position[0], position[1], position[2], surface_type );
		
		return GetGame().IsSurfaceDigable(surface_type);
	}
}
