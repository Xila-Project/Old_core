#include "Music_Player.hpp"

#define INSTANCE_POINTER Music_Player_Class::Instance_Pointer

Music_Player_Class *Music_Player_Class::Instance_Pointer = NULL;



void Music_Player_Task(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (INSTANCE_POINTER->Get_Command())
        {
        case 0:

            //idle state
            vTaskDelay(pdMS_TO_TICKS(20));
            break;
        case 0xFF:
            break;
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void Music_Player_Class::Pause()
{
    
}