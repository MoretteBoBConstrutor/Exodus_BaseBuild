modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);                	
        actions.Insert(ActionFoldLadder);
        actions.Insert(ActionTeleportUnderGroud);
        actions.Insert(ActionTeleportUnderGroudLeave);
        actions.Insert(ActionCreateUnderGroud);
    }
}
//Introduz a açao ao jogador
modded class PlayerBase
{
	override void SetActions(out TInputActionMap InputActionMap)
	{	
		super.SetActions(InputActionMap);
		AddAction(ActionFoldLadder, InputActionMap);
        AddAction(ActionTeleportUnderGroud, InputActionMap);
        AddAction(ActionTeleportUnderGroudLeave, InputActionMap);
	}
}
