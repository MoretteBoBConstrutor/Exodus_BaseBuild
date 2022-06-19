modded class Hologram
{
	override protected vector GetProjectionEntityPosition ( PlayerBase player )
	{
		ItemBase item_in_hands;
		if ( player )
		{
			if ( player.GetHumanInventory() )
			{
				if ( player.GetHumanInventory().GetEntityInHands() )
				{
					item_in_hands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
				}
			}
		}
		if ( item_in_hands && item_in_hands.OpcaoDeAgarrar() )
		{
			if ( item_in_hands.EncaixeVertical() || item_in_hands.EncaixeHorizontal() || item_in_hands.EncaixeVerticalPilares() || item_in_hands.EncaixeHorizontalFundacao() || item_in_hands.EncaixeHorizontalDelta())
			{	
				EXD_Base m_exodusObjetosEncaixe;
				m_exodusObjetosEncaixe = ExodusObjetosDeEncaixe;
				if ( EncaixeAtivado && m_exodusObjetosEncaixe != NULL )
				{
					if ( item_in_hands.EncaixeVertical() )
					{
						SetIsFloating( false );
						return m_exodusObjetosEncaixe.PegarPontosEncaixeVertical();
					}
					if ( item_in_hands.EncaixeHorizontal() )
					{
						SetIsFloating( false );
						return m_exodusObjetosEncaixe.PegarPontosEncaixeHorizontal();
					}
					if ( item_in_hands.EncaixeVerticalPilares() )
					{
						SetIsFloating( false );
						return m_exodusObjetosEncaixe.PegarPontosEncaixeVerticalPilares();
					}
					if ( item_in_hands.EncaixeHorizontalFundacao() )
					{
						SetIsFloating( false );
						return m_exodusObjetosEncaixe.PegarPontosEncaixeHorizontalFundacao();
					}
					if (item_in_hands.EncaixeHorizontalDelta())
					{
						SetIsFloating( false );
						return m_exodusObjetosEncaixe.PegarPontosEncaixeHorizontalDelta();
					}
				}
			}
		}
		return super.GetProjectionEntityPosition(player);
	}
	//Projeta o Holograma baseado no Holograma requirido dentro do Kit.
	//Quase o mesmo sistema do Door and Barricades
	override string ProjectionBasedOnParent()
    {
        EXD_BaseKit exd_in_hands = EXD_BaseKit.Cast(m_Player.GetHumanInventory().GetEntityInHands());
        if ( exd_in_hands )
            return exd_in_hands.RequiredHologram();
		
        return super.ProjectionBasedOnParent();
    }
	//Baseado no MoreDoors, Doors and BArricades e Furniture Kits 1.0
    override void EvaluateCollision(ItemBase action_item = null)
    {
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		ItemBase exdfloor = EXDFloorCollision();
		if (item_in_hands && item_in_hands.IsInherited(EXD_BaseKit))
        {
            SetIsColliding(false);
            return;
        };
		if (item_in_hands && item_in_hands.IsInherited(Inventory_Base))
        {
            if (exdfloor)
            {
                SetIsColliding(false);
                return;
            }
        };
		
        super.EvaluateCollision(action_item);
    }
	//Baseado no Furniture Kits 1.0
	ItemBase EXDFloorCollision()
	{
		vector center;
		vector relative_ofset; //we need to lift BBox, because it is calculated from the bottom of projection, and not from the middle
		vector absolute_ofset = "0 0.01 0"; //we need to lift BBox even more, because it colliddes with house floors due to various reasons (probably geometry or float imperfections)
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		ref array<Object> excluded_objects = new array<Object>;
		ref array<Object> collided_objects = new array<Object>;
		m_Projection.GetCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2.4;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );
		if ( GetGame().IsBoxColliding( center, orientation, edge_length, excluded_objects, collided_objects ) )
		{
			for( int i = 0; i < collided_objects.Count(); i++ )
			{
				Object obj_collided = collided_objects[i];
				if( obj_collided.IsInherited(EXD_Roof) )
				{
					EXD_Roof exdroof = EXD_Roof.Cast(obj_collided);
					return exdroof;
				}
				if( obj_collided.IsInherited(EXD_Roof_Delta) )
				{
					EXD_Roof_Delta exdroofdeltta = EXD_Roof_Delta.Cast(obj_collided);
					return exdroofdeltta;
				}
				if( obj_collided.IsInherited(EXD_Roof_Hatch) )
				{
					EXD_Roof_Hatch exdroofhatch = EXD_Roof_Hatch.Cast(obj_collided);
					return exdroofhatch;
				}
				if( obj_collided.IsInherited(EXD_Floor) )
				{
					EXD_Floor exdfloor = EXD_Floor.Cast(obj_collided);
					return exdfloor;
				}
				if( obj_collided.IsInherited(EXD_Floor_Car) )
				{
					EXD_Floor_Car exdfloorcar = EXD_Floor_Car.Cast(obj_collided);
					return exdfloorcar;
				}
				if( obj_collided.IsInherited(EXD_Floor_Delta) )
				{
					EXD_Floor_Delta exdfloordelta = EXD_Floor_Delta.Cast(obj_collided);
					return exdfloordelta;
				}
				if( obj_collided.IsInherited(EXD_Floor_Hatch) )
				{
					EXD_Floor_Hatch exdfloorhatch = EXD_Floor_Hatch.Cast(obj_collided);
					return exdfloorhatch;
				}
				if( obj_collided.IsInherited(EXD_Stair_L) )
				{
					EXD_Stair_L exdstairl = EXD_Stair_L.Cast(obj_collided);
					return exdstairl;
				}
				if( obj_collided.IsInherited(EXD_Foundation) )
				{
					EXD_Foundation exdfoundation = EXD_Foundation.Cast(obj_collided);
					return exdfoundation;
				}
				//EXODUS WORKBENCH
				if( obj_collided.IsInherited(Exodus_Workbench) )
				{
					Exodus_Workbench exdwb = Exodus_Workbench.Cast(obj_collided);
					return exdwb;
				}
			}
		}
		return null;
	}
	//Orientaçao do Objeto
	override void SetProjectionOrientation( vector orientation ) 
	{
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		//Talvez criar uma variavel para a Bse dos kits ?
		//Ou permanecer usando esse metodo
		//Lembrete para testar depois
		if (item_in_hands.IsInherited(EXD_BaseKit))
		{
			m_Projection.SetOrientation( m_Rotation );
		}
		else
		{
			super.SetProjectionOrientation(orientation);
		}
	}

	//Matematica para rotaçao do objeto, estudar novos meios de deixar suave
	override vector GetProjectionRotation()
	{
		return m_Rotation;
	}
	
	override void AddProjectionRotation( float addition )
	{	
		m_Rotation[0] = m_Rotation[0] + (addition / Rotation_R);
	}
	
	override void SubtractProjectionRotation( float subtraction )
	{	
		m_Rotation[0] = m_Rotation[0] - (subtraction / Rotation_R);
	}

	override bool IsFloating() 
	{
		if (!super.IsFloating())
			return false;

		return m_IsFloating;
	}
}

int Rotation_R = 1;
static bool sendMensage_R = false;
static bool sendMensage_R()
{
	return sendMensage_R;
}
static void MensageSend_R()
{
    sendMensage_R = !sendMensage_R;
	PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
	string Picture = "set:dayz_inventory image:paper";
	if (sendMensage_R)
	{

		NotificationSystem.AddNotificationExtended(0.5, "BaseBuild", "Rotaçao lenta ativada", Picture);
		//GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "BaseBuild", "Rotaçao lenta ativada", "RED"));
		Rotation_R = 6;
		//Print("Rotation Change Test");
	}
	else
	{
		
		NotificationSystem.AddNotificationExtended(0.5, "BaseBuild", "Rotaçao lenta desativada", Picture);
		//GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "BaseBuild", "Rotaçao lenta desativada", "RED"));
		Rotation_R = 1;
	}
}
