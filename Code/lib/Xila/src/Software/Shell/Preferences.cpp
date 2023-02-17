///
/// @file Preferences.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 29-06-2021
///
/// @copyright Copyright (c) 2021
///

#include "Software/Shell/Shell.hpp"
#include "Software/Shell/Translation.hpp"

const Coordinate_Type Column_Descriptor[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
const Coordinate_Type Row_Descriptor[] = {40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, LV_GRID_TEMPLATE_LAST};

// -- Constructor -- //

Shell_Class::Preferences_Class::Preferences_Class(Shell_Class *Shell_Pointer) : Shell_Pointer(Shell_Pointer)
{
    Window.Create();
    Window.Set_Title("Preferences");

    Tabs.Create(Window.Get_Body(), Direction_Type::Left, 80);
    Tabs.Set_Style_Background_Opacity(Opacity_Type::Opacity_0_Percent, 0);

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

    // -- Account
    Autologin = false;
    strlcpy(Username, Account.Get_Current_Username(), sizeof(Username));
    memset(Password_1, '\0', sizeof(Password_1));
    memset(Password_2, '\0', sizeof(Password_2));

    memset(Target_Username, '\0', sizeof(Username));
    memset(Name, '\0', sizeof(Name));
    strlcpy(Name, System.Get_Device_Name(), sizeof(Name));

    // -- Network
    strlcpy(WiFi_Name, WiFi.Get_SSID().c_str(), sizeof(WiFi_Name));
    memset(WiFi_Password, '\0', sizeof(WiFi_Password));

    Local_IP = WiFi.Get_IP_Address();
    Gateway_IP = WiFi.Get_Gateway_IP_Address();
    Subnet_Mask = WiFi.Get_Subnet_Mask();
    DNS[0] = WiFi.Get_DNS_IP_Address(0);
    DNS[1] = WiFi.Get_DNS_IP_Address(1);

    // -- Time
    memset(NTP_Server, '\0', sizeof(NTP_Server));
    strlcpy(NTP_Server, Time.NTP_Server, sizeof(NTP_Server));
    GMT_Offset = Time.GMT_Offset;
    Daylight_Offset = Time.Daylight_Offset;

    // -- Benchmark
    Write_Speed = 0;
    Read_Speed = 0;
}

void Shell_Class::Preferences_Class::Open(Shell_Class *Shell_Pointer)
{
    Shell_Pointer->Preferences_Pointer = new Preferences_Class(Shell_Pointer);
}

void Shell_Class::Preferences_Class::Close(Shell_Class *Shell_Pointer)
{
    delete Shell_Pointer->Preferences_Pointer;
    Shell_Pointer->Preferences_Pointer = NULL;
}

bool Shell_Class::Preferences_Class::Is_Openned(Shell_Class *Shell_Pointer)
{
    if (Shell_Pointer->Preferences_Pointer == NULL)
    {
        return false;
    }
    return true;
}

void Shell_Class::Preferences_Class::Draw_Wireless()
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
        Label.Set_Text("WiFi");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, WiFi_Section_Row, 1);
        Label.Clear_Pointer();
    
        // - Access point roller
        Wireless_WiFi_Access_Point_Roller.Create(Grid);
        Wireless_WiFi_Access_Point_Roller.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Stretch, WiFi_Section_Row + 1, 1);
        
        // - Refresh button

        Wireless_WiFi_Refresh_Button.Create(Grid);
        Wireless_WiFi_Refresh_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, WiFi_Section_Row + 1, 1);
        
        Label.Create(Wireless_WiFi_Refresh_Button);
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Set_Text("Refresh");
        Label.Clear_Pointer();

        // - Informations button

        Wireless_WiFi_Informations_Button.Create(Grid);
        Wireless_WiFi_Informations_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, WiFi_Section_Row + 2, 1);
    
        Label.Create(Wireless_WiFi_Informations_Button);
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Set_Text("Informations");
        Label.Clear_Pointer();

        // - Connect button

        Wireless_WiFi_Connect_Button.Create(Grid);
        Wireless_WiFi_Connect_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, WiFi_Section_Row + 3, 1);

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

void Shell_Class::Preferences_Class::Draw_Hardware()
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

        Hardware_Display_Calibrate_Button.Create(Grid);
        Hardware_Display_Calibrate_Button.Set_Grid_Cell(Grid_Alignment_Type::Center, 6, 2, Grid_Alignment_Type::Center, Display_Section_Row + 1, 1);

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

        Label.Create(Grid);
        switch (Drive.Get_Type())
        {
        case Drive_Types::Type_Type::None:
            Label.Set_Text("Type : None");
            break;
        case Drive_Types::Type_Type::MMC:
            Label.Set_Text("Type : MMC");
            break;
        case Drive_Types::Type_Type::SD_SC:
            Label.Set_Text("Type : SD SC");
            break;
        case Drive_Types::Type_Type::SD_HC:
            Label.Set_Text("Type : SD HC");
            break;
        default:
            Label.Set_Text("Type : Unknown");
            break;
        }

        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 4, Grid_Alignment_Type::Center, Drive_Section_Row + 1, 1);
        Label.Clear_Pointer();

        Label.Create(Grid);
        Label.Set_Text_Format("Size : %u", Drive.Get_Size());
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 4, 4, Grid_Alignment_Type::Center, Drive_Section_Row + 1, 1);
        Label.Clear_Pointer();
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

        Label.Create(Hardware_Energy_Apply_Button);
        Label.Set_Text("Apply");
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Clear_Pointer();

        // - - - Standby label

        Label.Create(Grid);
        Label.Set_Text("Standby :");
        Label.Set_Grid_Cell(Grid_Alignment_Type::End, 0, 2, Grid_Alignment_Type::Center, Energy_Section_Row + 1, 1);
        Label.Clear_Pointer();

        // - - - Standby roller

        Hardware_Energy_Standby_Roller.Create(Grid);
        Hardware_Energy_Standby_Roller.Set_Grid_Cell(Grid_Alignment_Type::Center, 2, 2, Grid_Alignment_Type::Center, Energy_Section_Row + 1, 1);
        Hardware_Energy_Standby_Roller.Set_Options("1 min\n2 min\n3 min\n5 min\n10 min\n15 min\n20 min\n25 min\n30 min\n45 min\n1 h\n2 h\n3 h\n4 h\n5 h\nNever", Roller_Type::Mode_Type::Normal);
    }
}

void Shell_Class::Preferences_Class::Draw_Softwares()
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
        Label_Type Label;
        Label.Create(Grid);
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Software_Section_Row, 1);

        // - - - Softwares roller

        Softwares_Roller.Create(Grid);
        Softwares_Roller.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Center, Software_Section_Row + 1, 1);

        // - - - Delete button

        Softwares_Delete_Button.Create(Grid);
        Softwares_Delete_Button.Set_Grid_Cell(Grid_Alignment_Type::Center, 6, 2, Grid_Alignment_Type::Center, Software_Section_Row + 1, 1);

        Label_Type Label;
        Label.Create(Softwares_Delete_Button);
        Label.Set_Text("Delete");
        Label.Set_Alignment(Alignment_Type::Center);
    }

    Refresh_Softwares();
}

void Shell_Class::Preferences_Class::Draw_Personal()
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

void Shell_Class::Preferences_Class::Draw_System()
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

        Label.Create(System_Update_Button);
        Label.Set_Text("Update system");
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Clear_Pointer();

        // - - - System reboot to loader button

        System_Reboot_Loader_Button.Create(Grid);
        System_Reboot_Loader_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 4, 4, Grid_Alignment_Type::Stretch, Device_Section_Row + 2, 1);

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

        Label.Create(System_Time_Apply_Button);
        Label.Set_Text("Apply");
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Clear_Pointer();

        // - - - NTP server text area

        System_NTP_Server_Text_Area.Create(Grid);
        System_NTP_Server_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 1, 6, Grid_Alignment_Type::Stretch, Time_Section_Row + 1, 1);
        System_NTP_Server_Text_Area.Set_Placeholder_Text("N.T.P. server");
        System_NTP_Server_Text_Area.Set_One_Line(true);

        // - - - UTC offset roller

        System_Time_Zone_Roller.Create(Grid);
        System_Time_Zone_Roller.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 1, 6, Grid_Alignment_Type::Stretch, Time_Section_Row + 2, 2);
        // TODO : Set time zone options
        // System_Time_Zone_Roller.Set_Options(Time_Zone_Options, );
        System_Time_Zone_Roller.Set_Selected(0, true);
        System_Time_Zone_Roller.Set_Visible_Row_Count(3);
    }

    // - - About section

    const uint8_t About_Section_Row = Time_Section_Row + 3;

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

// -- State management -- //

void Shell_Class::Preferences_Class::Open(uint8_t Mode)
{
    DUMP("open preferences");
    DUMP(Mode);
    if (!State())
    {
        PREFERENCES = new Preferences_Class();
    }
    switch (Mode)
    {
    case Pages.Preferences_Personal:
        Display.Set_Current_Page(Pages.Preferences_Personal);
        break;
    case Pages.Preferences_System:
        Display.Set_Current_Page(Pages.Preferences_System);
        break;
    case Pages.Preferences_Network:
        Display.Set_Current_Page(Pages.Preferences_Network);
        break;

    case Pages.Preferences_Hardware:
        Display.Set_Current_Page(Pages.Preferences_Hardware);
        break;
    case Pages.Preferences_Install:
        Display.Set_Current_Page(Pages.Preferences_Install);
        break;
    default:
        break;
    }
    SHELL->Send_Instruction('R', 'e');
}

bool Shell_Class::Preferences_Class::State()
{

    if (PREFERENCES == NULL)
    {
        return false;
    }
    return true;
}

void Shell_Class::Preferences_Class::Close()
{
    DUMP("close preferences");
    if (State())
    {
        delete PREFERENCES;
        PREFERENCES = NULL;
    }
}

// --

void Shell_Class::Preferences_Class::Execute_Instruction(Instruction_Type Instruction)
{
    if (Instruction.Get_Sender() == &Graphics)
    {
        switch (Instruction.Graphics.Get_Code())
        {
        case Graphics_Types::Event_Code_Type::Clicked:
            // - Personnal
            if (Instruction.Graphics.Get_Object() == Personnal_Style_Apply_Button)
            {
                Shell_Pointer->Desk.Set_Foreground_Color(Personnal_Style_Foreground_Button.Get_Style_Background_Color(Part_Type::Main));
                Shell_Pointer->Desk.Set_Background_Color(Personnal_Style_Background_Button.Get_Style_Background_Color(Part_Type::Main));
            }
            // - Softwares
            else if (Instruction.Graphics.Get_Object() == Softwares_Delete_Button)
            {
                // TODO
            }

            break;
        }
    }
}

void Shell_Class::Preferences_Class::Refresh_Personal()
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
void Shell_Class::Preferences_Class::Refresh_Softwares()
{
    char Software_Name[Software_Handle_Type::List.size() * sizeof(Software_Handle_Type::Name)];
    memset(Software_Name, '\0', sizeof(Software_Name));
    for (auto Software_Handle : Software_Handle_Type::List)
    {
        strlcat(Software_Name, Software_Handle->Get_Name(), sizeof(Software_Name));
        strcat(Software_Name, "\n");
    }
    Softwares_Roller.Set_Options(Software_Name, Roller_Type::Mode_Type::Normal);
}

// -- Hardware -- //

void Shell_Class::Preferences_Class::Refresh_Hardware()
{
    char Temporary_String[40];

    Display.Set_Value(F("BRIGHTNESS_SLI"), Display.Brightness);
    snprintf(Temporary_String, sizeof(Temporary_String), " Battery : %i %%", Power.Get_Charge_Level());
    Display.Set_Text(F("BATTERY_TXT"), Temporary_String);
    Display.Set_Value(F("VOLUME_SLI"), Sound.Get_Volume());
    Display.Set_Value(F("STANDBY_NUM"), Display.Standby_Time);

    switch (Drive.Type())
    {
    case Drive.None:
        snprintf(Temporary_String, sizeof(Temporary_String), " Drive : None | %i MB", (uint16_t)(Drive.Size() / (1024 * 1024)));
        break;
    case Drive.SD_SC:
        snprintf(Temporary_String, sizeof(Temporary_String), " Drive : SD SC | %i MB", (uint16_t)(Drive.Size() / (1024 * 1024)));
        break;
    case Drive.SD_HC:
        snprintf(Temporary_String, sizeof(Temporary_String), " Drive : SD HC | %i MB", (uint16_t)(Drive.Size() / (1024 * 1024)));
        break;
    case Drive.MMC:
        snprintf(Temporary_String, sizeof(Temporary_String), " Drive : SD MMC | %i MB", (uint16_t)(Drive.Size() / (1024 * 1024)));
        break;
    case Drive.Unknow:
        snprintf(Temporary_String, sizeof(Temporary_String), " Drive : Unknow | %i MB", (uint16_t)(Drive.Size() / (1024 * 1024)));
        break;
    }
    Display.Set_Text(F("DRIVE_TXT"), Temporary_String);

    sprintf(Temporary_String, " Speed: Read %i KB/s | Write %i KB/s", Read_Speed, Write_Speed);
    Display.Set_Text(F("SPEED_TXT"), Temporary_String);
}

void Shell_Class::Preferences_Class::Execute_Hardware_Instruction(Xila_Class::Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('C', 'l'):
        SHELL->Send_Instruction('O', 'D');
        Preferences_Class::Close();
        break;
    case Instruction('T', 'D'): // -- Drive testing
    {
        File_Type Test_File = Drive.Open(F(Test_Path), true);
        if (!Test_File)
        {
            DIALOG.Event(F("Failed to start the write test."), Error);

            SHELL->Send_Instruction('R', 'e');
            break;
        }
        SHELL->Set_Watchdog_Timeout(15000);
        static uint8_t Buffer[512] = {255};
        uint16_t i;
        double Time = Time.Milliseconds();

        for (i = 0; i < 2048; i++)
        {
            Task_Type::Delay_Static(1);
            Test_File.write(Buffer, sizeof(Buffer));
        }

        Time = Time.Milliseconds() - Time;
        Time /= 1000;               // convert time in sec
        Time = (2048 * 512) / Time; // divide quantity data copied by the time in sec
        Write_Speed = Time / 1000;
        Test_File.Close();
        Test_File = Drive.Open(F(Test_Path));
        SHELL->Set_Watchdog_Timeout();
        if (!Test_File)
        {
            DIALOG.Event(F("Failed to start the read test."), Error);
            SHELL->Send_Instruction('R', 'e');
            break;
        }

        SHELL->Set_Watchdog_Timeout(15000);
        size_t Length = Test_File.size();
        Time = Time.Milliseconds();
        while (Length)
        {
            if (Length > 512)
            {
                Test_File.read(Buffer, sizeof(Buffer));
                Length -= sizeof(Buffer);
            }
            else
            {
                Test_File.read(Buffer, Length);
                Length = 0;
            }
        }
        Time = Time.Milliseconds() - Time;
        Time /= 1000;
        Time = Test_File.size() / Time;
        Read_Speed = Time / 1000;
        Test_File.Close();
        Drive.Remove(F(Test_Path));
        SHELL->Set_Watchdog_Timeout();
        break;
    }
    case Instruction('V', '+'):
        if (Sound.Get_Volume() <= 243)
        {
            Sound.Set_Volume(Sound.Get_Volume() + 12);
            SHELL->Send_Instruction('R', 'e');
        }
        break;
    case Instruction('V', '-'):
        if (Sound.Get_Volume() >= 12)
        {
            Sound.Set_Volume(Sound.Get_Volume() - 12);
            Instance_Pointer->Send_Instruction('R', 'e');
        }
        break;
    case Instruction('S', '+'):
        Display.Standby_Time += 5;
        Display.Set_Standby_Touch_Timer(Display.Standby_Time);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('S', '-'):
        if (Display.Standby_Time >= 5)
        {
            Display.Standby_Time -= 5;
            Display.Set_Standby_Touch_Timer(Display.Standby_Time);
        }
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('D', 'S'):
        Display.Standby_Time = 0;
        Display.Set_Standby_Touch_Timer(Display.Standby_Time);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('R', 'e'):
        Refresh_Hardware();
        break;
    case Instruction('D', 'C'):
        Display.Calibrate();
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

// -- Network -- //

void Shell_Class::Preferences_Class::Refresh_Wireless()
{
    uint16_t Access_Points_Number = WiFi.Scan_Networks();
    
    char Networks_List[32 * (Access_Points_Number + 1)];
    for (uint8_t i = 0; i < Access_Points_Number; i++)
    {
        strcat(Networks_List, WiFi.Get_SSID(i));
        strcat(Networks_List, "\n");
    }
    strcat(Networks_List, "Hidden\0");
    Wireless_WiFi_Access_Point_Roller.Set_Options(Networks_List, Roller_Class::Mode_Type::Normal);

    if 


}

void Shell_Class::Preferences_Class::Execute_Network_Instruction(Xila_Class::Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('C', 'l'):
        SHELL->Send_Instruction('O', 'D');
        Preferences_Class::Close();
        break;
    case Instruction('K', 'W'):
        DIALOG.Keyboard(WiFi_Name, sizeof(WiFi_Name));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'w'):
        DIALOG.Keyboard(WiFi_Password, sizeof(WiFi_Password), true);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('W', 'D'):
        WiFi.disconnect();
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('W', 'C'):
        WiFi.Set_Credentials(WiFi_Name, WiFi_Password);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('R', 'e'):
        Refresh_Network();
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

// -- System -- //

void Shell_Class::Preferences_Class::Execute_System_Instruction(Xila_Class::Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('C', 'l'):
        SHELL->Send_Instruction('O', 'D');
        Preferences_Class::Close();
        break;
    // -- Device name
    case Instruction('K', 'N'):
        DIALOG.Keyboard(Name, sizeof(Name));
        Refresh_System();
        break;
    case Instruction('A', 'N'):
        strlcpy(System.Device_Name, Name, sizeof(System.Device_Name));
        System.Save_Registry();
        DIALOG.Event(F("Please restart Xila to apply changes."), Information);
        SHELL->Send_Instruction('R', 'e');
        break;
    // -- Time
    case Instruction('K', 'n'):
        DIALOG.Keyboard(NTP_Server, sizeof(NTP_Server));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('k', 'O'):
    {
        float Temporary_Float = GMT_Offset;
        DIALOG.Keypad(Temporary_Float);
        GMT_Offset = Temporary_Float;
        SHELL->Send_Instruction('R', 'e');
        break;
    }
    case Instruction('k', 'o'):
    {
        float Temporary_Float = Daylight_Offset;
        DIALOG.Keypad(Temporary_Float);
        Daylight_Offset = Temporary_Float;
        SHELL->Send_Instruction('R', 'e');
        break;
    }
    case Instruction('A', 'T'):
        Time.GMT_Offset = GMT_Offset;
        Time.Daylight_Offset = Daylight_Offset;
        strlcpy(Time.NTP_Server, NTP_Server, sizeof(Time.NTP_Server));
        Time.Save_Registry();
        DIALOG.Event(F("Please restart Xila to apply changes."), Information);
        SHELL->Send_Instruction('R', 'e');
        break;
    // -- Add user
    case Instruction('K', 'U'):
        DIALOG.Keyboard(Username, sizeof(Username));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('A', 'U'):
        if (Account.Add(Username, ""))
        {
            DIALOG.Event(F("Failed to add user."), Error);
        }
        else
        {
            DIALOG.Event(F("User successfully added."), Information);
        }
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('O', 'A'):
        Display.Set_Current_Page(Pages.About);
        break;
    case Instruction('U', 'p'):
        if (DIALOG.Event(F("Do you really want to update Xila ? That will make the system restart."), Warning) != Button_1)
        {
            SHELL->Send_Instruction('R', 'e');
            return;
        }
        if (!Drive.Exists(Display_Executable_Path) || !Drive.Exists(Microcontroller_Executable_Path))
        {
            DIALOG.Event(F("Missing update files."), Error);
            SHELL->Send_Instruction('R', 'e');
            return;
        }
        else
        {
            Display.Set_Current_Page(Pages.Dialog_Load);
            Display.Set_Text(F("MESSAGE_TXT"), F("Updating Xila"));
            Display.Set_Text(F("SUBHEADER_TXT"), F("Update"));

            File_Type Temporary_File = Drive.Open(Microcontroller_Executable_Path, true);
            if (System.Load_Executable(Temporary_File) != Success)
            {
                System.Restart();
                return;
            }

            Temporary_File = Drive.Open(Display_Executable_Path);
            if (Display.Update(Temporary_File) != Success)
            {
                System.Restart();
                return;
            }

            System.Restart();
        }
        break;
    case Instruction('R', 'e'): // -- Refresh
        Refresh_System();
        break;

    case Instruction('G', 'V'): // -- Current version (About)
        Display.Set_Text(F("VERSION_TXT"), ("Version : " Xila_Version_Major_String "." Xila_Version_Minor_String "." Xila_Version_Revision_String));
        break;

    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

void Shell_Class::Preferences_Class::Refresh_System()
{
    Display.Set_Text(F("NTPVAL_TXT"), NTP_Server);
    Display.Set_Value(F("GMTOFFSET_NUM"), GMT_Offset);
    Display.Set_Value(F("DAYLIGHTO_NUM"), Daylight_Offset);

    Display.Set_Text(F("DEVICEVAL_TXT"), Name);
    Display.Set_Text(F("USERVAL_TXT"), Username);
}

void Shell_Class::Preferences_Class::Refresh_Install()
{
    if (DESK.Background < 0)
    {
        Display.Set_Value(F("DEFAULTB_RAD"), 1);
        Display.Set_Value(F("COLORB_RAD"), 0);
    }
    else
    {
        Display.Set_Value(F("DEFAULTB_RAD"), 0);
        Display.Set_Value(F("COLORB_RAD"), 1);
        Display.Set_Value(F("COLORB_NUM"), DESK.Background);
    }
    Display.Set_Value(F("GMTOFFSET_NUM"), GMT_Offset);
    Display.Set_Value(F("DAYLIGHTO_NUM"), Daylight_Offset);
    Display.Set_Text(F("DEVICEVAL_TXT"), Name);
    Display.Set_Text(F("USERVAL_TXT"), Username);
    Display.Set_Text(F("PASSVAL1_TXT"), Password_1);
    Display.Set_Text(F("PASSVAL2_TXT"), Password_2);
    Display.Set_Text(F("WNAMEVAL_TXT"), WiFi_Name);
    Display.Set_Text(F("WPASSVAL_TXT"), WiFi_Password);
    Display.Set_Value(F("AUTOLOGIN_CHE"), Autologin);
}

void Shell_Class::Preferences_Class::Execute_Install_Instruction(Xila_Class::Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('C', 'l'):
        if (DIALOG.Event(F("Are you sure to cancel the installation and shutdown Xila ?"), Question) == Default_Yes)
        {
            System.Shutdown();
        }
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('C', 'o'):
        if (strcmp(Password_1, Password_2) != 0)
        {
            DIALOG.Event(F("Passwords does not match."), Error);
            return;
        }

        if (DIALOG.Event(F("Are you sure of these entries ?"), Question) == Default_Yes)
        {
            if (!Drive.Make_Directory(Users_Directory_Path))
            {
                DIALOG.Event(F("Cannot make users directory."), Error);
            }
            // -- Regional preferences
            Time.GMT_Offset = GMT_Offset;
            Time.Daylight_Offset = Daylight_Offset;

            if (WiFi.Save_Registry() != Success)
            {
                DIALOG.Event(F("Cannot save network registry."), Error);
            }

            if (Time.Save_Registry() != Success)
            {
                DIALOG.Event(F("Cannot save regional registry."), Error);
            }
            // -- User account
            if (Account.Add(Username, Password_1) != Success)
            {
                DIALOG.Event(F("Cannot create user account."), Error);
            }
            Account.Login(Username, Password_1);
            Account.Set_Autologin(Autologin);
            // -- Shell registry
            SHELL->Save_Registry();

            // -- Load
#if Animations == 1
            DIALOG.Load(F("Login"), F("Loading user data ..."), 4000);
            DIALOG.Close_Load();
#endif

            DESK.Open(Pages.Desk);
            Preferences_Class::Close();
        }
        break;
    case Instruction('D', 'B'):
        DESK.Background = -1;
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('C', 'B'):
    {
        if (DESK.Background < 0 || DESK.Background > 0xFFFF)
        {
            DESK.Background = 16904;
        }
        uint16_t Temporary_Color = DESK.Background;
        DIALOG.Color_Picker(Temporary_Color);
        DESK.Background = Temporary_Color;
        SHELL->Send_Instruction('R', 'e');
        break;
    }
    case Instruction('k', 'O'): // -- Keypad for GMT Offset
    {
        float Temporary_Float = GMT_Offset;
        DIALOG.Keypad(Temporary_Float);
        GMT_Offset = (int32_t)Temporary_Float;
        SHELL->Send_Instruction('R', 'e');
        break;
    }
    case Instruction('k', 'o'): // -- Keypad for Daylight offset
    {
        float Temporary_Float = Daylight_Offset;
        DIALOG.Keypad(Temporary_Float);
        Daylight_Offset = (int16_t)Temporary_Float;
        SHELL->Send_Instruction('R', 'e');
        break;
    }
    case Instruction('K', 'N'): // -- Device name keyboard input
        DIALOG.Keyboard(Name, sizeof(Name));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'U'): // -- Username keyboard input
        DIALOG.Keyboard(Username, sizeof(Username));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'P'): // -- Password keyboard input
        DIALOG.Keyboard(Password_1, sizeof(Password_1), true);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'p'): // -- Confirm password keyboard input
        DIALOG.Keyboard(Password_2, sizeof(Password_2), true);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('A', 'u'): // -- Enable or disable autologin
        Autologin = !Autologin;
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'W'): // -- WiFi name keyboard input
        DIALOG.Keyboard(WiFi_Name, sizeof(WiFi_Name));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'w'): // -- WiFi password keyboard input
        DIALOG.Keyboard(WiFi_Password, sizeof(WiFi_Password), true);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('W', 'C'): // WiFi connect
        WiFi.Set_Credentials(WiFi_Name, WiFi_Password);
        break;
    case Instruction('R', 'e'):
        Refresh_Install();
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}