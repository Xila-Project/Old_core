///
/// @file Desk.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Desk of Shell
/// @version 0.1
/// @date 29-06-2021
///
/// @copyright Copyright (c) 2021
///

#include "Software/Shell/Shell.hpp"
#include "Software/Shell/Translation.hpp"

#define Shell_Pointer Shell_Class::Instance_Pointer
#define Desk_Pointer Shell_Class::Desk

// -- Constructor -- //

Shell_Class::Desk_Class::Desk_Class()
{
    Offset = 0;
    Background = -1;
}

void Shell_Class::Desk_Class::Refresh_Login()
{
    Xila.Display.Set_Text(F("USERNAME_TXT"), Username);
    Xila.Display.Set_Text(F("PASSWORD_TXT"), Password);
}

void Shell_Class::Desk_Class::Execute_Login_Instruction(Xila_Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('S', 'h'):
        DIALOG->Load(F("Shutdown"), F("Xila is shutting down..."));
        Xila.System.Shutdown();
        break;
    case Instruction('K', 'U'):
        memset(Username, '\0', sizeof(Username));
        DIALOG->Keyboard(Username, sizeof(Username));
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'P'):
        memset(Password, '\0', sizeof(Password));
        DIALOG->Keyboard(Password, sizeof(Password), true);
        Instance_Pointer->Send_Instruction('R', 'e');
        break;
    case Instruction('L', 'o'): // Lo : Login with entred username and password
        if (Xila.Account.Login(Username, Password) == Xila.Success)
        {
            if (Xila.Account.State == Xila.Account.Locked && (strcmp(Xila.Account.Current_Username, Username) != 0)) // if a preced user was connected and we connect from a new user, have to close all of it's software.
            {
                for (uint8_t i = 2; i < 8; i++)
                {
                    if (Xila.Software.Openned[i] != NULL)
                    {
                        Xila.Software.Close(*Xila.Software.Openned[i]->Handle);
                    }
                }
            }

            Xila.Sound.Play(Sounds("Login.wav"));

            DIALOG->Load(Load_Login_Header_String, Load_Login_Message_String);

            if (Instance_Pointer->Load_Registry() != Xila.Success)
            {
                Instance_Pointer->Save_Registry();
            }

#if Animations == 1
            Xila.Task.Delay(4000);
#endif

            DIALOG->Close();

            SHELL->Send_Instruction('O', 'D');
        }
        else
        {
            DIALOG->Event(Event_Error_Wrong_Credentials, Xila.Error);
            Instance_Pointer->Send_Instruction('R', 'e');
        }
        break;
    case Instruction('R', 'e'):
        Refresh_Login();
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

void Shell_Class::Desk_Class::Logout()
{
    if (Xila.Account.Current_Username[0] != '\0')
    {
        Instance_Pointer->Save_Registry();
    }
    Xila.Account.Logout();

    DESK.Open(Pages.Login);
}

// -- Drawer -- //

void Shell_Class::Desk_Class::Refresh_Drawer()
{
    if (Xila.Software.Handle[Offset] == NULL)
    {
        Offset = 0;
    }
    // Item name drawing
    char Temporary_String[11] = "ITEM _TXT";
    for (uint8_t i = 0; i < 15; i++)
    {

        Temporary_String[4] = i + 'A';

        if (Xila.Software.Handle[i + Offset] != NULL)
        {
            Xila.Display.Set_Text(Temporary_String, Xila.Software.Handle[i + Offset]->Name);
        }
        else
        {
            Xila.Display.Set_Text(Temporary_String, "");
        }
        Xila.Task.Delay(1);
    }

    // Item picture drawing
    strcpy(Temporary_String, "ITEM _PIC");
    for (uint8_t i = 0; i < 15; i++)
    {
        Temporary_String[4] = i + 'A';

        if (Xila.Software.Handle[i + Offset] != NULL)
        {
            Xila.Display.Set_Picture(Temporary_String, Xila.Software.Handle[i + Offset]->Icon);
        }
        else
        {
            Xila.Display.Hide(Temporary_String);
        }
    }
}

void Shell_Class::Desk_Class::Execute_Drawer_Instruction(Xila_Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('R', 'e'):
        Refresh_Drawer();
        break;
    case Instruction('N', 'd'): // Nd : Next drawer items
        if ((Offset + 15) < (sizeof(Xila.Software.Handle) / sizeof(Xila.Software.Handle[1])))
        {
            if (Xila.Software.Handle[Offset + 15] != NULL)
            {
                Offset += 15;
                Instance_Pointer->Send_Instruction('R', 'e');
            }
        }
        break;
    case Instruction('P', 'd'): // Pd : Previous drawer items
        if (Offset > 14)
        {
            Offset -= 15;
            Instance_Pointer->Send_Instruction('R', 'e');
        }
        else
        {
            Offset = 0;
        }
        break;
    case Instruction('d', '0'): // dx : Open software from drawer
        Open_From_Drawer(0);
        break;
    case Instruction('d', '1'): // dx : Open software from drawer
        Open_From_Drawer(1);
        break;
    case Instruction('d', '2'): // dx : Open software from drawer
        Open_From_Drawer(2);
        break;
    case Instruction('d', '3'): // dx : Open software from drawer
        Open_From_Drawer(3);
        break;
    case Instruction('d', '4'): // dx : Open software from drawer
        Open_From_Drawer(4);
        break;
    case Instruction('d', '5'): // dx : Open software from drawer
        Open_From_Drawer(5);
        break;
    case Instruction('d', '6'): // dx : Open software from drawer
        Open_From_Drawer(6);
        break;
    case Instruction('d', '7'): // dx : Open software from drawer
        Open_From_Drawer(7);
        break;
    case Instruction('d', '8'): // dx : Open software from drawer
        Open_From_Drawer(8);
        break;
    case Instruction('d', '9'): // dx : Open software from drawer
        Open_From_Drawer(9);
        break;
    case Instruction('d', 'A'): // dx : Open software from drawer
        Open_From_Drawer(10);
        break;
    case Instruction('d', 'B'): // dx : Open software from drawer
        Open_From_Drawer(11);
        break;
    case Instruction('d', 'C'): // dx : Open software from drawer
        Open_From_Drawer(12);
        break;
    case Instruction('d', 'D'): // dx : Open software from drawer
        Open_From_Drawer(13);
        break;
    case Instruction('d', 'E'): // dx : Open software from drawer
        Open_From_Drawer(14);
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

void Shell_Class::Desk_Class::Open_From_Drawer(uint8_t Slot)
{
    if ((Slot + Offset) < (sizeof(Xila.Software.Handle) / sizeof(Software_Handle_Class *)))
    {
        if (Xila.Software.Handle[Slot + Offset] != NULL)
        {
            if (Xila.Software.Open(*Xila.Software.Handle[Slot + Offset]) != Xila.Success)
            {
                DIALOG->Event(Event_Error_Open_Software, Xila.Error);
                Instance_Pointer->Send_Instruction('R', 'e');
            }
        }
        else
        {
            DESK.Open(Pages.Drawer);
        }
    }
    else
    {
        DESK.Open(Pages.Drawer);
    }
}

// -- Desk -- //

void Shell_Class::Desk_Class::Open(char Mode)
{

    if (Xila.Account.Get_State() != Xila.Account.Logged)
    {
        Xila.Display.Set_Current_Page(Pages.Login);
        if (Xila.Account.Get_State() != Xila.Account.Disconnected)
        {
            memset(Username, '\0', sizeof(Username));
            memset(Password, '\0', sizeof(Password));
            strcpy(Username, "Username");
            strcpy(Password, "Password");
        }
        else
        {
            memset(Username, '\0', sizeof(Username));
            memset(Password, '\0', sizeof(Password));
            strcpy(Username, Xila.Account.Get_Current_Username());
            strcpy(Password, "Password");
        }
        Refresh_Login();
        return;
    }
    else if (Mode == Pages.Drawer)
    {
        Xila.Display.Set_Current_Page(Pages.Drawer);
        Offset = 0;
        Refresh_Drawer();
        return;
    }
    else
    {
        Xila.Display.Set_Current_Page(Pages.Desk);
        Refresh_Desk();
        Xila.Display.Hide(F("MAXIMIZE_BUT"));
        Xila.Display.Hide(F("CLOSE_BUT"));
        return;
    }
}

void Shell_Class::Desk_Class::Refresh_Desk()
{
    if (DESK.Background == -1)
    {
        Xila.Display.Hide(F("COLORB_TXT"));
        Xila.Display.Show(F("IMAGEB_TXT"));
    }
    else
    {
        Xila.Display.Set_Background_Color(F("COLORB_TXT"), DESK.Background);
        Xila.Display.Hide(F("IMAGEB_TXT"));
        Xila.Display.Show(F("COLORB_TXT"));
    }

    Xila.Display.Refresh(F("0"));

    char Temporary_String[] = "SLOT _PIC";

    // List all running app on the task bar
    for (uint8_t Slot = 2; Slot < 8; Slot++)
    {
        Temporary_String[4] = Slot - 1 + '0';
        if (Xila.Software.Openned[Slot] != NULL)
        {
            Xila.Display.Set_Picture(Temporary_String, Xila.Software.Openned[Slot]->Handle->Icon);
        }
        else
        {
            Xila.Display.Hide(Temporary_String);
        }
    }
}

void Shell_Class::Desk_Class::Execute_Desk_Instruction(Xila_Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('M', '1'):
        Dock(1, 'M');
        break;
    case Instruction('M', '2'):
        Dock(2, 'M');
        break;
    case Instruction('M', '3'):
        Dock(3, 'M');
        break;
    case Instruction('M', '4'):
        Dock(4, 'M');
        break;
    case Instruction('M', '5'):
        Dock(5, 'M');
        break;
    case Instruction('M', '6'):
        Dock(6, 'M');
        break;
    case Instruction('C', '1'):
        Dock(1, 'C');
        break;
    case Instruction('C', '2'):
        Dock(2, 'C');
        break;
    case Instruction('C', '3'):
        Dock(3, 'C');
        break;
    case Instruction('C', '4'):
        Dock(4, 'C');
        break;
    case Instruction('C', '5'):
        Dock(5, 'C');
        break;
    case Instruction('C', '6'):
        Dock(6, 'C');
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

void Shell_Class::Desk_Class::Dock(uint8_t Slot, uint8_t Action)
{
    if (Xila.Software.Openned[Slot + 1] == NULL)
    {
        return;
    }
    if (Action == 'M') // maximize
    {
        Xila.Software.Maximize(*Xila.Software.Openned[Slot + 1]->Handle);
    }
    else if (Action == 'C')
    {
        Xila.Software.Close(*Xila.Software.Openned[Slot + 1]->Handle);
    }
}
