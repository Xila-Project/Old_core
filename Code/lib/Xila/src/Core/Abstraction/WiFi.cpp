///
/// @file WiFi.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr) - Espressif
/// @brief Xila WiFi abstraction layer source file.
/// @version 0.1
/// @date 08-04-2021
///
/// @copyright Copyright (c) 2021
///

/*
 ESP8266WiFi.cpp - WiFi library for esp8266

 Copyright (c) 2014 Ivan Grokhotkov. All rights reserved.
 This file is part of the esp8266 core for Arduino environment.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

 Reworked on 28 Dec 2015 by Markus Sattler

 */

#include "Core/Core.hpp"

extern "C"
{
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <esp_err.h>
#include <esp_wifi.h>
#include <esp_event_loop.h>
}

// -----------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------- Debug ------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------------------

Xila_Class::WiFi_Class::WiFi_Class()
{
    prov_enable = false;
    memset(Password, '\0', sizeof(Password));
}

///
/// @brief
///
/// @return Xila_Class::Event
///
Xila_Class::Event Xila_Class::WiFi_Class::Load_Registry()
{
    File Temporary_File = Xila.Drive.Open((Registry("Network")));
    DynamicJsonDocument Network_Registry(512);
    if (deserializeJson(Network_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.close();
        return Error;
    }
    Temporary_File.close();
    if (strcmp(Network_Registry["Registry"] | "", "Network") != 0)
    {
        return Error;
    }
    JsonObject WiFi_Registry = Network_Registry["WiFi"];
    strlcpy(this->Password, WiFi_Registry["Password"] | "\0", sizeof(Password));
    char Temporary_Char[33];
    strlcpy(Temporary_Char, WiFi_Registry["Name"] | "\0", sizeof(Temporary_Char));
    Set_Credentials(Temporary_Char, Password);
    return Success;
}

///
/// @brief
///
/// @return Xila_Class::Event
///
Xila_Class::Event Xila_Class::WiFi_Class::Save_Registry()
{
    DynamicJsonDocument Network_Registry(512);
    Network_Registry["Registry"] = "Network";
    JsonObject WiFi_Registry = Network_Registry.createNestedObject("WiFi");
    WiFi_Registry["Name"] = SSID();
    WiFi_Registry["Password"] = Password;
    File Temporary_File = Xila.Drive.Open(Registry("Network"), FILE_WRITE);
    if (serializeJson(Network_Registry, Temporary_File) == 0)
    {
        Temporary_File.close();
        return Error;
    }
    Temporary_File.close();
    return Success;
}

/**
     * @brief Function that allow to connect WiFi.

     * @param Name SSID of the access point.
     * @param Password Password of the access point.
     *
     * @details Function that that try to connect to the given access point, and if succed, save credential into network registry.
     */
void Xila_Class::WiFi_Class::Set_Credentials(const char *Name, const char *Password)
{
    strlcpy(this->Password, Password, sizeof(this->Password));
    setAutoConnect(false);
    begin(Name, this->Password);
    setSleep(WIFI_PS_NONE);
}

/**
 * Output WiFi settings to an object derived from Print interface (like Serial).
 * @param p Print interface
 */
void Xila_Class::WiFi_Class::printDiag(Print &p)
{
    const char *modes[] = {"NULL", "STA", "AP", "STA+AP"};

    wifi_mode_t mode;
    esp_wifi_get_mode(&mode);

    uint8_t primaryChan;
    wifi_second_chan_t secondChan;
    esp_wifi_get_channel(&primaryChan, &secondChan);

    p.print("Mode: ");
    p.println(modes[mode]);

    p.print("Channel: ");
    p.println(primaryChan);
    /*
        p.print("AP id: ");
        p.println(wifi_station_get_current_ap_id());

        p.print("Status: ");
        p.println(wifi_station_get_connect_status());
    */

    wifi_config_t conf;
    esp_wifi_get_config(WIFI_IF_STA, &conf);

    const char *ssid = reinterpret_cast<const char *>(conf.sta.ssid);
    p.print("SSID (");
    p.print(strlen(ssid));
    p.print("): ");
    p.println(ssid);

    const char *passphrase = reinterpret_cast<const char *>(conf.sta.password);
    p.print("Passphrase (");
    p.print(strlen(passphrase));
    p.print("): ");
    p.println(passphrase);

    p.print("BSSID set: ");
    p.println(conf.sta.bssid_set);
}

void Xila_Class::WiFi_Class::enableProv(bool status)
{
    prov_enable = status;
}

bool Xila_Class::WiFi_Class::isProvEnabled()
{
    return prov_enable;
}
