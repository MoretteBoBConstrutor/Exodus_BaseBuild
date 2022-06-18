class CfgPatches
{
	class Exodus_BaseBuild_Itens
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data","DZ_Gear_Camping","DZ_Scripts","Exodus_BaseBuild"};
	};
};

class CfgVehicles
{
    class Inventory_Base;
    class EXD_Wall_Base;
    class EXD_Wall: EXD_Wall_Base
	{
		scope = 2;
		displayName = "Wall";
		descriptionShort = "Wood Wall.";
		model = "\Exodus_BaseBuild\Data\Models\Wall\EXD_SimpleWall.p3d";
		attachments[] = {"Wall_Barbedwire_1","Wall_Camonet","Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks","Material_MetalSheets"};
		hybridAttachments[] = {"Wall_BarbedWire_1"};
		mountables[] = {"Wall_BarbedWire_1"};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "Attachments";
				description = "";
				attachmentSlots[] = {"Wall_Barbedwire_1","Wall_Camonet"};
				icon = "cat_bb_attachments";
				selection = "exd_wall_t1";
			};
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
				icon = "cat_bb_material";
				selection = "wall_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Material_Nails: AnimSourceHidden{};
			class Material_L1_WoodenLogs: AnimSourceHidden{};
			class Material_WoodenPlanks: AnimSourceHidden{};
			class Material_MetalSheets: AnimSourceHidden{};
			class Wall_Barbedwire_1: AnimSourceHidden{};
			class Wall_Barbedwire_1_Mounted: AnimSourceHidden{};
			class Wall_Camonet: AnimSourceHidden{};
			class Deployed: AnimSourceHidden{};
			class Hologram: AnimSourceHidden{};
			class Exd_wall_t1: AnimSourceHidden{};
			class Exd_wall_t2: AnimSourceHidden{};
			class Build_holo: AnimSourceHidden{};
			class WallCamonet: AnimSourceHidden{};
		};
		class Construction
		{
			class wall_build
			{
				class exd_wall_t1
				{
					name = "Wall | T1 |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
				    {
				    	class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 20;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 36;
						};
				    };
				};
				class exd_wall_t2
				{
					name = "Wall | T2 |";
					id = 2;
					required_parts[] = {"exd_wall_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
				    {
				    	class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 20;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 36;
						};
				    };
				};
			};
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
			class DamageZones
			{
				class exd_wall_t1
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_wall_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_wall_t2
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_wall_t2"};
					fatalInjuryCoef=-1;
				};
			};
		};
		
	};

    class EXD_Wall_Window: EXD_Wall_Base
	{
		scope = 2;
		displayName = "Window";
		descriptionShort = "Wood Window";
		model = "\Exodus_BaseBuild\Data\Models\Wall_W\EXD_Wall_W.p3d";
		attachments[] = {"Wall_Barbedwire_1","Wall_Camonet","Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks","Material_MetalSheets","Att_CombinationLock","Wall_Camonet"};
		hybridAttachments[] = {"Wall_BarbedWire_1"};
		mountables[] = {"Wall_BarbedWire_1"};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "Attachments";
				description = "";
				attachmentSlots[] = {"Wall_Barbedwire_1","Att_CombinationLock","Wall_Camonet"};
				icon = "cat_bb_attachments";
				selection = "exd_wall_w_t1";
			};
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
				icon = "cat_bb_material";
				selection = "wall_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Material_Nails: AnimSourceHidden{};
			class Material_L1_WoodenLogs: AnimSourceHidden{};
			class Material_WoodenPlanks: AnimSourceHidden{};
			class Material_MetalSheets: AnimSourceHidden{};
			class Wall_Barbedwire_1: AnimSourceHidden{};
			class Wall_Barbedwire_1_Mounted: AnimSourceHidden{};
			class Deployed: AnimSourceHidden{};
			class Hologram: AnimSourceHidden{};
			class Exd_wall_w_t1: AnimSourceHidden{};
			class Exd_wall_w_t2: AnimSourceHidden{};
			class Exd_wall_w_frame_t1: AnimSourceHidden{};
			class Build_holo: AnimSourceHidden{};
			class Exd_wall_w_door_t1: AnimSourceHidden{};
			class Exd_wall_w_door_t2: AnimSourceHidden{};
			class Exd_wall_w_door_t1_Rotate: AnimRotate{};
			class Exd_wall_w_door_t2_Rotate: AnimRotate{};
			class WallCamonet: AnimSourceHidden{};
		};
		class Construction
		{
			class wall_build
			{
				class exd_wall_w_t1
				{
					name = "Wall | T1 |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
				    {
				    	class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 18;
						};
				    };
				};
				class exd_wall_w_t2
				{
					name = "Wall | T2 |";
					id = 4;
					required_parts[] = {"exd_wall_w_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
				    {
				    	class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 18;
						};
				    };
				};
				class exd_wall_w_door_t1
				{
					name = "Window | T1 |";
					is_gate = 1;
					id = 2;
					required_parts[] = {"exd_wall_w_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
				    {
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 18;
						};
				    };
				};
				class exd_wall_w_door_t2
				{
					name = "Window | T2 |";
					id = 5;
					required_parts[] = {"exd_wall_w_t2", "exd_wall_w_door_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
				    {
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 18;
						};
				    };
				};
				class exd_wall_w_frame_t1
				{
					name = "Window Frame | T1 |";
					id = 3;
					required_parts[] = {"exd_wall_w_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
				    {
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 18;
						};
				    };
				};
			};
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
			class DamageZones
			{
				class exd_wall_w_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_wall_w_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_wall_w_t2
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_wall_w_t2"};
					fatalInjuryCoef=-1;
				};
				class exd_wall_w_frame_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_wall_w_frame_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_wall_w_door_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_wall_w_door_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_wall_w_door_t2
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_wall_w_door_t2"};
					fatalInjuryCoef=-1;
				};
			};
		};
	};

    class EXD_Floor: Inventory_Base
	{
		scope = 2;
		displayName = "Floor";
		descriptionShort = "Wood Floor";
		model = "\Exodus_BaseBuild\Data\Models\Floor\EXD_Floor.p3d";
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
		attachments[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks","Wall_Camonet"};
		hybridAttachments[] = {};
		mountables[] = {};
		class GUIInventoryAttachmentsProps
		{
			class Camonet
			{
				name = "Camo Net";
				description = "";
				attachmentSlots[] = {"Wall_Camonet"};
				icon = "cat_bb_attachments";
				selection = "floor_build";
			};
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
				icon = "cat_bb_material";
				selection = "floor_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Wall_Camonet: AnimSourceHidden{};
			class Deployed: AnimSourceHidden{};
			class Hologram: AnimSourceHidden{};
			class Exd_Floor_t1: AnimSourceHidden{};
			class Exd_Floor_t2: AnimSourceHidden{};
			class Build_holo: AnimSourceHidden{};
			class WallCamonet: AnimSourceHidden{};
		};
		class Construction
		{
			class floor_build
			{
				class exd_floor_t1
				{
					name = "Floor | T1 |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 20;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 36;
						};
					};
				};
				class exd_floor_t2
				{
					name = "Floor | T2 |";
					id = 2;
					required_parts[] = {"exd_floor_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 20;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 36;
						};
					};
				};
			};
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
			class DamageZones
			{
				class exd_floor_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_floor_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_floor_t2
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_floor_t2"};
					fatalInjuryCoef=-1;
				};
			};
		};
	};

    class EXD_Floor_Delta: Inventory_Base
	{
		scope = 2;
		displayName = "Floor D";
		descriptionShort = "Floor Delta.";
		model = "\Exodus_BaseBuild\Data\Models\Floor_D\EXD_Floor_D.p3d";
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
		attachments[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks","Wall_Camonet"};
		hybridAttachments[] = {};
		mountables[] = {};
		class GUIInventoryAttachmentsProps
		{
			class Camonet
			{
				name = "Camo Net";
				description = "";
				attachmentSlots[] = {"Wall_Camonet"};
				icon = "cat_bb_attachments";
				selection = "floor_build";
			};
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
				icon = "cat_bb_material";
				selection = "floor_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Material_Nails: AnimSourceHidden{};
			class Wall_Camonet: AnimSourceHidden{};
			class Deployed: AnimSourceHidden{};
			class Hologram: AnimSourceHidden{};
			class Exd_floor_d_t1: AnimSourceHidden{};
			class Exd_floor_d_t2: AnimSourceHidden{};
			class Build_holo: AnimSourceHidden{};
			class WallCamonet: AnimSourceHidden{};
		};
		class Construction
		{
			class floor_build
			{
				class exd_floor_d_t1
				{
					name = "Delta Floor | T1 |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 20;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 36;
						};
					};
				};
				class exd_floor_d_t2
				{
					name = "Delta Floor | T2 |";
					id = 2;
					required_parts[] = {"exd_floor_d_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 20;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 36;
						};
					};
				};
			};
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
			class DamageZones
			{
				class exd_floor_d_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_floor_d_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_floor_d_t2
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_floor_d_t2"};
					fatalInjuryCoef=-1;
				};
			};
		};
	};

    class EXD_Floor_Hatch: Inventory_Base
	{
		scope = 2;
		displayName = "Floor Hatch";
		descriptionShort = "Wood Floor";
		model = "\Exodus_BaseBuild\Data\Models\Floor_H\EXD_FloorHatch.p3d";
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
		attachments[] = {"Att_CombinationLock","Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
		hybridAttachments[] = {};
		mountables[] = {};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "Attachments";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_attachments";
				selection = "floor_build";
			};
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
				icon = "cat_bb_material";
				selection = "floor_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Hologram: AnimSourceHidden{};
			class Exd_floorh_t1: AnimSourceHidden{};
			class Exd_floorh_door1_t1: AnimSourceHidden{};
			class Exd_floorh_door1_t1_Rotate: AnimRotate{};
			class Exd_floorh_door2_t1: AnimSourceHidden{};
			class Exd_floorh_door2_t1_Rotate: AnimRotate{};
			class Wall_Interact_Rotate: AnimRotate{};
			class Build_holo: AnimSourceHidden{};
			class Exd_floorh_stair_t1: AnimSourceHidden{};
		};
		class Construction
		{
			class floor_build
			{
				class exd_floorh_t1
				{
					name = "Floor | T1 |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 12;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
					};
					
				};
				class exd_floorh_door1_t1
				{
					name = "Door P1 | T1 |";
					is_gate = 1;
					id = 3;
					required_parts[] = {"exd_floorh_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 8;
						};
					};
				};
				class exd_floorh_door2_t1
				{
					name = "Door P2 | T1 |";
					is_gate = 1;
					id = 4;
					required_parts[] = {"exd_floorh_door1_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 8;
						};
					};
				};
				class exd_floorh_stair_t1
				{
					name = "Stair | T1 |";
					id = 5;
					required_parts[] = {"exd_floorh_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 8;
						};
					};
				};
			};
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
			class DamageZones
			{
				class exd_floorh_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_floorh_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_floorh_door1_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_floorh_door1_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_floorh_door2_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_floorh_door2_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_floorh_stair_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_floorh_stair_t1"};
					fatalInjuryCoef=-1;
				};
			};
		};
	};

    class EXD_Door: EXD_Wall_Base
	{
		scope = 2;
		displayName = "Door";
		descriptionShort = "Wood Door.";
		model = "\Exodus_BaseBuild\Data\Models\Door\EXD_SimpleDoor.p3d";
		attachments[] = {"Att_CombinationLock","Wall_Camonet","Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks","Material_MetalSheets"};
		hybridAttachments[] = {};
		mountables[] = {};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "Attachments";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_attachments";
				selection = "door_build";
			};
			class Camonet
			{
				name = "Camo Net";
				description = "";
				attachmentSlots[] = {"Wall_Camonet"};
				icon = "cat_bb_attachments";
				selection = "door_build";
			};
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
				icon = "cat_bb_material";
				selection = "door_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Material_Nails: AnimSourceHidden{};
			class Material_L1_WoodenLogs: AnimSourceHidden{};
			class Material_WoodenPlanks: AnimSourceHidden{};
			class Material_MetalSheets: AnimSourceHidden{};
			class Wall_Camonet: AnimSourceHidden{};
			class Wall_Camonet_Gate: AnimSourceHidden{};
			class Deployed: AnimSourceHidden{};
			class Hologram: AnimSourceHidden{};
			class Exd_wall_d_t1: AnimSourceHidden{};
			class Exd_wall_d_t2: AnimSourceHidden{};
			class Exd_door_t1: AnimSourceHidden{};
			class Exd_door_t1_Rotate: AnimRotate{};
			class Exd_door_t2: AnimSourceHidden{};
			class Exd_door_t2_Rotate: AnimRotate{};
			class Wall_Interact_Rotate: AnimRotate{};
			class Build_holo: AnimSourceHidden{};
			class WallCamonet: AnimSourceHidden{};
			class GateCamonet: AnimSourceHidden{};
			class GateCamonet_Rotate: AnimRotate{};
		};
		class Construction
		{
			class door_build
			{
				class exd_wall_d_t1
				{
					name = "Wall | T1 |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 18;
						};
					};
					
				};
				class exd_door_t1
				{
					name = "Door | T1 |";
					is_gate = 1;
					id = 3;
					required_parts[] = {"exd_wall_d_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 18;
						};
					};
				};
				class exd_door_t2
				{
					name = "Door | T2 |";
					id = 4;
					required_parts[] = {"exd_door_t1", "exd_wall_d_t2"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";//metalplate
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 18;
						};
					};
				};
				class exd_wall_d_t2
				{
					name = "Wall | T2 |";
					id = 5;
					required_parts[] = {"exd_wall_d_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 18;
						};
					};
				};
			};
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
			class DamageZones
			{
				class exd_wall_d_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_wall_d_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_wall_d_t2
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_wall_d_t2"};
					fatalInjuryCoef=-1;
				};
				class exd_door_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_door_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_door_t2
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_door_t2"};
					fatalInjuryCoef=-1;
				};
			};
		};
	};

    class EXD_Double_Door: EXD_Wall_Base
	{
		scope = 2;
		displayName = "Double Door";
		descriptionShort = "Wood double door.";
		model = "\Exodus_BaseBuild\Data\Models\Door_Double\EXD_Door_Double.p3d";
		attachments[] = {"Att_CombinationLock","Wall_Camonet","Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks","Material_MetalSheets"};
		hybridAttachments[] = {};
		mountables[] = {};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "Attachments";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_attachments";
				selection = "door_build";
			};
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
				icon = "cat_bb_material";
				selection = "door_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Material_Nails: AnimSourceHidden{};
			class Material_L1_WoodenLogs: AnimSourceHidden{};
			class Material_WoodenPlanks: AnimSourceHidden{};
			class Material_MetalSheets: AnimSourceHidden{};
			class Wall_Camonet: AnimSourceHidden{};
			class Wall_Camonet_Gate: AnimSourceHidden{};
			class Deployed: AnimSourceHidden{};
			class Hologram: AnimSourceHidden{};
			class Exd_wall_double_door_t1: AnimSourceHidden{};
			class Exd_wall_double_door_t2: AnimSourceHidden{};
			class Exd_d_d_l_t1: AnimSourceHidden{};
			class Exd_d_d_r_t1: AnimSourceHidden{};
			class Exd_d_d_l_Rotate: AnimRotate{};
			class Exd_d_d_r_Rotate: AnimRotate{};
			class Exd_d_d_l_t2: AnimSourceHidden{};
			class Exd_d_d_r_t2: AnimSourceHidden{};
			class Exd_d_d_l_t2_Rotate: AnimRotate{};
			class Exd_d_d_r_t2_Rotate: AnimRotate{};
			class Wall_Interact_Rotate: AnimRotate{};
			class Build_holo: AnimSourceHidden{};
		};
		class Construction
		{
			class door_build
			{
				class exd_wall_double_door_t1
				{
					name = "Wall | T1 |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 18;
						};
					};
					
				};
				class exd_wall_double_door_t2
				{
					name = "Wall | T2 |";
					id = 6;
					required_parts[] = {"exd_wall_double_door_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 18;
						};
					};
					
				};
				class exd_d_d_r_t1
				{
					name = "Door R | T1 |";
					is_gate = 1;
					id = 2;
					required_parts[] = {"exd_wall_double_door_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 9;
						};
					};
					
				};
				class exd_d_d_l_t1
				{
					name = "Door L | T1 |";
					is_gate = 1;
					id = 3;
					required_parts[] = {"exd_wall_double_door_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 9;
						};
					};
				};
				class exd_d_d_r_t2
				{
					name = "Door R | T2 |";
					id = 4;
					required_parts[] = {"exd_d_d_r_t1", "exd_wall_double_door_t2"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 9;
						};
					};
					
				};
				class exd_d_d_l_t2
				{
					name = "Door L | T2 |";
					id = 5;
					required_parts[] = {"exd_d_d_l_t1", "exd_wall_double_door_t2"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 9;
						};
					};
				};
			};
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
			class DamageZones
			{
				class exd_wall_double_door_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_wall_double_door_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_wall_double_door_t2
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_wall_double_door_t2"};
					fatalInjuryCoef=-1;
				};
				class exd_d_d_r_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_d_d_r_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_d_d_r_t2
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_d_d_r_t2"};
					fatalInjuryCoef=-1;
				};
				class exd_d_d_l_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_d_d_l_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_d_d_l_t2
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_d_d_l_t2"};
					fatalInjuryCoef=-1;
				};
			};
		};
	};

	class EXD_Gate_Ramp: EXD_Wall_Base
	{
		scope = 2;
		displayName = "Gate Ramp";
		descriptionShort = "|-_-|";
		model = "\Exodus_BaseBuild\Data\Models\Gate_Ramp\EXD_Gate_Ramp.p3d";
		attachments[] = {"Att_CombinationLock","Wall_Camonet","Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks","Material_MetalSheets"};
		hybridAttachments[] = {};
		mountables[] = {};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "Attachments";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_attachments";
				selection = "door_build";
			};
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
				icon = "cat_bb_material";
				selection = "door_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Material_Nails: AnimSourceHidden{};
			class Material_L1_WoodenLogs: AnimSourceHidden{};
			class Material_WoodenPlanks: AnimSourceHidden{};
			class Material_MetalSheets: AnimSourceHidden{};
			class Wall_Camonet: AnimSourceHidden{};
			class Wall_Camonet_Gate: AnimSourceHidden{};
			class Deployed: AnimSourceHidden{};
			class Hologram: AnimSourceHidden{};
			class Exd_wall_d_t1: AnimSourceHidden{};
			class Exd_door_t1: AnimSourceHidden{};
			class Exd_door_t1_Rotate: AnimRotate{};
			class Exd_door_t2: AnimSourceHidden{};
			class Exd_door_t2_Rotate: AnimRotate{};
			class Wall_Interact_Rotate: AnimRotate{};
			class Build_holo: AnimSourceHidden{};
		};
		class Construction
		{
			class door_build
			{
				class exd_wall_d_t1
				{
					name = "Frame | T1 |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 18;
						};
					};
					
				};
				class exd_door_t1
				{
					name = "Gate Ramp | T1 |";
					is_gate = 1;
					id = 2;
					required_parts[] = {"exd_wall_d_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 18;
						};
					};
				};
				class exd_door_t2
				{
					name = "Gate Ramp | T2 |";
					id = 3;
					required_parts[] = {"exd_door_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 10;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 18;
						};
					};
				};
			};
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
			class DamageZones
			{
				class exd_wall_d_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_wall_d_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_door_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_door_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_door_t2
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_door_t2"};
					fatalInjuryCoef=-1;
				};
			};
		};
	};

	class EXD_Roof: Inventory_Base
	{
		scope = 2;
		displayName = "Roof";
		descriptionShort = "Wood Roof.";
		model = "\Exodus_BaseBuild\Data\Models\Roof\EXD_Roof.p3d";
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
		attachments[] = {"Wall_Camonet","Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
		class GUIInventoryAttachmentsProps
		{
			class Camonet
			{
				name = "Camo Net";
				description = "";
				attachmentSlots[] = {"Wall_Camonet"};
				icon = "cat_bb_attachments";
				selection = "roof_build";
			};
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
				icon = "cat_bb_material";
				selection = "roof_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Material_Nails: AnimSourceHidden{};
			class Material_MetalSheets: AnimSourceHidden{};
			class Wall_Barbedwire_1: AnimSourceHidden{};
			class Wall_Barbedwire_2: AnimSourceHidden{};
			class Wall_Barbedwire_1_Mounted: AnimSourceHidden{};
			class Wall_Barbedwire_2_Mounted: AnimSourceHidden{};
			class Wall_Camonet: AnimSourceHidden{};
			class Deployed: AnimSourceHidden{};
			class Hologram: AnimSourceHidden{};
			class Exd_roof_t1: AnimSourceHidden{};
			class Exd_roof_t2: AnimSourceHidden{};
			class Build_holo: AnimSourceHidden{};
			class WallCamonet: AnimSourceHidden{};
		};
		class Construction
		{
			class roof_build
			{
				class exd_roof_t1
				{
					name = "Roof | T1 |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 20;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 36;
						};
					};
				};
				class exd_roof_t2
				{
					name = "Roof | T2 |";
					id = 2;
					required_parts[] = {"exd_roof_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 20;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 36;
						};
					};
				};
			};
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
			class DamageZones
			{
				class exd_roof_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_roof_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_roof_t2
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_roof_t2"};
					fatalInjuryCoef=-1;
				};
			};
		};
	};

	class EXD_Roof_Delta: Inventory_Base
	{
		scope = 2;
		displayName = "Roof D";
		descriptionShort = "Roof Delta";
		model = "\Exodus_BaseBuild\Data\Models\Roof_D\EXD_Roof_D.p3d";
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
		attachments[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks","Wall_Camonet"};
		class GUIInventoryAttachmentsProps
		{
			class Camonet
			{
				name = "Camo Net";
				description = "";
				attachmentSlots[] = {"Wall_Camonet"};
				icon = "cat_bb_attachments";
				selection = "roof_build";
			};
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
				icon = "cat_bb_material";
				selection = "roof_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Material_Nails: AnimSourceHidden{};
			class Material_MetalSheets: AnimSourceHidden{};
			class Wall_Barbedwire_1: AnimSourceHidden{};
			class Wall_Barbedwire_2: AnimSourceHidden{};
			class Wall_Barbedwire_1_Mounted: AnimSourceHidden{};
			class Wall_Barbedwire_2_Mounted: AnimSourceHidden{};
			class Wall_Camonet: AnimSourceHidden{};
			class Deployed: AnimSourceHidden{};
			class Hologram: AnimSourceHidden{};
			class Exd_roof_d_t1: AnimSourceHidden{};
			class Build_holo: AnimSourceHidden{};
			class WallCamonet: AnimSourceHidden{};
		};
		class Construction
		{
			class roof_build
			{
				class exd_roof_d_t1
				{
					name = "Delta Roof | T1 |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 20;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 36;
						};
					};
				};
			};
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
			class DamageZones
			{
				class exd_roof_d_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_roof_d_t1"};
					fatalInjuryCoef=-1;
				};
			};
		};
	};

	class EXD_Roof_Hatch: Inventory_Base
	{
		scope = 2;
		displayName = "Roof Hatch";
		descriptionShort = "Wood Roof";
		model = "\Exodus_BaseBuild\Data\Models\Roof_H\EXD_RoofHatch.p3d";
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
		attachments[] = {"Att_CombinationLock","Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
		hybridAttachments[] = {};
		mountables[] = {};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "Attachments";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_attachments";
				selection = "floor_build";
			};
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
				icon = "cat_bb_material";
				selection = "floor_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Hologram: AnimSourceHidden{};
			class Exd_floorh_t1: AnimSourceHidden{};
			class Exd_floorh_door1_t1: AnimSourceHidden{};
			class Exd_floorh_door1_t1_Rotate: AnimRotate{};
			class Exd_floorh_door2_t1: AnimSourceHidden{};
			class Exd_floorh_door2_t1_Rotate: AnimRotate{};
			class Wall_Interact_Rotate: AnimRotate{};
			class Build_holo: AnimSourceHidden{};
			class Exd_floorh_stair_t1: AnimSourceHidden{};
		};
		class Construction
		{
			class floor_build
			{
				class exd_floorh_t1
				{
					name = "Roof | T1 |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 12;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
					};
					
				};
				class exd_floorh_door1_t1
				{
					name = "Door P1 | T1 |";
					is_gate = 1;
					id = 3;
					required_parts[] = {"exd_floorh_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 8;
						};
					};
				};
				class exd_floorh_door2_t1
				{
					name = "Door P2 | T1 |";
					is_gate = 1;
					id = 4;
					required_parts[] = {"exd_floorh_door1_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 8;
						};
					};
				};
				class exd_floorh_stair_t1
				{
					name = "Stair | T1 |";
					id = 5;
					required_parts[] = {"exd_floorh_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 8;
						};
					};
				};
			};
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
			class DamageZones
			{
				class exd_floorh_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_floorh_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_floorh_door1_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_floorh_door1_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_floorh_door2_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_floorh_door2_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_floorh_stair_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_floorh_stair_t1"};
					fatalInjuryCoef=-1;
				};
			};
		};
	};

	class EXD_Stair_L: Inventory_Base
	{
		scope = 2;
		displayName = "Stair L";
		descriptionShort = "A simple L Stair.";
		model = "\Exodus_BaseBuild\Data\Models\Stair_L\EXD_Stair_L.p3d";
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
		attachments[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
		hybridAttachments[] = {};
		mountables[] = {};
		class GUIInventoryAttachmentsProps
		{
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_WoodenPlanks"};
				icon = "cat_bb_material";
				selection = "stair_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Deployed: AnimSourceHidden{};
			class Hologram: AnimSourceHidden{};
			class Exd_stair_l_t1: AnimSourceHidden{};
			class Build_holo: AnimSourceHidden{};
		};
		class Construction
		{
			class stair_build
			{
				class exd_stair_l_t1
				{
					name = "Stair L | T1 |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 20;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 20;
						};
					};
				};
			};
		};
	};

    class EXD_Pillar: Inventory_Base
	{
		scope = 2;
		displayName = "Pillar";
		descriptionShort = "Pillar.";
		model = "\Exodus_BaseBuild\Data\Models\Pillar\EXD_Pillar.p3d";
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
					hitpoints = 500;
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
		attachments[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
		hybridAttachments[] = {};
		mountables[] = {};
		class GUIInventoryAttachmentsProps
		{
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_L1_WoodenLogs"};
				icon = "cat_bb_material";
				selection = "pillar_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Deployed: AnimSourceHidden{};
			class Hologram: AnimSourceHidden{};
			class Exd_pillar_t1: AnimSourceHidden{};
			class Build_holo: AnimSourceHidden{};
		};
		class Construction
		{
			class pillar_build
			{
				class exd_pillar_t1
				{
					name = "Pillar | T1 |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
					};
				};
			};
		};
	};

    class EXD_Foundation: Inventory_Base
	{
		scope = 2;
		displayName = "Foundation";
		descriptionShort = "Wood Foundation";
		model = "\Exodus_BaseBuild\Data\Models\Foundation\EXD_Foundation.p3d";
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
		attachments[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
		hybridAttachments[] = {};
		mountables[] = {};
		class GUIInventoryAttachmentsProps
		{
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_L1_WoodenLogs","Material_WoodenPlanks"};
				icon = "cat_bb_material";
				selection = "foundation_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Wall_Camonet: AnimSourceHidden{};
			class Deployed: AnimSourceHidden{};
			class Hologram: AnimSourceHidden{};
			class Exd_foundation_t1: AnimSourceHidden{};
			class Exd_foundation_t2: AnimSourceHidden{};
			class Build_holo: AnimSourceHidden{};
		};
		class Construction
		{
			class foundation_build
			{
				class exd_foundation_t1
				{
					name = "Foundation | T1 |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 20;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 36;
						};
					};
				};
				class exd_foundation_t2
				{
					name = "Foundation | T2 |";
					id = 2;
					required_parts[] = {"exd_foundation_t1"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 2;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 20;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 36;
						};
					};
				};
			};
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
			class DamageZones
			{
				class exd_foundation_t1
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_foundation_t1"};
					fatalInjuryCoef=-1;
				};
				class exd_foundation_t2
				{
					class Health
					{
						hitpoints=100;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
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
					componentNames[]=	 {"exd_foundation_t2"};
					fatalInjuryCoef=-1;
				};
			};
		};
	};

	//TESTE UNDERGROUD BASE	
	class EXD_UnderGroud: Inventory_Base
	{
		scope = 2;
		displayName = " ";
		descriptionShort = "?";
		model = "\Exodus_BaseBuild\Data\Models\UndergroudBase\Small\UnderGroudTeste.p3d";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		lootCategory = "Crafted";
		carveNavmesh = 1;
		weight = 60000;
		itemSize[] = {6,6};
		physLayer = "item_large";
		createProxyPhysicsOnInit = "false";
		createdProxiesOnInit[] = {"Hologram"};
		rotationFlags = 2;
		attachments[] = 
		{
			"Truck_01_WoodenLogs",
			"Truck_01_WoodenPlanks",
			"Material_FPole_Stones",
			"Material_Nails",
			"Att_CombinationLock",
			"Wall_Camonet"
		};
		hybridAttachments[] = {};
		mountables[] = {};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "Attachments";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_attachments";
				selection = "under_build";
			};
			class Camonet
			{
				name = "Camo Net";
				description = "";
				attachmentSlots[] = {"Wall_Camonet"};
				icon = "cat_bb_attachments";
				selection = "under_build";
			};
			class Materials
			{
				name = "Materials";
				description = "";
				attachmentSlots[] = {"Truck_01_WoodenLogs","Truck_01_WoodenPlanks","Material_Nails","Material_FPole_Stones"};
				icon = "cat_bb_material";
				selection = "under_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Hologram: AnimSourceHidden{};
			class Under_base: AnimSourceHidden{};
			class Under_entrance: AnimSourceHidden{};
			class Under_Door_t1: AnimSourceHidden{};
			class Under_Door_Rotate: AnimRotate{};
			class WallCamonet: AnimSourceHidden{};
			class GateCamonet: AnimSourceHidden{};
			class GateCamonet_Rotate: AnimRotate{};
			class UpgradeLock_t1: AnimSourceHidden{};
			class Unlokedzone_1: AnimSourceHidden{};
		};
		class Construction
		{
			class under_build
			{
				class Under_entrance
				{
					name = "| Escavar entrada |";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type=4;
					dismantle_action_type=4;
					material_type = 1;
					class Materials
					{
						/* class Material1
						{
							type = "WoodenLog";
							slot_name = "Truck_01_WoodenLogs";
							quantity = 8;
						}; */
						class Material1
						{
							type = "Stone";
							slot_name = "Material_FPole_Stones";
							quantity = 20;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Truck_01_WoodenPlanks";
							quantity = 10;
						};
						class Material3
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=36;
						};
					};
				};
				class Under_base
				{
					name = "| Escavar zona base |";
					//is_base = 1;
					id = 2;
					required_parts[] = {"Under_entrance"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type=4;
					dismantle_action_type=4;
					material_type = 1;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Truck_01_WoodenLogs";
							quantity = 16;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Truck_01_WoodenPlanks";
							quantity = 20;
						};
						class Material3
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=36;
						};
					};
				};
				class under_door_t1
				{
					name = "| Porta |";
					is_gate = 1;
					id = 3;
					required_parts[] = {"Under_base"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Truck_01_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=10;
						};
					};
				};
				class upgradelock_t1
				{
					name = "| Reforcar abrigo |";
					id = 4;
					required_parts[] = {"Under_base"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type=4;
					dismantle_action_type=4;
					material_type = 1;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Truck_01_WoodenLogs";
							quantity = 16;
						};
						class Material2
						{
							type = "WoodenPlank";
							slot_name = "Truck_01_WoodenPlanks";
							quantity = 20;
						};
						class Material3
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=36;
						};
					};
				};
			};
		};
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
			class DamageZones
			{
				class under_door_t1
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
						healthLevels[]=	 {{1.01,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.01,{}}};
					};
					class ArmorType
					{
						class Projectile{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class Melee{
							class Health {damage=0;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
						class FragGrenade{
							//TENTAR ADICIONAR DANO POR GRANADA E ARMA
							class Health {damage=1;};
							class Blood  {damage=0;};
							class Shock	 {damage=0;};
						};
					};
					componentNames[]=	 {"under_door_t1"};
					fatalInjuryCoef=-1;
				};
			};
		};
	};

};