/**
 * @file Display.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Core/Core.hpp"

Xila_Class::Event Xila_Class::Display_Class::Load_Registry()
{
    Verbose_Print_Line("> Load display registry ...");
    File Temporary_File = Xila.Drive.Open(Display_Registry_Path);
    DynamicJsonDocument Display_Registry(256);
    if (deserializeJson(Display_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.close();
        return Error;
    }
    Brightness = Display_Registry["Brightness"];
    Temporary_File.close();
    return Success;
}

Xila_Class::Event Xila_Class::Display_Class::Save_Registry()
{
    File Temporary_File = Xila.Drive.Open(Display_Registry_Path, FILE_WRITE);
    DynamicJsonDocument Display_Registry(256);
    Display_Registry["Brightness"] = Brightness;
    Display_Registry["Receive Pin"] = Receive_Pin;
    Display_Registry["Send Pin"] = Send_Pin;
    Display_Registry["Standby Time"] = Standby_Time;
    if (serializeJson(Display_Registry, Temporary_File) == 0)
    {
        Temporary_File.close();
        return Error;
    }
    Temporary_File.close();
    return Success;
}

// Callback function for display

///
 /// @brief Incomming display string data
 /// 
 /// @param Received_Data 
 /// @param Size 
void Xila_Class::Display_Class::Incomming_String_Data_From_Display(const char *Received_Data, uint8_t Size)
{
    while (Xila.Software.Openned[0] == NULL)
    {
        Xila.Task.Delay(20);
    }
    switch (Received_Data[0])
    {
    case Xila.Display.Instruction:
        Xila.Software.Openned[0]->Send_Instruction(Instruction(Received_Data[1], Received_Data[2]));
        break;
    case Xila.Display.Variable_String:
        Xila.Software.Openned[0]->Set_Variable(Received_Data + 2, Variable_String, Received_Data[1]);
        Xila.Display.Tag = '\0';
        break;
    case Xila.Display.Variable_Long:
        Xila.Display.Tag = Received_Data[1];
        break;
    default:
        //error handle
        break;
    }
}

void Xila_Class::Display_Class::Incomming_Numeric_Data_From_Display(uint32_t Received_Data)
{
    if (Xila.Display.Tag != '\0')
    {
        Xila.Software.Openned[0]->Set_Variable(&Received_Data, Xila.Display.Variable_Long, Xila.Display.Tag);
        Xila.Display.Tag = '\0';
    }
    else
    {
        Xila.Dialog.Event(F("Unexpected Numeric Data Return From Display"), Error);
    }
}

void Xila_Class::Display_Class::Incomming_Event_From_Display(uint8_t Event_Code)
{
    switch (Event_Code)
    {
    case Nextion_Display_Class::Current_Page_Number:
        Xila.System.Refresh_Header();
        break;
    case Nextion_Display_Class::Serial_Buffer_Overflow:
        Verbose_Print_Line("Display buffer overflow");
        break;
    default:
        break;
    }
    //Openned[0]->Send_Instruction((uint16_t)Event_Code);
}