///
/// @file Semaphore.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 25-01-2023
///
/// @copyright Copyright (c) 2023
///

#ifndef Semaphore_Hpp_Included
#define Semaphore_Hpp_Included

#include "Arduino.h"
#include "Base_Types.hpp"

namespace Xila_Namespace
{
    /// @brief Xila Semaphore type.
    typedef class Semaphore_Class
    {
    public:
     
        enum class Type_Type 
        {
            Binary,
            Counting,
            Mutex,
            Recursive_Mutex
        };

        Semaphore_Class();

        Result_Type Create(Type_Type Type, unsigned int Initial_Count, unsigned int Maximum_Count);
        // Event_Type Create_Static()

        void Delete();
        Result_Type Take(uint32_t Timeout = 0xFFFFFFFF);
        void Take_Recursive(Tick_Type Tick_To_Wait);
        void Give();
        void Take_From_ISR(Integer *Higher_Priority_Task_Woken);
        void Give_From_ISR(Integer *Higher_Priority_Task_Woken);
        void Take_Recursive();
        void Give_Recursive();
        // Task_Type Get_Mutex_Holder();
        unsigned int Get_Count();

    private:
        SemaphoreHandle_t Semaphore_Handle;
    } Semaphore_Type;

}

#endif