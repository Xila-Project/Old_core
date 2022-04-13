///
/// @file Nextion_Library.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Nextion driver display.
/// @version 0.1
/// @date 25-05-2020
///
/// @copyright Copyright (c) 2021
///

#ifndef NEXTION_LIBRARY_H_INCLUDED
#define NEXTION_LIBRARY_H_INCLUDED

#include "Arduino.h"
#include "HardwareSerial.h"
#include "FS.h"
#include "Configuration.hpp"
#include "ArduinoTrace.h"

class Nextion_Class
{
public:
    // -- Constructors / Destructors
    Nextion_Class();
    ~Nextion_Class();

    // -- Enumerations

    enum Errors
    {
        Invalid_Instruction = 0x00,
        Invalid_Component_ID = 0x02,
        Invalid_Page_ID = 0x03,
        Invalid_Picture_ID = 0x04,
        Invalid_Font_ID = 0x05,
        Invalid_File_Operation = 0x06,
        Invalid_CRC = 0x09,
        Invalid_Baud_Rate_Setting = 0x11,
        Invalid_Waveform_ID_Or_Channel = 0x12,
        Invalid_Variable_Name_Or_Attribute = 0x1A,
        Invalid_Variable_Operation = 0x1B,
        Fail_To_Assign = 0x1C,
        Fail_EEPROM_Operation = 0x1D,
        Invalid_Quantity_Of_Parameters = 0x1E,
        IO_Operation_Failed = 0x1F,
        Invalid_Escape_Character = 0x20,
        Too_Long_Variable_Name = 0x23,
        Serial_Buffer_Overflow = 0x24,
        Update_Failed = 0x25
    };

    enum Informations
    {
        Startup = 0x07,
        Instruction_Successfull = 0x01,
        Touch_Event = 0x65,
        Current_Page_Number = 0x66,
        Touch_Coordinate_Awake = 0x67,
        Touch_Coordinate_Sleep = 0x68,
        String_Data_Enclosed = 0x70,
        Numeric_Data_Enclosed = 0x71,
        Auto_Entered_Sleep_Mode = 0x86,
        Auto_Wake_From_Sleep_Mode = 0x87,
        Ready = 0x88,
        Start_Upgrade_From_SD = 0x89,
        Transparent_Data_Finished = 0xFD,
        Transparent_Data_Ready = 0xFE,
        Update_Succeed = 0x69
    };

    enum Colors
    {
        Black = 0,
        Blue = 31,
        Green = 2016,
        Yellow = 65504,
        Red = 63488,
        White = 65535
    };

    enum Alignments
    {
        Top = 0,
        Bottom = 3,
        Left = 0,
        Right = 2,
        Center = 0
    };

    enum Backgrounds
    {
        Crop_Image = 0,
        Solid_Color = 1,
        Image = 2,
        None = 3
    };

    // -- Methods

    void Begin(uint32_t Baud_Rate = 921600, uint8_t RX_Pin = 16, uint8_t TX_Pin = 17);

    // -- Loop process

    void Loop();

    // -- Default call back functions
    static void Default_Callback_Function_String_Data(const char *, uint8_t);
    static void Default_Callback_Function_Numeric_Data(uint32_t);
    static void Default_Callback_Function_Event(uint8_t);

    // -- Drawing

    void Draw_Pixel(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Color);
    void Draw_Rectangle(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Width, uint16_t Height, uint16_t Color, bool Hollow = false);
    void Draw_Circle(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Radius, uint16_t Color, bool Hollow = false);
    void Draw_Fill(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Width, uint16_t Height, uint16_t Color);
    void Draw_Line(uint16_t X_Start, uint16_t Y_Start, uint16_t X_End, uint16_t Y_End, uint16_t Color);
    void Draw_Picture(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Picture_ID);
    void Draw_Crop_Picture(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Width, uint16_t Height, uint16_t Picture_ID);
    void Draw_Advanced_Crop_Picture(uint16_t X_Destination, uint16_t Y_Destination, uint16_t Width, uint16_t Height, uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Picture_ID);
    void Draw_Text(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Width, uint16_t Height, uint16_t Font_ID, uint16_t Text_Color, uint16_t Background, uint16_t Horizontal_Alignment, uint16_t Vertical_Alignment, uint16_t Background_Type, String const &Text);
    void Draw_Text(uint16_t X_Coordinate, uint16_t Y_Coordinate, uint16_t Width, uint16_t Height, uint16_t Font_ID, uint16_t Text_Color, uint16_t Background, uint16_t Horizontal_Alignment, uint16_t Vertical_Alignment, uint16_t Background_Type, const char *Text);

    // -- Set object attributes methods
    void Set_Font(const __FlashStringHelper *Object_Name, uint8_t Font_ID);
    void Set_Background_Color(const __FlashStringHelper *Object_Name, uint16_t Color, int8_t Type = -1);
    void Set_Font_Color(const __FlashStringHelper *Object_Name, uint16_t Color, int8_t Type = -1);
    void Set_Horizontal_Alignment(const __FlashStringHelper *Object_Name, uint8_t Alignment);
    void Set_Vertical_Alignment(const __FlashStringHelper *Object_Name, uint8_t Alignment);

    void Set_Mask(const __FlashStringHelper *Object_Name, bool Masked);
    void Set_Wordwrap(const __FlashStringHelper *Object_Name, bool Wordwrap);

    void Set_Text(const __FlashStringHelper *Object_Name, char Value);
    void Set_Text(const __FlashStringHelper *Object_Name, const __FlashStringHelper *Value);
    void Set_Text(String const &Object_Name, String const &Value);
    void Set_Text(const char *Object_Name, const char *Value);
    void Set_Text(const __FlashStringHelper *Object_Name, const char *Value);

    void Add_Text(const __FlashStringHelper *Component_Name, const char *Data);
    void Add_Text(const __FlashStringHelper *Object_Name, char Data);

    void Delete_Text(const __FlashStringHelper *Component_Name, uint8_t Quantity);

    void Set_Maximum_Value(const __FlashStringHelper *Object_Name, uint16_t Value);

    void Set_Minimum_Value(const __FlashStringHelper *Object_Name, uint16_t Value);

    void Set_Value(const __FlashStringHelper *Object_Name, uint32_t Value);
    void Set_Value(String const &Object_Name, uint32_t Value);
    void Set_Value(const char *Object_Name, uint32_t Value);

    void Set_Global_Variable(const __FlashStringHelper *Object_Name, uint32_t Value);

    void Set_Channel_Color(const __FlashStringHelper *Object_Name, uint8_t Channel_ID, uint16_t Color);
    void Set_Grid_Color(const __FlashStringHelper *Object_Name, uint16_t Color);
    void Set_Grid_Width(const __FlashStringHelper *Object_Name, uint16_t Width);
    void Set_Grid_Height(const __FlashStringHelper *Object_Name, uint16_t Height);
    void Set_Data_Scaling(const __FlashStringHelper *Object_Name, uint16_t Scale);

    void Set_Picture(const __FlashStringHelper *Object_Name, uint8_t Picture_ID);
    void Set_Picture(String const &Object_Name, uint8_t Picture_ID);

    void Set_Time(const __FlashStringHelper *Object_Name, uint16_t Time);
    void Set_Trigger(const __FlashStringHelper *Object_Name, bool Enable);

    void Set_Reparse_Mode(uint8_t Mode);

    // Set System Global Variable
    bool Set_Current_Page(uint8_t Page_ID, bool Feedback = true);
    bool Set_Current_Page(const __FlashStringHelper *Page_Name);
    uint8_t Get_Current_Page(bool Refresh_Now = true);
    void Set_Brightness(uint16_t Brightness, bool Save = false);
    void Set_Display_Baud_Rate(uint32_t Baud_Rate, bool Save);

    void Set_Horizontal_Font_Spacing(uint16_t Spacing);
    void Set_Vertical_Font_Spacing(uint16_t Spacing);

    void Set_Draw_Color(uint16_t Color);
    void Set_Drawing(bool Enable);

    void Set_Random_Generator(int32_t Minimum, int32_t Maximum);

    void Set_Standby_Serial_Timer(uint16_t Value);
    void Set_Standby_Touch_Timer(uint16_t Value);

    void Set_Serial_Wake_Up(bool Value);
    void Set_Touch_Wake_Up(bool Value);

    void Set_Wake_Up_Page(uint8_t Value);

    void Sleep();
    void Wake_Up();

    void Set_Debugging(uint8_t Level);

    void Start_Sending_Realtime_Coordinate();
    void Stop_Sending_Realtime_Coordinate();

    // -- Raw

    void Write(int Data);
    void Send_Raw(const __FlashStringHelper *Data);
    void Send_Raw(String const &Data);
    void Send_Raw(const char *Data);

    void Purge();

    // -- Methods command

    void Clear(uint16_t Color);

    void Refresh(uint16_t Component_ID);
    void Refresh(const __FlashStringHelper *Object_Name);
    void Refresh(const char *Object_Name);

    void Delay(uint16_t Delay_Time);

    void Click(uint16_t Component_ID, uint8_t Event_Type);
    void Click(const __FlashStringHelper *Object_Name, uint8_t Event_Type);
    void Click(const char *Object_Name, uint8_t Event_Type);

    void Set_Waveform_Refresh(bool Enable);

    void Add_Value_Waveform(uint8_t Component_ID, uint8_t Channel, uint8_t *Data, uint32_t Quantity = 0);
    void Clear_Waveform(uint16_t Component_ID, uint8_t Channel);

    void Get(const __FlashStringHelper *Attribute);

    void Calibrate();

    void Show(const __FlashStringHelper *Object_Name);
    void Show(String const &Object_Name);
    void Show(const char *Object_Name);

    void Hide(const __FlashStringHelper *Object_Name);
    void Hide(String const &Object_Name);
    void Hide(const char *Object_Name);

    void Set_Touch_Event(const __FlashStringHelper *Object_Name, bool Enable);
    void Set_Touch_Event(uint8_t Object_ID, bool Enable);

    void Set_Execution(bool Enable);

    void Reboot();

    uint8_t Update(File Update_File);

    // -- Setter methods
    void Set_Address(uint16_t Address);
    void Set_Baud_Rate(uint32_t Baud_Rate);

    void Set_Callback_Function_String_Data(void (*Function_Pointer)(const char *, uint8_t));
    void Set_Callback_Function_Numeric_Data(void (*Function_Pointer)(uint32_t));
    void Set_Callback_Function_Event(void (*Function_Pointer)(uint8_t));

    // -- Getter methods
    uint16_t Get_Address();

protected:
    // -- Methods

    inline void Instruction_End()
    {
        Nextion_Serial.write(0xFF);
        Nextion_Serial.write(0xFF);
        Nextion_Serial.write(0xFF);
        xSemaphoreGive(Serial_Semaphore);
    }

    inline void Argument_Separator()
    {
        Nextion_Serial.write(',');
    }

    inline bool Ending(char *String)
    {
        if (String[0] == 0xFF && String[1] == 0xFF && String[2] == 0xFF)
        {
            return true;
        }
        return false;
    }

    inline bool Wait_For_Event(uint8_t Expected_Event, uint32_t Time_Out = 500)
    {
        Time_Out = Time_Out + millis();
        while (this->Expected_Event != 0xFF && this->Expected_Event != Expected_Event)
        {
            if (Time_Out < millis())
            {
                DUMP("return 1");
                return false;
            }
            vTaskDelay(pdMS_TO_TICKS(40));
        }

        this->Expected_Event = Expected_Event;
        State = false;

        while (State == false)
        {
            if (this->Expected_Event != Expected_Event || Time_Out < millis())
            {
                DUMP("timeout");
                State = false;
                this->Expected_Event = 0xFF;
                return false;
            }
            vTaskDelay(pdMS_TO_TICKS(100));
        }

        State = false;
        this->Expected_Event = 0xFF;

        return true;
    }

    // -- Attributes

    volatile uint8_t Expected_Event = 0xFF;
    volatile bool State = false;

    static Nextion_Class *Instance_Pointer;

    uint8_t Page_History[5];

    uint32_t Baud_Rate;
    HardwareSerial Nextion_Serial;
    SemaphoreHandle_t Serial_Semaphore;
    uint16_t Address;

    void (*Callback_Function_String_Data)(const char *, uint8_t);
    void (*Callback_Function_Numeric_Data)(uint32_t);
    void (*Callback_Function_Event)(uint8_t);

    uint16_t Cursor_X, Cursor_Y;
    uint16_t X_Press, X_Release, Y_Press, Y_Release;

    File Temporary_File;

    char Temporary_String[150];
    uint8_t Return_Code;
};

#endif