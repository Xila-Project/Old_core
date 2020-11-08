#include "Paint.hpp"

#define INSTANCE_POINTER Paint_Class::Instance_Pointer

Paint_Class* Paint_Class::Instance_Pointer = NULL;

Software_Class *Paint_Class::Load()
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Paint_Class;
    }
    return Instance_Pointer;
}


Paint_Class::Paint_Class() : Software_Class(6)
{
    xTaskCreatePinnedToCore(Main_Task, "Paint Task", 8192, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);

}

Paint_Class::~Paint_Class()
{

}

void Paint_Class::Main_Task(void* pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (INSTANCE_POINTER->Get_Command())
        {
            case 0:
                break;
            case Software_Code::Maximize: // NULL + M : Maximize
                GalaxOS.Display.Set_Current_Page(F("Paint"));
                break;
            case Software_Code::Minimize: // NULL + m : Minimize
                vTaskSuspend(NULL);
                break;
            case Software_Code::Close: // NULL + C : Close
                vTaskDelete(NULL);
                break;
            
        }
    }
}

#undef INSTANCE_POINTER