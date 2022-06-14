modded class UAMaxDistances
{
	const float INTERACTEXODUS = 1.5;
};


class ActionInteractWithWorkbench : ActionInteractBase
{
	void ActionInteractWithWorkbench()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.INTERACTEXODUS);
		//m_ConditionTarget = new CCTNone; UAMaxDistances.DEFAULT
	} 

	override string GetText()
	{
		return "Abrir";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (GetGame().IsClient())
		{
			Exodus_Workbench ntarget = Exodus_Workbench.Cast(  target.GetObject() );
			if(  ntarget )
			{
				return true;
			}
			return false;
		}
		return true;
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		Exodus_Workbench ntarget = Exodus_Workbench.Cast( action_data.m_Target.GetObject() );
		string message;
		if ( ntarget)
		{
			g_CraftManager.SetWorkbench(ntarget);
			g_CraftManager.RequestCraft();
		}
	}	
}