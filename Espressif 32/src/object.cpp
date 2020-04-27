#include "object.h"

HardwareSerial Nextion_Serial(2);
WiFiClient WiFi_Client;
GalaxOS_Class GalaxOS;

File Temporary_File;
String Temporary_File_Path = "\0";
String Temporary_File_Name = "\0";


