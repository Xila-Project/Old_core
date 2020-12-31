#include "Shell.hpp"

Shell_Class *Shell_Class::Instance_Pointer = NULL;

Shell_Class::Shell_Class() : Software_Class(6),
                             Mode(0)
{
    Handle_Pointer = &Shell_Handle;
    xTaskCreatePinnedToCore(Main_Task, "Shell Task", 6 * 1024, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
    Execute(Xila.Open);
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

void Shell_Class::Startup()
{
    Xila.Open_Software(Shell_Handle);
    Verbose_Print_Line(F("> Open_Shell"));
}

void Shell_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    switch (Xila.Display.Get_Current_Page())
    {
    case Install:
        switch (Adress)
        {
        case 'O':
            Temporary_Variable[0] = (uint32_t)Variable;
            break;
        case 'o':
            Temporary_Variable[1] = (uint32_t)Variable;
            break;
        case 'A': // Autologin
            Temporary_Variable[2] = (uint8_t)Variable;
            break;
        case 'D':
            if (Temporary_Char_Array[0] != NULL)
            {
                delete[] Temporary_Char_Array[0];
            }
            Temporary_Char_Array[0] = new char[25];
            strcpy(Temporary_Char_Array[0], (char *)Variable);
            break;
        case 'U':
            if (Temporary_Char_Array[1] != NULL)
            {
                delete[] Temporary_Char_Array[1];
            }
            Temporary_Char_Array[1] = new char[9];
            strcpy(Temporary_Char_Array[1], (char *)Variable);
            break;
        case 'P':
            if (Temporary_Char_Array[2] != NULL)
            {
                delete[] Temporary_Char_Array[2];
            }
            Temporary_Char_Array[2] = new char[25];
            strcpy(Temporary_Char_Array[2], (char *)Variable);
            break;
        case 's':
            if (Temporary_Char_Array[0] != NULL)
            {
                delete[] Temporary_Char_Array[0];
            }
            Temporary_Char_Array[0] = new char[33];
            strcpy(Temporary_Char_Array[0], (char *)Variable);
            break;
        case 'p':
            if (Temporary_Char_Array[1] != NULL)
            {
                delete[] Temporary_Char_Array[1];
            }
            Temporary_Char_Array[1] = new char[81];
            strcpy(Temporary_Char_Array[1], (char *)Variable);
            break;
        default:
            break;
        }
        break;
    case Preferences_Personal:
        switch (Adress)
        {
        case 'C':
            Temporary_Variable[0] = *(uint32_t *)Variable;
            break;
        default:
            break;
        }
        break;
    case Preferences_Hardware:
        switch (Adress)
        {
        case 'B':
            Temporary_Variable[0] = *(uint8_t *)Variable;
            break;
        case 'V':
            Temporary_Variable[1] = *(uint8_t *)Variable;
            break;
        case 's':
            Temporary_Variable[2] = *(uint16_t *)Variable;
            break;
        case 'S':
            Temporary_Variable[3] = *(uint32_t *)Variable;
            break;
        default:
            break;
        }
        break;
    case Preferences_Network:
        switch (Adress)
        {
        case 'N':
            if (Temporary_Char_Array[0] != NULL)
            {
                delete[] Temporary_Char_Array[0];
            }
            Temporary_Char_Array[0] = new char[33];
            strcpy(Temporary_Char_Array[0], (char *)Variable);
            break;
        case 'P':
            if (Temporary_Char_Array[1] != NULL)
            {
                delete[] Temporary_Char_Array[1];
            }
            Temporary_Char_Array[1] = new char[81];
            strcpy(Temporary_Char_Array[1], (char *)Variable);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void Shell_Class::Install_Commands()
{
    switch (Get_Command())
    {
    case Instruction('I', 'P'):
        Xila.Event_Dialog(F("Entered passwords does not match."), Xila.Error);
        Xila.Display.Set_Current_Page(F("Shell_Install"));
        break;
    case Instruction('Q', 'u'):
        if (Xila.Event_Dialog(F("Are you sure of the information entered ?"), Xila.Question) != Xila.Button_1)
        {
            return;
        }
        Xila.Display.Set_Current_Page(F("Shell_Install"));
        break;
    case Instruction('C', 'o'):
    {
        if (Xila.Event_Dialog(F("Are you sure of the information entered ?"), Xila.Question) != Xila.Button_1)
        {
            // Regional preferences
            if (Xila.Set_Regionnal_Registry(NULL, Temporary_Variable[0], Temporary_Variable[1]) != Xila.Success)
            {
                Xila.Event_Dialog(F("Cannot set the regional preferences."), Xila.Error);
                Xila.Display.Set_Current_Page(F("Shell_Install"));
            }
            // User account preferences
            if (Temporary_Variable[2] != 0)
            {
                if (Xila.Set_Account_Registry(Temporary_Char_Array[1]) != Xila.Success)
                {
                    Xila.Event_Dialog(F("Cannot set the account registry."), Xila.Error);
                    Xila.Display.Set_Current_Page(F("Shell_Install"));
                }
            }
            if (Xila.Add_User(Temporary_Char_Array[1], Temporary_Char_Array[2]) != Xila.Success)
            {
                Xila.Event_Dialog(F("Cannot create the user account."), Xila.Error);
                Xila.Display.Set_Current_Page(F("Shell_Install"));
                break;
            }
            delete[] Temporary_Char_Array[0];
            delete[] Temporary_Char_Array[1];
            delete[] Temporary_Char_Array[2];
            Temporary_Char_Array[0] = NULL;
            Temporary_Char_Array[1] = NULL;
            Temporary_Char_Array[2] = NULL;
            Login();
        }
    }
    break;
    case Instruction('W', 'C'): // WiFi connect
        if (Xila.WiFi_Connect(Temporary_Char_Array[0], Temporary_Char_Array[1]) != Xila.Success)
        {
            Xila.Event_Dialog(F("Failed to connect to the WiFi network."), Xila.Error);
            Xila.Display.Set_Current_Page(F("Shell_Install"));
        }
        else
        {
            Xila.Event_Dialog(F("Succed to connect to the WiFi Network"), Xila.Information);
            Xila.Display.Set_Current_Page(F("Shell_Install"));
        }
        break;
    default:
        break;
    }
}

void Shell_Class::Main_Task(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (Xila.Display.Get_Current_Page())
        {
        case Pages::About:
            Instance_Pointer->Preferences_System_Commands();
            break;
        case Pages::Desk:
            Instance_Pointer->Desk_Commands();
            break;
        case Pages::Drawer:
            Instance_Pointer->Drawer_Commands();
            break;
        case Pages::Event:
            Instance_Pointer->Current_Command = Instance_Pointer->Get_Command();
            Instance_Pointer->Main_Commands();
            break;
        case Pages::File_Manager:
            Instance_Pointer->File_Manager_Commands();
            break;
        case Pages::Preferences_Hardware:
            Instance_Pointer->Preferences_Hardware_Commands();
            break;
        case Pages::Install:
            Instance_Pointer->Install_Commands();
            break;
        case Pages::Login:
            Instance_Pointer->Login_Commands();
            break;
        case Pages::Preferences_Network:
            Instance_Pointer->Preferences_Network_Commands();
            break;
        case Pages::Preferences_Personal:
            Instance_Pointer->Preferences_Personal_Commands();
            break;
        case Pages::Shutdown:
            Instance_Pointer->Shutdown_Commands();
            break;
        case Pages::Preferences_System:
            Instance_Pointer->Preferences_System_Commands();
            break;
        case Pages::Welcome:
            Instance_Pointer->Install_Commands();
            break;
        default:
            break;
        }
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

void Shell_Class::Desk_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0: // IDLE
        Idle();
        break;
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::Login_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0: // IDLE
        Idle();
        break;
    case 0x4C6F: // Lo : Login with entred username and password
        Instance_Pointer->Login();
        break;
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::Drawer_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0:
        Idle();
        break;
    case 0x4E64: // Nd : Next drawer items

        break;
    case 0x5064: // Pd : Previous drawer items

        break;
    case 0x6430: // dx : Open software from drawer
        Open_From_Drawer(0);
        break;
    case 0x6431: // dx : Open software from drawer
        Open_From_Drawer(1);
        break;
    case 0x6432: // dx : Open software from drawer
        Open_From_Drawer(2);
        break;
    case 0x6433: // dx : Open software from drawer
        Open_From_Drawer(3);
        break;
    case 0x6434: // dx : Open software from drawer
        Open_From_Drawer(4);
        break;
    case 0x6435: // dx : Open software from drawer
        Open_From_Drawer(5);
        break;
    case 0x6436: // dx : Open software from drawer
        Open_From_Drawer(6);
        break;
    case 0x6437: // dx : Open software from drawer
        Open_From_Drawer(7);
        break;
    case 0x6438: // dx : Open software from drawer
        Open_From_Drawer(8);
        break;
    case 0x6439: // dx : Open software from drawer
        Open_From_Drawer(9);
        break;
    case 0x6441: // dx : Open software from drawer
        Open_From_Drawer(10);
        break;
    case 0x6442: // dx : Open software from drawer
        Open_From_Drawer(11);
        break;
    case 0x6443: // dx : Open software from drawer
        Open_From_Drawer(12);
        break;
    case 0x6444: // dx : Open software from drawer
        Open_From_Drawer(13);
        break;
    case 0x6445: // dx : Open software from drawer
        Open_From_Drawer(14);
        break;
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::Preferences_Network_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case Instruction('W', 'C'):
        if (Xila.WiFi_Connect(Temporary_Char_Array[0], Temporary_Char_Array[1]) != Xila.Success)
        {
            Xila.Event_Dialog(F("Failed to connect to the WiFi Network."), Xila.Error);
            Xila.Display.Set_Current_Page(F("Shell_Network"));
        }
        delete[] Temporary_Char_Array[0];
        delete[] Temporary_Char_Array[1];
        Temporary_Char_Array[0] = NULL;
        Temporary_Char_Array[1] = NULL;
        break;
    case Instruction('W', 'A'):
        WiFi.disconnect();
        WiFi.softAP(Temporary_Char_Array[0], Temporary_Char_Array[1]);
        delete[] Temporary_Char_Array[0];
        delete[] Temporary_Char_Array[1];
        Temporary_Char_Array[0] = NULL;
        Temporary_Char_Array[1] = NULL;
        break;
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::Preferences_Personal_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case Instruction('S', 'P'):
        break;
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::Preferences_Hardware_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case Instruction('D', 'C'):
        Xila.Display.Calibrate();
        break;
    case Instruction('S', 'H'):
        Xila.Display.Set_Brightness((uint8_t)Temporary_Variable[0]);
        Xila.Sound.Set_Volume((uint8_t)Temporary_Variable[1]);
        Xila.Display_Standby_Time = (uint16_t)Temporary_Variable[2];
        Xila.System_Standby_Time = Temporary_Variable[3];
        break;
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::Preferences_Personal_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0:
        Idle();
        break;
    case Instruction('S', 'P'):
    {
        DynamicJsonDocument Shell_Registry(256);
        Temporary_File = Xila.Drive->open("/USERS/" + String(Xila.Current_Username), FILE_WRITE);
        if (deserializeJson(Shell_Registry, Temporary_File) != DeserializationError::Ok)
        {
            Xila.Event_Dialog(F("Cannot set the user shell registry."), Xila.Error);
            Open_Preferences('P');
        }
        else
        {
            Shell_Registry["Color"] = (uint16_t)Temporary_Variable[0];
        }
    }
    break;
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::Shutdown_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0:
        Idle();
        break;
    case Instruction('R', 'S'): // RS : Restart system
        Xila.Restart();
        break;
    case Instruction('H', 'S'): // HS : hibernate sys

        break;
    case Instruction('L', 'S'): // LS : lock system
        break;

    case Instruction('S', 'S'): // SS : shutdown
        Xila.Display.Set_Current_Page(F("LOAD_TXT"));
        Xila.Shutdown();
        break;
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::Main_Commands()
{
    switch (Current_Command)
    {
    case Instruction('O', 's'): // Os : Shutdown menu
        Xila.Display.Set_Current_Page(F("Shell_Shutdown"));
        break;
    case Instruction('O', 'L'): // "OL" : Open Login page
        Open_Login();
        break;
    case Instruction('O', 'D'): // "OD" Open Desk page & load it
        Open_Desk();
        break;
    case Instruction('O', 'd'): // "Od" Open drawer
        Open_Drawer();
        break;
    case Instruction('O', 'A'): // Open about xila
        Xila.Display.Set_Current_Page(F("Shell_About"));
        break;
    case Xila.Installation_Wizard:
        Xila.Display.Set_Current_Page(F("Shell_Install"));
        break;
    case Xila.Open_File_Dialog:
        File_Manager_Mode = Xila.Open_File_Dialog;
        Open_File_Manager();
        break;
    case Xila.Open_Folder_Dialog:
        File_Manager_Mode = Xila.Open_Folder_Dialog;
        Open_File_Manager();
        break;
    case Xila.Save_File_Dialog:
        File_Manager_Mode = Xila.Save_File_Dialog;
        Open_File_Manager();
        break;
    case 0x4F46: // "OF" : Open file manager
        File_Manager_Mode = 0;
        Open_File_Manager();
        break;
    case Instruction('O', 'P'): // "OP" : Open preferiencies (default : personnal)
        Instance_Pointer->Open_Preferences('P');
        break;
    case Instruction('O', 'H'): // "OH" : Open hardware prefencies
        Instance_Pointer->Open_Preferences('H');
        break;
    case Instruction('O', 'N'): // "ON" : Open network
        Instance_Pointer->Open_Preferences('N');
        break;
    case Instruction('O', 'S'): // "OS" : Open system preferencies
        Instance_Pointer->Open_Preferences('S');
        break;
    case Xila.Open: // open routine
        Execute(Xila.Maximize);
        break;
    case Xila.Close: // close
        Xila.Display.Set_Current_Page(F("Shell_Load"));
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Shutdown"));
        Xila.Display.Set_Text(F("LOAD_TXT"), F("Shutting down ..."));
        delete Instance_Pointer;
        vTaskDelete(NULL);
        break;
    case Xila.Minimize: // minimize
        vTaskSuspend(NULL);
        break;
    case Xila.Maximize:
        if (Xila.Power_Button_Counter == 1)
        {
            Instance_Pointer->Execute(0x534D);
        }
        Instance_Pointer->Open_Desk();
        break;
    }
}

void Shell_Class::Idle()
{
    vTaskDelay(pdMS_TO_TICKS(20));
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
        Xila.Open_Software(Xila.Software_Handle_Pointer[Slot]); // exclude 1st slot (shell ui), so add, minus 2 = 1
        break;
    }
}

void Shell_Class::Dock(uint8_t Slot, uint8_t Action)
{
    if (Action == 'M') // maximize
    {
        Xila.Maximize_Software(Slot + 1);
    }
    else if (Action == 'C')
    {
        Xila.Close_Software(Xila.Open_Software_Pointer[Slot + 1]->Handle_Pointer);
    }
}

void Shell_Class::Open_Preferences(char const &Section)
{
    switch (Section)
    {
    case 'P':
        Xila.Display.Set_Current_Page(F("Shell_Personal"));
        break;
    case 'H':
        Xila.Display.Set_Current_Page(F("Shell_Hardware"));
        break;
    case 'N':
        Xila.Display.Set_Current_Page(F("Shell_Network"));

        break;
    case 'S':
        Xila.Display.Set_Current_Page(F("Shell_System"));
        Xila.Display.Set_Text(F("NTPVAL_TXT"), Xila.NTP_Server);
        Xila.Display.Set_Text(F("USERNVAL_TXT"), Xila.Current_Username);

        break;
    default:
        break;
    }
}

void Shell_Class::Modify_User(uint8_t const &Mode)
{
    switch (Mode)
    {
    case 'D':
        if (Xila.Event_Dialog(F("Are you sure you want to delete this user ?"), Xila.Question) == Xila.Button_2)
        {
            if (Xila.Delete_User(Username, Password) == Xila.Success)
            {
                Xila.Event_Dialog(F("Succed to delete this user account."), Xila.Information);
                if (strcmp(Xila.Current_Username, Username) == 0)
                {
                    Logout();
                    return;
                }
            }
            else
            {
                Xila.Event_Dialog(F("Failed to delete this user account."), Xila.Error);
            }
        }
        break;
    case 'A':
        if (Xila.Add_User(Username, Password) == Xila.Success)
        {
            Xila.Event_Dialog(F("User account created successfully."), Xila.Information);
        }
        else
        {
            Xila.Event_Dialog(F("Failed to create this user account."), Xila.Error);
        }
        break;
    case 'M':
        if (Xila.Change_Password(Username, Password, Password_To_Set) == Xila.Success)
        {
            Xila.Event_Dialog(F("Succed to change user's password."), Xila.Information);
        }
        else
        {
            Xila.Event_Dialog(F("Failed to change user's password."), Xila.Error);
        }
        break;
    }
    Execute(0x4F53);
}

void Shell_Class::Logout()
{
    if (Xila.Logout() == Xila.Success)
    {
    }
    Open_Login();
}

void Shell_Class::Open_Desk()
{
    Verbose_Print_Line("> Open desk");
    if (Xila.Current_Username[0] == '\0')
    {
        Open_Login();
        return;
    }
    Xila.Display.Set_Current_Page(F("Shell_Desk"));

    if (Desk_Background == 0)
    {
        Xila.Display.Hide(F("COLORB_TXT"));
        Xila.Display.Show(F("IMAGEB_TXT"));
    }
    else
    {
        Xila.Display.Set_Background_Color(F("COLORB_TXT"), Desk_Background);
        Xila.Display.Hide(F("IMAGEB_TXT"));
        Xila.Display.Show(F("COLORB_TXT"));
    }
    Xila.Display.Hide(F("MAXIMIZE_BUT"));
    Xila.Display.Hide(F("CLOSE_BUT"));

    char Temporary_String[] = "SLOT _PIC";

    // List all files on the desk
    /*Temporary_File = Xila.Drive->open("/USERS/" + String(Xila.Current_Username) + "/DESKTOP/");
    Temporary_File.rewindDirectory();
    Temporary_File.openNextFile();*/

    // List all running app on the task bar
    for (uint8_t Slot = 2; Slot < 8; Slot++)
    {
        Temporary_String[4] = Slot + 47;
        if (Xila.Open_Software_Pointer[Slot] != NULL)
        {
            Xila.Display.Set_Picture(Temporary_String, Xila.Open_Software_Pointer[Slot]->Handle_Pointer->Icon);
        }
        else
        {
            Xila.Display.Set_Picture(Temporary_String, Empty_32); //if there's
        }
    }
}

void Shell_Class::Open_Drawer()
{
    Xila.Display.Set_Current_Page(F("Shell_Drawer"));
    char Temporary_String[11];
    Temporary_String[0] = '\r'; //jump
    Temporary_String[1] = '\n';
    strcpy(Temporary_String + 2, Xila.Current_Username);
    Xila.Display.Set_Text(F("USERNAME_TXT"), Temporary_String);
    Xila.Display.Show(F("SHUTDOWN_PIC"));
    strcpy(Temporary_String, "ITEM _TXT");
    uint8_t Item = 0;
    Xila.Display.Set_Text(F("ITEM0_TXT"), F("File Manager"));
    Xila.Display.Set_Picture(F("ITEM0_PIC"), File_Manager_32);
    Xila.Display.Set_Text(F("ITEM1_TXT"), F("Preferences"));
    Xila.Display.Set_Picture(F("ITEM1_PIC"), Preferences_32);
    for (Item = 2; Item < 10; Item++)
    {
        Temporary_String[4] = Item + 48;
        if (Xila.Software_Handle_Pointer[Item] != NULL)
        {
            Xila.Display.Set_Text(String(Temporary_String), String(Xila.Software_Handle_Pointer[Item]->Name));
        }
        else
        {
            Xila.Display.Set_Text(String(Temporary_String), "");
        }
    }
    strcpy(Temporary_String, "ITEM1 _TXT");
    for (Item = 0; Item < 4; Item++)
    {
        Temporary_String[5] = Item + 48;
        if (Xila.Software_Handle_Pointer[Item + 10] != NULL)
        {
            Xila.Display.Set_Text(String(Temporary_String), String(Xila.Software_Handle_Pointer[Item + 10]->Name));
        }
        else
        {
            Xila.Display.Set_Text(String(Temporary_String), "");
        }
    }
    strcpy(Temporary_String, "ITEM _PIC");
    for (Item = 2; Item < 10; Item++)
    {
        Temporary_String[4] = Item + 48;
        if (Xila.Software_Handle_Pointer[Item] != NULL)
        {
            Xila.Display.Set_Picture(String(Temporary_String), Xila.Software_Handle_Pointer[Item]->Icon);
        }
        else
        {
            Xila.Display.Set_Picture(String(Temporary_String), Empty_32);
        }
    }
    strcpy(Temporary_String, "ITEM1 _PIC");
    for (Item = 0; Item < 5; Item++)
    {
        Temporary_String[5] = Item + 48;
        if (Xila.Software_Handle_Pointer[Item + 10] != NULL)
        {
            Xila.Display.Set_Picture(String(Temporary_String), Xila.Software_Handle_Pointer[Item + 10]->Icon);
        }
        else
        {
            Xila.Display.Set_Picture(String(Temporary_String), Empty_32);
        }
    }
}

// File manager

void Shell_Class::Open_File_Manager()
{
    Xila.Display.Set_Current_Page(F("Shell_File"));
    switch (File_Manager_Mode)
    {
    case Xila.Open_File:
        Xila.Display.Show(F("CANCEL_BUT"));
        Xila.Display.Set_Text(F("SAVEOPEN_BUT"), F("Open"));
        Xila.Display.Show(F("SAVEOPEN_BUT"));
        Xila.Display.Show(F("FILENAME_BUT"));
        break;
    case Xila.Save_File:
        Xila.Display.Show(F("CANCEL_BUT"));
        Xila.Display.Set_Text(F("SAVEOPEN_BUT"), F("Save"));
        Xila.Display.Show(F("SAVEOPEN_BUT"));
        Xila.Display.Show(F("FILENAME_BUT"));
        break;
    case Xila.Open_Folder:
        Xila.Display.Show(F("CANCEL_BUT"));
        Xila.Display.Set_Text(F("SAVEOPEN_BUT"), F("Open"));
        Xila.Display.Show(F("SAVEOPEN_BUT"));
        Xila.Display.Show(F("FILENAME_BUT"));
        break;
    default:
        Xila.Display.Hide(F("CANCEL_BUT"));
        Xila.Display.Hide(F("SAVEOPEN_BUT"));
        Xila.Display.Hide(F("FILENAME_BUT"));
        break;
    }
    Display_Path();
}

void Shell_Class::Display_Path()
{
    Temporary_File = Xila.Drive->open(Current_Path);
    String Temporary_String;
    if (Temporary_File)
    {
        if (Temporary_File.isDirectory())
        {
            Temporary_File.rewindDirectory();
            Xila.Display.Set_Text("PATH_TXT", Current_Path);
            File Item;
            for (byte i = 1; i < 31; i++)
            {
                Item = Temporary_File.openNextFile();
                if (Item)
                {
                    Xila.Display.Set_Text("ITEM" + char(i) + "_TXT", Item.name());
                    if (Item.isDirectory())
                    {
                        Xila.Display.Set_Picture("ITEM" + String(i) + "_PIC", 17);
                    }
                    else
                    {
                        Xila.Display.Set_Picture("ITEM" + String(i) + "_PIC", 16);
                    }
                }
                else
                {
                    Xila.Display.Set_Text("ITEM" + String(i) + "_TXT", "");
                    Xila.Display.Set_Picture("ITEM" + String(i) + "_PIC", 15);
                }

                Item.close();
            }
        }
        else
        {
            Xila.Open_File(Temporary_File);
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
    if (!Xila.Drive->open(Current_Path + "/" + File_Name, FILE_WRITE))
    {
        //error
    }
}

void Shell_Class::Make_Directory(char *Item_Name)
{
    if (!Xila.Drive->exists(Current_Path + Item_Name))
    {
        Xila.Drive->mkdir(Current_Path + Item_Name);
    }
}

void Shell_Class::Delete(char *Item_Name)
{
    switch (Xila.Event_Dialog(F("Do you "), Xila.Question))
    {
    case Xila.Button_1:
        Xila.Drive->remove(Current_Path + Item_Name);
        break;
    default:
        break;
    }
}

// Login

void Shell_Class::Open_Login()
{

    if (Xila.Current_Username[0] == '\0') // Check if logged
    {
        Verbose_Print_Line("> Open login page");
        Xila.Display.Set_Current_Page(F("Shell_Login"));
        Xila.Display.Set_Text(F("USERNAME_TXT"), F("Username"));
        Xila.Display.Set_Text(F("PASSWORD_TXT"), F("Password"));
    }
    else
    {
        Open_Desk();
    }
}

void Shell_Class::Login()
{

    if (Xila.Check_Credentials(Username, Password) == Xila.Good_Credentials)
    {
        strcpy(Xila.Current_Username, Username);
        Verbose_Print_Line(F("> Load user files"));
        Xila.Display.Set_Current_Page(F("Shell_Load"));
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Login"));
        Xila.Display.Refresh(F("CLOSE_BUT"));
        Xila.Display.Set_Text(F("LOAD_TXT"), F("Loading user data ..."));

        DynamicJsonDocument Shell_Registry(256);
        File Temporary_File = Xila.Drive->open("/USERS/" + String(Xila.Current_Username) + "/REGISTRY/SHELL.GRF");
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

        Xila.Display.Set_Value(F("STATE_VAR"), 2);
        vTaskDelay(pdMS_TO_TICKS(1000));
        Open_Desk();
    }
    else // Wrong credentials
    {
        Xila.Event_Dialog(F("Wrong credentials !"), Xila.Error);
        Open_Login();
    }
}
