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

#include "../Module/Module.hpp"

//==============================================================================//
///
/// @brief Memory management class.
///

namespace Xila_Namespace
{
    namespace Memory_Types
    {        
    }


    /// @brief Memory management module.
    typedef class Memory_Class : public Module_Class
    {
    public:
        // -- Methods

        /// @brief Get the heap size.
        /// @return Size_Type
        Size_Type Get_Heap_Size();

        /// @brief Get the free heap.
        /// @return Size_Type
        Size_Type Get_Free_Heap();

        /// @brief Get the minimum free heap.
        /// @return Size_Type
        Size_Type Get_Minimum_Free_Heap();

        /// @brief Get the maximum allocated heap.
        /// @return Size_Type
        Size_Type Get_Maximum_Allocated_Heap();

        /// @brief Get the PSRAM size.
        /// @return Size_Type
        Size_Type Get_PSRAM_Size();

        /// @brief Get the free PSRAM.
        /// @return Size_Type
        Size_Type Get_Free_PSRAM();

        /// @brief Get the minimum free PSRAM.
        /// @return Size_Type
        Size_Type Get_Minimum_Free_PSRAM();

        /// @brief Get the maximum allocated PSRAM.
        /// @return Size_Type
        Size_Type Get_Maximum_Allocated_PSRAM();
    } Memory_Type;

    extern Memory_Type Memory;
}

#endif