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
#include "Configuration\Path.hpp"          // Path list

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
class Xila_Class : public Module_Class
{
public:
    //==============================================================================//
    //                                 Constructors                                 //
    //==============================================================================//

    Xila_Class();
    ~Xila_Class();

    //==============================================================================//
    //                              Enumerations & Type definition                  //
    //==============================================================================//

    Account_Class Account;

    Clipboard_Class Clipboard;

    Display_Class Display;

    Drive_Class Drive;

    Flash_Class Flash;

    GPIO_Class GPIO;

    Graphical_Interface_Class Graphical_Interface;

    Keyboard_Class Keyboard;

    Mathematics_Class Mathematics;

    Memory_Class Memory;

    Power_Class Power;

    typedef Software_Class Software_Type;

    typedef Software_Handle_Class Software_Handle_Type;

    //Sound_Class Sound;

    System_Class System;

    WiFi_Class WiFi;

private:
    //==============================================================================//
    //                                    Attributes                                //
    //==============================================================================//

    ///
    /// @brief Current instance pointer. Help to prevent from corruption.
    ///
    static Xila_Class *Instance_Pointer;
};

extern Xila_Class Xila;

#endif