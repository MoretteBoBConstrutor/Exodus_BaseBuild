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

	override void SetActions()
	{
		super.SetActions();
		
		RemoveAction(ActionDialCombinationLockOnTarget);
		RemoveAction(ActionNextCombinationLockDialOnTarget);
		RemoveAction(ActionOpenFence);
		RemoveAction(ActionCloseFence);
	}
}
