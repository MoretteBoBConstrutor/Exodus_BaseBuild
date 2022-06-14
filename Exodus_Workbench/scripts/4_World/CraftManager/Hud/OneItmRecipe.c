class OneRecipe
{
    private Widget                  item;
    private ImageWidget             m_OneItemImage; 
    private MultilineTextWidget     m_OneItem;
    private ButtonWidget            m_OneItemButtonWidget;
    private EditBoxWidget           m_OneItemStorage;

    const string    RepairPath = "Exodus_Workbench/scripts/4_World/layout/repair.edds";
    const string    PaintPath = "Exodus_Workbench/scripts/4_World/layout/paint.edds";
    const string    CraftPath = "Exodus_Workbench/scripts/4_World/layout/craft.edds";

    PlayerBase player;

    ref CraftItem m_CraftItem;
    int m_Test;
    
    void OneRecipe()
    {
        player = PlayerBase.Cast(GetGame().GetPlayer());
    }

    Widget Init( Widget parent, string name, string type)
    {
        item = GetGame().GetWorkspace().CreateWidgets("Exodus_Workbench/scripts/4_World/layout/OneItemRecipe.layout", parent);
        m_OneItemImage = ImageWidget.Cast(item.FindAnyWidget("OneItemImage"));
        m_OneItem = MultilineTextWidget.Cast(item.FindAnyWidget("OneItem"));
        m_OneItemButtonWidget = ButtonWidget.Cast(item.FindAnyWidget("OneItemButtonWidget"));
        m_OneItemStorage = EditBoxWidget.Cast(item.FindAnyWidget("OneItemStorage"));

        m_OneItem.SetText(name);
        SetImage(type);
        return item;
    }

    void SetImage(string type)
    {
        if ( !m_OneItemImage.LoadImageFile(0, GetTypePath(type)) )
        {
            m_OneItemImage.LoadImageFile(0, GetVanilaTypePath(type));
        }
    }

    string GetVanilaTypePath(string val)
    {
        switch (val)
        {
            case "repair":
                return RepairPath;
            break;
            case "paint":
                return PaintPath;
            break;
            case "craft":
                return CraftPath;
            break;
        }
        return CraftPath;
    }

    string GetTypePath(string val)
    {
        switch (val)
        {
            case "repair":
                return player.m_CraftClasses.m_CustomizationSetting.PathToRepairImg;
            break;
            case "paint":
                return player.m_CraftClasses.m_CustomizationSetting.PathToPaintImg;
            break;
            case "craft":
                return player.m_CraftClasses.m_CustomizationSetting.PathToCraftImg;
            break;
        }
        return CraftPath;
    }

    void SetData(CraftItem itm)
    {
        m_CraftItem = itm;
    }

    void SetDataTEST(int val)
    {
        m_Test = val;
    }
}