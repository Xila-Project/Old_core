///
/// @file WT32-SC01-Plus.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 02-02-2023
///
/// @copyright Copyright (c) 2023
///

#ifdef Xila_Display_Hardware_Native

// - Include header
#include "Core/Display/Display.hpp"

// - Include external libraries
#include <unistd.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "display/monitor.h"
#include "indev/mouse.h"
#include "indev/mousewheel.h"
#include "indev/keyboard.h"
#include "sdl/sdl.h"

using namespace Xila_Namespace;

/**
 * A task to measure the elapsed time for LittlevGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void * data)
{
    (void)data;

    while(1) {
        SDL_Delay(5);   /*Sleep for 5 millisecond*/
        lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
    }

    return 0;
}


Result_Type Display_Class::Initialize()
{
}

void Display_Class::Sleep()
{
   
}

void Display_Class::Wake_Up()
{
  
}

void Display_Class::Set_Brightness(uint8_t Brightness)
{
    
};

uint8_t Display_Class::Get_Brightness()
{
    return 100;
};

void Display_Class::Output_Flush(lv_disp_drv_t *Display_Driver_Interface, const lv_area_t *Area, lv_color_t *Buffer)
{
    
};

void Display_Class::Input_Read(lv_indev_drv_t *Input_Device_Driver_Interface, lv_indev_data_t *Data)
{
   
};

void Display_Class::Calibrate()
{
   
};

#endif