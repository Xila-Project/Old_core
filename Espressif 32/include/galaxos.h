#include "Arduino.h"
#include <string>

#ifndef GALAXOS_H_INCLUDED
#define GALAXOS_H_INCLUDED

class Galax_OS{
    private:

        uint8_t Taskbar_Items_PID[7];
        uint8_t Taskbar_Items_Icon[7];

        uint8_t Current_Page;
        uint8_t Last_Page;

        const char* WiFi_SSID     = "Avrupa";
        const char* WiFi_Password = "0235745484";

        uint8_t C_MIDI;

        uint16_t C_Frequency;

        uint8_t Speaker_Pin = 25;

        String Username = "NULL";
        String Password = "NULL";

        uint16_t Low_RAM_Threshold = 2000;

    public:

        GalaxOS();

        void WiFi_Connect();

        void USB_Serial_Transmit(const char* USB_Serial_Transmit_String, byte Alignment);

        void Open_Desk();
        void Open_Menu();

        void Musical_Digital_Player( void *pvParameters );
        void Nextion_Serial_Receive( void *pvParameters );
        void Nextion_Serial_Transmit(String Component, byte Type, String Nextion_Serial_Transmit_String = "", int Nextion_Serial_Transmit_Integer = 0);

        void Load_System_Files();
        void Load_User_Files();
        void Logon();
        
        void Ressource_Monitor( void *pvParameters );

        void Event_Handler_Request(byte Type, String Informations);
        void Event_Handler_Reply(byte Reply);
};

#endif