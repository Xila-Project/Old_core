/// @file Header.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief Main header file
/// @version 0.1.0
/// @date 14-03-2023
///
/// @copyright Copyright (c) 2023

#ifndef Header_Hpp_Included
#define Header_Hpp_Included

#ifdef ARDUINO
//    #define Arduino
#endif

#ifdef Arduino
#include "Arduino.h"
#endif

#ifdef Native
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#endif

#include <memory>

#define Stringize_Helper(x) #x
#define Stringize(x) Stringize_Helper(x)

#define Xila_Version_Major_String Stringize(Xila_Version_Major)
#define Xila_Version_Minor_String Stringize(Xila_Version_Minor)
#define Xila_Version_Revision_String Stringize(Xila_Version_Revision)

#define Xila_Version_String Xila_Version_Major_String "." Xila_Version_Minor_String "." Xila_Version_Revision_String

#endif