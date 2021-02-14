#include "Software/Paint.hpp"

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
    Xila.Task_Create(Main_Task, "Paint Task", Memory_Chunk(4), NULL, &Task_Handle);
}

Paint_Class::~Paint_Class()
{



}

/*void Paint_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    if (Adress == 'C')
    {
        if (Buffer_Position < sizeof(Currrent_Buffer))
        {
            Buffer[Currrent_Buffer][Buffer_Position++] = *(uint32_t *)Variable;
        }
        else
        {
            if (Currrent_Buffer == 0)
            {
                Currrent_Buffer == 1;
            }
            else
            {
                Currrent_Buffer == 0;
            }
            Buffer_Position = 0;
            Execute(0x); //write
        }
    }
}*/

void Paint_Class::Main_Task(void* pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (INSTANCE_POINTER->Get_Command())
        {
            case 0:
                break;
            case Xila.Maximize: // NULL + M : Maximize
                Xila.Display.Set_Current_Page(F("Paint"));
                break;
            case Xila.Minimize: // NULL + m : Minimize
                vTaskSuspend(NULL);
                break;
            case Xila.Close: // NULL + C : Close
                vTaskDelete(NULL);
                break;
            
        }
    }
}

#undef INSTANCE_POINTER