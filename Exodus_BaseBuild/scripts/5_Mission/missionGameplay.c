modded class MissionGameplay
{
	void MissionGameplay()
	{
		GetRPCManager().AddRPC("ExodusConfig", "ExodusConfigStoreConfig", this, SingeplayerExecutionType.Client);
		GetRPCManager().SendRPC("ExodusConfig", "GetExodusConfig", null, true, null); 
	}

	void ExodusConfigStoreConfig(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        ref Param1<ref ExodusConfig> data;
        if (type == CallType.Client)
		{
			if (!ctx.Read(data)) return;

			g_Game.SetExodusConfig( data.param1 );
			Print("[ExodusConfig] MissionGameplay --> Got instance of cfg: " + data.param1);
		}
    }
}

/* 	
	UTILIZADO PARA ENVIAR MENSAGEM AO CLIENTE OU SERVER
	Thanks S4MT3Kツ#0544
	modded class MissionGameplay
	{
	    override void OnKeyPress(int key)
	    {
	        PlayerBase m_Player = PlayerBase.Cast(GetGame().GetPlayer());
	
	        super.OnKeyPress(key);
	
	        if (key == KeyCode.KC_N)
	        {
	            if (m_Player)
	            {
	                if (GetGame().IsServer())
	                {
	                    GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "ADMIN - PRÄFIX", "ServerSide - PUT TEXT HERE", "RED - COLOR"));
	                }

	                if (GetGame().IsClient())
	                {
	                    GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "ADMIN - PRÄFIX", "ClientSide - PUT TEXT HERE", "RED - COLOR"));
	                }
	            }
	        }
	    }
	}
*/
modded class MissionGameplay
{

	override void OnKeyRelease(int key)
	{
		super.OnKeyRelease(key);

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		ItemBase item_in_hands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
		if (!player) return;
		
		if ( key == KeyCode.KC_B )
		{
			if (item_in_hands != NULL && item_in_hands.OpcaoDeAgarrar())
			{
				if (item_in_hands.EncaixeVertical() || item_in_hands.EncaixeHorizontal() || item_in_hands.EncaixeVerticalPilares() || item_in_hands.EncaixeHorizontalFundacao && item_in_hands != NULL)
				{	
					AtivarEncaixe();
					player.MensageSend();
				}
			}
        }
		if ( key == KeyCode.KC_K ) 
		{
			if (item_in_hands != NULL && item_in_hands.OpcaoDeAgarrar())
			{
				if (item_in_hands.EncaixeVertical() || item_in_hands.EncaixeHorizontal() || item_in_hands.EncaixeVerticalPilares() || item_in_hands.EncaixeHorizontalFundacao() && item_in_hands != NULL)
				{	
					SelecaoEncaixe();
					SelecionarAlvoDeEncaixe();
					player.MensageSendKeyK();
				} 
			}
        }
		if ( key == KeyCode.KC_F )
		{
			if (item_in_hands != NULL && item_in_hands.OpcaoDeAgarrar())
			{
				if (item_in_hands.EncaixeVertical())
				{	
					ProcurePontosEncaixeVertical();
				}
				if (item_in_hands.EncaixeHorizontal())
				{	
					ProcurePontosEncaixeHorizontal();
				}
				if (item_in_hands.EncaixeVerticalPilares())
				{
					ProcurePontosEncaixeVerticalPilares();
				}
				if (item_in_hands.EncaixeHorizontalFundacao())
				{
					ProcurePontosEncaixeHorizontalFundacao();
				}
			}
		}
    }

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		ItemBase item_in_hands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
		if (EncaixeAtivadoEscaneando)
		{
			if (item_in_hands != NULL && item_in_hands.OpcaoDeAgarrar())
			{
				if (item_in_hands.EncaixeVertical() || item_in_hands.EncaixeHorizontal() || item_in_hands.EncaixeVerticalPilares() || item_in_hands.EncaixeHorizontalFundacao() && item_in_hands != NULL)
				{
					if (SelecionarObjetoEncaixeNoAlcance().IsInherited(EXD_Base))
					{
						SelecaoEncaixe();
					}
				}
			}
		}
	}
}
