#include "periodic.hpp"

Periodic_Class* Periodic_Class::Instance_Pointer = NULL;
#define INSTANCE_POINTER Periodic_Class::Instance_Pointer

Periodic_Class::Periodic_Class() : Software_Class(6)
{
    xTaskCreatePinnedToCore(Periodic_Task, "Periodic", 4096, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
}

Periodic_Class::~Periodic_Class()
{
    Instance_Pointer = NULL;
}

Software_Class* Periodic_Class::Load()
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Periodic_Class;
    }
    return Instance_Pointer;
}

void Periodic_Class::Set_Variable(const void* Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    switch(Adress)
    {
        case 'X':
            X = *(uint32_t *)Variable;
            break;
        case 'Y':
            Y = *(uint32_t *)Variable;
            break;
        default:
            break;
    }   
}

void Periodic_Task(void *pvParamters)
{
    (void)pvParamters;
    for (;;)
    {
        switch (INSTANCE_POINTER->Get_Command())
        {
        case 0: //Idle state
            Serial.println(F("Periodic Socket : Nothing to do ..."));
            break;
        case 18253: //GM
            INSTANCE_POINTER->Get_Main_Data();
            break;
        case 18252: //GL
            INSTANCE_POINTER->Get_List();
            break;
        case 18244: //GD
            INSTANCE_POINTER->Get_Data();
            break;
        default:
            Serial.println(F("Unknow Socket Method ! "));
            //error handle
            break;
        }
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}

void Periodic_Class::Get_Main_Data()
{
    float Column, Line;

    Column = (float)X;
    Column += 8;
    Column /= 26;
    Column = round(Column);
    Line = (float)Y;
    Line -= 16;
    Line /= 26;
    Line = round(Line);
    Verbose_Print("> Column :");
    Serial.println(Column);
    Verbose_Print("> Line :");
    Serial.println(Line);
    if (Line == 1)
    {
        Current_Atom = 3;
        Column -= 16;
    }
    else if (Line < 4)
    {
        Current_Atom = 9;
        Column -= 10;
    }
    else if (Line < 6)
    {
        Current_Atom = 19;
    }
    else if (Line < 8)
    {
        Current_Atom = 33;
        Column -= 1;
    }
    else if (Line < 10)
    {
        Current_Atom = 16;
        Column -= 3;
    }
    Current_Atom -= Column;
}

void Periodic_Class::Get_Data()
{
}

void Periodic_Class::Get_List()
{
}