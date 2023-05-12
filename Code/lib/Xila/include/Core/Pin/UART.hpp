 /// @file UART.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 12-05-2023
 /// 
 /// @copyright Copyright (c) 2023
 
#include "Arduino.h"
#include "Stream.hpp"

 namespace Xila_Namespace
 {
    namespace Pin_Types
    {
        typedef class Serial_Class : public Xila_Namespace::Stream_Type
        {
            Serial_Class();


        private:

            HardwareSerial Hadware_Serial;



        } Serial_Type;
    }
 }