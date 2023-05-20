///
/// @file Semaphore.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 19-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Module/Semaphore.hpp"
#include "Module/Task.hpp"
#include "Log/Log.hpp"

using namespace Xila_Namespace;

// - Methods

// - - Constructors

/// @brief Construct a new Semaphore object.
Semaphore_Class::Semaphore_Class() : Semaphore_Handle(NULL)
{
}

Semaphore_Class::Semaphore_Class(const Semaphore_Class& Semaphore_To_Copy) : Semaphore_Handle(Semaphore_To_Copy.Semaphore_Handle)
{
}

Result_Type Semaphore_Class::Create(Semaphore_Type_Type Type, unsigned int Initial_Count, unsigned int Maximum_Count)
{
    if (Semaphore_Handle != NULL)
    {
        return Result_Type::Error;
    }

    switch (Type)
    {
    case Semaphore_Type_Type::Binary:
        Semaphore_Handle = xSemaphoreCreateBinary();
        break;
    case Semaphore_Type_Type::Counting:
        Semaphore_Handle = xSemaphoreCreateCounting(Maximum_Count, Initial_Count);
        break;
    case Semaphore_Type_Type::Mutex:
        Semaphore_Handle = xSemaphoreCreateMutex();
        break;
    case Semaphore_Type_Type::Recursive_Mutex:
        Semaphore_Handle = xSemaphoreCreateRecursiveMutex();
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
    if (Timeout == 0xFFFFFFFF)
    {
        if (xSemaphoreTake(Semaphore_Handle, portMAX_DELAY) == pdFALSE)
        {
            return Result_Type::Error;
        }
    }
    else if (xSemaphoreTake(Semaphore_Handle, pdMS_TO_TICKS(Timeout)) == pdFALSE)
    {
        return Result_Type::Error;
    }
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

Result_Type Semaphore_Class::Take_Recursive(uint32_t Timeout)
{
    if (Timeout == 0xFFFFFFFF)
    {
        if (xSemaphoreTakeRecursive(Semaphore_Handle, portMAX_DELAY) == pdFALSE)
        {
            return Result_Type::Error;
        }
    }
    else if (xSemaphoreTakeRecursive(Semaphore_Handle, pdMS_TO_TICKS(Timeout)) == pdFALSE)
    {

        return Result_Type::Error;
    }
    return Result_Type::Success;
}

void Semaphore_Class::Give_Recursive()
{
    xSemaphoreGiveRecursive(Semaphore_Handle);
}

unsigned int Semaphore_Class::Get_Count()
{
    return uxSemaphoreGetCount(Semaphore_Handle);
}

Auto_Semaphore_Type Semaphore_Class::Take_Auto(uint32_t Timeout)
{
    //return Auto_Semaphore_Type(*this, Timeout);
    return Auto_Semaphore_Type(*this, Timeout);
}

Task_Type Semaphore_Class::Get_Mutex_Holder()
{
    return Task_Type(xSemaphoreGetMutexHolder(Semaphore_Handle));
}

bool Semaphore_Class::Is_Valid()
{
    return Semaphore_Handle != NULL;
}