#include "Music_Player.hpp"

#define INSTANCE_POINTER Music_Player_Class::Instance_Pointer

Music_Player_Class *Music_Player_Class::Instance_Pointer = NULL;



void Music_Player_Task(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        while (INSTANCE_POINTER->Read_Position == INSTANCE_POINTER->Write_Position)
        {
            vTaskDelay(pdMS_TO_TICKS(20));
        }
        switch (INSTANCE_POINTER->Task_Method_Array[INSTANCE_POINTER->Read_Position])
        {
        case 0:

            //idle state
            break;
        case 0xPP:
            break;
        }
        INSTANCE_POINTER->Task_Method_Array[INSTANCE_POINTER->Read_Position] = NULL;
        INSTANCE_POINTER->Read_Position++;
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void Music_Player_Class::Pause()
{
    
}