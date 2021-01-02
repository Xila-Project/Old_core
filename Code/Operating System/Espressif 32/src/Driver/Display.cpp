#include "Driver/Display.hpp"

Nextion_Display_Class *Nextion_Display_Class::Display_Pointer = NULL;

Nextion_Display_Class::Nextion_Display_Class() : Nextion_Serial(1),
                                                 Callback_Function_String_Data(NULL),
                                                 Callback_Function_Numeric_Data(NULL),
                                                 Callback_Function_Event(NULL)

{
    if (Display_Pointer != NULL)
    {
        delete this;
    }
    Display_Pointer = this;
    Serial_Semaphore = xSemaphoreCreateMutex();
}

Nextion_Display_Class::~Nextion_Display_Class()
{
    Display_Pointer = NULL;
    vSemaphoreDelete(Serial_Semaphore);
    vTaskDelete(Nextion_Serial_Handle);
}

void Nextion_Display_Class::Begin(uint32_t Baud_Rate, uint8_t RX_Pin, uint8_t TX_Pin)
{
    Nextion_Serial.begin(Baud_Rate, SERIAL_8N1, RX_Pin, TX_Pin); //Nextion UART
    xTaskCreatePinnedToCore(Nextion_Serial_Receive, "Nextion Serial", 1024 * 4, NULL, DRIVER_TASK_PRIORITY, &Nextion_Serial_Handle, SYSTEM_CORE);
}

void Nextion_Display_Class::Set_Callback_Function_String_Data(void (*Function_Pointer)(const char *, uint8_t))
{
    Callback_Function_String_Data = Function_Pointer;
}

void Nextion_Display_Class::Set_Callback_Function_Numeric_Data(void (*Function_Pointer)(uint32_t &))
{
    Callback_Function_Numeric_Data = Function_Pointer;
}

void Nextion_Display_Class::Set_Callback_Function_Event(void (*Function_Pointer)(uint8_t &))
{
    Callback_Function_Event = Function_Pointer;
}

void Nextion_Serial_Receive(void *pvParameters) //Parsing incomming data
{
    if (Nextion_Display_Class::Display_Pointer == NULL)
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
        if (Nextion_Display_Class::Display_Pointer->Nextion_Serial.available())
        {
            Return_Code = Nextion_Display_Class::Display_Pointer->Nextion_Serial.read();
            Serial.print(F("|| R_C : "));
            Serial.println(Return_Code, HEX);
            switch (Return_Code)
            {
            case Nextion_Display_Class::Numeric_Data_Enclosed:

                if (7 == Nextion_Display_Class::Display_Pointer->Nextion_Serial.readBytes((char *)Temporary_String, 7))
                {
                    if (Temporary_String[4] == 0xFF && Temporary_String[5] == 0xFF && Temporary_String[6] == 0xFF)
                    {
                        uint32_t Temporary_Long = ((uint32_t)Temporary_String[4] << 24) | ((uint32_t)Temporary_String[3] << 16) | ((uint32_t)Temporary_String[2] << 8) | (Temporary_String[1]);
                        (Nextion_Display_Class::Display_Pointer->Callback_Function_Numeric_Data(Temporary_Long));
                    }
                }
                break;
            case Nextion_Display_Class::String_Data_Enclosed:
                Temporary_Byte = DISPLAY_POINTER->Nextion_Serial.readBytesUntil(0xFF, Temporary_String, sizeof(Temporary_String));
                DISPLAY_POINTER->Nextion_Serial.read();
                DISPLAY_POINTER->Nextion_Serial.read();
                Temporary_String[Temporary_Byte] = '\0';
                if (Nextion_Display_Class::Display_Pointer->Callback_Function_String_Data != NULL)
                {
                    (DISPLAY_POINTER->Callback_Function_String_Data(Temporary_String, sizeof(Temporary_String)));
                }
                break;
            case Nextion_Display_Class::Current_Page_Number:
                if (4 == Nextion_Display_Class::Display_Pointer->Nextion_Serial.readBytes((char *)Temporary_String, 4))
                {
                    if (Temporary_String[1] == 0xFF && Temporary_String[2] == 0xFF && Temporary_String[3] == 0xFF)
                    {

                        DISPLAY_POINTER->Page_History[5] = DISPLAY_POINTER->Page_History[4];
                        DISPLAY_POINTER->Page_History[3] = DISPLAY_POINTER->Page_History[2];
                        DISPLAY_POINTER->Page_History[2] = DISPLAY_POINTER->Page_History[1];
                        DISPLAY_POINTER->Page_History[1] = DISPLAY_POINTER->Page_History[0];
                        DISPLAY_POINTER->Page_History[0] = Temporary_String[0];
                    }
                }
                break;

            case Nextion_Display_Class::Invalid_Instruction:
                switch (Nextion_Display_Class::Display_Pointer->Nextion_Serial.read()) //Distinguish Invalid instruction && startup
                {
                case 0x00: // Startup Instruction
                    Nextion_Display_Class::Display_Pointer->Nextion_Serial.readBytes((char *)Temporary_String, 5);
                    if (Temporary_String[0] == 0x00 && Temporary_String[1] == 0x00)
                    {
                        if (Temporary_String[2] == 0xFF && Temporary_String[3] == 0xFF && Temporary_String[4] == 0xFF)
                        {
                            if (Nextion_Display_Class::Display_Pointer->Callback_Function_Event != NULL)
                            {
                                Temporary_Byte = Nextion_Display_Class::Startup;
                                Nextion_Display_Class::Display_Pointer->Callback_Function_Event(Temporary_Byte);
                            }
                        }
                        else // unrecognize command : purge serial
                        {
                            DISPLAY_POINTER->Nextion_Serial.readStringUntil(0xFF);
                            DISPLAY_POINTER->Nextion_Serial.read();
                            DISPLAY_POINTER->Nextion_Serial.read();
                            DISPLAY_POINTER->Nextion_Serial.read();
                        }
                    }

                case 0xFF: //Invalid Instruction
                    Nextion_Display_Class::Display_Pointer->Nextion_Serial.readBytes((char *)Temporary_String, 3);
                    if (Temporary_String[0] == 0xFF && Temporary_String[1] == 0xFF && Temporary_String[2] == 0xFF)
                    {
                        if (Nextion_Display_Class::Display_Pointer->Callback_Function_Event != NULL)
                        {
                            Temporary_Byte = Nextion_Display_Class::Invalid_Instruction;
                            Nextion_Display_Class::Display_Pointer->Callback_Function_Event(Temporary_Byte);
                        }
                    }
                    else // Unrecognized instruction : purge serial
                    {
                        DISPLAY_POINTER->Nextion_Serial.readStringUntil(0xFF);
                        DISPLAY_POINTER->Nextion_Serial.read();
                        DISPLAY_POINTER->Nextion_Serial.read();
                        DISPLAY_POINTER->Nextion_Serial.read();
                    }
                }

            default:
                DISPLAY_POINTER->Nextion_Serial.readStringUntil(0xFF);
                DISPLAY_POINTER->Nextion_Serial.read();
                DISPLAY_POINTER->Nextion_Serial.read();
                DISPLAY_POINTER->Nextion_Serial.read();
                Nextion_Display_Class::Display_Pointer->Callback_Function_Event(Return_Code);
                break;
            }
        }
        vTaskDelay(pdMS_TO_TICKS(20));
    }
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
    Nextion_Serial.print(F(".pw=\""));
    Nextion_Serial.print(Input_Type);
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

void Nextion_Display_Class::Set_Value(const __FlashStringHelper *Object_Name, uint32_t const &Value)
{
    xSemaphoreTake(Serial_Semaphore, portMAX_DELAY);
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".val="));
    Nextion_Serial.print(String(Value));
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
    Nextion_Serial.print(String(Value));
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

void Nextion_Display_Class::Draw_Circle(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Radius, uint16_t const &, uint16_t const &Color, bool const &Hollow)
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

void Nextion_Display_Class::Add_Value_Waveform(uint16_t const &Component_ID, uint8_t const &Channel, uint32_t *Data, uint32_t const &Quantity)
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
    }
    else
    {
        Nextion_Serial.print(F("t "));
        Nextion_Serial.print(Component_ID);
        Argument_Separator();
        Nextion_Serial.print(Channel);
        Argument_Separator();
        Nextion_Serial.print(Quantity);
        vTaskDelay(pdMS_TO_TICKS(10)); //wait display to prepare transparent mode
        for (uint16_t i = 0; i < Quantity; i++)
        {
            Nextion_Serial.write(Data[i]);
        }
    }
    Instruction_End();
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