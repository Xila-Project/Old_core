#include "Software/Pong.hpp"

Pong_Class *Pong_Class::Instance_Pointer = NULL;

Pong_Class::Pong_Class()
    : Xila_Class::Software(Pong_Handle)
{
    Scores[0] = 0;
    Scores[1] = 0;
    Xila.Task.Create(Main_Task, "Pong", Memory_Chunk(2), NULL, &Task_Handle);
}

Pong_Class::~Pong_Class()
{
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
}

Xila_Class::Software *Pong_Class::Load()
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
        case Xila.Idle:
            if (Xila.Software_Management.Get_State(Pong_Handle) == Xila.Minimized)
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

        case Xila.Hibernate:
        case Xila.Shutdown:
        case Xila.Restart:
        case Instruction('C', 'l'):
            Xila.Software_Management.Close(Pong_Handle);
            break;
        case Instruction('M', 'i'):
            Xila.Software_Management.Minimize(Pong_Handle);
            break;
        case Xila.Close:
            delete Instance_Pointer;
            Xila.Task.Delete();
            break;
        case Xila.Maximize:
            Xila.Display.Set_Current_Page(F("Pong"));
            Xila.Keyboard.Clear();
            Instance_Pointer->Send_Instruction('R', 'e');
            break;
        case Xila.Open:
            Xila.Display.Set_Current_Page(F("Pong"));
            Instance_Pointer->Send_Instruction('R', 'e');
            break;
        case Xila.Minimize:
            break;
        case Instruction('S', '1'):
            Instance_Pointer->Scores[0]++;
            Instance_Pointer->Send_Instruction('R', 'e');
            break;
        case Instruction('S', '2'):
            Instance_Pointer->Scores[1]++;
            Instance_Pointer->Send_Instruction('R', 'e');
            break;
        case Instruction('R', 'E'):
            Instance_Pointer->Scores[0] = 0;
            Instance_Pointer->Scores[1] = 0;
            Instance_Pointer->Send_Instruction('R', 'e');
            break;
        case Instruction('R', 'e'):
            Instance_Pointer->Refresh_Interface();
            break;
        }
    }
}

void Pong_Class::Refresh_Interface()
{
    sprintf(Temporary_String, "Player 1 : %i", Scores[0]);
    Xila.Display.Set_Text(F("PLAYER1_TXT"), Temporary_String);
    sprintf(Temporary_String, "Player 2 : %i", Scores[1]);
    Xila.Display.Set_Text(F("PLAYER2_TXT"), Temporary_String);
}