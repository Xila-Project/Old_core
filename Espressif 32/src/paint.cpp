#include "Paint.hpp"

#define INSTANCE_POINTER Paint_Class::Instance_Pointer

Paint_Class* Paint_Class::Instance_Pointer = NULL;

Software_Class *Paint_Class::Load(Software_Handle_Class *Software_Handle_To_Set)
{
    if (Instance_Pointer != NULL)
    {
        return Instance_Pointer;
    }
    return new Paint_Class(Software_Handle_To_Set);
}


Paint_Class::Paint_Class(Software_Handle_Class *Software_Handle_To_Set) : Software_Class(Software_Handle_To_Set, 6)
{
    xTaskCreatePinnedToCore(Paint_Task, "Paint Task", 8192, NULL, 2, &Task_Handle, 1);

}

Paint_Class::~Paint_Class() : ~Software_Class()
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
            case 0x004D: // NULL + M : Maximize
                GalaxOS.Display.Set_Current_Page(Paint_Class::Page_Paint);
                break;
            case 0x006D: // NULL + m : Minimize
                vTaskSuspend(NULL);
                break;
            case 0x0043: // NULL + C : Close
                vTaskDelete(NULL);
                break;
            
        }
    }
}