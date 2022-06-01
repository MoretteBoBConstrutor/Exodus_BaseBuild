class EXD_Stair_L extends EXD_Base
{		
	override string GetConstructionKitType()
	{
		return "EXD_BB_Kit_Stair_L";
	}
	
	override bool IsNormalPart()
    {
        return true;
    }
	
	override bool IsIrregularPart()
	{
		return true;
	}
	
	override bool DistanceNormalPart( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance >= 2 )
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
	}
}
