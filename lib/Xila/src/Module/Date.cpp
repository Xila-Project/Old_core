///
/// @file Date.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 22-02-2023
///
/// @copyright Copyright (c) 2023
///

#include "Module/Date.hpp"

using namespace Xila_Namespace;

Date_Class::Date_Class() : Day(0), Month(0), Year(0)
{
}

Date_Class::Date_Class(uint8_t Day, uint8_t Month, uint16_t Year) : Day(Day), Month(Month), Year(Year)
{}

Date_Class::Date_Class(const Date_Class &Date) : Day(Date.Day), Month(Date.Month), Year(Date.Year)
{}

void Date_Class::Set(uint8_t Day, uint8_t Month, uint16_t Year)
{
    this->Day = Day;
    this->Month = Month;
    this->Year = Year;
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

bool Date_Class::Is_Valid()
{
    return Is_Valid(this->Day, this->Month, this->Year);
}

bool Date_Class::Is_Valid(uint8_t Day, uint8_t Month, uint16_t Year)
{
    bool Leap_Year = ((Year % 4) == 0 && (Year % 100) != 0) || (Year % 400) == 0;
    bool Month_30_Days = (Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day <= 30;
    bool Month_February = Month == 2 && ((Leap_Year && Day <= 29) || Day <= 28);
    bool Month_31_Days = (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12);

    return (Month_30_Days || Month_February || Month_31_Days);
}

// - - Operators

bool Date_Class::operator==(const Date_Class &Date)
{
    return (Day == Date.Day && Month == Date.Month && Year == Date.Year);
}

bool Date_Class::operator!=(const Date_Class &Date)
{
    return !(*this == Date);
}

bool Date_Class::operator<(const Date_Class &Date)
{
    return (Year < Date.Year || (Year == Date.Year && (Month < Date.Month || (Month == Date.Month && Day < Date.Day))));
}

bool Date_Class::operator<=(const Date_Class &Date)
{
    return (*this < Date || *this == Date);
}

bool Date_Class::operator>(const Date_Class &Date)
{
    return !(*this <= Date);
}

bool Date_Class::operator>=(const Date_Class &Date)
{
    return !(*this < Date);
}