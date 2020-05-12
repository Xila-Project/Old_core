#ifndef PERIODIC_H_INCLUDED
#define PERIODIC_H_INCLUDED

#include "Arduino.h"

class Periodic_Class {
    private:

        static uint8_t Number_Instance;

        uint16_t Socket_Method;

        xTaskHandle Socket_Handle;

        void Periodic_Class::Get_Main_Data();
        void Periodic_Class::Get_Data();
        void Periodic_Class::Get_List();

    public:

        Periodic_Class(GalaxOS_Class const& GalaxOS_Pointer_To_Set);
        ~Periodic_Class();

        void Execute(uint16_t const& Socket_Method_To_Set);
        void Execute(char const& Socket_Method_Char1, char const& Socket_Method_Char2);

        friend void Periodic_Socket(void *pvParameters);

};

void Periodic_Socket(void *pvParameters);

#endif