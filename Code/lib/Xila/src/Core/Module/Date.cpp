///
/// @file Date.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 22-02-2023
///
/// @copyright Copyright (c) 2023
///

#include "Core/Module/Date.hpp"

using namespace Xila_Namespace;

Date_Class::Date_Class() : Day(0), Month(0), Year(0)
{
}

Date_Class::Date_Class(uint8_t Day, uint8_t Month, uint16_t Year) : Day(Day), Month(Month), Year(Year)
{
}

void Date_Class::Set(uint8_t Day, uint8_t Month, uint16_t Year)
{
    Set_Day(Day);
    Set_Month(Month);
    Set_Year(Year);
}

void Date_Class::Set_Day(uint8_t Day)
{
    this->Day = Day;
}

void Date_Class::Set_Month(uint8_t Month)
{
    this->Month = Month;
}

void Date_Class::Set_Year(uint16_t Year)
{
    this->Year = Year;
}

uint8_t Date_Class::Get_Day()
{
    return Day;
}

uint8_t Date_Class::Get_Month()
{
    return Month;
}

uint16_t Date_Class::Get_Year()
{
    return Year;
}

