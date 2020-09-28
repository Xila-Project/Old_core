#include "Shell.hpp"

Shell_Class *Instance_Pointer = NULL;

Shell_Class::Shell_Class(Software_Handle_Class *Software_Handle_Pointer) : Software_Class(Software_Handle_Pointer, 6), Instance_Pointer(this)
{
}

Shell_Class::~Shell_Class()
{
}

Software_Class *Shell_Class::Load(Software_Handle_Class *Software_Handle_Pointer)
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Shell_Class(Software_Handle_Pointer);
    }
    return Instance_Pointer;
}

void Shell_Task(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (INSTANCE_POINTER->Get_Command())
        {
        case 0: //default
            //Nothing to do : idle
            break;
        case 0x4C47: //LG
            INSTANCE_POINTER->Login();
            break;
        case 0x4F4C: //OL
            INSTANCE_POINTER->Open_Login();
            break;
        case 0x4F44: //OD
            INSTANCE_POINTER->Open_Desk();
            break;
        case 0x4F4D: //OM
            INSTANCE_POINTER->Open_Menu();
            break;
        case 0x4F49: //OI
            INSTANCE_POINTER->Open_Item();
            break;
        default:
            break;
        }
        vTaskSuspend(NULL);
    }
}

void Shell_Class::Open_Desk()
{
    GalaxOS.Display.Set_Current_Page(Page_Desk);
    char Temporary_String[] = "SLOT _PIC";
    Temporary_File = GalaxOS.Drive->open("/USERS/" + String(GalaxOS.Current_Username) + "/DESKTOP/");
    Temporary_File.rewindDirectory();
    Temporary_File.openNextFile();
    // List all files on the desk
    for (uint8_t Slot = 0; Slot < 6; Slot++) // list all running app on the task bar
    {
        Temporary_String[4] = Slot;
        for (uint8_t Item = 0; Item < 6; Item++)
        {
            if (GalaxOS.Software_Pointer[Item] != NULL)
            {
                GalaxOS.Display.Set_Picture(Temporary_String, GalaxOS.Software_Pointer[Item]->Handle_Pointer->Icon);
            }
            else
            {
                GalaxOS.Display.Set_Picture(Temporary_String, 39); //if there's
            }
        }
    }
}

void Shell_Class::Open_Menu()
{
    GalaxOS.Display.Set_Current_Page(Page_Menu);
    GalaxOS.Display.Set_Text(F("USERNAME_TXT"), GalaxOS.Get_Current_Username());
    char Temporary_String[] = "SLOT _PIC";
    for (uint8_t Slot = 0; Slot < MAXIMUM_SOFTWARE; Slot++)
    {
        Temporary_String[4] = Slot;
        GalaxOS.Display.Set_Picture(String(Temporary_String), GalaxOS.Software_Handle_Pointer[Slot]->Icon);
        GalaxOS.Display.Set_Text(Temporary_String, GalaxOS.Software_Handle_Pointer[Slot]->Name);
    }
}

void Shell_Class::Open_Item()
{
    char Software_Name[24];
    GalaxOS.Get_Variable('S', &Software_Name);
    GalaxOS.Open_Software(Software_Name);
}

void Shell_Class::Open_Login()
{
    String Username, Password;
    GalaxOS.Get_Variable('U', Username, 0, Handle_Pointer);
    GalaxOS.Get_Variable('P', Password, 0, Handle_Pointer);
    GalaxOS.Login(Username, Password);
}

void Shell_Class::Login()
{
    GalaxOS.Load_User_Files();
}

void Shell_Class::Display_Path()
{
    GalaxOS.Get_Variable('P', &Current_Path);
    Temporary_File = GalaxOS.Drive->open(Current_Path);
    String Temporary_String;
    if (Temporary_File)
    {
        if (Temporary_File.isDirectory())
        {
            Temporary_File.rewindDirectory();
            GalaxOS.Display.Set_Text("PATH_TXT", Current_Path);
            File Item;
            for (byte i = 1; i < 33; i++)
            {
                Item = Temporary_File.openNextFile();
                if (Item)
                {
                    GalaxOS.Display.Set_Text("ITEM" + String(i) + "_TXT", Item.name());
                    if (Item.isDirectory())
                    {
                        GalaxOS.Display.Set_Picture("ITEM" + String(i) + "_PIC", 17);
                    }
                    else
                    {
                        GalaxOS.Display.Set_Picture("ITEM" + String(i) + "_PIC", 16);
                    }
                }
                else
                {
                    GalaxOS.Display.Set_Text("ITEM" + String(i) + "_TXT", "");
                    GalaxOS.Display.Set_Picture("ITEM" + String(i) + "_PIC", 15);
                }

                Item.close();
            }
        }
        else
        {
            GalaxOS.Open_File(GalaxOS.Drive->open(Current_Path));
            Temporary_File.close();
            Go_Parent();
        }
    }
    else
    {
        //error handle
    }
}

void Shell_Class::Go_Parent()
{
    byte i = strlen(Current_Path);
    while (Current_Path[i] != 0x2F || i >= 0)
    {
        Current_Path[i] == NULL;
        i--;
    }
    Display_Path();
}

void Shell_Class::Make_File(char *File_Name)
{
    if (!GalaxOS.Drive->exists(Current_Path + "/NEWFILE" + char(i) + ".TXT"))
    {
        GalaxOS.Drive->open(Current_Path + "/NEWFILE" + char(i) + ".TXT", FILE_WRITE);
        break;
    }
}
}

void Shell_Class::Make_Directory(char *Item_Name)
{
    if (!GalaxOS.Drive->exists(Current_Path + Directory_Name))
    {
        GalaxOS.Drive->mkdir(Current_Path + Directory_Name);
    }
}

void Shell_Class::Delete(char *Item_Name)
{
    switch(GalaxOS.Event_Handler(Delete_File)
    {
    case GalaxOS.Yes:
        GalaxOS.Drive->remove(Current_Path + Item_Name);
    case GalaxOS.No:
    case GalaxOS.Cancel:
    default:
        break;
        
    }
}