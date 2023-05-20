///
/// @file Regular_Battery.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 13-11-2022
///
/// @copyright Copyright (c) 2022
///

#if Power_Hardware == Regular_Battery

#include "Core/Power/Power.hpp"

#include "Battery_Library.hpp"

//Battery_Class Battery(Default_Battery_Sensing_Pin, Default_Battery_Minimum_Voltage, Default_Battery_Maximum_Voltage, Default_Battery_Conversion_Factor);

using namespace Xila_Namespace;

uint8_t Power_Class::Get_Battery_Charge_Level()
{
    //return Battery.Get_Charge_Level();
    return 0;
}

uint16_t Power_Class::Get_Battery_Voltage()
{
    //return Battery.Get_Voltage();
    return 0;
}

#endif