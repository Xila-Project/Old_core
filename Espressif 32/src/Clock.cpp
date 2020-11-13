#include "Clock.hpp"

Clock_Class* Clock_Class::Instance_Pointer = NULL;

Clock_Class::Clock_Class() : Software_Class(6)
{
    Execute(Open);
    xTaskCreatePinnedToCore(Main_Task, "Clock Task", 4 * 1024, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
}

Clock_Class::~Clock_Class()
{
    Instance_Pointer = NULL;
}

Software_Class* Clock_Class::Load()
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Clock_Class();
    }
    return Instance_Pointer;
}

void Clock_Class::Main_Task(void *pvParameters)
{
    Xila_Time Time;
    char Temporary_Char_Array[40];
    uint8_t Offset;
    while (1)
    {
        switch (Instance_Pointer->Get_Command())
        {
        case 0x0000: // IDLE
            Time = GalaxOS.Get_Time();
            // Set time
            Temporary_Char_Array[0] = (Time.tm_hour / 10) + 48;
            Temporary_Char_Array[1] = (Time.tm_hour % 10) + 48;
            Temporary_Char_Array[2] = ':';
            Temporary_Char_Array[3] = (Time.tm_min / 10) + 48;
            Temporary_Char_Array[4] = (Time.tm_min % 10) + 48;
            Temporary_Char_Array[5] = ':';
            Temporary_Char_Array[6] = (Time.tm_sec / 10) + 48;
            Temporary_Char_Array[7] = (Time.tm_sec % 10) + 48;
            Temporary_Char_Array[8] = '\0';
            GalaxOS.Display.Set_Text(F("TIME_TXT"), String(Temporary_Char_Array));
            // Set data
            Offset = 0;
            strcpy(Temporary_Char_Array, Instance_Pointer->Days[Time.tm_wday]);
            Offset = sizeof(Instance_Pointer->Days[Time.tm_wday]);
            Temporary_Char_Array[Offset] = ' ';
            Offset++;
            if (Time.tm_mday < 10)
            {
                Temporary_Char_Array[Offset] = Time.tm_mday + 48;
            }
            else
            {
                Temporary_Char_Array[Offset] = (Time.tm_mday / 10) + 48;
                Offset++;
                Temporary_Char_Array[Offset] = (Time.tm_mday % 10) + 48;
            }
            Offset++;
            switch (Time.tm_mday)
            {
            case 1:
                strcpy(Temporary_Char_Array + Offset, "st");
                break;
            case 2:
                strcpy(Temporary_Char_Array + Offset, "nd");
                break;
            case 3:
                strcpy(Temporary_Char_Array + Offset, "rd");
                break;
            default:
                strcpy(Temporary_Char_Array + Offset, "th");
                break;
            }
            Offset += 2;
            Temporary_Char_Array[Offset] = ' ';
            Offset++;
            strcpy(Temporary_Char_Array + Offset, Instance_Pointer->Months[Time.tm_mon]);
            Offset += sizeof(Instance_Pointer->Months[Time.tm_mon]);
            Temporary_Char_Array[Offset] = (Time.tm_year / 1000) + 48;
            Temporary_Char_Array[Offset + 1] = (Time.tm_year / 100) + 48;
            Temporary_Char_Array[Offset + 2] = (Time.tm_year / 10) + 48;
            Temporary_Char_Array[Offset + 3] = (Time.tm_year % 10) + 48;
            Temporary_Char_Array[Offset + 4] = '\0';
            GalaxOS.Display.Set_Text(F("DATE_TXT"), String(Temporary_Char_Array));
            break;
        case Software_Code::Open:
            GalaxOS.Display.Set_Current_Page(F("Clock"));
            break;
        case Software_Code::Close:
            delete Instance_Pointer;
            vTaskDelete(NULL);
            break;
        case Software_Code::Minimize:
            vTaskSuspend(NULL);
            break;
        case Software_Code::Maximize:
            GalaxOS.Display.Set_Current_Page(F("Clock"));
            break;
        default:
            break;
        }
        vTaskDelay(pdMS_TO_TICKS(40));
    }
}
