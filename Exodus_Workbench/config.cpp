class CfgPatches
{
	class Exodus_Workbench
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data", "DZ_Scripts", "Exodus_BaseBuild"
		};
	};
};

class CfgMods
{
	class Exodus_Workbench
	{
		dir = "Exodus_Workbench";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 1;
		name = "Exodus_Workbench";
		credits = "";
		author = "";
		authorID = "0";
		version = "1";
		extra = 0;
		type = "mod";
		dependencies[] =
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] =
				{
					"Exodus_Workbench/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] =
				{
					"Exodus_Workbench/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] =
				{
					"Exodus_Workbench/scripts/5_Mission"
				};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class Bottle_Base;
	class EXD_BaseKit;

	class EXD_BB_Kit_Clipboard : EXD_BaseKit
	{
		scope = 2;
		displayName = "Kit da Workbench";
	};
	class EXD_Clipboard_Hologram: EXD_BB_Kit_Clipboard
	{
		scope = 2;
		displayName = "Holograma";
		descriptionShort = "Chachorro Caramelo";
		model = "\Exodus_Workbench\data\models\EXD_Workbench_Holo.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};
	

	class Exodus_Workbench : Container_Base
	{
		scope = 2;
		displayName = "Mesa de Trabalho";
		descriptionShort = "Usada para criar seus Kits de Base e Construção";
		model = "\Exodus_Workbench\data\models\EXD_Workbench.p3d";
		overrideDrawArea = 8;
		useEntityHierarchy = "true";
		carveNavmesh = 1;
		canBeDigged = 0;
		heavyItem = 1;
		weight = 20000;
		itemSize[] = {10, 10};
		itemBehaviour = 0;
		repairKitType = 5;
		physLayer = "item_large";
		allowOwnedCargoManipulation = 1;
		attachments[] =
		{
			"ShovelExd",
			"Marreta",
			"Machado",
			"Picareta",
			"Shoulder",
			"Back",
			"CamoNet",	
			"Truck_01_WoodenCrate1",
			"Truck_01_WoodenPlanks",
			"Truck_01_WoodenLogs",
			"Truck_01_MetalSheets"
		};
		class Cargo
		{
			itemsCargoSize[] = {10, 80};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class GUIInventoryAttachmentsProps
		{
			class Tools
			{
				name = "Tools";
				description = "";
				attachmentSlots[] =
					{
						"ShovelExd",
						"Marreta",
						"machado",
						"Picareta"
					};
				icon = "cat_bb_attachments";
			};
			class Storage
			{
				name = "Storage";
				description = "";
				attachmentSlots[] =
					{
						"Shoulder",
						"Back",
						"CamoNet",	
						"Truck_01_WoodenCrate1",
						"Truck_01_WoodenPlanks",
						"Truck_01_WoodenLogs",
						"Truck_01_MetalSheets"
					};
				icon = "cat_bb_material";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 5000;
					healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpBarrelLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpBarrel_SoundSet";
					id = 797;
				};
			};
		};
	};
	class Pickaxe : Inventory_Base
	{
		inventorySlot[]+= {"Picareta"};
	};
	class Sledgehammer : Inventory_Base
	{
		inventorySlot[]+= {"Marreta"};
	};
	class WoodAxe : Inventory_Base
	{
		inventorySlot[]+= {"Machado"};
	};
	class Shovel : Inventory_Base
	{
		inventorySlot[]+= {"Shovel1"};
	};
};

class CfgSlots
{
	class Slot_ShovelExd
	{
		name = "Shovel1";
		displayName = "Pá";
		selection = "Shovel1";
		ghostIcon = "Shovel1";
	};
	class Slot_Picareta
	{
		name = "Picareta";
		displayName = "Picareta";
		ghostIcon = "";
		selection = "Pickaxe";
	};
	class Slot_Marreta
	{
		name = "Marreta";
		displayName = "Marreta";
		ghostIcon = "";
	};
	class Slot_Machado
	{
		name = "Machado";
		displayName = "Machado";
		ghostIcon = "";
	};
};

class CfgSoundShaders
{
	class craft_SoundShaders
	{
		samples[] =
			{
				{"Exodus_Workbench\data\sounds\desenhando_projeto.ogg", 1}};
		range = 6;
		volume = 6.1999998;
	};
};

class CfgSoundSets
{
	class Craft_SoundSet
	{
		soundShaders[] =
			{
				"craft_SoundShaders"};
	};
};
