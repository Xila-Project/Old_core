///
/// @file Regular_Battery.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 13-11-2022
///
/// @copyright Copyright (c) 2022
///

#include "Power/Power.hpp"

#include "Battery_Library.hpp"

#if defined(Xila_Power_Battery_Default_Sensing_Pin) && defined(Xila_Power_Battery_Default_Minimum_Voltage) && defined(Xila_Power_Battery_Default_Maximum_Voltage) && defined(Xila_Power_Battery_Default_Conversion_Factor)
Battery_Class Battery(Xila_Power_Battery_Default_Sensing_Pin, Xila_Power_Battery_Default_Minimum_Voltage, Xila_Power_Battery_Default_Maximum_Voltage, Xila_Power_Battery_Default_Conversion_Factor);
#endif

using namespace Xila_Namespace;

uint8_t Power_Class::Get_Battery_Charge_Level()
{
#ifdef Xila_Power_Battery_Default_Sensing_Pin
    return Battery.Get_Charge_Level();
#else
    return 100;
#endif
}

uint16_t Power_Class::Get_Battery_Voltage()
{
#ifdef Xila_Power_Battery_Default_Sensing_Pin
    return Battery.Get_Voltage();
#else
    return 0;
#endif
}
