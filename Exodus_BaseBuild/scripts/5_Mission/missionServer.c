modded class MissionServer
{
	private ref ExodusConfig m_ExodusConfig;

    void MissionServer()
    {
        GetRPCManager().AddRPC("ExodusConfig", "GetExodusConfig", this, SingeplayerExecutionType.Server);
    }

    override void OnInit()
    {
        super.OnInit();
        
        Print("[ExodusConfig] Configuraçao do servidor carregando..."); 
       
        m_ExodusConfig = new ExodusConfig();
        g_Game.SetExodusConfig( m_ExodusConfig );
    }

    void GetExodusConfig(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type == CallType.Server && sender != null) //Verify that sender is still around so we don't send a null RPC ( sending and RPC with null target will send it to all players in the session )
        {
            Print("[ExodusConfig] MissionServer --> Sending instance of cfg to client: " + sender.GetName());
            GetRPCManager().SendRPC("ExodusConfig", "ExodusConfigStoreConfig", new Param1<ref ExodusConfig>( m_ExodusConfig ), true, sender);
        }
    }
}
