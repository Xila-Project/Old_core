#include "signal_generator.hpp"

Signal_Generator_Class* Signal_Generator_Class::Instance_Pointer = NULL;

Signal_Generator_Class::Signal_Generator_Class() : Software_Class(6)
{
    xTaskCreatePinnedToCore(Signal_Generator_Task, "Signal Generator", 1024*4, NULL, 2, &Instance_Pointer, 1);
}

Signal_Generator_Class::~Signal_Generator_Class()
{

}

void Signal_Generator_Task(void *pvParameters)
{
    while(1)
    {
        switch(INSTANCE_POINTER->Get_Command())
        {
            case 0:
                //idle
                vTaskDelay(pdMS_TO_TICKS(10));
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
    }
}