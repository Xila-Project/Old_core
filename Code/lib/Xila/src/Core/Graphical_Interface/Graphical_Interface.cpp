///
/// @file Graphical_Interface.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Graphical_Interface.hpp"

#include "Core/Core.hpp"

#include "lvgl.h"

void Graphical_Interface_Class::Initialize()
{
    lv_init();

    lv_disp_draw_buf_init(&Draw_Buffer, Buffer, NULL, Default_Display_Horizontal_Definition);

    lv_disp_drv_init(&Display_Driver_Interface);

    Display_Driver_Interface.Horizontal_Definition = Default_Display_Horizontal_Definition;
    Display_Driver_Interface.Vertical_Definition = Default_Display_Vertical_Definition;
    Display_Driver_Interface.flush_cb = Display_Flush;
    Display_Driver_Interface.draw_buf = &Draw_Buffer;

    lv_driver_register(&Display_Driver_Interface);


}

IRAM_ATTR void Graphical_Interface::Event_Handler(Display_Class::Event_Type Event)
{

    Xila.Software_Management.Send_Instruction(Xila.Software_Management.);
}
