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

Shell_Class::Desk_Class::Desk_Class(Shell_Class *Shell_Pointer) : Shell_Pointer(Shell_Pointer)
{
    // Window
    Shell_Pointer->Screen.Load();
    Window.Create(Shell_Pointer->Screen);
    Task_Type::Delay_Static(100);
    Log_Verbose("Desk", "Desk window created : %p", Window.Get_Pointer());
    Window.Set_Title("Desk");

    // Grid for icons
    const Coordinate_Type Grid_Column_Descriptor[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    const Coordinate_Type Grid_Row_Descriptor[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};

    // Create grid
    Desk_Grid.Create(Window.Get_Body());
    Desk_Grid.Set_Style_Pad_All(10, 0);
    Desk_Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Desk_Grid.Set_Size(Percentage(100), Percentage(100));
    Desk_Grid.Set_Grid_Descriptor_Array(Grid_Column_Descriptor, Grid_Row_Descriptor);
    Desk_Grid.Move_Background();

    // - Desk icons
    {
        Graphics_Types::Label_Type Label;
        Object_Type Icon;

        for (uint8_t i = 0; i < 17; i++)
        {
            Icon.Create(Desk_Grid);
            Icon.Set_Size(40, 40);

            Label.Create(Desk_Grid);
            Label.Set_Text_Format("Item", i);
            Label.Set_Long_Mode(Graphics_Types::Long_Type::Dot);

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

            Icon.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Clicked);
            Label.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Clicked);

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
    Dock.Set_Style_Background_Color(Color_Type::Grey[8], 0);
    Dock.Set_Style_Radius(8, 0);

    // - - Dock's grid layout
    Dock.Set_Flex_Flow(Flex_Flow_Type::Row);
    Dock.Set_Flex_Alignment(Flex_Alignment_Type::Center, Flex_Alignment_Type::Center, Flex_Alignment_Type::Center);

    // - Menu button
    static Style_Type Menu_Button_Style;
    Menu_Button_Style.Initialize();
    Menu_Button_Style.Set_Pad_All(0);
    Menu_Button_Style.Set_Background_Opacity(Opacity_Type::Transparent);

    Menu_Button.Create(Dock);
    Menu_Button.Set_Size(32, 32);
    Menu_Button.Add_Style(Menu_Button_Style, 0);
    Menu_Button.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Clicked);

    static Style_Type Menu_Button_Part_Style;
    Menu_Button_Part_Style.Initialize();
    Menu_Button_Part_Style.Set_Pad_All(0);
    Menu_Button_Part_Style.Set_Radius(0);
    Menu_Button_Part_Style.Set_Outline_Width(0);
    Menu_Button_Part_Style.Set_Border_Width(0);


    static Style_Type Menu_Button_Part_Pressed_Style;
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
        Red_Part.Add_Style(Menu_Button_Part_Pressed_Style, Part_Type::Main | Graphics_Types::State_Type::Pressed);
        Red_Part.Add_Flag(Flag_Type::Event_Bubble);
    }
    {
        Object_Type Blue_Part;
        Blue_Part.Create(Menu_Button);
        Blue_Part.Set_Size(21, 10);
        Blue_Part.Set_Style_Background_Color(Color_Type::Blue[5], 0);
        Blue_Part.Set_Alignment(Alignment_Type::Bottom_Left);
        Blue_Part.Add_Style(Menu_Button_Part_Style, 0);
        Blue_Part.Add_Style(Menu_Button_Part_Pressed_Style, Part_Type::Main | Graphics_Types::State_Type::Pressed);
        Blue_Part.Add_Flag(Flag_Type::Event_Bubble);
    }
    {
        Object_Type Green_Part;
        Green_Part.Create(Menu_Button);
        Green_Part.Set_Size(10, 21);
        Green_Part.Set_Style_Background_Color(Color_Type::Green[5], 0);
        Green_Part.Set_Alignment(Alignment_Type::Bottom_Right);
        Green_Part.Add_Style(Menu_Button_Part_Style, 0);
        Green_Part.Add_Style(Menu_Button_Part_Pressed_Style, Part_Type::Main | Graphics_Types::State_Type::Pressed);
        Green_Part.Add_Flag(Flag_Type::Event_Bubble);
    }
    {
        Object_Type Yellow_Part;
        Yellow_Part.Create(Menu_Button);
        Yellow_Part.Set_Size(21, 10);
        Yellow_Part.Set_Style_Background_Color(Color_Type::Yellow[5], 0);
        Yellow_Part.Set_Alignment(Alignment_Type::Top_Right);
        Yellow_Part.Add_Style(Menu_Button_Part_Style, 0);
        Yellow_Part.Add_Style(Menu_Button_Part_Pressed_Style, Part_Type::Main | Graphics_Types::State_Type::Pressed);
        Yellow_Part.Add_Flag(Flag_Type::Event_Bubble);
    }

    Dock_List.Create(Dock);
    Dock_List.Set_Flex_Grow(1);
    Dock_List.Set_Flex_Flow(Flex_Flow_Type::Row);
    Dock_List.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Dock_List.Set_Style_Border_Width(0, 0);
    Dock_List.Set_Style_Pad_All(0, 0);
    Dock_List.Set_Content_Height(40);

    {
        Static_String_Type<24> User;

        Shell_Pointer->Get_Owner_User()->Get_Name(User);

        if (User == "Xila")
        {
            //    Log_Verbose("Shell", "System user detected, opening login screen / installer.");
            //    File_Type Users_Folder = Drive.Open(Users_Directory_Path);
            //    if (Users_Folder && Users_Folder.Is_Directory() && (Users_Folder.Count_Items() > 0))
            //    {
            //        Shell_Class::Login_Class::Open(Shell_Pointer);
            //    }
            //    else
            //    {
            //        Shell_Class::Installer_Class::Open(Shell_Pointer);
            //    }
            //    // Hide dock since current user is system user (Xila).
            //    Dock.Add_Flag(Flag_Type::Hidden);
        }
    }

    Refresh();
}

Shell_Class::Desk_Class::~Desk_Class()
{
}

Color_Type Shell_Class::Desk_Class::Get_Foreground_Color() const
{
    return Foreground_Color;
}

Color_Type Shell_Class::Desk_Class::Get_Background_Color() const
{
    return Background_Color;
}

void Shell_Class::Desk_Class::Set_Foreground_Color(Color_Type Color)
{
}

void Shell_Class::Desk_Class::Set_Background_Color(Color_Type Color)
{
}

void Shell_Class::Desk_Class::Refresh()
{
    Log_Trace();

    // TODO : Refresh desk icons and dock software
    // Delete grid items except the dock.

    // - If the dock is hidden, do nothing.
    if (Dock.Has_Flag(Flag_Type::Hidden))
    {
        return;
    }
    // - Refresh dock software list.

    // If there are too many buttons, delete some.
    while (Dock_List.Get_Child_Count() > Softwares.Get_User_Softwares_Count(Shell_Pointer->Get_Owner_User() - 1))
    {
        Dock_List.Get_Child(Dock_List.Get_Child_Count() - 1).Delete();
    }
    // If there is not enough buttons, create more.
    {
        Button_Type Button;
        while (Dock_List.Get_Child_Count() < Softwares.Get_User_Softwares_Count(Shell_Pointer->Get_Owner_User() - 1))
        {
            Log_Verbose("Shell", "Shell pointer : %p", Shell_Pointer);
            Button.Create(Dock_List, " ", 40, 40, Shell_Pointer); // Adding a space to force the button to create a label.
            Button.Set_Style_Border_Width(0, 0);
        }
    }
    // - - Set dock software icons.
    {
        Graphics_Types::Label_Type Label;
        const Software_Type *Software_Pointer;
        Static_String_Type<24> Name;

        for (uint8_t i = 0; i < Softwares.Get_User_Softwares_Count(Shell_Pointer->Get_Owner_User()); i++)
        {
            Software_Pointer = Softwares.Get_User_Softwares(Shell_Pointer->Get_Owner_User(), i);
            if (Software_Pointer != Shell_Pointer)
            {
                Software_Pointer->Get_Handle()->Get_Name(Name);
                Name.Set_Character(2, '\0');

                Label = Dock_List.Get_Child(i);
                Label.Set_Text(Name);
                Label.Clear_Pointer();
            }
        }
    }
}


void Shell_Class::Desk_Class::Execute_Instruction(const Instruction_Type &Instruction)
{
    using namespace Graphics_Types;
    if (Instruction.Get_Sender() == &Graphics)
    {
        switch (Instruction.Graphics.Get_Code())
        {
        case Event_Code_Type::Clicked:
        {
            if (Instruction.Graphics.Get_Object() == Menu_Button)
            {
                Log_Verbose("Shell", "Menu button clicked");
                Shell_Class::Drawer_Class::Open(Shell_Pointer);
            }
            else
            {
                // Check if dock button is pressed
                for (uint8_t i = 0; i < Dock_List.Get_Child_Count(); i++)
                {
                    // If one of the dock button is pressed, maximize the windows of corresponding software.
                    if (Desk_Grid.Get_Child(i) == Instruction.Graphics.Get_Object())
                    {
                        const Software_Type *Software_Pointer = Softwares.Get_User_Softwares(Shell_Pointer->Get_Owner_User(), i);
                        // Iterate through all children windows of the parent window.
                        for (uint8_t j = 0; j < Window.Get_Child_Count(); j++)
                        {
                            Window_Type Child_Window = Window.Get_Child(j);
                            // If the window is valid and owned by the software, maximize it.
                            if (Child_Window && (Child_Window.Get_Owner_Software() == Software_Pointer))
                            {
                                Child_Window.Set_State(Window_State_Type::Maximized);
                            }
                        }
                    }
                }
            }
        }
        break;
        default:
            break;
        }
    }
}