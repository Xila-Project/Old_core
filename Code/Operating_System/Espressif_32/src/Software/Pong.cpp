#include "Software/Pong.hpp"

Pong_Class *Pong_Class::Instance_Pointer = NULL;

Pong_Class::Pong_Class() : Software_Class(Pong_Handle),
                           Player_1_Score(0),
                           Player_2_Score(0)
{
    Xila.Task.Create(Main_Task, "Pong", Memory_Chunk(4), NULL, &Task_Handle);
}

Pong_Class::~Pong_Class()
{
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
}

Software_Class *Pong_Class::Load()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Pong_Class();
    return Instance_Pointer;
}

void Pong_Class::Main_Task(void *pvParameters)
{
    while (1)
    {
        switch (Instance_Pointer->Get_Instruction())
        {
        case Idle:
            if (Xila.Software.Get_State(Pong_Handle) == Minimized)
            {
                Xila.Task.Delay(90);
            }
            else
            {
                while (Xila.Keyboard.Available())
                {
                    switch (Xila.Keyboard.Read())
                    {
                    case 'a':
                    case 'A':
                        Xila.Display.Send_Raw(F("PADDLE1_SLI.val+=15"));
                        break;
                    case 'q':
                    case 'Q':
                        Xila.Display.Send_Raw(F("PADDLE1_SLI.val-=15"));
                        break;
                    case 'p':
                    case 'P':
                        Xila.Display.Send_Raw(F("PADDLE2_SLI.val+=15"));
                        break;
                    case 'm':
                    case 'M':
                        Xila.Display.Send_Raw(F("PADDLE2_SLI.val-=15"));
                        break;
                    default:
                        break;
                    }
                }
            }
            Xila.Task.Delay(10);
            break;

        case Instruction('C', 'l'):
            Xila.Software.Close(Pong_Handle);
            break;
        case Instruction('M', 'i'):
            Xila.Software.Minimize(Pong_Handle);
            break;
        case Restart: case Shutdown:
        case Close:
            delete Instance_Pointer;
            Xila.Task.Delete();
            break;
        case Maximize:
            Xila.Display.Set_Current_Page(F("Pong"));
            Xila.Keyboard.Clear();
            Instance_Pointer->Refresh_Interface();
            break;
        case Open:
            Xila.Display.Set_Current_Page(F("Pong"));
            break;
        case Minimize:
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