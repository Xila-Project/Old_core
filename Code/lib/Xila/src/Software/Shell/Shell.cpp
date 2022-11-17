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

Software_Handle_Type Shell_Class::Handle("Shell", Shell_Class::Images.Empty_32, Shell_Class::Load_Shell, Shell_Class::Startup);

// -- Initialize shell -- //

std::vector<Shell_Class *> Shell_Class::Instances;

Shell_Class::Shell_Class() : Software_Class()
{
    File_Manager_Pointer = NULL;
    Preferences_Pointer = NULL;
    Next_Refresh = 0;

    Instances.push_back(this);
}

Shell_Class::~Shell_Class()
{
    // -- Unload all modules -- //
    File_Manager_Class::Close();
    Preferences_Class::Close();

    Instances.erase(std::remove(Instances.begin(), Instances.end(), this), Instances.end());
}

Software_Type *Shell_Class::Open_Shell()
{
    return new Shell_Class();
}

void Shell_Class::Startup()
{
    Software_Management.Open(Shell_Handle);
}

// -- Main shell methods -- //

void Shell_Class::Main_Task_Function()
{
    while (1)
    {

        if (File_Manager_Pointer != NULL)
        {
            if (File_Manager_Pointer->Window.Is_Maximized() == true)
            {
                File_Manager_Pointer->Execute_Instruction(Get_Instruction());
            }
        }
        else if (Preferences_Pointer != NULL)
        {
            if (Preferences_Pointer->Window.Is_Maximized() == true)
            {
                Preferences_Pointer->Execute_Instruction(Get_Instruction());
            }
        }
        else if (Drawer.Window.Is_Maximized())
        {
            Drawer.Execute_Instruction(Get_Instruction());
        }
        else
        {
            Desk.Execute_Instruction(Get_Instruction());
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
