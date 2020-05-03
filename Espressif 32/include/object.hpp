#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <SD.h>
#include <SPI.h>
#include "WiFi.h"
#include "galaxos.hpp"

extern HardwareSerial Nextion_Serial;
extern WiFiClient WiFi_Client;
extern GalaxOS_Class GalaxOS;

extern String Temporary_File_Path;
extern String Temporary_File_Name;

#endif