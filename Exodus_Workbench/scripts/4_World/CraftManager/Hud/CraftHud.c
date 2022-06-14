class CraftHud extends UIScriptedMenu
{
    private Widget              m_PanelWidgetMain;
    private Widget              m_PanelWidgetItem;
    private ButtonWidget        m_BtnAllRecipes;
    private ButtonWidget        m_BtnPosbRecipes;
    private ScrollWidget        m_ScrollWidgetRecipes;
    private ScrollWidget        m_ScrollWidgetPosRecipes;
    private WrapSpacerWidget    m_WrapSpacerWidgetRecipes;
    private TextWidget          m_TextItemName;
    private ItemPreviewWidget   m_ItemPreviewWidget;
    private ButtonWidget        m_BtnCraft;
    private ScrollWidget        m_ScrollCraftItems;
    private WrapSpacerWidget    m_WrapSpacerWidget;
    private TextWidget          m_ItemResultCount;
    private ProgressBarWidget   m_ProgressCraftBar;
    private MultilineTextWidget m_NedeedAttachms;
    private WrapSpacerWidget    m_WrapSpacerWidgetPosRecipes;
    private Widget              m_PanelWrapperAllRecipes;
    private Widget              m_PanelWrapperPosRecipes;

    private ImageWidget         m_MainImg;
    private ImageWidget         m_ImgCraft;

    ref array<Widget> AllWidgetRecipes;
    ref array<Widget> PosWidgetRecipes;
    ref array<ref OneRecipe> AllRecipes;
    ref array<ref OneRecipe> AllPosRecipes;
    ref array<ref OneItemForCraft> TempIngrsArray;

    ref CraftItem crItm;

    private int m_characterRotationX;
	private int m_characterRotationY;
	private int m_characterScaleDelta;
	private vector m_characterOrientation;
    private EntityAI m_MainEnt;

    private float progressCounter;

    PlayerBase targetPlayer;

    private const string RedBtn = "Exodus_Workbench/data/gui/images/CRIAR.edds";
    private const string GrnBtn = "Exodus_Workbench/data/gui/images/CRIAR_checked.edds";

    void CraftHud()
    {
        targetPlayer = PlayerBase.Cast(GetGame().GetPlayer());
        if(targetPlayer)
        targetPlayer.CanCraft = true;

        ScanItems();
        progressCounter = 0;
        crItm = new CraftItem();
        AllWidgetRecipes = new array<Widget>();
        PosWidgetRecipes = new array<Widget>();
        AllRecipes  = new array<ref OneRecipe>();
        AllPosRecipes  = new array<ref OneRecipe>();
        TempIngrsArray = new array<ref OneItemForCraft>();
        GetGame().GetMission().PlayerControlDisable( INPUT_EXCLUDE_ALL );
    }

    void ~CraftHud()
    {
        g_CraftManager.m_ExItems.Clear();
        TempIngrsArray.Clear();
        AllWidgetRecipes.Clear();
        PosWidgetRecipes.Clear();
        AllRecipes.Clear();
        AllPosRecipes.Clear();
        if (m_MainEnt) GetGame().ObjectDeleteOnClient(m_MainEnt);
        g_CraftManager.DeleteEntities();
        GetGame().GetMission().PlayerControlEnable( true );
    }

    override Widget Init()
	{
		layoutRoot 				    = 	GetGame().GetWorkspace().CreateWidgets("Exodus_Workbench/scripts/4_World/layout/Workbench.layout");
        m_PanelWidgetMain           =   Widget.Cast(GetWid("PanelWidgetMain"));
        m_PanelWidgetItem           =   Widget.Cast(GetWid("PanelWidgetItem"));
        m_BtnAllRecipes             =   ButtonWidget.Cast(GetWid("BtnAllRecipes"));
        m_BtnPosbRecipes            =   ButtonWidget.Cast(GetWid("BtnPosbRecipes"));
        m_BtnCraft                  =   ButtonWidget.Cast(GetWid("BtnCraft"));
        m_ScrollWidgetRecipes       =   ScrollWidget.Cast(GetWid("ScrollWidgetRecipes"));
        m_ScrollCraftItems          =   ScrollWidget.Cast(GetWid("ScrollCraftItems"));
        m_ScrollWidgetPosRecipes    =   ScrollWidget.Cast(GetWid("ScrollWidgetPosRecipes"));
        m_WrapSpacerWidgetRecipes   =   WrapSpacerWidget.Cast(GetWid("WrapSpacerWidgetRecipes"));
        m_WrapSpacerWidget          =   WrapSpacerWidget.Cast(GetWid("WrapSpacerWidget"));
        m_TextItemName              =   TextWidget.Cast(GetWid("TextItemName"));
        m_ItemPreviewWidget         =   ItemPreviewWidget.Cast(GetWid("ItemPreviewWidget"));
        m_ItemResultCount           =   TextWidget.Cast(GetWid("ItemResultCount"));
        m_ProgressCraftBar          =   ProgressBarWidget.Cast(GetWid("ProgressCraftBar"));
        m_NedeedAttachms            =   MultilineTextWidget.Cast(GetWid("NedeedAttachms"));
        m_WrapSpacerWidgetPosRecipes=   WrapSpacerWidget.Cast(GetWid("WrapSpacerWidgetPosRecipes"));
        m_PanelWrapperAllRecipes    =   Widget.Cast(GetWid("PanelWrapperAllRecipes"));
        m_PanelWrapperPosRecipes    =   Widget.Cast(GetWid("PanelWrapperPosRecipes"));

        m_MainImg                   =   ImageWidget.Cast(GetWid("ImageWidgetRoot"));
        m_ImgCraft                  =   ImageWidget.Cast(GetWid("ImgBtn"));

        m_ImgCraft.LoadImageFile(0, RedBtn);
        m_ImgCraft.LoadImageFile(1, GrnBtn);
        m_ImgCraft.SetImage(0);


        if(!m_MainImg.LoadImageFile(0, targetPlayer.m_CraftClasses.m_CustomizationSetting.PathToMainBackgroundImg))
        {
            m_MainImg.LoadImageFile(0, "Exodus_Workbench/data/gui/images/Workbench.edds");
        }
        FillRecipes();
        FillPosibleRecipes();
		return layoutRoot;
	}

	Widget GetWid(string val)
	{
		return layoutRoot.FindAnyWidget(val);
	}

    void FillRecipes()
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player)
        {
            for (int i = 0; i < player.m_CraftClasses.CraftItems.Count(); i++)
            {
                CraftItem ci = player.m_CraftClasses.CraftItems.Get(i);
                OneRecipe recipe = new OneRecipe();
                Widget w = recipe.Init(m_WrapSpacerWidgetRecipes, ci.RecipeName, ci.CraftType);
                recipe.SetData(ci);
                AllWidgetRecipes.Insert(w);
                AllRecipes.Insert(recipe);
            }
        }
    }

    void FillPosibleRecipes()
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player)
        {
            for (int i = 0; i < player.m_CraftClasses.CraftItems.Count(); i++)
            {
                CraftItem ci = player.m_CraftClasses.CraftItems.Get(i);
                if (WBHasAllAttachments(ci))
                {
                    OneRecipe recipe = new OneRecipe();
                    Widget w = recipe.Init(m_WrapSpacerWidgetPosRecipes, ci.RecipeName, ci.CraftType);
                    recipe.SetData(ci);
                    PosWidgetRecipes.Insert(w);
                    AllPosRecipes.Insert(recipe);
                }
            }
        }
    }

    bool WBHasAllAttachments(CraftItem ci)
    {
        int attCounter = 0;
        int finalAttCount = ci.AttachmentsNeed.Count();
        int attCount = g_CraftManager.GetWB().GetInventory().AttachmentCount();
        string name;
        for (int j = 0; j < finalAttCount; j++)
        {
            name = ci.AttachmentsNeed.Get(j);
            for (int i = 0; i < attCount; i++)
            {
                ItemBase item = ItemBase.Cast( g_CraftManager.GetWB().GetInventory().GetAttachmentFromIndex( i ) );
                if (item && (item.GetType() == name))
                {
                    attCounter++;
                }
            }
        }
        return (attCounter == finalAttCount);
    }

    override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);
		if (ButtonWidget.Cast(w))
		{
            if (w.GetParent().GetParent().GetName() == "WrapSpacerWidgetPosRecipes")
            {
                ShowMoreInfo(w, 1);
                return true;
            }
            if (w.GetParent().GetName() == "RecipeItem")
            {
                ShowMoreInfo(w, 0);
                return true;
            }

            switch (w)
            {
                case m_BtnAllRecipes:
                    SwitchPanel("AllRecipes");
                break;
                case m_BtnPosbRecipes:
                    SwitchPanel("PosbRecipes");
                break;
                case m_BtnCraft:
                    TryCraftItem();
                break;
            }

		}		
		return false;
	}

    void SwitchPanel(string pan)
    {
        m_PanelWrapperAllRecipes.Show(false);
        m_PanelWrapperPosRecipes.Show(false);
        m_ScrollCraftItems.VScrollToPos01( 0 );
		m_ScrollWidgetRecipes.VScrollToPos01( 0 );
		m_ScrollWidgetPosRecipes.VScrollToPos01( 0 );

        switch (pan)
        {
            case "AllRecipes":
                m_PanelWrapperAllRecipes.Show(true);
            break;
            case "PosbRecipes":
                m_PanelWrapperPosRecipes.Show(true);
            break;
        }
    }

    void ShowMoreInfo(Widget w, int type)
    {
        int idx;
        OneRecipe recipe;
        Widget pw = w.GetParent();
        g_CraftManager.DeleteEntities();
        ClearCraftItemsBuffer();
        if (type)
        {
            idx = PosWidgetRecipes.Find(pw);
            if (idx != -1)
            {
                recipe = AllPosRecipes.Get(idx);
                SetupItems(recipe.m_CraftItem);
            }
        }
        else
        {
            idx = AllWidgetRecipes.Find(pw);
            if (idx != -1)
            {
                recipe = AllRecipes.Get(idx);
                SetupItems(recipe.m_CraftItem);
            }
        }
    }

    void ClearCraftItemsBuffer()
    {
        while (m_WrapSpacerWidget.GetChildren())
        {
            m_WrapSpacerWidget.RemoveChild(m_WrapSpacerWidget.GetChildren());
        }
    }

    void ScanItems()
    {
        if (!g_CraftManager.GetWB())
        {
            g_CraftManager.SelfChatMessage("Error workbench not found.");
            return;
        }

        if (!g_CraftManager.GetWB().HasAnyCargo())
        {
            return;
        }

        CargoBase cargoBase;
        int cargoCount;
        int quant;
        
        cargoBase = g_CraftManager.GetWB().GetInventory().GetCargo();
        cargoCount = cargoBase.GetItemCount();
        for (int c = 0; c < cargoCount; c++)
        {
            ItemBase cargoItemIB;
			if ( Class.CastTo(cargoItemIB, cargoBase.GetItem(c)) && cargoItemIB.IsItemBase() )
            {
                if (cargoItemIB.IsRuined()) continue;
                if (cargoItemIB.HasQuantity())
                {
                    quant = cargoItemIB.GetQuantity();
                }
                else
                {
                    quant = 1;
                }

                if (!g_CraftManager.m_ExItems.Contains(cargoItemIB.GetType()))
                {
                    g_CraftManager.m_ExItems.Insert(cargoItemIB.GetType(), quant);
                }
                else
                {
                    int nowQuant = g_CraftManager.m_ExItems.Get(cargoItemIB.GetType());
                    g_CraftManager.m_ExItems.Set(cargoItemIB.GetType(), (nowQuant + quant));
                }
            }
        }
    }

    bool OnMouseEnter(Widget w, int x, int y)
	{
		super.OnMouseEnter(w, x, y);
		
        if (w.GetUserID() == 25)
        {
            w.FindAnyWidget("CraftItemPanel").Show(true);
            w.FindAnyWidget("CraftItemPreview").Show(false);
        }
		return false;
	}
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		super.OnMouseLeave(w, enterW, x, y);
		
        if (w.GetUserID() == 25)
        {
            w.FindAnyWidget("CraftItemPanel").Show(false);
            w.FindAnyWidget("CraftItemPreview").Show(true);
        }

		return false;
	}

    void TryCraftItem()
    {
        PlayerBase pl = PlayerBase.Cast(GetGame().GetPlayer());
        if (pl)
        {
            if (pl.CanCraft())
            {
                pl.CanCraft = false;
                m_ProgressCraftBar.SetCurrent(0);
                m_ProgressCraftBar.Show(true);
                EffectSound sound =	SEffectManager.PlaySoundOnObject( "Craft_SoundSet", GetGame().GetPlayer() );
		        sound.SetSoundAutodestroy( true );
                StartProggres();
                m_BtnCraft.Enable(false);
                m_ImgCraft.SetImage(0);
            }
            else
            {
                g_CraftManager.SelfChatMessage("Devagar!");
            }
        }
    }

    void StartProggres()
    {
        GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( StartProggres, 10, false);
        progressCounter += 0.5;
        m_ProgressCraftBar.SetCurrent(progressCounter);
        if (m_ProgressCraftBar.GetCurrent() == 100)
        {
            PlayerBase pl = PlayerBase.Cast(GetGame().GetPlayer());
            if (pl)
            {
                pl.RPCSingleParam(CRPc.CLIENT_REQUEST_CRAFT_ITEMS, new Param2<CraftItem, ItemBase>(crItm, g_CraftManager.GetWB()), true, null);
            }
            GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Remove(StartProggres);
            progressCounter = 0;
            m_ProgressCraftBar.Show(false);
            GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( ReloadBench, 1000, false);
        }
    }

    void ReloadBench()
    {
        PlayerBase pl = PlayerBase.Cast(GetGame().GetPlayer());
        g_CraftManager.m_ExItems.Clear();
        ScanItems();
        g_CraftManager.DeleteEntities();
        ClearCraftItemsBuffer();
        SetupItems(crItm);
        pl.CanCraft = true;
    }

    //--------------------------------------------------------------------------
    void SetupItems(CraftItem crItem)
    {
        string attchts = "";
        m_NedeedAttachms.SetText(attchts);
        m_BtnCraft.Enable(false);
        m_ImgCraft.SetImage(0);
        TempIngrsArray.Clear();
        if (m_MainEnt) GetGame().ObjectDeleteOnClient(m_MainEnt);
        m_MainEnt = EntityAI.Cast(GetGame().CreateObject(crItem.Result, vector.Zero, true));
        if (m_MainEnt)
        {
            crItm = crItem;
            m_ItemPreviewWidget.SetItem(m_MainEnt);
			m_ItemPreviewWidget.SetView(m_MainEnt.GetViewIndex());
			m_ItemPreviewWidget.SetModelPosition(Vector(0,0,1));
            m_TextItemName.SetText(m_MainEnt.GetDisplayName());
            m_ItemResultCount.SetText(crItem.ResultCount.ToString());
            for (int i = 0; i < crItem.CraftComponents.Count(); i++)
            {
                FillIngrsWidget(crItem.CraftComponents.Get(i));
            }
            for (int j = 0; j < crItem.AttachmentsNeed.Count(); j++)
            {
                attchts = attchts + crItem.AttachmentsNeed.Get(j);
                if ((crItem.AttachmentsNeed.Count() - j) != 1 )
                attchts = attchts + ",";
            }
            m_NedeedAttachms.SetText(attchts);
        }
        if (CheckCondition() && WBHasAllAttachments(crItem))
        {
            m_BtnCraft.Enable(true);
            m_ImgCraft.SetImage(1);
        }
    }

    void FillIngrsWidget(CraftComponent cc)
    {
        OneItemForCraft itCraft = new OneItemForCraft();
        Widget w = itCraft.Init(m_WrapSpacerWidget, cc);
        TempIngrsArray.Insert(itCraft);
    }

    bool CheckCondition()
    {
        for (int i = 0; i < TempIngrsArray.Count(); i++)
        {
            OneItemForCraft tmp = TempIngrsArray.Get(i);
            if (!(tmp && tmp.EnoughIngrs))
            {
                return false;
            }
        }
        return true;
    }

    //--------------------------------------------------------------------------
	override bool OnMouseButtonDown(Widget w, int x, int y, int button)
	{
		super.OnMouseButtonDown(w, x, y, button);
		
		if (w == m_ItemPreviewWidget)
		{
			GetGame().GetDragQueue().Call(this, "UpdateRotation");
			g_Game.GetMousePos(m_characterRotationX, m_characterRotationY);
			return true;
		}
		return false;
	}
	
	//--------------------------------------------------------------------------
	void UpdateRotation(int mouse_x, int mouse_y, bool is_dragging)
	{
		vector o = m_characterOrientation;
		o[0] = o[0] + (m_characterRotationY - mouse_y);
		o[1] = o[1] - (m_characterRotationX - mouse_x);
		
		m_ItemPreviewWidget.SetModelOrientation( o );
		
		if (!is_dragging)
		{
			m_characterOrientation = o;
		}
	}
	
	//--------------------------------------------------------------------------
	override bool OnMouseWheel(Widget  w, int  x, int  y, int wheel)
	{
		super.OnMouseWheel(w, x, y, wheel);
		
		if ( w == m_ItemPreviewWidget )
		{
			m_characterScaleDelta = wheel;
			UpdateScale();
		}
		return false;
	}
	
	//--------------------------------------------------------------------------
	void UpdateScale()
	{
		float w, h, x, y;		
		m_ItemPreviewWidget.GetPos(x, y);
		m_ItemPreviewWidget.GetSize(w,h);
		w = w + ( m_characterScaleDelta / 4);
		h = h + ( m_characterScaleDelta / 4 );
		if ( w > 0.5 && w < 3 )
		{
			m_ItemPreviewWidget.SetSize( w, h );
	
			int screen_w, screen_h;
			GetScreenSize(screen_w, screen_h);
			float new_x = x - ( m_characterScaleDelta / 8 );
			float new_y = y - ( m_characterScaleDelta / 8 );
			m_ItemPreviewWidget.SetPos( new_x, new_y );
		}
	}
}