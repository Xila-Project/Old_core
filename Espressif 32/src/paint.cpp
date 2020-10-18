#include "Paint.hpp"

#define INSTANCE_POINTER Paint_Class::Instance_Pointer

Paint_Class* Paint_Class::Instance_Pointer = NULL;

Software_Class *Paint_Class::Load(Software_Handle_Class *Software_Handle_To_Set)
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Paint_Class;
    }
    return Instance_Pointer;
}


Paint_Class::Paint_Class() : Software_Class(6)
{
    xTaskCreatePinnedToCore(Paint_Task, "Paint Task", 8192, NULL, 2, &Task_Handle, 1);

}

Paint_Class::~Paint_Class()
{

}

void Paint_Task(void* pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (INSTANCE_POINTER->Get_Command())
        {
            case 0:
                break;
            case Code::Maximize: // NULL + M : Maximize
                GalaxOS.Display.Set_Current_Page(Paint_Class::Page_Paint);
                break;
            case Code::Minimize: // NULL + m : Minimize
                vTaskSuspend(NULL);
                break;
            case Code::Close: // NULL + C : Close
                vTaskDelete(NULL);
                break;
            
        }
    }
}

#undef INSTANCE_POINTER