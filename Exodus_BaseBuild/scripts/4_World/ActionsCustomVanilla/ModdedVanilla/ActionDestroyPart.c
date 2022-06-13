modded class ActionDestroyPartCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		Object targetObject = m_ActionData.m_Target.GetObject();
		BaseBuildingBase m_target = BaseBuildingBase.Cast(targetObject);
		int raidTime = RaidTimeForTier(); /* * 60; */ //Adicionar o * 60 para tornar o raid por minutos, porem fazer essa mudança somente quando for atualizar
		//m_ActionData.m_ActionComponent = new CAContinuousTime( raidTime );
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(raidTime);
	}
	//Tempos de Raid para cada nivel
	int raidTimeDefault = g_Game.GetExodusConfig().Get_DestroyTimeDefault();
	int raidTimeT1 = g_Game.GetExodusConfig().Get_DestroyTimeT1();
	int raidTimeT2 = g_Game.GetExodusConfig().Get_DestroyTimeT2();
	int raidTimeT3 = g_Game.GetExodusConfig().Get_DestroyTimeT3();
	// Usado para definir para cada parte que contenha certa nomeclatura um tempo especifico
	int RaidTimeForTier()
	{
		BaseBuildingBase base_building = BaseBuildingBase.Cast( m_ActionData.m_Target.GetObject() );
		Construction construction = base_building.GetConstruction();
		ConstructionActionData construction_action_data = m_ActionData.m_Player.GetConstructionActionData();
		ConstructionPart construction_part = construction_action_data.GetTargetPart();
		int compIdx;
		string compName;
		Object object;
		object = m_ActionData.m_Target.GetObject();
		compIdx  = m_ActionData.m_Target.GetComponentIndex();
		compName = object.GetActionComponentName( compIdx );
		compName.ToLower();
		
		if ( construction.CanDestroyPart( construction_part.GetPartName() ) )
		{
			/* Suporta uma grande varievel de mods, por isso usamos t1, t2 e t3
			Sera usado para a aneaçao do dorrs and barricades ou grande parte dele ao mod */
			if ( compName.Contains("t3") )
			{
				return raidTimeT3;
			}
			else if ( compName.Contains("t2") )
			{
				return raidTimeT2;
			}
			else if ( compName.Contains("t1") )
			{
				return raidTimeT1;
			}
		}
		//Default
		return raidTimeDefault;
	}

	

};

modded class ActionDestroyPart: ActionContinuousBase
{

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ConstructionActionData construction_action_data = player.GetConstructionActionData();	
		ConstructionPart construction_part = construction_action_data.GetTargetPart();
		if ( player )
		{	
			if ( construction_part )
			{
				m_Text = "#destroy" + " " + construction_part.GetName();
			}
		}
		else
		{
			m_Text = "#destroy " + construction_action_data.GetTargetPart();
		}
		
	}

	//Ferramentas para Raid Baseado em More Door e Dorrs and Barricades
	bool GetRaidToolT1(ItemBase item_in_hands, ActionTarget target)
	{
		ref TStringArray j_raidingToolsT1 = g_Game.GetExodusConfig().Get_RaidToolsT1();

		foreach (string toolT1 : j_raidingToolsT1) 
		{
			if ( item_in_hands && item_in_hands.IsKindOf(toolT1) )
			{
				return true;
			}
		}
		return false;
	}
	bool GetRaidToolT2(ItemBase item_in_hands, ActionTarget target)
	{
		ref TStringArray j_raidingToolsT2 = g_Game.GetExodusConfig().Get_RaidToolsT2();

		foreach (string toolT2 : j_raidingToolsT2) 
		{
			if ( item_in_hands && item_in_hands.IsKindOf(toolT2) )
			{
				return true;
			}
		}
		return false;
	}
	bool GetRaidToolT3(ItemBase item_in_hands, ActionTarget target)
	{
		ref TStringArray j_raidingToolsT3 = g_Game.GetExodusConfig().Get_RaidToolsT3();

		foreach (string toolT3 : j_raidingToolsT3) 
		{
			if ( item_in_hands && item_in_hands.IsKindOf(toolT3) )
			{
				return true;
			}
		}
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (!super.ActionCondition( player, target, item ))
			return false;
		
		//Se a destruiçao for desativada no .json sempre voltara negativo
		if(CfgAllowDestructConstructions() == false)
		return false;

		BaseBuildingBase base_building = BaseBuildingBase.Cast( target.GetObject() );
		Construction construction = base_building.GetConstruction();
		ConstructionActionData construction_action_data = player.GetConstructionActionData();
		ConstructionPart construction_part = construction_action_data.GetTargetPart();
		int compIdx;
		string compName;
		Object object;
		object = target.GetObject();
		compIdx  = target.GetComponentIndex();
		compName = object.GetActionComponentName( compIdx );

		compName.ToLower();
		if ( construction.CanDestroyPart( construction_part.GetPartName() ) )
		{
			if ( compName.Contains("t3"))
			{
				if ( !GetRaidToolT3(item, target) )
				{
					return false;
				}
			}
			else if ( compName.Contains("t2") )
			{
				if ( !GetRaidToolT2(item, target) )
				{
					return false;
				}
			}
			else if ( compName.Contains("t1") )
			{
				if ( !GetRaidToolT1(item, target) )
				{
					return false;
				}
			}
			else 
			{
				if ( !GetRaidToolT1(item, target) )
				{
					return false;
				}
			}
		}
		
		if ( base_building && base_building.DestructionDisable() )
		{
			return false;
		}

		if ( CfgDestructConstructionsOnlyDoors() == true )
		{
			if (compName.Contains("gate") || compName.Contains("door") || compName.Contains("d_d_r_t1") || compName.Contains("d_d_l_t1") || compName.Contains("exd_floorh_door1_t1") || compName.Contains("exd_floorh_door2_t1"))
			{
				return DestroyCondition( player, target, item, true );
			}

			return false;
		}

		return DestroyCondition( player, target, item, true );
	}

	//Ajustado para Raidar itens Irregulares
	protected bool DestroyCondition( PlayerBase player, ActionTarget target, ItemBase item, bool camera_check )
	{	
		if ( player && !player.IsLeaning() )
		{
			Object target_object = target.GetObject();
			if ( target_object && target_object.CanUseConstruction() )
			{
				string part_name = target_object.GetActionComponentName( target.GetComponentIndex() );
				
				BaseBuildingBase base_building = BaseBuildingBase.Cast( target_object );
				Construction construction = base_building.GetConstruction();		
				ConstructionPart construction_part = construction.GetConstructionPartToDestroy( part_name );
				EXD_Base exdbase = EXD_Base.Cast( target.GetObject() );

				if ( construction_part )
				{
					if ( base_building.IsNormalPart() )
					{
						if (/*  !base_building.IsIrregularPart() == false  */!base_building.IsIrregularPart() )
						{
							//camera and position checks
							if ( !player.GetInputController().CameraIsFreeLook() && IsInReach(player, target, UAMaxDistances.DEFAULT) && !player.GetInputController().CameraIsFreeLook() )
							{
								//Camera check (client-only)
								if ( camera_check )
								{
									if ( GetGame() && ( !GetGame().IsDedicatedServer() ) )
									{
										if ( !base_building.IsFacingCamera( part_name ) )
										{
											return false;
										}
									}
								}

								ConstructionActionData construction_action_data = player.GetConstructionActionData();
								construction_action_data.SetTargetPart( construction_part );

								return true;				
							}
						}
						//Usado para adicionar um ponto de distancia e uma area para raidar os itens planos ou diferentes
						if( base_building.IsIrregularPart() )
						{
							if( exdbase )
							{
								if ( exdbase.RaidDistanceIrregularPart( "RaidDistance", player ))
								{
									ConstructionActionData construction_action_data_Flat = player.GetConstructionActionData();
									construction_action_data_Flat.SetTargetPart( construction_part );
									return true;
								}
							}
							return false;
						}
					}
				}
			}
		}
		
		return false;
	}
	
	//Envia Mensagem de qual parte foi destruida para o player
	void EnviarMensagem(PlayerBase player, string message)	
	{
		Param1<string> Msgparam;
		Msgparam = new Param1<string>(message);
		GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, player.GetIdentity());
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		BaseBuildingBase base_building = BaseBuildingBase.Cast( action_data.m_Target.GetObject() );
		Construction construction = base_building.GetConstruction();
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		ConstructionPart construction_part = construction_action_data.GetTargetPart();
		int compIdx;
		string compName;
		Object object;
		object = action_data.m_Target.GetObject();
		compIdx  = action_data.m_Target.GetComponentIndex();
		compName = object.GetActionComponentName( compIdx );
		compName.ToLower();
		//TESTE
		string part_name = construction_part.GetPartName();
		string zone_name;
		DamageSystem.GetDamageZoneFromComponentName(base_building,part_name,zone_name);
		//
		//Danos paras os 3 niveis de ferraamentas
		int raidToolDamageT1 = g_Game.GetExodusConfig().Get_RaidToolDamageT1();
		int raidToolDamageT2 = g_Game.GetExodusConfig().Get_RaidToolDamageT2();
		int raidToolDamageT3 = g_Game.GetExodusConfig().Get_RaidToolDamageT3();
		//Loopes para Zonas, Cada Loop necessario é o tempo definido no .json
		int DamageZoneLoopT1 = g_Game.GetExodusConfig().Get_LoopToDestructT1();
		string Picture = "set:dayz_inventory image:paper";

		if ( construction.CanDestroyPart( construction_part.GetPartName() ) )
		{
			if ( compName.Contains("t1") )
			{
				if (zone_name != "")
				{
					base_building.AddHealth(zone_name,"Health",-(base_building.GetMaxHealth(zone_name,"")/DamageZoneLoopT1));

					//Print("Dano Adicionado" + " "+ action_data.m_MainItem.GetDisplayName() +" "+ action_data.m_Player.GetIdentity().GetName() + " " + action_data.m_Player.GetPosition()); GetId()

					if ( base_building.GetHealth(zone_name,"Health") < 1 )
					{
						construction.DestroyPartServer( action_data.m_Player, construction_part.GetPartName(), AT_DESTROY_PART );
						NotificationSystem.SendNotificationToPlayerIdentityExtended(action_data.m_Player.GetIdentity(), 0.5, "BaseBuild", construction_part.GetName() + " " + "has been destroyed", Picture);
						Print("Destroyed " + action_data.m_Target.GetObject().GetDisplayName() + " with " + action_data.m_MainItem.GetDisplayName() + " " + action_data.m_Player.GetIdentity().GetName() + " = " + action_data.m_Player.GetIdentity().GetPlainId() + " " + action_data.m_Player.GetPosition());
					}
				}
				else
				{
					construction.DestroyPartServer( action_data.m_Player, construction_part.GetPartName(), AT_DESTROY_PART );
				}
				action_data.m_MainItem.DecreaseHealth( raidToolDamageT1, false );
				//Print("Dano a Ferramenta");
			}
			else if ( compName.Contains("t2") )
			{
				construction.DestroyPartServer( action_data.m_Player, construction_part.GetPartName(), AT_DESTROY_PART );
				action_data.m_MainItem.DecreaseHealth( raidToolDamageT2, false );
				EnviarMensagem(action_data.m_Player, "Uma parte nivel 2 foi destruida");
			}
			else if ( compName.Contains("t3") )
			{
				construction.DestroyPartServer( action_data.m_Player, construction_part.GetPartName(), AT_DESTROY_PART );
				action_data.m_MainItem.DecreaseHealth( raidToolDamageT3, false );
				EnviarMensagem(action_data.m_Player, "Uma parte nivel 3 foi destruida");
			}
			else 
			{
				construction.DestroyPartServer( action_data.m_Player, construction_part.GetPartName(), AT_DESTROY_PART );
				//add damage to tool
				action_data.m_MainItem.DecreaseHealth( raidToolDamageT1, false );
			}
		}
	
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}

	bool CfgAllowDestructConstructions()
	{
		return g_Game.GetExodusConfig().Get_CanDestroyConstructions();
	}

	bool CfgDestructConstructionsOnlyDoors()
	{
		return g_Game.GetExodusConfig().Get_CanRaidOnlyDoors();
	}

}
