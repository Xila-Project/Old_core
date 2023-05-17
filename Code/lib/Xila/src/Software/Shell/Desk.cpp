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

Shell_Class::Desk_Class::Desk_Class(Shell_Class *Shell_Pointer)
    : Shell_Pointer(Shell_Pointer)
{
}

void Shell_Class::Desk_Class::Set_Interface()
{
    using namespace Graphics_Types;

    // Window
    Window.Create(Shell_Pointer);
    Window.Set_Minimize_Button_Hidden(true);
    Window.Set_Title("Desk");

    // - Override close button event handler
    Window.Get_Close_Button().Remove_All_Events();
    Window.Get_Close_Button().Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Clicked);

    // Create grid
    Window.Get_Body().Set_Flex_Flow(Flex_Flow_Type::Column);
    Window.Get_Body().Set_Style_Flex_Cross_Place(Flex_Alignment_Type::Center, 0);
    Window.Get_Body().Set_Style_Pad_Bottom(10, 0);

    Desk_Grid.Create(Window.Get_Body());

    Desk_Grid.Set_Style_Pad_All(10, 0);
    Desk_Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Desk_Grid.Set_Flex_Flow(Flex_Flow_Type::Column_Wrap);
    Desk_Grid.Set_Flex_Alignment(Flex_Alignment_Type::Space_Evenly, Flex_Alignment_Type::Start, Flex_Alignment_Type::Start);

    Desk_Grid.Set_Flex_Grow(1);
    Desk_Grid.Set_Width(Percentage(100));

    // - Dock
    Dock.Create(Window.Get_Body());
    Dock.Set_Size(Percentage(60), 7 * 8);

    // - - Dock's style
    Dock.Set_Style_Pad_Bottom(0, 0);
    Dock.Set_Style_Pad_Top(0, 0);
    Dock.Set_Style_Pad_Left(10, 0);
    Dock.Set_Style_Pad_Right(10, 0);

    // Dock.Set_Style_Shadow_Width(20, 0);   // TODO : Fix shadow width -> crash

    Dock.Set_Style_Shadow_Color(Color_Type::White, 0);
    Dock.Set_Style_Background_Color(Color_Type::Grey[8], 0);
    Dock.Set_Style_Radius(8, 0);
    Dock.Add_Flag(Flag_Type::Overflow_Visible);

    // - - Dock's grid layout
    Dock.Set_Flex_Flow(Flex_Flow_Type::Row);
    Dock.Set_Flex_Alignment(Flex_Alignment_Type::Center, Flex_Alignment_Type::Center, Flex_Alignment_Type::Center);

    Dock_Options.Create(Dock);
    Dock_Options.Add_Flag(Flag_Type::Floating);
    Dock_Options.Add_Flag(Flag_Type::Hidden);
    Dock_Options.Set_Flex_Flow(Flex_Flow_Type::Column);
    Dock_Options.Set_Size(Size_Content, Size_Content);
    Dock_Options.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Dock_Options.Set_Style_Pad_All(0, 0);

    Dock_Close_Button.Create(Dock_Options, "Close", 0, 0, Shell_Pointer);
    Dock_Close_Button.Set_Style_Background_Color(Color_Type::Red[5], 0);
    Dock_Close_Button.Set_Style_Background_Opacity(Opacity_Type::Cover, 0);

    Dock_Maximize_Button.Create(Dock_Options, "Maximize", 0, 0, Shell_Pointer);
    Dock_Maximize_Button.Set_Style_Background_Opacity(Opacity_Type::Cover, 0);
    Dock_Maximize_Button.Set_Style_Background_Color(Color_Type::Green[5], 0);



    // - Menu button
    static Style_Type Menu_Button_Style;
    Menu_Button_Style.Initialize();
    Menu_Button_Style.Set_Pad_All(0);
    Menu_Button_Style.Set_Background_Opacity(Opacity_Type::Transparent);

    Menu_Button.Create(Dock);
    Menu_Button.Set_Size(32, 32);
    Menu_Button.Add_Style(Menu_Button_Style, 0);
    Menu_Button.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Pressed);
    Menu_Button.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Released);
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
    // Menu_Button_Part_Pressed_Style.Set_Shadow_Width(15);
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
        Static_String_Type<24> User_Name;

        Shell_Pointer->Get_Owner_User()->Get_Name(User_Name);

        // - If current user is the system user (Xila), open login screen or installer.
        if (User_Name == "Xila")
        {
            Drive_Types::File_Type Users_Folder = Drive.Open(Users_Directory_Path);

            if (Users_Folder && Users_Folder.Is_Directory() && (Users_Folder.Count_Items() > 0))
                Shell_Class::Login_Class::Open(Shell_Pointer);

            else
                Shell_Class::Installer_Class::Open(Shell_Pointer);

            // Hide dock since current user is system user (Xila).
            Dock.Add_Flag(Flag_Type::Hidden);
            Window.Set_Title("");
        }
    }

    Refresh();
}

Shell_Class::Desk_Class::~Desk_Class()
{
}

const Softwares_Types::Software_Type *Shell_Class::Desk_Class::Get_Software_Pointer_From_Dock(Size_Type Index)
{
    uint8_t User_Softwares_Count = Softwares.Get_User_Softwares_Count(Shell_Pointer->Get_Owner_User());
    for (uint8_t j = 0; j < User_Softwares_Count; j++)
    {
        // - Skip shell instances
        if (Softwares.Get_User_Softwares(Shell_Pointer->Get_Owner_User(), j) == Shell_Pointer)
        {
            Index++;
            j++;
        }

        if (j == Index)
        {
            Log_Verbose("Shell", "Software %u found !", j);
            return Softwares.Get_User_Softwares(Shell_Pointer->Get_Owner_User(), j);
        };
    }
    return NULL;
}

void Shell_Class::Desk_Class::Set_Software_Window_State(const Softwares_Types::Software_Type *Software_Pointer, Graphics_Types::Window_State_Type State)
{
    using namespace Graphics_Types;
    if (!Software_Pointer)
        return;

    Size_Type Screen_Child_Count = Shell_Pointer->Screen.Get_Children_Count();
    for (uint8_t i = 0; i < Screen_Child_Count; i++)
    {
        Window_Type Child_Window = Shell_Pointer->Screen.Get_Child(i);
        if (Child_Window && (Child_Window.Get_Owner_Software() == Software_Pointer))
            Child_Window.Set_State(State);
    }
}

void Shell_Class::Desk_Class::Refresh()
{

    // - Desk icons
    //    {
    //        Object_Type Container;
    //        Graphics_Types::Label_Type Label;
    //        Graphics_Types::Label_Type Icon;
    //
    //        for (uint8_t i = 0; i < 6; i++)
    //        {
    //            Container.Create(Desk_Grid);
    //            Container.Set_Size(10 * 8, 9 * 8);
    //            Container.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    //            Container.Set_Style_Pad_All(0, 0);
    //            Container.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Clicked);
    //
    //            Icon.Create(Container, LV_SYMBOL_DIRECTORY, 5 * 8, 5 * 8);
    //            Icon.Set_Style_Text_Font(&lv_font_montserrat_34, 0);
    //            Icon.Set_Alignment(Alignment_Type::Center);
    //            Icon.Add_Flag(Flag_Type::Event_Bubble);
    //
    //            Label.Create(Container, "Item", Percentage(100));
    //            Label.Set_Long_Mode(Graphics_Types::Long_Type::Dot);
    //            Label.Set_Alignment(Alignment_Type::Bottom_Middle);
    //            Label.Add_Flag(Flag_Type::Event_Bubble);
    //            Label.Set_Style_Text_Alignment(Text_Alignment_Type::Center, 0);
    //
    //            Icon.Clear_Pointer();
    //            Label.Clear_Pointer();
    //            Container.Clear_Pointer();
    //        }
    //    }

    // Delete grid items except the dock.

    // - If the dock is hidden, do nothing.
    Log_Trace();

    if (Dock.Has_Flag(Graphics_Types::Flag_Type::Hidden))
    {
        return;
    }
    // - Refresh dock software list.

    Log_Trace();

    // If there are too many buttons, delete some.

    const uint8_t User_Softwares_Count = Softwares.Get_User_Softwares_Count(Shell_Pointer->Get_Owner_User());

    Log_Verbose("Shell", "User softwares count : %u", User_Softwares_Count);

    while (Dock_List.Get_Children_Count() > (User_Softwares_Count - 1))
    {
        Log_Verbose("Shell", "Deleting dock icon %u", Dock_List.Get_Children_Count() - 1);
        Dock_List.Get_Child(Dock_List.Get_Children_Count() - 1).Delete();
    }

    Log_Trace();

    // If there is not enough icons, create more.
    {
        Graphics_Types::Object_Type Icon_Container;
        Graphics_Types::Label_Type Icon_Label;
        while (Dock_List.Get_Children_Count() < (User_Softwares_Count - 1))
        {

            Log_Verbose("Shell", "Creating dock icon %u", Dock_List.Get_Children_Count());
            Icon_Container.Create(Dock_List);
            Icon_Label.Create(Icon_Container);
            Icon_Container.Set_Alignment(Graphics_Types::Alignment_Type::Top_Middle);
            Icon_Container.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Clicked);
            Icon_Container.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Long_Pressed);

            Icon_Container.Clear_Pointer();
            Icon_Label.Clear_Pointer();
        }
    }


    Log_Trace();

    // - - Set dock software icons.
    {
        Graphics_Types::Object_Type Icon_Container;
        const Softwares_Types::Software_Type *Software_Pointer;
        Static_String_Type<24> Name;

        uint8_t j = 0;
        for (uint8_t i = 0; i < User_Softwares_Count; i++)
        {
            Log_Verbose("Shell", "Dock icon %u", i);
            Software_Pointer = Softwares.Get_User_Softwares(Shell_Pointer->Get_Owner_User(), i);
            if (Software_Pointer && (Software_Pointer != Shell_Pointer))
            {
                Log_Verbose("Shell", "Dock icon %u is not the shell", i);
                Icon_Container = Dock_List.Get_Child(j++); // Get the icon container and increment the counter (after).

                Software_Pointer->Get_Handle()->Get_Name(Name);

                Shell_Class::Get_Software_Icon(Icon_Container, Name);

                Icon_Container.Clear_Pointer();
            }
        }
    }
    Log_Trace();
}

void Shell_Class::Desk_Class::Execute_Instruction(const Instruction_Type &Instruction)
{
    using namespace Graphics_Types;
    if (Instruction.Get_Sender() == &Graphics)
    {
        auto Current_Target = Instruction.Graphics.Get_Current_Target();
        Dock_Options.Add_Flag(Flag_Type::Hidden);
        switch (Instruction.Graphics.Get_Code())
        {
        case Event_Code_Type::Child_Changed:
            if (Current_Target == Shell_Pointer->Screen)
            {
                Refresh();
                Shell_Pointer->Refresh_Overlay();
            }
            break;
        case Event_Code_Type::Pressed:
            if (Current_Target == Menu_Button)
            {
                for (uint8_t i = Menu_Button.Get_Children_Count(); i > 0; i--)
                    Menu_Button.Get_Child(i - 1).Add_State(State_Type::Pressed);
            }
            Ignore_Button.Clear_Pointer();
            break;
        case Event_Code_Type::Released:
            if (Current_Target == Menu_Button)
            {
                for (uint8_t i = Menu_Button.Get_Children_Count(); i > 0; i--)
                    Menu_Button.Get_Child(i - 1).Clear_State(State_Type::Pressed);
            }
            break;
        case Event_Code_Type::Long_Pressed:
            if (Current_Target.Get_Parent() == Dock_List)
            {
                Ignore_Button = Current_Target;
                Dock_Options.Set_Alignment(Alignment_Type::Out_Top_Left, 0, -16, &Current_Target);
                Dock_Options.Clear_Flag(Flag_Type::Hidden);
            }
            break;
        case Event_Code_Type::Clicked:
            if (Current_Target == Menu_Button)
                Shell_Pointer->Drawer.Open();
            else if ((Current_Target == Dock_Close_Button) && Selected_Button)
            {
                Softwares.Close(const_cast<Softwares_Types::Software_Type *>(Get_Software_Pointer_From_Dock(Dock_List.Get_Child_Index(Selected_Button))));
                Refresh();
                Selected_Button.Clear_Pointer();
            }
            else if ((Current_Target == Dock_Maximize_Button) && Selected_Button)
            {
                Set_Software_Window_State(Get_Software_Pointer_From_Dock(Dock_List.Get_Child_Index(Selected_Button)), Window_State_Type::Maximized);
                Selected_Button.Clear_Pointer();
            }
            else if (Current_Target.Get_Parent() == Dock_List)
            {
                if (Current_Target == Ignore_Button)
                {
                    Dock_Options.Clear_Flag(Flag_Type::Hidden); // Discard the hide dock options.
                    Selected_Button = Current_Target;
                }
                else
                    Set_Software_Window_State(Get_Software_Pointer_From_Dock(Dock_List.Get_Child_Index(Current_Target)), Window_State_Type::Maximized);
            }
            else if (Current_Target == Window.Get_Close_Button())
            {
                Shell_Class::Power_Class::Open(*Shell_Pointer);
            }
            Ignore_Button.Clear_Pointer();
            break;
        default:
            break;
        }
    }
}