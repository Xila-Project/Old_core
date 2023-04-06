/// @file Queue.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 06-04-2023
///
/// @copyright Copyright (c) 2023

#ifndef Queue_Hpp_Included
#define Queue_Hpp_Included

#include "Base_Types.hpp"

namespace Xila_Namespace
{

    typedef class Queue_Class
    {
    public:
        // - Methods

        // - - Constructors / Destructors

        Queue_Class();

        /// @brief Create a new queue.
        /// @param Length Length of the queue.
        /// @param Item_Size Size of each item in the queue.
        /// @return Result_Type
        Result_Type Create(Size_Type Length, Size_Type Item_Size);

        /// @brief Delete the queue.
        void Delete();

        // - - Operations

        void Send(const void* Item_To_Send, uint32_t Time = 0xFFFFFFFF);
        void Send_To_Back(const void* Item_To_Send, uint32_t Time = 0xFFFFFFFF);
        void Send_To_Front(const void* Item_To_Send, uint32_t Time = 0xFFFFFFFF);
        void Overwrite(const void* Item_To_Send);

        void Receive(void* Buffer, uint32_t Time = 0xFFFFFFFF);

         /// @brief Return an item from the queue without removing it. 
         /// @param Buffer Buffer to store the item.
         /// @param Time Timeout to receive the item in milliseconds.
        void Peek(void* Buffer, uint32_t Time = 0xFFFFFFFF);

        Size_Type Get_Available();
        Size_Type Get_Free_Space();

        /// @brief Clear the queue (make it empty).
        void Clear();

    private:

        /// @brief Handle of the queue.
        QueueHandle_t Handle;
    } Queue_Type;

}

#endif // Queue_Hpp_Included