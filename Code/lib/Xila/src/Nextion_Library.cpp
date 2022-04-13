///
/// @file Nextion_Library.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Nextion display library source file.
/// @version 0.1.0
/// @date 21-05-2020
///
/// @copyright Copyright (c) 2021
///

#include "Nextion_Library.hpp"

Nextion_Class *Nextion_Class::Instance_Pointer = NULL;

Nextion_Class::Nextion_Class() : Nextion_Serial(1),
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
        delete this;
    }
    xSemaphoreGive(Serial_Semaphore);
    memset(Temporary_String, '\0', sizeof(Temporary_String));
}

Nextion_Class::~Nextion_Class()
{
    if (Instance_Pointer == this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
    vSemaphoreDelete(Serial_Semaphore);
}

void Nextion_Class::Begin(uint32_t Baud_Rate, uint8_t RX_Pin, uint8_t TX_Pin)
{
    this->Baud_Rate = Baud_Rate;
    Nextion_Serial.begin(Baud_Rate, SERIAL_8N1, RX_Pin, TX_Pin); //Nextion UART
    Nextion_Serial.print("DRAKJHSUYDGBNCJHGJKSHBDN");            // exit transparent mode and clear last send command
    Instruction_End();
}

void Nextion_Class::Set_Callback_Function_String_Data(void (*Function_Pointer)(const char *, uint8_t))
{
    Callback_Function_String_Data = Function_Pointer;
}

void Nextion_Class::Set_Callback_Function_Numeric_Data(void (*Function_Pointer)(uint32_t))
{
    Callback_Function_Numeric_Data = Function_Pointer;
}

void Nextion_Class::Set_Callback_Function_Event(void (*Function_Pointer)(uint8_t))
{
    Callback_Function_Event = Function_Pointer;
}

void Nextion_Class::Default_Callback_Function_String_Data(const char *String, uint8_t Size)
{
}

void Nextion_Class::Default_Callback_Function_Numeric_Data(uint32_t Numeric_Data)
{
}

void Nextion_Class::Default_Callback_Function_Event(uint8_t Event)
{
}

///
/// @brief Main loop (data parsing etc.).
///
void Nextion_Class::Loop()
{
    if (Nextion_Serial.available())
    {

        Return_Code = Nextion_Serial.read();
        memset(Temporary_String, '\0', sizeof(Temporary_String));

        switch (Return_Code)
        {
        case Numeric_Data_Enclosed:

            Nextion_Serial.readBytes((char *)Temporary_String, 7);

            if (Ending(Temporary_String + 4))
            {
                uint32_t Temporary_Long = ((uint32_t)Temporary_String[3] << 24) | ((uint32_t)Temporary_String[2] << 16) | ((uint32_t)Temporary_String[1] << 8) | (Temporary_String[0]);

                (Callback_Function_Numeric_Data(Temporary_Long));
            }

            break;
        case String_Data_Enclosed:
            Nextion_Serial.readBytesUntil(0xFF, Temporary_String, sizeof(Temporary_String));
            Nextion_Serial.read();
            Nextion_Serial.read();

            (Callback_Function_String_Data(Temporary_String, sizeof(Temporary_String)));

            break;
        case Current_Page_Number:
            Nextion_Serial.readBytes((char *)Temporary_String, 4);
            if (Ending(Temporary_String + 1))
            {
                DUMP((uint8_t)Temporary_String[0]);
                if (Temporary_String[0] != Page_History[0])
                {
                    Page_History[4] = Page_History[3];
                    Page_History[3] = Page_History[2];
                    Page_History[2] = Page_History[1];
                    Page_History[1] = Page_History[0];
                    Page_History[0] = Temporary_String[0];
                }

                Callback_Function_Event(Current_Page_Number);
            }
            else
            {
                Purge();
            }
            break;

        case Touch_Coordinate_Awake:
        case Touch_Coordinate_Sleep:
            Nextion_Serial.readBytes((char *)Temporary_String, 5);
            if (Temporary_String[4] == 01)
            {
                X_Press = Temporary_String[0] << 8 | Temporary_String[1];
                Y_Press = Temporary_String[2] << 8 | Temporary_String[3];
                Callback_Function_Event(Return_Code);
            }
            else if (Temporary_String[4] == 00)
            {
                X_Release = Temporary_String[0] << 8 | Temporary_String[1];
                Y_Release = Temporary_String[2] << 8 | Temporary_String[3];
                Callback_Function_Event(Return_Code);
            }
            Purge();
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
        case Invalid_Variable_Name_Or_Attribute:
        case Invalid_Variable_Operation:
        case Fail_To_Assign:
        case Invalid_Quantity_Of_Parameters:
        case IO_Operation_Failed:
        case Invalid_Escape_Character:
        case Too_Long_Variable_Name:
        case Serial_Buffer_Overflow:
            Nextion_Serial.readBytes((char *)Temporary_String, 3);
            if (Ending(Temporary_String))
            {
                Callback_Function_Event(Return_Code);
            }
            else
            {
                Purge();
            }
            break;

        case Invalid_Instruction:
            switch (Nextion_Serial.read()) //Distinguish Invalid instruction or startup
            {
            case 0x00: // Startup Instruction
                Nextion_Serial.readBytes((char *)Temporary_String, 4);
                if (Temporary_String[0] == 0x00 && Temporary_String[1] == 0x00 && Temporary_String[2] == 0xFF && Ending(Temporary_String + 3))
                {
                    if (Callback_Function_Event != NULL)
                    {
                        Callback_Function_Event(Startup);
                    }
                }
                else // unrecognized command : purge serial
                {
                    Purge();
                }

            case 0xFF: //Invalid Instruction
                Nextion_Serial.readBytes((char *)Temporary_String, 2);
                if (Temporary_String[0] == 0xFF && Temporary_String[1] == 0xFF)
                {
                    if (Callback_Function_Event != NULL)
                    {
                        Callback_Function_Event(Invalid_Instruction);
                    }
                }
                else // Unrecognized instruction : purge serial
                {
                    Purge();
                }
            }

        default:
            Purge();
            Callback_Function_Event(Return_Code);
            break;
        }

        if (Expected_Event == Return_Code)
        {
            State = true;
        }
    }
}

void Nextion_Class::Purge()
{
    Nextion_Serial.readStringUntil(0xFF);
    while (Nextion_Serial.peek() == 0xFF)
    {
        Nextion_Serial.read();
    }
}

void Nextion_Class::Write(int Data)
{
    Nextion_Serial.write(Data);
}

void Nextion_Class::Send_Raw(const __FlashStringHelper *Data)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Data);
    Instruction_End();
}

void Nextion_Class::Send_Raw(String const &Data)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Data);
    Instruction_End();
}

void Nextion_Class::Send_Raw(const char *Data)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Data);
    Instruction_End();
}

void Nextion_Class::Refresh(uint16_t Component_ID)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("ref "));
    Nextion_Serial.print(Component_ID);
    Instruction_End();
}

void Nextion_Class::Refresh(const __FlashStringHelper *Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("ref "));
    Nextion_Serial.print(Object_Name);
    Instruction_End();
}

void Nextion_Class::Refresh(const char *Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("ref "));
    Nextion_Serial.print(Object_Name);
    Instruction_End();
}

void Nextion_Class::Set_Waveform_Refresh(bool Enable)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    if (Enable == true)
    {
        Nextion_Serial.print(F("ref_stop"));
    }
    else
    {
        Nextion_Serial.print(F("ref_star"));
    }
    Instruction_End();
}

uint16_t Nextion_Class::Get_Address()
{
    return Address;
}

void Nextion_Class::Set_Address(uint16_t Address)
{
    this->Address = Address;
}

///
/// @brief Return current displayed page ID.
///
/// @param Refresh_Now
/// @return uint8_t
uint8_t Nextion_Class::Get_Current_Page(bool Refresh_Now)
{
    if (Refresh_Now)
    {
        xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
        Nextion_Serial.print(F("sendme"));
        Instruction_End();
        DUMP(millis());
        Wait_For_Event(Current_Page_Number);
    }
    DUMP(Page_History[0]);
    return Page_History[0];
}

bool Nextion_Class::Set_Current_Page(uint8_t Page_ID, bool Feedback)
{
    DUMP("==== Set current page =====");
    DUMP(Page_ID);
    for (uint8_t i = 0; i <= 3; i++) // -- Attempts to switch page.
    {
        xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
        Nextion_Serial.print(F("page "));
        Nextion_Serial.print(Page_ID);
        vTaskDelay(pdMS_TO_TICKS(200));
        Instruction_End();
        if (i >= 3)
        {
            DUMP("Failed to set current page.");
            return false;
        }
        if (Feedback == false || Get_Current_Page(true) == Page_ID)
        {
            DUMP("Find page.");
            break;
        }
    }

    return true;
}

bool Nextion_Class::Set_Current_Page(const __FlashStringHelper *Page_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("page "));
    Nextion_Serial.print(Page_Name);
    Instruction_End();
    return true;
}

void Nextion_Class::Draw_Advanced_Crop_Picture(uint16_t X_Destination, uint16_t Y_Destination, uint16_t Width, uint16_t Height, uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Picture_ID)
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

void Nextion_Class::Draw_Fill(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Width, uint16_t Height, uint16_t Color)
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

void Nextion_Class::Set_Background_Color(const __FlashStringHelper *Object_Name, uint16_t Color, int8_t Type)
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

void Nextion_Class::Set_Time(const __FlashStringHelper *Object_Name, uint16_t Time)
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

void Nextion_Class::Set_Reparse_Mode(uint8_t Mode)
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

void Nextion_Class::Set_Trigger(const __FlashStringHelper *Object_Name, bool Enable)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".en="));
    Nextion_Serial.print(Enable);
    Instruction_End();
}

void Nextion_Class::Set_Picture(const __FlashStringHelper *Object_Name, uint8_t Picture_ID)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".pic="));
    Nextion_Serial.print(Picture_ID);
    Instruction_End();
}

void Nextion_Class::Set_Picture(String const &Object_Name, uint8_t Picture_ID)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".pic="));
    Nextion_Serial.print(Picture_ID);
    Instruction_End();
}

void Nextion_Class::Set_Font_Color(const __FlashStringHelper *Object_Name, uint16_t Color, int8_t Type)
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

void Nextion_Class::Set_Horizontal_Font_Spacing(uint16_t Spacing)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("spax="));
    Nextion_Serial.print(Spacing);
    Instruction_End();
}

void Nextion_Class::Set_Vertical_Font_Spacing(uint16_t Spacing)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("spay="));
    Nextion_Serial.print(Spacing);
    Instruction_End();
}

void Nextion_Class::Set_Mask(const __FlashStringHelper *Object_Name, bool Masked)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".pw="));
    Nextion_Serial.write(Masked);
    Instruction_End();
}

void Nextion_Class::Set_Text(const __FlashStringHelper *Object_Name, char Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".txt=\""));
    switch (Value)
    {
    case '\"':
        Nextion_Serial.write('\\');
        Nextion_Serial.write('\"');
        break;
    case '\\':
        Nextion_Serial.write('\\');
        Nextion_Serial.write('\\');
        break;
    case '\0':
        break;
    default:
        Nextion_Serial.write(Value);
        break;
    }
    Nextion_Serial.print('\"');
    Instruction_End();
}

void Nextion_Class::Set_Text(const __FlashStringHelper *Object_Name, const __FlashStringHelper *Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".txt=\""));
    Nextion_Serial.print(Value);
    Nextion_Serial.print('\"');
    Instruction_End();
}

void Nextion_Class::Set_Text(String const &Object_Name, String const &Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".txt=\""));
    Nextion_Serial.print(Value);
    Nextion_Serial.print('\"');
    Instruction_End();
}

void Nextion_Class::Set_Text(const __FlashStringHelper *Object_Name, const char *Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".txt=\""));
    uint16_t i = 0;
    while (1)
    {
        switch (Value[i])
        {
        case '\"':
            Nextion_Serial.write('\\');
            Nextion_Serial.write('\"');
            break;
        case '\\':
            Nextion_Serial.write('\\');
            Nextion_Serial.write('\\');
            break;
        case '\0':
            Nextion_Serial.write('\"');
            Instruction_End();
            return;
        default:
            Nextion_Serial.write(Value[i]);
            break;
        }
        i++;
    }
}

void Nextion_Class::Set_Text(const char *Object_Name, const char *Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".txt=\""));
    uint16_t i = 0;
    while (1)
    {
        switch (Value[i])
        {
        case '\"':
            Nextion_Serial.write('\\');
            Nextion_Serial.write('\"');
            break;
        case '\\':
            Nextion_Serial.write('\\');
            Nextion_Serial.write('\\');
            break;
        case '\0':
            Nextion_Serial.write('\"');
            Instruction_End();
            return;
        default:
            Nextion_Serial.write(Value[i]);
            break;
        }
        i++;
    }
}

void Nextion_Class::Add_Text(const __FlashStringHelper *Component_Name, const char *Data)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Component_Name);
    Nextion_Serial.print(F(".txt+=\""));
    uint16_t i = 0;
    while (1)
    {
        switch (Data[i])
        {
        case '\"':
            Nextion_Serial.write('\\');
            Nextion_Serial.write('\"');
            break;
        case '\\':
            Nextion_Serial.write('\\');
            Nextion_Serial.write('\\');
            break;
        case '\0':
            Nextion_Serial.print('\"');
            Instruction_End();
            return;
        default:
            Nextion_Serial.write(Data[i]);
            break;
        }
        i++;
    }
}

void Nextion_Class::Add_Text(const __FlashStringHelper *Object_Name, char Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".txt+=\""));
    switch (Value)
    {
    case '\"':
        Nextion_Serial.write('\\');
        Nextion_Serial.write('\"');
        break;
    case '\\':
        Nextion_Serial.write('\\');
        Nextion_Serial.write('\\');
        break;
    case '\0':
        break;
    default:
        Nextion_Serial.write(Value);
        break;
    }
    Nextion_Serial.write('\"');
    Instruction_End();
}

void Nextion_Class::Delete_Text(const __FlashStringHelper *Component_Name, uint8_t Quantity)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Component_Name);
    Nextion_Serial.print(F(".txt-="));
    Nextion_Serial.print(Quantity);
    Instruction_End();
}

void Nextion_Class::Set_Value(const __FlashStringHelper *Object_Name, uint32_t Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".val="));
    Nextion_Serial.print(Value);
    Instruction_End();
}

void Nextion_Class::Set_Value(String const &Object_Name, uint32_t Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".val="));
    Nextion_Serial.print(Value);
    Instruction_End();
}

void Nextion_Class::Set_Value(const char *Object_Name, uint32_t Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".val="));
    Nextion_Serial.print(Value);
    Instruction_End();
}

void Nextion_Class::Set_Maximum_Value(const __FlashStringHelper *Object_Name, uint16_t Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".maxval="));
    Nextion_Serial.print(Value);
    Instruction_End();
}

void Nextion_Class::Set_Minimum_Value(const __FlashStringHelper *Object_Name, uint16_t Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".minval="));
    Nextion_Serial.print(Value);
    Instruction_End();
}

void Nextion_Class::Set_Global_Variable(const __FlashStringHelper *Object_Name, uint32_t Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print("=");
    Nextion_Serial.print(Value);
    Instruction_End();
}

void Nextion_Class::Set_Font(const __FlashStringHelper *Object_Name, uint8_t Font_ID)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".font="));
    Nextion_Serial.print(Font_ID);
    Instruction_End();
}

void Nextion_Class::Set_Horizontal_Alignment(const __FlashStringHelper *Object_Name, uint8_t Alignment)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".xcen="));
    Nextion_Serial.print(Alignment);
    Instruction_End();
}

void Nextion_Class::Set_Vertical_Alignment(const __FlashStringHelper *Object_Name, uint8_t Alignment)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".ycen="));
    Nextion_Serial.print(Alignment);
    Instruction_End();
}

void Nextion_Class::Set_Grid_Width(const __FlashStringHelper *Object_Name, uint16_t Width)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".gdw="));
    Nextion_Serial.print(Width);
    Instruction_End();
}

void Nextion_Class::Set_Grid_Height(const __FlashStringHelper *Object_Name, uint16_t Height)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".gdh="));
    Nextion_Serial.print(Height);
    Instruction_End();
}

void Nextion_Class::Set_Channel_Color(const __FlashStringHelper *Object_Name, uint8_t Channel_ID, uint16_t Color)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".pco"));
    Nextion_Serial.print(Channel_ID);
    Nextion_Serial.write('=');
    Nextion_Serial.print(Color);
    Instruction_End();
}

void Nextion_Class::Set_Grid_Color(const __FlashStringHelper *Object_Name, uint16_t Color)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".gdc="));
    Nextion_Serial.print(Color);
    Instruction_End();
}

void Nextion_Class::Set_Data_Scaling(const __FlashStringHelper *Object_Name, uint16_t Scale)
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

void Nextion_Class::Draw_Crop_Picture(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Width, uint16_t Height, uint16_t Picture_ID)
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

void Nextion_Class::Draw_Text(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Width, uint16_t Height, uint16_t Font_ID, uint16_t Text_Color, uint16_t Background, uint16_t Horizontal_Alignment, uint16_t Vertical_Alignment, uint16_t Background_Type, String const &Text)
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
    Nextion_Serial.print(Background);
    Argument_Separator();
    Nextion_Serial.print(Horizontal_Alignment);
    Argument_Separator();
    Nextion_Serial.print(Vertical_Alignment);
    Argument_Separator();
    Nextion_Serial.print(Background_Type);
    Argument_Separator();
    Nextion_Serial.print('\"');
    Nextion_Serial.print(Text);
    Nextion_Serial.print('\"');
    Instruction_End();
}

void Nextion_Class::Draw_Text(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Width, uint16_t Height, uint16_t Font_ID, uint16_t Text_Color, uint16_t Background, uint16_t Horizontal_Alignment, uint16_t Vertical_Alignment, uint16_t Background_Type, const char *Text)
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
    Nextion_Serial.print(Background);
    Argument_Separator();
    Nextion_Serial.print(Horizontal_Alignment);
    Argument_Separator();
    Nextion_Serial.print(Vertical_Alignment);
    Argument_Separator();
    Nextion_Serial.print(Background_Type);
    Argument_Separator();
    Nextion_Serial.print('\"');
    uint16_t i = 0;
    while (1)
    {
        switch (Text[i])
        {
        case '\"':
            Nextion_Serial.write('\\');
            Nextion_Serial.write('\"');
            break;
        case '\\':
            Nextion_Serial.write('\\');
            Nextion_Serial.write('\\');
            break;
        case '\0':
            Nextion_Serial.write('\"');
            Instruction_End();
            return;
        default:
            Nextion_Serial.write(Text[i]);
            break;
        }
        i++;
    }
}

void Nextion_Class::Draw_Picture(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Picture_ID)
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

void Nextion_Class::Draw_Circle(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Radius, uint16_t Color, bool Hollow)
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

void Nextion_Class::Draw_Pixel(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Color)
{
    Draw_Rectangle(X_Coordinate, Y_Coordinate, 1, 1, Color);
}

void Nextion_Class::Draw_Rectangle(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Width, uint16_t Height, uint16_t Color, bool Hollow)
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

void Nextion_Class::Draw_Line(uint16_t X_Start, uint16_t Y_Start, uint16_t X_End, uint16_t Y_End, uint16_t Color)
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

void Nextion_Class::Calibrate()
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("touch_j"));
    Instruction_End();
}

void Nextion_Class::Show(const __FlashStringHelper *Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("vis "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print("1");
    Instruction_End();
}

void Nextion_Class::Show(String const &Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("vis "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print("1");
    Instruction_End();
}
void Nextion_Class::Show(const char *Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("vis "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print("1");
    Instruction_End();
}

void Nextion_Class::Hide(const __FlashStringHelper *Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("vis "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print("0");
    Instruction_End();
}

void Nextion_Class::Hide(String const &Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("vis "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print("0");
    Instruction_End();
}
void Nextion_Class::Hide(const char *Object_Name)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("vis "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print("0");
    Instruction_End();
}

void Nextion_Class::Set_Touch_Event(const __FlashStringHelper *Object_Name, bool Enable)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("tsw "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print(Enable);
    Instruction_End();
}

void Nextion_Class::Set_Execution(bool Enable)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    if (Enable == true)
    {
        Nextion_Serial.print(F("com_star"));
    }
    else
    {
        Nextion_Serial.print(F("com_stop"));
    }
    Instruction_End();
}

void Nextion_Class::Click(const __FlashStringHelper *Object_Name, uint8_t Event_Type)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("click "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print(Event_Type);
    Instruction_End();
}

void Nextion_Class::Click(const char *Object_Name, uint8_t Event_Type)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("click "));
    Nextion_Serial.print(Object_Name);
    Argument_Separator();
    Nextion_Serial.print(Event_Type);
    Instruction_End();
}

void Nextion_Class::Click(uint16_t Component_ID, uint8_t Event_Type)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("click "));
    Nextion_Serial.print(Component_ID);
    Argument_Separator();
    Nextion_Serial.print(Event_Type);
    Instruction_End();
}

void Nextion_Class::Add_Value_Waveform(uint8_t Component_ID, uint8_t Channel, uint8_t *Data, uint32_t Quantity)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("add"));
    if (Quantity == 0)
    {
        Nextion_Serial.write(' ');
        Nextion_Serial.print(Component_ID);
        Argument_Separator();
        Nextion_Serial.print(Channel);
        Argument_Separator();
        Nextion_Serial.print(Data[0]);
        Instruction_End();
    }
    else
    {
        Nextion_Serial.print("t ");
        Nextion_Serial.print(Component_ID);
        Argument_Separator();
        Nextion_Serial.print(Channel);
        Argument_Separator();
        Nextion_Serial.print(Quantity);
        Nextion_Serial.print(F("\xFF\xFF\xFF"));
        vTaskDelay(pdMS_TO_TICKS(10)); //wait display to prepare transparent mode
        Nextion_Serial.write(Data, Quantity);
        Nextion_Serial.print(F("DRAKJHSUYDGBNCJHGJKSHBDN")); // ensure that display is not in transparent mode anymore
        Instruction_End();
    }
}

void Nextion_Class::Clear_Waveform(uint16_t Component_ID, uint8_t Channel)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("cle "));
    Nextion_Serial.print(Component_ID);
    Argument_Separator();
    Nextion_Serial.print(Channel);
    Instruction_End();
}

void Nextion_Class::Reboot()
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("rest"));
    Instruction_End();
}

void Nextion_Class::Set_Standby_Serial_Timer(uint16_t Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("ussp="));
    Nextion_Serial.print(Value);
    Instruction_End();
}

void Nextion_Class::Set_Standby_Touch_Timer(uint16_t Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("thsp="));
    Nextion_Serial.print(Value);
    Instruction_End();
}

void Nextion_Class::Set_Touch_Wake_Up(bool Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("thup="));
    Nextion_Serial.print(Value);
    Instruction_End();
}

void Nextion_Class::Set_Serial_Wake_Up(bool Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("usup="));
    Nextion_Serial.print(Value);
    Instruction_End();
}

void Nextion_Class::Set_Debugging(uint8_t Level)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("bkcmd="));
    Nextion_Serial.print(Level);
    Instruction_End();
}

void Nextion_Class::Set_Wordwrap(const __FlashStringHelper *Object_Name, bool Wordwrap)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".isbr="));
    Nextion_Serial.print(Wordwrap);
    Instruction_End();
}

void Nextion_Class::Set_Wake_Up_Page(uint8_t Page_ID)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("wup="));
    Nextion_Serial.print(Page_ID);
    Instruction_End();
}

void Nextion_Class::Delay(uint16_t Delay_Time)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("delay="));
    Nextion_Serial.print(Delay_Time);
    Instruction_End();
}

uint8_t Nextion_Class::Update(File Update_File)
{
    if (!Update_File || Update_File.isDirectory())
    {
        return Update_Failed;
    }

    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);

    vTaskDelay(pdMS_TO_TICKS(250));

    while (Nextion_Serial.available()) //clear serial buffer
    {

        Nextion_Serial.read();
    }

    uint32_t Timeout;

    uint8_t i;

    const uint32_t Baud_Rate[] = {2400, 4800, 9600, 19200, 31250, 38400, 57600, 115200, 230400, 250000, 256000, 921600};

    for (i = 0; i <= 12; i++)
    {
        if (i == 12)
        {
            return Update_Failed;
        }
        Nextion_Serial.updateBaudRate(Baud_Rate[i]);

        Nextion_Serial.print(F("DRAKJHSUYDGBNCJHGJKSHBDN\xFF\xFF\xFF"));
        Nextion_Serial.print(F("connect\xFF\xFF\xFF"));

        Timeout = millis() + ((1000000 / Baud_Rate[i]) + 30);
        while (millis() <= Timeout)
        {
        }

        char Temporary_String[5];
        Nextion_Serial.readBytes(Temporary_String, 5);
        if (memcmp(Temporary_String, "comok", sizeof(Temporary_String)) == 0)
        {
            while (Nextion_Serial.available())
            {
                Nextion_Serial.read();
                vTaskDelay(pdMS_TO_TICKS(1));
            }
            break;
        }

        vTaskDelay(pdMS_TO_TICKS(1));
    }

    Nextion_Serial.print(F("dim=100\xFF\xFF\xFF"));
    Nextion_Serial.print(F("ussp=0\xFF\xFF\xFF"));
    Nextion_Serial.print(F("thsp=0\xFF\xFF\xFF"));

    Nextion_Serial.print(F("whmi-wri "));
    Nextion_Serial.print(Update_File.size());
    Argument_Separator();
    Nextion_Serial.print(Baud_Rate[i]);
    Argument_Separator();
    Nextion_Serial.print(F("0\xFF\xFF\xFF"));

    char Temporary_Buffer[4096];
    memset(Temporary_Buffer, '\0', sizeof(Temporary_Buffer));

    while (Update_File.available() >= 4096)
    {
        if (Update_File.readBytes(Temporary_Buffer, sizeof(Temporary_Buffer)) != 4096)
        {
            return Update_Failed;
        }

        Timeout = millis() + 3000;
        while (Nextion_Serial.read() != 0x05)
        {
            if (millis() > Timeout)
            {
                return Update_Failed;
            }
        }

        Nextion_Serial.write(Temporary_Buffer, sizeof(Temporary_Buffer));

        vTaskDelay(pdMS_TO_TICKS(1));
    }

    memset(Temporary_Buffer, '\0', sizeof(Temporary_Buffer));

    uint16_t Remaining_Bytes = Update_File.available();

    Update_File.readBytes(Temporary_Buffer, Remaining_Bytes);

    Timeout = millis() + 3000;
    while (Nextion_Serial.read() != 0x05)
    {
        if (millis() > Timeout)
        {
            return Update_Failed;
        }
    }

    Nextion_Serial.write(Temporary_Buffer, Remaining_Bytes);

    Timeout = millis() + 3000;
    while (Nextion_Serial.read() != 0x05)
    {
        if (millis() > Timeout)
        {
            return Update_Failed;
        }
    }

    return Update_Succeed;
}

// Sleep & Wake up

void Nextion_Class::Sleep()
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("sleep=1"));
    Instruction_End();
}

void Nextion_Class::Wake_Up()
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("sleep=0"));
    Instruction_End();
}

void Nextion_Class::Get(const __FlashStringHelper *Attribute)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("get "));
    Nextion_Serial.print(Attribute);
    Instruction_End();
}

void Nextion_Class::Clear(uint16_t Color)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("cls "));
    Nextion_Serial.print(Color);
    Instruction_End();
}

void Nextion_Class::Set_Drawing(bool Enable)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("thdra="));
    Nextion_Serial.print(Enable);
    Instruction_End();
}

void Nextion_Class::Set_Draw_Color(uint16_t Color)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("thc="));
    Nextion_Serial.print(Color);
    Instruction_End();
}

void Nextion_Class::Set_Random_Generator(int32_t Minimum, int32_t Maximum)
{
    if (Minimum > Maximum)
    {
        return;
    }
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(F("randset "));
    Nextion_Serial.print(Minimum);
    Argument_Separator();
    Nextion_Serial.print(Maximum);
    Instruction_End();
}

void Nextion_Class::Set_Display_Baud_Rate(uint32_t Baud_Rate, bool Save)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    if (Baud_Rate > 921000)
    {
        return;
    }
    Nextion_Serial.print(F("baud"));
    if (Save)
    {
        Nextion_Serial.print(F("s"));
    }
    Nextion_Serial.print(F("="));
    Nextion_Serial.print(Baud_Rate);
    Instruction_End();
}

void Nextion_Class::Set_Baud_Rate(uint32_t Baud_Rate)
{
    Nextion_Serial.updateBaudRate(Baud_Rate);
}

void Nextion_Class::Set_Brightness(uint16_t Brightness, bool Save)
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