///
/// @file Window.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Window.hpp"

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Window_Class::Create()
{
    this->Set_Pointer(lv_obj_create(lv_scr_act()));
    this->Set_Size(Percentage(100), Percentage(100));
    this->Set_Flex_Flow(Flex::Column);
    this->Set_Style_Pad_All(0, 0);
    this->Set_Style_Border_Width(0, 0);

    // - Header create.
    Header.Create(*this);
    Header.Set_Size(Percentage(100), 32);

    static Style_Class Style_Window_Header;
    Style_Window_Header.Set_Background_Color(Color_Class::Get_From_Palette(Color_Class::Grey, -1));

    // - Left buttons.
    Close_Button.Create(Header);
    Close_Button.Set_Size(24, 24);
    Close_Button.Set_Alignment(Alignment::Middle_Left);
    Minimize_Button.Create(Header);
    Minimize_Button.Set_Size(24, 24);
    Minimize_Button.Set_Alignment(Close_Button, Alignment::Out_Right_Middle, 4, 0);

    // - Middle title.
    Title_Label.Create(Header);
    Title_Label.Set_Long_Mode(Label_Class::Long_Mode_Enumeration::Long_Dot);
    Title_Label.Set_Alignment(Alignment::Center);
    Clock_Label.Create(Header);
    Clock_Label.Set_Alignment(Alignment::Middle_Right);

    // - Right buttons.
    Battery_Button.Create(Header);
    Battery_Button.Set_Size(24, Percentage(100));
    Battery_Button.Set_Alignment(Clock_Label, Alignment::Out_Left_Middle, -4, 0);

    Network_Button.Create(Header);
    Network_Button.Set_Size(24, Percentage(100));
    Network_Button.Set_Alignment(Battery_Button, Alignment::Out_Left_Middle, 0, 0);

    Sound_Button.Create(Header);
    Sound_Button.Set_Size(24, Percentage(100));
    Sound_Button.Set_Alignment(Network_Button, Alignment::Out_Left_Middle, 0, 0);

    // - Body.
    Body.Create(*this);
    Body.Set_Flex_Grow(1);
}

void Window_Class::Create(Object_Class Parent_Object)
{
    if (!Parent_Object.Is_Valid())
    {
        return;
    }

    this->Set_Pointer(lv_obj_create(Parent_Object.Get_Pointer()));
    this->Set_Size(Percentage(100), Percentage(100));
    this->Set_Flex_Flow(Flex::Column);
    this->Set_Style_Pad_All(0, 0);
    this->Set_Style_Border_Width(0, 0);
    // - Header create.
    Header.Create(*this);
    Header.Set_Size(Percentage(100), 32);

    static Style_Class Style_Window_Header;
    Style_Window_Header.Set_Background_Color(Color_Class::Get_From_Palette(Color_Class::Grey, -1));

    // - Left buttons.
    Close_Button.Create(Header);
    Close_Button.Set_Size(24, 24);
    Close_Button.Set_Alignment(Alignment::Middle_Left);
    Minimize_Button.Create(Header);
    Minimize_Button.Set_Size(24, 24);
    Minimize_Button.Set_Alignment(Close_Button, Alignment::Out_Right_Middle, 4, 0);

    // - Middle title.
    Title_Label.Create(Header);
    Title_Label.Set_Long_Mode(Label_Class::Long_Mode_Enumeration::Long_Dot);
    Title_Label.Set_Alignment(Alignment::Center);
    Clock_Label.Create(Header);
    Clock_Label.Set_Alignment(Alignment::Middle_Right);

    // - Right buttons.
    Battery_Button.Create(Header);
    Battery_Button.Set_Size(24, Percentage(100));
    Battery_Button.Set_Alignment(Clock_Label, Alignment::Out_Left_Middle, -4, 0);


    Network_Button.Create(Header);
    Network_Button.Set_Size(24, Percentage(100));
    Network_Button.Set_Alignment(Battery_Button, Alignment::Out_Left_Middle, 0, 0);

    Sound_Button.Create(Header);
    Sound_Button.Set_Size(24, Percentage(100));
    Sound_Button.Set_Alignment(Network_Button, Alignment::Out_Left_Middle, 0, 0);

    // - Body.
    Body.Create(*this);
    Body.Set_Flex_Grow(1);
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Window_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
         if (Get_Pointer() == NULL)
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

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

Object_Class Window_Class::Get_Body()
{
    if (Body.Is_Valid())
    {
        return Body;
    }
}

Object_Class Window_Class::Get_Header()
{
    if (Header.Is_Valid())
    {
        return Header;
    }
}