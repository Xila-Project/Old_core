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

Window_Class::Window_Class(const Object_Class &Object_To_Copy)
{
    if (Object_To_Copy.Is_Valid() && (Object_To_Copy.Get_User_Data() != NULL) && Object_To_Copy.Is_Valid() && Set_Pointer(Object_To_Copy))
        Data = static_cast<Data_Type *>(Object_To_Copy.Get_User_Data());
}

// - - Manipulation

void Window_Class::Create(const Softwares_Types::Software_Type *Owner_Software)
{

    if (Owner_Software == NULL)
        return;

    Screen_Type User_Screen = Screen_Type::Get_User_Screen(Owner_Software->Get_Owner_User());

    if (!User_Screen.Is_Valid())
        return;

    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_obj_create(User_Screen);
        if (!Is_Valid())
            return;

        this->LVGL_Object_Pointer->class_p = &Window_Class::Class; // Set the custom class.
    }

    Data = new Data_Type;
    Set_User_Data(Data);
    Data->Owner_Software = Owner_Software;
    this->Set_Interface();
}

void Window_Class::Create(Object_Class Parent_Object)
{
    if (!Parent_Object.Is_Valid())
        return;

    {
        auto Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_obj_create(Parent_Object);

        if (this->LVGL_Object_Pointer == NULL)
            return;

        this->LVGL_Object_Pointer->class_p = &Window_Class::Class; // Set the custom class.
    }

    Data = new Data_Type;
    Set_User_Data(Data);
    Data->Owner_Software = NULL;

    this->Set_Interface();
}

void Window_Class::Delete()
{
    if (!this->Is_Valid())
        return;

    auto Semaphore = Graphics.Take_Semaphore_Auto();
    lv_obj_del_async(this->Get_Pointer());
    this->Clear_Pointer();
    delete Data;
    Data = NULL;
}

void Window_Class::Set_Interface()
{

    if (!this->Is_Valid() || this->Data == NULL)
        return;

    this->Set_Size(Percentage(100), Percentage(100));
    this->Set_Flex_Flow(Flex_Flow_Type::Column);
    this->Set_Style_Pad_All(0, 0);
    this->Set_Style_Border_Width(0, 0);

    // - Header create.
    Data->Header.Create(*this);
    Data->Header.Set_Size(Percentage(100), 32);
    Data->Header.Set_Style_Background_Color(Color_Type::Grey[8], 0);
    Data->Header.Set_Style_Pad_All(0, 0);

    if (!Data->Header.Is_Valid())
        Log_Error("Win", "Header is not valid.");

    // - Left buttons.
    Data->Close_Button.Create(Data->Header, "", 24, 24);
    Data->Close_Button.Set_Alignment(Alignment_Type::Middle_Left, 4, 0);
    Data->Close_Button.Set_Style_Border_Color(Color_Type::Red[5], 0);
    Data->Close_Button.Set_Style_Border_Width(4, 0);
    Data->Close_Button.Set_Style_Radius(8, 0);
    Data->Close_Button.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Data->Close_Button.Set_Style_Shadow_Width(0, 0);
    Data->Close_Button.Add_Event(Event_Callback, Event_Code_Type::Clicked, this);

    Data->Minimize_Button.Create(Data->Header);
    Data->Minimize_Button.Set_Size(24, 24);
    Data->Minimize_Button.Set_Alignment(Alignment_Type::Out_Right_Middle, 8, 0, &Data->Close_Button);
    Data->Minimize_Button.Set_Style_Border_Color(Color_Type::Yellow[5], 0);
    Data->Minimize_Button.Set_Style_Border_Width(4, 0);
    Data->Minimize_Button.Set_Style_Radius(8, 0);
    Data->Minimize_Button.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Data->Minimize_Button.Set_Style_Shadow_Width(0, 0);
    Data->Minimize_Button.Add_Event(Event_Callback, Event_Code_Type::Clicked, this);

    // - Middle title.
    Data->Title_Label.Create(Data->Header);
    Data->Title_Label.Set_Long_Mode(Graphics_Types::Long_Type::Dot);
    Data->Title_Label.Set_Alignment(Alignment_Type::Center);
    Data->Title_Label.Set_Style_Text_Color(Color_Type::White, 0);

    // - Body.
    Data->Body.Create(*this);
    Data->Body.Set_Style_Pad_All(0, 0);
    Data->Body.Set_Width(Percentage(100));
    Data->Body.Set_Flex_Grow(1);

    Task_Class::Delay_Static(100);
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
        // - Move foreground
        Move_Foreground();
        break;
    case Window_State_Type::Minimized:
        // - Set window hidden
        Add_Flag(Flag_Type::Hidden);
        break;
    case Window_State_Type::Full_screen:
        // - Set window visible
        Clear_Flag(Flag_Type::Hidden);
        // - Set window header hidden
        Get_Header().Add_Flag(Flag_Type::Hidden);
        // - Set window size to parent size
        Set_Size(Percentage(100), Percentage(100));
        // - Move foreground
        Move_Foreground();
        break;
    }
}

Window_State_Type Window_Class::Get_State()
{
    // - Hidden
    if (Has_Flag(Flag_Type::Hidden))
        return Window_State_Type::Minimized;
    // - Not hidden, but header is hidden
    else if (Get_Header().Has_Flag(Flag_Type::Hidden))
        return Window_State_Type::Full_screen;
    // - Not hidden, header is not hidden
    else
        return Window_State_Type::Maximized;
}

// - - Setters

bool Window_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (Get_Pointer() != NULL)
        return false;

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
    Data->Title_Label.Set_Text(Title);
}

// - - Getters

Object_Type Window_Class::Get_Body()
{
    if (!Is_Valid())
        return Object_Type();
    return Data->Body;
}

Object_Type Window_Class::Get_Header()
{
    if (!Is_Valid())
        return Object_Type();
    return Data->Header;
}

Button_Type Window_Class::Get_Close_Button()
{
    if (!Is_Valid())
        return Button_Type();
    return Data->Close_Button;
}

Button_Type Window_Class::Get_Minimize_Button()
{
    if (!Is_Valid())
        return Button_Type();
    return Data->Minimize_Button;
}

const Softwares_Types::Software_Type *Window_Class::Get_Owner_Software() const
{
    return Data->Owner_Software;
}

void Window_Class::Set_Minimize_Button_Hidden(bool Hidden)
{
    if (Data == NULL || !Data->Minimize_Button.Is_Valid())
        return;

    if (Hidden)
        Data->Minimize_Button.Add_Flag(Flag_Type::Hidden);
    else
        Data->Minimize_Button.Clear_Flag(Flag_Type::Hidden);
}

void Window_Class::Event_Callback(lv_event_t *Event)
{
    auto Semaphore = Graphics.Take_Semaphore_Auto();
 
    Window_Type *Window = static_cast<Window_Type *>(lv_event_get_user_data(Event));

Log_Trace();

    if (!Window || !Window->Is_Valid())
        return;

Log_Trace();

    if (lv_event_get_code(Event) == LV_EVENT_CLICKED)
    {
        Log_Trace();
        if (lv_event_get_target(Event) == (lv_obj_t*)Window->Get_Close_Button())
        {
            Log_Trace();
            Window->Delete();
            return;
        }
        else if (lv_event_get_target(Event) == (lv_obj_t*)Window->Get_Minimize_Button())
        {
            Log_Trace();
            Window->Set_State(Window_State_Type::Minimized);
            return;
        }
    }
}