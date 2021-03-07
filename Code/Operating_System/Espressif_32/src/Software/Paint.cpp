#include "Software/Paint.hpp"

Paint_Class* Paint_Class::Instance_Pointer = NULL;

Software_Class *Paint_Class::Load()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Paint_Class();
    return Instance_Pointer;
}


Paint_Class::Paint_Class() : Software_Class(Paint_Handle)
{
    Xila.Task_Create(Main_Task, "Paint Task", Memory_Chunk(4), NULL, &Task_Handle);
}

Paint_Class::~Paint_Class()
{
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
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
            Send_Instruction(0x); //write
        }
    }
}*/

void Paint_Class::Main_Task(void* pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (Instance_Pointer->Get_Instruction())
        {
            case 0:
                Xila.Delay(30);
                break;
            case Xila.Watchdog:
                Xila.Feed_Watchdog();
                break;
            case Xila.Open:
                Xila.Display.Set_Current_Page(F("Paint"));
                break;
            case Xila.Maximize:
                Xila.Display.Set_Current_Page(F("Paint"));
                break;
            case Xila.Minimize:
                break;
            case Xila.Close:
                delete Instance_Pointer;
                vTaskDelete(NULL);
                break;
            case Instruction('C', 'l'):
                Xila.Software_Close(Paint_Handle);
                break;
            case Instruction('M', 'i'):
                Xila.Software_Minimize(Paint_Handle);
                break;
        }
    }
}

#undef INSTANCE_POINTER