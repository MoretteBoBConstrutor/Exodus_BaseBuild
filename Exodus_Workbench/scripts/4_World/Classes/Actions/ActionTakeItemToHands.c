modded class ActionTakeItemToHands
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (GetGame().IsClient())
		{
			ItemBase ntarget = ItemBase.Cast(target.GetObject());
			if (ntarget && (player.m_CraftClasses.WorkbenchesClassnames.Find(ntarget.GetType()) + 1))
				return false;
		}
		return super.ActionCondition(player, target, item);
	}
}