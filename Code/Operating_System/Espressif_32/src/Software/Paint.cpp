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
    Color_Palette[0] = 0;
    Color_Palette[1] = 31;
    Color_Palette[2] = 63488;
    Color_Palette[3] = 63519;
    Color_Palette[4] = 2016;
    Color_Palette[5] = 2047;
    Color_Palette[6] = 65504;
    Color_Palette[7] = 65535;
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
                Instance_Pointer->Refresh_Interface();
                break;
            case Xila.Maximize:
                Xila.Display.Set_Current_Page(F("Paint"));
                Instance_Pointer->Refresh_Interface();
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
            case Instruction('S', '1'):
                Xila.Color_Picker_Dialog(Instance_Pointer->Color_Palette[0]);
                Instance_Pointer->Refresh_Interface();
                break;
            case Instruction('S', '2'):
                Xila.Color_Picker_Dialog(Instance_Pointer->Color_Palette[1]);
                Instance_Pointer->Refresh_Interface();
                break;
            case Instruction('S', '3'):
                Xila.Color_Picker_Dialog(Instance_Pointer->Color_Palette[2]);
                Instance_Pointer->Refresh_Interface();
                break;
            case Instruction('S', '4'):
                Xila.Color_Picker_Dialog(Instance_Pointer->Color_Palette[3]);
                Instance_Pointer->Refresh_Interface();
                break;
            case Instruction('S', '5'):
                Xila.Color_Picker_Dialog(Instance_Pointer->Color_Palette[4]);
                Instance_Pointer->Refresh_Interface();
                break;
            case Instruction('S', '6'):
                Xila.Color_Picker_Dialog(Instance_Pointer->Color_Palette[5]);
                Instance_Pointer->Refresh_Interface();
                break;
            case Instruction('S', '7'):
                Xila.Color_Picker_Dialog(Instance_Pointer->Color_Palette[6]);
                Instance_Pointer->Refresh_Interface();
                break;
            case Instruction('S', '8'):
                Xila.Color_Picker_Dialog(Instance_Pointer->Color_Palette[7]);
                Instance_Pointer->Refresh_Interface();
                break;
        }
    }
}

void Paint_Class::Refresh_Interface()
{
    Xila.Display.Set_Background_Color(F("COLOR1_CHE"), Color_Palette[0]);
    Xila.Display.Set_Background_Color(F("COLOR2_CHE"), Color_Palette[1]);
    Xila.Display.Set_Background_Color(F("COLOR3_CHE"), Color_Palette[2]);
    Xila.Display.Set_Background_Color(F("COLOR4_CHE"), Color_Palette[3]);
    Xila.Display.Set_Background_Color(F("COLOR5_CHE"), Color_Palette[4]);
    Xila.Display.Set_Background_Color(F("COLOR6_CHE"), Color_Palette[5]);
    Xila.Display.Set_Background_Color(F("COLOR7_CHE"), Color_Palette[6]);
    Xila.Display.Set_Background_Color(F("COLOR8_CHE"), Color_Palette[7]);
}