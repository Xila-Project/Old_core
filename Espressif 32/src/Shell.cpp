#include "Shell.hpp"

Shell_Class *Shell_Class::Instance_Pointer = NULL;

Software_Handle_Class *Shell_Class::Handle_Pointer = &Shell_Handle;

Shell_Class::Shell_Class() : Software_Class(6),
                             Mode(0)
{
    Instance_Pointer = this;
    xTaskCreatePinnedToCore(Shell_Task, "Shell Task", 2 * 1024, NULL, 1, &Task_Handle, 0);
    Execute('L', 'G');
}

Shell_Class::~Shell_Class()
{
    Instance_Pointer = NULL;
}

Software_Class *Shell_Class::Load()
{
    if (Shell_Class::Instance_Pointer == NULL)
    {
        Shell_Class::Instance_Pointer = new Shell_Class;
    }
    return Shell_Class::Instance_Pointer;
}

void Shell_Class::Set_Variable(const void* Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    switch (Adress)
    {
        case 'S':
            strcpy(Software_Name, (char*)Variable);
            break;
        case 'U':
            strcpy(Username, (char*)Variable);
            break;
        case 'P':
            if (Type == GalaxOS.Code::Variable_String_Local)
            {
                Current_Path = *(String*)Variable;
            }
            else
            {
                strcpy(Password, (char*)Variable);
            }
            break;
    }
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
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void Shell_Class::Open_From_Menu()
{
    GalaxOS.Open_Software(Software_Name);
}

void Shell_Class::Open_From_Dock(uint8_t Slot)
{
    GalaxOS.Maximize_Software(Slot + 1);
}

void Shell_Class::Open_Desk()
{
    GalaxOS.Display.Set_Current_Page(F("Shell_Desk"));
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
            if (GalaxOS.Open_Software_Pointer[Item] != NULL)
            {
                GalaxOS.Display.Set_Picture(Temporary_String, GalaxOS.Open_Software_Pointer[Item]->Handle_Pointer->Icon);
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
    GalaxOS.Display.Set_Current_Page(F("Shell_Menu"));
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
        GalaxOS.Display.Set_Current_Page(F("Shell_Login"));
    }
    else
    {
        Open_Desk();
    }
}

void Shell_Class::Login()
{
    GalaxOS.Login(Username, Password);
}

void Shell_Class::Display_Path()
{
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
            GalaxOS.Open_File(Temporary_File);
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
    byte i = Current_Path.length();
    while (Current_Path.charAt(i) != 0x2F || i >= 0)
    {
        Current_Path.remove(i);
        i--;
    }
    Display_Path();
}

void Shell_Class::Make_File(char *File_Name)
{
    if (!GalaxOS.Drive->open(Current_Path + "/" + File_Name, FILE_WRITE))
    {
        //error
    }
}

void Shell_Class::Make_Directory(char *Item_Name)
{
    if (!GalaxOS.Drive->exists(Current_Path + Item_Name))
    {
        GalaxOS.Drive->mkdir(Current_Path + Item_Name);
    }
}

void Shell_Class::Delete(char *Item_Name)
{
    switch (GalaxOS.Event_Handler(F("Do you "), GalaxOS.Question))
    {
    case GalaxOS.Answer::Yes:
        GalaxOS.Drive->remove(Current_Path + Item_Name);
        break;
    case GalaxOS.Answer::No:
    case GalaxOS.Answer::Cancel:
    default:
        break;
    }
}

#undef INSTANCE_POINTER