modded class ActionBuildPartCB : ActionContinuousBaseCB
{
	int ConstructionTimeExodus;

	override void CreateActionComponent()
	{
		ConstructionTimeExodus = g_Game.GetExodusConfig().Get_BuildTime();
		m_ActionData.m_ActionComponent = new CAContinuousTime( ConstructionTimeExodus );
	}
};

modded class ActionBuildPart: ActionContinuousBase
{
	bool BuildToolInHands(ItemBase item_in_hands, ActionTarget target)
	{
		ref TStringArray j_buildTools = g_Game.GetExodusConfig().Get_BuildTools();

		foreach (string tool : j_buildTools) 
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
		if ( player.IsPlacingLocal() || player.IsPlacingServer() )
			return false;
		
		//Action not allowed if player has broken legs
		if (player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
			return false;

		//hack - gate
		//WTF
		if (target.GetObject() && (!target.GetObject().CanUseConstructionBuild() || target.GetObject().CanUseHandConstruction()))
			return false;
		
		string itemName = item.GetType();
		itemName.ToLower();
		//Talvez funcione ou nao, preciso testar, se vai causar algum problema.
		//Pequeno lembrete
		if ( !BuildToolInHands(item, target) /*== false*/ && !itemName.Contains("admin") && !item.IsInherited(Shovel) && !item.IsInherited(FarmingHoe) && !item.IsInherited(Pickaxe) && !item.IsInherited(Pliers) && !item.IsInherited(SledgeHammer))
		{
			return false;
		}
		return super.ActionCondition( player, target, item );

	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		BaseBuildingBase base_building = BaseBuildingBase.Cast( action_data.m_Target.GetObject() );
		Construction construction = base_building.GetConstruction();
		
		string part_name = BuildPartActionData.Cast(action_data).m_PartType;
		
		//Dano da ferramenta .Json
		int damageToTool = g_Game.GetExodusConfig().Get_BuildToolDamage();

		if ( !construction.IsColliding( part_name ) && construction.CanBuildPart( part_name, action_data.m_MainItem, true ) )
		{
			//build
			construction.BuildPartServer( action_data.m_Player, part_name, AT_BUILD_PART );
			
			//add damage to tool
			action_data.m_MainItem.DecreaseHealth( damageToTool, false );
			
		}
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}

}
