class ActionTeleportUnderGroud: ActionInteractBase
{
	void ActionTeleportUnderGroud()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}

    override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		/* m_ConditionTarget = new CCTNone; */
        m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}

	override string GetText()
	{
		return " Enter ";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{


		Object targetObject = target.GetObject();
		if ( targetObject && targetObject.CanUseConstruction() )
		{
			/* EXD_Base exdbase = EXD_Base.Cast( targetObject );
			
			if ( exdbase && exdbase.IsUnderGroud() && exdbase.IsOpened())
			{
				array<string> selections = new array<string>;
				targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);
				
				for ( int i = 0; i < selections.Count(); i++ )
				{
					if ( selections[i] == "under_entrance" )
					{
						if(exdbase.GetConstruction().GetConstructionPart("Under_base").IsBuilt() )
						return true;
					}
					return false;
				}
			} */


			EXD_Base exdbase = EXD_Base.Cast( targetObject );
			array<string> selections = new array<string>;
			targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);

			if ( exdbase && exdbase.IsUnderGroud() && exdbase.IsOpened() && exdbase.HasFullyConstructedGate())
			{
				for ( int i = 0; i < selections.Count(); i++ )
				{
                    if ( selections[i] == "under_entrance" )
					{
						if(exdbase.GetConstruction().GetConstructionPart("Under_base").IsBuilt() )
						return true;
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
						if(exdbase.GetConstruction().GetConstructionPart("Under_base").IsBuilt() )
						return true;
					}
					return false;
				}
			}
		}

		
		
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		PlayerBase player = PlayerBase.Cast( action_data.m_Player );
        Object target_object = action_data.m_Target.GetObject();
        EXD_Base exdbase = EXD_Base.Cast( target_object );
        if( exdbase.IsUnderGroud() )
		{
           /*  vector pos = player.GetPosition() + "0 101 0"; */
		    vector pos = target_object.GetPosition() + "0 100.5 0";
            player.SetPosition( pos );
            Print("Teleporte para dentro");
		}
	}

}

class ActionTeleportUnderGroudLeave: ActionInteractBase
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
       /*  Object target_object = target.GetObject();
        EXD_Base exdbase = EXD_Base.Cast( target_object );
        if( exdbase.IsUnderGroud() )
		{
			return true;
		}
        return false; */

        Object targetObject = target.GetObject();
		if ( targetObject && targetObject.CanUseConstruction() )
		{
			EXD_Base exdbase = EXD_Base.Cast( targetObject );
			array<string> selections = new array<string>;
			targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);

			if ( exdbase && exdbase.IsUnderGroud() && exdbase.IsOpened() && exdbase.HasFullyConstructedGate())
			{
				//array<string> selections = new array<string>;
				//targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);
				
				for ( int i = 0; i < selections.Count(); i++ )
				{
					/* if ( selections[i] == "under_base" ) */
                    if ( selections[i] == "under_leave" )
						return true;
				}
				return false;
			}
			else if (exdbase && exdbase.IsUnderGroud() && !exdbase.HasFullyConstructedGate())
			{
				//array<string> selections = new array<string>;
				//targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);
				
				for ( int j = 0; j < selections.Count(); j++ )
				{
					/* if ( selections[i] == "under_base" ) */
                    if ( selections[j] == "under_leave" )
						return true;
				}
				return false;
			}
		}
		
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		PlayerBase player = PlayerBase.Cast( action_data.m_Player );
        Object target_object = action_data.m_Target.GetObject();
        EXD_Base exdbase = EXD_Base.Cast( target_object );
        if( exdbase.IsUnderGroud() )
		{
            /* vector pos = player.GetPosition() - "0 101 0"; */
			vector pos = target_object.GetPosition();
		    //pos = GetMemoryPointPos( "inside" );
            player.SetPosition( pos );
            Print("Teleporte para Fora");
		}
	}

}