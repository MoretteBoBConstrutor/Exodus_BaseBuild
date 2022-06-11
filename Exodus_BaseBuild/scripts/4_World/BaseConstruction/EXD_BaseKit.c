class EXD_BaseKit extends ItemBase
{
	string RequiredHologram()
    {
        return ""; 
    }

	override bool OpcaoDeAgarrar()
	{
		return true;
	}

	override bool IsBasebuildingKit()
	{
		return true;
	}
	
	override bool IsDeployable()
	{
		return true;
	}

	bool IsUnderGroudProject()
    {
        return false;
    }
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
}

modded class ModItemRegisterCallbacks
{
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded(pType, pBehavior);
		pType.AddItemInHandsProfileIK("EXD_BaseKit", "dz/anims/workspaces/player/player_main/props/player_main_1h_compass.asi", pBehavior,	"dz/anims/anm/player/ik/gear/compass_modern.anm");
	}
};
