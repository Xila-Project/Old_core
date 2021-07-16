///
/// @file Shell.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Xila main user interface source file.
/// @version 0.1.0
/// @date 08-04-2021
///
/// @copyright Copyright (c) 2021
///

#include "Software/Shell/Shell.hpp"
#include "Software/Shell/Translation.hpp"

Xila_Class::Software_Handle Shell_Handle("Shell", Shell_Class::Images.Empty_32, Shell_Class::Load_Shell, Shell_Class::Startup);

// -- Initialize shell -- //

Shell_Class *Shell_Class::Instance_Pointer = NULL;

Shell_Class::Shell_Class() : Xila_Class::Software(Shell_Handle)
{
    File_Manager_Pointer = NULL;
    Preferences_Pointer = NULL;
    Next_Refresh = 0;

    Xila.Task.Create(Main_Task, "Shell Task", Memory_Chunk(8), NULL, &Task_Handle);
}

Shell_Class::~Shell_Class()
{
    // -- Unload all modules -- //
    File_Manager_Class::Close();
    Preferences_Class::Close();
    // -- Check if there's a duplicate
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
}

Xila_Class::Software *Shell_Class::Load_Shell()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Shell_Class();
    return Instance_Pointer;
}

void Shell_Class::Startup()
{
    Xila.Software_Management.Open(Shell_Handle);
}

// -- Main shell methods -- //

void Shell_Class::Main_Task(void *)
{
    while (1)
    {
        switch (Xila.Display.Get_Current_Page())
        {
        case Pages.About:
            if (Preferences_Class::State())
            {
                PREFERENCES->Execute_System_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Preferences_Personal:
            if (Preferences_Class::State())
            {
                PREFERENCES->Execute_Personal_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Preferences_System:
            if (Preferences_Class::State())
            {
                PREFERENCES->Execute_System_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;

        case Pages.Desk:
            DESK.Execute_Desk_Instruction(SHELL->Get_Instruction());
            break;
        case Pages.Drawer:
            DESK.Execute_Drawer_Instruction(SHELL->Get_Instruction());
            break;

        case Pages.File_Manager_Main:
        case Pages.File_Manager_Detail:
            if (File_Manager_Class::State())
            {
                FILE_MANAGER->Execute_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Preferences_Hardware:
            if (Preferences_Class::State())
            {
                PREFERENCES->Execute_Hardware_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Preferences_Install:
            if (Preferences_Class::State())
            {
                PREFERENCES->Execute_Install_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Dialog_Color_Picker:
            COLOR_PICKER.Execute_Instruction(SHELL->Get_Instruction());
            break;
        case Pages.Dialog_Event:
            if (EVENT->State())
            {
                EVENT->Execute_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Dialog_Power:
            Dialog_Class::Power_Class::Execute_Instruction(SHELL->Get_Instruction());
            break;
        case Pages.Dialog_Keyboard:
            if (Dialog_Class::Keyboard_Class::State())
            {
                Dialog_Class::Keyboard_Class::Execute_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Dialog_Keypad:
            if (KEYPAD->State())
            {
                KEYPAD->Execute_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Dialog_Login:
            if (LOGIN->State())
            {
                LOGIN->Execute_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Dialog_Load:
            if (LOAD->State())
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Preferences_Network:
            if (Preferences_Class::State())
            {
                PREFERENCES->Execute_Network_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Welcome:
            DESK.Execute_Desk_Instruction(SHELL->Get_Instruction());
            break;
        default:
            SHELL->Execute_Instruction(SHELL->Get_Instruction());
            break;
        }
    }
}

void Shell_Class::Refresh_Header()
{
    // -- Update clock
    Temporary_Char_Array[0] = Xila.Time.Current_Time.tm_hour / 10;
    Temporary_Char_Array[0] += 48;
    Temporary_Char_Array[1] = Xila.Time.Current_Time.tm_hour % 10;
    Temporary_Char_Array[1] += 48;
    Temporary_Char_Array[2] = ':';
    Temporary_Char_Array[3] = Xila.Time.Current_Time.tm_min / 10;
    Temporary_Char_Array[3] += 48;
    Temporary_Char_Array[4] = Xila.Time.Current_Time.tm_min % 10;
    Temporary_Char_Array[4] += 48;
    Temporary_Char_Array[5] = '\0';

    Xila.Display.Set_Text(F("CLOCK_TXT"), Temporary_Char_Array);

    // -- Update connexion
    Temporary_Char_Array[5] = Xila.WiFi.RSSI();

    if (Xila.WiFi.status() == WL_CONNECTED)
    {
        if (Temporary_Char_Array[5] <= -70)
        {
            Xila.Display.Set_Text(F("CONNEXION_BUT"), Xila.Display.WiFi_Low);
        }
        if (Temporary_Char_Array[0] <= -50 && Temporary_Char_Array[0] > -70)
        {
            Xila.Display.Set_Text(F("CONNEXION_BUT"), Xila.Display.WiFi_Medium);
        }
        else
        {
            Xila.Display.Set_Text(F("CONNEXION_BUT"), Xila.Display.WiFi_High);
        }
    }
    else
    {
        Xila.Display.Set_Text(F("CONNEXION_BUT"), ' ');
    }

    // -- Update charge level
    Temporary_Char_Array[5] = Xila.Power.Get_Charge_Level();

    if (Temporary_Char_Array[5] <= 5)
    {
        Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Empty);
        Xila.Display.Set_Font_Color(F("BATTERY_BUT"), Xila.Display.Red);
    }
    else if (Temporary_Char_Array[5] <= 10 && Temporary_Char_Array[5] > 5)
    {
        Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Empty);
        Xila.Display.Set_Font_Color(F("BATTERY_BUT"), Xila.Display.White);
    }
    else if (Temporary_Char_Array[5] <= 35 && Temporary_Char_Array[5] > 10)
    {
        Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Quarter);
    }
    else if (Temporary_Char_Array[5] <= 60 && Temporary_Char_Array[5] > 35)
    {
        Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Half);
    }
    else if (Temporary_Char_Array[5] <= 85 && Temporary_Char_Array[5] > 60)
    {
        Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Three_Quarters);
    }
    else // more than 85 %
    {
        Xila.Display.Set_Text(F("BATTERY_BUT"), Xila.Display.Battery_Full);
    }

    // -- Update sound
    Temporary_Char_Array[5] = Xila.Sound.Get_Volume();

    if (Temporary_Char_Array[5] == 0)
    {
        Xila.Display.Set_Text(F("SOUND_BUT"), Xila.Display.Sound_Mute);
    }
    else if (Temporary_Char_Array[5] < 86)
    {
        Xila.Display.Set_Text(F("SOUND_BUT"), Xila.Display.Sound_Low);
    }
    else if (Temporary_Char_Array[5] < 172)
    {
        Xila.Display.Set_Text(F("SOUND_BUT"), Xila.Display.Sound_Medium);
    }
    else
    {
        Xila.Display.Set_Text(F("SOUND_BUT"), Xila.Display.Sound_High);
    }
}

void Shell_Class::Execute_Instruction(Xila_Class::Instruction Instruction)
{
    switch (Instruction)
    {
    case Xila.Idle:
        if (Xila.Software_Management.Get_State(Shell_Handle) == Xila.Minimized)
        {
            Xila.Task.Delay(80);
        }
        else
        {
            while (Xila.Keyboard.Available())
            {
                switch (Xila.Keyboard.Read())
                {
                case Xila.Keyboard.Escape:
                    Xila.Display.Click("CLOSE_BUT", 0);
                    break;

                default:
                    break;
                }
            }
        }
        if (Xila.Time.Milliseconds() > Next_Refresh)
        {
            Refresh_Header();
            Next_Refresh = Xila.Time.Milliseconds() + 4000;
        }
        Xila.Task.Delay(20);
        break;
    case Xila.Dialog_Color_Picker:
        Dialog.Color_Picker_Pointer.Open();
        break;
    case Xila.Dialog_Power:
        Dialog.Power();
        break;
    case Xila.Dialog_Login:
        Dialog.Login_Pointer->Open(Pages.Dialog_Login);
        break;
    case Xila.Open:
        if (!Xila.Drive.Exists(Users_Directory_Path))
        {
            Xila.Display.Set_Current_Page(Pages.Welcome);
            return;
        }

        if (Xila.Account.Get_State() == Xila.Account.Logged)
        {
            Load_Registry();
        }
    case Instruction('O', 'D'):
    case Xila.Desk: // "OD" Open Desk page & load it
        Desk.Open(Pages.Desk);
        break;
    case Instruction('O', 'd'): // "Od" Open drawer
        Desk.Open(Pages.Drawer);
        break;
    case Instruction('O', 'A'): // Open about xila
        Xila.Display.Set_Current_Page(Pages.About);
        break;
    case Xila.Dialog_Keyboard:
        Dialog.Keyboard_Pointer->Open();
        break;
    case Xila.Dialog_Keypad:
        Dialog.Keypad_Pointer->Open();
        break;
    case Xila.Dialog_Open_File:
        File_Manager_Pointer->Open(Xila.Dialog_Open_File);
        break;
    case Xila.Dialog_Open_Folder:
        File_Manager_Pointer->Open(Xila.Dialog_Open_Folder);
        break;
    case Xila.Dialog_Save_File:
        File_Manager_Pointer->Open(Xila.Dialog_Save_File);
        break;
    case Xila.Dialog_Event:
        Dialog.Event_Pointer->Open();
        break;
    case Xila.Dialog_Load:
        Dialog.Load_Pointer->Open();
        break;
    case Xila.Shutdown:
        DIALOG.Load(Load_Shutdown_Header_String, Load_Shutdown_Message_String);
        Save_Registry();
        break;
    case Xila.Restart:
        DIALOG.Load(Load_Restart_Header_String, Load_Restart_Message_String);
        Save_Registry();
        break;
    case Xila.Hibernate:
        DIALOG.Load(Load_Hibernate_Header_String, Load_Hibernate_Message_String);
        Save_Registry();
        break;
    case Instruction('O', 'F'): // Open file manager
        File_Manager_Class::Open(Xila.Idle);
        break;

    case Instruction('O', 'P'): // Open preferiencies (default : personnal)
        Preferences_Class::Open(Pages.Preferences_Personal);
        break;
    case Instruction('O', 'H'): // "OH" : Open hardware prefencies
        Preferences_Class::Open(Pages.Preferences_Hardware);
        break;
    case Instruction('O', 'N'): // "ON" : Open network
        Preferences_Class::Open(Pages.Preferences_Network);
        break;
    case Instruction('O', 'S'): // "OS" : Open system preferencies
        Preferences_Class::Open(Pages.Preferences_System);
        break;
    case Instruction('O', 'I'):
        Preferences_Class::Open(Pages.Preferences_Install);
        break;
    case Xila.Close: // close
        delete Instance_Pointer;
        Xila.Task.Delete();
        break;
    case Xila.Minimize: // minimize
        break;
    case Xila.Maximize:
        Send_Instruction('R', 'e');
        break;
    default:
        break;
    }
}

// -- Set variable -- //

void Shell_Class::Set_Variable(Xila_Class::Adress Adress, uint8_t Type, const void *Variable)
{
    DUMP(Adress);
    DUMP(Type);
    switch (Xila.Display.Get_Current_Page())
    {
    case Pages.Preferences_Hardware:
        if (Preferences_Class::State())
        {
            switch (Adress)
            {
            case Adress('B', 'r'):
                Xila.Display.Brightness = *(uint8_t *)Variable;
                break;
            case Adress('V', 'o'):
                Xila.Sound.Set_Volume(*(uint8_t *)Variable);
                break;
            default:
                break;
            }
        }
        break;
    case Pages.File_Manager_Main:
        if (File_Manager_Pointer->State())
        {
            switch (Adress)
            {
            case Adress('F', 'i'):
                if (FILE_MANAGER->Current_Path[1] != '\0')
                {
                    strcat(FILE_MANAGER->Current_Path, "/");
                }
                strlcat(FILE_MANAGER->Current_Path, (char *)Variable, sizeof(FILE_MANAGER->Current_Path));
                SHELL->Send_Instruction('R', 'e');
                break;
            case Adress('I', 'P'):
                File_Manager_Pointer->Item_Pointer = (File *)Variable;
                break;
            default:
                break;
            }
        }
        break;
    case Pages.Dialog_Keyboard:
        if (Dialog.Keyboard_Pointer->State())
        {
            switch (Adress)
            {
            case Adress('S', 't'): // -- Keyboard
                Dialog.Keyboard_Pointer->String = (char *)Variable;
                break;
            case Adress('S', 'i'):
                Dialog.Keyboard_Pointer->Size = *(size_t *)Variable;
                break;
            case Adress('M', 'a'):
                Dialog.Keyboard_Pointer->Masked_Input = *(bool *)Variable;
                break;
            case Adress('I', 'n'):
                strlcpy(Dialog.Keyboard_Pointer->String, (const char *)Variable, Dialog.Keyboard_Pointer->Size);
                break;
            default:
                break;
            }
        }
        break;
    case Pages.Dialog_Event:
        if (Dialog.Event_Pointer->State())
        {
            switch (Adress)
            {
            case Adress('M', 'e'): // -- Event
                Dialog.Event_Pointer->Message = (void *)Variable;
                break;
            case Adress('M', 'o'):
                Dialog.Event_Pointer->Mode = *(uint8_t *)Variable;
                break;
            case Adress('T', 'y'):
                Dialog.Event_Pointer->Type = *(uint8_t *)Variable;
                break;
            case Adress('B', '1'):
                Dialog.Event_Pointer->Button_Text[0] = (void *)Variable;
                break;
            case Adress('B', '2'):
                Dialog.Event_Pointer->Button_Text[1] = (void *)Variable;
                break;
            case Adress('B', '3'):
                Dialog.Event_Pointer->Button_Text[2] = (void *)Variable;
                break;
            default:
                break;
            }
        }
        break;
    case Pages.Dialog_Load:
        if (Dialog.Load_Pointer->State())
        {
            switch (Adress)
            {
            case Adress('H', 'e'): // -- Load
                Dialog.Load_Pointer->Header = (void *)Variable;
                break;
            case Adress('M', 'e'):
                Dialog.Load_Pointer->Message = (void *)Variable;
                break;
            case Adress('M', 'o'):
                Dialog.Load_Pointer->Mode = *(uint8_t *)Variable;
                break;
            case Adress('P', 'o'):
                Dialog.Load_Pointer->Page = *(Xila_Class::Page *)Variable;
                break;
            case Adress('S', 'o'):
                Dialog.Load_Pointer->Caller_Software = (Xila_Class::Software *)Variable;
                break;
            case Adress('D', 'u'):
                Dialog.Load_Pointer->Duration = *(uint32_t *)Variable;
                break;
            default:
                break;
            }
        }
        break;
    case Pages.Dialog_Keypad:
        if (Dialog.Keypad_Pointer->State())
        {
            switch (Adress)
            {
            case Adress('N', 'u'):
                Dialog.Keypad_Pointer->Number = (float *)Variable;
                break;
            case Adress('I', 'n'):
                strlcpy(Dialog.Keypad_Pointer->Temporary_Float_String, (char *)Variable, sizeof(Dialog.Keypad_Pointer->Temporary_Float_String));
                break;
            default:
                break;
            }
        }
        break;
    case Pages.Dialog_Color_Picker:
        switch (Adress)
        {
        case Adress('C', 'P'):
            Dialog.Color_Picker_Pointer.Color = (uint16_t *)Variable;
            break;
        case Adress('C', 'o'):
            memcpy(Dialog.Color_Picker_Pointer.Color, (uint16_t *)Variable, sizeof(uint16_t));
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

// -- Shell registry management -- //

Xila_Class::Event Shell_Class::Load_Registry()
{
    char User_Registry_Path[40];
    snprintf(User_Registry_Path, sizeof(User_Registry_Path), (Users_Directory_Path "/%s/Registry/Shell.xrf"), Xila.Account.Get_Current_Username());
    File Registry_File = Xila.Drive.Open(User_Registry_Path);
    DynamicJsonDocument Shell_Registry(256);
    if (deserializeJson(Shell_Registry, Registry_File) != DeserializationError::Ok)
    {
        Registry_File.close();
        return Xila.Error;
    }
    Registry_File.close();
    if (strcmp("Shell", Shell_Registry["Registry"] | "") != 0)
    {
        DESK.Background = Default_Background;
        return Xila.Error;
    }
    DESK.Background = Shell_Registry["Desk Background"] | Default_Background;
    return Xila.Success;
}

Xila_Class::Event Shell_Class::Save_Registry()
{
    char User_Registry_Path[40];
    snprintf(User_Registry_Path, sizeof(User_Registry_Path), (Users_Directory_Path "/%s/Registry/Shell.xrf"), Xila.Account.Get_Current_Username());
    File Registry_File = Xila.Drive.Open(User_Registry_Path, FILE_WRITE);
    DynamicJsonDocument Shell_Registry(256);
    deserializeJson(Shell_Registry, Registry_File);
    Shell_Registry["Registry"] = "Shell";
    Shell_Registry["Desk Background"] = DESK.Background;
    if (serializeJson(Shell_Registry, Registry_File) == 0)
    {
        Registry_File.close();
        return Xila.Error;
    }
    Registry_File.close();
    return Xila.Success;
}
