///
/// @file Core.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Xila's core header file.
/// @version 0.1
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021
///
/// @details Gather all the parts used by Xila core.
///
/// @section MIT License
///
/// Copyright (c) 2021 Alix ANNERAUD
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
/// The above notice and this permission notice shall be included in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
///
#ifndef CORE_HPP_INCLUDED
#define CORE_HPP_INCLUDED

#ifdef __cplusplus

#else

#error Xila requires a C++ complier, please change file extension to .cpp

#endif

//============================================================================//
//                          Include required libraries                        //
//============================================================================//

// -- C++ standard library
#include <stdint.h>

// -- Arduino framework
#include "Arduino.h"

// -- File system library
#include "FS.h"

// -- SPI library
#include "SPI.h"

// -- Registry management library
#include "ArduinoJson.h" //used to store registries
#include "StreamUtils.h"

// -- Debug library
#include <ArduinoTrace.h>

//----------------------------------------------------------------------------//
//                          Include all project file                          //
//----------------------------------------------------------------------------//

// - - Configuration file (at compile time)
#include "Configuration\Path.hpp" // Path list

// - - Modules
#include "Module.hpp" // Module class
#include "Log/Log.hpp"

#include "Account\Account.hpp"
#include "Clipboard\Clipboard.hpp"
#include "Communication\Communication.hpp"
#include "Display\Display.hpp"
#include "Drive\Drive.hpp"
#include "Flash\Flash.hpp"
#include "GPIO\GPIO.hpp"
#include "Graphical_Interface\Graphical_Interface.hpp"
#include "Keyboard\Keyboard.hpp"
#include "Mathematics\Mathematics.hpp"
#include "Memory\Memory.hpp"
#include "Power\Power.hpp"
#include "Software\Software.hpp"
//#include "Sound\Sound.hpp"
#include "System\System.hpp"
#include "Time\Time.hpp"

//----------------------------------------------------------------------------//
//                                Define Const                                //
//----------------------------------------------------------------------------//

///
/// @brief Memory chunk macro.
///
#define Memory_Chunk(x) (x * 1024)

//----------------------------------------------------------------------------//
//                         Define Xila Core API                               //
//----------------------------------------------------------------------------//

class Shell_Class;

///
/// @class Xila_Class
///
/// @brief Core class.
///
/// @details Contain all core A.P.I. and modules to make the kernel working.
///
namespace Xila_Namespace
{

    //==============================================================================//
    //                                 Constructors                                 //
    //==============================================================================//

    //==============================================================================//
    //                              Enumerations & Type definition                  //
    //==============================================================================//

    // - General types

    typedef Module_Class::Size_Type Size_Type;
    typedef Module_Class::Result Result;
    typedef Module_Class::Module Module;
    typedef Module_Class::Time_Type Time_Type;
    typedef Module_Class::Instruction_Type Instruction_Type;
    typedef Module_Class::Task_Class Task_Class;

    // - Graphical interface objects.

    typedef Graphical_Interface_Class::Object_Type Object_Type;
    typedef Graphical_Interface_Class::Arc_Type Arc_Type;
    typedef Graphical_Interface_Class::Bar_Type Bar_Type;
    typedef Graphical_Interface_Class::Button_Type Button_Type;
    typedef Graphical_Interface_Class::Button_Matrix_Type Button_Matrix_Type;
    typedef Graphical_Interface_Class::Canvas_Type Canvas_Type;
    typedef Graphical_Interface_Class::Checkbox_Type Checkbox_Type;
    typedef Graphical_Interface_Class::Drop_Down_List_Type Drop_Down_List_Type;
    typedef Graphical_Interface_Class::Image_Type Image_Type;
    typedef Graphical_Interface_Class::Line_Type Line_Type;
    typedef Graphical_Interface_Class::Roller_Type Roller_Type;
    typedef Graphical_Interface_Class::Slider_Type Slider_Type;
    typedef Graphical_Interface_Class::Switch_Type Switch_Type;
    typedef Graphical_Interface_Class::Table_Type Table_Type;
    typedef Graphical_Interface_Class::Text_Area_Type Text_Area_Type;
    typedef Graphical_Interface_Class::Calendar_Type Calendar_Type;
    // typedef Chart_Class Chart_Type Type;
    typedef Graphical_Interface_Class::Color_Wheel_Type Color_Wheel_Type;
    typedef Graphical_Interface_Class::Keyboard_Type Keyboard_Type;
    typedef Graphical_Interface_Class::List_Type List_Type;
    // typedef Menu_Class Menu_Type Type;
    // typedef Meter_Class Meter_Type Type;
    typedef Graphical_Interface_Class::Tabs_Type Tabs_Type;
    typedef Graphical_Interface_Class::Window_Type Window_Type;

    //==============================================================================//
    //                                Public modules declaration                    //
    //==============================================================================//

    Account_Class Account;

    Clipboard_Class Clipboard;

    Display_Class Display;

    Drive_Class Drive;
    typedef Drive_Class Drive_Class;

    Flash_Class Flash;

    Pin_Class Pin;

    Graphical_Interface_Class Graphical_Interface;

    Keyboard_UI_Class Keyboard;

    Mathematics_Class Mathematics;

    Memory_Class Memory;

    Power_Class Power;

    typedef Software_Class Software_Type;

    typedef Software_Handle_Class Software_Handle_Type;

    // Sound_Class Sound;

    System_Class System;

    WiFi_Class WiFi;
};

namespace Xila = Xila_Namespace;

#endif