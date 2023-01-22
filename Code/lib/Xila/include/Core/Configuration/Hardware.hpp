///
/// @file Hardware.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 24-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Hardware_Hpp_Included
#define Hardware_Hpp_Included

#include "Arduino.h"

// - Display hardware enumeration
#define Display_None                            0
#define Display_Wireless_Tag_WT32_SC01          1
#define Display_Wireless_Tag_WT32_SC01_Plus     2

// - Drive hardware enumeration

#define Drive_None      0
#define Drive_SD_MMC    1
#define Drive_SD_SPI    2

// - WiFi hardware enumeration

#define WiFi_Hardware_None      0
#define WiFi_Hardware_ESP32     1

// - Power hardware enumeration
#define Battery_None        0
#define Regular_Battery     1

// - Keyboard hardware enumeration

#define Keyboard_Hardware_None  0
#define Keyboard_Hardware_PS2   1

#endif