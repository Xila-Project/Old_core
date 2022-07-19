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

#include "Drivers/WT32-SC01.hpp"

class Display_Class
{
    Display_Class();
    ~Display_Class();

    uint8_t Get_State();

    friend class Xila_Class;
    friend class Shell_Class;
    friend class Unit_Test_Class;

    Xila_Class::Event Load_Registry();
    Xila_Class::Event Save_Registry();
}



#endif