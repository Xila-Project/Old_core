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
    Window.Create(Shell_Pointer);
    Window.Set_Title("Desk");

    // Overlay

    Overlay.Create(Window);
    Overlay.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Overlay.Set_Size(18 * 8, 32);
    Overlay.Set_Alignment(Alignment_Type::Top_Right);

    Clock_Label.Create(Overlay);
    Clock_Label.Set_Alignment(Alignment_Type::Middle_Right);
    Clock_Label.Set_Text("00:00");

    Battery_Button.Create(Overlay);
    Battery_Button.Set_Alignment(Clock_Label, Alignment_Type::Out_Left_Middle, -4, 0);
    Battery_Button.Set_Size(24, 24);
    Battery_Button.Set_Style_Border_Width(0, 0);
    Battery_Button.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Clicked);

    Battery_Image.Create(Battery_Button);
    Battery_Image.Set_Source(LV_SYMBOL_BATTERY_FULL);
    Battery_Image.Set_Alignment(Alignment_Type::Center);

    Sound_Button.Create(Overlay);
    Sound_Button.Set_Alignment(Battery_Button, Alignment_Type::Out_Left_Middle, -4, 0);
    Sound_Button.Set_Size(24, 24);
    Sound_Button.Set_Style_Border_Width(0, 0);
    Sound_Button.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Clicked);

    Sound_Image.Create(Sound_Button);
    Sound_Image.Set_Source(LV_SYMBOL_AUDIO);
    Sound_Image.Set_Alignment(Alignment_Type::Center);

    WiFi_Button.Create(Overlay);
    WiFi_Button.Set_Alignment(Sound_Button, Alignment_Type::Out_Left_Middle, -4, 0);
    WiFi_Button.Set_Size(24, 24);
    WiFi_Button.Set_Style_Border_Width(0, 0);
    WiFi_Button.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Clicked);

    WiFi_Image.Create(WiFi_Button);
    WiFi_Image.Set_Source(LV_SYMBOL_WIFI);
    WiFi_Image.Set_Alignment(Alignment_Type::Center);

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
        Graphics_Types::Label_Type Label;
        Object_Type Icon;

        for (uint8_t i = 0; i < 17; i++)
        {
            Icon.Create(Desk_Grid);
            Icon.Set_Size(40, 40);

            Label.Create(Desk_Grid);
            Label.Set_Text_Format("Item %u", i);
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
        Red_Part.Add_Style(Menu_Button_Part_Pressed_Style, Part_Type::Main | Graphics_Types::State_Type::Pressed);
        Red_Part.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Pressed);
    }
    {
        Object_Type Blue_Part;
        Blue_Part.Create(Menu_Button);
        Blue_Part.Set_Size(21, 10);
        Blue_Part.Set_Style_Background_Color(Color_Type::Blue[5], 0);
        Blue_Part.Set_Alignment(Alignment_Type::Bottom_Left);
        Blue_Part.Add_Style(Menu_Button_Part_Style, 0);
        Blue_Part.Add_Style(Menu_Button_Part_Pressed_Style, Part_Type::Main | Graphics_Types::State_Type::Pressed);
        Blue_Part.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Pressed);
    }
    {
        Object_Type Green_Part;
        Green_Part.Create(Menu_Button);
        Green_Part.Set_Size(10, 21);
        Green_Part.Set_Style_Background_Color(Color_Type::Green[5], 0);
        Green_Part.Set_Alignment(Alignment_Type::Bottom_Right);
        Green_Part.Add_Style(Menu_Button_Part_Style, 0);
        Green_Part.Add_Style(Menu_Button_Part_Pressed_Style, Part_Type::Main | Graphics_Types::State_Type::Pressed);
        Green_Part.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Pressed);
    }
    {
        Object_Type Yellow_Part;
        Yellow_Part.Create(Menu_Button);
        Yellow_Part.Set_Size(21, 10);
        Yellow_Part.Set_Style_Background_Color(Color_Type::Yellow[5], 0);
        Yellow_Part.Set_Alignment(Alignment_Type::Top_Right);
        Yellow_Part.Add_Style(Menu_Button_Part_Style, 0);
        Yellow_Part.Add_Style(Menu_Button_Part_Pressed_Style, Part_Type::Main | Graphics_Types::State_Type::Pressed);
        Yellow_Part.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Pressed);
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
    // TODO : Refresh desk icons and dock software
    // Delete grid items except the dock.

    // - Refresh dock software list.

    // If there are too many buttons, delete some.
    while (Dock_List.Get_Child_Count() > Softwares.Get_User_Softwares_Count(Shell_Pointer->Get_Owner_User()))
    {
        Dock_List.Get_Child(Dock_List.Get_Child_Count() - 1).Delete();
    }
    // If there is not enough buttons, create more.
    {
        Button_Type Button;
        Graphics_Types::Label_Type Label;
        while (Dock_List.Get_Child_Count() < Softwares.Get_User_Softwares_Count(Shell_Pointer->Get_Owner_User()))
        {
            Button.Create(Dock_List);
            Button.Set_Size(40, 40);
            Button.Set_Style_Border_Width(0, 0);
            Button.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Pressed);
            Button.Clear_Pointer();

            Label.Create(Button);
            Label.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Pressed);
            Label.Set_Alignment(Alignment_Type::Center);
            Label.Clear_Pointer();
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

/// @brief Refresh the header overlay.
void Shell_Class::Desk_Class::Refresh_Overlay()
{
    // - Refresh clock
    static Time_Type Current_Time = System.Get_Time();

    Clock_Label.Set_Text_Format("%02d:%02d", Current_Time.Get_Hours(), Current_Time.Get_Minutes());

    if (WiFi.Get_Mode() == WiFi_Types::Mode_Type::Station && WiFi.Station.Get_Status() == WiFi_Types::Status_Type::Connected)
    {
        // - Update WiFi signal strength
        // TODO : Add different WiFi signal strength icons.
        if (WiFi.Station.Get_RSSI() >= (-120 / 3))
        {
            WiFi_Image.Set_Source(LV_SYMBOL_WIFI);
        }
        else if (WiFi.Station.Get_RSSI() >= (-120 * 2 / 3))
        {
            WiFi_Image.Set_Source(LV_SYMBOL_WIFI);
        }
        else
        {
            WiFi_Image.Set_Source(LV_SYMBOL_WIFI);
        }
    }
    else if (WiFi.Get_Mode() == WiFi_Types::Mode_Type::Access_Point)
    {
        WiFi_Image.Set_Source(LV_SYMBOL_WIFI);
    }
    else
    {
        WiFi_Image.Set_Source(LV_SYMBOL_WIFI);
    }

    // - Update charge level
    if (Power.Get_Charge_Level() >= 85)
    {
        Battery_Image.Set_Source(LV_SYMBOL_BATTERY_FULL);
    }
    else if (Power.Get_Charge_Level() >= 60)
    {
        Battery_Image.Set_Source(LV_SYMBOL_BATTERY_3);
    }
    else if (Power.Get_Charge_Level() >= 35)
    {
        Battery_Image.Set_Source(LV_SYMBOL_BATTERY_2);
    }
    else if (Power.Get_Charge_Level() >= 10)
    {
        Battery_Image.Set_Source(LV_SYMBOL_BATTERY_1);
    }
    else
    {
        Battery_Image.Set_Source(LV_SYMBOL_BATTERY_EMPTY);
    }

    // -- Update sound
    if (Sound.Get_Volume() >= (255 * 2 / 3))
    {
        Sound_Image.Set_Source(LV_SYMBOL_VOLUME_MAX);
    }
    else if (Sound.Get_Volume() >= (255 / 3))
    {
        Sound_Image.Set_Source(LV_SYMBOL_VOLUME_MID);
    }
    else
    {
        Sound_Image.Set_Source(LV_SYMBOL_MUTE);
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
        break;
        default:
            break;
        }
    }
}