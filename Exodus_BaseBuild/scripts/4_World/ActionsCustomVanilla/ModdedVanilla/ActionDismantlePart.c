modded class ActionDismantlePartCB : ActionContinuousBaCB
{
	int dismantleTime;

	override void CreateActionComponent()
	{
		dismantleTime = g_Game.GetExodusConfig().Get_DismantleTime();
		m_ActionData.m_ActionComponent = new CAContinuousTime( dismantleTime );
	}
};

modded class ActionDismantlePart: ActionContinuousBase
{
	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ConstructionActionData construction_action_data = player.GetConstructionActionData();	
		ConstructionPart construction_part = construction_action_data.GetTargetPart();
		if ( player )
		{	
			if ( construction_part )
			{
				m_Text = "#dismantle" + " " + construction_part.GetName();
			}
		}
		else
		{
			m_Text = "#dismantle " + construction_action_data.GetTargetPart();
		}
	}

	override string GetText()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if ( player )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			ConstructionPart construction_part = construction_action_data.GetTargetPart();
			
			if ( construction_part )
			{
				return "#dismantle" + " " + construction_part.GetName();
			}
		}
		
		return "";
	}

	bool GetDismantleTools(ItemBase item_in_hands, ActionTarget target)
	{
		ref TStringArray j_dismantleTools = g_Game.GetExodusConfig().Get_DismantleTools();

		foreach (string tool : j_dismantleTools) 
		{
			if ( item_in_hands && item_in_hands.IsKindOf(tool) )
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

		//Action not allowed if player has broken legs
		if (player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
			return false;

		if ( CfgAllowDismantleConstructions() == false )
		{
			return false;
		}
		/* Necessario para fazer a ferramenta admin funcionar ser estar no .json */

		string itemName = item.GetType();
		itemName.ToLower();
		if ( /* GetDismantleTools(item, target) == false && */ !GetDismantleTools(item, target) && !itemName.Contains("admin") )
		{
			return false;
		}		
		
		return DismantleCondition( player, target, item, true );
	}
	
	protected bool DismantleCondition( PlayerBase player, ActionTarget target, ItemBase item, bool camera_check )
	{	
		if ( player && !player.IsLeaning() )
		{
			Object target_object = target.GetObject();
			EntityAI target_entity;
			if ( target_object && target_object.CanUseConstruction() )
			{
				//invalid if is gate and is locked
				if ( Class.CastTo(target_entity,target_object) && (target_entity.FindAttachmentBySlotName("Att_CombinationLock") || target_entity.FindAttachmentBySlotName("Material_FPole_Flag")) )
				{
					return false;
				}

				string part_name = target_object.GetActionComponentName( target.GetComponentIndex() );

				BaseBuildingBase base_building = BaseBuildingBase.Cast( target_object );
				Construction construction = base_building.GetConstruction();		
				ConstructionPart construction_part = construction.GetConstructionPartToDismantle( part_name, item );

				EXD_Base exdbase = EXD_Base.Cast( target.GetObject() );
				
				if ( construction_part )
				{
					/*Print("DismantleCondition");
					Print(part_name);
					Print("construction_part.GetPartName: " + construction_part.GetPartName());
					Print("construction_part.GetMainPartName: " + construction_part.GetMainPartName());
					Print("-----");*/
					
					if ( base_building.IsNormalPart() )
					{	
						if (/* base_building.IsIrregularPart() == false */ !base_building.IsIrregularPart() )
						{
							//camera and position checks
							if ( !base_building.IsFacingPlayer( player, part_name ) && !player.GetInputController().CameraIsFreeLook() && base_building.HasProperDistance( construction_part.GetMainPartName(), player ) )
							{
								//Camera check (client-only)
								if ( camera_check )
								{
									if ( GetGame() && ( !GetGame().IsDedicatedServer() ) )
									{
										if ( base_building.IsFacingCamera( part_name ) )
										{
											return false;
										}
									}
								}
								//Distance check
								if ( exdbase )
								{
									if ( !exdbase.DistanceNormalPart( "center", player ) /* == false */)
									{
										return false;
									}
								}
								ConstructionActionData construction_action_data = player.GetConstructionActionData();
								construction_action_data.SetTargetPart( construction_part );
								return true;
							}
						}
						if( base_building.IsIrregularPart() )
						{
							if( exdbase )
							{
								if ( exdbase.DistanceNormalPart( "center", player ) )
								{
									ConstructionActionData construction_action_data_flat = player.GetConstructionActionData();
									construction_action_data_flat.SetTargetPart( construction_part );
									return true;
								}
							}
							return false;
						}
					}
					if ( !base_building.IsNormalPart() )
					{
						return super.DismantleCondition(player, target, item, camera_check);
					}
				}
			}
		}
		return false;
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

		int dismantleToolDamage = g_Game.GetExodusConfig().Get_DismantleToolDamage();
		// Oficial
		if ( construction.CanDismantlePart( construction_part.GetPartName(), action_data.m_MainItem ) )
		{
			//build
			construction.DismantlePartServer( action_data.m_Player, construction_part.GetPartName(), AT_DISMANTLE_PART );
			
			//add damage to tool
			action_data.m_MainItem.DecreaseHealth( dismantleToolDamage, false );
		}

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
	
	bool CfgAllowDismantleConstructions()
	{
		return g_Game.GetExodusConfig().Get_CanDismnatleConstructions();
	}

};