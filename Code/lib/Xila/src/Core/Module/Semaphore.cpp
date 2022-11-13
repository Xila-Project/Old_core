///
/// @file Semaphore.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 19-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Module.hpp"

using namespace Xila_Namespace;

Module_Class::Semaphore_Class::Semaphore_Class() : Semaphore_Handle(NULL)
{
}

Module_Class::Result::Type Module_Class::Semaphore_Class::Create(Type_Type Type, unsigned int Initial_Count, unsigned int Maximum_Count)
{
    if (Semaphore_Handle != NULL)
    {
        return Result::Error;
    }

    switch (Type)
    {
    case Binary:
        Semaphore_Handle = xSemaphoreCreateBinary();
        break;
    case Counting:
        Semaphore_Handle = xSemaphoreCreateCounting(Maximum_Count, Initial_Count);
        break;
    case Mutex:
        Semaphore_Handle = xSemaphoreCreateMutex();
        break;
    default:
        break;
    }

    if (Semaphore_Handle == NULL)
    {
        return Result::Error;
    }
    else
    {
        return Result::Success;
    }
}

/*
Static_Semaphore_Type Module_Class::Semaphore_Class::Create_Static(uint8_t Type, Static_Semaphore_Type *Semaphore_Buffer, UBaseType_t Initial_Count, UBaseType_t Maximum_Count)
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

void Module_Class::Semaphore_Class::Delete()
{
    vSemaphoreDelete(Semaphore_Handle);
}

void Module_Class::Semaphore_Class::Give()
{
    xSemaphoreGive(Semaphore_Handle);
}

Module_Class::Result::Type Module_Class::Semaphore_Class::Take(uint32_t Timeout)
{
    if (Timeout = 0xFFFFFFFFF)
    {
        if (xSemaphoreTake(Semaphore_Handle, portMAX_DELAY) == pdFALSE)
        {
            return Result::Error;
        }
        else
        {
            return Result::Success;
        }
    }
    else
    {
        if (xSemaphoreTake(Semaphore_Handle, pdMS_TO_TICKS(Timeout)) == pdFALSE)
        {
            return Result::Error;
        }
        else
        {
            return Result::Success;
        }
    }
}

void Module_Class::Semaphore_Class::Give_From_ISR(Integer *Higher_Priority_Task_Woken)
{
    xSemaphoreGiveFromISR(Semaphore_Handle, Higher_Priority_Task_Woken);
}

void Module_Class::Semaphore_Class::Take_From_ISR(Integer *Higher_Priority_Task_Woken)
{
    xSemaphoreTakeFromISR(Semaphore_Handle, Higher_Priority_Task_Woken);
}

void Module_Class::Semaphore_Class::Take_Recursive(Tick_Type Ticks_To_Wait)
{
    xSemaphoreTakeRecursive(Semaphore_Handle, Ticks_To_Wait);
}

void Module_Class::Semaphore_Class::Give_Recursive()
{
    xSemaphoreGiveRecursive(Semaphore_Handle);
}

/*
Module_Class::Task_Type Module_Class::Semaphore_Class::Get_Mutex_Holder()
{
    // TODO : Implement

}*/

unsigned int Module_Class::Semaphore_Class::Get_Count()
{
    return uxSemaphoreGetCount(Semaphore_Handle);
}