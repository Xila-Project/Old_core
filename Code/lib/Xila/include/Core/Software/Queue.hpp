///
 /// @file Queue.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 30-07-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

 #ifndef Queue_Hpp_Included
 #define Queue_Hpp_Included

#include "../Module.hpp"

class Queue_Class : Module_Class
{
public:

    Queue_Class();
    ~Queue_Class();

    Result_Type Create(Size_Type Length, Size_Type Item_Size);
    void Delete();
    void Reset();
    
    Result_Type Send(const void* Item, Tick_Type Ticks_To_Wait, bool Send_To_Front = true);
    void Overwrite(const void* Buffer);
    Result_Type Peek(void* Buffer, Tick_Type Ticks_To_Wait);
    Result_Type Receive(void* Buffer, Tick_Type Ticks_To_Wait);

    uint16_t Waiting();

    Size_Type Spaces_Available();

private:

    QueueHandle_t Queue_Handle;
};

 #endif