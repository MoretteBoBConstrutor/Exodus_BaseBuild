class ActionDestroyLockedZoneCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(5);
	}
}

class ActionDestroyLockedZone: ActionContinuousBase
{
	void ActionDestroyLockedZone()
	{
		m_CallbackClass		= ActionDestroyLockedZoneCB;
		m_CommandUID		= DayZPlayerConstants.CMD_ACTIONFB_DIG;
		m_FullBody			= true;
		m_StanceMask		= DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight	= UASoftSkillsWeight.ROUGH_LOW;
		m_Text = "Criar passagem";
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		/* Object targetObject = target.GetObject();
		EXD_Base exdbase = EXD_Base.Cast( targetObject );
		if (player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
			return false;
		
		if (targetObject && !targetObject.IsInherited(EXD_Base))
		{
			return false;
		}
		
		if (exdbase && exdbase.IsUnderGroud())
		{
			array<string> selections = new array<string>;
			exdbase.GetActionComponentNameList(target.GetComponentIndex(), selections);

			for ( int i = 0; i < selections.Count(); i++ )
			{
                if ( selections[i] == "upgradelock_t1" )
				{
					if(exdbase.GetConstruction().GetConstructionPart("unlokedzone_1").IsBuilt() ) //Trocar por unlokedzone_1 depois da parte for feita
					return true;
				}
				return false;
			}
		} */

		Object targetObject = target.GetObject();
		Land_UnderGroud_LockPart under_partL = Land_UnderGroud_LockPart.Cast( targetObject );
		if ( under_partL )
		{
			array<string> selections = new array<string>;
			targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);
			for ( int i = 0; i < selections.Count(); i++ )
			{
                if ( selections[i] == "unlock_zone" )
					return true;
			}
			return false;
		}
		
		return false;
	}

	override bool ActionConditionContinue( ActionData action_data )
	{
		return true;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		/* Object targetObject = action_data.m_Target.GetObject();
		
		if (targetObject.IsInherited(EXD_Base))
		{
			EXD_Base exdbase = EXD_Base.Cast(targetObject);
			Construction construction = exdbase.GetConstruction();
			if (exdbase.GetConstruction().IsPartConstructed( "upgradelock_t1" ))
			{
				construction.DestroyPartServer( action_data.m_Player, "upgradelock_t1" , AT_DESTROY_PART );
			}
		} */
		Object target_object = action_data.m_Target.GetObject();
        Land_UnderGroud_LockPart under_partL = Land_UnderGroud_LockPart.Cast( target_object );
        if( under_partL )
		{
			target_object.AddHealth("GlobalHealth", "Health", -25);
			action_data.m_MainItem.SetHealth( "", "", GameConstants.DAMAGE_RUINED_VALUE );
			Print("Dano Aplicado");
			if ( target_object.GetHealth("GlobalHealth", "Health") < 5 )
			{
				target_object.Delete();
				Print("Objeto de Bloqueio deletado");
			}
			//target_object.Delete();
			//action_data.m_MainItem.SetHealth( "", "", GameConstants.DAMAGE_RUINED_VALUE );
		}
	}
}