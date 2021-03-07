/**
 * @file Display.cpp
 * @brief Xila's display driver source file.
 * @author Alix ANNERAUD
 * @copyright MIT License
 * @version 0.1.0
 * @date 21/05/2020
 * @details Xila display driver, used by the core and softwares to display things.
 * @section License
 * 
 * Copyright (c) 2020 Alix ANNERAUD
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
*/

#include "Driver/Display.hpp"

Nextion_Display_Class *Nextion_Display_Class::Instance_Pointer = NULL;

Nextion_Display_Class::Nextion_Display_Class() : Nextion_Serial(1),
                                                 Callback_Function_String_Data(Default_Callback_Function_String_Data),
                                                 Callback_Function_Numeric_Data(Default_Callback_Function_Numeric_Data),
                                                 Callback_Function_Event(Default_Callback_Function_Event)

{
    if (Instance_Pointer != NULL)
    {
        delete this;
    }
    
    Instance_Pointer = this;
    Serial_Semaphore = xSemaphoreCreateBinary();

    if (Serial_Semaphore == NULL)
    {
        Verbose_Print_Line("Failed to create serial semaphore");
        delete this;
    }
    xSemaphoreGive(Serial_Semaphore);
}

Nextion_Display_Class::~Nextion_Display_Class()
{
    Instance_Pointer = NULL;
    vSemaphoreDelete(Serial_Semaphore);
    vTaskDelete(Nextion_Serial_Handle);
}

void Nextion_Display_Class::Begin(uint32_t Baud_Rate, uint8_t RX_Pin, uint8_t TX_Pin)
{
    Nextion_Serial.begin(Baud_Rate, SERIAL_8N1, RX_Pin, TX_Pin); //Nextion UART
    Instruction_End();                                           // clear last entered command
    xTaskCreatePinnedToCore(Main_Task, "Nextion Serial", Memory_Chunk(4), NULL, DRIVER_TASK_PRIORITY, &Nextion_Serial_Handle, tskNO_AFFINITY);
}

void Nextion_Display_Class::Set_Callback_Function_String_Data(void (*Function_Pointer)(const char *, uint8_t))
{
    Callback_Function_String_Data = Function_Pointer;
}

void Nextion_Display_Class::Set_Callback_Function_Numeric_Data(void (*Function_Pointer)(uint32_t))
{
    Callback_Function_Numeric_Data = Function_Pointer;
}

void Nextion_Display_Class::Set_Callback_Function_Event(void (*Function_Pointer)(uint8_t))
{
    Callback_Function_Event = Function_Pointer;
}

void Nextion_Display_Class::Default_Callback_Function_String_Data(const char * String, uint8_t Size)
{
}

void Nextion_Display_Class::Default_Callback_Function_Numeric_Data(uint32_t Numeric_Data)
{
}

void Nextion_Display_Class::Default_Callback_Function_Event(uint8_t Event)
{
}

void Nextion_Display_Class::Main_Task(void *pvParameters) //Parsing incomming data
{
    if (Instance_Pointer == NULL)
    {
        vTaskDelete(NULL);
    }
    uint8_t Return_Code = 0;
    char Temporary_String[150];
    memset(Temporary_String, '\0', sizeof(Temporary_String));
    uint8_t Temporary_Byte = 0;
    (void)pvParameters;
    while (1)
    {
        if (Instance_Pointer->Nextion_Serial.available())
        {
            Return_Code = Instance_Pointer->Nextion_Serial.read();

            memset(Temporary_String, '\0', sizeof(Temporary_String));

            switch (Return_Code)
            {
            case Numeric_Data_Enclosed:

                Instance_Pointer->Nextion_Serial.readBytes((char *)Temporary_String, 7);

                if (Temporary_String[4] == 0xFF && Temporary_String[5] == 0xFF && Temporary_String[6] == 0xFF)
                {
                    uint32_t Temporary_Long = ((uint32_t)Temporary_String[3] << 24) | ((uint32_t)Temporary_String[2] << 16) | ((uint32_t)Temporary_String[1] << 8) | (Temporary_String[0]);

                    (Instance_Pointer->Callback_Function_Numeric_Data(Temporary_Long));
                }

                break;
            case String_Data_Enclosed:
                Temporary_Byte = Instance_Pointer->Nextion_Serial.readBytesUntil(0xFF, Temporary_String, sizeof(Temporary_String));
                Instance_Pointer->Nextion_Serial.read();
                Instance_Pointer->Nextion_Serial.read();

                (Instance_Pointer->Callback_Function_String_Data(Temporary_String, sizeof(Temporary_String)));

                break;
            case Current_Page_Number:
                Instance_Pointer->Nextion_Serial.readBytes((char *)Temporary_String, 4);

                if (Temporary_String[1] == 0xFF && Temporary_String[2] == 0xFF && Temporary_String[3] == 0xFF)
                {
                    if (Temporary_String[0] != Instance_Pointer->Page_History[0])
                    {
                        Instance_Pointer->Page_History[5] = Instance_Pointer->Page_History[4];
                        Instance_Pointer->Page_History[3] = Instance_Pointer->Page_History[2];
                        Instance_Pointer->Page_History[2] = Instance_Pointer->Page_History[1];
                        Instance_Pointer->Page_History[1] = Instance_Pointer->Page_History[0];
                        Instance_Pointer->Page_History[0] = Temporary_String[0];
                    }

                    Instance_Pointer->Callback_Function_Event(Current_Page_Number);
                }
                else
                {
                    Instance_Pointer->Purge();
                }

                break;
            
            case Touch_Event:
                // -- Unhandled yet
                break;

            // -- 4  bytes instruction 
            case Auto_Entered_Sleep_Mode:
            case Auto_Wake_From_Sleep_Mode:
            case Ready:
            case Start_Upgrade_From_SD:
            case Transparent_Data_Finished:
            case Transparent_Data_Ready:
            case Instruction_Successfull:
            case Invalid_Component_ID:
            case Invalid_Page_ID:
            case Invalid_Picture_ID:
            case Invalid_Font_ID:
            case Invalid_CRC:
            case Invalid_Baud_Rate_Setting:
            case Invalid_Waveform_ID_Or_Channel:
            case Invalid_Variable_Name_Or_Attribue:
            case Invalid_Variable_Operation:
            case Fail_To_Assign:
            case Invalid_Quantity_Of_Parameters:
            case IO_Operation_Failed:
            case Invalid_Escape_Character:
            case Too_Long_Variable_Name:
            case Serial_Buffer_Overflow:
                Instance_Pointer->Nextion_Serial.readBytes((char *)Temporary_String, 3);
                if (Temporary_String[0] == 0xFF && Temporary_String[1] == 0xFF && Temporary_String[2] == 0xFF)
                {
                    Instance_Pointer->Callback_Function_Event(Return_Code);
                }
                else
                {
                    Instance_Pointer->Purge();
                }            
                break;
        
            case Invalid_Instruction:
                switch (Instance_Pointer->Nextion_Serial.read()) //Distinguish Invalid instruction or startup
                {
                case 0x00: // Startup Instruction
                    Instance_Pointer->Nextion_Serial.readBytes((char *)Temporary_String, 4);
                    if (Temporary_String[0] == 0x00 && Temporary_String[1] == 0x00 && Temporary_String[2] == 0xFF && Temporary_String[3] == 0xFF)
                    {
                        if (Instance_Pointer->Callback_Function_Event != NULL)
                        {
                            Instance_Pointer->Callback_Function_Event(Startup);
                        }
                    }
                    else // unrecognize command : purge serial
                    {
                        Instance_Pointer->Purge();
                    }

                case 0xFF: //Invalid Instruction
                    Instance_Pointer->Nextion_Serial.readBytes((char *)Temporary_String, 2);
                    if (Temporary_String[0] == 0xFF && Temporary_String[1] == 0xFF)
                    {
                        if (Instance_Pointer->Callback_Function_Event != NULL)
                        {
                            Instance_Pointer->Callback_Function_Event(Invalid_Instruction);
                        }
                    }
                    else // Unrecognized instruction : purge serial
                    {
                        Instance_Pointer->Purge();
                    }
                }
            
            default:
                Verbose_Print_Line("Unrecognized nextion message");
                Instance_Pointer->Purge();
                Instance_Pointer->Callback_Function_Event(Return_Code);
                break;
            }
        }
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}

void Nextion_Display_Class::Purge()
{
    Nextion_Serial.readStringUntil(0xFF);
    while (Nextion_Serial.peek() == 0xFF)
    {
        Nextion_Serial.read();
    }
}

void Nextion_Display_Class::Write(int Data)
{
    Nextion_Serial.write(Data);
}

void Nextion_Display_Class::Send_Raw(const __FlashStringHelper *Data)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Data);
    Instruction_End();
}

void Nextion_Display_Class::Send_Raw(String const &Data)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Data);
    Instruction_End();
}

void Nextion_Display_Class::Send_Raw(const char *Data)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Data);
    Instruction_End();
}

void Nextion_Display_Class::Refresh(const __FlashStringHelper *Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("ref "));
    Nextion_Serial.print(Object_Name);
    Instruction_End();
}

void Nextion_Display_Class::Refresh_Current_Page()
{
    Get(F("dp"));
}

uint8_t &Nextion_Display_Class::Get_Current_Page()
{
    return Page_History[0];
}

void Nextion_Display_Class::Set_Current_Page(uint8_t const &Page_ID)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("page "));
    Nextion_Serial.print(Page_ID);
    Instruction_End();
}

void Nextion_Display_Class::Set_Current_Page(const __FlashStringHelper *Page_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("page "));
    Nextion_Serial.print(Page_Name);
    Instruction_End();
}

void Nextion_Display_Class::Draw_Advanced_Crop_Picture(uint16_t const &X_Destination, uint16_t const &Y_Destination, uint16_t const &Width, uint16_t const &Height, uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Picture_ID)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("xpic "));
    Nextion_Serial.print(X_Destination);
    Argument_Separator();
    Nextion_Serial.print(Y_Destination);
    Argument_Separator();
    Nextion_Serial.print(Width);
    Argument_Separator();
    Nextion_Serial.print(Height);
    Argument_Separator();
    Nextion_Serial.print(X_Coordinate);
    Argument_Separator();
    Nextion_Serial.print(Y_Coordinate);
    Argument_Separator();
    Nextion_Serial.print(Picture_ID);
    Instruction_End();
}

void Nextion_Display_Class::Draw_Fill(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint16_t const &Color)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("fill"));
    Nextion_Serial.print(X_Coordinate);
    Argument_Separator();
    Nextion_Serial.print(Y_Coordinate);
    Argument_Separator();
    Nextion_Serial.print(Width);
    Argument_Separator();
    Nextion_Serial.print(Height);
    Argument_Separator();
    Nextion_Serial.print(Color);
    Instruction_End();
}

void Nextion_Display_Class::Set_Background_Color(const __FlashStringHelper *Object_Name, uint16_t const &Color, int8_t Type)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".bco"));
    if (Type != -1)
    {
        Nextion_Serial.print(Type);
    }
    Nextion_Serial.print(F("="));
    Nextion_Serial.print(Color);
    Instruction_End();
}

void Nextion_Display_Class::Set_Time(const __FlashStringHelper *Object_Name, uint16_t const &Time)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    if (Time < 50)
    {
        return;
    }
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".tim="));
    Nextion_Serial.print(Time);
    Instruction_End();
}

void Nextion_Display_Class::Set_Reparse_Mode(uint8_t Mode)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    if (Mode == 0)
    {
        Nextion_Serial.print(F("DRAKJHSUYDGBNCJHGJKSHBDN"));
    }
    else
    {
        Nextion_Serial.print(F("recmod=0"));
    }
    Instruction_End();
}

void Nextion_Display_Class::Set_Trigger(const __FlashStringHelper *Object_Name, bool const &Enable)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".en="));
    Nextion_Serial.print(Enable);
    Instruction_End();
}

void Nextion_Display_Class::Set_Picture(const __FlashStringHelper *Object_Name, uint8_t const &Picture_ID)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".pic="));
    Nextion_Serial.print(Picture_ID);
    Instruction_End();
}

void Nextion_Display_Class::Set_Picture(String const &Object_Name, uint8_t const &Picture_ID)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".pic="));
    Nextion_Serial.print(Picture_ID);
    Instruction_End();
}

void Nextion_Display_Class::Set_Font_Color(const __FlashStringHelper *Object_Name, uint16_t const &Color, int8_t Type)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".pco"));
    if (Type != -1)
    {
        Nextion_Serial.print(Type);
    }
    Nextion_Serial.print(F("="));
    Nextion_Serial.print(Color);
    Instruction_End();
}

void Nextion_Display_Class::Set_Input_Type(const __FlashStringHelper *Object_Name, uint8_t const &Input_Type)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".pw="));
    Nextion_Serial.write(Input_Type);
    Instruction_End();
}

void Nextion_Display_Class::Set_Text(const __FlashStringHelper *Object_Name, char Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".txt=\""));
    Nextion_Serial.print(Value);
    Nextion_Serial.print(F("\""));
    Instruction_End();
}

void Nextion_Display_Class::Set_Text(const __FlashStringHelper *Object_Name, const __FlashStringHelper *Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".txt=\""));
    Nextion_Serial.print(Value);
    Nextion_Serial.print(F("\""));
    Instruction_End();
}

void Nextion_Display_Class::Set_Text(String const &Object_Name, String const &Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".txt=\""));
    Nextion_Serial.print(Value);
    Nextion_Serial.print(F("\""));
    Instruction_End();
}

void Nextion_Display_Class::Set_Text(const __FlashStringHelper *Object_Name, const char *Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".txt=\""));
    Nextion_Serial.print(Value);
    Nextion_Serial.print(F("\""));
    Instruction_End();
}

void Nextion_Display_Class::Add_Text(const __FlashStringHelper *Component_Name, const char *Data)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Component_Name);
    Nextion_Serial.print(F(".txt+=\""));
    Nextion_Serial.print(Data);
    Nextion_Serial.print(F("\""));
    Instruction_End();
}

void Nextion_Display_Class::Delete_Text(const __FlashStringHelper *Component_Name, uint8_t const &Quantity_To_Delete)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Component_Name);
    Nextion_Serial.print(F(".txt-="));
    Nextion_Serial.print(Quantity_To_Delete);
    Instruction_End();
}

void Nextion_Display_Class::Set_Value(const __FlashStringHelper *Object_Name, uint32_t const &Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".val="));
    Nextion_Serial.print(Value);
    Instruction_End();
}

void Nextion_Display_Class::Set_Value(String const &Object_Name, uint32_t const &Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".val="));
    Nextion_Serial.print(String(Value));
    Instruction_End();
}

void Nextion_Display_Class::Set_Value(const char *Object_Name, uint32_t const &Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".val="));
    Nextion_Serial.print(Value);
    Instruction_End();
}

void Nextion_Display_Class::Set_Global_Value(const __FlashStringHelper *Object_Name, uint32_t const &Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print("=");
    Nextion_Serial.print(Value);
    Instruction_End();
}

void Nextion_Display_Class::Set_Font(const __FlashStringHelper *Object_Name, uint8_t const &Font_ID)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".font="));
    Nextion_Serial.print(Font_ID);
    Instruction_End();
}

void Nextion_Display_Class::Set_Data_Scalling(const __FlashStringHelper *Object_Name, uint16_t const &Scale)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    if (Scale < 10 || Scale > 1000)
    {
        return;
    }
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".dis="));
    Nextion_Serial.print(Scale);
    Instruction_End();
}

void Nextion_Display_Class::Draw_Crop_Picture(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint16_t const &Picture_ID)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("picq "));
    Nextion_Serial.print(X_Coordinate);
    Argument_Separator();
    Nextion_Serial.print(Y_Coordinate);
    Argument_Separator();
    Nextion_Serial.print(Width);
    Argument_Separator();
    Nextion_Serial.print(Height);
    Argument_Separator();
    Nextion_Serial.print(Picture_ID);
    Instruction_End();
}

void Nextion_Display_Class::Draw_Text(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint16_t const &Font_ID, uint16_t const &Text_Color, uint16_t Backgroud, uint16_t const &Horizontal_Alignment, uint16_t const &Vertical_Alignment, uint16_t const &Background_Type, String const &Text)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("xstr "));
    Nextion_Serial.print(X_Coordinate);
    Argument_Separator();
    Nextion_Serial.print(Y_Coordinate);
    Argument_Separator();
    Nextion_Serial.print(Width);
    Argument_Separator();
    Nextion_Serial.print(Height);
    Argument_Separator();
    Nextion_Serial.print(Font_ID);
    Argument_Separator();
    Nextion_Serial.print(Text_Color);
    Argument_Separator();
    Nextion_Serial.print(Backgroud);
    Argument_Separator();
    Nextion_Serial.print(Horizontal_Alignment);
    Argument_Separator();
    Nextion_Serial.print(Vertical_Alignment);
    Argument_Separator();
    Nextion_Serial.print(Background_Type);
    Argument_Separator();
    Nextion_Serial.print(F("\""));
    Nextion_Serial.print(Text);
    Nextion_Serial.print(F("\""));
    Instruction_End();
}

void Nextion_Display_Class::Draw_Text(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint16_t const &Font_ID, uint16_t const &Text_Color, uint16_t Backgroud, uint16_t const &Horizontal_Alignment, uint16_t const &Vertical_Alignment, uint16_t const &Background_Type, const char *Text)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("xstr "));
    Nextion_Serial.print(X_Coordinate);
    Argument_Separator();
    Nextion_Serial.print(Y_Coordinate);
    Argument_Separator();
    Nextion_Serial.print(Width);
    Argument_Separator();
    Nextion_Serial.print(Height);
    Argument_Separator();
    Nextion_Serial.print(Font_ID);
    Argument_Separator();
    Nextion_Serial.print(Text_Color);
    Argument_Separator();
    Nextion_Serial.print(Backgroud);
    Argument_Separator();
    Nextion_Serial.print(Horizontal_Alignment);
    Argument_Separator();
    Nextion_Serial.print(Vertical_Alignment);
    Argument_Separator();
    Nextion_Serial.print(Background_Type);
    Argument_Separator();
    Nextion_Serial.print(F("\""));
    Nextion_Serial.print(Text);
    Nextion_Serial.print(F("\""));
    Instruction_End();
}

void Nextion_Display_Class::Draw_Picture(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Picture_ID)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("pic "));
    Nextion_Serial.print(X_Coordinate);
    Argument_Separator();
    Nextion_Serial.print(Y_Coordinate);
    Argument_Separator();
    Nextion_Serial.print(Picture_ID);
    Instruction_End();
}

void Nextion_Display_Class::Draw_Circle(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Radius, uint16_t const &Color, bool const &Hollow)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    if (Hollow)
    {
        Nextion_Serial.print(F("cir "));
    }
    else
    {
        Nextion_Serial.print(F("cirs "));
    }
    Nextion_Serial.print(X_Coordinate);
    Argument_Separator();
    Nextion_Serial.print(Y_Coordinate);
    Argument_Separator();
    Nextion_Serial.print(Radius);
    Argument_Separator();
    Nextion_Serial.print(Color);
    Instruction_End();
}

void Nextion_Display_Class::Draw_Pixel(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Color)
{
    Draw_Rectangle(X_Coordinate, Y_Coordinate, 1, 1, Color);
}

void Nextion_Display_Class::Draw_Rectangle(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint16_t const &Color, bool const &Hollow)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    if (Hollow)
    {
        Nextion_Serial.print(F("draw "));
        Nextion_Serial.print(X_Coordinate);
        Argument_Separator();
        Nextion_Serial.print(Y_Coordinate);
        Argument_Separator();
        Nextion_Serial.print(X_Coordinate + Width);
        Argument_Separator();
        Nextion_Serial.print(Y_Coordinate + Height);
    }
    else
    {
        Nextion_Serial.print(F("fill "));
        Nextion_Serial.print(X_Coordinate);
        Argument_Separator();
        Nextion_Serial.print(Y_Coordinate);
        Argument_Separator();
        Nextion_Serial.print(Width);
        Argument_Separator();
        Nextion_Serial.print(Height);
    }

    Argument_Separator();
    Nextion_Serial.print(Color);
    Instruction_End();
}

void Nextion_Display_Class::Draw_Line(uint16_t const &X_Start, uint16_t const &Y_Start, uint16_t const &X_End, uint16_t const &Y_End, uint16_t const &Color)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("line "));
    Nextion_Serial.print(X_Start);
    Argument_Separator();
    Nextion_Serial.print(Y_Start);
    Argument_Separator();
    Nextion_Serial.print(X_End);
    Argument_Separator();
    Nextion_Serial.print(Y_End);
    Argument_Separator();
    Nextion_Serial.print(Color);
    Instruction_End();
}

void Nextion_Display_Class::Calibrate()
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("touch_j"));
    Instruction_End();
}

void Nextion_Display_Class::Show(const __FlashStringHelper *Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("vis "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print("1");
    Instruction_End();
}

void Nextion_Display_Class::Show(String const &Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("vis "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print("1");
    Instruction_End();
}
void Nextion_Display_Class::Show(const char *Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("vis "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print("1");
    Instruction_End();
}

void Nextion_Display_Class::Hide(const __FlashStringHelper *Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("vis "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print("0");
    Instruction_End();
}

void Nextion_Display_Class::Hide(String const &Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("vis "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print("0");
    Instruction_End();
}
void Nextion_Display_Class::Hide(const char *Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("vis "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print("0");
    Instruction_End();
}

void Nextion_Display_Class::Click(const __FlashStringHelper *Object_Name, uint8_t const &Event_Type)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("click "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print(Event_Type);
    Instruction_End();
}

void Nextion_Display_Class::Click(const char *Object_Name, uint8_t const &Event_Type)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("click "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print(Event_Type);
    Instruction_End();
}

void Nextion_Display_Class::Click(uint16_t const &Component_ID, uint8_t const &Event_Type)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("click "));
    Nextion_Serial.print(Component_ID);
    Argument_Separator();
    Nextion_Serial.print(Event_Type);
    Instruction_End();
}

void Nextion_Display_Class::Add_Value_Waveform(uint8_t const &Component_ID, uint8_t const &Channel, uint8_t *Data, uint32_t const &Quantity)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("add "));
    if (Quantity == 0)
    {
        Nextion_Serial.print(Component_ID);
        Argument_Separator();
        Nextion_Serial.print(Channel);
        Argument_Separator();
        Nextion_Serial.print(Data[0]);
        Instruction_End();
    }
    else
    {
        Nextion_Serial.print(F("t "));
        Nextion_Serial.print(Component_ID);
        Argument_Separator();
        Nextion_Serial.print(Channel);
        Argument_Separator();
        Nextion_Serial.print(Quantity);
        Nextion_Serial.print(F("\xFF\xFF\xFF"));
        vTaskDelay(pdMS_TO_TICKS(10)); //wait display to prepare transparent mode
        Nextion_Serial.write(Data, Quantity);
    }
}

void Nextion_Display_Class::Clear_Waveform(uint16_t const &Component_ID, uint8_t const &Channel)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("cle "));
    Serial.print(Component_ID);
    Argument_Separator();
    Serial.print(Channel);
    Instruction_End();
}

void Nextion_Display_Class::Reboot()
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("rest"));
    Instruction_End();
}

void Nextion_Display_Class::Set_Standby_Serial_Timer(uint16_t const &Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("ussp="));
    Nextion_Serial.print(Value);
    Instruction_End();
}

void Nextion_Display_Class::Set_Standby_Touch_Timer(uint16_t const &Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("thsp="));
    Nextion_Serial.print(Value);
    Instruction_End();
}

uint8_t Nextion_Display_Class::Update(File Update_File)
{
    Set_Brightness(100);
    Set_Standby_Serial_Timer(0);
    Set_Standby_Touch_Timer(0);
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    vTaskSuspend(Nextion_Serial_Handle); // Suspend serial task
    while (Nextion_Serial.available())   //clear serial buffer
    {
        Nextion_Serial.read();
    }
    Nextion_Serial.print(F("ÿÿÿ")); // ensure that last instruction is cleared
    Nextion_Serial.print(F("DRAKJHSUYDGBNCJHGJKSHBDNÿÿÿ"));
    Nextion_Serial.print(F("connectÿÿÿ"));

    byte i = 0;
    while (Nextion_Serial.available() == 0)
    {
        vTaskDelay(pdMS_TO_TICKS(100));
        i++;
        if (i > 50)
        {
            //error handle : no reply from screen
            return Update_Failed;
        }
    }
    char Temporary_String[5] = "";
    Serial.readBytes(Temporary_String, sizeof(String));
    if (strcmp(Temporary_String, "comok") != 0)
    {
        return Update_Failed;
    }
    while (Nextion_Serial.available())
    {
        Nextion_Serial.read();
    }

    size_t Size = Update_File.size();

    Nextion_Serial.print(F("whmi-wri "));
    Nextion_Serial.print(Size);
    Argument_Separator();
    Nextion_Serial.print(F("921600"));
    Argument_Separator();
    Nextion_Serial.print(F("res0"));
    Instruction_End();

    char Temporary_Buffer[4097];
    memset(Temporary_Buffer, 0, sizeof(Temporary_Buffer));

    while (Update_File.available() >= 4096)
    {
        Update_File.readBytes(Temporary_Buffer, 4096);
        while (Nextion_Serial.available() == 0)
        {
            vTaskDelay(pdMS_TO_TICKS(5));
        }
        if (Nextion_Serial.read() != 0x05)
        {
            //error - unexpected return number
            return Update_Failed;
        }
        Nextion_Serial.print(Temporary_Buffer);
    }
    memset(Temporary_Buffer, 0, sizeof(Temporary_Buffer));
    Update_File.readBytes(Temporary_Buffer, Update_File.available());
    while (Nextion_Serial.available() == 0)
    {
        vTaskDelay(pdMS_TO_TICKS(5));
    }
    if (Nextion_Serial.read() != 0x05)
    {
        //error - unexpected return number
        return Update_Failed;
    }
    Nextion_Serial.print(Temporary_Buffer);
    while (Nextion_Serial.available() == 0)
    {
        vTaskDelay(pdMS_TO_TICKS(5));
    }
    if (Nextion_Serial.read() != 0x05)
    {
        //error - unexpected return number
        return Update_Failed;
    }
    return Update_Succeed;
}

// Sleep & Wake up

void Nextion_Display_Class::Sleep()
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("sleep=1"));
    Instruction_End();
}

void Nextion_Display_Class::Wake_Up()
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("sleep=0"));
    Instruction_End();
}

void Nextion_Display_Class::Get(const __FlashStringHelper *Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("get "));
    Nextion_Serial.print(Object_Name);
    Instruction_End();
}

void Nextion_Display_Class::Clear(uint16_t const &Color)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("cls"));
    Instruction_End();
}

void Nextion_Display_Class::Set_Draw_Color(uint16_t const &Color)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("thc="));
    Nextion_Serial.print(Color);
    Instruction_End();
}

void Nextion_Display_Class::Set_Baud_Rate(uint32_t const &Baudrate, bool const &Save)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    if (Baudrate > 921000)
    {
        return;
    }
    Nextion_Serial.print(F("baud"));
    if (Save)
    {
        Nextion_Serial.print(F("s"));
    }
    Nextion_Serial.print(F("="));
    Nextion_Serial.print(Baudrate);
    Instruction_End();
}

void Nextion_Display_Class::Set_Brightness(uint16_t const &Brightness, bool const &Save)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    if (Brightness > 100)
    {
        return;
    }
    Nextion_Serial.print(F("dim"));
    if (Save)
    {
        Nextion_Serial.print(F("s"));
    }
    Nextion_Serial.print(F("="));
    Nextion_Serial.print(Brightness);
    Instruction_End();
}

void Nextion_Display_Class::Instruction_End()
{
    Nextion_Serial.print(F("\xFF\xFF\xFF"));
    xSemaphoreGive(Serial_Semaphore);
}

void Nextion_Display_Class::Argument_Separator()
{
    Nextion_Serial.print(F(","));
}