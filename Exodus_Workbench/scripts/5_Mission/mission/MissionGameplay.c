modded class MissionGameplay
{
	override void OnInit()
	{
		super.OnInit();
		
		g_CraftManager	=	new CraftManager();

	}

	override void OnKeyPress( int key )
	{
		super.OnKeyPress( key );

		g_CraftManager.OnKeyPress( key );
	}
}