class EXD_Base extends Fence
{
	typename ATTACHMENT_BARBED_WIRE				= BarbedWire;
	const string ATTACHMENT_SLOT_BARBED_WIRE 	= "Wall_BarbedWire_1";

	void EXD_Base()
	{
	}
	
	ItemBase CreateConstructionKit()
	{
		ItemBase construction_kit = ItemBase.Cast( GetGame().CreateObjectEx( GetConstructionKitType(), GetKitSpawnPosition(), ECE_PLACE_ON_SURFACE ) );
		if ( m_ConstructionKitHealth > 0 )
		{
			construction_kit.SetHealth( m_ConstructionKitHealth );
		}
		
		return construction_kit;
	}
	
	protected vector GetKitSpawnPosition()
	{
		//Isso esta no vanilla
		if ( MemoryPointExists( "kit_spawn_position" ) )
		{
			vector position;
			position = GetMemoryPointPos( "kit_spawn_position" );
			
			return ModelToWorld( position );
		}
		//Obrigado InclementDab pela ajuda <3
		Man player = GetHierarchyRootPlayer();
		return player.GetPosition();
	}

	protected string GetConstructionKitType()
	{
		return "";
	}
	
	// --- INVENTORY
	override bool CanDisplayAttachmentSlot( string slot_name )
	{
		if (!super.CanDisplayAttachmentSlot(slot_name))
			return false;

		if ( slot_name == "Att_CombinationLock" )
		{
			if ( !HasFullyConstructedGate() )
			{
				return false;
			}
		}

		if ( !GateAttachmentConditions(InventorySlots.GetSlotIdFromString(slot_name)) )
			return false;
		
		return true;
	}
	
	override bool CanDisplayAttachmentCategory( string category_name )
	{
		if ( category_name == "Attachments" || category_name == "Camonet")
		{
			if ( !HasBase() )
			{
				return false;
			}
		}
		
		return true;
	}
	
	//--- ACTION CONDITIONS
	override bool IsPlayerInside( PlayerBase player, string selection )
	{
		if ( IsIrregularPart() == false )
		{
			if ( IsFacingPlayer( player, "EXD_Base" ) )
			{return false;}
			if ( DistanceNormalPart( "center", player ) == false )
			{return false;}
		}
		if ( IsIrregularPart() == true && DistanceNormalPart( "center", player ) == false)
		{return false;}
		
		return true;
	}
	
	override bool NameOverride(out string output)
	{
		if ( m_GateState != GATE_STATE_NONE )
		{
			output = "Gate";
			output.ToUpper();
			return true;
		}
		return false;
	}
	
	//CRIADO PARA MOSTRAR ONDE O PLAYER PODE ANEXAR OS MAERIAIS E CONSTRUIR AS MELHORIAS
	bool IsUpgradeMaterialsAttached()
	{
		ItemBase materials_plank;
		ItemBase materials_nails;
		ItemBase materials_logs;
		int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString("Material_WoodenPlanks");
		materials_plank = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slot_id = InventorySlots.GetSlotIdFromString("Material_Nails");
		materials_nails = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slot_id = InventorySlots.GetSlotIdFromString("Material_L1_WoodenLogs");
		materials_logs = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		if ( materials_plank || materials_nails || materials_logs )
		{
			return true;
		}
		return false;
	}
	
	bool IsCamonet()
	{
		ItemBase materials_camonet;
		int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString("Wall_Camonet");
		materials_camonet = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		
		string itemname = materials_camonet.GetType();
		
		if ( itemname == "CamoNet" )
		{
			return true;
		}
		return false;
	}

	/* CamoNet exodus para textura diferente da camonet
	bool IsCamonetExodus()
	{
		int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString("Wall_Camonet");
		ItemBase materials_camonet = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		string itemname = materials_camonet.GetType();
		if ( itemname == "CamoNetExodus" )
		{
			return true;
		}
		return false;
	}
	*/

	//--- ATTACHMENT & CONDITIONS
	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			if ( player )
			{
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				construction_action_data.SetActionInitiator( NULL );				
			}
		}

		if ( attachment.IsInherited( ATTACHMENT_COMBINATION_LOCK ) )
		{
			return ( HasFullyConstructedGate() && !IsOpened() );
		}

		if ( !GateAttachmentConditions(slotId) )
			return false;
		
		return true;
	}
	// Mostra o Lugar onde o jogador tem que construir
	void RefreshBuildLocation()
	{
		if (IsUpgradeMaterialsAttached() == true)
		{
			if(HasBase())
			{
				SetAnimationPhase( "Build_holo", 0 );
			}
		}
		else if (IsUpgradeMaterialsAttached() == false)
		{
			if(HasBase())
			{
				SetAnimationPhase( "Build_holo", 1 );
			}
		}
	}

	void RefreshCamonet()
	{
		if (IsCamonet() == true)
		{
			if(HasBase())
			{	
				if(HasFullyConstructedGate())
				{
					SetAnimationPhase( "GateCamonet", 0 );
					SetAnimationPhase( "WallCamonet", 0 );
				}
				else if(!HasFullyConstructedGate())
				{
					SetAnimationPhase( "WallCamonet", 0 );
					SetAnimationPhase( "GateCamonet", 1 );
				}
			}
		}
		if (IsCamonet() == false)
		{
			SetAnimationPhase( "GateCamonet", 1 );
			SetAnimationPhase( "WallCamonet", 1 );
		}

		/* if (IsCamonetExodus() == true)
		{
			if(HasBase())
			{	
				if(HasFullyConstructedGate())
				{
					SetAnimationPhase( "GateCamonetExodus", 0 );
					SetAnimationPhase( "WallCamonetExodus", 0 );
				}
				else if(!HasFullyConstructedGate())
				{
					SetAnimationPhase( "WallCamonetExodus", 0 );
					SetAnimationPhase( "GateCamonetExodus", 1 );
				}
			}
		}
		if (IsCamonetExodus() == false)
		{
			SetAnimationPhase( "GateCamonetExodus", 1 );
			SetAnimationPhase( "WallCamonetExodus", 1 );
		} */
	}

	
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		CheckForHybridAttachments( item, slot_name );
		UpdateVisuals();
		RefreshBuildLocation();
		RefreshCamonet();
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		UpdateVisuals();
		RefreshBuildLocation();
		RefreshCamonet();
	}
	
	protected void OnSetSlotLock( int slotId, bool locked, bool was_locked )
	{
		string slot_name = InventorySlots.GetSlotName( slotId );
		bsbDebugPrint( "inv: OnSetSlotLock " + GetDebugName( this ) + " slot=" + slot_name + " locked=" + locked + " was_locked=" + was_locked );

		UpdateAttachmentVisuals( slot_name, locked );
	}

	override void OnPartBuiltServer( notnull Man player, string part_name, int action_id )
	{
		ConstructionPart construction_part = GetConstruction().GetConstructionPart( part_name );

		if ( construction_part.IsBase() )
		{
			SetBaseState( true );
			SetAnimationPhase( "Hologram", 		1 );
			CreateConstructionKit();
		}

		if( GatePartConstruct() )
		{
			if ( construction_part.IsGate() )
			{
				SetGateState( true );
			}
		}
		
		//register constructed parts for synchronization
		RegisterPartForSync( construction_part.GetId() );
		
		//register action that was performed on part
		RegisterActionForSync( construction_part.GetId(), action_id );
		
		//synchronize
		SynchronizeBaseState();
		
		if (GetGame().IsMultiplayer() && GetGame().IsServer())
			SetPartFromSyncData(construction_part); // server part of sync, client will be synced from SetPartsFromSyncData
		
		//reset action sync data
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( ResetActionSyncData, 100, false, this );
		
		//set gate state
		if( GatePartConstruct() )
		{
			SetGateState( CheckGateState() );
		}
		
		//drop attachments without carrier part
		if (construction_part.IsGate())
			//GateAttachmentsSanityCheck();
		
		//update visuals (server)
		RefreshCamonet();
		UpdateVisuals();
	}
	
	override void OnPartDismantledServer( notnull Man player, string part_name, int action_id )
	{
		bsbDebugPrint("[bsb] " + GetDebugName(this) + " OnPartDismantledServer " + part_name);
		ConstructionPart construction_part = GetConstruction().GetConstructionPart( part_name );
		
		//register constructed parts for synchronization
		UnregisterPartForSync( construction_part.GetId() );
		
		//register action that was performed on part
		RegisterActionForSync( construction_part.GetId(), action_id );
		
		//synchronize
		SynchronizeBaseState();

		// server part of sync, client will be synced from SetPartsFromSyncData
		SetPartFromSyncData( construction_part );
		
		//reset action sync data
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( ResetActionSyncData, 100, false, this );
		
		//check base state
		if ( construction_part.IsBase() )
		{
			//Destroy construction
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( DestroyConstruction, 200, false, this );
		}
		if( GatePartConstruct() )
		{
			SetGateState( CheckGateState() );
		}
		if( GatePartConstruct() )
		{
			if ( construction_part.IsGate() )
			{
				if ( IsLocked() )
				{
					CombinationLock combination_lock = CombinationLock.Cast( FindAttachmentBySlotName( ATTACHMENT_SLOT_COMBINATION_LOCK ) );
					combination_lock.UnlockServer( player , this );
				}
			}			
		}
		
		//update visuals (server)
		RefreshCamonet();
		UpdateVisuals();
	}

	override void OnPartDestroyedServer( Man player, string part_name, int action_id, bool destroyed_by_connected_part = false )
	{
		super.OnPartDestroyedServer( player, part_name, action_id );
		
		//check gate state
		ConstructionPart construction_part = GetConstruction().GetConstructionPart( part_name );
		if ( GatePartConstruct() && construction_part.IsGate() /* && part_name != "exd_wall_w_door_t1" */ )
		{
			//drop regular attachments
			HandleDropAttachment(GetBarbedWire1());
			HandleDropAttachment(GetCombinationLock());
			//rotate back to place
			if ( IsOpened() )
				CloseFence();
		}
		/* if (part_name == "exd_wall_w_door_t1")
		{
			HandleDropAttachment(GetCombinationLock());
		} */

		RefreshCamonet();
	}
	
	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
		super.EEHealthLevelChanged(oldLevel,newLevel,zone);

		Construction construction = GetConstruction();
		string part_name = zone;
		part_name.ToLower();
		if ( newLevel == GameConstants.STATE_RUINED )
		{
			ConstructionPart construction_part = construction.GetConstructionPart( part_name );
			
			if ( construction_part && construction.IsPartConstructed( part_name ) )
			{
				construction.DestroyPartServer( null, part_name, AT_DESTROY_PART );
				construction.DestroyConnectedParts(part_name);
			}
			
			//barbed wire handling (hack-ish)
			if ( part_name.Contains("barbed") )
			{
				BarbedWire barbed_wire = BarbedWire.Cast( FindAttachmentBySlotName( zone ) );
				if (barbed_wire)
					barbed_wire.SetMountedState( false );
			}
		}
		UpdateVisuals();
	}
	
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );

		//Write
		ctx.Write( m_GateState );
		ctx.Write( m_IsOpened );
		bsbDebugPrint("[bsb] OnStoreSave - build=" + m_GateState + " opened=" + m_IsOpened);
	}
	
	override void AfterStoreLoad()
	{	
		//if (!m_FixDamageSystemInit)
		//{
		//	SetPartsAfterStoreLoad();
		//}
		//check base state
		if ( !HasBase() )
		{
			//show hologram
			SetAnimationPhase( "Hologram", 	0 );
		}
		
		//update server data
		SetPartsFromSyncData();
		
		//set base state
		ConstructionPart construction_part = GetConstruction().GetBaseConstructionPart();
		SetBaseState( construction_part.IsBuilt() );
		
		//set gate state
		if ( GatePartConstruct() )
		{
			ConstructionPart gate_part = GetConstruction().GetGateConstructionPart();
			SetGateState( CheckGateState() );
		}

		if ( IsOpened() )
		{
			OpenFence();
		}
		
		UpdateVisuals();
		
		bsbDebugPrint("[bsb] AfterStoreLoad - build=" + "false" + " opened=" + IsOpened());
		
		//synchronize after load
		SynchronizeBaseState();
	}
	
	override void OpenFence()
	{	
		//server or single player
		if ( GetGame().IsServer() )
		{
			float value = GATE_ROTATION_ANGLE_DEG;
			SetAnimationPhase( "Wall_Interact_Rotate", 				value );
			SetAnimationPhase( "Wall_Barbedwire_1_Mounted_Rotate", 	value );
			SetAnimationPhase( "Wall_Barbedwire_2_Mounted_Rotate", 	value );
			SetAnimationPhase( "Wall_Camonet_Rotate", 				value );
			SetAnimationPhase( "Wall_Gate_Rotate", 					value );
			SetAnimationPhase( "Wall_Base_Down_Rotate", 			value );
			SetAnimationPhase( "Wall_Base_Up_Rotate", 				value );
			SetAnimationPhase( "Wall_Wood_Down_Rotate", 			value );
			SetAnimationPhase( "Wall_Wood_Up_Rotate", 				value );
			SetAnimationPhase( "Wall_Metal_Down_Rotate", 			value );
			SetAnimationPhase( "Wall_Metal_Up_Rotate", 				value );
			
			SetOpenedState( true );
			
			//regenerate navmesh
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, GATE_ROTATION_TIME_APPROX, false );
			
			//synchronize
			SynchronizeBaseState();
		}
		
		//client or single player
		if ( !GetGame().IsDedicatedServer() )
		{
			//play sound
			SoundGateOpenStart();
		}
		
		//remove BarbedWire AreaDamageTrigger
		UpdateBarbedWireAreaDamagePos(0,true);
		
		//add check
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Remove(CheckFenceClosed);
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( CheckFenceOpened, 0, true );	
	}

	override void CloseFence()
	{
		//server or single player
		if ( GetGame().IsServer() )
		{
			float value = 0;
			SetAnimationPhase( "Wall_Interact_Rotate", 				value );
			SetAnimationPhase( "Wall_Barbedwire_1_Mounted_Rotate", 	value );
			SetAnimationPhase( "Wall_Barbedwire_2_Mounted_Rotate", 	value );
			SetAnimationPhase( "Wall_Camonet_Rotate", 				value );
			SetAnimationPhase( "Wall_Gate_Rotate", 					value );
			SetAnimationPhase( "Wall_Base_Down_Rotate", 			value );
			SetAnimationPhase( "Wall_Base_Up_Rotate", 				value );
			SetAnimationPhase( "Wall_Wood_Down_Rotate", 			value );
			SetAnimationPhase( "Wall_Wood_Up_Rotate", 				value );
			SetAnimationPhase( "Wall_Metal_Down_Rotate", 			value );
			SetAnimationPhase( "Wall_Metal_Up_Rotate", 				value );
			
			SetOpenedState( false );
			
			//regenerate navmesh
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, GATE_ROTATION_TIME_APPROX, false );
			
			//synchronize
			SynchronizeBaseState();
		}
		
		//client or single player
		if ( !GetGame().IsDedicatedServer() )
		{
			//play sound
			SoundGateCloseStart();
		}
		
		//remove BarbedWire AreaDamageTrigger
		UpdateBarbedWireAreaDamagePos(0,true);
		
		//add check
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Remove(CheckFenceOpened);
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( CheckFenceClosed, 0, true );	
	}

	void CheckFenceOpened()
	{
		if ( GetAnimationPhase( "Wall_Gate_Rotate" ) == GATE_ROTATION_ANGLE_DEG )			//animation finished - open
		{
			UpdateBarbedWireAreaDamagePos(GetAnimationPhase( "Wall_Gate_Rotate" ));
			//remove check
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Remove( CheckFenceOpened );
		}
	}

	override void CheckFenceClosed()
	{
		if ( GetAnimationPhase( "Wall_Gate_Rotate" ) == 0 )			//animation finished - closed
		{
			//client or single player
			if ( !GetGame().IsDedicatedServer() )
			{
				//play sound
				if ( this ) SoundGateCloseEnd();
			}
			UpdateBarbedWireAreaDamagePos(GetAnimationPhase( "Wall_Gate_Rotate" ));
			//remove check
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Remove( CheckFenceClosed );
		}
	}

	override void CreateAreaDamage( string slot_name, float rotation_angle = 0 )
    {
        if ( IsOpened() )
		{
			rotation_angle = 100;
		}
		
		super.CreateAreaDamage( slot_name, rotation_angle );
    }
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionFoldBaseBuildingObject);
		AddAction(ActionDialCombinationLockOnTarget);
		AddAction(ActionNextCombinationLockDialOnTarget);
	}
};



