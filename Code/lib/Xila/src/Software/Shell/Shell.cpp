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

Shell_Class::Shell_Handle_Class Shell_Class::Handle;

/// @brief Shell constructor.
Shell_Class::Shell_Class(const Accounts_Types::User_Type *Owner_User)
    : Software_Class(Handle, Owner_User),
      Desk(this),
      Screen(this),
      Drawer(this),
      Installer_Pointer(NULL),
      Login_Pointer(NULL)
{
}

/// @brief Shell destructor.
Shell_Class::~Shell_Class()
{
    this->Save_Registry();
    Login_Class::Close(this);
    Installer_Class::Close(this);
}

void Shell_Class::Set_Interface()
{
    using namespace Graphics_Types;

    Screen.Load();

    // - Keyboard
    Keyboard.Create(Screen);
    Keyboard.Remove_Text_Area();

    // - Overlay
    Overlay.Create(Graphics.Get_Top_Layer());
    Overlay.Move_Foreground();
    Overlay.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Overlay.Set_Size(18 * 8, 32);
    Overlay.Set_Alignment(Alignment_Type::Top_Right, -4, 0);
    Overlay.Set_Flex_Flow(Flex_Flow_Type::Row);
    Overlay.Set_Flex_Alignment(Flex_Alignment_Type::Space_Evenly, Flex_Alignment_Type::Center, Flex_Alignment_Type::Center);
    Overlay.Set_Style_Pad_All(0, 0);

    Status_Buttons_Style.Set_Background_Opacity(Opacity_Type::Transparent);
    Status_Buttons_Style.Set_Pad_All(0);
    Status_Buttons_Style.Set_Shadow_Width(0);

    WiFi_Button.Create(Overlay, " ", 24, 24, this);
    WiFi_Button.Add_Style(Status_Buttons_Style, 0);
    WiFi_Button.Get_Child(0).Set_Style_Text_Color(Color_Type::White, 0);

    Sound_Button.Create(Overlay, " ", 24, 24, this);
    Sound_Button.Add_Style(Status_Buttons_Style, 0);
    Sound_Button.Get_Child(0).Set_Style_Text_Color(Color_Type::White, 0);

    Battery_Button.Create(Overlay, " ", 24, 24, this);
    Battery_Button.Add_Style(Status_Buttons_Style, 0);
    Battery_Button.Get_Child(0).Set_Style_Text_Color(Color_Type::White, 0);

    Clock_Label.Create(Overlay);
    Clock_Label.Set_Alignment(Alignment_Type::Middle_Right);
    Clock_Label.Set_Text("00:00");
    Clock_Label.Set_Style_Text_Color(Color_Type::White, 0);

    Desk.Set_Interface();
}

/// @brief Shell main task.
void Shell_Class::Main_Task_Function()
{
    uint32_t Next_Refresh = 0;

    // - Registry
    if (this->Load_Registry() != Result_Type::Success)

    {
        this->Create_Registry();
    }

    Set_Interface();

    while (1)
    {
        // Log_Verbose("Shell", "Main task");
        if (this->Instruction_Available())
        {
            // Log_Verbose("Shell", "Instruction received");
            this->Execute_Instruction(Get_Instruction());
        }
        else
        {
            if (this->Get_Owner_User()->Get_State() != Accounts_Types::User_State_Type::Logged)
            {
                Main_Task.Delay(100);
            }

            // - Refresh the overlay every 10 seconds
            else if (System.Get_Up_Time_Milliseconds() > Next_Refresh)
            {
                Refresh_Overlay();
                Next_Refresh = System.Get_Up_Time_Milliseconds() + 10000;
            }

            Main_Task.Delay(40);
        }
    }
}

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
    else if (Instruction.Get_Sender() == &Graphics)
    {
        if (Power_Class::Is_Openned(*this))
        {
            Power_Pointer->Execute_Instruction(Instruction);
            return;
        }

        if (Login_Class::Is_Openned(this))
        {
            Login_Pointer->Execute_Instruction(Instruction);
            return;
        }

        if (Installer_Class::Is_Openned(this))
        {

            Installer_Pointer->Execute_Instruction(Instruction);
            return;
        }

        if (Drawer.Is_Openned())
        {
            Drawer.Execute_Instruction(Instruction);
            return;
        }

        Desk.Execute_Instruction(Instruction);
        return;
    }
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
    Drive_Types::File_Type Registry_File = Drive.Open(Shell_Registry_Path, true);

    // - Load registry
    StaticJsonDocument<256> Shell_Registry;
    if (!Registry_File || (deserializeJson(Shell_Registry, Registry_File) != DeserializationError::Ok) || (strcmp("Shell", Shell_Registry["Registry"] | "") != 0))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }
    Registry_File.Close();

    // - Load registry values
    Graphics.Set_Theme_Primary_Color(Graphics_Types::Color_Type(Graphics_Types::Color_Type(Shell_Registry["Desk"]["Primary color"] | (uint32_t)Graphics_Types::Color_Type::Blue[5])));
    Graphics.Set_Theme_Dark_Mode(Shell_Registry["Desk"]["Dark mode"] | true);

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
    Drive_Types::File_Type Registry_File = Drive.Open(Shell_Registry_Path, true);

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
    Drive_Types::File_Type Registry_File = Drive.Open(Shell_Registry_Path, true);

    // - Load registry
    StaticJsonDocument<256> Shell_Registry;
    if (!Registry_File || (deserializeJson(Shell_Registry, Registry_File) != DeserializationError::Ok) || ((strcmp("Shell", Shell_Registry["Registry"] | "") != 0)))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }

    // - Save registry values

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
    static char Clock_Text[6] = "00:00";

    using namespace Xila::Graphics_Types;

    // - Refresh clock
    static Time_Type Current_Time = System.Get_Time();

    if (Current_Time.Get_Hours() < 10)
    {
        Clock_Text[0] = '0';
        Clock_Text[1] = '0' + Current_Time.Get_Hours();
    }
    else
    {
        Clock_Text[0] = '0' + Current_Time.Get_Hours() / 10;
        Clock_Text[1] = '0' + Current_Time.Get_Hours() % 10;
    }

    Clock_Text[2] = ':';

    if (Current_Time.Get_Minutes() < 10)
    {
        Clock_Text[3] = '0';
        Clock_Text[4] = '0' + Current_Time.Get_Minutes();
    }
    else
    {
        Clock_Text[3] = '0' + Current_Time.Get_Minutes() / 10;
        Clock_Text[4] = '0' + Current_Time.Get_Minutes() % 10;
    }

    Clock_Label.Set_Text(Clock_Text);

    {
        Label_Type WiFi_Label = Label_Type(WiFi_Button.Get_Child(0)); // Casting
        if (Communication.WiFi.Get_Mode() == Communication_Types::Mode_Type::Station && Communication.WiFi.Station.Get_Status() == Communication_Types::Status_Type::Connected)
        {
            // - Update WiFi signal strength
            // TODO : Add different WiFi signal strength icons.
            if (!WiFi_Label.Is_Valid())
            {
            }
            else if (Communication.WiFi.Station.Get_RSSI() >= (-120 / 3))
            {
                WiFi_Label.Set_Text(LV_SYMBOL_WIFI);
            }
            else if (Communication.WiFi.Station.Get_RSSI() >= (-120 * 2 / 3))
            {
                WiFi_Label.Set_Text(LV_SYMBOL_WIFI);
            }
            else
            {
                WiFi_Label.Set_Text(LV_SYMBOL_WIFI);
            }
        }
        else if (Communication.WiFi.Get_Mode() == Communication_Types::Mode_Type::Access_Point)
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
        Battery_Label.Set_Text(LV_SYMBOL_BATTERY_2);
        /*
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
        }*/
    }
    {
        Label_Type Sound_Label = Label_Type(Sound_Button.Get_Child(0)); // Casting
        if (Sound_Label.Is_Valid())
        {
            // -- Update sound
            // Log_Verbose("Shell", "Sound volume : %d", Sound.Get_Volume());
            if (Sound.Get_Volume() >= (255 * 2 / 3))
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
}

void Shell_Class::Get_Software_Icon(Graphics_Types::Object_Type &Icon_Container, const String_Type &Name)
{
    using namespace Xila::Graphics_Types;

    if (!Icon_Container.Is_Valid())
    {
        Log_Verbose("Shell", "Invalid icon label.");
        return;
    }

    Label_Type Icon_Label = Label_Type(Icon_Container.Get_Child(0));

    if (!Icon_Label.Is_Valid())
    {
        Log_Verbose("Shell", "Invalid icon label.");
        return;
    }

    Icon_Container.Set_Size(5 * 8, 5 * 8);
    Icon_Container.Set_Style_Radius(5, 0);
    Icon_Container.Set_Style_Pad_All(0, 0);

    char Icon_Characters[] = {Name.Get_Character(0), Name.Get_Character(1), 0};
    Icon_Label.Set_Text(Icon_Characters);
    Icon_Label.Set_Style_Text_Font(&lv_font_montserrat_20, 0);
    Icon_Label.Add_Flag(Flag_Type::Event_Bubble);
    Icon_Label.Set_Alignment(Alignment_Type::Center);
    Icon_Label.Set_Style_Text_Color(Color_Type::White, 0);

    // - Color

    Byte_Type Color[3] = {0, 0, 0};

    for (uint8_t i = 0; i < Name.Get_Length(); i++)
        Color[i % 3] = ((Natural_Type)Color[i % 3] + (Natural_Type)Name.Get_Character(i)) % 255;

    if (((Icon_Characters[0] + Icon_Characters[1]) % 2) == 0)
        Icon_Container.Set_Style_Background_Color(Color_Type(Color[0], Color[1], Color[2]), 0);
    else
        Icon_Container.Set_Style_Background_Color(Color_Type(Color[2], Color[1], Color[0]), 0);
}

void Shell_Class::Clean_Softwares()
{
    using namespace Graphics_Types;

    uint8_t User_Softwares_Count = Softwares.Get_User_Softwares_Count(Get_Owner_User());

    for (uint8_t i = 0; i < User_Softwares_Count; i++)
    {
        // - Get software pointer
        const Softwares_Types::Software_Type* Software_Pointer = Softwares.Get_User_Softwares(Get_Owner_User(), i);

        bool Window_Found = false;

        uint8_t Screen_Children_Count = Screen.Get_Children_Count();
        
        // - Check if a window exist for a given software.
        for (uint8_t j = 0; j < Screen_Children_Count; j++)
        {
            Window_Type Child_Window = Window_Type(Screen.Get_Child(j));
            if (Child_Window && Child_Window.Get_Owner_Software() == Software_Pointer)
            {
                Window_Found = true;
                break;
            }
        }

        // - If no window found for a given software, close it.
        if (!Window_Found)
        {
            Softwares.Close(const_cast<Softwares_Types::Software_Type*>(Software_Pointer));
            // TODO : Add wait time and then kill the software.

        }
        
    }
}