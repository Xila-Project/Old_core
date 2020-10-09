#include "Shell.hpp"

Shell_Class *Instance_Pointer = NULL;

Shell_Class::Shell_Class(Software_Handle_Class *Software_Handle_Pointer) : Software_Class(Software_Handle_Pointer, 6),
                                                                           Mode(0),
{
    Instance_Pointer = this;
    xTaskCreatePinnedToCore(Shell_Task, "Shell Task", 2 * 1024, NULL, 1, &Task_Handle, 0);
    Execute('L', 'G');
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
        case 0: // IDLE
            //Nothing to do : idle
            vTaskDelay(pdMS_TO_TICKS(20));
            break;

        case 0x0043: // close
            delete INSTANCE_POINTER;
            vTaskDelete(NULL);
            break;
        case 0x004D: // minimize
            vTaskSuspend(NULL);
            break;

        case 0x4C47: // LoGin with entred username and password
            INSTANCE_POINTER->Login();
            break;

        case 0x4F4C: // Open Login page
            INSTANCE_POINTER->Open_Login();
            break;
        case 0x4F44: // Open Desk page & load it
            INSTANCE_POINTER->Open_Desk();
            break;
        case 0x4F4D: // Open Menu
            INSTANCE_POINTER->Open_Menu();
            break;

        case 0x4D4F: // MO : Open software from menu
            INSTANCE_POINTER->Open_From_Menu();
            break;

        case 0x5431: // T1 : Maxmize software from task bar
            INSTANCE_POINTER->Open_From_Dock(1);
            break;
        case 0x5432:
            INSTANCE_POINTER->Open_From_Dock(2);
            break;
        case 0x5433:
            INSTANCE_POINTER->Open_From_Dock(3);
            break;
        case 0x5434:
            INSTANCE_POINTER->Open_From_Dock(4);
            break;
        case 0x5435:
            INSTANCE_POINTER->Open_From_Dock(5);
            break;
        case 0x5436:
            INSTANCE_POINTER->Open_From_Dock(6);
            break;
        default:
            break;
        }
        vTaskSuspend(pdMS_TO_TICKS(10));
    }
}

void Shell_Class::Open_From_Menu()
{
    char Software_Name[24];
    GalaxOS.Get_Variable('S', Software_Name, 24, INSTANCE_POINTER->Handle_Pointer);
    GalaxOS.Open_Software(Software_Name);
}

void Shell_Class::Open_From_Dock(uint8_t Slot)
{
    GalaxOS.Maximize(Slot + 1);
}

void Shell_Class::Open_Desk()
{
    GalaxOS.Display.Set_Current_Page(Page_Desk);
    char Temporary_String[] = "SLOT _PIC";

    // List all files on the desk
    /*Temporary_File = GalaxOS.Drive->open("/USERS/" + String(GalaxOS.Current_Username) + "/DESKTOP/");
    Temporary_File.rewindDirectory();
    Temporary_File.openNextFile();*/

    // List all running app on the task bar
    for (uint8_t Slot = 0; Slot < 6; Slot++)
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
    GalaxOS.Display.Set_Text(F("USERNAME_TXT"), GalaxOS.Current_Username);
    char Temporary_String[] = "SLOT _PIC";
    for (uint8_t Slot = 0; Slot < MAXIMUM_SOFTWARE; Slot++)
    {
        Temporary_String[4] = Slot;
        GalaxOS.Display.Set_Picture(String(Temporary_String), GalaxOS.Software_Handle_Pointer[Slot]->Icon);
        GalaxOS.Display.Set_Text(String(Temporary_String), GalaxOS.Software_Handle_Pointer[Slot]->Name);
    }
}

void Shell_Class::Open_Login()
{

    if (GalaxOS.Current_Username[0] == 255)
    {
        GalaxOS.Display.Set_Current_Page(Page_Loggin);
    }
    else
    {
        Open_Desk();
    }
}

void Shell_Class::Login()
{
    String Username, Password;
    GalaxOS.Get_Variable('U', Username, 0, Handle_Pointer);
    GalaxOS.Get_Variable('P', Password, 0, Handle_Pointer);
    GalaxOS.Login(Username, Password);
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