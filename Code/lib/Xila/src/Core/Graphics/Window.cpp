///
/// @file Window.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Window.hpp"
#include "Core/Account/Accounts.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Methods

// - - Management

/// @brief Function that create a window.
void Window_Class::Create(Module_Type* Owner_Module)
{
    this->Create(Parent_Window_Class::Get_User_Parent_Window(Accounts.Get_Logged_User()), Owner_Module);
}

void Window_Class::Create(Object_Class Parent_Object, Module_Type* Owner_Module)
{
    this->Owner_Module = Owner_Module;
    this->Set_Pointer(lv_obj_create(Parent_Object.Get_Pointer()));
    this->Set_Interface();
}

/// @brief Function that create a window inside a parent object.
/// @param Parent_Object Parent object.
void Window_Class::Create(Object_Class Parent_Object)
{
}


void Window_Class::Set_Interface()
{
    this->Set_Size(Percentage(100), Percentage(100));
    this->Set_Flex_Flow(Flex_Flow_Type::Column);
    this->Set_Style_Pad_All(0, 0);
    this->Set_Style_Border_Width(0, 0);
    // - Header create.
    static Style_Type Style_Window_Header;
    Style_Window_Header.Set_Background_Color(Color_Type::Grey[6]);

    Header.Create(*this);
    Header.Set_Size(Percentage(100), 32);
    Header.Add_Style(Style_Window_Header, 0);

    // - Left buttons.
    Close_Button.Create(Header);
    Close_Button.Set_Size(24, 24);
    Close_Button.Set_Alignment(Alignment_Type::Middle_Left);
    Close_Button.Set_Style_Border_Color(Color_Type::Red[5], 0);
    Close_Button.Set_Style_Border_Width(4, 0);
    Close_Button.Set_Style_Radius(8, 0);

    Minimize_Button.Create(Header);
    Minimize_Button.Set_Size(24, 24);
    Minimize_Button.Set_Style_Border_Color(Color_Type::Yellow[5], 0);
    Minimize_Button.Set_Style_Border_Width(4, 0);
    Minimize_Button.Set_Style_Radius(8, 0);
    Minimize_Button.Set_Alignment(Close_Button, Alignment_Type::Out_Right_Middle, 4, 0);

    // - Middle title.
    Title_Label.Create(Header);
    Title_Label.Set_Long_Mode(Label_Class::Long_Mode_Type::Dot);
    Title_Label.Set_Alignment(Alignment_Type::Center);



    Clock_Label.Create(Header);
    Clock_Label.Set_Alignment(Alignment_Type::Middle_Right);

    // - Right buttons.
    Battery_Button.Create(Header);
    Battery_Button.Set_Size(24, Percentage(100));
    Battery_Button.Set_Alignment(Clock_Label, Alignment_Type::Out_Left_Middle, -4, 0);

    Network_Button.Create(Header);
    Network_Button.Set_Size(24, Percentage(100));
    Network_Button.Set_Alignment(Battery_Button, Alignment_Type::Out_Left_Middle, 0, 0);

    Sound_Button.Create(Header);
    Sound_Button.Set_Size(24, Percentage(100));
    Sound_Button.Set_Alignment(Network_Button, Alignment_Type::Out_Left_Middle, 0, 0);

    // - Body.
    Body.Create(*this);
    Body.Set_Flex_Grow(1);
}

void Window_Class::Set_State(Window_State_Type State)
{
    switch (State)
    {
    case Window_State_Type::Maximized:
        // - Set window visible
        Clear_Flag(Flag_Type::Hidden);
        // - Set window header visible
        Get_Header().Clear_Flag(Flag_Type::Hidden);
        // - Set window size to parent size
        Set_Size(Percentage(100), Percentage(100));
        // - Set parent window header hidden
        Parent_Window_Type::Get_User_Parent_Window(Accounts.Get_Logged_User()).Get_Header().Add_Flag(Flag_Type::Hidden);
        break;
    case Window_State_Type::Minimized:
        // - Set window hidden
        Add_Flag(Flag_Type::Hidden);
        // - Set parent window header visible
        Parent_Window_Type::Get_User_Parent_Window(Accounts.Get_Logged_User()).Get_Header().Clear_Flag(Flag_Type::Hidden);
        break;
    case Window_State_Type::Full_screen:
        // - Set window visible
        Clear_Flag(Flag_Type::Hidden);
        // - Set window header hidden
        Get_Header().Add_Flag(Flag_Type::Hidden);
        // - Set window size to parent size
        Set_Size(Percentage(100), Percentage(100));
        // - Set parent window header hidden
        Parent_Window_Type::Get_User_Parent_Window(Accounts.Get_Logged_User()).Get_Header().Add_Flag(Flag_Type::Hidden);
        break;
    }
}

/// @brief Function that return if the window is maximized.
/// @return true if the window is maximized.
Window_State_Type Window_Class::Get_State()
{
    if (Has_Flag(Flag_Type::Hidden))
    {
        return Window_State_Type::Minimized;
    }
    else if (Get_Header().Has_Flag(Flag_Type::Hidden))
    {
        return Window_State_Type::Full_screen;
    }
    else
    {
        return Window_State_Type::Maximized;
    }
}

// - - Setters

/// @brief Set the lvgl pointer of the window object.
/// @param LVGL_Object_Pointer Pointer to the lvgl object.
/// @return
bool Window_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (Get_Pointer() != NULL)
    {
        return false;
    }
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_obj_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Window_Class::Set_Title(const char *Title)
{
    Title_Label.Set_Text(Title);
}

// - - Getters

Object_Class Window_Class::Get_Body()
{
    return Body;
}

Object_Class Window_Class::Get_Header()
{
    return Header;
}