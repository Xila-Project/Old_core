///
/// @file Memory.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 24-06-2021
///
/// @copyright Copyright (c) 2021
///

#include "Arduino.h"

#ifndef MEMORY_HPP_INCLUDED
#define MEMORY_HPP_INCLUDED

///
/// @brief Return the amount of free heap.
///
/// @return uint32_t
inline uint32_t Xila_Class::Memory_Class::Get_Free_Heap()
{
    return heap_caps_get_free_size(MALLOC_CAP_INTERNAL);
}

inline uint32_t Xila_Class::Memory_Class::Get_Heap_Size()
{
    multi_heap_info_t info;
    heap_caps_get_info(&info, MALLOC_CAP_INTERNAL);
    return info.total_free_bytes + info.total_allocated_bytes;
}

inline uint32_t Xila_Class::Memory_Class::Get_Minimum_Free_Heap()
{
    return heap_caps_get_minimum_free_size(MALLOC_CAP_INTERNAL);
}

inline uint32_t Xila_Class::Memory_Class::Get_Maximum_Allocated_Heap()
{
    return heap_caps_get_largest_free_block(MALLOC_CAP_INTERNAL);
}

inline uint32_t Xila_Class::Memory_Class::Get_PSRAM_Size()
{
    multi_heap_info_t info;
    heap_caps_get_info(&info, MALLOC_CAP_SPIRAM);
    return info.total_free_bytes + info.total_allocated_bytes;
}

inline uint32_t Xila_Class::Memory_Class::Get_Free_PSRAM()
{
    return heap_caps_get_free_size(MALLOC_CAP_SPIRAM);
}

inline uint32_t Xila_Class::Memory_Class::Get_Minimum_Free_PSRAM()
{
    return heap_caps_get_minimum_free_size(MALLOC_CAP_SPIRAM);
}

inline uint32_t Xila_Class::Memory_Class::Get_Maximum_Allocated_PSRAM()
{
    return heap_caps_get_largest_free_block(MALLOC_CAP_SPIRAM);
}

#endif