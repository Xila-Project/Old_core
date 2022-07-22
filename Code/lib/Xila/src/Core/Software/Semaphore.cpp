///
/// @file Semaphore.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 19-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Software/Semaphore.hpp"

Semaphore_Class::Semaphore_Class() : Semaphore_Handle(NULL)
{
}

Event_Type Semaphore_Class::Create(Type_Type Type, unsigned int Initial_Count, unsigned int Maximum_Count)
{
    if (Semaphore_Handle != NULL)
    {
        return Event_Type::Error;
    }

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

    if (Semaphore_Handle == NULL)
    {
        return Event_Type::Error;
    }
    else
    {
        return Event_Type::Success;
    }
}

/*
Static_Semaphore_Type Semaphore_Class::Create_Static(uint8_t Type, Static_Semaphore_Type *Semaphore_Buffer, UBaseType_t Initial_Count, UBaseType_t Maximum_Count)
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
}*/

void Semaphore_Class::Delete()
{
    vSemaphoreDelete(Semaphore_Handle);
}

void Semaphore_Class::Give()
{
    xSemaphoreGive(Semaphore_Handle);
}

Event_Type Semaphore_Class::Take(uint32_t Timeout)
{
    if (Timeout = 0xFFFFFFFFF)
    {
        xSemaphoreTake(Semaphore_Handle, portMAX_DELAY);
    }
    else
    {
        xSemaphoreTake(Semaphore_Handle, pdMS_TO_TICKS(Timeout));
    }
}

void Semaphore_Class::Give_From_ISR(, BaseType_t *Higher_Priority_Task_Woken)
{
    xSemaphoreGiveFromISR(Semaphore_Handle, Higher_Priority_Task_Woken);
}

void Semaphore_Class::Take_From_ISR(, BaseType_t *Higher_Priority_Task_Woken)
{
    xSemaphoreTakeFromISR(Semaphore_Handle, Higher_Priority_Task_Woken);
}

void Semaphore_Class::Take_Recursive(, Tick_Type Ticks_To_Wait)
{
    xSemaphoreTakeRecursive(Semaphore_Handle, Ticks_To_Wait);
}

void Semaphore_Class::Give_Recursive()
{
    xSemaphoreGiveRecursive(Semaphore_Handle);
}

void Semaphore_Class::Task_Class Get_Mutex_Holder()
{
    return xSemaphoreGetMutexHolder(Semaphore_Handle);
}

UBaseType_t Get_Count(Semaphore_Handle_Type Semaphore_Handle)
{
    return uxSemaphoreGetCount(Semaphore_Handle);
}