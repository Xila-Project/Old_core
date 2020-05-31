#include "Display.hpp"

uint8_t Number_Instance = 0;

Nextion_Display_Class *Nextion_Display_Class::Display_Pointer;

Nextion_Display_Class::Nextion_Display_Class(uint32_t const &Baud_Rate, uint8_t const &RX_Pin, uint8_t const &TX_Pin)
{
    ++Number_Instance;
    if (Number_Instance > 1)
    {
        delete this;
    }
    Display_Pointer = this;

    Nextion_Serial.begin(Baud_Rate, SERIAL_8N1, RX_Pin, TX_Pin); //Nextion UART
    xTaskCreatePinnedToCore(Nextion_Serial_Receive, "Nextion Serial", 1024 * 3, NULL, 2, &Nextion_Serial_Handle, 1);
}

Nextion_Display_Class::~Nextion_Display_Class()
{
    vTaskDelete(Nextion_Serial_Handle);
}

void Nextion_Display_Class::Set_Callback_Function_String_Data(void (*Function_Pointer)(String))
{
    Callback_Function_String_Data = Function_Pointer;
}

void Nextion_Display_Class::Set_Callback_Function_Numeric_Data(void(*Function_Pointer(uint32_t)))
{
    Callback_Function_Numeric_Data = Function_Pointer;
}

void Nextion_Display_Class::Set_Callback_Function_Event(void(*Function_Pointer(uint16_t)))
{
    Callback_Function_Event = Function_Pointer;
}

void Nextion_Serial_Receive(void *pvParameters) //Parsing incomming data
{
    if (Display_Pointer == NULL)
    {
        vTaskDelete(NULL);
    }
    uint8_t Return_Code = 0;
    uint8_t Temporary_Byte_Array[] = {0, 0, 0, 0, 0, 0, 0};
    String Temporary_String = String("");

    (void)pvParameters;
    for (;;)
    {
        if (Display_Pointer->Nextion_Serial.available())
        {
            Return_Code = Display_Pointer->Nextion_Serial.read();
            Serial.print(F("|| R_C : "));
            Serial.print(Return_Code);
            switch (Return_Code)
            {
            case NEXTION_INFORMATION_NUMERIC_DATA_ENCLOSED:

                if (7 == Display_Pointer->Nextion_Serial.readBytes((char *)Temporary_Byte_Array, 7))
                {
                    if (Temporary_Byte_Array[4] == 0xFF && Temporary_Byte_Array[5] == 0xFF && Temporary_Byte_Array[6] == 0xFF)
                    {
                        uint32_t Temporary_Long = ((uint32_t)Temporary_Byte_Array[4] << 24) | ((uint32_t)Temporary_Byte_Array[3] << 16) | ((uint32_t)Temporary_Byte_Array[2] << 8) | (Temporary_Byte_Array[1]);
                        (Display_Pointer->Callback_Function_Numeric_Data(Temporary_Long));
                    }
                }
                break;
            case NEXTION_INFORMATION_STRING_DATA_ENCLOSED:
                Temporary_String = String("");
                while (Display_Pointer->Nextion_Serial.available())
                {
                    Temporary_Byte_Array[0] = Display_Pointer->Nextion_Serial.read();
                    if (Temporary_Byte_Array[0] == 255)
                    {
                        ++Temporary_Byte_Array[1];
                        if (Temporary_Byte_Array[1] >= 3) //end of message
                        {
                            break;
                        }
                    }
                    else
                    {
                        Temporary_String += (char)Temporary_Byte_Array[2];
                    }
                }
                if (Display_Pointer->Callback_Function_String_Data != NULL)
                {
                    (Display_Pointer->Callback_Function_String_Data(Temporary_String));
                }
                break;

            case NEXTION_INFORMATION_CURRENT_PAGE_NUMBER:
                if (4 == Display_Pointer->Nextion_Serial.readBytes((char *)Temporary_Byte_Array, 4))
                {
                    if (Temporary_Byte_Array[1] == 0xFF && Temporary_Byte_Array[2] == 0xFF && Temporary_Byte_Array[3] == 0xFF)
                    {
                        Display_Pointer->Last_Page = Display_Pointer->Current_Page;
                        Display_Pointer->Current_Page = Temporary_Byte_Array[0];
                    }
                }
                break;

            case NEXTION_ERROR_INVALID_INSTRUCTION:
                switch (Display_Pointer->Nextion_Serial.read()) //Distinguish Invalid instruction && startup
                {
                case 0x00: // Startup_Instruction
                    Display_Pointer->Nextion_Serial.readBytes((char *)Temporary_Byte_Array, 5);
                    if (Temporary_Byte_Array[0] == 0x00 && Temporary_Byte_Array[1] == 0x00)
                    {
                        if (Temporary_Byte_Array[2] == 0xFF && Temporary_Byte_Array[3] == 0xFF && Temporary_Byte_Array[4] == 0xFF)
                        {
                            if (Display_Pointer->Callback_Function_Event != NULL)
                            {
                                Display_Pointer->Callback_Function_Event(NEXTION_INFORMATION_STARTUP);
                            }
                        }
                    }

                case 0xFF: //Invalid Instruction
                    Display_Pointer->Nextion_Serial.readBytes((char *)Temporary_Byte_Array, 3);
                    if (Temporary_Byte_Array[0] == 0xFF && Temporary_Byte_Array[1] == 0xFF && Temporary_Byte_Array[2] == 0xFF)
                    {
                        if (Display_Pointer->Callback_Function_Event != NULL)
                        {
                            Display_Pointer->Callback_Function_Event(NEXTION_ERROR_INVALID_INSTRUCTION);
                        }
                    }
                }

            default:

                Temporary_Byte_Array[1] = 0;                        //counter for 0xFF ending code
                while (Display_Pointer->Nextion_Serial.available()) //Purge until the end of the intruction
                {
                    Temporary_Byte_Array[0] = Display_Pointer->Nextion_Serial.read();
                    if (Temporary_Byte_Array[0] == 0xFF)
                    {
                        Temporary_Byte_Array[1]++;
                        if (Temporary_Byte_Array[1] >= 3)
                        {
                            break;
                        }
                    }
                }
                Display_Pointer->Callback_Function_Event(Return_Code);
                break;
            }
        }
        vTaskDelay(50);
    }
}

void Nextion_Display_Class::Refresh_Current_Page()
{
    Get(F("dp"));
}

uint8_t& Nextion_Display_Class::Get_Current_Page()
{
    return Current_Page;
}

void Nextion_Display_Class::Set_Current_Page(uint8_t const& Page_ID)
{
    Nextion_Serial.print(F("page "));
    Nextion_Serial.print(Page_ID);
    Instruction_End();
}

void Nextion_Display_Class::Set_Current_Page(const __FlashStringHelper* Page_Name)
{
    Nextion_Serial.print(F("page "));
    Nextion_Serial.print(Page_Name);
    Instruction_End();
}

void Nextion_Display_Class::Draw_Advanced_Crop_Picture(uint16_t const &X_Destination, uint16_t const &Y_Destination, uint16_t const &Width, uint16_t const &Height, uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Picture_ID)
{
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

void Nextion_Display_Class::Set_Background_Color(const __FlashStringHelper *Object_Name, uint16_t const &Color, int8_t Type = -1)
{
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

void Nextion_Display_Class::Set_Time(const __FlashStringHelper* Object_Name, uint16_t const& Time)
{
    if(Time < 50)
    {
        return;
    }
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".tim="));
    Nextion_Serial.print(Time);
    Instruction_End();
}

void Nextion_Display_Class::Set_Picture(const __FlashStringHelper* Object_Name, uint8_t const& Picture_ID)
{
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".pic="));
    Nextion_Serial.print(Picture_ID);
    Instruction_End();
}

void Nextion_Display_Class::Set_Picture(String const& Object_Name, uint8_t const& Picture_ID)
{
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".pic="));
    Nextion_Serial.print(Picture_ID);
    Instruction_End();
}

void Nextion_Display_Class::Set_Font_Color(const __FlashStringHelper *Object_Name, uint16_t const &Color, int8_t Type = -1)
{
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
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".pw=\""));
    Nextion_Serial.print(Input_Type);
    Nextion_Serial.print(F("\""));
    Instruction_End();
}

void Nextion_Display_Class::Set_Text(const __FlashStringHelper *Object_Name, const __FlashStringHelper *Value)
{
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".txt=\""));
    Nextion_Serial.print(Value);
    Nextion_Serial.print(F("\""));
    Instruction_End();
}

void Nextion_Display_Class::Set_Font(const __FlashStringHelper *Object_Name, uint8_t const &Font_ID)
{
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".font="));
    Nextion_Serial.print(Font_ID);
    Instruction_End();
}

void Nextion_Display_Class::Set_Data_Scalling(const __FlashStringHelper* Object_Name, uint16_t const& Scale)
{
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

void Nextion_Display_Class::Draw_Picture(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Picture_ID)
{
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

void Nextion_Display_Class::Draw_Rectangle(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint16_t const &Color, bool const &Hollow = false)
{
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
    Nextion_Serial.print(F("touch_j"));
    Instruction_End();
}

void Nextion_Display_Class::Reboot()
{
    Nextion_Serial.print(F("rest"));
    Instruction_End();
}

uint8_t Nextion_Display_Class::Update(String const &File_Path)
{
    vTaskSuspend(Nextion_Serial_Handle);
    if (!SD_MMC.exists(File_Path))
    {
        //error handle
        return 0;
    }
    while (Nextion_Serial.available()) //clear serial buffer
    {
        Nextion_Serial.read();
    }
    Instruction_End();
    Nextion_Serial.print(F("DRAKJHSUYDGBNCJHGJKSHBDN"));
    Instruction_End();
    Instruction_End(); //twice to clear
    Nextion_Serial.print(F("connect"));
    Instruction_End();
    Nextion_Serial.print(F("ÿÿconnect"));
    Instruction_End();
    byte i = 0;
    while (Nextion_Serial.available() == 0)
    {
        vTaskDelay(pdMS_TO_TICKS(100));
        i++;
        if (i > 50)
        {
            //error handle : no reply from screen
            return 0;
        }
    }
    String Temporary_String = "";
    for (byte i = 0; i < 5; i++)
    {
        Temporary_String += char(Nextion_Serial.read());
    }
    while (Nextion_Serial.available())
    {
        Nextion_Serial.read();
    }
    if (Temporary_String != "comok")
    {
        return 0;
    }
    Temporary_File = SD_MMC.open(File_Path, FILE_READ);
    uint32_t Size = Temporary_File.size();

    Nextion_Serial.print(F("whmi-wri "));
    Nextion_Serial.print(Size);
    Argument_Separator();
    Nextion_Serial.print(F("921600"));
    Argument_Separator();
    Nextion_Serial.print(F("res0"));
    Instruction_End();

    while (Temporary_File.available() >= 4096)
    {
        while (Nextion_Serial.available() == 0)
        {
            vTaskDelay(50);
        }
        if (Nextion_Serial.read() != 0x05)
        {
            //error handle
            return 0;
        }
        for (uint16_t i = 0; i < 4096; i++)
        {
            Nextion_Serial.print(Temporary_File.read());
        }
    }
    while (Temporary_File.available()) //final packet
    {
        Nextion_Serial.print(Temporary_File.read());
    }
    while (Nextion_Serial.available() == 0)
    {
        vTaskDelay(50);
    }
    if (Nextion_Serial.read() != 0x05)
    {
        //error handle
        return;
    }
    Serial.println(F("Succefully transmited file"));
}

void Nextion_Display_Class::Get(const __FlashStringHelper* Object_Name)
{
    Nextion_Serial.print(F("get "));
    Nextion_Serial.print(Object_Name);
    Instruction_End();
}

void Nextion_Display_Class::Clear(uint16_t const &Color)
{
    Nextion_Serial.print(F("cls"));
    Instruction_End();
}

void Nextion_Display_Class::Set_Draw_Color(uint16_t const &Color)
{
    Nextion_Serial.print(F("thc="));
    Nextion_Serial.print(Color);
    Instruction_End();
}

void Nextion_Display_Class::Set_Baud_Rate(uint32_t const &Baudrate, bool const &Save)
{
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

void Nextion_Display_Class::Set_Backlight(uint8_t const &Brightness, bool const &Save = false)
{
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
}

void Nextion_Display_Class::Argument_Separator()
{
    Nextion_Serial.print(F(","));
}