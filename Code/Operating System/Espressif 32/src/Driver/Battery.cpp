#include "Driver/Battery.hpp"

Battery_Class::Battery_Class(uint8_t Battery_Sensing_Pin, float Resistor_1, float Resistor_2)
{
    Sensing_Pin = Battery_Sensing_Pin;
    // Calculate conversion factor (maximum output voltage of the voltage divider)
    Conversion_Factor = (Voltage_Table[100] * Resistor_2);
    Conversion_Factor /= (Resistor_2 + Resistor_1);
}

Battery_Class::~Battery_Class()
{

}

uint8_t Battery_Class::Get_Charge_Level()
{
    Current_Level = (analogRead(Sensing_Pin) * Conversion_Factor) / 4095;
    // Find matching percentage value for a given voltage
    for (uint8_t i = 100; i > 0; i--)
    {
        if (Current_Level > Voltage_Table[i])
        {
            return i;
        }
    }
    return 0;
}
