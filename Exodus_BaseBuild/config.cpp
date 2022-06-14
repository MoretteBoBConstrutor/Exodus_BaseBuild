class CfgPatches
{
	class Exodus_BaseBuild
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data","DZ_Gear_Camping","DZ_Scripts","DZ_Gear_Tools","DZ_Gear_Containers","DZ_Weapons_Melee","DZ_Gear_Medical","DZ_Gear_Consumables","DZ_Weapons_Melee_Blade"};
	};
};

class CfgMods
{
	class Exodus_BaseBuild
	{
		type = "mod";
		credits = "ProjectBR";
		author = "Morette|Zoomoon";
		dir = "Exodus_BaseBuild";
		name = "Exodus_BaseBuild";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"Exodus_BaseBuild/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Exodus_BaseBuild/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"Exodus_BaseBuild/Scripts/5_Mission"};
			};
		};
	};
};
class CfgVehicles
{
	class Fence;
	class Inventory_Base;
	class Container_Base;
	class EXD_BaseKit: Inventory_Base
	{
		scope = 0;
		displayName = "ClipBoard Base";
		descriptionShort = "Projeto de construção de base";
		isMeleeWeapon = 0;
		weight = 10000;
		absorbency = 0;
		rotationFlags = 2;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		model = "\Exodus_BaseBuild\Data\Models\ClipBoard\EXD_Clipboard.p3d";
		hiddenSelections[] = {"blueprint"};
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Models\ClipBoard\textures\blueprint\blueprint_co.paa"};
	};
	class EXD_Wall_Base: Inventory_Base
	{
		scope = 0;
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		lootCategory = "Crafted";
		carveNavmesh = 1;
		weight = 60000;
		itemSize[] = {6,6};
		physLayer = "item_large";
		createProxyPhysicsOnInit = "false";
		createdProxiesOnInit[] = {"Deployed","Hologram"};
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 9999990;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	
	class EXD_BB_Kit_Wall: EXD_BaseKit
	{
		scope = 2;
		displayName = "Wood Wall Kit";
		descriptionShort = "Press B while holding the kit to toggle snapping. Press K to target the base part you want. Press F to cycle through the snap points.";
		rotationFlags = 2;
		isMeleeWeapon = 0;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Parede_co.paa"};
	};
	class EXD_Wall_Hologram: EXD_BB_Kit_Wall
	{
		scope = 2;
		displayName = "Wall Hologram";
		descriptionShort = "xD";
		model = "\Exodus_BaseBuild\Data\Models\Wall\EXD_SimpleWall_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};

	class EXD_BB_Kit_Wall_Window: EXD_BaseKit
	{
		scope = 2;
		displayName = "Wood Window Kit";
		descriptionShort = "Press B while holding the kit to toggle snapping. Press K to target the base part you want. Press F to cycle through the snap points.";
		rotationFlags = 2;
		isMeleeWeapon = 0;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Janela_co.paa"};
	};
	class EXD_Wall_Window_Hologram: EXD_BB_Kit_Wall_Window
	{
		scope = 2;
		displayName = "Window Wall Hologram";
		descriptionShort = "xD";
		model = "\Exodus_BaseBuild\Data\Models\Wall_W\EXD_Wall_W_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};

	class EXD_BB_Kit_Floor: EXD_BaseKit
	{
		scope = 2;
		displayName = "Wood Floor Kit";
		descriptionShort = "Press B while holding the kit to toggle snapping. Press K to target the base part you want. Press F to cycle through the snap points.";
		rotationFlags = 2;
		isMeleeWeapon = 0;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		minPlacingDist = 8;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Piso_co.paa"};
	};
	class EXD_Floor_Hologram: EXD_BB_Kit_Floor
	{
		scope = 2;
		displayName = "Floor Hologram";
		descriptionShort = "xD";
		model = "\Exodus_BaseBuild\Data\Models\Floor\EXD_Floor_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};
	
	class EXD_BB_Kit_Floor_Delta: EXD_BaseKit
	{
		scope = 2;
		displayName = "Wood Delta Floor Kit";
		descriptionShort = "Press B while holding the kit to toggle snapping. Press K to target the base part you want. Press F to cycle through the snap points.";
		rotationFlags = 2;
		isMeleeWeapon = 0;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		minPlacingDist = 8;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Piso_D_co.paa"};
	};
	class EXD_Floor_Delta_Hologram: EXD_BB_Kit_Floor_Delta
	{
		scope = 2;
		displayName = "Delta Floor Hologram";
		descriptionShort = "Volta Rapariga";
		model = "\Exodus_BaseBuild\Data\Models\Floor_D\EXD_Floor_D_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};

	class EXD_BB_Kit_Floor_Hatch: EXD_BaseKit
	{
		scope = 2;
		displayName = "Wood Floor Hatch Kit";
		descriptionShort = "Press B while holding the kit to toggle snapping. Press K to target the base part you want. Press F to cycle through the snap points.";
		rotationFlags = 2;
		isMeleeWeapon = 0;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		minPlacingDist = 8;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Piso_aberto_co.paa"};
	};
	class EXD_Floor_Hatch_Hologram: EXD_BB_Kit_Floor_Hatch
	{
		scope = 2;
		displayName = "Floor Hatch Hologram";
		descriptionShort = "xD";
		model = "\Exodus_BaseBuild\Data\Models\Floor_H\EXD_FloorHatch_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};

	class EXD_BB_Kit_Door: EXD_BaseKit
	{
		scope = 2;
		displayName = "Wood Door Kit";
		descriptionShort = "Press B while holding the kit to toggle snapping. Press K to target the base part you want. Press F to cycle through the snap points.";
		rotationFlags = 2;
		isMeleeWeapon = 0;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Porta_co.paa"};
	};
	class EXD_Door_Hologram: EXD_BB_Kit_Door
	{
		scope = 2;
		displayName = "Door Hologram";
		descriptionShort = "xD";
		model = "\Exodus_BaseBuild\Data\Models\Door\EXD_SimpleDoor_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};
	
	class EXD_BB_Kit_Double_Door: EXD_BaseKit
	{
		scope = 2;
		displayName = "Wood Double Door Kit";
		descriptionShort = "Press B while holding the kit to toggle snapping. Press K to target the base part you want. Press F to cycle through the snap points.";
		rotationFlags = 2;
		isMeleeWeapon = 0;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Porta_dupla_co.paa"};
	};
	class EXD_Double_Door_Hologram: EXD_BB_Kit_Double_Door
	{
		scope = 2;
		displayName = "Double Door Hologram";
		descriptionShort = "xD";
		model = "\Exodus_BaseBuild\Data\Models\Door_Double\EXD_Door_Double_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};

	class EXD_BB_Kit_GateRamp: EXD_BaseKit
	{
		scope = 2;
		displayName = "Wood Gate Ramp Kit";
		descriptionShort = "Press B while holding the kit to toggle snapping. Press K to target the base part you want. Press F to cycle through the snap points.";
		rotationFlags = 2;
		isMeleeWeapon = 0;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Portao_rampa_co.paa"};
	};
	class EXD_Gate_Ramp_Hologram: EXD_BB_Kit_GateRamp
	{
		scope = 2;
		displayName = "Gate Hologram";
		descriptionShort = "xD";
		model = "\Exodus_BaseBuild\Data\Models\Gate_Ramp\EXD_Gate_Ramp_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};

	class EXD_BB_Kit_Roof: EXD_BaseKit
	{
		scope = 2;
		displayName = "Wood Roof Kit";
		descriptionShort = "Press B while holding the kit to toggle snapping. Press K to target the base part you want. Press F to cycle through the snap points.";
		rotationFlags = 2;
		isMeleeWeapon = 0;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		minPlacingDist = 8;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Teto_co.paa"};
	};
	class EXD_Roof_Hologram: EXD_BB_Kit_Roof
	{
		scope = 2;
		displayName = "Roof Hologram";
		descriptionShort = "xD";
		model = "\Exodus_BaseBuild\Data\Models\Roof\EXD_Roof_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};
	
	class EXD_BB_Kit_Roof_Delta: EXD_BaseKit
	{
		scope = 2;
		displayName = "Wood Delta Roof Kit";
		descriptionShort = "Press B while holding the kit to toggle snapping. Press K to target the base part you want. Press F to cycle through the snap points.";
		rotationFlags = 2;
		isMeleeWeapon = 0;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		minPlacingDist = 8;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Teto_D_co.paa"};
	};
	class EXD_Roof_Delta_Hologram: EXD_BB_Kit_Roof_Delta
	{
		scope = 2;
		displayName = "Delta Roof Hologram";
		descriptionShort = "xD";
		model = "\Exodus_BaseBuild\Data\Models\Roof_D\EXD_Roof_D_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};
	
	class EXD_BB_Kit_Roof_Hatch: EXD_BaseKit
	{
		scope = 2;
		displayName = "Wood Roof Hatch Kit";
		descriptionShort = "Press B while holding the kit to toggle snapping. Press K to target the base part you want. Press F to cycle through the snap points.";
		rotationFlags = 2;
		isMeleeWeapon = 0;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		minPlacingDist = 8;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Teto_aberto_co.paa"};
	};
	class EXD_Roof_Hatch_Hologram: EXD_BB_Kit_Roof_Hatch
	{
		scope = 2;
		displayName = "Roof Hatch Hologram";
		descriptionShort = "xD";
		model = "\Exodus_BaseBuild\Data\Models\Roof_H\EXD_RoofHatch_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};

	class EXD_BB_Kit_Stair_Mini: EXD_BaseKit
	{
		scope = 2;
		displayName = "Mini Stair Kit";
		descriptionShort = "A folded wooden ladder.";
		model = "\Exodus_BaseBuild\Data\Models\Stair_Mini\EXD_Stair_Mini_Kit.p3d";
		isMeleeWeapon = 0;
		weight = 30000;
		absorbency = 0;
		rotationFlags = 0;
		itemSize[] = {5,5};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		physLayer = "item_small";
	};
	class EXD_Stair_Mini: Inventory_Base
	{
		scope = 2;
		displayName = "Mini Stair";
		descriptionShort = "Use this to Build a Roof.";
		model = "\Exodus_BaseBuild\Data\Models\Stair_Mini\EXD_Stair_Mini.p3d";
		handheld = "true";
		weight = 5000;
		heavyItem = 1;
		itemSize[] = {25,25};
		itemsCargoSize[] = {0,0};
		canBeDigged = 0;
		isMeleeWeapon = 0;
		//quantityBar = 1;
		carveNavmesh = 1;
		placement = "ForceSlopeOnTerrain";
		overrideDrawArea = "8.0";
		physLayer = "item_large";
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		//allowOwnedCargoManipulation = 1;
		itemBehaviour = 0;
		//randomQuantity = 2;
		minPlacingDist = 10;
		rotationFlags = 0;
		attachments[] = {};
		class GUIInventoryAttachmentsProps{};
	};

	class EXD_BB_Kit_Stair_L: EXD_BaseKit
	{
		scope = 2;
		displayName = "Stair L Kit";
		descriptionShort = "Press B while holding the kit to toggle snapping. Press K to target the base part you want. Press F to cycle through the snap points.";
		isMeleeWeapon = 0;
		weight = 30000;
		absorbency = 0;
		rotationFlags = 2;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Ecada_L_co.paa"};
	};
	class EXD_Stair_L_Hologram: EXD_BB_Kit_Stair_L
	{
		scope = 2;
		displayName = "Stair L Hologram";
		descriptionShort = "BR";
		model = "\Exodus_BaseBuild\Data\Models\Stair_L\EXD_Stair_L_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};

	class EXD_BB_Kit_Pillar: EXD_BaseKit
	{
		scope = 2;
		displayName = "Pillar Kit";
		descriptionShort = "Press B while holding the kit to toggle snapping. Press K to target the base part you want. Press F to cycle through the snap points.";
		isMeleeWeapon = 0;
		weight = 30000;
		absorbency = 0;
		rotationFlags = 2;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Pilar_co.paa"};
	};
	class EXD_Pillar_Hologram: EXD_BB_Kit_Pillar
	{
		scope = 2;
		displayName = "Pillar Hologram";
		descriptionShort = "BR";
		model = "\Exodus_BaseBuild\Data\Models\Pillar\EXD_Pillar_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};

	class EXD_BB_Kit_Foundation: EXD_BaseKit
	{
		scope = 2;
		displayName = "Wood Foundation Kit";
		descriptionShort = "Press B while holding the kit to toggle snapping. Press K to target the base part you want. Press F to cycle through the snap points.";
		rotationFlags = 2;
		isMeleeWeapon = 0;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		minPlacingDist = 8;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Fundacao.paa"};
	};
	class EXD_Foundation_Hologram: EXD_BB_Kit_Foundation
	{
		scope = 2;
		displayName = "Foundation Hologram";
		descriptionShort = "xD";
		model = "\Exodus_BaseBuild\Data\Models\Foundation\EXD_Foundation_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};

	//Admin Tool
	class Hatchet;
	class EXD_Hammer_Admin: Hatchet
	{
		displayName="Admin";
		descriptionShort="Tome cuidado, os itens contruidos por essa ferramenta geram problemas de colisao com o carros. Odiamos Abusers";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10000;
				};
			};
		};
	};

	class EXD_Brourette: Container_Base
	{
		displayName="Brourette";
		descriptionShort="Use para estocar iten de construçao";
		scope=2;
		model="\Exodus_BaseBuild\Data\Models\Item_Brourette\EXD_Brourette.p3d";
		hologramMaterial="EXD_Brourette";
		hologramMaterialPath="\Exodus_BaseBuild\Data\Models\Item_Brourette";
		slopeTolerance=0.40;
		yawPitchRollLimit[]={45,45,45};
		weight=10000;
		itemBehaviour=0;
		carveNavmesh=1;
		canBeDigged=1;
		rotationFlags=2;
		itemSize[]={10,4};
		physLayer = "item_large";
		attachments[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};   
		class Cargo
		{
			itemsCargoSize[]={8,4};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health 	 {hitpoints = 500;};
			};
			class GlobalArmor
			{
				class Projectile{
					class Health {damage=1;};
					class Blood  {damage=0;};
					class Shock	 {damage=0;};
				};
				class FragGrenade{
					class Health {damage=10;};
					class Blood  {damage=0;};
					class Shock	 {damage=0;};
				};
			};
		};
		class AnimationSources
		{
			class ShowLog
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class ShowPlank
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};

	//UnderGroud
	class EXD_BB_Kit_UnderGroud: EXD_BaseKit
	{
		scope = 2;
		displayName = "Under Ground Project";
		descriptionShort = "";
		rotationFlags = 2;
		isMeleeWeapon = 0;
		weight = 300;
		absorbency = 0;
		itemSize[] = {2,2};
		lootCategory = "Materials";
		reversed = 0;
		itemBehaviour = 2;
		minPlacingDist = 8;
		hiddenSelectionsTextures[] = {"\Exodus_BaseBuild\Data\Textures\Shared\Thumbs\Bunker_co.paa"};
	};
	class EXD_UnderGroud_Hologram: EXD_BB_Kit_UnderGroud
	{
		scope = 2;
		displayName = "Hologram";
		descriptionShort = "xD";
		model = "\Exodus_BaseBuild\Data\Models\UndergroudBase\Small\UnderGroundBase_Hologram.p3d";
		overrideDrawArea = "3.0";
		attachments[] = {};
		carveNavmesh = 1;
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class GUIInventoryAttachmentsProps{};
	};

	/* 
	class HouseNoDestruct; Container_Base  Inventory_Base
	é possivel usar o Inventory_Base, e trasformar o obejto em um item de base build pelo script, precisa ser testado o sistema de partes e zonas
	- nascer tudo ja construido, fazendo uma açao alternativa para fazer a picareta ir destruindo as partes e no final da açao destruir a zona (desmontar)
	  fazendo a animaçao ir para 1
	*/
	class Land_UnderGroud_Part: Container_Base
	{
		scope=2;
		physLayer = "item_large";
		model="\Exodus_BaseBuild\Data\Models\UndergroudBase\data\Land_UnderGroudBase.p3d";
		//itemSize[] = {10,99};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health 	 {hitpoints = 100;};
			};
			class GlobalArmor
			{
				class Projectile{
					class Health {damage=0;};
					class Blood  {damage=0;};
					class Shock	 {damage=0;};
				};
				class FragGrenade{
					class Health {damage=0;};
					class Blood  {damage=0;};
					class Shock	 {damage=0;};
				};
			};
		};
	};
	class Land_UnderGroud_LockPart: Container_Base
	{
		scope=2;
		physLayer = "item_large";
		model="\Exodus_BaseBuild\Data\Models\UndergroudBase\data\UpgradeLock.p3d";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health 	 {hitpoints = 100;};
				healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
			};
			class GlobalArmor
			{
				class Projectile{
					class Health {damage=0;};
					class Blood  {damage=0;};
					class Shock	 {damage=0;};
				};
				class FragGrenade{
					class Health {damage=0;};
					class Blood  {damage=0;};
					class Shock	 {damage=0;};
				};
			};
		};
	};

}; 

/* 
```fix
EXD_BB_Kit_Wall
EXD_BB_Kit_Wall_Window
EXD_BB_Kit_Floor
EXD_BB_Kit_Floor_Delta
EXD_BB_Kit_Floor_Hatch
EXD_BB_Kit_Door
EXD_BB_Kit_Double_Door
EXD_BB_Kit_GateRamp
EXD_BB_Kit_Roof
EXD_BB_Kit_Roof_Delta
EXD_BB_Kit_Roof_Hatch
EXD_BB_Kit_Stair_Mini
EXD_BB_Kit_Stair_L
EXD_BB_Kit_Pillar
EXD_BB_Kit_Foundation
```
```
EXD_Wall
EXD_Wall_Window
EXD_Floor
EXD_Floor_Delta
EXD_Floor_Hatch
EXD_Door
EXD_Double_Door
EXD_Gate_Ramp
EXD_Roof
EXD_Roof_Delta
EXD_Roof_Hatch
EXD_Stair_Mini
EXD_Stair_L
EXD_Pillar
EXD_Foundation
``` */
