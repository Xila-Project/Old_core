///
/// @file Memory.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Memory/Memory.hpp"

using namespace Xila_Namespace;

Memory_Type Xila_Namespace::Memory;

Size_Type Xila_Namespace::Memory_Class::Get_Free_Heap()
{
    return ESP.getFreeHeap();
}

Size_Type Xila_Namespace::Memory_Class::Get_Heap_Size()
{
    return ESP.getHeapSize();
}

Size_Type Xila_Namespace::Memory_Class::Get_Minimum_Free_Heap()
{
    return ESP.getMinFreeHeap();
}

Size_Type Xila_Namespace::Memory_Class::Get_Maximum_Allocated_Heap()
{
    return ESP.getMaxAllocHeap();
}

Size_Type Xila_Namespace::Memory_Class::Get_PSRAM_Size()
{
    return ESP.getPsramSize();
}

Size_Type Xila_Namespace::Memory_Class::Get_Free_PSRAM()
{
    return ESP.getFreePsram();
}

Size_Type Xila_Namespace::Memory_Class::Get_Minimum_Free_PSRAM()
{
    return ESP.getMinFreePsram();
}

Size_Type Xila_Namespace::Memory_Class::Get_Maximum_Allocated_PSRAM()
{
    return ESP.getMaxAllocPsram();
}