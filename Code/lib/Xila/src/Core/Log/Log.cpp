///
/// @file Log.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 13-03-2023
///
/// @copyright Copyright (c) 2023
///

#include "Core/Log/Log.hpp"

using namespace Xila_Namespace;

Log_Type Xila_Namespace::Log;

Log_Class::Log_Class() : Semaphore_Handle(NULL)
{
    xSemaphoreHandle Semaphore_Handle = xSemaphoreCreateMutexStatic(&Semaphore_Buffer);
    if (Semaphore_Handle == NULL)
    {
        Print_Static("Failed to create log semaphore !\r\n");
    }

    //if (Semaphore.Create(Semaphore_Class::Type_Type::Mutex) != Result_Type::Success)
    //{
    //    Print_Static("Failed to create log semaphore !\r\n");
    //}

    Print_Static("Semaphore created.\r\n");
}