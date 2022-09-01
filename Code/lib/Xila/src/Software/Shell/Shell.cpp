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

    Task.Create(Main_Task, "Shell Task", Memory_Chunk(8), NULL, &Task_Handle);
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
    Software_Management.Open(Shell_Handle);
}

// -- Main shell methods -- //

Xila_Class::Task_Function Shell_Class::Main_Task(void *)
{
    while (1)
    {
        switch (Display.Get_Current_Page())
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
    Temporary_Char_Array[0] = Time.Current_Time.tm_hour / 10;
    Temporary_Char_Array[0] += 48;
    Temporary_Char_Array[1] = Time.Current_Time.tm_hour % 10;
    Temporary_Char_Array[1] += 48;
    Temporary_Char_Array[2] = ':';
    Temporary_Char_Array[3] = Time.Current_Time.tm_min / 10;
    Temporary_Char_Array[3] += 48;
    Temporary_Char_Array[4] = Time.Current_Time.tm_min % 10;
    Temporary_Char_Array[4] += 48;
    Temporary_Char_Array[5] = '\0';

    Display.Set_Text(F("CLOCK_TXT"), Temporary_Char_Array);

    // -- Update connection
    Temporary_Char_Array[5] = WiFi.RSSI();

    if (WiFi.status() == WL_CONNECTED)
    {
        if (Temporary_Char_Array[5] <= -70)
        {
            Display.Set_Text(F("CONNECTION_BUT"), Display.WiFi_Low);
        }
        if (Temporary_Char_Array[0] <= -50 && Temporary_Char_Array[0] > -70)
        {
            Display.Set_Text(F("CONNECTION_BUT"), Display.WiFi_Medium);
        }
        else
        {
            Display.Set_Text(F("CONNECTION_BUT"), Display.WiFi_High);
        }
    }
    else
    {
        Display.Set_Text(F("CONNECTION_BUT"), ' ');
    }

    // -- Update charge level
    Temporary_Char_Array[5] = Power.Get_Charge_Level();

    if (Temporary_Char_Array[5] <= 5)
    {
        Display.Set_Text(F("BATTERY_BUT"), Display.Battery_Empty);
        Display.Set_Font_Color(F("BATTERY_BUT"), Display.Red);
    }
    else if (Temporary_Char_Array[5] <= 10 && Temporary_Char_Array[5] > 5)
    {
        Display.Set_Text(F("BATTERY_BUT"), Display.Battery_Empty);
        Display.Set_Font_Color(F("BATTERY_BUT"), Display.White);
    }
    else if (Temporary_Char_Array[5] <= 35 && Temporary_Char_Array[5] > 10)
    {
        Display.Set_Text(F("BATTERY_BUT"), Display.Battery_Quarter);
    }
    else if (Temporary_Char_Array[5] <= 60 && Temporary_Char_Array[5] > 35)
    {
        Display.Set_Text(F("BATTERY_BUT"), Display.Battery_Half);
    }
    else if (Temporary_Char_Array[5] <= 85 && Temporary_Char_Array[5] > 60)
    {
        Display.Set_Text(F("BATTERY_BUT"), Display.Battery_Three_Quarters);
    }
    else // more than 85 %
    {
        Display.Set_Text(F("BATTERY_BUT"), Display.Battery_Full);
    }

    // -- Update sound
    Temporary_Char_Array[5] = Sound.Get_Volume();

    if (Temporary_Char_Array[5] == 0)
    {
        Display.Set_Text(F("SOUND_BUT"), Display.Sound_Mute);
    }
    else if (Temporary_Char_Array[5] < 86)
    {
        Display.Set_Text(F("SOUND_BUT"), Display.Sound_Low);
    }
    else if (Temporary_Char_Array[5] < 172)
    {
        Display.Set_Text(F("SOUND_BUT"), Display.Sound_Medium);
    }
    else
    {
        Display.Set_Text(F("SOUND_BUT"), Display.Sound_High);
    }
}

void Shell_Class::Execute_Instruction(Xila_Class::Instruction Instruction)
{
    switch (Instruction)
    {
    case Idle:
        if (Software_Management.Get_State(Shell_Handle) == Minimized)
        {
            Task_Class::Delay(80);
        }
        else
        {
            while (Keyboard.Available())
            {
                switch (Keyboard.Read())
                {
                case Keyboard.Escape:
                    Display.Click("CLOSE_BUT", 0);
                    break;

                default:
                    break;
                }
            }
        }
        if (Time.Milliseconds() > Next_Refresh)
        {
            Refresh_Header();
            Next_Refresh = Time.Milliseconds() + 4000;
        }
        Task_Class::Delay(20);
        break;
    case Dialog_Color_Picker:
        Dialog.Color_Picker_Pointer.Open();
        break;
    case Dialog_Power:
        Dialog.Power();
        break;
    case Dialog_Login:
        Dialog.Login_Pointer->Open(Pages.Dialog_Login);
        break;
    case Open:
        if (!Drive.Exists(Users_Directory_Path))
        {
            Display.Set_Current_Page(Pages.Welcome);
            return;
        }

        if (Account.Get_State() == Account.Logged)
        {
            Load_Registry();
        }
    case Instruction('O', 'D'):
    case Desk: // "OD" Open Desk page & load it
        Desk.Open(Pages.Desk);
        break;
    case Instruction('O', 'd'): // "Od" Open drawer
        Desk.Open(Pages.Drawer);
        break;
    case Instruction('O', 'A'): // Open about xila
        Display.Set_Current_Page(Pages.About);
        break;
    case Dialog_Keyboard:
        Dialog.Keyboard_Pointer->Open();
        break;
    case Dialog_Keypad:
        Dialog.Keypad_Pointer->Open();
        break;
    case Dialog_Open_File:
        File_Manager_Pointer->Open(Dialog_Open_File);
        break;
    case Dialog_Open_Folder:
        File_Manager_Pointer->Open(Dialog_Open_Folder);
        break;
    case Dialog_Save_File:
        File_Manager_Pointer->Open(Dialog_Save_File);
        break;
    case Dialog_Event:
        Dialog.Event_Pointer->Open();
        break;
    case Dialog_Load:
        Dialog.Load_Pointer->Open();
        break;
    case Shutdown:
        DIALOG.Load(Load_Shutdown_Header_String, Load_Shutdown_Message_String);
        Save_Registry();
        break;
    case Restart:
        DIALOG.Load(Load_Restart_Header_String, Load_Restart_Message_String);
        Save_Registry();
        break;
    case Hibernate:
        DIALOG.Load(Load_Hibernate_Header_String, Load_Hibernate_Message_String);
        Save_Registry();
        break;
    case Instruction('O', 'F'): // Open file manager
        File_Manager_Class::Open(Idle);
        break;

    case Instruction('O', 'P'): // Open preferiencies (default : personal)
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
    case Close: // close
        delete Instance_Pointer;
        Task.Delete();
        break;
    case Minimize: // minimize
        break;
    case Maximize:
        Send_Instruction('R', 'e');
        break;
    default:
        break;
    }
}

// -- Set variable -- //

void Shell_Class::Set_Variable(Xila_Class::Address Address, uint8_t Type, const void *Variable)
{
    DUMP(Address);
    DUMP(Type);
    switch (Display.Get_Current_Page())
    {
    case Pages.Preferences_Hardware:
        if (Preferences_Class::State())
        {
            switch (Address)
            {
            case Address('B', 'r'):
                Display.Brightness = *(uint8_t *)Variable;
                break;
            case Address('V', 'o'):
                Sound.Set_Volume(*(uint8_t *)Variable);
                break;
            default:
                break;
            }
        }
        break;
    case Pages.File_Manager_Main:
        if (File_Manager_Pointer->State())
        {
            switch (Address)
            {
            case Address('F', 'i'):
                if (FILE_MANAGER->Current_Path[1] != '\0')
                {
                    strcat(FILE_MANAGER->Current_Path, "/");
                }
                strlcat(FILE_MANAGER->Current_Path, (char *)Variable, sizeof(FILE_MANAGER->Current_Path));
                SHELL->Send_Instruction('R', 'e');
                break;
            case Address('I', 'P'):
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
            switch (Address)
            {
            case Address('S', 't'): // -- Keyboard
                Dialog.Keyboard_Pointer->String = (char *)Variable;
                break;
            case Address('S', 'i'):
                Dialog.Keyboard_Pointer->Size = *(size_t *)Variable;
                break;
            case Address('M', 'a'):
                Dialog.Keyboard_Pointer->Masked_Input = *(bool *)Variable;
                break;
            case (Address('I', 'n')):
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
            switch (Address)
            {
            case Address('M', 'e'): // -- Event
                Dialog.Event_Pointer->Message = (void *)Variable;
                break;
            case Address('M', 'o'):
                Dialog.Event_Pointer->Mode = *(uint8_t *)Variable;
                break;
            case Address('T', 'y'):
                Dialog.Event_Pointer->Type = *(uint8_t *)Variable;
                break;
            case Address('B', '1'):
                Dialog.Event_Pointer->Button_Text[0] = (void *)Variable;
                break;
            case Address('B', '2'):
                Dialog.Event_Pointer->Button_Text[1] = (void *)Variable;
                break;
            case Address('B', '3'):
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
            switch (Address)
            {
            case Address('H', 'e'): // -- Load
                Dialog.Load_Pointer->Header = (void *)Variable;
                break;
            case Address('M', 'e'):
                Dialog.Load_Pointer->Message = (void *)Variable;
                break;
            case Address('M', 'o'):
                Dialog.Load_Pointer->Mode = *(uint8_t *)Variable;
                break;
            case Address('P', 'o'):
                Dialog.Load_Pointer->Page = *(Xila_Class::Page *)Variable;
                break;
            case Address('S', 'o'):
                Dialog.Load_Pointer->Caller_Software = (Xila_Class::Software *)Variable;
                break;
            case Address('D', 'u'):
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
            switch (Address)
            {
            case Address('N', 'u'):
                Dialog.Keypad_Pointer->Number = (float *)Variable;
                break;
            case Address('I', 'n'):
                strlcpy(Dialog.Keypad_Pointer->Temporary_Float_String, (char *)Variable, sizeof(Dialog.Keypad_Pointer->Temporary_Float_String));
                break;
            default:
                break;
            }
        }
        break;
    case Pages.Dialog_Color_Picker:
        switch (Address)
        {
        case (Address('C', 'P')):
            DUMP("Color picker color pointer :");
            Dialog.Color_Picker_Pointer.Color = (uint16_t *)Variable;
            break;
        case Address('C', 'o'):
            DUMP("Color picker color :");
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

Result::Type Shell_Class::Load_Registry()
{
    char User_Registry_Path[40];
    snprintf(User_Registry_Path, sizeof(User_Registry_Path), (Users_Directory_Path "/%s/Registry/Shell.xrf"), Account.Get_Current_Username());
    File Registry_File = Drive.Open(User_Registry_Path);
    DynamicJsonDocument Shell_Registry(256);
    if (deserializeJson(Shell_Registry, Registry_File) != DeserializationError::Ok)
    {
        Registry_File.close();
        return Result::Error;
    }
    Registry_File.close();
    if (strcmp("Shell", Shell_Registry["Registry"] | "") != 0)
    {
        DESK.Background = Default_Background;
        return Result::Error;
    }
    DESK.Background = Shell_Registry["Desk Background"] | Default_Background;
    return Result::Success;
}

Result::Type Shell_Class::Save_Registry()
{
    char User_Registry_Path[40];
    snprintf(User_Registry_Path, sizeof(User_Registry_Path), (Users_Directory_Path "/%s/Registry/Shell.xrf"), Account.Get_Current_Username());
    File Registry_File = Drive.Open(User_Registry_Path, FILE_WRITE);
    DynamicJsonDocument Shell_Registry(256);
    deserializeJson(Shell_Registry, Registry_File);
    Shell_Registry["Registry"] = "Shell";
    Shell_Registry["Desk Background"] = DESK.Background;
    if (serializeJson(Shell_Registry, Registry_File) == 0)
    {
        Registry_File.close();
        return Result::Error;
    }
    Registry_File.close();
    return Result::Success;
}
