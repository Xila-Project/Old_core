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
#include "Core/Module/Task.hpp"
#include "Core/Log/Log.hpp"

using namespace Xila_Namespace;

/// @brief Construct a new Semaphore object.
Semaphore_Class::Semaphore_Class() : Semaphore_Handle(NULL)
{
}

/// @brief Create a new Semaphore.
/// @param Type Semaphore type (Binary, Counting, Mutex, Recursive_Mutex).
/// @param Initial_Count Initial count (for Counting semaphore).
/// @param Maximum_Count Maximum count (for Counting semaphore).
/// @return `Result_Type::Success` if the semaphore was created, Result_Type::Error otherwise.
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
        break;
    case Type_Type::Recursive_Mutex:
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
    Log_Verbose("Semaphore", "Current task try to take : %s", Task_Type(xTaskGetCurrentTaskHandle()).Get_Name());
    if (this->Get_Mutex_Holder().Get_State() != Task_Type::State_Type::Invalid)
    {
        Log_Verbose("Semaphore", "Currently taken by : %s", this->Get_Mutex_Holder().Get_Name());
    }
    else
    {
        Log_Verbose("Semaphore", "Currently taken by : None");
    }

    if (Timeout == 0xFFFFFFFF)
    {
        Log_Verbose("Semaphore", "Waiting for semaphore...")
        if (xSemaphoreTakeRecursive(Semaphore_Handle, portMAX_DELAY) == pdFALSE)
        {
            return Result_Type::Error;
        }
        Log_Verbose("Semaphore", "Taken by : %s", this->Get_Mutex_Holder().Get_Name());
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

    Log_Verbose("Semaphore", "Given by : %s", this->Get_Mutex_Holder().Get_Name());
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

Auto_Semaphore_Type Semaphore_Class::Take_Auto(uint32_t Timeout)
{
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