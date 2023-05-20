///
/// @file Auto_Semaphore.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 07-03-2023
///
/// @copyright Copyright (c) 2023
///

#include "Core/Module/Semaphore.hpp"
#include "Core/Log/Log.hpp"

using namespace Xila_Namespace;

Auto_Semaphore_Class::Auto_Semaphore_Class(Semaphore_Type& Semaphore, uint32_t Timeout) : Semaphore_Handle(Semaphore.Semaphore_Handle)
{
    xSemaphoreTakeRecursive(Semaphore_Handle, Timeout);
}

Auto_Semaphore_Class::Auto_Semaphore_Class(const Auto_Semaphore_Type &Auto_Semaphore) : //Semaphore(Auto_Semaphore.Semaphore)
Semaphore_Handle(Auto_Semaphore.Semaphore_Handle)
{
    xSemaphoreTakeRecursive(Semaphore_Handle, portMAX_DELAY);
    Log_Verbose("Auto_Semaphore", "Auto_Semaphore copied");
    // Do take the semaphore since it's supposed to be already taken since an Auto_Semaphore_Class is invoked.
}


Auto_Semaphore_Class::~Auto_Semaphore_Class()
{
    xSemaphoreGiveRecursive(Semaphore_Handle);
}