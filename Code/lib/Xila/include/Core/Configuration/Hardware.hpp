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

class Hardware_Class
{

    enum Display_Enumeration
    {
        WT32_SC01
    };

    enum Drive_Enumeration
    {
        SD_MMC,
        SD_SPI
    };
};

 #endif