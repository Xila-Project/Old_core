#ifndef BATTERY_H_INCLUDED
#define BATTERY_H_INCLUDED

#include "Arduino.h"

/* Conversion factor =  With a voltage divider with 1:1 relation (here 47 kOhm / 47 kOhm)*/

class Battery_Class
{
protected:
    uint8_t Sensing_Pin;
    float Conversion_Factor;
    const float Voltage_Table[101] = {
        3.200,
        3.250,
        3.300,
        3.350,
        3.400,
        3.450,
        3.500,
        3.550,
        3.600,
        3.650,
        3.700,
        3.703,
        3.706,
        3.710,
        3.713,
        3.716,
        3.719,
        3.723,
        3.726,
        3.729,
        3.732,
        3.735,
        3.739,
        3.742,
        3.745,
        3.748,
        3.752,
        3.755,
        3.758,
        3.761,
        3.765,
        3.768,
        3.771,
        3.774,
        3.777,
        3.781,
        3.784,
        3.787,
        3.790,
        3.794,
        3.797,
        3.800,
        3.805,
        3.811,
        3.816,
        3.821,
        3.826,
        3.832,
        3.837,
        3.842,
        3.847,
        3.853,
        3.858,
        3.863,
        3.868,
        3.874,
        3.879,
        3.884,
        3.889,
        3.895,
        3.900,
        3.906,
        3.911,
        3.917,
        3.922,
        3.928,
        3.933,
        3.939,
        3.944,
        3.950,
        3.956,
        3.961,
        3.967,
        3.972,
        3.978,
        3.983,
        3.989,
        3.994,
        4.000,
        4.008,
        4.015,
        4.023,
        4.031,
        4.038,
        4.046,
        4.054,
        4.062,
        4.069,
        4.077,
        4.085,
        4.092,
        4.100,
        4.111,
        4.122,
        4.133,
        4.144,
        4.156,
        4.167,
        4.178,
        4.189,
        4.200,
    };

    uint16_t Current_Level;

public:
    uint8_t Get_Charge_Level();

    Battery_Class(uint8_t Battery_Sensing_Pin = 12, float Resistor_1 = 47, float Resistor_2 = 47);
    ~Battery_Class();
};

#endif