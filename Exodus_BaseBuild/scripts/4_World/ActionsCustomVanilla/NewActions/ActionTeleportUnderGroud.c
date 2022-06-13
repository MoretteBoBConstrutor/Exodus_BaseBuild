//class ActionTeleportUnderGroud: ActionInteractBase
//{
//	void ActionTeleportUnderGroud()
//	{
//		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE; //CMD_ACTIONMOD_PICKUP_HANDS CMD_ACTIONMOD_INTERACTONCE
//		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
//		m_HUDCursorIcon = CursorIcons.CloseHood;
//	}
//
//	override bool HasProgress()
//	{
//		return false;
//	}
//
//    override void CreateConditionComponents()  
//	{
//		m_ConditionItem = new CCINone;
//        m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
//	}
//
//	override string GetText()
//	{
//		return " Enter ";
//	}
//
//	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
//	{
//		Object targetObject = target.GetObject();
//		if ( targetObject && targetObject.CanUseConstruction() )
//		{
//			EXD_Base exdbase = EXD_Base.Cast( targetObject );
//			array<string> selections = new array<string>;
//			targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);
//
//			if ( exdbase && exdbase.IsUnderGroud() && exdbase.IsOpened() && exdbase.HasFullyConstructedGate())
//			{
//				for ( int i = 0; i < selections.Count(); i++ )
//				{
//                    if ( selections[i] == "under_entrance" )
//					{
//						/* if(exdbase.GetConstruction().GetConstructionPart("Under_base").IsBuilt() )
//						return true; */
//						if (exdbase.GetConstruction().GetConstructionPart("upgradelock_t1").IsBuilt())
//						{
//							return true;
//						}
//					}
//					return false;
//				}
//			}
//			else if (exdbase && exdbase.IsUnderGroud() && !exdbase.HasFullyConstructedGate())
//			{
//				for ( int j = 0; j < selections.Count(); j++ )
//				{
//                    if ( selections[j] == "under_entrance" )
//					{
//						//if(exdbase.GetConstruction().GetConstructionPart("Under_base").IsBuilt() )
//						if (exdbase.GetConstruction().GetConstructionPart("upgradelock_t1").IsBuilt())
//						{
//							return true;
//						}
//					}
//					return false;
//				}
//			}
//		}
//		return false;
//	}
//
//	override void OnExecuteServer( ActionData action_data )
//	{
//		PlayerBase player = PlayerBase.Cast( action_data.m_Player );
//        Object target_object = action_data.m_Target.GetObject();
//        EXD_Base exdbase = EXD_Base.Cast( target_object );
//        if( exdbase.IsUnderGroud() )
//		{
//		    //vector pos = target_object.GetPosition() + "0 101.5 0"; "0 1205 0" 0 802 0
//			vector pos = target_object.GetPosition() + "0 1202 0";
//            player.SetPosition( pos );
//            Print("Teleporte para dentro");
//		}
//	}
//}

/* class ActionTeleportUnderGroudLeave: ActionInteractBase
{
	void ActionTeleportUnderGroudLeave()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}

    override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return " Leave ";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        //Object targetObject = target.GetObject();
		//if ( targetObject && targetObject.CanUseConstruction() )
		//{
		//	EXD_Base exdbase = EXD_Base.Cast( targetObject );
		//	array<string> selections = new array<string>;
		//	targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);
//
		//	if ( exdbase && exdbase.IsUnderGroud() && exdbase.IsOpened() && exdbase.HasFullyConstructedGate())
		//	{
		//		for ( int i = 0; i < selections.Count(); i++ )
		//		{
        //            if ( selections[i] == "under_leave" )
		//				return true;
		//		}
		//		return false;
		//	}
		//	else if (exdbase && exdbase.IsUnderGroud() && !exdbase.HasFullyConstructedGate())
		//	{
		//		for ( int j = 0; j < selections.Count(); j++ )
		//		{
        //            if ( selections[j] == "under_leave" )
		//				return true;
		//		}
		//		return false;
		//	}
		//}

		Object targetObject = target.GetObject();
		Land_UnderGroud_Part under_part = Land_UnderGroud_Part.Cast( targetObject );
		if ( under_part )
		{
			array<string> selections = new array<string>;
			targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);
			for ( int i = 0; i < selections.Count(); i++ )
			{
                if ( selections[i] == "under_leave" )
					return true;
			}
			return false;
		}
		
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		PlayerBase player = PlayerBase.Cast( action_data.m_Player );
        Object target_object = action_data.m_Target.GetObject();
        Land_UnderGroud_Part under_part = Land_UnderGroud_Part.Cast( target_object );
        if( under_part )
		{
			vector pos = target_object.GetPosition();
            player.SetPosition( pos - "0 1200 0" );
            Print("Teleporte para Fora");
		}
	}

} */
/////TESTE
class ActionTeleportLeaveCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(3);
	}
}
class ActionTeleportUnderGroudLeave: ActionContinuousBase
{
	void ActionTeleportUnderGroudLeave()
	{
		m_CallbackClass = ActionTeleportLeaveCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT; //CMD_ACTIONMOD_OPENITEM
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT; //DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return " Leave ";
	}

	override bool CanContinue( ActionData action_data )
	{
		return true;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		Land_UnderGroud_Part under_part = Land_UnderGroud_Part.Cast( targetObject );
		if ( under_part )
		{
			array<string> selections = new array<string>;
			targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);
			for ( int i = 0; i < selections.Count(); i++ )
			{
                if ( selections[i] == "under_leave" )
					return true;
			}
			return false;
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		PlayerBase player = PlayerBase.Cast( action_data.m_Player );
        Object target_object = action_data.m_Target.GetObject();
        Land_UnderGroud_Part under_part = Land_UnderGroud_Part.Cast( target_object );
        if( under_part )
		{
			vector pos = target_object.GetPosition();
            player.SetPosition( pos - "0 1200 0" );
            Print("Teleporte para Fora");
		}
	}
}

class ActionTeleportEnterCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(3);
	}
}
class ActionTeleportUnderGroud: ActionContinuousBase
{
	void ActionTeleportUnderGroud()
	{
		m_CallbackClass = ActionTeleportEnterCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT; //CMD_ACTIONMOD_OPENITEM
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH; //DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
	    m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}

	override string GetText()
	{
		return " Enter ";
	}

	override bool CanContinue( ActionData action_data )
	{
		return true;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if ( targetObject && targetObject.CanUseConstruction() )
		{
			EXD_Base exdbase = EXD_Base.Cast( targetObject );
			array<string> selections = new array<string>;
			targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);

			if ( exdbase && exdbase.IsUnderGroud() && exdbase.IsOpened() && exdbase.HasFullyConstructedGate())
			{
				for ( int i = 0; i < selections.Count(); i++ )
				{
                    if ( selections[i] == "under_entrance" )
					{
						/* if(exdbase.GetConstruction().GetConstructionPart("Under_base").IsBuilt() )
						return true; */
						if (exdbase.GetConstruction().GetConstructionPart("upgradelock_t1").IsBuilt())
						{
							return true;
						}
					}
					return false;
				}
			}
			else if (exdbase && exdbase.IsUnderGroud() && !exdbase.HasFullyConstructedGate())
			{
				for ( int j = 0; j < selections.Count(); j++ )
				{
                    if ( selections[j] == "under_entrance" )
					{
						//if(exdbase.GetConstruction().GetConstructionPart("Under_base").IsBuilt() )
						if (exdbase.GetConstruction().GetConstructionPart("upgradelock_t1").IsBuilt())
						{
							return true;
						}
					}
					return false;
				}
			}
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		PlayerBase player = PlayerBase.Cast( action_data.m_Player );
        Object target_object = action_data.m_Target.GetObject();
        EXD_Base exdbase = EXD_Base.Cast( target_object );
        if( exdbase.IsUnderGroud() )
		{
		    //vector pos = target_object.GetPosition() + "0 101.5 0"; "0 1205 0" 0 802 0
			vector pos = target_object.GetPosition() + "0 1202 0";
            player.SetPosition( pos );
            Print("Teleporte para dentro");
		}
	}
}