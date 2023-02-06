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

// -- Constructor -- //

Shell_Class::Preferences_Class::Preferences_Class(Shell_Class* Shell_Pointer) : Shell_Pointer(Shell_Pointer)
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
    Draw_Network();
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

void Shell_Class::Preferences_Class::Draw_System()
{
    System_Tab.Set_Flex_Flow(Flex_Flow_Type::Row);
    System_Tab.Set_Style_Pad_All(0, 0);

    Object_Type Grid;
    Grid.Create(System_Tab);
    Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Grid.Set_Grid_Descriptor_Array(Column_Descriptor, Row_Descriptor);
    Grid.Set_Style_Pad_All(10, 0);

    const uint8_t Device_Section_Row = 1;

    {
        Label_Type Label;
        Label.Create(Grid),
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, 0, 1);
        Label.Set_Text("Device");
        Label.Clear_Pointer();

        Text_Area_Type Text_Area;
        Text_Area.Create(Grid);
        Text_Area.Set_Placeholder_Text("Device name");
        Text_Area.Set_One_Line(true);
        Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Stretch, Device_Section_Row, 1);

        System_Name_Apply_Button.Create(Grid); 
        System_Name_Apply_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, Device_Section_Row, 1);

        Label_Type Label;
        Label.Create(System_Name_Apply_Button);
        Label.Set_Text("Apply");
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Clear_Pointer();

        System_Update_Button.Create(Grid);
        System_Update_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 4, Grid_Alignment_Type::Stretch, Device_Section_Row + 1, 1);

        Label.Create(System_Update_Button);
        Label.Set_Text("Update system");
        Label.Set_Alignment(Alignment_Type::Center);
        Label.Clear_Pointer();

        System_Reboot_Loader_Button.Create(Grid);
        System_Reboot_Loader_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 4, 4, Grid_Alignment_Type::Stretch, Device_Section_Row + 1, 1);
    }

    const uint8_t Time_Section_Row = Device_Section_Row + 2;

    {
        Label_Type Label;
        Label.Create(Grid);
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Time_Section_Row, 1);

        NTP_Server_Text_Area.Create(Grid);
        NTP_Server_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Stretch, Time_Section_Row + 1, 1);
        NTP_Server_Text_Area.Set_Placeholder_Text("N.T.P. server");
        NTP_Server_Text_Area.Set_One_Line(true);

        System_Apply_NTP_Server_Button.Create(Grid);
        System_Apply_NTP_Server_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, Time_Section_Row + 1, 1);



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

}

void Shell_Class::Preferences_Class::Execute_Personal_Instruction(Xila_Class::Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('C', 'l'):
        SHELL->Send_Instruction('O', 'D');
        Preferences_Class::Close();
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
    case Instruction('D', 'B'):
        DESK.Background = -1;
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'U'):
        DIALOG.Keyboard(Username, sizeof(Username));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'P'):
        DIALOG.Keyboard(Password_1, sizeof(Password_1));
        SHELL->Send_Instruction('R', 'e');
        break;
            if (Account.Change_Password(Account.Current_Username, Password_1) != Success)
            {
                DIALOG.Event(F("Failed to change password."), Error);
            }
            else
            {
                DIALOG.Event(F("Password successfully modified."), Information);
            }
        }
        else
        {
            DIALOG.Event(F("Passwords doesn't match."), Error);
        }
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('D', 'A'): // Disable autologin
        Account.Set_Autologin(false);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('E', 'A'): // Enable autologin
        Account.Set_Autologin(true);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('N', 'L'):
        if (Keyboard.Layout < Keyboard.English)
        {
            Keyboard.Layout++;
        }
        else
        {
            Keyboard.Layout = 0;
        }
        DIALOG.Event(F("Please restart Xila to apply preferences."), Information);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('P', 'L'):
        if (Keyboard.Layout > 0)
        {
            Keyboard.Layout--;
        }
        else
        {
            Keyboard.Layout = Keyboard.English;
        }
        DIALOG.Event(F("Please restart Xila to apply preferences."), Information);
        SHELL->Send_Instruction('R', 'e');
        break;

    case Instruction('D', 'U'):
        if (DIALOG.Event(F("Are you sure to delete this user ?"), Question) == Button_1)
        {
            if (Account.Delete(Account.Current_Username) != Success)
            {
                DIALOG.Event(F("Cannot delete user."), Error);
            }
            else
            {
                DIALOG.Event(F("User successfully deleted."), Error);
            }
        }
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('R', 'e'):
        Refresh_Personal();
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

void Shell_Class::Preferences_Class::Refresh_Personal()
{
    if (DESK.Background < 0)
    {
        Display.Set_Value(F("COLORB_RAD"), 0);
        Display.Set_Value(F("DEFAULTB_RAD"), 1);
    }
    else
    {
        Display.Set_Value(F("COLORB_NUM"), DESK.Background);
        Display.Set_Background_Color(F("COLORB_NUM"), DESK.Background);
        Display.Set_Value(F("COLORB_RAD"), 1);
        Display.Set_Value(F("DEFAULTB_RAD"), 0);
    }
    Display.Set_Text(F("USERVAL_TXT"), Username);
    Display.Set_Text(F("PASSVAL1_TXT"), Password_1);
    Display.Set_Text(F("PASSVAL2_TXT"), Password_2);
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
    }
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
        File Test_File = Drive.Open(F(Test_Path), FILE_WRITE);
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
        Test_File.close();
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
        Test_File.close();
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

void Shell_Class::Preferences_Class::Refresh_Network()
{
    Display.Set_Text(F("WNAMEVAL_TXT"), WiFi_Name);
    Display.Set_Text(F("WPASSVAL_TXT"), WiFi_Password);
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

            File Temporary_File = Drive.Open(Microcontroller_Executable_Path);
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