#include "Software/Signal_Generator.hpp"

Signal_Generator_Class* Signal_Generator_Class::Instance_Pointer = NULL;

Signal_Generator_Class::Signal_Generator_Class() : Software_Class(6)
{
    Xila.Task_Create(Signal_Generator_Task, "Signal Generator", Memory_Chunk(8), NULL, &Task_Handle);
}

Signal_Generator_Class::~Signal_Generator_Class()
{

}

Software_Class* Signal_Generator_Class::Load()
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Signal_Generator_Class();
    }
    return Instance_Pointer;
}

void Signal_Generator_Task(void *pvParameters)
{
    while(1)
    {
        switch(INSTANCE_POINTER->Get_Command())
        {
            case 0:
                //idle
                Xila.Delay(20);
                break;
            case Xila.Close:
                delete INSTANCE_POINTER;
                vTaskDelete(NULL);
                break;
            case Xila.Minimize:
                vTaskSuspend(NULL);
                break;
            default :
                break;
        }
        Xila.Delay(10);
    }
}

#undef INSTANCE_POINTER