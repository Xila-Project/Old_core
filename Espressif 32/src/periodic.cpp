#include "periodic.hpp"
#include "Arduino.h"
#include "galaxos.hpp"

uint8_t Periodic_Class::Number_Instance = 0;

Periodic_Class::Periodic_Class(GalaxOS_Class const &GalaxOS_Pointer_To_Set)
{
    if (Number_Instance > 0)
    {
        delete this;
        //error handle
    }

    ++Number_Instance;

    GalaxOS_Pointer = GalaxOS_Pointer_To_Set;

    xTaskCreatePinnedToCore(Periodic_Socket, "Periodic", 4096, NULL, 2, &Socket_Handle, 1);
}

Periodic_Class::~Periodic_Class()
{
    --Number_Instance;
    vTaskDelete(Socket_Handle);
}

void Periodic_Socket(void *pvParamters)
{
    Periodic_Class *Periodic_Pointer = GalaxOS.Get_Software_Pointer();
    (void)pvParameters;
    for (;;)
    {
        switch (iGOS_Pointer->Socket_Method)
        {
        case 0:
            Serial.println(F("iGOS Socket : Nothing to do ..."));
            break;
        case: //GM

            break;
        case: //GL

            break;
        case: //GD

            break;
        default:
            Serial.println(F("Unknow Socket Method ! "));
            //error handle
            break;
        }
        Periodic_Pointer->Socket_Method = 0; //work done, reset the selector
        vTaskSuspend(NULL);
    }
}

void Periodic_Class::Execute(uint16_t const& Socket_Method_To_Set)
{
    Socket_Method = Socket_Method_To_Set;
    vTaskResume(Socket_Handle);
}

void Periodic_Class::Execute(char const &Socket_Method_Char1, char const &Socket_Method_Char2)
{
    Socket_Method = ((uint16_t)Socket_Method_Char1 << 8) | (uint16_t)Socket_Method_Char2;
    vTaskResume(Socket_Handle)
}

void Periodic_Class::Get_Main_Data()
{
    uint32_t Column, Line;

    GalaxOS_Pointer->Get_Variable('X', Column);
    GalaxOS_Pointer->Get_Variable('Y', Line);

    Column -= 6;
    Column /= 26;
    Column = round(Y);

    Line -= 29;
    Line /= 26;
    Line = round(Line);
}

void Periodic_Class::Get_Data()
{
}

void Periodic_Class::Get_List()
{
}