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

// Base object
#include "Object.hpp"
// Widgets
#include "Arc.hpp"
#include "Bar.hpp"
#include "Button.hpp"
#include "Button_Matrix.hpp"
#include "Canvas.hpp"
#include "Checkbox.hpp"
#include "Dropdown_List.hpp"
#include "Image.hpp"
#include "Line.hpp"
#include "Roller.hpp"
#include "Slider.hpp"
#include "Switch.hpp"
#include "Table.hpp"
#include "Text_Area.hpp"
// Extra widgets
#include "Animaton_Image.hpp"
#include "Calendar.hpp"
#include "Chart.hpp"
#include "Color_Wheel.hpp"
#include "Image_Button.hpp"
#include "Keyboard.hpp"
#include "List.hpp"
#include "Menu.hpp"
#include "Meter.hpp"
#include "Message_Box.hpp"
#include "Span.hpp"
#include "Spinbox.hpp"
#include "Spinner.hpp"
#include "Tabs.hpp"
#include "Tileview.hpp"
#include "Window.hpp"

class Graphic_Interface_Class
{

  

    void Initialise();
    bool Initialisation_State();

   

  

    // -- Widgets

  
   

    // @brief Color wheel class.
 

    //


    

    static void Task(void *);

    Xila_Class::Task_Handle Task_Handle;

    Xila_Class::Semaphore_Handle_Type Mutex_Semaphore_Handle;

    // -- Display state
    uint16_t Get_Horizontal_Definition();
    uint16_t Get_Vertical_Definition();

    Xila_Class::Event Compile_Page(File);
    Xila_Class::Event Load_Page(File, Object *, uint16_t);

protected:
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

    void Initialize_File_System();

    void Set_State(uint8_t State);

    void Set_State(uint8_t State);

    uint8_t State;

    uint8_t Brightness, Receive_Pin, Standby_Time, Transmit_Pin;

    Xila_Class::Address Current_Address;
};

#endif