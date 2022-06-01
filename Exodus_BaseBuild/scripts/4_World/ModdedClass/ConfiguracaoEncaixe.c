ItemBase ExodusObjetosDeEncaixe;
//Inteiros para pontos maximos de rotaçao
static int PontosEncaixeVertical = 0;
static int PontosEncaixeHorizontal = 0;
static int PontosEncaixeVerticalPilares = 0;
static int PontosEncaixeHorizontalFundacao = 0;
//Ativa o Encaie e Seleciona o Alvo do encaixe
static bool EncaixeAtivado = true;
static bool EncaixeAtivadoEscaneando = true;
//Quantidade maxima de rotaçoes / Pontos permitidos
static const int PontosMaximosEncaixeVertical = 7;
static const int PontosMaximosEncaixeHorizontal = 3;
static const int PontosMaximosEncaixeVerticalPilares = 4;
static const int PontosMaximosEncaixeHorizontalFundacao = 8;


static void ProcurePontosEncaixeVertical()
{
	PontosEncaixeVertical = PontosEncaixeVertical + 1;
	if(PontosEncaixeVertical > PontosMaximosEncaixeVertical)
	{
		PontosEncaixeVertical = 0;
	}
}
static void ProcurePontosEncaixeHorizontal()
{
	PontosEncaixeHorizontal = PontosEncaixeHorizontal + 1;
	if(PontosEncaixeHorizontal > PontosMaximosEncaixeHorizontal)
	{
		PontosEncaixeHorizontal = 0;
	}
}
static void ProcurePontosEncaixeVerticalPilares()
{
	PontosEncaixeVerticalPilares = PontosEncaixeVerticalPilares + 1;
	if(PontosEncaixeVerticalPilares > PontosMaximosEncaixeVerticalPilares)
	{
		PontosEncaixeVerticalPilares = 0;
	}
}
static void ProcurePontosEncaixeHorizontalFundacao()
{
	PontosEncaixeHorizontalFundacao = PontosEncaixeHorizontalFundacao + 1;
	if(PontosEncaixeHorizontalFundacao > PontosMaximosEncaixeHorizontalFundacao)
	{
		PontosEncaixeHorizontalFundacao = 0;
	}
}

static void AtivarEncaixe()
{
	EncaixeAtivado = !EncaixeAtivado;
}

static void SelecionarAlvoDeEncaixe()
{
	EncaixeAtivadoEscaneando = !EncaixeAtivadoEscaneando;
}

//Açoes para selecionar alvo dos Encaixes

static set< Object > PegarObjetoDeEncaixeNoAlcance( vector from, vector to, Object ignore = NULL, float radius = 0, Object with = NULL )
{
    vector contact_pos;
    vector contact_dir;
    int contact_component;

    set< Object > view = new set< Object >;

    DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, view, with, ignore, false, false, ObjIntersectView, radius );

    if ( view ) 
    {
        return view;
    }
    return NULL;
}
Object SelecionarObjetoEncaixeNoAlcance(float distance = 1000.0, float radius = 0, Object with = NULL)
{
	vector rayStart = GetGame().GetCurrentCameraPosition();
	vector rayEnd = rayStart + GetGame().GetCurrentCameraDirection() * distance;

	auto objs = PegarObjetoDeEncaixeNoAlcance( rayStart, rayEnd, GetGame().GetPlayer(), radius, with );

	if( objs.Count() > 0 )
	{
		return objs[ 0 ];
	}

	return NULL;
}

void SelecaoEncaixe()
{		
	ExodusObjetosDeEncaixe = ItemBase.Cast(EncaixeComOutrasPartes());	
}

Object EncaixeComOutrasPartes()
{
	Object objetoAlvo = SelecionarObjetoEncaixeNoAlcance();
	
	if (objetoAlvo.IsInherited(EXD_Base))
	{
		return objetoAlvo;
	}
	
	return null;
}

//PlayerBase
modded class PlayerBase
{
	bool DistanciaApropriadaParaSelecionar( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance >= 6 )
			{
				return false;
			}
		}
		return true;
	}

	bool sendMensage = false;
	bool sendMensage()
	{
 		return sendMensage;
	}
	void MensageSend()
	{
        sendMensage = !sendMensage;
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		string Picture = "set:dayz_inventory image:paper";
		if (sendMensage)
		{
			//GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "BaseBuild", "Encaixe desativado", "GREEN"));
			//NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 30.0, "BaseBuild", "Encaixe Desativado", "");
			NotificationSystem.AddNotificationExtended(0.5, "BaseBuild", "Encaixe Desativado", Picture);
		}
		else
		{
			//GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "BaseBuild", "Encaixe Ativado", "GREEN"));
			//NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 30.0, "BaseBuild", "Encaixe Ativado", "");
			NotificationSystem.AddNotificationExtended(0.5, "BaseBuild", "Encaixe Ativado", Picture);
		}
	}

	bool senMenssageKeyK = false;
	bool senMenssageKeyK()
	{
 		return senMenssageKeyK;
	}
	void MensageSendKeyK()
	{
		//PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        senMenssageKeyK = !senMenssageKeyK;
		if (senMenssageKeyK)
		{
			GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "BaseBuild", "Fixaçao no Alvo Ativada", "RED"));
			//Print("PlayerBase. Tecla B Apertada Encaixe Desativado")
			//NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Fixaçao no Alvo Ativada", "Precione K perto do Alvo", "");
		}
		else
		{
			GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "BaseBuild", "Fixaçao no Alvo Desativada", "RED"));
			//Print("PlayerBase. Tecla B Apertada Encaixe Ativado")
			//NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Fixaçao no Alvo Desativada", "Precione K perto do Alvo", "");
		}
	}
}





