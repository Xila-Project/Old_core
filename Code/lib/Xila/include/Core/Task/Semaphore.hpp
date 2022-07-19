///
/// @file Semaphore.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 04-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef SEMAPHORE_HPP_INCLUDED
#define SEMAPHORE_HPP_INCLUDED

#include "Arduino.h"

#define Class Xila_Class::Task_Class::Semaphore_Class // Shortcut

typedef SemaphoreHandle_t Semaphore_Handle_Type;
typedef StaticSemaphore_t Static_Semaphore_Type;

inline Semaphore_Handle_Type Class::Create(uint8_t Type, UBaseType_t Initial_Count, UBaseType_t Maximum_Count)
{
    switch (Type)
    {
    case Binary:
        return xSemaphoreCreateBinary();
        break;
    case Counting:
        return xSemaphoreCreateCounting(Maximum_Count, Initial_Count);
        break;
    case Mutex:
        return xSemaphoreCreateMutex();
        break;
    default:
        break;
    }
}

inline Static_Semaphore_Type Class::Create_Static(uint8_t Type, Static_Semaphore_Type *Semaphore_Buffer, UBaseType_t Initial_Count, UBaseType_t Maximum_Count)
{
    switch (Type)
    {
    case Binary:
        return xSemaphoreCreateBinaryStatic(Semaphore_Buffer);
        break;
    case Counting:
        return xSemaphoreCreateCountingStatic(Maximum_Count, Initial_Count, Semaphore_Buffer);
        break;
    case Mutex:
        return xSemaphoreCreateMutexStatic(Semaphore_Buffer);
        break;
    default:
        break;
    }
}

inline void Class::Delete(Semaphore_Handle_Type Semaphore_Handle)
{
    vSemaphoreDelete(Semaphore_Handle);
}

inline void Class::Give(Semaphore_Handle_Type Semaphore_Handle)
{
    xSemaphoreGive(Semaphore_Handle);
}

inline void Class::Take(Semaphore_Handle_Type Semaphore_Handle)
{
    xSemaphoreTake(Semaphore_Handle, portMAX_DELAY);
}

inline void Class::Give_From_ISR(Semaphore_Handle_Type Semaphore_Handle, BaseType_t *Higher_Priority_Task_Woken)
{
    xSemaphoreGiveFromISR(Semaphore_Handle, Higher_Priority_Task_Woken);
}

inline void Class::Take_From_ISR(Semaphore_Handle_Type Semaphore_Handle, BaseType_t *Higher_Priority_Task_Woken)
{
    xSemaphoreTakeFromISR(Semaphore_Handle, Higher_Priority_Task_Woken);
}

inline void Class::Take_Recursive(Semaphore_Handle_Type Semaphore_Handle, Tick_Type Ticks_To_Wait)
{
    xSemaphoreTakeRecursive(Semaphore_Handle, Ticks_To_Wait);
}

inline void Class::Give_Recursive(Semaphore_Handle_Type Semaphore_Handle)
{
    xSemaphoreGiveRecursive(Semaphore_Handle);
}

inline Xila_Class::Task_Class Get_Mutex_Holder(Semaphore_Handle_Type Semaphore_Handle)
{
    return xSemaphoreGetMutexHolder(Semaphore_Handle);
}

inline UBaseType_t Get_Count(Semaphore_Handle_Type Semaphore_Handle)
{
    return uxSemaphoreGetCount(Semaphore_Handle);
}

#endif