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


    Window.Create();
    Window.Set_Title("Desk");

    Grid.Create(Window);
    Grid.Set_Style_Pad_All(10, 0);
    Grid.Set_Style_Background_Opacity(0, 0);
    Grid.Set_Grid_Descriptor_Array(Grid_Column_Descriptor, Grid_Row_Descriptor);
    Grid.Set_Size(LV_PCT(100), LV_PCT(100));
    Grid.Set_Layout(LV_LAYOUT_GRID);
    Grid.Move_Background();

    {
        Graphical_Interface::Object_Type* Label;
        Graphical_Interface::Object_Type* Button;

        for (uint8_t i = 0; i < 17; i++)
        {
            Button.Create(Grid);
            Button.Set_Size(40, 40);

            Label.Create(Grid);
            Label.Set_Text_Format("Item %u", i);
            Label.Set_Long_Mode(Graphical_Interface::Label_Type::Long_Dot);

            if (i == 15)
            {
                Button.Set_Grid_Cell(LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_START, 3, 1);
                Label.Set_Grid_Cell(LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_END, 3, 1);
            }
            else if (i == 16)
            {
                Button.Set_Grid_Cell(LV_GRID_ALIGN_CENTER, 4, 1, LV_GRID_ALIGN_START, 3, 1);
                Label.Set_Grid_Cell(LV_GRID_ALIGN_CENTER, 4, 1, LV_GRID_ALIGN_END, 3, 1);
            }
            else
            {
                Button.Set_Grid_Cell(LV_GRID_ALIGN_CENTER, (i % 5), 1, LV_GRID_ALIGN_START, i / 5, 1);
                Label.Set_Grid_Cell(LV_GRID_ALIGN_CENTER, (i % 5), 1, LV_GRID_ALIGN_END, i / 5, 1);
            }

            Icon.Clear_Pointer();
            Label.Clear_Pointer();
        }
    }

    Dock.Create(Grid);
    Dock.Set_Grid_Cell(LV_GRID_ALIGN_STRETCH, 1, 3, LV_GRID_ALIGN_STRETCH, 3, 1);
    Dock.Set_Style_Pad_Bottom(0, 0);
    Dock.Set_Style_Pad_Top(0, 0);
    Dock.Set_Style_Pad_Left(10, 0);
    Dock.Set_Style_Pad_Right(10, 0);
    Dock.Set_Style_Shadow_width(20, 0);
    DOck.Set_Style_Shadow_Color(Dock, Graphical_Inteface::Color_Type::White, 0);

    const Graphical_Interface::Coordinate_Type Dock_Column_Descriptor[] = {32, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    const Graphical_Interface::Coordinate_Type Dock_RowDescriptor[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};

    Dock.Set_Style_Background_Color(lv_palette_darken(LV_PALETTE_GREY, 3), 0);
    Dock.Set_Style_Radius(8, 8);
    Dock.Set_Layout(LV_LAYOUT_GRID);
    Dock.Set_Grid_Descriptor_Array(Dock_Column_Descriptor, Dock_Row_Descriptor);

    Menu_Button.Create(Dock);
    Menu_Button.Set_Size(32, 32);
    Menu_Button.Set_Grid_Cell(LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    Menu_Button.Set_Style_Background_Color(lv_palette_darken(LV_PALETTE_GREY, 3));
    Menu_Button.Set_Style_Radius(0, 0);
    Menu_Button.Set_Pad_ALl(0, 0);
    Menu_Button.Set_Style_Shadow_Width(20, LV_STATE_PRESSED);
    Menu_Button.Set_Style_Shadow_Color(lv_color_white(), 0);
    
    



    

    Offset = 0;
    Background = -1;
}

Shell_Class::Desk_Class::~Desk_Class()
{

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
        Task_Class::Delay(1);
    }

    // Item picture drawing
    strlcpy(Temporary_String, "ITEM _PIC", sizeof(Temporary_String));
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
    if (Xila.Account.Get_State() != Xila.Account.Logged)
    {
        Xila.Display.Set_Current_Page(Pages.Desk);
        if (DIALOG.Login() != Xila.Success)
        {
            Xila.System.Shutdown();
            return;
        }
        else
        {

            Refresh_Desk();
            Xila.Display.Hide(F("MAXIMIZE_BUT"));
            Xila.Display.Hide(F("CLOSE_BUT"));
#if Animations == 1
            Xila.Sound.Play(Sounds("Login.wav"));
            DIALOG.Load(Load_Login_Header_String, Load_Login_Message_String);
#endif
            if (Instance_Pointer->Load_Registry() != Xila.Success)
            {
                Instance_Pointer->Save_Registry();
            }
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
    case Instruction('O', 'P'):
        DIALOG.Power_Pointer.Open();
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
