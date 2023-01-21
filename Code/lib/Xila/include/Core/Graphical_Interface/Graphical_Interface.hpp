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

#include "../Module.hpp"

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
#include "Drop_Down_List.hpp"
#include "Image.hpp"
#include "Line.hpp"
#include "Label.hpp"
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

#include "Theme.hpp"

namespace Xila_Namespace
{
    typedef class Graphical_Interface_Class : public Types_Class, public Xila_Namespace::Module_Class
    {
    public:
        
        // - Constructor
        Graphical_Interface_Class();

        Theme_Class Theme;

        Result_Type Initialize();

        bool Initialisation_State();

        static void Task_Function(void *);
        Task_Class Task;

        static void Event_Handler(lv_event_t *Event);

        void Clear_Cache();



    protected:
        // - - Drivers

        lv_color_t Draw_Buffer[Display_Horizontal_Definition * 10];
        lv_disp_draw_buf_t Draw_Buffer_Descriptor;
        lv_disp_drv_t Screen_Driver_Interface;

        lv_indev_drv_t Input_Device_Driver_Interface;

        lv_fs_drv_t File_System_Driver;

        void *File_System_Open(lv_fs_drv_t *, const char *, lv_fs_mode_t);
        lv_fs_res_t File_System_Close(lv_fs_drv_t *, void *);
        lv_fs_res_t File_System_Read(lv_fs_drv_t *, void *, void *, uint32_t, uint32_t *);
        lv_fs_res_t File_System_Write(lv_fs_drv_t *, void *, const void *, uint32_t, uint32_t *);
        lv_fs_res_t File_System_Set_Position(lv_fs_drv_t *, void *, uint32_t, lv_fs_whence_t);
        lv_fs_res_t File_System_Get_Position(lv_fs_drv_t *, void *, uint32_t *);
        void *File_System_Open_Directory(lv_fs_drv_t *, const char *);
        lv_fs_res_t File_System_Directory_Read(lv_fs_drv_t *, void *, char *);
        lv_fs_res_t File_System_Close_Directory(lv_fs_drv_t *, void *);
    } Graphical_Interface_Type;

    extern Graphical_Interface_Type Graphical_Interface;
}

#endif