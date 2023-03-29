///
/// @file Window.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

//

#include "Core/Graphics/Window.hpp"
#include "Core/Account/Accounts.hpp"
#include "Core/Software/Softwares.hpp"
#include "Core/Graphics/Graphics.hpp"
#include "Core/Log/Log.hpp"

// - Namespaces

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

const Class_Type Window_Class::Class = {
    .base_class = &lv_obj_class,
    .constructor_cb = lv_obj_class.constructor_cb,
    .destructor_cb = lv_obj_class.destructor_cb,
    .event_cb = lv_obj_class.event_cb,
    .width_def = lv_obj_class.width_def,
    .height_def = lv_obj_class.height_def,
    .editable = lv_obj_class.editable,
    .group_def = lv_obj_class.group_def,
    .instance_size = sizeof(lv_obj_t),
};

// - Methods

// - - Constructors / Destructors

// TODO : Implement copy constructor (have to copy header and body childs object into the right place).

Window_Class::Window_Class() : Object_Class()
{
}

Window_Class::Window_Class(const Object_Class &Object_To_Copy) : Object_Class(Object_To_Copy)
{
}

// - - Manipulation

/// @brief Function that create a window.
void Window_Class::Create(const Software_Type *Owner_Software)
{
    if (Owner_Software == NULL)
    {
        return;
    }
    Parent_Window_Type Parent_Window = Parent_Window_Type::Get_User_Parent_Window(Owner_Software->Get_Owner_User());
    if (!Parent_Window)
    {
        return;
    }
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_obj_create(Parent_Window.Get_Pointer());
        this->LVGL_Object_Pointer->class_p = &Window_Class::Class; // Set the custom class.
    }

    Log_Trace();

    this->Owner_Software = Owner_Software;
    this->Set_Interface();
}

void Window_Class::Create(Object_Class Parent_Object)
{
    this->Owner_Software = NULL;
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_obj_create(Parent_Object.Get_Pointer());
        this->LVGL_Object_Pointer->class_p = &Window_Class::Class; // Set the custom class.
    }
    this->Set_Interface();
}

void Window_Class::Set_Interface()
{
    Log_Trace();

    this->Set_Size(Percentage(100), Percentage(100));
    this->Set_Flex_Flow(Flex_Flow_Type::Column);
    this->Set_Style_Pad_All(0, 0);
    this->Set_Style_Border_Width(0, 0);


    Log_Trace();

    // - Header create.
    static Style_Type Style_Window_Header;
    Style_Window_Header.Initialize();
    Style_Window_Header.Set_Background_Color(Color_Type::Grey[8]);


    Log_Trace();

    Header.Create(*this);
    Header.Set_Size(Percentage(100), 32);
    Header.Add_Style(Style_Window_Header, 0);



    Log_Trace();

    // - Left buttons.
    Close_Button.Create(Header);
    Close_Button.Set_Size(24, 24);
    Close_Button.Set_Alignment(Alignment_Type::Middle_Left);
    Close_Button.Set_Style_Border_Color(Color_Type::Red[5], 0);
    Close_Button.Set_Style_Border_Width(4, 0);
    Close_Button.Set_Style_Radius(8, 0);
    Close_Button.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);


    Log_Trace();

    Minimize_Button.Create(Header);
    Minimize_Button.Set_Size(24, 24);
    Minimize_Button.Set_Style_Border_Color(Color_Type::Yellow[5], 0);
    Minimize_Button.Set_Style_Border_Width(4, 0);
    Minimize_Button.Set_Style_Radius(8, 0);
    Minimize_Button.Set_Alignment(Close_Button, Alignment_Type::Out_Right_Middle, 4, 0);
    Minimize_Button.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);


    Log_Trace();

    // - Middle title.
    Title_Label.Create(Header);
    Title_Label.Set_Long_Mode(Graphics_Types::Long_Type::Dot);
    Title_Label.Set_Alignment(Alignment_Type::Center);
    Title_Label.Set_Style_Text_Color(Color_Type::White, 0);


    Log_Trace();

    // - Body.
    Body.Create(*this);
    Body.Set_Style_Pad_All(0, 0);
    Body.Set_Width(Percentage(100));
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
        if (this->Get_Owner_Software() != NULL)
        {
            Parent_Window_Type::Get_User_Parent_Window(this->Get_Owner_Software()->Get_Owner_User()).Get_Header().Add_Flag(Flag_Type::Hidden);
        }
        break;
    case Window_State_Type::Minimized:
        // - Set window hidden
        Add_Flag(Flag_Type::Hidden);
        // - Set parent window header visible
        if (this->Get_Owner_Software() != NULL)
        {
            Parent_Window_Type::Get_User_Parent_Window(this->Get_Owner_Software()->Get_Owner_User()).Get_Header().Clear_Flag(Flag_Type::Hidden);
        }
        break;
    case Window_State_Type::Full_screen:
        // - Set window visible
        Clear_Flag(Flag_Type::Hidden);
        // - Set window header hidden
        Get_Header().Add_Flag(Flag_Type::Hidden);
        // - Set window size to parent size
        Set_Size(Percentage(100), Percentage(100));
        // - Set parent window header hidden
        if (this->Get_Owner_Software() != NULL)
        {
            Parent_Window_Type::Get_User_Parent_Window(this->Get_Owner_Software()->Get_Owner_User()).Get_Header().Add_Flag(Flag_Type::Hidden);
        }
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
    Object_Type Object(LVGL_Object_Pointer);
    if (!Object.Check_Class(&Window_Class::Class))
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

const Software_Type* Window_Class::Get_Owner_Software() const
{
    return Owner_Software;
}