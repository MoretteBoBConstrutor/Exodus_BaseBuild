modded class CraftFenceKit extends RecipeBase
{
	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		if ( ingredients[0].GetInventory().IsAttachment() )
			return false;
		if ( ingredients[1].GetInventory().IsAttachment() )
			return false;
		if ( CanDoVanillaFenceKit() == false )
			return false;
		if ( CanDoVanillaFenceKit() == true )
			return true;
		return true;
	}
	
	bool CanDoVanillaFenceKit()
	{
		return g_Game.GetExodusConfig().Get_CanCraftCVanillarFenceKit();
	}
};
