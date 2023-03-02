///
/// @file Preferences.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 29-06-2021
///
/// @copyright Copyright (c) 2021
///

#include "Software/Preferences/Preferences.hpp"

const Coordinate_Type Column_Descriptor[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
const Coordinate_Type Row_Descriptor[] = {40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, LV_GRID_TEMPLATE_LAST};

// -- Constructor -- //

Preferences_Class::Preferences_Class(const Accounts_Types::User_Type* Owner) : Software_Class(&Handle, Owner)
{
    Window.Create(this);
    Window.Set_Title("Preferences");

    Tabs.Create(Window.Get_Body(), Direction_Type::Left, 80);
    Tabs.Set_Style_Background_Opacity(Opacity_Type::Opacity_0_Percent, 0);
    Tabs.Add_Event(this, Graphics_Types::Event_Code_Type::Value_Changed);

    {
        Object_Class Tab_Buttons = Tabs.Get_Tab_Buttons();
        Tab_Buttons.Set_Style_Background_Color(Color_Type::Grey[2], 0);
        Tab_Buttons.Set_Style_Text_Color(Color_Type::White, 0);
        Tab_Buttons.Set_Style_Border_Side(Border_Side_Type::Right, Part_Type::Items | Graphics_Types::State_Type::Checked);
        Tab_Buttons.Set_Style_Border_Color(Color_Type::White, Part_Type::Items | Graphics_Types::State_Type::Checked);
        Tab_Buttons.Set_Style_Text_Color(Color_Type::White, Part_Type::Items | Graphics_Types::State_Type::Checked);
    }

    Personnal_Tab = Tabs.Add_Tab("Personnal");
    Softwares_Tab = Tabs.Add_Tab("Softwares");
    Network_Tab = Tabs.Add_Tab("Wireless");
    Users_Tab = Tabs.Add_Tab("Users");
    Hardware_Tab = Tabs.Add_Tab("Hardware");
    System_Tab = Tabs.Add_Tab("System");

    Draw_Personal();
    Draw_Softwares();
    Draw_Hardware();
    Draw_Wireless();
    Draw_Users();
    Draw_System();
}

Preferences_Class::~Preferences_Class()
{
    Window.Delete();
    Main_Task.Delete();
}

void Preferences_Class::Main_Task_Function()
{

    while (true)
    {
        if (this->Instruction_Available())
        {
            this->Execute_Instruction(this->Get_Instruction());
        }
        else
        {
            this->Main_Task.Delay(40);
        }
    }
}

void Preferences_Class::Draw_Wireless()
{

    Network_Tab.Set_Flex_Flow(Flex_Flow_Type::Row);
    Network_Tab.Set_Style_Pad_All(0, 0);

    // - Grid layout
    Object_Type Grid;
    Grid.Create(Network_Tab);
    Grid.Set_Size(Percentage(100), Percentage(100));
    Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Grid.Set_Grid_Descriptor_Array(Column_Descriptor, Row_Descriptor);
    Grid.Set_Style_Pad_All(10, 0);

    const uint8_t WiFi_Section_Row = 0;

    {
        Label_Type Label;
        Label.Create(Grid);
        Label.Set_Text("WiFi station");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, WiFi_Section_Row, 1);
        Label.Clear_Pointer();

        // - WiFi switch
        Wireless_WiFi_Switch.Create(Grid);
        Wireless_WiFi_Switch.Set_Grid_Cell(Grid_Alignment_Type::Center, 6, 2, Grid_Alignment_Type::Center, WiFi_Section_Row, 1);
        Wireless_WiFi_Switch.Add_Event(this, Graphics_Types::Event_Code_Type::Value_Changed);

        // - Access point roller
        Wireless_WiFi_Access_Point_Roller.Create(Grid);
        Wireless_WiFi_Access_Point_Roller.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Stretch, WiFi_Section_Row + 1, 1);

        // - Refresh button

        Wireless_WiFi_Refresh_Button.Create(Grid);
        Wireless_WiFi_Refresh_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, WiFi_Section_Row + 1, 1);
        Wireless_WiFi_Refresh_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);

        Label.Create(Wireless_WiFi_Refresh_Button);
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Set_Text("Refresh");
        Label.Clear_Pointer();

        // - Informations button

        Wireless_WiFi_Informations_Button.Create(Grid);
        Wireless_WiFi_Informations_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, WiFi_Section_Row + 2, 1);
        Wireless_WiFi_Informations_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);

        Label.Create(Wireless_WiFi_Informations_Button);
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Set_Text("Informations");
        Label.Clear_Pointer();

        // - Connect button

        Wireless_WiFi_Connect_Button.Create(Grid);
        Wireless_WiFi_Connect_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, WiFi_Section_Row + 3, 1);
        Wireless_WiFi_Connect_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);

        Label.Create(Wireless_WiFi_Connect_Button);
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Set_Text("Connect");
        Label.Clear_Pointer();

        // - Password text area

        Wireless_WiFi_Password_Text_Area.Create(Grid);
        Wireless_WiFi_Password_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Stretch, WiFi_Section_Row + 4, 1);
        Wireless_WiFi_Password_Text_Area.Set_Password_Mode(true);
        Wireless_WiFi_Password_Text_Area.Set_Placeholder_Text("Password");
        Wireless_WiFi_Password_Text_Area.Set_One_Line(true);
    }

    const uint8_t Network_Section_Row = WiFi_Section_Row + 5;

    {
        // - Title label

        Label_Type Label;
        Label.Create(Grid);
        Label.Set_Text("Network");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Network_Section_Row, 1);
        Label.Clear_Pointer();

        // - Apply button

        Wireless_Network_Apply_Button.Create(Grid);
        Wireless_Network_Apply_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, Network_Section_Row, 1);

        Label.Create(Wireless_Network_Apply_Button);
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Set_Text("Apply");
        Label.Clear_Pointer();

        // - Local IP

        Wireless_Network_Local_IP_Text_Area.Create(Grid);
        Wireless_Network_Local_IP_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Stretch, Network_Section_Row + 1, 1);
        Wireless_Network_Local_IP_Text_Area.Set_Placeholder_Text("Local IP");
        Wireless_Network_Local_IP_Text_Area.Set_One_Line(true);

        // - DHCP checkbox

        Wireless_Network_DHCP_Checkbox.Create(Grid);
        Wireless_Network_DHCP_Checkbox.Set_Grid_Cell(Grid_Alignment_Type::Center, 6, 2, Grid_Alignment_Type::Center, Network_Section_Row + 1, 1);
        Wireless_Network_DHCP_Checkbox.Set_Text("DHCP");

        // - Subnet mask

        Wireless_Network_Subnet_Mask_Text_Area.Create(Grid);
        Wireless_Network_Subnet_Mask_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Stretch, Network_Section_Row + 2, 1);
        Wireless_Network_Subnet_Mask_Text_Area.Set_Placeholder_Text("Subnet mask");
        Wireless_Network_Subnet_Mask_Text_Area.Set_One_Line(true);

        // - Gateway

        Wireless_Network_Gateway_IP_Text_Area.Create(Grid);
        Wireless_Network_Gateway_IP_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Stretch, Network_Section_Row + 3, 1);
        Wireless_Network_Gateway_IP_Text_Area.Set_Placeholder_Text("Gateway");
        Wireless_Network_Gateway_IP_Text_Area.Set_One_Line(true);

        // - DNS 1

        Wireless_Network_DNS_1_Text_Area.Create(Grid);
        Wireless_Network_DNS_1_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Stretch, Network_Section_Row + 4, 1);
        Wireless_Network_DNS_1_Text_Area.Set_Placeholder_Text("DNS 1");
        Wireless_Network_DNS_1_Text_Area.Set_One_Line(true);

        // - DNS 2

        Wireless_Network_DNS_2_Text_Area.Create(Grid);
        Wireless_Network_DNS_2_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Stretch, Network_Section_Row + 5, 1);
        Wireless_Network_DNS_2_Text_Area.Set_Placeholder_Text("DNS 2");
        Wireless_Network_DNS_2_Text_Area.Set_One_Line(true);
    }
}

void Preferences_Class::Draw_Hardware()
{
    Hardware_Tab.Set_Flex_Flow(Flex_Flow_Type::Row);
    Hardware_Tab.Set_Style_Pad_All(0, 0);

    // - Grid layout
    Object_Type Grid;
    Grid.Create(Hardware_Tab);
    Grid.Set_Size(Percentage(100), Percentage(100));
    Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Grid.Set_Grid_Descriptor_Array(Column_Descriptor, Row_Descriptor);
    Grid.Set_Style_Pad_All(10, 0);

    const uint8_t Display_Section_Row = 0;

    {
        Label_Type Label;
        Label.Create(Grid);
        Label.Set_Text("Display");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Display_Section_Row, 1);
        Label.Clear_Pointer();

        Label.Create(Grid);
        Label.Set_Text("Brightness :");
        Label.Set_Grid_Cell(Grid_Alignment_Type::End, 0, 2, Grid_Alignment_Type::Center, Display_Section_Row + 1, 1);
        Label.Clear_Pointer();

        Hardware_Display_Brightness_Slider.Create(Grid);
        Hardware_Display_Brightness_Slider.Set_Grid_Cell(Grid_Alignment_Type::Center, 2, 4, Grid_Alignment_Type::Center, Display_Section_Row + 1, 1);
        Hardware_Display_Brightness_Slider.Set_Range(0, 100);
        Hardware_Display_Brightness_Slider.Add_Event(this, Graphics_Types::Event_Code_Type::Value_Changed);

        Hardware_Display_Calibrate_Button.Create(Grid);
        Hardware_Display_Calibrate_Button.Set_Grid_Cell(Grid_Alignment_Type::Center, 6, 2, Grid_Alignment_Type::Center, Display_Section_Row + 1, 1);
        Hardware_Display_Calibrate_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);

        Label.Create(Hardware_Display_Calibrate_Button);
        Label.Set_Text("Calibrate");
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Clear_Pointer();
    }

    const uint8_t Sound_Section_Row = Display_Section_Row + 2;

    {
        Label_Type Label;
        Label.Create(Grid);
        Label.Set_Text("Sound");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Sound_Section_Row, 1);
        Label.Clear_Pointer();

        Label.Create(Grid);
        Label.Set_Text("Volume :");
        Label.Set_Grid_Cell(Grid_Alignment_Type::End, 0, 2, Grid_Alignment_Type::Center, Sound_Section_Row + 1, 1);
        Label.Clear_Pointer();

        Hardware_Sound_Volume_Slider.Create(Grid);
        Hardware_Sound_Volume_Slider.Set_Grid_Cell(Grid_Alignment_Type::Center, 2, 6, Grid_Alignment_Type::Center, Sound_Section_Row + 1, 1);
        Hardware_Sound_Volume_Slider.Set_Range(0, 100);
    }

    const uint8_t Battery_Section_Row = Sound_Section_Row + 2;

    {
        Label_Type Label;
        Label.Create(Grid);
        Label.Set_Text("Battery");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Battery_Section_Row, 1);
        Label.Clear_Pointer();

        Label.Create(Grid);
        Label.Set_Text("Level :");
        Label.Set_Grid_Cell(Grid_Alignment_Type::End, 0, 2, Grid_Alignment_Type::Center, Battery_Section_Row + 1, 1);
        Label.Clear_Pointer();

        Hardware_Battery_Level_Label.Create(Grid);
        Hardware_Battery_Level_Label.Set_Grid_Cell(Grid_Alignment_Type::Start, 2, 6, Grid_Alignment_Type::Center, Battery_Section_Row + 1, 1);
    }

    const uint8_t Drive_Section_Row = Battery_Section_Row + 2;

    {
        Label_Type Label;
        Label.Create(Grid);
        Label.Set_Text("Drive");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Drive_Section_Row, 1);
        Label.Clear_Pointer();

        Hardware_Drive_Informations_Label.Create(Grid);
        Hardware_Drive_Informations_Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Drive_Section_Row + 1, 1);
    }

    const uint8_t Energy_Section_Row = Drive_Section_Row + 2;

    {
        Label_Type Label;
        Label.Create(Grid);
        Label.Set_Text("Energy");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Energy_Section_Row, 1);
        Label.Clear_Pointer();

        Hardware_Energy_Apply_Button.Create(Grid);
        Hardware_Energy_Apply_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, Energy_Section_Row, 1);
        Hardware_Energy_Apply_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);

        Label.Create(Hardware_Energy_Apply_Button);
        Label.Set_Text("Apply");
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Clear_Pointer();

        // - - - Standby label

        Label.Create(Grid);
        Label.Set_Text("Standby :");
        Label.Set_Grid_Cell(Grid_Alignment_Type::End, 0, 2, Grid_Alignment_Type::Center, Energy_Section_Row + 1, 2);
        Label.Clear_Pointer();

        // - - - Standby roller

        Hardware_Energy_Standby_Roller.Create(Grid);
        Hardware_Energy_Standby_Roller.Set_Grid_Cell(Grid_Alignment_Type::Center, 2, 4, Grid_Alignment_Type::Center, Energy_Section_Row + 1, 2);
        Hardware_Energy_Standby_Roller.Set_Options("30 seconds\n1 minute\n2 minutes\n3 mintes\n4 minutes\n5 minutes\n10 minutes\n20 minutes\nNever", Roller_Type::Mode_Type::Normal);
    }
}

void Preferences_Class::Draw_Softwares()
{
    Softwares_Tab.Set_Flex_Flow(Flex_Flow_Type::Row);
    Softwares_Tab.Set_Style_Pad_All(0, 0);

    // - Grid layout

    Object_Type Grid;
    Grid.Create(Softwares_Tab);
    Grid.Set_Size(Percentage(100), Percentage(100));
    Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Grid.Set_Grid_Descriptor_Array(Column_Descriptor, Row_Descriptor);
    Grid.Set_Style_Pad_All(10, 0);

    // - - Software section

    const uint8_t Software_Section_Row = 0;

    {
        // - - - Software title label
        {
            Label_Type Label;
            Label.Create(Grid);
            Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Software_Section_Row, 1);
        }
        // - - - Softwares roller

        Softwares_Roller.Create(Grid);
        Softwares_Roller.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Center, Software_Section_Row + 1, 1);

        // - - - Delete button

        Softwares_Delete_Button.Create(Grid);
        Softwares_Delete_Button.Set_Grid_Cell(Grid_Alignment_Type::Center, 6, 2, Grid_Alignment_Type::Center, Software_Section_Row + 1, 1);
     
        {
            Label_Type Label;
            Label.Create(Softwares_Delete_Button);
            Label.Set_Text("Delete");
            Label.Set_Alignment(Alignment_Type::Center);
        }
    }

    Refresh_Softwares();
}

void Preferences_Class::Draw_Personal()
{
    Personnal_Tab.Set_Flex_Flow(Flex_Flow_Type::Row);
    Personnal_Tab.Set_Style_Pad_All(0, 0);

    // - Grid layout

    Object_Type Grid;
    Grid.Create(Personnal_Tab);
    Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Grid.Set_Grid_Descriptor_Array(Column_Descriptor, Row_Descriptor);
    Grid.Set_Style_Pad_All(10, 0);

    // - - Style section

    const uint8_t Style_Section_Row = 0;

    {
        // - - - Style title label

        Label_Type Label;
        Label.Create(Grid);
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Style_Section_Row, 1);
        Label.Set_Text("Style");
        Label.Clear_Pointer();

        Personnal_Style_Apply_Button.Create(Grid);
        Personnal_Style_Apply_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, Style_Section_Row, 1);

        Label.Create(Personnal_Style_Apply_Button);
        Label.Set_Text("Apply");
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Clear_Pointer();

        // - - - Color

        Label.Create(Grid);
        Label.Set_Text("Foreground :");
        Label.Set_Grid_Cell(Grid_Alignment_Type::End, 0, 3, Grid_Alignment_Type::Center, Style_Section_Row + 1, 1);
        Label.Clear_Pointer();

        Personnal_Style_Background_Button.Create(Grid);
        Personnal_Style_Background_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 3, 2, Grid_Alignment_Type::Stretch, Style_Section_Row + 1, 1);

        // - - - Background

        Label.Create(Grid);
        Label.Set_Text("Background :");
        Label.Set_Grid_Cell(Grid_Alignment_Type::End, 0, 3, Grid_Alignment_Type::Center, Style_Section_Row + 2, 1);
        Label.Clear_Pointer();

        Personnal_Style_Foreground_Button.Create(Grid);
        Personnal_Style_Foreground_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 3, 2, Grid_Alignment_Type::Stretch, Style_Section_Row + 2, 1);
    }

    Refresh_Personal();
}

void Preferences_Class::Draw_System()
{
    System_Tab.Set_Flex_Flow(Flex_Flow_Type::Row);
    System_Tab.Set_Style_Pad_All(0, 0);

    // - Grid layout

    Object_Type Grid;
    Grid.Create(System_Tab);
    Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Grid.Set_Grid_Descriptor_Array(Column_Descriptor, Row_Descriptor);
    Grid.Set_Style_Pad_All(10, 0);

    // - - Device section

    const uint8_t Device_Section_Row = 0;

    {
        // - - - Device title label

        Label_Type Label;
        Label.Create(Grid),
            Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Device_Section_Row, 1);
        Label.Set_Text("Device");
        Label.Clear_Pointer();

        // - - - Apply button

        System_Device_Apply_Button.Create(Grid);
        System_Device_Apply_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, Device_Section_Row, 1);
        System_Device_Apply_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);

        Label.Create(System_Device_Apply_Button);
        Label.Set_Text("Apply");
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Clear_Pointer();

        // - - - Device name text area

        System_Device_Name_Text_Area.Create(Grid);
        System_Device_Name_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Stretch, Device_Section_Row + 1, 1);
        System_Device_Name_Text_Area.Set_Placeholder_Text("Device name");
        System_Device_Name_Text_Area.Set_One_Line(true);

        // - - - System update button

        System_Update_Button.Create(Grid);
        System_Update_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 4, Grid_Alignment_Type::Stretch, Device_Section_Row + 2, 1);
        System_Update_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);

        Label.Create(System_Update_Button);
        Label.Set_Text("Update system");
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Clear_Pointer();

        // - - - System reboot to loader button

        System_Reboot_Loader_Button.Create(Grid);
        System_Reboot_Loader_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 4, 4, Grid_Alignment_Type::Stretch, Device_Section_Row + 2, 1);
        System_Reboot_Loader_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);

        Label.Create(System_Reboot_Loader_Button);
        Label.Set_Text("Reboot to loader");
        Label.Set_Alignment(Alignment_Type::Center);
    }

    // - - Time section

    const uint8_t Time_Section_Row = Device_Section_Row + 3;

    {
        // - - - Time title label

        Label_Type Label;
        Label.Create(Grid);
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Time_Section_Row, 1);
        Label.Set_Text("Time");
        Label.Clear_Pointer();

        // - - - Apply time button

        System_Time_Apply_Button.Create(Grid);
        System_Time_Apply_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, Time_Section_Row, 1);
        System_Time_Apply_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);

        Label.Create(System_Time_Apply_Button);
        Label.Set_Text("Apply");
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Clear_Pointer();

        // - - - NTP server text area

        System_Time_NTP_Server_Text_Area.Create(Grid);
        System_Time_NTP_Server_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 1, 6, Grid_Alignment_Type::Stretch, Time_Section_Row + 1, 1);
        System_Time_NTP_Server_Text_Area.Set_Placeholder_Text("N.T.P. server");
        System_Time_NTP_Server_Text_Area.Set_One_Line(true);

        // - - - UTC offset roller

        System_Time_Zone_Roller.Create(Grid);
        System_Time_Zone_Roller.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 2, 4, Grid_Alignment_Type::Stretch, Time_Section_Row + 2, 2);
        Static_String_Type<512> Options;
        Static_String_Type<12> Option;

        for (uint8_t i = -12; i <= 12; i++)
        {
            Option.Copy_Format("UTC %s%02u:00\n", i < 0 ? "-" : "+", i < 0 ? -i : i);
            Options += Option;

            if ((i == -4) || (i == -3) || (i == 3) || (i == 4) || (i == 5) || (i == 6) || (i == 9))
            {
                Options.Copy_Format("UTC %s%02u:30\n", i < 0 ? "-" : "+", i < 0 ? -i : i);
                Options += Option;
            }
        }
        System_Time_Zone_Roller.Set_Options(Options, Roller_Type::Mode_Type::Normal);
        System_Time_Zone_Roller.Set_Visible_Row_Count(3);

        // - - - UTC offset label

        Label.Create(Grid);
        Label.Set_Grid_Cell(Grid_Alignment_Type::End, 0, 3, Grid_Alignment_Type::Stretch, Time_Section_Row + 3, 1);
        Label.Set_Text("Daylight offset :");
        Label.Clear_Pointer();

        // - - - Minus button

        System_Time_Minus_Button.Create(Grid);
        System_Time_Minus_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 3, 1, Grid_Alignment_Type::Stretch, Time_Section_Row + 3, 1);
        System_Time_Minus_Button.Add_Event(this, Graphics_Types::Event_Code_Type::All);

        Label.Create(System_Time_Minus_Button);
        Label.Set_Text(LV_SYMBOL_MINUS);
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Clear_Pointer();

        // - - - UTC offset spinbox

        System_Time_Daylight_Offset_Spinbox.Create(Grid);
        System_Time_Daylight_Offset_Spinbox.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 3, 1, Grid_Alignment_Type::Stretch, Time_Section_Row + 3, 1);
        System_Time_Daylight_Offset_Spinbox.Set_Digit_Format(4, 0);

        // - - - Plus button

        System_Time_Plus_Button.Create(Grid);
        System_Time_Plus_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 3, 1, Grid_Alignment_Type::Stretch, Time_Section_Row + 3, 1);
        System_Time_Plus_Button.Add_Event(this, Graphics_Types::Event_Code_Type::All);

        Label.Create(System_Time_Plus_Button);
        Label.Set_Text(LV_SYMBOL_PLUS);
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Clear_Pointer();
    }

    // - - About section

    const uint8_t About_Section_Row = Time_Section_Row + 4;

    {
        // - - - About title label

        Label_Type Label;
        Label.Create(Grid);
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, About_Section_Row, 1);
        Label.Set_Text("About");
        Label.Clear_Pointer();

        // - - - Author label

        Label.Create(Grid);
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, About_Section_Row + 1, 1);
        Label.Set_Text_Format("Author : Alix ANNERAUD");
        Label.Clear_Pointer();

        // - - - About version

        Label.Create(Grid);
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, About_Section_Row + 2, 1);
        Label.Set_Text("Version : " Stringizing(Xila_Version_Major) "." Stringizing(Xila_Version_Minor) "." Stringizing(Xila_Version_Revision));
        Label.Clear_Pointer();
    }
}

// --

void Preferences_Class::Execute_Instruction(Instruction_Type Instruction)
{
    if (Instruction.Get_Sender() == &Softwares)
    {
        if (Instruction.Softwares.Get_Code() == Softwares_Types::Event_Code_Type::Close)
        {
            delete this;
            return;
        }
    }
    else if (Instruction.Get_Sender() == &Graphics)
    {
        if (Instruction.Graphics.Get_Object() == Tabs)
        {
            if (Instruction.Graphics.Get_Code() == Graphics_Types::Event_Code_Type::Clicked)
            {
                switch (Tabs.Get_Tab_Active())
                {
                case 0:
                    Refresh_Personal();
                    break;
                case 1:
                    Refresh_Softwares();
                    break;
                case 2:
                    Refresh_Hardware();
                    break;
                case 3:
                    Refresh_Wireless();
                    break;
                case 4:
                    Refresh_Users();
                    break;
                case 5:
                    Refresh_System();
                    break;
                }
                return;
            }
        }
    }
    // -
    switch (Tabs.Get_Tab_Active())
    {
    case 0:
        Execute_Personal_Instruction(Instruction);
        break;
    case 1:
        Execute_Softwares_Instruction(Instruction);
        break;
    case 2:
        Execute_Hardware_Instruction(Instruction);
        break;
    case 3:
        Execute_Wireless_Instruction(Instruction);
        break;
    case 4:
        Execute_Users_Instruction(Instruction);
        break;
    case 5:
        Execute_System_Instruction(Instruction);
        break;
    }
}

void Preferences_Class::Execute_Personal_Instruction(const Instruction_Type &Instruction)
{
    if (Instruction.Graphics.Get_Object() == Personnal_Style_Apply_Button)
    {
        // TODO : Send instruction to Shell to change style.
        //Shell_Pointer->Desk.Set_Foreground_Color(Personnal_Style_Foreground_Button.Get_Style_Background_Color(Part_Type::Main));
        //Shell_Pointer->Desk.Set_Background_Color(Personnal_Style_Background_Button.Get_Style_Background_Color(Part_Type::Main));
    }
}

void Preferences_Class::Execute_Softwares_Instruction(const Instruction_Type &Instruction)
{
    if (Instruction.Graphics.Get_Object() == Softwares_Delete_Button)
    {
        // TODO
    }
}

void Preferences_Class::Execute_Wireless_Instruction(const Instruction_Type &Instruction)
{
    if (Instruction.Graphics.Get_Object() == Wireless_WiFi_Switch)
    {
        if (Wireless_WiFi_Switch.Has_State(Graphics_Types::State_Type::Checked))
        {
            // TODO
        }
        else
        {
            WiFi.Turn_Off();
        }
        Refresh_Wireless();
    }
    else if (Instruction.Graphics.Get_Object() == Wireless_WiFi_Refresh_Button)
    {
        Refresh_Wireless();
    }
    else if (Instruction.Graphics.Get_Object() == Wireless_WiFi_Informations_Button)
    {
        // TODO
    }
    else if (Instruction.Graphics.Get_Object() == Wireless_WiFi_Connect_Button)
    {
        Static_String_Type<32> SSID;
        Wireless_WiFi_Access_Point_Roller.Get_Selected_String(SSID);

        if (!WiFi.Station.Is_Known(SSID))
        {
            WiFi.Station.Add(SSID, Wireless_WiFi_Password_Text_Area.Get_Text());
        }
        
        WiFi.Station.Connect(SSID);
    }
}

void Preferences_Class::Execute_Hardware_Instruction(const Instruction_Type &Instruction)
{
    if (Instruction.Graphics.Get_Object() == Hardware_Display_Brightness_Slider)
    {
        Display.Set_Brightness(Hardware_Display_Brightness_Slider.Get_Value());
    }
    else if (Instruction.Graphics.Get_Object() == Hardware_Display_Calibrate_Button)
    {
        Display.Calibrate();
    }
    else if (Instruction.Graphics.Get_Object() == Hardware_Sound_Volume_Slider)
    {
        Sound.Set_Volume(Hardware_Sound_Volume_Slider.Get_Value());
    }
    else if (Instruction.Graphics.Get_Object() == Hardware_Energy_Apply_Button)
    {
        switch (Hardware_Energy_Standby_Roller.Get_Selected())
        {
        case 0:
            Display.Set_Standby_Time(30);
            break;
        case 1:
            Display.Set_Standby_Time(1 * 60);
            break;
        case 2:
            Display.Set_Standby_Time(2 * 60);
            break;
        case 3:
            Display.Set_Standby_Time(3 * 60);
            break;
        case 4:
            Display.Set_Standby_Time(4 * 60);
            break;
        case 5:
            Display.Set_Standby_Time(5 * 60);
            break;
        case 6:
            Display.Set_Standby_Time(10 * 60);
            break;
        case 7:
            Display.Set_Standby_Time(20 * 60);
            break;
        default:
            Display.Set_Standby_Time(0);
            break;
        }
    }
}

void Preferences_Class::Refresh_Personal()
{
    Personnal_Style_Foreground_Button.Set_Style_Background_Color(Shell_Pointer->Desk.Get_Foreground_Color(), 0);
    Personnal_Style_Background_Button.Set_Style_Background_Color(Shell_Pointer->Desk.Get_Background_Color(), 0);

    /*
    switch (Keyboard.Layout)
    {
    case Keyboard.American:
        Display.Set_Text(F("LAYOUT_TXT"), F("American"));
        break;
    case Keyboard.German:
        Display.Set_Text(F("LAYOUT_TXT"), F("German"));
        break;
    case Keyboard.French:
        Display.Set_Text(F("LAYOUT_TXT"), F("French"));
        break;
    case Keyboard.Spanish:
        Display.Set_Text(F("LAYOUT_TXT"), F("Spanish"));
        break;
    case Keyboard.Italian:
        Display.Set_Text(F("LAYOUT_TXT"), F("Italian"));
        break;
    case Keyboard.English:
        Display.Set_Text(F("LAYOUT_TXT"), F("English"));
        break;
    default:
        break;
    }*/
}

/// @brief Refresh software tab.
void Preferences_Class::Refresh_Softwares()
{
    char Software_Name[Softwares.Get_Handle_List().size() * (sizeof(Default_Software_Name_Length) + 1) + 1];
    memset(Software_Name, '\0', sizeof(Software_Name));
    Static_String_Type<Default_Software_Name_Length> Software_Name_String;
    for (auto & Software_Handle : Softwares.Get_Handle_List())
    {
        Software_Handle->Get_Name(Software_Name_String);
        strlcat(Software_Name, Software_Name_String, sizeof(Software_Name));
        strcat(Software_Name, "\n");
    }
    Softwares_Roller.Set_Options(Software_Name, Roller_Type::Mode_Type::Normal);
}

// -- Hardware -- //

void Preferences_Class::Refresh_Hardware()
{
    Hardware_Display_Brightness_Slider.Set_Value(Display.Get_Brightness(), false);
    Hardware_Sound_Volume_Slider.Set_Value(Sound.Get_Volume(), false);
    Hardware_Battery_Level_Label.Set_Text(Power.Get_Charge_Level() + " %");

    switch (Drive.Get_Type())
    {
    case Drive_Types::Drive_Type_Type::None:
        Hardware_Drive_Informations_Label.Set_Text_Format("Type : None - Size : %u", Drive.Get_Size());
        break;
    case Drive_Types::Drive_Type_Type::MMC:
        Hardware_Drive_Informations_Label.Set_Text_Format("Type : MMC - Size : %u", Drive.Get_Size());
        break;
    case Drive_Types::Drive_Type_Type::SD_SC:
        Hardware_Drive_Informations_Label.Set_Text_Format("Type : SD SC - Size : %u", Drive.Get_Size());
        break;
    case Drive_Types::Drive_Type_Type::SD_HC:
        Hardware_Drive_Informations_Label.Set_Text_Format("Type : SD HC - Size : %u", Drive.Get_Size());
        break;
    default:
        Hardware_Drive_Informations_Label.Set_Text_Format("Type : Unknown - Size : %u", Drive.Get_Size());
        break;
    }

    if ((Display.Get_Standby_Time() <= 30) && (Display.Get_Standby_Time() > 0))
        Hardware_Energy_Standby_Roller.Set_Selected(0, false);
    else if (Display.Get_Standby_Time() <= (1 * 60))
        Hardware_Energy_Standby_Roller.Set_Selected(1, false);
    else if (Display.Get_Standby_Time() <= (2 * 60))
        Hardware_Energy_Standby_Roller.Set_Selected(2, false);
    else if (Display.Get_Standby_Time() <= (3 * 60))
        Hardware_Energy_Standby_Roller.Set_Selected(3, false);
    else if (Display.Get_Standby_Time() <= (4 * 60))
        Hardware_Energy_Standby_Roller.Set_Selected(4, false);
    else if (Display.Get_Standby_Time() <= (5 * 60))
        Hardware_Energy_Standby_Roller.Set_Selected(5, false);
    else if (Display.Get_Standby_Time() <= (10 * 60))
        Hardware_Energy_Standby_Roller.Set_Selected(6, false);
    else if (Display.Get_Standby_Time() <= (20 * 60))
        Hardware_Energy_Standby_Roller.Set_Selected(7, false);
    else
        Hardware_Energy_Standby_Roller.Set_Selected(8, false);
}

// -- Network -- //

void Preferences_Class::Refresh_Wireless()
{
    using namespace Xila_Namespace::WiFi_Types;

    // - WiFi section

    {

        if (WiFi.Get_Mode() == Mode_Type::Station)
        {
            Wireless_WiFi_Switch.Add_State(Graphics_Types::State_Type::Checked);
            Wireless_WiFi_Access_Point_Roller.Clear_State(Graphics_Types::State_Type::Disabled);
            Wireless_WiFi_Refresh_Button.Clear_State(Graphics_Types::State_Type::Disabled);
            Wireless_WiFi_Informations_Button.Clear_State(Graphics_Types::State_Type::Disabled);
            Wireless_WiFi_Connect_Button.Clear_State(Graphics_Types::State_Type::Disabled);
            Wireless_WiFi_Password_Text_Area.Clear_State(Graphics_Types::State_Type::Disabled);

            Static_String_Type<32> Connected_SSID;

            if (WiFi.Station.Get_Status() == Status_Type::Connected)
            {
                WiFi.Station.Get_SSID(Connected_SSID);
            }

            uint16_t Access_Points_Number = WiFi.Scan.Start(false, true);

            char Networks_List[33 * (Access_Points_Number)];
            Static_String_Type<32> Temporary_SSID;

            memset(Networks_List, '\0', sizeof(Networks_List));

            for (uint8_t i = 0; i < Access_Points_Number; i++)
            {
                WiFi.Scan.Get_SSID(i, Temporary_SSID);
                strlcat(Networks_List, Temporary_SSID, sizeof(Networks_List));

                if (Temporary_SSID == Connected_SSID)
                {
                    strlcat(Networks_List, " (Connected)", sizeof(Networks_List[i]));
                }

                if (i < (Access_Points_Number - 1))
                {
                    strlcat(Networks_List, "\n", sizeof(Networks_List[i]));
                }
            }

            Wireless_WiFi_Access_Point_Roller.Set_Options(Networks_List, Roller_Class::Mode_Type::Normal);

            WiFi.Scan.Delete();
        }
        else
        {
            Wireless_WiFi_Switch.Clear_State(Graphics_Types::State_Type::Checked);
            Wireless_WiFi_Access_Point_Roller.Add_State(Graphics_Types::State_Type::Disabled);
            Wireless_WiFi_Refresh_Button.Add_State(Graphics_Types::State_Type::Disabled);
            Wireless_WiFi_Informations_Button.Add_State(Graphics_Types::State_Type::Disabled);
            Wireless_WiFi_Connect_Button.Add_State(Graphics_Types::State_Type::Disabled);
            Wireless_WiFi_Password_Text_Area.Add_State(Graphics_Types::State_Type::Disabled);
        }
    }

    // - Network section

    {
        Static_String_Type<24> IP_Address;
        WiFi.Station.Get_IP_Address().To(IP_Address);
        Wireless_Network_Local_IP_Text_Area.Set_Text(IP_Address);
        WiFi.Station.Get_Subnet_Mask().To(IP_Address);
        Wireless_Network_Subnet_Mask_Text_Area.Set_Text(IP_Address);
        WiFi.Station.Get_Gateway_IP_Address().To(IP_Address);
        Wireless_Network_Gateway_IP_Text_Area.Set_Text(IP_Address);
        WiFi.Station.Get_DNS_IP_Address(0).To(IP_Address);
        Wireless_Network_DNS_1_Text_Area.Set_Text(IP_Address);
        WiFi.Station.Get_DNS_IP_Address(1).To(IP_Address);
        Wireless_Network_DNS_2_Text_Area.Set_Text(IP_Address);
    }
}

// -- System -- //

void Preferences_Class::Execute_System_Instruction(const Instruction_Type &Instruction)
{
    if (Instruction.Graphics.Get_Object() == System_Device_Apply_Button)
    {
        if (Instruction.Graphics.Get_Code() == Graphics_Types::Event_Code_Type::Clicked)
        {
            Static_String_Type<32> Temporary_String = System_Device_Name_Text_Area.Get_Text();
            System.Set_Device_Name(Temporary_String);
        }
    }
    else if (Instruction.Graphics.Get_Object() == System_Time_Apply_Button)
    {
        if (Instruction.Graphics.Get_Code() == Graphics_Types::Event_Code_Type::Clicked)
        {
            Static_String_Type<32> Temporary_String = System_Time_NTP_Server_Text_Area.Get_Text();
            System.Set_NTP_Server(Temporary_String);
            // TODO : System.Set_Time_Zone(..);
        }
    }
    else if (Instruction.Graphics.Get_Object() == System_Time_Minus_Button)
    {
        if (Instruction.Graphics.Get_Code() == Graphics_Types::Event_Code_Type::Short_Clicked || Instruction.Graphics.Get_Code() == Graphics_Types::Event_Code_Type::Long_Pressed_Repeat)
        {
            System_Time_Daylight_Offset_Spinbox.Decrement();
        }
    }
    else if (Instruction.Graphics.Get_Object() == System_Time_Plus_Button)
    {
        if (Instruction.Graphics.Get_Code() == Graphics_Types::Event_Code_Type::Short_Clicked || Instruction.Graphics.Get_Code() == Graphics_Types::Event_Code_Type::Long_Pressed_Repeat)
        {
            System_Time_Daylight_Offset_Spinbox.Increment();
        }
    }
}

void Preferences_Class::Refresh_System()
{
    Static_String_Type<32> Temporary_String;
    System.Get_Device_Name(Temporary_String);
    System_Device_Name_Text_Area.Set_Text(Temporary_String);

    Temporary_String = "";
    System.Get_NTP_Server(Temporary_String);
    System_Time_NTP_Server_Text_Area.Set_Text(Temporary_String);

    Temporary_String = "";

    for (uint8_t i = -12; i <= 12; i++)
    {

        if ((i == -4) || (i == -3) || (i == 3) || (i == 4) || (i == 5) || (i == 6) || (i == 9))
        {
            if ((i * 60 * 60) >= (System.Get_UTC_Offset() - (30 * 60)))
            {
                System_Time_Zone_Roller.Set_Selected(i + 12, false);
                break;
            }
        }
        else
        {
            if ((i * 60 * 60) >= System.Get_UTC_Offset())
            {
                System_Time_Zone_Roller.Set_Selected(i + 12, false);
                break;
            }
        }
    }

    System_Time_Daylight_Offset_Spinbox.Set_Value(System.Get_Daylight_Offset());
}