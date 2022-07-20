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

#include "../Drivers/Display/WT32_SC01.hpp"

#include "lvgl.h"

class Display_Class
{
    WT32_SC01_Class Touchscreen_Display;

    Display_Class();
    ~Display_Class();

    uint8_t Get_State();

    friend class Xila_Class;
    friend class Shell_Class;
    friend class Unit_Test_Class;

    Result_Type Load_Registry();
    Result_Type Save_Registry();

    void Calibrate();

    void Initialize();

    IRAM_ATTR void Flush(lv_disp_drv_t *Display_Driver_Interface, const lv_area_t *Area, lv_color_t *Buffer);

    IRAM_ATTR void 
}

#endif