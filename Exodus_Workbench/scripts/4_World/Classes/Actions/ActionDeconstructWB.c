class ActionDeconstructWB: ActionInteractBase
{
	void ActionDeconstructWB()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.INTERACTEXODUS);
		//m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return "Desmontar";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (GetGame().IsClient())
		{
			Exodus_Workbench wb = Exodus_Workbench.Cast(target.GetObject());
			if ( wb )
			{
				int attCount = wb.GetInventory().AttachmentCount();
				if (wb.HasAnyCargo() || (attCount!=0))
				{
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Exodus_Workbench wb = Exodus_Workbench.Cast(action_data.m_Target.GetObject());
		if (wb)
		{
			GetGame().CreateObject("EXD_BB_Kit_Clipboard", action_data.m_Player.GetPosition(), false);
			GetGame().ObjectDelete(wb);
		}
	}
}