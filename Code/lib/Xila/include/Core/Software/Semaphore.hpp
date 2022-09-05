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
#include "../Module.hpp"

class Semaphore_Class : public Module_Class
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

    Result::Type Create(Type_Type Type, unsigned int Initial_Count, unsigned int Maximum_Count);
    // Event_Type Create_Static()

    void Delete();
    void Take(uint32_t Timeout = 0xFFFFFFFF);
    void Take_Recursive(Tick_Type Tick_To_Wait);
    void Give();
    void Take_From_ISR(Integer *Higher_Priority_Task_Woken);
    void Give_From_ISR(Integer *Higher_Priority_Task_Woken);
    void Take_Recursive();
    void Give_Recursive();
    Task_Class Get_Mutex_Holder();
    unsigned int Get_Count();

private:
    SemaphoreHandle_t Semaphore_Handle;
};

#endif