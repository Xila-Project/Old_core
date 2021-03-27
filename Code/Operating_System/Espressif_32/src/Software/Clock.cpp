#include "Software/Clock.hpp"

Clock_Class *Clock_Class::Instance_Pointer = NULL;
uint32_t Clock_Class::Next_Alarm = 0;

Clock_Class::Clock_Class() : Software_Class(Clock_Handle),
                             Current_Tab(Clock)
{
    Xila.Task_Create(Background_Task, "Clock Task", Memory_Chunk(4), NULL, &Task_Handle);
}

Clock_Class::~Clock_Class()
{
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
}

Software_Class *Clock_Class::Load()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Clock_Class();
    return Instance_Pointer;
}

void Clock_Class::Startup_Function()
{
    Xila.Task_Create(Background_Task, "Clock Task", Memory_Chunk(2));
}

void Clock_Class::Background_Task(void *pvParameters)
{
    while (1)
    {
        if (Next_Alarm == 0)
        {
            vTaskDelay(pdMS_TO_TICKS(10000));
        }
        else
        {
            if (Next_Alarm < millis())
            {
                Xila.Software_Open(Clock_Handle);
                Instance_Pointer->Send_Instruction(Instruction('R', 'i'));
            }
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }
}

void Clock_Class::Refresh_Timer()
{
    if ((millis() - Last_Update) < 950)
    {

        Temporary_Time = Inital_Time - millis();
        Temporary_Time /= 1000; //get rid of milliseconds
        Xila.Display.Set_Value(F("SECONDS_NUM"), Temporary_Time % 60);
        Temporary_Time /= 60;
        Xila.Display.Set_Value(F("MINUTES_NUM"), Temporary_Time % 60);
        Xila.Display.Set_Value(F("HOURS_NUM"), Temporary_Time / 60);
        if (State == 1) // Running
        {
            if (millis() >= Inital_Time)
            {
                File Ringtone_File = Xila.Drive->open(Clock_File("Ringtone.wav"));
                Xila.Sound.Play(Ringtone_File); // play something
            }
        }
        Last_Update = millis();
    }
}

void Clock_Class::Refresh_Chronometer()
{
    if ((millis() - Last_Update) < 950)
    {
        if (State == 0)
        {
            Xila.Display.Set_Value(F("MILLIS_NUM"), 0);

            Xila.Display.Set_Value(F("SECOND_NUM"), 0);
            Xila.Display.Set_Value(F("MINUTE_NUM"), 0);
        }
        else if (State == 1)
        {
            Temporary_Time = millis() - Inital_Time;
            Xila.Display.Set_Value(F("MILLIS_NUM"), Temporary_Time % 1000);
            Temporary_Time /= 1000;
            Xila.Display.Set_Value(F("SECOND_NUM"), Temporary_Time % 60);
            Xila.Display.Set_Value(F("MINUTE_NUM"), Temporary_Time / 60);
        }
        else if (State == 2)
        {
            Temporary_Time = Paused_Time - Inital_Time;
            Xila.Display.Set_Value(F("MILLIS_NUM"), Temporary_Time % 1000);
            Temporary_Time /= 1000;
            Xila.Display.Set_Value(F("SECOND_NUM"), Temporary_Time % 60);
            Xila.Display.Set_Value(F("MINUTE_NUM"), Temporary_Time / 60);
        }
        Last_Update = millis();
    }
}

void Clock_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    if (Type == Xila.Variable_Long_Local)
    {
        if (Adress == 'H')
        {
            if (Current_Tab == Timer)
            {
                Hours = *(uint8_t *)Variable;
            }
            else // alarm
            {
                Alarm_Hour[Selected_Alarm] = *(uint8_t *)Variable;
            }
        }
        else if (Adress == 'M')
        {
            if (Current_Tab == Timer)
            {
                Minutes = *(uint8_t *)Variable;
            }
            else // alarm
            {
                Alarm_Minute[Selected_Alarm] = *(uint8_t *)Variable;
            }
        }
        else if (Adress == 'S')
        {
            Seconds = *(uint8_t *)Variable;
        }
    }
}

void Clock_Class::Refresh_Alarms()
{
    char Object_Name[11];
    char Object_Text[25] = "  -   :   -";
    for (uint8_t i = 0; i < 6; i++)
    {
        Object_Name[5] = i + 48;
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

            Object_Text[4] = (Alarm_Hour[i] / 10) + 48;
            Object_Text[5] = (Alarm_Hour[i] % 10) + 48;

            Object_Text[7] = (Alarm_Hour[i] / 10) + 48;
            Object_Text[8] = (Alarm_Hour[i] % 10) + 48;

            strcpy(Object_Text + 12, Alarm_Title[i]);

            strcpy(Object_Name, "ALARM _TXT");
            Object_Name[5] = i + 48;
            Xila.Display.Set_Text(Object_Name, Object_Text);

            strcpy(Object_Name, "ALARM _RAD");
            Object_Name[5] = i + 48;
            Xila.Display.Show(Object_Name);
            if (Selected_Alarm == i)
            {
                Xila.Display.Set_Value(Object_Name, 1);
            }
            else
            {
                Xila.Display.Set_Value(Object_Name, 0);
            }
        }
        else
        {
            strcpy(Object_Name, "ALARM _TXT");
            Object_Name[5] = i + 48;
            Xila.Display.Set_Text(Object_Name, "");

            strcpy(Object_Name, "ALARM _RAD");
            Object_Name[5] = i + 48;
            Xila.Display.Hide(Object_Name);
        }
    }
}

void Clock_Class::Refresh_Alarm()
{
    if (Alarm_Enabled[Selected_Alarm] == true)
    {
        Xila.Display.Set_Text(F("TITLE_TXT"), Alarm_Title[Selected_Alarm]);
        Xila.Display.Set_Value(F("HOURS_NUM"), Alarm_Hour[Selected_Alarm]);
        Xila.Display.Set_Value(F("MINUTES_NUM"), Alarm_Minute[Selected_Alarm]);
        if (Alarm_Enabled[Selected_Alarm] == true)
        {
            Xila.Display.Set_Text(F("ENABLE_BUT"), F("Disable"));
        }
        else
        {
            Xila.Display.Set_Text(F("ENABLE_BUT"), F("Enable"));
        }
    }
    else
    {
        for (uint8_t i = 0; i < 7; i++)
        {
            if (i < 6)
            {
                if (Instance_Pointer->Alarm_Exist[i] == true)
                {
                    Instance_Pointer->Selected_Alarm = i;
                    break;
                }
            }
            else
            {
                Instance_Pointer->Add_Alarm();
                break;
            }
        }
        Refresh_Alarm();
        Refresh_Alarms();
    }
}

void Clock_Class::Add_Alarm()
{
    for (uint8_t i = 0; i < 6; i++)
    {
        if (Alarm_Exist[i] == false)
        {
            Alarm_Exist[i] = true;
            Alarm_Hour[i] = 0;
            Alarm_Minute[i] = 0;
            Alarm_Enabled[i] = false;
            strcpy(Alarm_Title[i], "Untitled");
            Selected_Alarm = i;
            return;
        }
    }
}

void Clock_Class::Refresh_Clock()
{
    Time = Xila.Get_Time();
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
    Xila.Display.Set_Text(F("TIME_TXT"), String(Temporary_Char_Array));
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
    Xila.Display.Set_Text(F("DATE_TXT"), String(Temporary_Char_Array));
    Xila.Delay(500);
}

void Clock_Class::Main_Task(void *pvParameters)
{
    while (1)
    {
        switch (Instance_Pointer->Current_Tab)
        {
        case Clock:
            switch (Instance_Pointer->Get_Instruction())
            {
            case Xila.Idle: // IDLE
                Instance_Pointer->Refresh_Clock();
                break;
            case Instruction('O', 'A'):
                Xila.Display.Set_Current_Page(F("Clock_Alarm"));
                Instance_Pointer->Current_Tab = Alarm;
                Instance_Pointer->Refresh_Alarm();
                break;
            case Instruction('O', 'T'):
                Xila.Display.Set_Current_Page(F("Clock_Timer"));
                Instance_Pointer->Current_Tab = Timer;
                Instance_Pointer->Refresh_Timer();
                break;
            case Instruction('O', 'c'): // Switch page Chronometer
                Xila.Display.Set_Current_Page(F("Clock_Chrono"));
                Instance_Pointer->Current_Tab = Chronometer;
                Instance_Pointer->Refresh_Chronometer();
                break;
            case Instruction('R', 'i'): // Ring
                break;
            case Instruction('C', 'l'):
                Xila.Software_Close(Clock_Handle);
                break;
            case Instruction('M', 'i'):
                Xila.Software_Minimize(Clock_Handle);
                break;
            case Xila.Open:
                Xila.Display.Set_Current_Page(F("Clock"));
                Instance_Pointer->Current_Tab = Clock;
                Instance_Pointer->Refresh_Clock();
                break;
            case Xila.Close:
                delete Instance_Pointer;
                vTaskDelete(NULL);
                break;
            case Xila.Minimize:
                break;
            case Xila.Maximize:
                Xila.Display.Set_Current_Page(F("Clock"));
                break;
            default:
                break;
            }
            break;
        case Alarm:
            switch (Instance_Pointer->Get_Instruction())
            {
            case 0x0000: // IDLE
                Instance_Pointer->Refresh_Alarms();
                break;
            case 0x4F63: // Oc
                Xila.Display.Set_Current_Page(F("Clock_Chrono"));
                Instance_Pointer->Current_Tab = Alarm;
                Instance_Pointer->Refresh_Alarm();
                break;
            case 0x4F54: //OT
                Xila.Display.Set_Current_Page(F("Clock_Timer"));
                Instance_Pointer->Current_Tab = Timer;
                Instance_Pointer->Refresh_Timer();
                break;
            case 0x4F43: // OC: Switch page clock
                Xila.Display.Set_Current_Page(F("Clock"));
                Instance_Pointer->Current_Tab = Chronometer;
                Instance_Pointer->Refresh_Chronometer();
                break;

            case Instruction('A', '0'): //Ax : Select alarm
                if (Instance_Pointer->Alarm_Exist[0] == true)
                {
                    Instance_Pointer->Selected_Alarm = 0;
                    Instance_Pointer->Refresh_Alarms();
                    Instance_Pointer->Refresh_Alarm();
                }
                break;
            case Instruction('A', '1'):
                if (Instance_Pointer->Alarm_Exist[1] == true)
                {
                    Instance_Pointer->Selected_Alarm = 1;
                    Instance_Pointer->Refresh_Alarms();
                    Instance_Pointer->Refresh_Alarm();
                }

                break;
            case Instruction('A', '2'):
                if (Instance_Pointer->Alarm_Exist[2] == true)
                {
                    Instance_Pointer->Selected_Alarm = 2;
                    Instance_Pointer->Refresh_Alarms();
                    Instance_Pointer->Refresh_Alarm();
                }
                break;
            case Instruction('A', '3'):
                if (Instance_Pointer->Alarm_Exist[3] == true)
                {
                    Instance_Pointer->Selected_Alarm = 3;
                    Instance_Pointer->Refresh_Alarms();
                    Instance_Pointer->Refresh_Alarm();
                }
                break;
            case Instruction('A', '4'):
                if (Instance_Pointer->Alarm_Exist[4] == true)
                {
                    Instance_Pointer->Selected_Alarm = 4;
                    Instance_Pointer->Refresh_Alarms();
                    Instance_Pointer->Refresh_Alarm();
                }
                break;
            case Instruction('A', '5'):
                if (Instance_Pointer->Alarm_Exist[5] == true)
                {
                    Instance_Pointer->Selected_Alarm = 5;
                    Instance_Pointer->Refresh_Alarms();
                    Instance_Pointer->Refresh_Alarm();
                }
                break;
            case Instruction('A', 'A'): //AA
                Instance_Pointer->Add_Alarm();
                Instance_Pointer->Refresh_Alarm();
                Instance_Pointer->Refresh_Alarms();
                break;
            case 0x4441: //DA
                Instance_Pointer->Alarm_Exist[Instance_Pointer->Selected_Alarm] = false;
                for (uint8_t i = 0; i < 7; i++)
                {
                    if (i < 6)
                    {
                        if (Instance_Pointer->Alarm_Exist[i] == true)
                        {
                            Instance_Pointer->Selected_Alarm = i;
                            break;
                        }
                    }
                    else
                    {
                        Instance_Pointer->Add_Alarm();
                        break;
                    }
                }
                Instance_Pointer->Refresh_Alarms();
                break;
            case 0x4544: //ED
                if (Instance_Pointer->Alarm_Enabled[Instance_Pointer->Selected_Alarm] == true)
                {
                    Instance_Pointer->Alarm_Enabled[Instance_Pointer->Selected_Alarm] = false;
                }
                else
                {
                    Instance_Pointer->Alarm_Enabled[Instance_Pointer->Selected_Alarm] = true;
                }

                Instance_Pointer->Refresh_Alarm();
                Instance_Pointer->Refresh_Alarms();
                break;
            case Instruction('R', 'i'): // Ring
                break;
            case Xila.Open:
                Xila.Display.Set_Current_Page(F("Clock"));
                Instance_Pointer->Current_Tab = Clock;
                Instance_Pointer->Refresh_Clock();
                break;
            case Xila.Close:
                delete Instance_Pointer;
                vTaskDelete(NULL);
                break;
            case Xila.Minimize:
                vTaskSuspend(NULL);
                break;
            case Xila.Maximize:
                Xila.Display.Set_Current_Page(F("Clock"));
                break;
            default:
                break;
            }
            break;

        case Chronometer:
            switch (Instance_Pointer->Get_Instruction())
            {
            case 0x0000: //IDLE
                Instance_Pointer->Refresh_Chronometer();
                break;
            case 0x5350: // SP : Start / Pause
                Xila.Sound.Stop();
                if (Instance_Pointer->State == 0) // Stoped -> Running
                {
                    Instance_Pointer->State = 1;

                    Xila.Display.Set_Text(F("START_BUT"), F("Pause"));

                    Xila.Display.Set_Trigger(F("TIMER_TIM"), true);

                    Instance_Pointer->Inital_Time = millis();
                }
                else if (Instance_Pointer->State == 2) // Paused -> Running
                {
                    Instance_Pointer->Inital_Time += millis() - Instance_Pointer->Paused_Time;
                    Instance_Pointer->State = 1;

                    Xila.Display.Set_Text(F("START_BUT"), F("Pause"));
                    Xila.Display.Set_Trigger(F("TIMER_TIM"), true);
                }
                else // Running -> Pause
                {
                    Instance_Pointer->Paused_Time = millis();
                    Instance_Pointer->State = 2;
                    Xila.Display.Set_Text(F("START_BUT"), F("Start"));
                    Xila.Display.Set_Trigger(F("TIMER_TIM"), false);
                }
                break;

            case 0x4C52: //LR : Lap / Reset
                Xila.Sound.Stop();
                Instance_Pointer->Inital_Time = 0;
                Xila.Display.Set_Text(F("START_BUT"), F("Start"));

                Xila.Display.Set_Trigger(F("TIMER_TIM"), false);

                Xila.Display.Set_Value(F("MINUTE_NUM"), 0);
                Xila.Display.Set_Value(F("SECOND_NUM"), 0);
                Xila.Display.Set_Value(F("MILLIS_NUM"), 0);
                Instance_Pointer->State = 0;

                break;
            case 0x4255: // : UP laps

                break;
            case 0x4244: //  : Down laps
                break;
            case 0x4F41: // OA
                Xila.Display.Set_Current_Page(F("Clock_Alarm"));
                Instance_Pointer->Current_Tab = Alarm;
                Instance_Pointer->Refresh_Alarm();
                break;
            case 0x4F54: // OT
                Xila.Display.Set_Current_Page(F("Clock_Timer"));
                Instance_Pointer->Current_Tab = Timer;
                Instance_Pointer->Refresh_Timer();
                break;
            case 0x4F43: // "OC" : Switch page Clock
                Xila.Display.Set_Current_Page(F("Clock"));
                Instance_Pointer->Current_Tab = Clock;
                Instance_Pointer->Refresh_Clock();
                break;
            case 0x5249: // Ring
                break;
            case Xila.Open:
                Xila.Display.Set_Current_Page(F("Clock"));
                Instance_Pointer->Current_Tab = Clock;
                Instance_Pointer->Refresh_Clock();
                break;
            case Xila.Close:
                delete Instance_Pointer;
                vTaskDelete(NULL);
                break;
            case Xila.Minimize:
                vTaskSuspend(NULL);
                break;
            case Xila.Maximize:
                if (Instance_Pointer->Current_Tab == Clock)
                {
                    Xila.Display.Set_Current_Page(F("Clock"));
                }
                else if (Instance_Pointer->Current_Tab == Alarm)
                {
                    Xila.Display.Set_Current_Page(F("Clock_Alarm"));
                }
                else if (Instance_Pointer->Current_Tab == Timer)
                {
                    Xila.Display.Set_Current_Page(F("Clock_Timer"));
                }
                else if (Instance_Pointer->Current_Tab == Chronometer)
                {
                    Xila.Display.Set_Current_Page(F("Clock_Chronometer"));
                }
                break;
            default:
                break;
            }
            break;
        case Timer:
            switch (Instance_Pointer->Get_Instruction())
            {
            case 0x0000: // IDLE
                Instance_Pointer->Refresh_Timer();
                break;

            case 0x5350:                          // SP : Start / Pause
                if (Instance_Pointer->State == 0) //Stopped -> Start
                {
                    Instance_Pointer->State = 1;
                    Instance_Pointer->Inital_Time = Instance_Pointer->Hours * 3600;
                    Instance_Pointer->Inital_Time += Instance_Pointer->Minutes * 3600;
                    Instance_Pointer->Inital_Time += Instance_Pointer->Seconds;
                    Instance_Pointer->Inital_Time *= 1000;
                    Xila.Display.Set_Text(F("START_BUT"), F("Pause"));
                    Xila.Display.Hide(F("REMHOUR_BUT"));
                    Xila.Display.Hide(F("ADDHOUR_BUT"));
                    Xila.Display.Hide(F("REMMIN_BUT"));
                    Xila.Display.Hide(F("ADDMIN_BUT"));
                    Xila.Display.Hide(F("REMSEC_BUT"));
                    Xila.Display.Hide(F("ADDSEC_BUT"));
                }
                else if (Instance_Pointer->State == 1) // Running -> Pause
                {
                    Instance_Pointer->Paused_Time = millis();
                    Instance_Pointer->State = 2;
                    Xila.Display.Set_Text(F("START_BUT"), F("Start"));
                }
                else // Pause -> Start
                {
                    Instance_Pointer->State = 1;
                    Instance_Pointer->Inital_Time += millis() - Instance_Pointer->Paused_Time;
                    Xila.Display.Set_Text(F("START_BUT"), F("Pause"));
                }

                break;

            case 0x434C: // CL : clear
                Instance_Pointer->State = 0;
                Instance_Pointer->Hours = 0;
                Instance_Pointer->Minutes = 0;
                Instance_Pointer->Seconds = 0;
                Xila.Display.Show(F("REMHOUR_BUT"));
                Xila.Display.Show(F("ADDHOUR_BUT"));
                Xila.Display.Show(F("REMMIN_BUT"));
                Xila.Display.Show(F("ADDMIN_BUT"));
                Xila.Display.Show(F("REMSEC_BUT"));
                Xila.Display.Show(F("ADDSEC_BUT"));
                Xila.Display.Set_Text(F("START_BUT"), F("Start"));
                break;
            case 0x4F41: // OA
                Xila.Display.Set_Current_Page(F("Clock_Alarm"));
                Instance_Pointer->Current_Tab = Alarm;
                Instance_Pointer->Refresh_Alarm();
                break;
            case 0x4F43: // "OC" : Switch page Clock
                Xila.Display.Set_Current_Page(F("Clock"));
                Instance_Pointer->Current_Tab = Clock;
                Instance_Pointer->Refresh_Clock();
                break;
            case 0x4F63: // "Oc" : Switch page Clock
                Xila.Display.Set_Current_Page(F("Clock_Chrono"));
                Instance_Pointer->Current_Tab = Chronometer;
                Instance_Pointer->Refresh_Chronometer();
                break;
            case 0x5249: // Ring
                break;
            case Xila.Open:
                Xila.Display.Set_Current_Page(F("Clock"));
                Instance_Pointer->Current_Tab = Clock;
                Instance_Pointer->Refresh_Clock();
                break;
            case Xila.Close:
                delete Instance_Pointer;
                vTaskDelete(NULL);
                break;
            case Xila.Minimize:
                vTaskSuspend(NULL);
                break;
            case Xila.Maximize:
                if (Instance_Pointer->Current_Tab == Clock)
                {
                    Xila.Display.Set_Current_Page(F("Clock"));
                }
                else if (Instance_Pointer->Current_Tab == Alarm)
                {
                    Xila.Display.Set_Current_Page(F("Clock_Alarm"));
                }
                else if (Instance_Pointer->Current_Tab == Timer)
                {
                    Xila.Display.Set_Current_Page(F("Clock_Timer"));
                }
                else if (Instance_Pointer->Current_Tab == Chronometer)
                {
                    Xila.Display.Set_Current_Page(F("Clock_Chronometer"));
                }
                break;
            default:
                break;
            }
            break;
        }
        Xila.Delay(20);
    }
}
