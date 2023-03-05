///
/// @file Semaphore.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 19-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Module/Semaphore.hpp"
#include "Core/Log/Log.hpp"

using namespace Xila_Namespace;

Semaphore_Class::Semaphore_Class() : Semaphore_Handle(NULL)
{
}

Result_Type Semaphore_Class::Create(Type_Type Type, unsigned int Initial_Count, unsigned int Maximum_Count)
{
    if (Semaphore_Handle != NULL)
    {
        return Result_Type::Error;
    }

    switch (Type)
    {
    case Type_Type::Binary:
        Semaphore_Handle = xSemaphoreCreateBinary();
        break;
    case Type_Type::Counting:
        Semaphore_Handle = xSemaphoreCreateCounting(Maximum_Count, Initial_Count);
        break;
    case Type_Type::Mutex:
        Semaphore_Handle = xSemaphoreCreateMutex();
        this->Give();
        break;
    default:
        return Result_Type::Error;
    }

    if (Semaphore_Handle == NULL)
    {
        return Result_Type::Error;
    }

    return Result_Type::Success;
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

Result_Type Semaphore_Class::Take(uint32_t Timeout)
{
    Log_Verbose("Semaphore", "Try semaphore");
    if (Timeout == 0xFFFFFFFF)
    {
        Log_Verbose("Semaphore", "Wait forever");
        if (xSemaphoreTake(Semaphore_Handle, 0) == pdFALSE)
        {
            Log_Verbose("Semaphore", "Wait failed");
            return Result_Type::Error;
        }
        Log_Verbose("Semaphore", "Wait ended");
    }
    else if (xSemaphoreTake(Semaphore_Handle, pdMS_TO_TICKS(Timeout)) == pdFALSE)
    {
        return Result_Type::Error;
    }
    Log_Verbose("Semaphore", "Semaphore taken");
    return Result_Type::Success;
}

void Semaphore_Class::Give_From_ISR(Integer_Type *Higher_Priority_Task_Woken)
{
    xSemaphoreGiveFromISR(Semaphore_Handle, Higher_Priority_Task_Woken);
}

void Semaphore_Class::Take_From_ISR(Integer_Type *Higher_Priority_Task_Woken)
{
    xSemaphoreTakeFromISR(Semaphore_Handle, Higher_Priority_Task_Woken);
}

void Semaphore_Class::Take_Recursive(Tick_Type Ticks_To_Wait)
{
    xSemaphoreTakeRecursive(Semaphore_Handle, Ticks_To_Wait);
}

void Semaphore_Class::Give_Recursive()
{
    xSemaphoreGiveRecursive(Semaphore_Handle);
}

/*
Task_Type Semaphore_Class::Get_Mutex_Holder()
{
    // TODO : Implement

}*/

unsigned int Semaphore_Class::Get_Count()
{
    return uxSemaphoreGetCount(Semaphore_Handle);
}