#include "Display.hpp"

uint8_t Number_Instance = 0;
Nextion_Display_Class *Display_Pointer;

Nextion_Display_Class::Nextion_Display_Class(uint32_t const& Baud_Rate = 921600, uint8_t const& RX_Pin = 16, uint8_t const& TX_Pin = 17)
{
    ++Number_Instance;
    if (Number_Instance > 1)
    {
        delete this;
    }
    Display_Pointer = this;

    Nextion_Serial.begin(Baud_Rate, SERIAL_8N1, RX_Pin, TX_Pin); //Nextion UART
    xTaskCreatePinnedToCore(Nextion_Serial_Receive, "Nextion Serial", 1024 * 3, Nextion_Serial_Handle, 1);
}

Nextion_Display_Class::~Nextion_Display_Class()
{
    vTaskDelete(Nextion_Serial_Handle);
    Display_Pointer = NULL;
}

void Nextion_Serial_Receive(void *pvParameters)
{
    if (Display_Pointer == NULL)
    {
        vTaskDelete(NULL);
    }
    static char Tag;
    uint8_t Return_Code = 0;
    uint8_t Temporary_Byte_Array[7] = {0};
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
                Serial.print(F(" | Tag : "));
                Serial.print(Tag);
                Serial.print(F(" | Raw :"));
                Serial.write(Temporary_Byte_Array[4]);
                Serial.write(Temporary_Byte_Array[3]);
                Serial.write(Temporary_Byte_Array[2]);
                Serial.write(Temporary_Byte_Array[1]);

                if (7 == Display_Pointer->Nextion_Serial.readBytes((char *)Temporary_Byte_Array, 7))
                {
                    if (Temporary_Byte_Array[4] == 0xFF && Temporary_Byte_Array[5] == 0xFF && Temporary_Byte_Array[6] == 0xFF)
                    {
                        long Temporary_Long = ((long)Temporary_Byte_Array[4] << 24) | ((long)Temporary_Byte_Array[3] << 16) | (Temporary_Byte_Array[2] << 8) | (Temporary_Byte_Array[1]);
                        if (Tag != 0x00)
                        {
                            Serial.print(F(" | Long : "));
                            Serial.println(Temporary_Long);
                            //GalaxOS.Set_Variable(Tag, Temporary_Long);
                            Tag = '\0';
                        }
                        else
                        {
                            Serial.println(F("Error : Cannot Set Variable Because Tag is NULL."));
                            //error handle
                        }
                    }
                }
                break;
            case NEXTION_INFORMATION_STRING_DATA_ENCLOSED:
                Temporary_String = String("");
                Temporary_Byte_Array[0] = Display_Pointer->Nextion_Serial.read();
                Serial.print(F(" | Type : "));
                Serial.print(Temporary_Byte_Array[0]);
                if (Temporary_Byte_Array[0] != CODE_COMMAND && Temporary_Byte_Array[0] != CODE_COMMAND_NEW) //not a command, therefore a variable
                {
                    Temporary_Byte_Array[1] = Display_Pointer->Nextion_Serial.read(); //tag or ID
                    Serial.print(F(" | Tag : "));
                    Serial.print(Temporary_Byte_Array[1]);
                    switch (Temporary_Byte_Array[0])
                    {
                    case CODE_VARIABLE_CHAR:
                        Tag = (char)Temporary_Byte_Array[1];
                        GalaxOS.Set_Variable(Tag, (char)Display_Pointer->Nextion_Serial.read());
                        Tag = '\0';
                        break;
                    case CODE_VARIABLE_STRING:
                        Tag = (char)Temporary_Byte_Array[1];
                        break;
                    case CODE_VARIABLE_LONG:
                        Tag = (char)Temporary_Byte_Array[1];
                        break;
                    case CODE_VARIABLE_UNSIGNED_LONG:
                        Tag = (char)Temporary_Byte_Array[1];
                        break;
                    case CODE_SOFTWARE_OPEN:
                        GalaxOS.Open_Software(Temporary_Byte_Array[1]);
                        break;
                    case CODE_SOFTWARE_CLOSE:
                        GalaxOS.Close_Software(Temporary_Byte_Array[1]);
                        break;
                    default:
                        //error handle
                        break;
                    }
                }
                Temporary_Byte_Array[3] = 0; //counter for 0xFF ending code
                while (Display_Pointer->Nextion_Serial.available())
                {
                    Temporary_Byte_Array[2] = Display_Pointer->Nextion_Serial.read();
                    if (Temporary_Byte_Array[2] == 255)
                    {
                        ++Temporary_Byte_Array[3];
                        if (Temporary_Byte_Array[3] >= 3)
                        {
                            Serial.println(F(" ||"));
                            break;
                        }
                    }
                    else
                    {
                        Temporary_String += (char)Temporary_Byte_Array[2];
                        Serial.print((char)Temporary_Byte_Array[2]);
                    }
                }
                if (Temporary_Byte_Array[0] == CODE_VARIABLE_STRING)
                {
                    GalaxOS.Set_Variable(Tag, Temporary_String);
                    Temporary_String = String("");
                    Tag = '\0';
                }
                else if (Temporary_Byte_Array[0] == CODE_COMMAND || Temporary_Byte_Array[0] == CODE_COMMAND_NEW)
                {
                    if (Temporary_String == "LoadSystem")
                    {
                        GalaxOS.Load_System_Files();
                    }
                    else if (Temporary_String == "Login")
                        GalaxOS.Load_User_Files();
                    else if (Temporary_String == "OpenMenu")
                        GalaxOS.Open_Menu();
                    else if (Temporary_String == "OpenDesk")
                        GalaxOS.Open_Desk();
                    else if (Temporary_String == "F&F")
                        Files_And_Folders();
                    //else if (Temporary_String == "F&F_RDelete") Event_Handler_Request();
                    //taskbar item
                    else if (Temporary_String == "TBItem1")
                    {
                        Display_Pointer->Nextion_Serial.print(F("page "));
                        Display_Pointer->Nextion_Serial.print(GalaxOS.Taskbar_Items_PID[0]);
                        Display_Pointer->Nextion_Serial.print(F("\xFF\xFF\xFF"));
                    }
                    else if (Temporary_String == "TBItem2")
                    {
                        Display_Pointer->Nextion_Serial.print(F("page "));
                        Display_Pointer->Nextion_Serial.print(GalaxOS.Taskbar_Items_PID[1]);
                        Display_Pointer->Nextion_Serial.print(F("\xFF\xFF\xFF"));
                    }
                    else if (Temporary_String == "TBItem3")
                    {
                        Display_Pointer->Nextion_Serial.print(F("page "));
                        Display_Pointer->Nextion_Serial.print(GalaxOS.Taskbar_Items_PID[2]);
                        Display_Pointer->Nextion_Serial.print(F("\xFF\xFF\xFF"));
                    }
                    else if (Temporary_String == "TBItem4")
                    {
                        Display_Pointer->Nextion_Serial.print(F("page "));
                        Display_Pointer->Nextion_Serial.print(GalaxOS.Taskbar_Items_PID[3]);
                        Display_Pointer->Nextion_Serial.print(F("\xFF\xFF\xFF"));
                    }
                    else if (Temporary_String == "TBItem5")
                    {
                        Display_Pointer->Nextion_Serial.print(F("page "));
                        Display_Pointer->Nextion_Serial.print(GalaxOS.Taskbar_Items_PID[4]);
                        Display_Pointer->Nextion_Serial.print(F("\xFF\xFF\xFF"));
                    }
                    else if (Temporary_String == "TBItem6")
                    {
                        Display_Pointer->Nextion_Serial.print(F("page "));
                        Display_Pointer->Nextion_Serial.print(GalaxOS.Taskbar_Items_PID[5]);
                        Display_Pointer->Nextion_Serial.print(F("\xFF\xFF\xFF"));
                    }
                    else if (Temporary_String == "TBItem7")
                    {
                        Display_Pointer->Nextion_Serial.print(F("page "));
                        Display_Pointer->Nextion_Serial.print(GalaxOS.Taskbar_Items_PID[6]);
                        Display_Pointer->Nextion_Serial.print(F("\xFF\xFF\xFF"));
                    }
                    else
                    {
                        switch (GalaxOS.Current_Page)
                        {
                        case 20: //Event
                            GalaxOS.Event_Reply = uint8_t(Temporary_String.charAt(1));
                            break;
                        case 27: //iGOS
                            GalaxOS.iGOS_Pointer->Execute(Temporary_String.charAt(0), Temporary_String.charAt(1));
                            break;
                        case 38: //Piano
                            GalaxOS.Piano_Pointer->Execute(Temporary_String.charAt(0), Temporary_String.charAt(1));
                            break;
                        default:
                            Serial.println(F("Unknow Page ID"));
                            break;
                        }
                    }
                }
                break;
            case INFORMATION_NEXTION_CURRENT_PAGE_NUMBER:
                if (4 == Display_Pointer->Nextion_Serial.readBytes((char *)Temporary_Byte_Array, 4))
                {
                    if (Temporary_Byte_Array[1] == 0xFF && Temporary_Byte_Array[2] == 0xFF && Temporary_Byte_Array[3] == 0xFF)
                    {
                        Serial.print(F(" | Current Page : "));
                        Serial.print(Temporary_Byte_Array[0]);

                        GalaxOS.Last_Page = GalaxOS.Current_Page;
                        GalaxOS.Current_Page = Temporary_Byte_Array[0];
                    }
                }
                break;
            default:
                Temporary_Byte_Array[3] = 0;                        //counter for 0xFF ending code
                while (Display_Pointer->Nextion_Serial.available()) //Purge until the end of the intruction
                {
                    Temporary_Byte_Array[2] = Display_Pointer->Nextion_Serial.read();
                    if (Temporary_Byte_Array[2] == 0xFF)
                    {
                        Temporary_Byte_Array[3]++;
                        if (Temporary_Byte_Array[3] >= 3)
                        {

                            break;
                        }
                    }
                }
                GalaxOS.Event_Handler((int)Temporary_Byte_Array[0]);
                break;
            }
        }
        vTaskDelay(50);
    }
}

void Nextion_Display_Class::Argument_Separator()
{
    Nextion_Serial.print(F(","));
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

void Nextion_Display_Class::Set_Background_Color(const __FlashStringHelper *Object_Name, uint16_t const& Color, int8_t Type = -1)
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

void Nextion_Display_Class::Set_Font_Color(const __FlashStringHelper *Object_Name, uint16_t const& Color, int8_t Type = -1)
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
void Nextion_Display_Class::Set_Input_Type(const __FlashStringHelper *Object_Name, uint8_t const& Input_Type)
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

void Nextion_Display_Class::Set_Font(const __FlashStringHelper *Object_Name, uint8_t const& Font_ID)
{
    Nextion_Serial.print(Object_Name);
    Nextion_Serial.print(F(".font="));
    Nextion_Serial.print(Font_ID);
    Instruction_End();
}

void Nextion_Display_Class::Set_Data_Scalling(const __FlashStringHelper *Object_Name, uint16_t Scale)
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
