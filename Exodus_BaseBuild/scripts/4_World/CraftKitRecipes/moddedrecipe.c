modded class PluginRecipesManager
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new CraftExodusDoor);
		RegisterRecipe(new CraftExodusDoorDuble);
		RegisterRecipe(new CraftExodusFloor);
		RegisterRecipe(new CraftExodusFloorD);
		RegisterRecipe(new CraftExodusMiniStair);
		RegisterRecipe(new CraftExodusPillar);
		RegisterRecipe(new CraftExodusRoof);
		RegisterRecipe(new CraftExodusRoofD);
		RegisterRecipe(new CraftExodusStairL);
		RegisterRecipe(new CraftExodusWall);
		RegisterRecipe(new CraftExodusWindow);
		RegisterRecipe(new CraftExodusFloorHacth);
		RegisterRecipe(new CraftExodusFoundation);
		RegisterRecipe(new CraftExodusGateRamp);
		RegisterRecipe(new CraftExodusRoofHatch);
		RegisterRecipe(new CraftExodusWorkbench);
	}
}
