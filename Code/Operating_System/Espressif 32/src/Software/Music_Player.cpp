#include "Music_Player.hpp"

Music_Player_Class* Music_Player_Class::Instance_Pointer = NULL;

Software_Class* Music_Player_Class::Load()
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Music_Player_Class();
    }
    return Instance_Pointer;
}

Music_Player_Class::Music_Player_Class() : Software_Class(6)
{

}

Music_Player_Class::~Music_Player_Class()
{
    
}

void Music_Player_Class::Main_Task(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (Instance_Pointer->Get_Command())
        {
        case Xila.Idle:

            //idle state
            Xila.Delay(20);
            break;
        case 0xFF:
            break;
        }
        Xila.Delay(10);
        
    }
}

void Music_Player_Class::Pause()
{

}