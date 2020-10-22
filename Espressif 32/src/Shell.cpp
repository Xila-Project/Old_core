#include "Shell.hpp"

Shell_Class *Shell_Class::Instance_Pointer = NULL;

Software_Handle_Class *Shell_Class::Handle_Pointer = &Shell_Handle;

Shell_Class::Shell_Class() : Software_Class(6),
                             Mode(0),
                             Selected_Software(0)
{
    xTaskCreatePinnedToCore(Shell_Task, "Shell Task", 6 * 1024, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
    Execute(0x4F4C);
}

Shell_Class::~Shell_Class()
{
    Instance_Pointer = NULL;
}

Software_Class *Shell_Class::Load()
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Shell_Class();
    }
    else
    {
        Instance_Pointer->Execute('O', 'F');
    }
    return Instance_Pointer;
}

void Shell_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    Verbose_Print_Line("> Set variable shell");
    switch (Adress)
    {
    case 'S':
        Selected_Software = *(uint8_t *)Variable;
        break;
    case 'U':
        strcpy(Username, (char *)Variable);
        break;
    case 'P':
        if (Type == GalaxOS.Variable_String_Local)
        {
            Current_Path = *(String *)Variable;
        }
        else
        {
            strcpy(Password, (char *)Variable);
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

        case 0x534D: // SM : Shutdown menu
            GalaxOS.Display.Set_Current_Page(F("Shell_Shutdown"));
            break;

        case 0x5253: // RS : Restart system

            break;
        case 0x4853: // HS : hibernate sys
            break;

        case 0x4C53: // LS : lock system
            break;

        case 0x5353: // SS : shutdown

            break;
        case 0x4C6F: // LO : Login with entred username and password
            INSTANCE_POINTER->Login();
            break;

        case 0x4F4C: // "OL" : Open Login page
            INSTANCE_POINTER->Open_Login();
            break;
        case 0x4F44: // "OD" Open Desk page & load it
            INSTANCE_POINTER->Open_Desk();
            break;
        case 0x4F4D: // "OM" : Open Menu
            INSTANCE_POINTER->Open_Menu();
            break;
        case 0x4F46: // "OF" : Open file manager
            GalaxOS.Display.Set_Current_Page(F("Shell_File"));
            break;
        case 0x4F50: // "OP" : Open preferiencies (default : personnal)
            GalaxOS.Display.Set_Current_Page(F("Shell_Personal"));
            break;
        case 0x4F48: // "OH" : Open hardware prefencies
            GalaxOS.Display.Set_Current_Page(F("Shell_Hardware"));
            break;
        case 0x4F4E: // "ON" : Open network
            GalaxOS.Display.Set_Current_Page(F("Shell_Network"));
            break;
        case 0x4F53: // "OS" : Open software
            GalaxOS.Display.Set_Current_Page(F("Shell_System"));
            break;
        case 0x4D4F: // MO : Open software from menu
            INSTANCE_POINTER->Open_From_Menu();
            break;
        case 0x4431: // Dx : Maxmize software from task bar
            INSTANCE_POINTER->Open_From_Dock(1);
            break;
        case 0x4432:
            INSTANCE_POINTER->Open_From_Dock(2);
            break;
        case 0x4433:
            INSTANCE_POINTER->Open_From_Dock(3);
            break;
        case 0x4434:
            INSTANCE_POINTER->Open_From_Dock(4);
            break;
        case 0x4435:
            INSTANCE_POINTER->Open_From_Dock(5);
            break;
        case 0x4436:
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
    GalaxOS.Open_Software(GalaxOS.Software_Handle_Pointer[Selected_Software]);
}

void Shell_Class::Open_From_Dock(uint8_t Slot)
{
    GalaxOS.Maximize_Software(Slot + 1);
}

void Shell_Class::Open_Desk()
{
    Verbose_Print_Line("> Open desk");
    GalaxOS.Display.Set_Current_Page(F("Shell_Desk"));
    char Temporary_String[] = "SLOT _PIC";

    // List all files on the desk
    /*Temporary_File = GalaxOS.Drive->open("/USERS/" + String(GalaxOS.Current_Username) + "/DESKTOP/");
    Temporary_File.rewindDirectory();
    Temporary_File.openNextFile();*/

    // List all running app on the task bar
    for (uint8_t Slot = 1; Slot < 8; Slot++)
    {
        Temporary_String[4] = Slot;
        if (GalaxOS.Open_Software_Pointer[Slot + 1] != NULL)
        {
            GalaxOS.Display.Set_Picture(Temporary_String, GalaxOS.Open_Software_Pointer[Slot]->Handle_Pointer->Icon);
        }
        else
        {
            GalaxOS.Display.Set_Picture(Temporary_String, 39); //if there's
        }
    }
}

void Shell_Class::Open_Menu()
{
    GalaxOS.Display.Set_Current_Page(F("Shell_Menu"));
    GalaxOS.Display.Set_Text(F("USERNAME_TXT"), GalaxOS.Current_Username);
    char Temporary_String[] = "ITEM _TXT";
    uint8_t Item = 0;
    for (Item = 0; Item < 15; Item++)
    {
        Temporary_String[4] = Item;
        GalaxOS.Display.Set_Text(String(Temporary_String), GalaxOS.Software_Handle_Pointer[Item]->Name);
    }
    Temporary_String[6] = 'P';
    Temporary_String[7] = 'I';
    Temporary_String[8] = 'C';
    for (; Item < 15; Item++)
    {
        Temporary_String[4] = Item;
        GalaxOS.Display.Set_Picture(String(Temporary_String), GalaxOS.Software_Handle_Pointer[Item]->Icon);
    }
}

void Shell_Class::Open_Login()
{

    if (GalaxOS.Current_Username[0] == 255)
    {
        Verbose_Print_Line("> Open login page");
        GalaxOS.Display.Set_Current_Page(F("Shell_Login"));
        GalaxOS.Display.Set_Text(F("USERNAME_TXT"), F("Useranme"));
        GalaxOS.Display.Set_Text(F("PASSWORD_TXT"), F("Password"));
    }
    else
    {
        Open_Desk();
    }
}

void Shell_Class::Login()
{
    if (GalaxOS.Check_Credentials(Username, Password) == GalaxOS.Good_Credentials)
    {
        Verbose_Print_Line(F("> Load user files"));
        GalaxOS.Display.Hide(F("USERNAME_TXT"));
        GalaxOS.Display.Hide(F("PASSWORD_TXT"));
        GalaxOS.Display.Hide(F("LOGIN_BUT"));
        GalaxOS.Display.Show(F("YELLOW_TXT"));
        GalaxOS.Display.Show(F("GREEN_TXT"));
        GalaxOS.Display.Show(F("BLUE_TXT"));
        GalaxOS.Display.Show(F("RED_TXT"));
        GalaxOS.Display.Show(F("LOAD_BAR"));
        GalaxOS.Display.Show(F("LOAD_TXT"));
        GalaxOS.Display.Show(F("GALAXOS_TXT"));

        DynamicJsonDocument Shell_Registry(256);
        File Temporary_File = GalaxOS.Drive->open("/USERS/" + String(GalaxOS.Current_Username) + "/SHELL.GRF", FILE_WRITE);
        deserializeJson(Shell_Registry, Temporary_File);
        if (Shell_Registry["Registry"] == "Shell")
        {
            // Color = Shell_Registry["Color"] | 16904;
        }
        GalaxOS.Display.Set_Value(F("LOAD_BAR"), 20);
        vTaskDelay(pdMS_TO_TICKS(pdMS_TO_TICKS(100)));
        GalaxOS.Display.Set_Value(F("LOAD_BAR"), 40);
        vTaskDelay(pdMS_TO_TICKS(pdMS_TO_TICKS(100)));
        GalaxOS.Display.Set_Value(F("LOAD_BAR"), 60);
        vTaskDelay(pdMS_TO_TICKS(pdMS_TO_TICKS(100)));
        GalaxOS.Display.Set_Value(F("LOAD_BAR"), 80);
        vTaskDelay(pdMS_TO_TICKS(pdMS_TO_TICKS(100)));
        GalaxOS.Display.Set_Value(F("LOAD_BAR"), 100);
    }
    else // Wrong credentials
    {
        // Event handle :
    }
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
    case GalaxOS.Yes:
        GalaxOS.Drive->remove(Current_Path + Item_Name);
        break;
    case GalaxOS.No:
    case GalaxOS.Cancel:
    default:
        break;
    }
}

#undef INSTANCE_POINTER