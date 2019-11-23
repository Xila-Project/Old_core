#ifndef GALAXOS_H_INCLUDED
#define GALAXOS_H_INCLUDED

#include <Arduino.h>

void Files_And_Folders();
void Load_System_Files();
void Nextion_Serial_Transmit(String Component, byte Type, String Nextion_Serial_Transmit_String, int Nextion_Serial_Transmit_Integer);
void Load_User_Files();
void Load_System_Files();
void Open_Menu();
void Open_Desk();
void Logon();

#endif