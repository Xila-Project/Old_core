/// @file Queue.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 06-04-2023
///
/// @copyright Copyright (c) 2023

#include "Module/Queue.hpp"

using namespace Xila_Namespace;

Queue_Class::Queue_Class() : Handle(NULL)
{
}

Result_Type Queue_Class::Create(Size_Type Length, Size_Type Item_Size)
{
    Handle = xQueueCreate(Length, Item_Size);
    if (Handle == NULL)
    {
        return Result_Type::Error;
    }
    return Result_Type::Success;
}

void Queue_Class::Delete()
{
    vQueueDelete(Handle);
}

void Queue_Class::Send(const void *Item_To_Send, uint32_t Time)
{
    if (Time == 0xFFFFFFFF)
        xQueueSend(Handle, Item_To_Send, portMAX_DELAY);
    else
        xQueueSend(Handle, Item_To_Send, Time);
}

void Queue_Class::Send_To_Back(const void *Item_To_Send, uint32_t Time)
{
    if (Time == 0xFFFFFFFF)
        xQueueSendToBack(Handle, Item_To_Send, portMAX_DELAY);
    else
        xQueueSendToBack(Handle, Item_To_Send, Time);
}

void Queue_Class::Send_To_Front(const void *Item_To_Send, uint32_t Time)
{
    if (Time == 0xFFFFFFFF)
        xQueueSendToFront(Handle, Item_To_Send, portMAX_DELAY);
    else
        xQueueSendToFront(Handle, Item_To_Send, Time);
}

void Queue_Class::Overwrite(const void *Item_To_Send)
{
    xQueueOverwrite(Handle, Item_To_Send);
}

void Queue_Class::Receive(void *Buffer, uint32_t Time)
{
    if (Time == 0xFFFFFFFF)
        xQueueReceive(Handle, Buffer, portMAX_DELAY);
    else
        xQueueReceive(Handle, Buffer, Time);
}

void Queue_Class::Peek(void *Buffer, uint32_t Time)
{
    if (Time == 0xFFFFFFFF)
        xQueuePeek(Handle, Buffer, portMAX_DELAY);
    else
        xQueuePeek(Handle, Buffer, Time);
}

Size_Type Queue_Class::Get_Available()
{
    return uxQueueMessagesWaiting(Handle);
}

Size_Type Queue_Class::Get_Free_Space()
{
    return uxQueueSpacesAvailable(Handle);
}

void Queue_Class::Clear()
{
    xQueueReset(Handle);
}