# 🛜 WiFi

Here you will find a complete description of the WiFi abstraction layer.

## Description

Xila provides a WiFi abstraction layer to simplify the use of WiFi. It is based on the ESP32 WiFi library for Arduino.
It's composed of 3 sub-modules: `Station`, `Access Point` and `Scan`.

Here are the types defined in the namespace `WiFi_Types` and used by `WiFi` module.

```{toctree}
:maxdepth:  1
WiFi/IP Address
```

## Example

```cpp
    using namespace Xila;

    WiFi.Station.Connect("SSID", "Password"); // - Connect to a WiFi network.
    WiFi.Station.Disconnect(); // - Disconnect from the current WiFi network.
    WiFi.Station.Get_IP_Address(); // - Get the IP address of the current WiFi network.
    WiFi.Station.Get_MAC_Address(); // - Get the MAC address of the current WiFi network.
    WiFi.Station.Get_SSID(); // - Get the SSID of the current WiFi network.
    WiFi.Station.Get_Status(); // - Get the status of the current WiFi network.
    
```

## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::WiFi_Class
    :members:
```
