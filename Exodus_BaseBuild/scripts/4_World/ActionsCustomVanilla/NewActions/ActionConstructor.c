modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);                	
        actions.Insert(ActionFoldLadder);
    }
}
//Introduz a açao ao jogador
modded class PlayerBase
{
	override void SetActions(out TInputActionMap InputActionMap)
	{	
		super.SetActions(InputActionMap);
		AddAction(ActionFoldLadder, InputActionMap);
	}
}
