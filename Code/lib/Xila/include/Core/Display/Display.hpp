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

#include "../Module/Module.hpp"

#include "lvgl.h"

namespace Xila_Namespace
{
    class Display_Class : Module_Class
    {
    public:
        // - Methods

        // - - Constructor / destructor
        Display_Class();
        ~Display_Class();

        // - - Management
        Result_Type Start();
        void Calibrate();

        // - - Registry
        Result_Type Load_Registry();
        Result_Type Save_Registry();

        uint16_t Get_Horizontal_Definition();
        uint16_t Get_Vertical_Definition();

        // - - Setters

        void Set_Brightness(uint8_t Brightness);
        uint8_t Get_Brightness();

        // - - Getters

        void Set_Standby_Time(uint16_t Standby_Time);
        uint16_t Get_Standby_Time();

        // - - LVGL interface

        static IRAM_ATTR void Output_Flush(lv_disp_drv_t *Display_Driver_Interface, const lv_area_t *Area, lv_color_t *Buffer);
        static IRAM_ATTR void Input_Read(lv_indev_drv_t *Input_Device_Driver_Interface, lv_indev_data_t *Data);
        

    
    private:
        // - Attributes
        uint16_t Standby_Time;
        uint8_t Brightness;

    } Display;
}

#endif