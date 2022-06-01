//Doors And Barricades

class ExodusConfig
{
	static const string MODCONFIG_ROOT_FOLDER = "$profile:Exodus_BaseBuild/";
    static const string CONFIG_PATH = MODCONFIG_ROOT_FOLDER + "Exodus_BaseBuild_Settings.json";
	
	//Variaveis dos Kits
	private bool CanDestroyConstructions;
	private bool CanDismnatleConstructions;
	private bool CanCraftConstructionsKits;
	private bool CanCraftCVanillarFenceKit;
	private bool CanCraftCVanillarWatchTowerKit;
	private bool CanCutComboLock;
	private bool CanRaidOnlyDoors;
	//Ferramentas de Raid
	private ref array<string> BuildTools;
	private ref array<string> DismantleTools; 
    private ref array<string> RaidToolsT1;
    private ref array<string> RaidToolsT2;
    private ref array<string> RaidToolsT3;
	//Tempos de Destruição e Construçao
	private int BuildTime;
	private int DismantleTime;
	private int DestroyTimeDefault;
	private int DestroyTimeT1;
	private int DestroyTimeT2;
	private int DestroyTimeT3;
	//Loop para detruiçao
	private int LoopToDestructT1;
	//Danos a Ferramentas
	private int BuildToolDamage;
	private int DismantleToolDamage;
	private int RaidToolDamageT1;
	private int RaidToolDamageT2;
	private int RaidToolDamageT3;

	void ExodusConfig()
	{
		if (!GetGame().IsServer()) return;

		if (!FileExist(MODCONFIG_ROOT_FOLDER))
        {
            Print("[ExodusConfig] '" + MODCONFIG_ROOT_FOLDER + "' Nao existe, criando diretorio!");
            MakeDirectory(MODCONFIG_ROOT_FOLDER);
        }

        if (!FileExist(CONFIG_PATH))
        {
            Print("[ExodusConfig] '" + CONFIG_PATH + "' Nao existe, criando configuraçao padrao!");
            Default();
            return;
        }

        Load();
    }

	bool Load()
    {
        if (FileExist(CONFIG_PATH))
        {
            Print("[ExodusConfig] '" + CONFIG_PATH + "' encontrado, carregando configuraçao existente!");
            JsonFileLoader<ExodusConfig>.JsonLoadFile(CONFIG_PATH, this);
            return true;
        }
        return false;
    }

	protected void Save()
    {
        JsonFileLoader<ExodusConfig>.JsonSaveFile(CONFIG_PATH, this);
    }

	protected void Default()
    {
		CanDestroyConstructions 	   = true;
		CanDismnatleConstructions      = true;
		CanCraftConstructionsKits      = true;
		CanCraftCVanillarFenceKit      = false;
		CanCraftCVanillarWatchTowerKit = false;
		CanRaidOnlyDoors			   = false;

		BuildTools  	   = {"Hatchet", "Hammer"};
		DismantleTools	   = {"Hatchet", "Crowbar"};
		RaidToolsT1 	   = { "SledgeHammer", "FirefighterAxe", "WoodAxe"};
		RaidToolsT2 	   = { "SledgeHammer", "FirefighterAxe"};
		RaidToolsT3 	   = { "SledgeHammer" };

		BuildTime 	  	   = 10;
		DismantleTime 	   = 30;
		DestroyTimeDefault = 10;
		LoopToDestructT1   = 4;
		DestroyTimeT1 	   = 10;
		DestroyTimeT2 	   = 900;
		DestroyTimeT3 	   = 1800;

		BuildToolDamage     = 5;
		DismantleToolDamage = 5;
		RaidToolDamageT1    = 50;
		RaidToolDamageT2    = 100;
		RaidToolDamageT3    = 1000;

		Save();
	}
	//Permição de construções
	bool Get_CanDestroyConstructions()
	{
		return CanDestroyConstructions;
	}
	bool Get_CanDismnatleConstructions()
	{
		return CanDismnatleConstructions;
	}
	bool Get_CanCraftConstructionsKits()
	{
		return CanCraftConstructionsKits;
	}
	bool Get_CanCraftCVanillarFenceKit()
	{
		return CanCraftCVanillarFenceKit;
	}
	bool Get_CanCraftCVanillarWatchTowerKit()
	{
		return CanCraftCVanillarWatchTowerKit;
	}
	bool Get_CanRaidOnlyDoors()
	{
		return CanRaidOnlyDoors;
	}
	//Ferramentas para ações
	ref array<string> Get_BuildTools()
	{
		return BuildTools;
	}
	ref array<string> Get_DismantleTools()
	{
		return DismantleTools;
	}
	ref array<string> Get_RaidToolsT1()
	{
		return RaidToolsT1;
	}
	ref array<string> Get_RaidToolsT2()
	{
		return RaidToolsT2;
	}
	ref array<string> Get_RaidToolsT3()
	{
		return RaidToolsT3;
	}
	//Dano a ferramenta apos ação
	int Get_BuildToolDamage()
	{
		return BuildToolDamage;
	}
	int Get_DismantleToolDamage()
	{
		return DismantleToolDamage;
	}
	int Get_RaidToolDamageT1()
	{
		return RaidToolDamageT1;
	}
	int Get_RaidToolDamageT2()
	{
		return RaidToolDamageT2;
	}
	int Get_RaidToolDamageT3()
	{
		return RaidToolDamageT3;
	}
	//Loop para destruir
	int Get_LoopToDestructT1()
	{
		return LoopToDestructT1;
	}
	//Tempos para ações
	int Get_BuildTime()
	{
		return BuildTime;
	}
	int Get_DismantleTime()
	{
		return DismantleTime;
	}
	int Get_DestroyTimeDefault()
	{
		return DestroyTimeDefault;
	}
	int Get_DestroyTimeT1()
	{
		return DestroyTimeT1;
	}
	int Get_DestroyTimeT2()
	{
		return DestroyTimeT2;
	}
	int Get_DestroyTimeT3()
	{
		return DestroyTimeT3;
	}
};

