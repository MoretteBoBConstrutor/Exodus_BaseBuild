modded class CraftWatchtowerKit extends RecipeBase
{
	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		if ( ingredients[0].GetInventory().IsAttachment() )
			return false;
		if ( ingredients[1].GetInventory().IsAttachment() )
			return false;
		if ( CanDoVanillaWatchTowerKit() == false )
			return false;
		if ( CanDoVanillaWatchTowerKit() == true )
			return true;
		return true;
	}
	
	bool CanDoVanillaWatchTowerKit()
	{
		return g_Game.GetExodusConfig().Get_CanCraftCVanillarWatchTowerKit();
	}
};
