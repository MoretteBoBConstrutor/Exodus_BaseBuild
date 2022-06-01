class ActionFoldLadderCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 5 );
	}
}

class ActionFoldLadder: ActionContinuousBase
{
	void ActionFoldLadder()
	{
		m_CallbackClass = ActionFoldLadderCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{	
		
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINotPresent;
	}
		
	override string GetText()
	{
		return "Desmontar";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Object targetObject = target.GetObject();
		
		if (targetObject.IsKindOf("EXD_Stair_Mini"))
		{
			return true;
		}
		return false;
	}
	
	override void OnFinishProgressServer(ActionData action_data)
	{
		Object targetObject = action_data.m_Target.GetObject();
		if (targetObject.IsInherited(EXD_Stair_Mini))
		{
			Object m_Object;
			if (GetGame().IsServer())
			{
				m_Object = GetGame().CreateObject("EXD_BB_Kit_Stair_Mini", targetObject.GetPosition(), false);
				m_Object.SetPosition(action_data.m_Player.GetPosition());
				GetGame().ObjectDelete(action_data.m_Target.GetObject());
			}
		}
	}
}
