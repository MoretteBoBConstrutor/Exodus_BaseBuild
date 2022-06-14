modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        g_CraftServerManager = new CraftServerManager();
        g_CraftServerManager = CraftServerManager.LoadData();
    }

    void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
        g_CraftServerManager.SendTraderData(player);
	}
}