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

// - Constructor

Shell_Class::Desk_Class::Desk_Class(Shell_Class* Shell_Pointer) : Shell_Pointer(Shell_Pointer)
{
    // Window
    Window.Create(Account.Get_Logged_User());
    Window.Set_Title("Desk");

    // Grid for icons
    const Coordinate_Type Grid_Column_Descriptor[6] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    const Coordinate_Type Grid_Row_Descriptor[5] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};

    // Create grid
    Desk_Grid.Create(Window.Get_Body());
    Desk_Grid.Set_Style_Pad_All(10, 0);
    Desk_Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Desk_Grid.Set_Grid_Descriptor_Array(Grid_Column_Descriptor, Grid_Row_Descriptor);
    Desk_Grid.Set_Size(LV_PCT(100), LV_PCT(100));
    Desk_Grid.Set_Layout(LV_LAYOUT_GRID);
    Desk_Grid.Move_Background();

    // - Desk icons
    {
        Label_Type Label;
        Object_Type Icon;

        for (uint8_t i = 0; i < 17; i++)
        {
            Icon.Create(Desk_Grid);
            Icon.Set_Size(40, 40);

            Label.Create(Desk_Grid);
            Label.Set_Text_Format("Item %u", i);
            Label.Set_Long_Mode(Label_Type::Long_Dot);

            if (i == 15)
            {
                Icon.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 1, Grid_Alignment_Type::Start, 3, 1);
                Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 1, Grid_Alignment_Type::End, 3, 1);
            }
            else if (i == 16)
            {
                Icon.Set_Grid_Cell(Grid_Alignment_Type::Center, 4, 1, Grid_Alignment_Type::Start, 3, 1);
                Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 4, 1, Grid_Alignment_Type::End, 3, 1);
            }
            else
            {
                Icon.Set_Grid_Cell(Grid_Alignment_Type::Center, (i % 5), 1, Grid_Alignment_Type::Start, i / 5, 1);
                Label.Set_Grid_Cell(Grid_Alignment_Type::Center, (i % 5), 1, Grid_Alignment_Type::End, i / 5, 1);
            }

            Icon.Add_Event(Shell_Pointer, Graphics_Type::Event_Code_Type::Pressed);
            Label.Add_Event(Shell_Pointer, Graphics_Type::Event_Code_Type::Pressed);

            Icon.Clear_Pointer();
            Label.Clear_Pointer();
        }
    }

    // - Dock
    Dock.Create(Desk_Grid);
    // - - Dock's style
    Dock.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 1, 3, Grid_Alignment_Type::Stretch, 3, 1);
    Dock.Set_Style_Pad_Bottom(0, 0);
    Dock.Set_Style_Pad_Top(0, 0);
    Dock.Set_Style_Pad_Left(10, 0);
    Dock.Set_Style_Pad_Right(10, 0);
    Dock.Set_Style_Shadow_Width(20, 0);
    Dock.Set_Style_Shadow_Color(Color_Type::White, 0);
    Dock.Set_Style_Background_Color(lv_palette_darken(LV_PALETTE_GREY, 3), 0);
    Dock.Set_Style_Radius(8, 8);
    // - - Dock's grid layout
    const Coordinate_Type Dock_Column_Descriptor[] = {32, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    const Coordinate_Type Dock_Row_Descriptor[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    Dock.Set_Layout(LV_LAYOUT_GRID);
    Dock.Set_Grid_Descriptor_Array(Dock_Column_Descriptor, Dock_Row_Descriptor);

    // - Menu button
    Menu_Button.Create(Dock);
    Menu_Button.Set_Size(32, 32);
    Menu_Button.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 1, Grid_Alignment_Type::Center, 0, 1);
    Menu_Button.Set_Style_Background_Color(Color_Type::Grey[2], 0);
    Menu_Button.Set_Style_Radius(0, 0);
    Menu_Button.Set_Style_Pad_All(0, 0);
    Menu_Button.Set_Style_Shadow_Width(20, LV_STATE_PRESSED);
    Menu_Button.Set_Style_Shadow_Color(lv_color_white(), 0);

    Object_Type::Style_Type Menu_Button_Part_Style;
    Menu_Button_Part_Style.Initialize();
    Menu_Button_Part_Style.Set_Pad_All(0);
    Menu_Button_Part_Style.Set_Radius(0);
    Menu_Button_Part_Style.Set_Outline_Width(0);
    Menu_Button_Part_Style.Set_Border_Width(0);

    Object_Type::Style_Type Menu_Button_Part_Pressed_Style;
    Menu_Button_Part_Pressed_Style.Initialize();
    Menu_Button_Part_Pressed_Style.Set_Background_Color(Color_Type::White);
    Menu_Button_Part_Pressed_Style.Set_Shadow_Width(15);
    Menu_Button_Part_Pressed_Style.Set_Shadow_Color(Color_Type::White);

    {
        Object_Type Red_Part;
        Red_Part.Create(Menu_Button);
        Red_Part.Set_Size(10, 21);
        Red_Part.Set_Style_Radius(0, 0);
        Red_Part.Set_Style_Background_Color(Color_Type::Red[5], 0);
        Red_Part.Set_Alignment(Alignment_Type::Top_Left);
        Red_Part.Add_Style(Menu_Button_Part_Style, 0);
        Red_Part.Add_Style(Menu_Button_Part_Pressed_Style, Object_Type::Part_Type::Main | Graphics_Types::State_Type::Pressed);
        Red_Part.Add_Event(Shell_Pointer, Graphics_Type::Event_Code_Type::Pressed);
    }
    {
        Object_Type Blue_Part;
        Blue_Part.Create(Menu_Button);
        Blue_Part.Set_Size(21, 10);
        Blue_Part.Set_Style_Background_Color(Color_Type::Blue[5], 0);
        Blue_Part.Set_Alignment(Alignment_Type::Bottom_Left);
        Blue_Part.Add_Style(Menu_Button_Part_Style, 0);
        Blue_Part.Add_Style(Menu_Button_Part_Pressed_Style, Object_Type::Part_Type::Main | Graphics_Types::State_Type::Pressed);
        Blue_Part.Add_Event(Shell_Pointer, Graphics_Type::Event_Code_Type::Pressed);
    }
    {
        Object_Type Green_Part;
        Green_Part.Create(Menu_Button);
        Green_Part.Set_Size(10, 21);
        Green_Part.Set_Style_Background_Color(Color_Type::Green[5], 0);
        Green_Part.Set_Alignment(Alignment_Type::Bottom_Right);
        Green_Part.Add_Style(Menu_Button_Part_Style, 0);
        Green_Part.Add_Style(Menu_Button_Part_Pressed_Style, Object_Type::Part_Type::Main | Graphics_Types::State_Type::Pressed);
        Green_Part.Add_Event(Shell_Pointer, Graphics_Type::Event_Code_Type::Pressed);
    }
    {
        Object_Type Yellow_Part;
        Yellow_Part.Create(Menu_Button);
        Yellow_Part.Set_Size(21, 10);
        Yellow_Part.Set_Style_Background_Color(Color_Type::Yellow[5], 0);
        Yellow_Part.Set_Alignment(Alignment_Type::Top_Right);
        Yellow_Part.Add_Style(Menu_Button_Part_Style, 0);
        Yellow_Part.Add_Style(Menu_Button_Part_Pressed_Style, Object_Type::Part_Type::Main | Graphics_Types::State_Type::Pressed);
        Yellow_Part.Add_Event(Shell_Pointer, Graphics_Type::Event_Code_Type::Pressed);
    }

    Dock_List.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 1, 1, Grid_Alignment_Type::Stretch, 0, 1);
    Dock_List.Set_Flex_Flow(Flex_Flow_Type::Row);
    Dock_List.Set_Style_Background_Color(Color_Type::Grey[6], 0);
    Dock_List.Set_Style_Border_Width(0, 0);
    Dock_List.Set_Style_Pad_All(0, 0);
    Dock_List.Set_Content_Height(40);

    Refresh();
}

Shell_Class::Desk_Class::~Desk_Class()
{
    Desk_Grid.Delete();
    Dock.Delete();
    Menu_Button.Delete();
    Window.Delete();
}

void Shell_Class::Desk_Class::Refresh()
{
    // TODO : Refresh desk icons and dock software
    // Delete grid items except the dock.

    // - Refresh dock software list.

    // If there are too many buttons, delete some.
    while (Dock_List.Get_Child_Count() > (Software_Class::List.size() - 1))
    {
        Dock_List.Get_Child(Dock_List.Get_Child_Count() - 1).Delete();
    }
    // If there is not enough buttons, create more.
    {
        Button_Type Button;
        Label_Type Label;
        while (Dock_List.Get_Child_Count() < (Software_Class::List.size() - 1))
        {
            Button.Create(Dock_List);
            Button.Set_Size(40, 40);
            Button.Set_Style_Border_Width(0, 0);
            Button.Add_Event(Shell_Pointer, Graphics_Type::Event_Code_Type::Pressed);
            Button.Clear_Pointer();

            Label.Create(Button);
            Label.Add_Event(Shell_Pointer, Graphics_Type::Event_Code_Type::Pressed);
            Label.Set_Alignment(Alignment_Type::Center);
            Label.Clear_Pointer();
        }
    }
    // - - Set dock software icons.
    {
        Label_Type Label;
        char Text[3];
        uint8_t i = 0;
        for (auto Software_Pointer : Software_Class::List)
        {
            if (Software_Pointer == Shell_Pointer)
                continue;

            Text[0] = Software_Pointer->Handle_Pointer->Get_Name()[0];
            Text[1] = Software_Pointer->Handle_Pointer->Get_Name()[1];
            Text[2] = '\0';
                        
            Label = Dock_List.Get_Child(i);

            Label.Set_Text(Text);
            Label.Clear_Pointer();

            i++;
        }
    }
}

void Shell_Class::Desk_Class::Execute_Instruction(const Instruction_Type &Instruction)
{
    if (Instruction.Get_Sender() == &Graphics)
    {
        switch (Instruction.Graphics.Get_Code())
        {
        // TODO : Use implicit cast for enum
        case Graphics_Type::Pressed:
            {
                // Check if dock button is pressed
                for (uint8_t i = 0; i < Dock_List.Get_Child_Count(); i++)
                {
                    if (Desk_Grid.Get_Child(i) == Instruction.Graphics.Get_Object())
                    {
                        Instruction_Type Instruction(&Graphics, Software_Class::List[i]);
                        Instruction.Graphics.Set_Code(Graphics_Type::Maximize);
                        Software_Class::List[i]->Send_Instruction(Instruction);
                        break;
                    }
                }
            }
            break;
        default:
            break;
        }
    }
}