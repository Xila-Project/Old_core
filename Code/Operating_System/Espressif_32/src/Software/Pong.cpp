#include "Software/Pong.hpp"

Pong_Class *Pong_Class::Instance_Pointer = NULL;

Pong_Class::Pong_Class() : Software_Class(Pong_Handle),
                            Player_1_Score(0),
                            Player_2_Score(0)
{
    Xila.Task_Create(Main_Task, "Pong", Memory_Chunk(4), NULL, &Task_Handle);
}

Pong_Class::~Pong_Class()
{
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
}

Software_Class* Pong_Class::Load()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Pong_Class();
    return Instance_Pointer;
}

void Pong_Class::Main_Task(void* pvParameters)
{
    while (1)
    {
        switch (Instance_Pointer->Get_Instruction())
        {
            case Xila.Idle:
                Xila.Delay(20);
                break;
            case Xila.Watchdog:
                Xila.Feed_Watchdog();
                break;
            case Instruction('C', 'l'):
                Xila.Software_Close(Pong_Handle);
                break;
            case Instruction('M', 'i'):
                Xila.Software_Minimize(Pong_Handle);
                break;
            case Xila.Close:
                delete Instance_Pointer;
                Xila.Task_Delete();
                break;
            case Xila.Maximize:
                Xila.Display.Set_Current_Page(F("Pong"));
                Instance_Pointer->Refresh_Interface();
                break;
            case Xila.Open:
                Xila.Display.Set_Current_Page(F("Pong"));
                break;
            case Xila.Minimize:
                break;
            case Instruction('S', '1'):
                Instance_Pointer->Player_1_Score++;
                Instance_Pointer->Refresh_Interface();
                break;
            case Instruction('S', '2'):
                Instance_Pointer->Player_2_Score++;
                Instance_Pointer->Refresh_Interface();
                break;
            case Instruction('R', 'e'):
                Instance_Pointer->Player_1_Score = 0;
                Instance_Pointer->Player_2_Score = 0;
                Instance_Pointer->Refresh_Interface();
                break;
        }
    }
}

void Pong_Class::Refresh_Interface()
{
    Xila.Display.Set_Value(F("SCORE1_NUM"), Player_1_Score);
    Xila.Display.Set_Value(F("SCORE2_NUM"), Player_2_Score);
}