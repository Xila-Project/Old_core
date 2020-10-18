#include "signal_generator.hpp"

Signal_Generator_Class* Signal_Generator_Class::Instance_Pointer = NULL;

Signal_Generator_Class::Signal_Generator_Class() : Software_Class(6)
{
    xTaskCreatePinnedToCore(Signal_Generator_Task, "Signal Generator", 1024*4, NULL, 2, &Task_Handle, 1);
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
                vTaskDelay(pdMS_TO_TICKS(20));
                break;
            case Code::Close:
                delete INSTANCE_POINTER;
                vTaskDelete(NULL);
                break;
            case Code::Minimize:
                vTaskSuspend(NULL);
                break;
            default :
                break;
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

#undef INSTANCE_POINTER