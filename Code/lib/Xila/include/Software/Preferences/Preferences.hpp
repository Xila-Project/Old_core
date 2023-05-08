/// @file Preferences.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 24-02-2023
///
/// @copyright Copyright (c) 2023

#ifndef Preferences_Hpp_Included
#define Preferences_Hpp_Included

#include "Xila.hpp"

using namespace Xila;

class Preferences_Class : public Softwares_Types::Software_Type
{

    // - Methods

    // - - Constructors / destructor

    Preferences_Class(const Accounts_Types::User_Type *Owner_User);
    ~Preferences_Class();

    // - - Management

    void Set_Interface();

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
    Graphics_Types::Tabs_Type Tabs;
    Graphics_Types::Object_Type Personal_Tab, Softwares_Tab, Hardware_Tab, Network_Tab, Users_Tab, System_Tab;

    Graphics_Types::Keyboard_Type Keyboard;

    const Graphics_Types::Coordinate_Type Column_Descriptor[9] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    const Graphics_Types::Coordinate_Type Row_Descriptor[18] = {40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, LV_GRID_TEMPLATE_LAST};

    // - - Personal

    Graphics_Types::Switch_Type Personal_Dark_Mode_Switch;

    const Graphics_Types::Color_Type Personal_Primary_Colors[7] = {Graphics_Types::Color_Type::Blue[5], Graphics_Types::Color_Type::Green[5], Graphics_Types::Color_Type::Blue_Grey[5], Graphics_Types::Color_Type::Orange[5], Graphics_Types::Color_Type::Red[5], Graphics_Types::Color_Type::Purple[5], Graphics_Types::Color_Type::Teal[5]};
    const Graphics_Types::Color_Type Personal_Secondary_Colors[7] = {Graphics_Types::Color_Type::Teal[5], Graphics_Types::Color_Type::Yellow[5], Graphics_Types::Color_Type::Red[5], Graphics_Types::Color_Type::Blue_Grey[5], Graphics_Types::Color_Type::Deep_Purple[5], Graphics_Types::Color_Type::Blue[5], Graphics_Types::Color_Type::Lime[5]};

    // - - Wireless

    Graphics_Types::Switch_Type Wireless_WiFi_Switch;
    Graphics_Types::Button_Type Wireless_WiFi_Refresh_Button;
    Graphics_Types::Button_Type Wireless_WiFi_Informations_Button;
    Graphics_Types::Button_Type Wireless_WiFi_Connect_Button;
    Graphics_Types::Roller_Type Wireless_WiFi_Access_Point_Roller;
    Graphics_Types::Text_Area_Type Wireless_WiFi_Password_Text_Area;

    Graphics_Types::Button_Type Wireless_Network_Apply_Button;
    Graphics_Types::Checkbox_Type Wireless_Network_DHCP_Checkbox;
    Graphics_Types::Text_Area_Type Wireless_Network_Local_IP_Text_Area;
    Graphics_Types::Text_Area_Type Wireless_Network_Gateway_IP_Text_Area;
    Graphics_Types::Text_Area_Type Wireless_Network_Subnet_Mask_Text_Area;
    Graphics_Types::Text_Area_Type Wireless_Network_DNS_1_Text_Area;
    Graphics_Types::Text_Area_Type Wireless_Network_DNS_2_Text_Area;

    // - - Users
    Graphics_Types::Button_Type Users_Apply_Button;
    Graphics_Types::Button_Type Users_Delete_Your_Account_Button;
    Graphics_Types::Button_Type Users_Delete_User_Button;
    Graphics_Types::Button_Type Users_Add_User_Button;

    Graphics_Types::Roller_Type Users_Roller;

    Graphics_Types::Text_Area_Type Users_Add_User_Name_Text_Area;
    Graphics_Types::Text_Area_Type Users_Add_User_Password_Text_Area;

    Graphics_Types::Text_Area_Type Users_Your_Account_Password_Text_Area;
    Graphics_Types::Text_Area_Type Users_Your_Account_New_Name_Text_Area;
    Graphics_Types::Text_Area_Type Users_Your_Account_New_Password_Text_Area;
    Graphics_Types::Text_Area_Type Users_Your_Account_New_Password_Confirmation_Text_Area;

    // - - Hardware

    Graphics_Types::Button_Type Hardware_Display_Calibrate_Button;
    Graphics_Types::Slider_Type Hardware_Display_Brightness_Slider;
    Graphics_Types::Slider_Type Hardware_Sound_Volume_Slider;
    Graphics_Types::Label_Type Hardware_Battery_Level_Label;
    Graphics_Types::Label_Type Hardware_Drive_Informations_Label;
    Graphics_Types::Roller_Type Hardware_Energy_Standby_Roller;
    Graphics_Types::Button_Type Hardware_Energy_Apply_Button;

    // - - Softwares

    Graphics_Types::Roller_Type Softwares_Roller;
    Graphics_Types::Button_Type Softwares_Delete_Button;

    // - - System

    Graphics_Types::Button_Type System_Device_Apply_Button;
    Graphics_Types::Text_Area_Type System_Device_Name_Text_Area;
    Graphics_Types::Button_Type System_Update_Button;
    Graphics_Types::Button_Type System_Reboot_Loader_Button;

    Graphics_Types::Button_Type System_Time_Apply_Button;
    Graphics_Types::Button_Type System_Time_Plus_Button;
    Graphics_Types::Button_Type System_Time_Minus_Button;
    Graphics_Types::Spinbox_Type System_Time_Daylight_Offset_Spinbox;
    Graphics_Types::Text_Area_Type System_Time_NTP_Server_Text_Area;
    Graphics_Types::Roller_Type System_Time_Zone_Roller;

    friend class Preferences_Handle_Class;
};

// - Types

static class Preferences_Handle_Class : public Softwares_Types::Software_Handle_Type
{
public:
    Preferences_Handle_Class() : Softwares_Types::Software_Handle_Type("Preferences"){};

    void Create_Instance(const Accounts_Types::User_Type* Owner_User) const override
    {
        new Preferences_Class(Owner_User);
    };
} Preferences_Handle;

#endif