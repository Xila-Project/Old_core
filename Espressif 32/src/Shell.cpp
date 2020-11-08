#include "Shell.hpp"

Shell_Class *Shell_Class::Instance_Pointer = NULL;

Shell_Class::Shell_Class() : Software_Class(6),
                             Mode(0)
{
    Handle_Pointer = &Shell_Handle;
    memset(Username, '\0', sizeof(Username));
    memset(Password, '\0', sizeof(Password));
    xTaskCreatePinnedToCore(Main_Task, "Shell Task", 6 * 1024, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
    Execute(Software_Code::Maximize);
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
    return Instance_Pointer;
}

void Shell_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    switch (Adress)
    {
    case 'U':
        strcpy(Username, (char *)Variable);
        break;
    case 'D':
        if (Type == GalaxOS.Variable_Long_Local)
        {
        }
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

void Shell_Class::Main_Task(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {

        switch (Instance_Pointer->Get_Command())
        {
        case 0: // IDLE
            //Nothing to do : idle
            vTaskDelay(pdMS_TO_TICKS(20));
            break;

        case Software_Code::Close: // close
            delete Instance_Pointer;
            vTaskDelete(NULL);
            break;
        case Software_Code::Minimize: // minimize
            vTaskSuspend(NULL);
            break;
        case Software_Code::Maximize:
            Instance_Pointer->Open_Desk();
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
            GalaxOS.Shutdown();
            break;
        case 0x4C6F: // Lo : Login with entred username and password
            Instance_Pointer->Login();
            break;
        case 0x44: // DC : display calibration
            GalaxOS.Display.Calibrate();
            // wait until display sent reset code
            break;
        case 0x4F4C: // "OL" : Open Login page
            Instance_Pointer->Open_Login();
            break;
        case 0x4F44: // "OD" Open Desk page & load it
            Instance_Pointer->Open_Desk();
            break;
        case 0x4F64: // "Od" Open drawer
            Instance_Pointer->Open_Drawer();
            break;
        case 0x4F46: // "OF" : Open file manager
            Instance_Pointer->Open_File_Manager();

            break;
        case 0x4F50: // "OP" : Open preferiencies (default : personnal)
            Instance_Pointer->Open_Preferences('P');
            break;
        case 0x4F48: // "OH" : Open hardware prefencies
            Instance_Pointer->Open_Preferences('H');
            break;
        case 0x4F4E: // "ON" : Open network
            Instance_Pointer->Open_Preferences('N');
            break;
        case 0x4F53: // "OS" : Open software
            Instance_Pointer->Open_Preferences('S');
            break;
        case 0x6430: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(0);
            break;
        case 0x6431: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(1);
            break;
        case 0x6432: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(2);
            break;
        case 0x6433: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(3);
            break;
        case 0x6434: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(4);
            break;
        case 0x6435: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(5);
            break;
        case 0x6436: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(6);
            break;
        case 0x6437: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(7);
            break;
        case 0x6438: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(8);
            break;
        case 0x6439: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(9);
            break;
        case 0x6441: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(10);
            break;
        case 0x6442: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(11);
            break;
        case 0x6443: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(12);
            break;
        case 0x6444: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(13);
            break;
        case 0x6445: // dx : Open software from drawer
            Instance_Pointer->Open_From_Drawer(14);
            break;
        case 0x4431: // Dx : Maxmize software from dock
            Instance_Pointer->Open_From_Dock(1);
            break;
        case 0x4432:
            Instance_Pointer->Open_From_Dock(2);
            break;
        case 0x4433:
            Instance_Pointer->Open_From_Dock(3);
            break;
        case 0x4434:
            Instance_Pointer->Open_From_Dock(4);
            break;
        case 0x4435:
            Instance_Pointer->Open_From_Dock(5);
            break;
        case 0x4436:
            Instance_Pointer->Open_From_Dock(6);
            break;
        default:
            break;
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void Shell_Class::Open_From_Drawer(uint8_t Slot)
{
    switch (Slot)
    {
    case 0: //File manager
        Open_File_Manager();
        break;
    case 1:
        Open_Preferences('P');
        break;
    default:
        GalaxOS.Open_Software(GalaxOS.Software_Handle_Pointer[Slot]); // exclude 1st slot (shell ui), so add, minus 2 = 1
        break;
    }
}

void Shell_Class::Open_From_Dock(uint8_t Slot)
{
    GalaxOS.Maximize_Software(Slot + 1);
}

void Shell_Class::Open_Preferences(char Section)
{
    switch (Section)
    {
    case 'P':
        GalaxOS.Display.Set_Current_Page(F("Shell_Personal"));
        break;
    case 'H':
        GalaxOS.Display.Set_Current_Page(F("Shell_Hardware"));
        break;
    case 'N':
        GalaxOS.Display.Set_Current_Page(F("Shell_Network"));
        break;
    case 'S':
        GalaxOS.Display.Set_Current_Page(F("Shell_System"));
        break;
    default:
        break;
    }
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
    if (GalaxOS.Current_Username[0] == '\0')
    {
        Open_Login();
        return;
    }
    // List all running app on the task bar
    for (uint8_t Slot = 2; Slot < 8; Slot++)
    {
        Temporary_String[4] = Slot + 47;
        if (GalaxOS.Open_Software_Pointer[Slot] != NULL)
        {
            GalaxOS.Display.Set_Picture(Temporary_String, GalaxOS.Open_Software_Pointer[Slot]->Handle_Pointer->Icon);
        }
        else
        {
            GalaxOS.Display.Set_Picture(Temporary_String, Empty_32); //if there's
        }
    }
}

void Shell_Class::Open_Drawer()
{
    GalaxOS.Display.Set_Current_Page(F("Shell_Drawer"));
    char Temporary_String[11];
    Temporary_String[0] = '\r'; //jump
    Temporary_String[1] = '\n';
    strcpy(Temporary_String + 2, GalaxOS.Current_Username);
    GalaxOS.Display.Set_Text(F("USERNAME_TXT"), Temporary_String);
    GalaxOS.Display.Show(F("SHUTDOWN_PIC"));
    strcpy(Temporary_String, "ITEM _TXT");
    uint8_t Item = 0;
    GalaxOS.Display.Set_Text(F("ITEM0_TXT"), F("File Manager"));
    GalaxOS.Display.Set_Picture(F("ITEM0_PIC"), File_Manager_32);
    GalaxOS.Display.Set_Text(F("ITEM1_TXT"), F("Preferences"));
    GalaxOS.Display.Set_Picture(F("ITEM1_PIC"), Preferences_32);
    for (Item = 2; Item < 10; Item++)
    {
        Temporary_String[4] = Item + 48;
        if (GalaxOS.Software_Handle_Pointer[Item] != NULL)
        {
            GalaxOS.Display.Set_Text(String(Temporary_String), String(GalaxOS.Software_Handle_Pointer[Item]->Name));
        }
        else
        {
            GalaxOS.Display.Set_Text(String(Temporary_String), "");
        }
    }
    strcpy(Temporary_String, "ITEM1 _TXT");
    for (Item = 0; Item < 4; Item++)
    {
        Temporary_String[5] = Item + 48;
        if (GalaxOS.Software_Handle_Pointer[Item + 10] != NULL)
        {
            GalaxOS.Display.Set_Text(String(Temporary_String), String(GalaxOS.Software_Handle_Pointer[Item + 10]->Name));
        }
        else
        {
            GalaxOS.Display.Set_Text(String(Temporary_String), "");
        }
    }
    strcpy(Temporary_String, "ITEM _PIC");
    for (Item = 2; Item < 10; Item++)
    {
        Temporary_String[4] = Item + 48;
        if (GalaxOS.Software_Handle_Pointer[Item] != NULL)
        {
            GalaxOS.Display.Set_Picture(String(Temporary_String), GalaxOS.Software_Handle_Pointer[Item]->Icon);
        }
        else
        {
            GalaxOS.Display.Set_Picture(String(Temporary_String), Empty_32);
        }
    }
    strcpy(Temporary_String, "ITEM1 _PIC");
    for (Item = 0; Item < 5; Item++)
    {
        Temporary_String[5] = Item + 48;
        if (GalaxOS.Software_Handle_Pointer[Item + 10] != NULL)
        {
            GalaxOS.Display.Set_Picture(String(Temporary_String), GalaxOS.Software_Handle_Pointer[Item + 10]->Icon);
        }
        else
        {
            GalaxOS.Display.Set_Picture(String(Temporary_String), Empty_32);
        }
    }
}

void Shell_Class::Open_File_Manager()
{
    GalaxOS.Display.Set_Current_Page(F("Shell_File"));
}

void Shell_Class::Open_Login()
{

    if (GalaxOS.Current_Username[0] == '\0')
    {
        Verbose_Print_Line("> Open login page");
        GalaxOS.Display.Set_Current_Page(F("Shell_Login"));
        GalaxOS.Display.Set_Text(F("USERNAME_TXT"), F("Username"));
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
        strcpy(GalaxOS.Current_Username, Username);
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
        File Temporary_File = GalaxOS.Drive->open("/USERS/" + String(GalaxOS.Current_Username) + "/REGISTRY/SHELL.GRF");
        deserializeJson(Shell_Registry, Temporary_File);
        /*
                char Temporary_Char_Array[20];
        strcpy(Temporary_Char_Array, Shell_Registry["Registry"]);
        if (strcmp(Temporary_Char_Array, "Shell"))
        {
            //Color = Shell_Registry["Color"] | 16904;
        }
        */
        if (strcmp(Shell_Registry["Registry"], "Shell") == 0)
        {
            Verbose_Print_Line("Simple comp work !!!!");
            //Color = Shell_Registry["Color"] | 16904;
        }

        GalaxOS.Display.Set_Value(F("LOAD_BAR"), 20);
        vTaskDelay(pdMS_TO_TICKS(1000));
        GalaxOS.Display.Set_Value(F("LOAD_BAR"), 40);
        vTaskDelay(pdMS_TO_TICKS(1000));
        GalaxOS.Display.Set_Value(F("LOAD_BAR"), 60);
        vTaskDelay(pdMS_TO_TICKS(1000));
        GalaxOS.Display.Set_Value(F("LOAD_BAR"), 80);
        vTaskDelay(pdMS_TO_TICKS(1000));
        GalaxOS.Display.Set_Value(F("LOAD_BAR"), 100);
        vTaskDelay(pdMS_TO_TICKS(1000));
        Open_Desk();
    }
    else // Wrong credentials
    {
        GalaxOS.Event_Handler(F("Wrong credentials !"), GalaxOS.Error);
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
