/* Doors And Barricades */
modded class VicinityItemManager
{
	override bool IsObstructed (Object filtered_object)
	{
		if ( filtered_object.CanUseConstruction() )
		{
			EXD_Base exdbase = EXD_Base.Cast( filtered_object );
			if ( exdbase )
			{
				return false;
			}
		}
		
		return super.IsObstructed (filtered_object);
	}
}
