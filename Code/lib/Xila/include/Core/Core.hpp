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

#error Xila requires a C++ complier

#endif

//============================================================================//
//                          Include required libraries                        //
//============================================================================//

// -- C++ standard library
#include <stdint.h>

// -- Arduino framework
#include "Arduino.h"

#include "Module.hpp"



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
    //                              Enumerations & Type definition                  //
    //==============================================================================//

    // - General types

    typedef Module_Class::Size_Type Size_Type;
    typedef Module_Class::Result Result;
    typedef Module_Class::Module Module;
    typedef Module_Class::Time_Type Time_Type;
    typedef Module_Class::Instruction_Type Instruction_Type;
    typedef Module_Class::Task_Class Task_Class;
};

namespace Xila = Xila_Namespace;

#endif