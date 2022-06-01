class EXD_Stair_Mini extends ItemBase
{
	override bool CanPutInCargo(EntityAI parent)
    {
        return false;
    }
    
    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }
	//Mesma variavel do vanila para validar uma distancia de açao, funcional ate o momento
	bool HasProperDistance( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance >= 2.3 )
			{
				return false;
			}
		}
		return true;
	}
	
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionFoldLadder);
    }
}