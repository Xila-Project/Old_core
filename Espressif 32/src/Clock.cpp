#include "Clock.hpp"

Clock_Class *Clock_Class::Instance_Pointer = NULL;

Clock_Class::Clock_Class() : Software_Class(6),
                             Current_Tab(Clock)
{
    Execute(Open);
    xTaskCreatePinnedToCore(Main_Task, "Clock Task", 4 * 1024, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
}

Clock_Class::~Clock_Class()
{
    Instance_Pointer = NULL;
}

Software_Class *Clock_Class::Load()
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Clock_Class();
    }
    return Instance_Pointer;
}

void Clock_Class::Refresh_Alarm()
{
    char Object_Name[10];
    char Object_Text[20];
    for (uint8_t i = 0; i < 6; i++)
    {
        if (Alarm_Exist[i] == true)
        {
            if (Alarm_Enabled[i] == true)
            {
                Object_Text[0] = 'E';
            }
            else
            {
                Object_Text[0] = 'D';
            }
            Object_Text[1] = '|';
            strcpy(Object_Text + 2, Alarm_Title[i]);
            if (Alarm_Hour < 10)
            {
                Object_Text[sizeof(Alarm_Title) + 2] = ' ';
                Object_Text[sizeof(Alarm_Title) + 3] = ':';
                Object_Text[sizeof(Alarm_Title) + 4] = ' ';
            }
        }
        else
        {

            GalaxOS.Display.Set_Text(F("ALARM__TXT"), "");
        }
    }
}

void Clock_Class::Add_Alarm()
{
}

void Clock_Class::Refresh_Clock()
{
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
    vTaskDelay(pdMS_TO_TICKS(500));
}

void Clock_Class::Main_Task(void *pvParameters)
{
    while (1)
    {
        switch (Instance_Pointer->Current_Tab)
        {
        case Clock:
            switch (Instance_Pointer->Get_Command())
            {
            case 0x0000: // IDLE
                Instance_Pointer->Refresh_Clock();
                break;
            case 0x4F41:
                GalaxOS.Display.Set_Current_Page(F("Clock_Alarm"));
                Instance_Pointer->Current_Tab = Alarm;
                Instance_Pointer->Refresh_Alarm();
                break;
            case 0x4F54:
                GalaxOS.Display.Set_Current_Page(F("Clock_Timer"));
                Instance_Pointer->Current_Tab = Timer;
                Instance_Pointer->Refresh_Timer();
                break;
            case 0x4F63: // Switch page Chronometer
                GalaxOS.Display.Set_Current_Page(F("Clock_Chrono"));
                Instance_Pointer->Current_Tab = Chronometer;
                Instance_Pointer->Refresh_Chronometer();
                break;
            case Software_Code::Open:
                GalaxOS.Display.Set_Current_Page(F("Clock"));
                Instance_Pointer->Current_Tab = Clock;
                Instance_Pointer->Refresh_Clock();
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
            break;
        case Alarm:
            switch (Instance_Pointer->Get_Command())
            {
            case 0x0000: // IDLE
                Instance_Pointer->Refresh_Clock();
                break;
            case 0x4F63: // Oc
                GalaxOS.Display.Set_Current_Page(F("Clock_Chrono"));
                Instance_Pointer->Current_Tab = Alarm;
                Instance_Pointer->Refresh_Alarm();
                break;
            case 0x4F54: //OT
                GalaxOS.Display.Set_Current_Page(F("Clock_Timer"));
                Instance_Pointer->Current_Tab = Timer;
                Instance_Pointer->Refresh_Timer();
                break;
            case 0x4F43: // OC: Switch page clock
                GalaxOS.Display.Set_Current_Page(F("Clock"));
                Instance_Pointer->Current_Tab = Chronometer;
                Instance_Pointer->Refresh_Chronometer();
                break;

            case: //A0
                Instance_Pointer->Selected_Alarm = 0;
                Instance_Pointer->Refresh_Alarms();
                break;
            case: //A1
                Instance_Pointer->Selected_Alarm = 1;
                break;
            case: //A0
                Instance_Pointer->Selected_Alarm = 2;
                break;
            case: //A0
                Instance_Pointer->Selected_Alarm = 3;
                break;
            case: //A0
                Instance_Pointer->Selected_Alarm = 4;
                break;
            case: //A0
                Instance_Pointer->Selected_Alarm = 5;
                break;
            case : //AM
                Instance_Pointer->Alarm_Minute[Instance_Pointer->Selected_Alarm]++;
                break;    
            case : //RM
                Instance_Pointer->Alarm_Minute[Instance_Pointer->Selected_Alarm]--;
                break;
            case : //AH
                Instance_Pointer->Alarm_Hour[Instance_Pointer->Selected_Alarm]++;
                break;
            case 
            case 0x case Software_Code::Open:
                GalaxOS.Display.Set_Current_Page(F("Clock"));
                Instance_Pointer->Current_Tab = Clock;
                Instance_Pointer->Refresh_Clock();
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
            break;

        case Timer:
            break;

        case Chronometer:
            break;
        }
        vTaskDelay(pdMS_TO_TICKS(40));
    }
}
