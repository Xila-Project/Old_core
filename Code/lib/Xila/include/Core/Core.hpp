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
#ifndef Core_Hpp_Included
#define Core_Hpp_Included

#ifdef __cplusplus

#else

#error Xila requires a C++ complier

#endif

// - Include all the required dependencies

// -  Arduino framework
#include "Arduino.h"

// - Xila's modules
#include "Account/Accounts.hpp"
#include "Clipboard/Clipboard.hpp"
#include "Communication/Communication.hpp"
#include "Display/Display.hpp"
#include "Drive/Drive.hpp"
#include "Flash/Flash.hpp"
#include "Graphics/Graphics.hpp"
#include "Keyboard/Keyboard.hpp"
#include "Mathematics/Mathematics.hpp"
#include "Memory/Memory.hpp"
#include "Pin/Pin.hpp"
#include "Power/Power.hpp"
#include "Software/Software.hpp"
#include "Software/Software_Handle.hpp"
#include "Software/Softwares.hpp"
#include "Sound/Sound.hpp"
#include "System/System.hpp"

/// @brief Xila namespace
/// @details Gather all the parts used by Xila core : modules, types, sub-namespaces etc.
namespace Xila_Namespace
{
};

namespace Xila = Xila_Namespace;

#endif