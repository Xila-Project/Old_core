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
#include "Task.hpp"

typedef SemaphoreHandle_t Semaphore_Handle_Type;
typedef StaticSemaphore_t Static_Semaphore_Type;

class Semaphore_Class
{
public:
    typedef enum
    {
        Binary,
        Counting,
        Mutex,
        Recursive_Mutex
    } Type_Type;

    Semaphore_Class();

    Event_Type Create(Type_Type Type, unsigned int Initial_Count, unsigned int Maximum_Count);
    // Event_Type Create_Static()

    void Delete();
    void Take(uint32_t Timeout = 0xFFFFFFFF);
    void Give();
    void Take_From_ISR(signed int *Higher_Priority_Task_Woken);
    void Give_From_ISR(signed int *Higher_Priority_Task_Woken);
    void Take_Recursive();
    void Give_Recursive();
    Task_Class Get_Mutex_Holder();
    unsigned int Get_Count();

private:
    SemaphoreHandle_t Semaphore_Handle;
}

#endif