class OneItemForCraft
{
    private Widget                  item;
    private ItemPreviewWidget       m_CraftItemPreview;
    private TextWidget              m_Craftitemnedeed;
    private MultilineTextWidget     m_Tooltip;
    private Widget                  m_CraftPanel;
    private CargoBase               m_CargoBase;
    private CraftComponent          m_CraftComp;

    bool EnoughIngrs                = false;

    Widget Init( Widget parent, CraftComponent cc)
    {
        item                    = GetGame().GetWorkspace().CreateWidgets("Exodus_Workbench/scripts/4_World/layout/OneItemForCraft.layout", parent);
        m_CraftItemPreview      = ItemPreviewWidget.Cast(item.FindAnyWidget("CraftItemPreview"));
        m_Craftitemnedeed       = TextWidget.Cast(item.FindAnyWidget("Craftitemnedeed"));
        m_Tooltip               = MultilineTextWidget.Cast(item.FindAnyWidget("CraftItemName"));
        m_CraftPanel            = Widget.Cast(item.FindAnyWidget("CraftItemPanel"));
        m_CraftComp = cc;

        EntityAI ent = GetGame().CreateObject(m_CraftComp.Classname, vector.Zero, true);
        if (ent)
        {
            m_Tooltip.SetText(ent.GetDisplayName());
            int count = g_CraftManager.m_ExItems.Get(m_CraftComp.Classname);
            m_CraftItemPreview.SetItem(ent);
            string amount = string.Format("%1/%2", count, cc.Amount);
            if (count >= cc.Amount)
            {
                EnoughIngrs = true;
                SetColor();
            }
            SetAmount(amount);
        }
        return item;
    }

    void SetColor()
    {
        m_Craftitemnedeed.SetColor(-16744416);
    }

    void SetAmount(string val)
    {
        m_Craftitemnedeed.SetText(val);
    }

    CraftComponent GetCC()
    {
        return m_CraftComp;
    }

    void OnEnter()
    {
        m_CraftPanel.Show(true);
    }

    void OnLeave()
    {
        m_CraftPanel.Show(false);
    }
}
