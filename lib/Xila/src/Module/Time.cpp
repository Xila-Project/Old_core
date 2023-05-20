///
/// @file Time.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 22-02-2023
///
/// @copyright Copyright (c) 2023
///

#include "Module/Time.hpp"

using namespace Xila_Namespace;

Time_Class::Time_Class() : Hours(0), Minutes(0), Seconds(0), Milliseconds(0)
{
}

Time_Class::Time_Class(uint8_t Hours, uint8_t Minutes, uint8_t Seconds, uint16_t Milliseconds) : Hours(Hours), Minutes(Minutes), Seconds(Seconds), Milliseconds(Milliseconds)
{
}

void Time_Class::Set(uint8_t Hours, uint8_t Minutes, uint8_t Seconds, uint16_t Milliseconds)
{
    Set_Hours(Hours);
    Set_Minutes(Minutes);
    Set_Seconds(Seconds);
    Set_Milliseconds(Milliseconds);
}

void Time_Class::Set_Hours(uint8_t Hours)
{
    this->Hours = Hours;
}

void Time_Class::Set_Minutes(uint8_t Minutes)
{
    this->Minutes = Minutes;
}

void Time_Class::Set_Seconds(uint8_t Seconds)
{
    this->Seconds = Seconds;
}

void Time_Class::Set_Milliseconds(uint16_t Milliseconds)
{
    this->Milliseconds = Milliseconds;
}

uint8_t Time_Class::Get_Hours()
{
    return Hours;
}

uint8_t Time_Class::Get_Minutes()
{
    return Minutes;
}

uint8_t Time_Class::Get_Seconds()
{
    return Seconds;
}

uint16_t Time_Class::Get_Milliseconds()
{
    return Milliseconds;
}
