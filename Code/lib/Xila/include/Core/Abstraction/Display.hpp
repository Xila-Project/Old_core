///
 /// @file Display.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1
 /// @date 06-04-2021
 /// 
 /// @copyright Copyright (c) 2021
 /// 

#ifndef DISPLAY_HPP_INCLUDED
#define DISPLAY_HPP_INCLUDED

// Base object
#include "Display/Object.hpp"
// Widgets
#include "Display/Arc.hpp"
#include "Display/Bar.hpp"
#include "Display/Button.hpp"
#include "Display/Button_Matrix.hpp"
#include "Display/Canvas.hpp"
#include "Display/Checkbox.hpp"
#include "Display/Dropdown_List.hpp"
#include "Display/Image.hpp"
#include "Display/Line.hpp"
#include "Display/Roller.hpp"
#include "Display/Slider.hpp"
#include "Display/Switch.hpp"
#include "Display/Table.hpp"
#include "Display/Text_Area.hpp"
// Extra widgets
#include "Display/Animaton_Image.hpp"
#include "Display/Calendar.hpp"
#include "Display/Chart.hpp"
#include "Display/Color_Wheel.hpp"
#include "Display/Image_Button.hpp"
#include "Display/Keyboard.hpp"
#include "Display/List.hpp"
#include "Display/Menu.hpp"
#include "Display/Meter.hpp"
#include "Display/Message_Box.hpp"
#include "Display/Span.hpp"
#include "Display/Spinbox.hpp"
#include "Display/Spinner.hpp"
#include "Display/Tab.hpp"
#include "Display/Tileview.hpp"
#include "Display/Window.hpp"

inline uint16_t Display_Class::Get_Horizontal_Definition()
{
    return Display_Horizontal_Definition;
}

inline uint16_t Display_Class::Get_Vertical_Definition()
{
    return Display_Vertical_Definition;
}

inline State Display_Class::Get_Object_Visibility(Xila_Class::Object_Type Object_Type)
{
    if (lv_obj_is_visible(Object_Type))
    {
        return Visible;
    }
    else
    {
        return Hidden;
    }
}


inline uint8_t Display_Class::Get_State()
{
    return State;
}

inline void Display_Class::Set_State(uint8_t State)
{
    this->State = State;
}



#endif