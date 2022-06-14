class Exodus_Workbench extends Container_Base
{
	void SetActions()
	{
		super.SetActions();

		AddAction(ActionInteractWithWorkbench);
		AddAction(ActionDeconstructWB);
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

	ref array<string> m_AllowedCargo = {
		"WoodenLog","WoodenPlank","Nail","NailBox","MetalPlate","Stone",
		"Rope","MetalWire","BarbedWire","Paper","WoodenStick","DuctTape","Netting",
		"Pliers","Shovel","FieldShovel","Crowbar","Hammer","Screwdriver","Hacksaw","SledgeHammer","HandSaw","Pickaxe","Hatchet","Pipe",
		"EXD_BaseKit", "FenceKit", "WatchtowerKit", "ShelterKit", "TerritoryFlagKit"};
	override bool CanReceiveItemIntoCargo (EntityAI item)	
	{
		foreach( string allowedCargo : m_AllowedCargo )
		{
			if(item.IsKindOf(allowedCargo))
				return true;
		};
		
		return false;
	}
}