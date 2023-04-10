///
/// @file Preferences.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 24-02-2023
///
/// @copyright Copyright (c) 2023
///

#ifndef Preferences_Hpp_Included
#define Preferences_Hpp_Included

#include "Xila.hpp"

using namespace Xila;

class Preferences_Class : public Software_Type
{

    // - Methods

    // - - Constructors / destructor

    Preferences_Class(const Accounts_Types::User_Type *Owner_User);
    ~Preferences_Class();

    // - - Management

    void Main_Task_Function() override;
    void Execute_Instruction(Instruction_Type Instruction);

    void Draw_Personal();
    void Draw_Softwares();
    void Draw_Wireless();
    void Draw_Users();
    void Draw_Hardware();
    void Draw_System();

    void Refresh_Personal();
    void Refresh_Softwares();
    void Refresh_Wireless();
    void Refresh_Users();
    void Refresh_Hardware();
    void Refresh_System();

    void Execute_Personal_Instruction(const Instruction_Type &Instruction);
    void Execute_Softwares_Instruction(const Instruction_Type &Instruction);
    void Execute_Wireless_Instruction(const Instruction_Type &Instruction);
    void Execute_Users_Instruction(const Instruction_Type &Instruction);
    void Execute_Hardware_Instruction(const Instruction_Type &Instruction);
    void Execute_System_Instruction(const Instruction_Type &Instruction);

    // - Attributes

    Graphics_Types::Window_Type Window;
    Tabs_Type Tabs;
    Object_Type Personnal_Tab, Softwares_Tab, Hardware_Tab, Network_Tab, Users_Tab, System_Tab;

    Graphics_Types::Keyboard_Type Keyboard;

    // - - Personnal

    Button_Type Personnal_Style_Apply_Button;
    Button_Type Personnal_Style_Background_Button;
    Button_Type Personnal_Style_Foreground_Button;

    // - - Wireless

    Switch_Type Wireless_WiFi_Switch;
    Button_Type Wireless_WiFi_Refresh_Button;
    Button_Type Wireless_WiFi_Informations_Button;
    Button_Type Wireless_WiFi_Connect_Button;
    Roller_Type Wireless_WiFi_Access_Point_Roller;
    Graphics_Types::Text_Area_Type Wireless_WiFi_Password_Text_Area;

    Button_Type Wireless_Network_Apply_Button;
    Graphics_Types::Checkbox_Type Wireless_Network_DHCP_Checkbox;
    Graphics_Types::Text_Area_Type Wireless_Network_Local_IP_Text_Area;
    Graphics_Types::Text_Area_Type Wireless_Network_Gateway_IP_Text_Area;
    Graphics_Types::Text_Area_Type Wireless_Network_Subnet_Mask_Text_Area;
    Graphics_Types::Text_Area_Type Wireless_Network_DNS_1_Text_Area;
    Graphics_Types::Text_Area_Type Wireless_Network_DNS_2_Text_Area;

    // - - Users
    Button_Type Users_Apply_Button;
    Button_Type Users_Delete_Your_Account_Button;
    Button_Type Users_Delete_User_Button;
    Button_Type Users_Add_User_Button;

    Roller_Type Users_Roller;

    Graphics_Types::Text_Area_Type Users_Add_User_Name_Text_Area;
    Graphics_Types::Text_Area_Type Users_Add_User_Password_Text_Area;

    Graphics_Types::Text_Area_Type Users_Your_Account_Password_Text_Area;
    Graphics_Types::Text_Area_Type Users_Your_Account_New_Name_Text_Area;
    Graphics_Types::Text_Area_Type Users_Your_Account_New_Password_Text_Area;
    Graphics_Types::Text_Area_Type Users_Your_Account_New_Password_Confirmation_Text_Area;

    // - - Hardware

    Button_Type Hardware_Display_Calibrate_Button;
    Slider_Type Hardware_Display_Brightness_Slider;
    Slider_Type Hardware_Sound_Volume_Slider;
    Graphics_Types::Label_Type Hardware_Battery_Level_Label;
    Graphics_Types::Label_Type Hardware_Drive_Informations_Label;
    Roller_Type Hardware_Energy_Standby_Roller;
    Button_Type Hardware_Energy_Apply_Button;

    // - - Softwares

    Roller_Type Softwares_Roller;
    Button_Type Softwares_Delete_Button;

    // - - System

    Button_Type System_Device_Apply_Button;
    Graphics_Types::Text_Area_Type System_Device_Name_Text_Area;
    Button_Type System_Update_Button;
    Button_Type System_Reboot_Loader_Button;

    Button_Type System_Time_Apply_Button;
    Button_Type System_Time_Plus_Button;
    Button_Type System_Time_Minus_Button;
    Spinbox_Type System_Time_Daylight_Offset_Spinbox;
    Graphics_Types::Text_Area_Type System_Time_NTP_Server_Text_Area;
    Roller_Type System_Time_Zone_Roller;

    friend class Preferences_Handle_Class;
};

// - Types

static class Preferences_Handle_Class : public Software_Handle_Type
{
public:
    Preferences_Handle_Class() : Software_Handle_Type("Preferences"){};

    void Create_Instance(const Accounts_Types::User_Type* Owner_User) const override
    {
        new Preferences_Class(Owner_User);
    };
} Preferences_Handle;

#endif