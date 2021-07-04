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

Shell_Class::Preferences_Class::Preferences_Class()
{
    // -- Account
    Autologin = false;
    strcpy(Username, Xila.Account.Get_Current_Username());
    memset(Password_1, '\0', sizeof(Password_1));
    memset(Password_2, '\0', sizeof(Password_2));

    memset(Target_Username, '\0', sizeof(Username));
    memset(Name, '\0', sizeof(Name));
    strcpy(Name, Xila.System.Get_Device_Name());

    // -- Network
    strlcpy(WiFi_Name, Xila.WiFi.SSID().c_str(), sizeof(WiFi_Name));
    memset(WiFi_Password, '\0', sizeof(WiFi_Password));

    Local_IP = Xila.WiFi.localIP();
    Gateway_IP = Xila.WiFi.gatewayIP();
    Subnet_Mask = Xila.WiFi.subnetMask();
    DNS[0] = Xila.WiFi.dnsIP(0);
    DNS[1] = Xila.WiFi.dnsIP(1);

    // -- Time
    memset(NTP_Server, '\0', sizeof(NTP_Server));
    strcpy(NTP_Server, Xila.Time.NTP_Server);
    GMT_Offset = Xila.Time.GMT_Offset;
    Daylight_Offset = Xila.Time.Daylight_Offset;

    // -- Benchmark
    Write_Speed = 0;
    Read_Speed = 0;
}

// -- State management -- //

void Shell_Class::Preferences_Class::Open(uint8_t Mode)
{
    if (!State())
    {
        PREFERENCES = new Preferences_Class();
    }
    switch (Mode)
    {
    case Pages.Preferences_Personal:
        Xila.Display.Set_Current_Page(Pages.Preferences_Personal);
        break;
    case Pages.Preferences_System:
        Xila.Display.Set_Current_Page(Pages.Preferences_System);
        break;
    case Pages.Preferences_Network:
        Xila.Display.Set_Current_Page(Pages.Preferences_Network);
        break;

    case Pages.Preferences_Hardware:
        Xila.Display.Set_Current_Page(Pages.Preferences_Hardware);
        break;
    case Pages.Preferences_Install:
        Xila.Display.Set_Current_Page(Pages.Preferences_Install);
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
    if (State())
    {
        delete PREFERENCES;
    }
}

// --

void Shell_Class::Preferences_Class::Execute_Personal_Instruction(Xila_Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('C', 'B'):
    {
        if (DESK.Background < 0 || DESK.Background > 0xFFFF)
        {
            DESK.Background = 16904;
        }
        uint16_t Temporary_Color = DESK.Background;
        DIALOG->Color_Picker(Temporary_Color);
        DESK.Background = Temporary_Color;
        SHELL->Send_Instruction('R', 'e');
        break;
    }
    case Instruction('D', 'B'):
        DESK.Background = -1;
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'U'):
        Dialog_Class::Keyboard(Username, sizeof(Username));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'P'):
        Dialog_Class::Keyboard(Password_1, sizeof(Password_1));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'p'):
        Dialog_Class::Keyboard(Password_2, sizeof(Password_2));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('C', 'U'):
        if (Xila.Account.Change_Username(Xila.Account.Current_Username, Username) != Xila.Success)
        {
            DIALOG->Event(F("Failed to change username."), Xila.Error);
        }
        else
        {
            DIALOG->Event(F("Username successfully modified."), Xila.Information);
        }
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('C', 'P'):
        if (strcmp(Password_1, Password_2) == 0)
        {
            if (Xila.Account.Change_Password(Xila.Account.Current_Username, Password_1) != Xila.Success)
            {
                DIALOG->Event(F("Failed to change password."), Xila.Error);
            }
            else
            {
                DIALOG->Event(F("Password successfully modified."), Xila.Information);
            }
        }
        else
        {
            DIALOG->Event(F("Passwords doesn't match."), Xila.Error);
        }
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('D', 'A'): // Disable autologin
        Xila.Account.Set_Autologin(false);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('E', 'A'): // Enable autologin
        Xila.Account.Set_Autologin(true);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('N', 'L'):
        if (Xila.Keyboard.Layout < Xila.Keyboard.English)
        {
            Xila.Keyboard.Layout++;
        }
        else
        {
            Xila.Keyboard.Layout = 0;
        }
        DIALOG->Event(F("Please restart Xila to apply preferences."), Xila.Information);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('P', 'L'):
        if (Xila.Keyboard.Layout > 0)
        {
            Xila.Keyboard.Layout--;
        }
        else
        {
            Xila.Keyboard.Layout = Xila.Keyboard.English;
        }
        DIALOG->Event(F("Please restart Xila to apply preferences."), Xila.Information);
        SHELL->Send_Instruction('R', 'e');
        break;

    case Instruction('D', 'U'):
        if (DIALOG->Event(F("Are you sure to delete this user ?"), Xila.Question) == Xila.Button_1)
        {
            if (Xila.Account.Delete(Xila.Account.Current_Username) != Xila.Success)
            {
                DIALOG->Event(F("Cannot delete user."), Xila.Error);
            }
            else
            {
                DIALOG->Event(F("User successfully deleted."), Xila.Error);
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
        Xila.Display.Set_Value(F("COLORB_RAD"), 0);
        Xila.Display.Set_Value(F("DEFAULTB_RAD"), 1);
    }
    else
    {
        Xila.Display.Set_Value(F("COLORB_NUM"), DESK.Background);
        Xila.Display.Set_Background_Color(F("COLORB_NUM"), DESK.Background);
        Xila.Display.Set_Value(F("COLORB_RAD"), 1);
        Xila.Display.Set_Value(F("DEFAULTB_RAD"), 0);
    }
    Xila.Display.Set_Text(F("USERVAL_TXT"), Username);
    Xila.Display.Set_Text(F("PASSVAL1_TXT"), Password_1);
    Xila.Display.Set_Text(F("PASSVAL2_TXT"), Password_2);
    switch (Xila.Keyboard.Layout)
    {
    case Xila.Keyboard.American:
        Xila.Display.Set_Text(F("LAYOUT_TXT"), F("American"));
        break;
    case Xila.Keyboard.German:
        Xila.Display.Set_Text(F("LAYOUT_TXT"), F("German"));
        break;
    case Xila.Keyboard.French:
        Xila.Display.Set_Text(F("LAYOUT_TXT"), F("French"));
        break;
    case Xila.Keyboard.Spanish:
        Xila.Display.Set_Text(F("LAYOUT_TXT"), F("Spanish"));
        break;
    case Xila.Keyboard.Italian:
        Xila.Display.Set_Text(F("LAYOUT_TXT"), F("Italian"));
        break;
    case Xila.Keyboard.English:
        Xila.Display.Set_Text(F("LAYOUT_TXT"), F("English"));
        break;
    default:
        break;
    }
}

// -- Hardware -- //

void Shell_Class::Preferences_Class::Refresh_Hardware()
{
    char Temporary_String[40];

    Xila.Display.Set_Value(F("BRIGHTNESS_SLI"), Xila.Display.Brightness);
    snprintf(Temporary_String, sizeof(Temporary_String), " Battery : %i %%", Xila.Power.Get_Charge_Level());
    Xila.Display.Set_Text(F("BATTERY_TXT"), Temporary_String);
    Xila.Display.Set_Value(F("VOLUME_SLI"), Xila.Sound.Get_Volume());
    Xila.Display.Set_Value(F("STANDBY_NUM"), Xila.Display.Standby_Time);

    switch (Xila.Drive.Type())
    {
    case Xila.Drive.None:
        snprintf(Temporary_String, sizeof(Temporary_String), " Drive : None | %i MB", (uint16_t)(Xila.Drive.Size() / (1024 * 1024)));
        break;
    case Xila.Drive.SD_SC:
        snprintf(Temporary_String, sizeof(Temporary_String), " Drive : SD SC | %i MB", (uint16_t)(Xila.Drive.Size() / (1024 * 1024)));
        break;
    case Xila.Drive.SD_HC:
        snprintf(Temporary_String, sizeof(Temporary_String), " Drive : SD HC | %i MB", (uint16_t)(Xila.Drive.Size() / (1024 * 1024)));
        break;
    case Xila.Drive.MMC:
        snprintf(Temporary_String, sizeof(Temporary_String), " Drive : SD MMC | %i MB", (uint16_t)(Xila.Drive.Size() / (1024 * 1024)));
        break;
    case Xila.Drive.Unknow:
        snprintf(Temporary_String, sizeof(Temporary_String), " Drive : Unknow | %i MB", (uint16_t)(Xila.Drive.Size() / (1024 * 1024)));
        break;
    }
    Xila.Display.Set_Text(F("DRIVE_TXT"), Temporary_String);

    sprintf(Temporary_String, " Speed: Read %i KB/s | Write %i KB/s", Read_Speed, Write_Speed);
    Xila.Display.Set_Text(F("SPEED_TXT"), Temporary_String);
}

void Shell_Class::Preferences_Class::Execute_Hardware_Instruction(Xila_Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('T', 'D'): // -- Drive testing
    {
        File Test_File = Xila.Drive.Open(F(Test_Path), FILE_WRITE);
        if (!Test_File)
        {
            DIALOG->Event(F("Failed to start the write test."), Xila.Error);

            SHELL->Send_Instruction('R', 'e');
            break;
        }
        SHELL->Set_Watchdog_Timeout(15000);
        static uint8_t Buffer[512] = {255};
        uint16_t i;
        double Time = Xila.Time.Milliseconds();

        for (i = 0; i < 2048; i++)
        {
            Xila.Task.Delay(1);
            Test_File.write(Buffer, sizeof(Buffer));
        }

        Time = Xila.Time.Milliseconds() - Time;
        Time /= 1000;               // convert time in sec
        Time = (2048 * 512) / Time; // divide quantity data copied by the time in sec
        Write_Speed = Time / 1000;
        Test_File.close();
        Test_File = Xila.Drive.Open(F(Test_Path));
        SHELL->Set_Watchdog_Timeout();
        if (!Test_File)
        {
            DIALOG->Event(F("Failed to start the read test."), Xila.Error);
            SHELL->Send_Instruction('R', 'e');
            break;
        }

        SHELL->Set_Watchdog_Timeout(15000);
        size_t Length = Test_File.size();
        Time = Xila.Time.Milliseconds();
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
        Time = Xila.Time.Milliseconds() - Time;
        Time /= 1000;
        Time = Test_File.size() / Time;
        Read_Speed = Time / 1000;
        Test_File.close();
        Xila.Drive.Remove(F(Test_Path));
        SHELL->Set_Watchdog_Timeout();
        break;
    }
    case Instruction('V', '+'):
        if (Xila.Sound.Get_Volume() <= 243)
        {
            Xila.Sound.Set_Volume(Xila.Sound.Get_Volume() + 12);
            SHELL->Send_Instruction('R', 'e');
        }
        break;
    case Instruction('V', '-'):
        if (Xila.Sound.Get_Volume() >= 12)
        {
            Xila.Sound.Set_Volume(Xila.Sound.Get_Volume() - 12);
            Instance_Pointer->Send_Instruction('R', 'e');
        }
        break;
    case Instruction('S', '+'):
        Xila.Display.Standby_Time += 5;
        Xila.Display.Set_Standby_Touch_Timer(Xila.Display.Standby_Time);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('S', '-'):
        if (Xila.Display.Standby_Time >= 5)
        {
            Xila.Display.Standby_Time -= 5;
            Xila.Display.Set_Standby_Touch_Timer(Xila.Display.Standby_Time);
        }
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('D', 'S'):
        Xila.Display.Standby_Time = 0;
        Xila.Display.Set_Standby_Touch_Timer(Xila.Display.Standby_Time);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('R', 'e'):
        Refresh_Hardware();
        break;
    case Instruction('D', 'C'):
        Xila.Display.Calibrate();
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

// -- Network -- //

void Shell_Class::Preferences_Class::Refresh_Network()
{
    Xila.Display.Set_Text(F("WNAMEVAL_TXT"), WiFi_Name);
    Xila.Display.Set_Text(F("WPASSVAL_TXT"), WiFi_Password);
}

void Shell_Class::Preferences_Class::Execute_Network_Instruction(Xila_Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('K', 'W'):
        Dialog_Class::Keyboard(WiFi_Name, sizeof(WiFi_Name));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'w'):
        Dialog_Class::Keyboard(WiFi_Password, sizeof(WiFi_Password), true);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('W', 'D'):
        Xila.WiFi.disconnect();
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('W', 'C'):
        Xila.WiFi.Set_Credentials(WiFi_Name, WiFi_Password);
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

void Shell_Class::Preferences_Class::Execute_System_Instruction(Xila_Instruction Instruction)
{
    switch (Instruction)
    {
    // -- Device name
    case Instruction('K', 'N'):
        Dialog_Class::Keyboard(Name, sizeof(Name));
        Refresh_System();
        break;
    case Instruction('A', 'N'):
        strlcpy(Xila.System.Device_Name, Name, sizeof(Xila.System.Device_Name));
        Xila.System.Save_Registry();
        DIALOG->Event(F("Please restart Xila to apply changes."), Xila.Information);
        SHELL->Send_Instruction('R', 'e');
        break;
    // -- Time
    case Instruction('K', 'n'):
        Dialog_Class::Keyboard(NTP_Server, sizeof(NTP_Server));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('k', 'O'):
    {
        float Temporary_Float = GMT_Offset;
        Dialog_Class::Keypad(Temporary_Float);
        GMT_Offset = Temporary_Float;
        SHELL->Send_Instruction('R', 'e');
        break;
    }
    case Instruction('k', 'o'):
    {
        float Temporary_Float = Daylight_Offset;
        Dialog_Class::Keypad(Temporary_Float);
        Daylight_Offset = Temporary_Float;
        SHELL->Send_Instruction('R', 'e');
        break;
    }
    case Instruction('A', 'T'):
        Xila.Time.GMT_Offset = GMT_Offset;
        Xila.Time.Daylight_Offset = Daylight_Offset;
        strlcpy(Xila.Time.NTP_Server, NTP_Server, sizeof(Xila.Time.NTP_Server));
        Xila.Time.Save_Registry();
        DIALOG->Event(F("Please restart Xila to apply changes."), Xila.Information);
        SHELL->Send_Instruction('R', 'e');
        break;
    // -- Add user
    case Instruction('K', 'U'):
        Dialog_Class::Keyboard(Username, sizeof(Username));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('A', 'U'):
        if (Xila.Account.Add(Username, ""))
        {
            DIALOG->Event(F("Failed to add user."), Xila.Error);
        }
        else
        {
            DIALOG->Event(F("User successfully added."), Xila.Information);
        }
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('O', 'A'):
        Xila.Display.Set_Current_Page(Pages.About);
        break;
    case Instruction('U', 'p'):
        if (DIALOG->Event(F("Do you really want to update Xila ? That will make the system restart."), Xila.Warning) != Xila.Button_1)
        {
            SHELL->Send_Instruction('R', 'e');
            return;
        }
        if (!Xila.Drive.Exists(Display_Executable_Path) || !Xila.Drive.Exists(Microcontroller_Executable_Path))
        {
            DIALOG->Event(F("Missing update files."), Xila.Error);
            SHELL->Send_Instruction('R', 'e');
            return;
        }
        else
        {
            Xila.Display.Set_Current_Page(Pages.Dialog_Load);
            Xila.Display.Set_Text(F("MESSAGE_TXT"), F("Updating Xila"));
            Xila.Display.Set_Text(F("SUBHEADER_TXT"), F("Update"));

            File Temporary_File = Xila.Drive.Open(Microcontroller_Executable_Path);
            if (Xila.System.Load_Executable(Temporary_File) != Xila.Success)
            {
                Xila.System.Restart();
                return;
            }

            Temporary_File = Xila.Drive.Open(Display_Executable_Path);
            if (Xila.Display.Update(Temporary_File) != Xila.Success)
            {
                Xila.System.Restart();
                return;
            }

            Xila.System.Restart();
        }
        break;
    case Instruction('R', 'e'): // -- Refresh
        Refresh_System();
        break;

    case Instruction('G', 'V'): // -- Current version (About)
        Xila.Display.Set_Text(F("VERSION_TXT"), ("Version : " Xila_Version_Major_String "." Xila_Version_Minor_String "." Xila_Version_Revision_String));
        break;

    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

void Shell_Class::Preferences_Class::Refresh_System()
{
    Xila.Display.Set_Text(F("NTPVAL_TXT"), NTP_Server);
    Xila.Display.Set_Value(F("GMTOFFSET_NUM"), GMT_Offset);
    Xila.Display.Set_Value(F("DAYLIGHTO_NUM"), Daylight_Offset);

    Xila.Display.Set_Text(F("DEVICEVAL_TXT"), Name);
    Xila.Display.Set_Text(F("USERVAL_TXT"), Username);
}

void Shell_Class::Preferences_Class::Refresh_Install()
{
    if (DESK.Background < 0)
    {
        Xila.Display.Set_Value(F("DEFAULTB_RAD"), 1);
        Xila.Display.Set_Value(F("COLORB_RAD"), 0);
    }
    else
    {
        Xila.Display.Set_Value(F("DEFAULTB_RAD"), 0);
        Xila.Display.Set_Value(F("COLORB_RAD"), 1);
        Xila.Display.Set_Value(F("COLORB_NUM"), DESK.Background);
    }
    Xila.Display.Set_Value(F("GMTOFFSET_NUM"), GMT_Offset);
    Xila.Display.Set_Value(F("DAYLIGHTO_NUM"), Daylight_Offset);
    Xila.Display.Set_Text(F("DEVICEVAL_TXT"), Name);
    Xila.Display.Set_Text(F("USERVAL_TXT"), Username);
    Xila.Display.Set_Text(F("PASSVAL1_TXT"), Password_1);
    Xila.Display.Set_Text(F("PASSVAL2_TXT"), Password_2);
    Xila.Display.Set_Text(F("WNAMEVAL_TXT"), WiFi_Name);
    Xila.Display.Set_Text(F("WPASSVAL_TXT"), WiFi_Password);
    Xila.Display.Set_Value(F("AUTOLOGIN_CHE"), Autologin);
}

void Shell_Class::Preferences_Class::Execute_Install_Instruction(Xila_Instruction Instruction)
{
    switch (Instruction)
    {
    case Dialog_Power:
    case Instruction('O', 's'):
        if (DIALOG->Event(F("Are you sure to cancel the installation and shutdown Xila ?"), Xila.Question) == Xila.Default_Yes)
        {
            Xila.System.Shutdown();
        }
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('C', 'o'):
        if (strcmp(Password_1, Password_2) != 0)
        {
            DIALOG->Event(F("Passwords does not match."), Xila.Error);
            return;
        }

        if (DIALOG->Event(F("Are you sure of these entries ?"), Xila.Question) == Xila.Default_Yes)
        {
            if (!Xila.Drive.Make_Directory(Users_Directory_Path))
            {
                DIALOG->Event(F("Cannot make users directory."), Xila.Error);
            }
            // -- Regional preferences
            Xila.Time.GMT_Offset = GMT_Offset;
            Xila.Time.Daylight_Offset = Daylight_Offset;

            if (Xila.WiFi.Save_Registry() != Xila.Success)
            {
                DIALOG->Event(F("Cannot save network registry."), Xila.Error);
            }

            if (Xila.Time.Save_Registry() != Xila.Success)
            {
                DIALOG->Event(F("Cannot save regional registry."), Xila.Error);
            }
            // -- User account
            if (Xila.Account.Add(Username, Password_1) != Xila.Success)
            {
                DIALOG->Event(F("Cannot create user account."), Xila.Error);
            }
            Xila.Account.Login(Username, Password_1);
            Xila.Account.Set_Autologin(Autologin);
            // -- Shell registry
            SHELL->Save_Registry();

            // -- Load

#if Animations == 1
            DIALOG->Load(F("Login"), F("Loading user data ..."), 4000);
#else
            DIALOG->Load(F("Login"), F("Loading user data ..."));
#endif

            Xila.Display.Set_Value(F("STATE_VAR"), 2);

#if Animations == 1
            Xila.Task.Delay(1000);
#endif
            DESK.Open(Pages.Desk);
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
        DIALOG->Color_Picker(Temporary_Color);
        DESK.Background = Temporary_Color;
        SHELL->Send_Instruction('R', 'e');
        break;
    }
    case Instruction('k', 'O'): // -- Keypad for GMT Offset
    {
        float Temporary_Float = GMT_Offset;
        DIALOG->Keypad(Temporary_Float);
        GMT_Offset = (int32_t)Temporary_Float;
        SHELL->Send_Instruction('R', 'e');
        break;
    }
    case Instruction('k', 'o'): // -- Keypad for Daylight offset
    {
        float Temporary_Float = Daylight_Offset;
        DIALOG->Keypad(Temporary_Float);
        Daylight_Offset = (int16_t)Temporary_Float;
        SHELL->Send_Instruction('R', 'e');
        break;
    }
    case Instruction('K', 'N'): // -- Device name keyboard input
        Dialog_Class::Keyboard(Name, sizeof(Name));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'U'): // -- Username keyboard input
        Dialog_Class::Keyboard(Username, sizeof(Username));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'P'): // -- Password keyboard input
        Dialog_Class::Keyboard(Password_1, sizeof(Password_1), true);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'p'): // -- Confirm password keyboard input
        Dialog_Class::Keyboard(Password_2, sizeof(Password_2), true);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('A', 'u'): // -- Enable or disable autologin
        Autologin = !Autologin;
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'W'): // -- WiFi name keyboard input
        Dialog_Class::Keyboard(WiFi_Name, sizeof(WiFi_Name));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'w'): // -- WiFi password keyboard input
        Dialog_Class::Keyboard(WiFi_Password, sizeof(WiFi_Password), true);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('W', 'C'): // WiFi connect
        Xila.WiFi.Set_Credentials(WiFi_Name, WiFi_Password);
        break;
    case Instruction('R', 'e'):
        Refresh_Install();
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}