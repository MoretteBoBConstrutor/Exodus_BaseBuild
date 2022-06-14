class CraftClasses
{
    ref CustomizationSetting m_CustomizationSetting = new CustomizationSetting();
    ref array<string> WorkbenchesClassnames = new array<string>();
    ref array<ref CraftItem> CraftItems = new array<ref CraftItem>();
}

class CraftItem
{
    string Result;
    int    ResultCount;
    string CraftType;
    string RecipeName;
    ref array<ref CraftComponent> CraftComponents = new array <ref CraftComponent>();
    ref array <string> AttachmentsNeed = new array<string>();
}

class CraftComponent
{
    string Classname;
    int    Amount;
    bool   Destroy;
    float  Changehealth;
}

class CustomizationSetting
{
    string PathToMainBackgroundImg;
    string PathToRepairImg;
    string PathToPaintImg;
    string PathToCraftImg;
}