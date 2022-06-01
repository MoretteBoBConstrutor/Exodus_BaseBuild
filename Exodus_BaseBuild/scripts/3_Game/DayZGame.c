modded class DayZGame
{
    private ref ExodusConfig m_ExodusConfig;

    ref ExodusConfig GetExodusConfig()
    {
        if (m_ExodusConfig)
        {
            return m_ExodusConfig;
        }

        Print("[ExodusConfig] DayZGame --> NAo foi possivel achar o aquiquivo de configuracao ExodusConfig...");
	    return null;
    }

    void SetExodusConfig(ref ExodusConfig cfg)
	{
		m_ExodusConfig = cfg;
	}
}