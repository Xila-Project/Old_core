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

void Shell_Class::Desk_Class::Logout()
{
    if (Xila.Account.Current_Username[0] != '\0')
    {
        Instance_Pointer->Save_Registry();
    }
    Xila.Account.Logout();

    DESK.Open(Pages.Desk);
}

// -- Drawer -- //

void Shell_Class::Desk_Class::Refresh_Drawer()
{
    if (Xila.Software_Management.Handle[Offset] == NULL)
    {
        Offset = 0;
    }
    // Item name drawing
    char Temporary_String[11] = "ITEM _TXT";
    for (uint8_t i = 0; i < 15; i++)
    {

        Temporary_String[4] = i + 'A';

        if (Xila.Software_Management.Handle[i + Offset] != NULL)
        {
            Xila.Display.Set_Text(Temporary_String, Xila.Software_Management.Handle[i + Offset]->Name);
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

        if (Xila.Software_Management.Handle[i + Offset] != NULL)
        {
            Xila.Display.Set_Picture(Temporary_String, Xila.Software_Management.Handle[i + Offset]->Icon);
        }
        else
        {
            Xila.Display.Hide(Temporary_String);
        }
    }
}

void Shell_Class::Desk_Class::Execute_Drawer_Instruction(Xila_Class::Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('R', 'e'):
        Refresh_Drawer();
        break;
    case Instruction('N', 'd'): // Nd : Next drawer items
        if ((Offset + 15) < (sizeof(Xila.Software_Management.Handle) / sizeof(Xila.Software_Management.Handle[1])))
        {
            if (Xila.Software_Management.Handle[Offset + 15] != NULL)
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
    if ((Slot + Offset) < (sizeof(Xila.Software_Management.Handle) / sizeof(Xila_Class::Software_Handle *)))
    {
        if (Xila.Software_Management.Handle[Slot + Offset] != NULL)
        {
            if (Xila.Software_Management.Open(*Xila.Software_Management.Handle[Slot + Offset]) != Xila.Success)
            {
                DIALOG.Event(Event_Error_Open_Software, Xila.Error);
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

void Shell_Class::Desk_Class::Open(uint8_t Mode)
{
    DUMP("Open desk");
    DUMP(Mode);

    if (Xila.Account.Get_State() != Xila.Account.Logged)
    {
        Xila.Display.Set_Current_Page(Pages.Desk);
        Xila.Display.Refresh(F("IMAGEB_TXT"));
        Xila.Display.Refresh(F("HEADER_TXT"));

        if (DIALOG.Login() != Xila.Success)
        {
            Xila.System.Shutdown();
            return;
        }
#if Animations == 1
        Xila.Sound.Play(Sounds("Login.wav"));
        DIALOG.Load(Load_Login_Header_String, Load_Login_Message_String);
#endif
        if (Instance_Pointer->Load_Registry() != Xila.Success)
        {
            Instance_Pointer->Save_Registry();
        }
    }

    if (Mode == Pages.Drawer)
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
        if (Xila.Software_Management.Openned[Slot] != NULL)
        {
            Xila.Display.Set_Picture(Temporary_String, Xila.Software_Management.Openned[Slot]->Handle->Icon);
        }
        else
        {
            Xila.Display.Hide(Temporary_String);
        }
    }
}

void Shell_Class::Desk_Class::Execute_Desk_Instruction(Xila_Class::Instruction Instruction)
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
    if (Xila.Software_Management.Openned[Slot + 1] == NULL)
    {
        return;
    }
    if (Action == 'M') // maximize
    {
        Xila.Software_Management.Maximize(*Xila.Software_Management.Openned[Slot + 1]->Handle);
    }
    else if (Action == 'C')
    {
        Xila.Software_Management.Close(*Xila.Software_Management.Openned[Slot + 1]->Handle);
    }
}
