#include "periodic.hpp"
#include "object.hpp"

uint8_t Periodic_Class::Number_Instance = 0;

Periodic_Class::Periodic_Class()
{
    if (Number_Instance > 0)
    {
        delete this;
        //error handle
    }

    ++Number_Instance;

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
    (void)pvParamters;
    for (;;)
    {
        switch (Periodic_Pointer->Socket_Method)
        {
        case 0: //Idle state
            Serial.println(F("Periodic Socket : Nothing to do ..."));
            break;
        case 18253: //GM

            break;
        case 18252: //GL

            break;
        case 18244: //GD

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
    long X, Y;
    float Column, Line;

    GalaxOS_Pointer->Get_Variable('X', X);
    GalaxOS_Pointer->Get_Variable('Y', Y);
    Column = (float)X;
    Column += 8;
    Column /= 26;
    Column = round(Column);
    Line = (float)Y;
    Line -= 16;
    Line /= 26;
    Line = round(Line);
    Current_Atom = ((uint16_t)Column * 10) + (uint16_t)Line;
}

void Periodic_Class::Get_Data()
{
}

void Periodic_Class::Get_List()
{
}