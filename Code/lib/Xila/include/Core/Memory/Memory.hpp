///
/// @file Memory.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 24-06-2021
///
/// @copyright Copyright (c) 2021
///

#ifndef Memory_Hpp_Included
#define Memory_Hpp_Included

#include "Arduino.h"
#include "../Module.hpp"

//==============================================================================//
///
/// @brief Memory management class.
///

namespace Xila_Namespace
{
    class Memory_Class : public Module_Class
    {
    public:
        // -- Methods

        uint32_t Get_Heap_Size();
        uint32_t Get_Free_Heap();
        uint32_t Get_Minimum_Free_Heap();
        uint32_t Get_Maximum_Allocated_Heap();

        uint32_t Get_PSRAM_Size();
        uint32_t Get_Free_PSRAM();
        uint32_t Get_Minimum_Free_PSRAM();
        uint32_t Get_Maximum_Allocated_PSRAM();
    } Memory;
}

#endif