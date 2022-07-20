///
/// @file Graphic_Interface.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 03-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Graphical_Interface_Hpp_Included
#define Graphical_Interface_Hpp_Included

#include <Arduino.h>

#include "lvgl.h"

#include "../Module.hpp"

#include "Core/Software/Task.hpp"

// Base object
#include "Object.hpp"
// Widgets
#include "Arc.hpp"
#include "Bar.hpp"
#include "Button.hpp"
#include "Button_Matrix.hpp"
#include "Canvas.hpp"
#include "Checkbox.hpp"
#include "Drop_Down_List.hpp"
#include "Image.hpp"
#include "Line.hpp"
#include "Roller.hpp"
#include "Slider.hpp"
#include "Switch.hpp"
#include "Table.hpp"
#include "Text_Area.hpp"
// Extra widgets
//#include "Animaton_Image.hpp"
#include "Calendar.hpp"
#include "Chart.hpp"
#include "Color_Wheel.hpp"
//#include "Image_Button.hpp"
#include "Keyboard.hpp"
#include "List.hpp"
#include "Menu.hpp"
#include "Meter.hpp"
//#include "Message_Box.hpp"
//#include "Span.hpp"
//#include "Spinbox.hpp"
//#include "Spinner.hpp"
#include "Tabs.hpp"
//#include "Tileview.hpp"
#include "Window.hpp"

class Graphical_Interface_Class : public Module_Class
{

    // - Types

    typedef Object_Class Object_Type;
    typedef Arc_Class Arc_Type;
    typedef Bar_Class Bar_Type;
    typedef Button_Class Button_Type;
    typedef Button_Matrix_Class Button_Matrix_Type;
    typedef Canvas_Class Canvas_Type;
    typedef Checkbox_Class Checkbox_Type;
    typedef Drop_Down_List_Class Drop_Down_List_Type;
    typedef Image_Class Image_Type;
    typedef Line_Class Line_Type;
    typedef Roller_Class Roller_Type;
    typedef Slider_Class Slider_Type;
    typedef Switch_Class Switch_Type;
    typedef Table_Class Table_Type;
    typedef Text_Area_Class Text_Area_Type;
    typedef Calendar_Class Calendar_Type;
    //typedef Chart_Class Chart_Type;
    typedef Color_Wheel_Class Color_Wheel_Type;
    typedef Keyboard_Class Keyboard_Type;
    typedef List_Class List_Type;
    //typedef Menu_Class Menu_Type;
    //typedef Meter_Class Meter_Type;
    typedef Tabs_Class Tabs_Type;
    typedef Window_Class Window_Type;
    

    static void Initialise();
    static bool Initialisation_State();


    static void Task_Function(void *);

    static Task_Type Task;

    static Xila_Class::Semaphore_Handle_Type Mutex_Semaphore_Handle;

    // -- Display state
    static uint16_t Get_Horizontal_Definition();
    static uint16_t Get_Vertical_Definition();

    static Result_Type Compile_Page(File);
    static Result_Type Load_Page(File, Object *, uint16_t);

protected:

    static lv_color_t Buffer[Default_Display_Horizontal_Definition * 10];
    static lv_disp_draw_buf_t Draw_Buffer;
    static lv_disp_drv_t Display_Driver_Interface;

    static lv_fs_drv_t File_System_Driver;

    static void *File_System_Open(lv_fs_drv_t *, const char *, lv_fs_mode_t);
    static lv_fs_res_t File_System_Close(lv_fs_drv_t *, void *);
    static lv_fs_res_t File_System_Read(lv_fs_drv_t *, void *, void *, uint32_t, uint32_t *);
    static lv_fs_res_t File_System_Write(lv_fs_drv_t *, void *, const void *, uint32_t, uint32_t *);
    static lv_fs_res_t File_System_Set_Position(lv_fs_drv_t *, void *, uint32_t, lv_fs_whence_t);
    static lv_fs_res_t File_System_Get_Position(lv_fs_drv_t *, void *, uint32_t *);
    static void *File_System_Open_Directory(lv_fs_drv_t *, const char *);
    static lv_fs_res_t File_System_Directory_Read(lv_fs_drv_t *, void *, char *);
    static lv_fs_res_t File_System_Close_Directory(lv_fs_drv_t *, void *);

    static void Set_State(uint8_t State);
    static void Set_State(uint8_t State);

    static uint8_t Brightness;
};

#endif