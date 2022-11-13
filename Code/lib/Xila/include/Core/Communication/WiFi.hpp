///
/// @file WiFi.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef WiFi_Hpp_Included
#define WiFi_Hpp_Included

#include "Arduino.h"
#include "../Module.hpp"

// -- WiFi libraries
#include "Print.h"
#include "IPAddress.h"
#include "IPv6Address.h"
#include "WiFiType.h"
#include "WiFiSTA.h"
#include "WiFiAP.h"
#include "WiFiScan.h"
#include "WiFiGeneric.h"
#include "WiFiClient.h"
#include "WiFiServer.h"
#include "WiFiUdp.h"

//==============================================================================//
///
/// @brief WiFi class
///

namespace Xila_Namespace
{

    class WiFi_Class : public WiFiGenericClass, public WiFiSTAClass, public WiFiScanClass, public WiFiAPClass, public Module_Class
    {
    public:
        void printDiag(Print &dest);

        void enableProv(bool status);
        bool isProvEnabled();

        WiFi_Class();

        using WiFiGenericClass::channel;

        using WiFiSTAClass::BSSID;
        using WiFiSTAClass::BSSIDstr;
        using WiFiSTAClass::RSSI;
        using WiFiSTAClass::SSID;

        using WiFiScanClass::BSSID;
        using WiFiScanClass::BSSIDstr;
        using WiFiScanClass::channel;
        using WiFiScanClass::encryptionType;
        using WiFiScanClass::RSSI;
        using WiFiScanClass::SSID;

        void Set_Credentials(const char *Name, const char *Password);

        static Result::Type Load_Registry();
        static Result::Type Save_Registry();

        friend class WiFiClient;
        friend class WiFiServer;
        friend class WiFiUDP;

        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;

    protected:
        bool prov_enable;

        ///
        /// @brief Access point password.
        ///
        char Password[82];
    } WiFi;

}

#endif