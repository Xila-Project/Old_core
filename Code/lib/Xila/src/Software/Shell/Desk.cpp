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
    // Window
    Window.Create();
    Window.Set_Title("Desk");

    // Grid for icons
    const Object_Type::Coordinate_Type Grid_Column_Descriptor[6] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    const Object_Type::Coordinate_Type Grid_Row_Descriptor[5] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};

    Grid.Create(Window.Get_Body());
    Grid.Set_Style_Pad_All(10, 0);
    Grid.Set_Style_Background_Opacity(0, 0);
    Grid.Set_Grid_Descriptor_Array(Grid_Column_Descriptor, Grid_Row_Descriptor);
    Grid.Set_Size(LV_PCT(100), LV_PCT(100));
    Grid.Set_Layout(LV_LAYOUT_GRID);
    Grid.Move_Background();

    {
        Label_Type Label;
        Object_Type Icon;

        for (uint8_t i = 0; i < 17; i++)
        {
            Icon.Create(Grid);
            Icon.Set_Size(40, 40);

            Label.Create(Grid);
            Label.Set_Text_Format("Item %u", i);
            Label.Set_Long_Mode(Label_Type::Long_Dot);

            if (i == 15)
            {
                Icon.Set_Grid_Cell(Object_Class::Grid::Center, 0, 1, Object_Class::Grid::Start, 3, 1);
                Label.Set_Grid_Cell(Object_Class::Grid::Center, 0, 1, Object_Class::Grid::End, 3, 1);
            }
            else if (i == 16)
            {
                Icon.Set_Grid_Cell(Object_Class::Grid::Center, 4, 1, Object_Class::Grid::Start, 3, 1);
                Label.Set_Grid_Cell(Object_Class::Grid::Center, 4, 1, Object_Class::Grid::End, 3, 1);
            }
            else
            {
                Icon.Set_Grid_Cell(Object_Class::Grid::Center, (i % 5), 1, Object_Class::Grid::Start, i / 5, 1);
                Label.Set_Grid_Cell(Object_Class::Grid::Center, (i % 5), 1, Object_Class::Grid::End, i / 5, 1);
            }

            Icon.Clear_Pointer();
            Label.Clear_Pointer();
        }
    }

    Dock.Create(Grid);
    Dock.Set_Grid_Cell(Object_Class::Grid::Stretch, 1, 3, Object_Class::Grid::Stretch, 3, 1);
    Dock.Set_Style_Pad_Bottom(0, 0);
    Dock.Set_Style_Pad_Top(0, 0);
    Dock.Set_Style_Pad_Left(10, 0);
    Dock.Set_Style_Pad_Right(10, 0);
    Dock.Set_Style_Shadow_Width(20, 0);
    Dock.Set_Style_Shadow_Color(Object_Type::Color_Type::White, 0);

    const Object_Type::Coordinate_Type Dock_Column_Descriptor[] = {32, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    const Object_Type::Coordinate_Type Dock_Row_Descriptor[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};

    Dock.Set_Style_Background_Color(lv_palette_darken(LV_PALETTE_GREY, 3), 0);
    Dock.Set_Style_Radius(8, 8);
    Dock.Set_Layout(LV_LAYOUT_GRID);
    Dock.Set_Grid_Descriptor_Array(Dock_Column_Descriptor, Dock_Row_Descriptor);

    Menu_Button.Create(Dock);
    Menu_Button.Set_Size(32, 32);
    Menu_Button.Set_Grid_Cell(Object_Type::Grid::Center, 0, 1, Object_Type::Grid::Center, 0, 1);
    Menu_Button.Set_Style_Background_Color(lv_palette_darken(LV_PALETTE_GREY, 3));
    Menu_Button.Set_Style_Radius(0, 0);
    Menu_Button.Set_Style_Pad_All(0, 0);
    Menu_Button.Set_Style_Shadow_Width(20, LV_STATE_PRESSED);
    Menu_Button.Set_Style_Shadow_Color(lv_color_white(), 0);

    Background_Color.Set_Color();

    Object_Type::Style_Type Menu_Button_Part_Style;
    Menu_Button_Part_Style.Initialize();
    Menu_Button_Part_Style.Set_Pad_All(0);
    Menu_Button_Part_Style.Set_Radius(0);
    Menu_Button_Part_Style.Set_Outline_Width(0);
    Menu_Button_Part_Style.Set_Border_Width(0);

    Object_Type::Style_Type Menu_Button_Part_Pressed_Style;
    Menu_Button_Part_Pressed_Style.Initialize();
    Menu_Button_Part_Pressed_Style.Set_Background_Color(Object_Type::Color_Type::Get_From_Palette(White, 0));
    Menu_Button_Part_Pressed_Style.Set_Shadow_Width(15);
    Menu_Button_Part_Pressed_Style.Set_Shadow_Color(Object_Type::Color_Type::Get_From_Palette(White, 0));

    {
        Object_Type Red_Part;
        Red_Part.Create(Menu_Button);
        Red_Part.Set_Size(10, 21);
        Red_Part.Set_Style_Radius(0, 0);
        Red_Part.Set_Style_Background_Color(Object_Type::Color_Type::Get_From_Palette(Xila_Red, 0), 0)
            Red_Part.Set_Alignment(Object_Type::Alignment::Top_Left);
        Red_Part.Add_Style(Menu_Button_Part_Style, 0);
        Red_Part.Add_Style(Menu_Button_Part_Pressed_Style, Object_Type::State::Pressed);
    }
    {
        Object_Type Blue_Part;
        Blue_Part.Create(Menu_Button);
        Blue_Part.Set_Size(21, 10);
        Blue_Part.Set_Style_Background_Color(Object_Type::Color_Type::Get_From_Palette(Xila_Blue, 0), 0);
        Blue_Part.Set_Alignment(Object_Type::Alignment::Bottom_Left);
        Blue_Part.Add_Style(Menu_Button_Part_Style, 0);
        Blue_Part.Add_Style(Menu_Button_Part_Pressed_Style, Object_Type::State::Pressed);
    }
    {
        Object_Type Green_Part;
        Green_Part.Create(Menu_Button);
        Green_Part.Set_Size(10, 21);
        Green_Part.Set_Style_Background_Color(Object_Type::Color_Type::Get_From_Palette(Xila_Green, 0), 0);
        Green_Part.Set_Alignment(Object_Type::Alignment::Bottom_Right);
        Green_Part.Add_Style(Menu_Button_Part_Style, 0);
        Green_Part.Add_Style(Menu_Button_Part_Pressed_Style, Object_Type::State::Pressed);
    }
    {
        Object_Type Yellow_Part;
        Yellow_Part.Create(Menu_Button);
        Yellow_Part.Set_Size(21, 10);
        Yellow_Part.Set_Style_Background_Color(Object_Type::Color_Type::Get_From_Palette(Xila_Yellow, 0), 0);
        Yellow_Part.Set_Alignment(Object_Type::Alignment::Top_Right);
        Yellow_Part.Add_Style(Menu_Button_Part_Style, 0);
        Yellow_Part.Add_Style(Menu_Button_Part_Pressed_Style, Object_Type::State::Pressed);
    }
    Object_Type List;
    List.Set_Grid_Cell(Object_Type::Grid::Stretch, 1, 1, Object_Type::Grid::Stretch, 0, 1);
    List.Set_Flex_Flow(Object_Type::Flex_Flow::Row);
    List.Set_Style_Background_Color(Object_Type::Color_Type::Get_From_Palette(Color_Type::Grey, -1), 0);
    List.Set_Style_Border_Width(0, 0);
    List.Set_Style_Pad_All(0, 0);
    List.Set_Content_Height(40);

    {
        Button_Type Button;
        Label_Type Label;
        for (uint8_t i = 0; i < 8; i++)
        {
            Button.Create(List);
            Button.Set_Size(40, 40);
            Button.Set_Style_Border_Width(0, 0);
            Button.Clear_Pointer();

            Label.Create(List);
            Label.Set_Text_Format("A %u", i);
            Label.Set_Alignment(Object_Type::Alignment::Center);
        }
    }
}

Shell_Class::Desk_Class::~Desk_Class()
{
    Grid.Delete();
    Dock.Delete();
    Menu_Button.Delete();
    Window.Delete();
}

void Shell_Class::Desk_Class::Logout()
{
    if (Account.Current_Username[0] != '\0')
    {
        Instance_Pointer->Save_Registry();
    }
    Account.Logout();

    DESK.Open(Pages.Desk);
}

// -- Drawer -- //

// -- Desk -- //

void Shell_Class::Desk_Class::Open(uint8_t Mode)
{
    if (Account.Get_State() != Account.Logged)
    {
        Display.Set_Current_Page(Pages.Desk);
        if (DIALOG.Login() != Success)
        {
            System.Shutdown();
            return;
        }
        else
        {

            Refresh_Desk();
            Display.Hide(F("MAXIMIZE_BUT"));
            Display.Hide(F("CLOSE_BUT"));
#if Animations == 1
            Sound.Play(Sounds("Login.wav"));
            DIALOG.Load(Load_Login_Header_String, Load_Login_Message_String);
#endif
            if (Instance_Pointer->Load_Registry() != Success)
            {
                Instance_Pointer->Save_Registry();
            }
        }
    }

    if (Mode == Pages.Drawer)
    {
        Display.Set_Current_Page(Pages.Drawer);
        Offset = 0;
        Refresh_Drawer();
        return;
    }
    else
    {
        Display.Set_Current_Page(Pages.Desk);
        Refresh_Desk();
        Display.Hide(F("MAXIMIZE_BUT"));
        Display.Hide(F("CLOSE_BUT"));
        return;
    }
}

void Shell_Class::Desk_Class::Refresh_Desk()
{
    if (DESK.Background == -1)
    {
        Display.Hide(F("COLORB_TXT"));
        Display.Show(F("IMAGEB_TXT"));
    }
    else
    {
        Display.Set_Background_Color(F("COLORB_TXT"), DESK.Background);
        Display.Hide(F("IMAGEB_TXT"));
        Display.Show(F("COLORB_TXT"));
    }

    Display.Refresh(F("0"));

    char Temporary_String[] = "SLOT _PIC";

    // List all running app on the task bar
    for (uint8_t Slot = 2; Slot < 8; Slot++)
    {
        Temporary_String[4] = Slot - 1 + '0';
        if (Software_Management.Openned[Slot] != NULL)
        {
            Display.Set_Picture(Temporary_String, Software_Management.Openned[Slot]->Handle->Icon);
        }
        else
        {
            Display.Hide(Temporary_String);
        }
    }
}

void Shell_Class::Desk_Class::Execute_Desk_Instruction(Instruction_Type Instruction)
{
    switch (Instruction.Get_Arguments())
    {
    case Instruction('M', '1'):
        Maximize_Dock_Software(1);
        break;
    case Instruction('M', '2'):
        Maximize_Dock_Software(2);
        break;
    case Instruction('M', '3'):
        Maximize_Dock_Software(3);
        break;
    case Instruction('M', '4'):
        Maximize_Dock_Software(4);
        break;
    case Instruction('M', '5'):
        Maximize_Dock_Software(5);
        break;
    case Instruction('M', '6'):
        Maximize_Dock_Software(6);
        break;
    case Instruction('C', '1'):
        Close_Dock_Software(1);
        break;
    case Instruction('C', '2'):
        Close_Dock_Software(2);
        break;
    case Instruction('C', '3'):
        Close_Dock_Software(3);
        break;
    case Instruction('C', '4'):
        Close_Dock_Software(4);
        break;
    case Instruction('C', '5'):
        Close_Dock_Software(5);
        break;
    case Instruction('C', '6'):
        Close_Dock_Software(6);
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

void Shell_Class::Desk_Class::Maximize_Dock_Software(uint8_t Slot)
{
    if (Software_Management.Openned[Slot + 1] == NULL)
    {
        return;
    }
    Software_Management.Maximize(*Software_Management.Openned[Slot + 1]->Handle);
}

void Shell_Class::Desk_Class::Close_Dock_Software(uint8_t Slot)
{
    if (Software_Management.Openned[Slot + 1] == NULL)
    {
        return;
    }
    Software_Management.Close(*Software_Management.Openned[Slot + 1]->Handle);
}