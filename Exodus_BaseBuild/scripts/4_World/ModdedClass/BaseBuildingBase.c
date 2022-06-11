modded class BaseBuildingBase
{
	bool IsNormalPart()
    {
        return false;
    }
	
	bool GatePartConstruct()
	{
		return false;
	}
	
	bool IsIrregularPart()
	{
		return false;
	}
	
	bool DestructionDisable()
    {
        return false;
    }

	bool IsUnderGroud()
	{
		return false;
	}
	
	/* bool NoResstrictBuild()
	{
		return false;
	} */

	//Procure por HasProperDistance no arquivo fence.c la voce encontra essa varievel :D
	bool DistanceNormalPart( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance >= 1 )
			{
				return false;
			}
		}
		return true;
	}
	// Utilizado Para ajustar a distancia de raid e posiçao de um item Irregular [Escadas, Fundaçoes, Teto e Piso]
	bool RaidDistanceIrregularPart( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance >= 1.7 )
			{
				return false;
			}
		}
		return true;
	}
};


modded class Construction
{	
	//Utilizado para adicionar funcionalidade a Ferramenta de Admin
	override bool CanBuildPart( string part_name, ItemBase tool, bool use_tool )
	{
		if ( tool && tool.isExdAdminTool() && !IsPartConstructed( part_name ) && HasRequiredPart( part_name ) && !HasConflictPart( part_name ) )
		{
			return true;
		}
		
		else if ( !IsPartConstructed( part_name ) && HasRequiredPart( part_name ) && !HasConflictPart( part_name ) && HasMaterials( part_name ) && (!use_tool || CanUseToolToBuildPart( part_name, tool )) && !MaterialIsRuined(part_name) )
		{
			return true;
		}
		
		return false;
	}
};
