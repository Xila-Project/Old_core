///
/// @file Display.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 06-04-2021
///
/// @copyright Copyright (c) 2021
///

#ifndef Display_Hpp_Included
#define Display_Hpp_Included

#include "../Module/Module.hpp"

#include "lvgl.h"

namespace Xila_Namespace
{
    typedef class Display_Class : Module_Class
    {
    public:
        // - Methods
        Result_Type Start();
        Result_Type Stop();

        // - - Management
        void Calibrate();

    
        uint16_t Get_Horizontal_Definition();
        uint16_t Get_Vertical_Definition();

        // - - Getters
        uint8_t Get_Brightness();
        uint16_t Get_Standby_Time();

        // - - Setters
        void Set_Brightness(uint8_t Brightness);
        void Set_Standby_Time(uint16_t Standby_Time);

        // - - LVGL interface

        static IRAM_ATTR void Output_Flush(lv_disp_drv_t *Display_Driver_Interface, const lv_area_t *Area, lv_color_t *Buffer);
        static IRAM_ATTR void Input_Read(lv_indev_drv_t *Input_Device_Driver_Interface, lv_indev_data_t *Data);
        
    private:

        // - Methods
        Result_Type Initialize();
        void Sleep();
        void Wake_Up();
        
        // - - Registry
        Result_Type Create_Registry();
        Result_Type Load_Registry();
        Result_Type Save_Registry();

    
        // - Attributes
        uint16_t Standby_Time;
        uint8_t Brightness;

    } Display_Type;

    extern Display_Type Display;
}

#endif