#ifndef BATTERY_H_INCLUDED
#define BATTERY_H_INCLUDED

#include "Arduino.h"

class Battery_Class
{
    protected:
        uint8_t Get_Current_Level();
        Battery_Class(uint8_t);
        ~Battery_Class();
};

#endif