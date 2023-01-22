///
/// @file Configuration.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Xila configuration header file.
/// @details Configure few parameters of Xila at compile time.
/// @version 0.1
/// @date 09-04-2021
///
/// @copyright Copyright (c) 2021
///

// Configuration File
#ifndef Configuration_Hpp_Included
#define Configuration_Hpp_Included

#include "Hardware.hpp"

// -- Default values -- //

#define Stringizing(x) #x

// -- Display

// -- Time

// -- Release configuration
#if CORE_DEBUG_LEVEL <= 1 // release mode

//#define ARDUINOTRACE_ENABLE 0 // Disable ArduinoTrace

#define Animations 1        // Enable animation
#define USB_Serial 1        // Disable USB Serial
#define Start_On_Power 1    // Start when Xila is powered up

// -- Debug configuration
#else

#define Animations 0        // Disable animation
#define USB_Serial 1        // Enable USB Serial
#define Start_On_Power 1    // 

#endif

#endif