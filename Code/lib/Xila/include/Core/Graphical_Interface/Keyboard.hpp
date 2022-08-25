///
/// @file Keyboard.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 11-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Keyboard_Hpp_Included
#define Keyboard_Hpp_Included

#include "Object.hpp"
#include "Text_Area.hpp"
#include "Button_Matrix.hpp"

class Keyboard_Class : public Object_Class
{
public:
    typedef lv_keyboard_mode_t Mode_Type;

    enum Mode_Enumeration
    {
        Text_Lower = LV_KEYBOARD_MODE_TEXT_LOWER,
        Text_Upper = LV_KEYBOARD_MODE_TEXT_UPPER,
        Special = LV_KEYBOARD_MODE_SPECIAL,
        Number = LV_KEYBOARD_MODE_NUMBER,
        User_1 = LV_KEYBOARD_MODE_USER_1,
        User_2 = LV_KEYBOARD_MODE_USER_2,
        User_3 = LV_KEYBOARD_MODE_USER_3,
        User_4 = LV_KEYBOARD_MODE_USER_4
    };

    // -- Methods
    void Create(Object_Class &Parent_Object);

    // -- -- Setters
    bool Set_Pointer(lv_obj_t* LVGL_Object_Pointer);

    void Set_Text_Area(Text_Area_Class &Text_Area);
    void Set_Mode(Mode_Type Mode);
    void Set_Pop_Overs(bool Enabled);
    void Set_Map(Mode_Type Mode, const char *Map[], const Button_Matrix_Class::Control::Type Control_Map[]);

    // -- Getters
    Text_Area_Class Get_Text_Area();
    Mode_Type Get_Mode();
    const char **Get_Map_Array();
    uint16_t Get_Selected_Button();
    const char *Get_Button_Text(uint16_t Button_Identifier);
};

#endif