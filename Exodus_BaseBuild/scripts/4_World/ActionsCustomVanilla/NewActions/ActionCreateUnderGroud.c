class ActionCreateUnderGroudCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(5);
	}
}

class ActionCreateUnderGroud: ActionContinuousBase
{
	void ActionCreateUnderGroud()
	{
		m_CallbackClass		= ActionCreateUnderGroudCB;
		m_CommandUID		= DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody			= true;
		m_StanceMask		= DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight	= UASoftSkillsWeight.ROUGH_LOW;
		m_Text = "Create Project";
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget	= new CCTNonRuined(UAMaxDistances.DEFAULT);
		m_ConditionItem		= new CCINonRuined();
	}
	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		//Action not allowed if player has broken legs
		if (player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
		{
			return false;
		}
		
		EXD_Base kit_underG = EXD_Base.Cast(target.GetObject());
		if (kit_underG)
		{
			if ( kit_underG.IsUnderGroud() )
			{
				return true;
			}
		}
		
		return false;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		Object target_object = action_data.m_Target.GetObject();
		target_object.GetGame().CreateObjectEx("EXD_UnderGroud_Part2", target_object.GetPosition(), ECE_PLACE_ON_SURFACE);
	}
}