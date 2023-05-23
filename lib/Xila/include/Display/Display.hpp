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
    /// @brief Display module class.
    typedef class Display_Class : Module_Class
    {
    public:
        // - Methods
        Result_Type Start();
        Result_Type Stop();

        // - - Management

        /// @brief 

        /// @brief Calibrate the touch screen.
        void Calibrate();

        /// @brief Get the horizontal definition of the display.
        /// @return uint16_t Horizontal definition of the display in pixels.
        uint16_t Get_Horizontal_Definition();

        /// @brief Get the vertical definition of the display.
        /// @return uint16_t Vertical definition of the display in pixels.
        uint16_t Get_Vertical_Definition();

        // - - Getters

        /// @brief Get the brightness of the display.Xila_Namespace
        /// @return uint8_t Brightness of the display (0-255).
        uint8_t Get_Brightness();

        /// @brief Get the standby time of the display.
        /// @return uint16_t Standby time of the display in seconds.
        uint16_t Get_Standby_Time();

        // - - Setters

        /// @brief Set the brightness of the display.
        /// @param Brightness Brightness of the display (0-255).
        void Set_Brightness(uint8_t Brightness);

        /// @brief Set the standby time of the display.
        /// @param Standby_Time Standby time of the display in seconds.
        void Set_Standby_Time(uint16_t Standby_Time);

        // - - LVGL interface

        /// @brief Display output flush callback function for Graphics module.
        /// @param Display_Driver_Interface LVGL display driver interface.
        /// @param Area LVGL area to flush.
        /// @param Buffer LVGL buffer to flush.
        static IRAM_ATTR void Output_Flush(lv_disp_drv_t *Display_Driver_Interface, const lv_area_t *Area, lv_color_t *Buffer);

        /// @brief Display input read callback function for Graphics module.
        /// @param Input_Device_Driver_Interface LVGL input device driver interface.
        /// @param Data LVGL input data written by the callback.
        static IRAM_ATTR void Input_Read(lv_indev_drv_t *Input_Device_Driver_Interface, lv_indev_data_t *Data);
        
        /// @brief Sleep the display.
        void Sleep();
        
        /// @brief Wake up the display.
        void Wake_Up();

    private:

        // - Methods
        Result_Type Initialize();
        
        // - - Registry

        /// @brief Create the registry of the display module.
        /// @return Result_Type
        Result_Type Create_Registry();

         /// @brief Load the registry of the display module. 
         /// 
         /// @return Result_Type 
        Result_Type Load_Registry();

        /// @brief Save the registry of the display module.
        /// @return Result_Type
        Result_Type Save_Registry();

    
        // - Attributes

        /// @brief Display standy time in seconds.
        uint16_t Standby_Time;
        uint8_t Brightness;

    } Display_Type;

    /// @brief Display module instance.
    extern Display_Type Display;
}

#endif