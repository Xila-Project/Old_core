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

/// @brief Shell constructor.
Shell_Class::Shell_Class(const Accounts_Types::User_Type *Owner_User)
    : Software_Class(&Shell_Handle, Owner_User),
      Desk(this),
      Screen(this),
      Installer_Pointer(NULL),
      Login_Pointer(NULL),
      Drawer_Pointer(NULL)
{
    // - Registry
    if (this->Load_Registry() != Result_Type::Success)
    {
        this->Create_Registry();
    }

    // - Keyboard
    Keyboard.Create(Screen);
    Keyboard.Remove_Text_Area();

    // - Overlay
    Overlay.Create(Screen);
    Overlay.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Overlay.Set_Size(18 * 8, 32);
    Overlay.Set_Alignment(Alignment_Type::Top_Right);
    Overlay.Set_Flex_Flow(Flex_Flow_Type::Row);
    Overlay.Set_Flex_Alignment(Flex_Alignment_Type::Space_Evenly, Flex_Alignment_Type::Center, Flex_Alignment_Type::Center);
    Overlay.Set_Style_Pad_All(0, 0);

    Status_Buttons_Style.Set_Background_Opacity(Opacity_Type::Transparent);
    Status_Buttons_Style.Set_Pad_All(0);
    Status_Buttons_Style.Set_Shadow_Width(0);

    WiFi_Button.Create(Overlay, LV_SYMBOL_WIFI, 24, 24, this);
    WiFi_Button.Add_Style(Status_Buttons_Style, 0);
    WiFi_Button.Get_Child(0).Set_Style_Text_Color(Color_Type::White, 0);

    Sound_Button.Create(Overlay, LV_SYMBOL_VOLUME_MAX, 24, 24, this);
    Sound_Button.Add_Style(Status_Buttons_Style, 0);
    Sound_Button.Get_Child(0).Set_Style_Text_Color(Color_Type::White, 0);

    Battery_Button.Create(Overlay, LV_SYMBOL_BATTERY_FULL, 24, 24, this);
    Battery_Button.Add_Style(Status_Buttons_Style, 0);
    Battery_Button.Get_Child(0).Set_Style_Text_Color(Color_Type::White, 0);

    Clock_Label.Create(Overlay);
    Clock_Label.Set_Alignment(Alignment_Type::Middle_Right);
    Clock_Label.Set_Text("00:00");
    Clock_Label.Set_Style_Text_Color(Color_Type::White, 0);

    Screen.Load();
}

/// @brief Shell destructor.
Shell_Class::~Shell_Class()
{
    this->Save_Registry();
    Drawer_Class::Close(this);
    Login_Class::Close(this);
    Installer_Class::Close(this);
}

/// @brief Shell main task.
void Shell_Class::Main_Task_Function()
{
    uint32_t Next_Refresh = 0;
    while (1)
    {
        if (this->Instruction_Available())
        {
            this->Execute_Instruction(Get_Instruction());
        }
        else
        {
            if (this->Get_Owner_User()->Get_State() == Accounts_Types::User_State_Type::Locked)
            {
                if (Desk.Window.Get_State() != Graphics_Types::Window_State_Type::Minimized)
                {
                    Desk.Window.Set_State(Graphics_Types::Window_State_Type::Minimized);
                }
            }
            else if (System.Get_Up_Time_Milliseconds() > Next_Refresh)
            {
                Refresh_Overlay();
                Next_Refresh = System.Get_Up_Time_Milliseconds() + 5000;
            }

            Main_Task.Delay(40);
        }
    }
}

/// @brief
/// @param Instruction
void Shell_Class::Execute_Instruction(Instruction_Type Instruction)
{
    if (Instruction.Get_Sender() == &Softwares)
    {
        switch (Instruction.Softwares.Get_Code())
        {
        case Softwares_Types::Event_Code_Type::Close:
            delete this;
            break;
        }
        return;
    }

    if (Drawer_Class::Is_Openned(this))
    {
        if (Drawer_Pointer->Window.Get_State() == Graphics_Types::Window_State_Type::Maximized)
        {
            Drawer_Pointer->Execute_Instruction(Instruction);
            return;
        }
    }
    if (Installer_Class::Is_Openned(this))
    {
        if (Installer_Pointer->Dialog.Get_State() == Graphics_Types::Window_State_Type::Maximized)
        {
            Installer_Pointer->Execute_Instruction(Instruction);
            return;
        }
    }
    if (Login_Class::Is_Openned(this) && (Login_Pointer->Dialog.Get_State() == Graphics_Types::Window_State_Type::Maximized))
    {
        if (Login_Pointer->Dialog.Get_State() == Graphics_Types::Window_State_Type::Maximized)
        {
            Login_Pointer->Execute_Instruction(Instruction);
            return;
        }
    }

    Log_Verbose("Shell", "Instruction received");
    Desk.Execute_Instruction(Instruction);
    return;
}

// -- Shell registry management -- //

/// @brief Load shell registry.
/// @return
Result_Type Shell_Class::Load_Registry()
{
    // - Open registry file
    Static_String_Type<64> Shell_Registry_Path;
    this->Get_Owner_User()->Get_Home_Folder_Path(Shell_Registry_Path);
    Shell_Registry_Path += "/Shell/Shell.xrf";
    File_Type Registry_File = Drive.Open(Shell_Registry_Path, true);

    // - Load registry
    StaticJsonDocument<256> Shell_Registry;
    if (!Registry_File || (deserializeJson(Shell_Registry, Registry_File) != DeserializationError::Ok) || (strcmp("Shell", Shell_Registry["Registry"] | "") != 0))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }
    Registry_File.Close();

    // - Load registry values
    this->Desk.Set_Background_Color(Color_Type(Shell_Registry["Desk"]["Background color"] | Shell_Default_Background_Color));
    this->Desk.Set_Foreground_Color(Color_Type(Shell_Registry["Desk"]["Foreground color"] | Shell_Default_Foreground_Color));

    return Result_Type::Success;
}

Result_Type Shell_Class::Create_Registry()
{
    // -
    StaticJsonDocument<256> Shell_Registry;
    Shell_Registry["Registry"] = "Shell";
    Shell_Registry.createNestedObject("Desk");

    // - Open registry file
    Static_String_Type<64> Shell_Registry_Path;
    this->Get_Owner_User()->Get_Home_Folder_Path(Shell_Registry_Path);
    Shell_Registry_Path += "/Registry/Shell.xrf";
    File_Type Registry_File = Drive.Open(Shell_Registry_Path, true);

    // - Write registry
    if (!Registry_File || (serializeJson(Shell_Registry, Registry_File) == 0))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }

    Registry_File.Close();
    return Result_Type::Success;
}

/// @brief Save shell registry.
/// @return
Result_Type Shell_Class::Save_Registry()
{
    // - Open registry file
    Static_String_Type<64> Shell_Registry_Path;
    this->Get_Owner_User()->Get_Home_Folder_Path(Shell_Registry_Path);
    Shell_Registry_Path += "/Registry/Shell.xrf";
    File_Type Registry_File = Drive.Open(Shell_Registry_Path, true);

    // - Load registry
    StaticJsonDocument<256> Shell_Registry;
    if (!Registry_File || (deserializeJson(Shell_Registry, Registry_File) != DeserializationError::Ok) || ((strcmp("Shell", Shell_Registry["Registry"] | "") != 0)))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }

    // - Save registry values
    Shell_Registry["Background color"] = static_cast<uint32_t>(Desk.Get_Background_Color());
    Shell_Registry["Foreground color"] = static_cast<uint32_t>(Desk.Get_Foreground_Color());

    // - Write registry
    if (serializeJson(Shell_Registry, Registry_File) == 0)
    {
        Registry_File.Close();
        return Result_Type::Error;
    }

    // - Close registry file
    Registry_File.Close();
    return Result_Type::Success;
}

/// @brief Refresh the header overlay.
void Shell_Class::Refresh_Overlay()
{
    using namespace Xila::Graphics_Types;

    // - Refresh clock
    static Time_Type Current_Time = System.Get_Time();

    Log_Verbose("Shell", "Refreshing overlay : %u : %u", Current_Time.Get_Hours(), Current_Time.Get_Minutes());

    Clock_Label.Set_Text_Format("%d:%d", 15, 59);



    {
        Label_Type WiFi_Label = Label_Type(WiFi_Button.Get_Child(0)); // Casting
        if (WiFi.Get_Mode() == WiFi_Types::Mode_Type::Station && WiFi.Station.Get_Status() == WiFi_Types::Status_Type::Connected)
        {
            // - Update WiFi signal strength
            // TODO : Add different WiFi signal strength icons.
            if (!WiFi_Label.Is_Valid())
            {
            }
            else if (WiFi.Station.Get_RSSI() >= (-120 / 3))
            {
                WiFi_Label.Set_Text(LV_SYMBOL_WIFI);
            }
            else if (WiFi.Station.Get_RSSI() >= (-120 * 2 / 3))
            {
                WiFi_Label.Set_Text(LV_SYMBOL_WIFI);
            }
            else
            {
                WiFi_Label.Set_Text(LV_SYMBOL_WIFI);
            }
        }
        else if (WiFi.Get_Mode() == WiFi_Types::Mode_Type::Access_Point)
        {
            WiFi_Label.Set_Text("");
        }
        else
        {
            WiFi_Label.Set_Text("");
        }
    }

    {
        Label_Type Battery_Label = Label_Type(Battery_Button.Get_Child(0)); // Casting
        // - Update charge level
        if (!Battery_Label.Is_Valid())
        {
        }
        else if (Power.Get_Charge_Level() >= 85)
        {
            Battery_Label.Set_Text(LV_SYMBOL_BATTERY_FULL);
        }
        else if (Power.Get_Charge_Level() >= 60)
        {
            Battery_Label.Set_Text(LV_SYMBOL_BATTERY_3);
        }
        else if (Power.Get_Charge_Level() >= 35)
        {
            Battery_Label.Set_Text(LV_SYMBOL_BATTERY_2);
        }
        else if (Power.Get_Charge_Level() >= 10)
        {
            Battery_Label.Set_Text(LV_SYMBOL_BATTERY_1);
        }
        else
        {
            Battery_Label.Set_Text(LV_SYMBOL_BATTERY_EMPTY);
        }
    }
    {
        Label_Type Sound_Label = Label_Type(Sound_Button.Get_Child(0)); // Casting
        if (!Sound_Label.Is_Valid())
        {
        }
        // -- Update sound
        else if (Sound.Get_Volume() >= (255 * 2 / 3))
        {
            Sound_Label.Set_Text(LV_SYMBOL_VOLUME_MAX);
        }
        else if (Sound.Get_Volume() >= (255 / 3))
        {
            Sound_Label.Set_Text(LV_SYMBOL_VOLUME_MID);
        }
        else
        {
            Sound_Label.Set_Text(LV_SYMBOL_MUTE);
        }
    }
}