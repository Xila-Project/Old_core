#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include "Arduino.h"
#include "HardwareSerial.h"
#include "FS.h"
#include "SD_MMC.h"
#include "Configuration.hpp"

#define DISPLAY_POINTER Nextion_Display_Class::Display_Pointer

class Nextion_Display_Class
{
protected:
    HardwareSerial Nextion_Serial;

    xTaskHandle Nextion_Serial_Handle;

    SemaphoreHandle_t Serial_Semaphore;

    void (*Callback_Function_String_Data)(const char *, uint8_t);
    void (*Callback_Function_Numeric_Data)(uint32_t &);
    void (*Callback_Function_Event)(uint8_t &);

    uint16_t Cursor_X, Cursor_Y;

    File Temporary_File;

    uint16_t Adress;

    inline void Instruction_End();
    inline void Argument_Separator();

    void Main_Routine();

public:
    enum Error
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
        Invalid_Variable_Name_Or_Attribue = 0x1A,
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

    enum Information
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

    enum Color
    {
        Black = 0,
        Blue = 31,
        Green = 2016,
        Yellow = 65504,
        Red = 63488,
        White = 65535
    };

    enum Alignement
    {
        Top = 0,
        Bottom = 3,
        Left = 0,
        Right = 2,
        Center = 0
    };

    enum Background
    {
        Crop_Image = 0,
        Solid_Color = 1,
        Image = 2,
        None = 3
    };

    uint8_t Page_History[5];

    static Nextion_Display_Class *Display_Pointer;

    //Class setup
    Nextion_Display_Class();
    ~Nextion_Display_Class();

    void Begin(uint32_t Baud_Rate = 912600, uint8_t RX_Pin = 16, uint8_t TX_Pin = 17);

    void Set_Callback_Function_String_Data(void (*Function_Pointer)(const char *, uint8_t));
    void Set_Callback_Function_Numeric_Data(void (*Function_Pointer)(uint32_t &));
    void Set_Callback_Function_Event(void (*Function_Pointer)(uint8_t &));

    // Basic Geometrical Drawing
    void Draw_Pixel(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Color);
    void Draw_Rectangle(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint16_t const &Color, bool const &Hollow = false);
    void Draw_Circle(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Radius, uint16_t const &, uint16_t const &Color, bool const &Hollow = false);
    void Draw_Fill(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint16_t const &Color);
    void Draw_Line(uint16_t const &X_Start, uint16_t const &Y_Start, uint16_t const &X_End, uint16_t const &Y_End, uint16_t const &Color);

    // Advanced Drawing
    void Draw_Picture(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Picture_ID);
    void Draw_Crop_Picture(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint16_t const &Picture_ID);
    void Draw_Advanced_Crop_Picture(uint16_t const &X_Destination, uint16_t const &Y_Destination, uint16_t const &Width, uint16_t const &Height, uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Picture_ID);
    void Draw_Text(uint16_t const &X_Coordinarte, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint16_t const &Font_ID, uint16_t const &Text_Color, uint16_t Backgroud, uint16_t const &Horizontal_Alignment, uint16_t const &Vertical_Alignment, uint16_t const &Background_Type, String const &Text);
    void Draw_Text(uint16_t const &X_Coordinarte, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint16_t const &Font_ID, uint16_t const &Text_Color, uint16_t Backgroud, uint16_t const &Horizontal_Alignment, uint16_t const &Vertical_Alignment, uint16_t const &Background_Type, const char *Text);

    //void Print(String const& Text_To_Print);
    //void Print(const __FlashStringHelper* Text_To_Print);

    // Set Object Attributes
    void Set_Font(const __FlashStringHelper *Object_Name, uint8_t const &Font_ID);
    void Set_Background_Color(const __FlashStringHelper *Object_Name, uint16_t const &Color, int8_t Type);
    void Set_Font_Color(const __FlashStringHelper *Object_Name, uint16_t const &Color, int8_t Type);
    void Set_Horizontal_Alignment(const __FlashStringHelper *Object_Name, uint8_t const &Horizontal_Alignment);
    void Set_Vertical_Alignment(const __FlashStringHelper *Object_Name, uint8_t const &Set_Vertical_Alignment);
    void Set_Input_Type(const __FlashStringHelper *Object_Name, uint8_t const &Input_Type);
    void Set_Wordwrap(const __FlashStringHelper *Object_Name, bool const &Wordwrap);
    void Set_Text(const __FlashStringHelper *Object_Name, const __FlashStringHelper *Value);
    void Set_Text(const __FlashStringHelper *Object_Name, String const &Value, uint8_t const &Insert);
    void Set_Text(String const &Object_Name, String const &Value);
    void Set_Text(const __FlashStringHelper *Object_Name, const char *Value);
    void Set_Value(const __FlashStringHelper *Object_Name, uint32_t const &Value);
    void Set_Value(String const& Object_Name, uint32_t const& Value);
    void Set_Value(const char* Object_Name, uint32_t const& Value);
    void Set_Channel(const __FlashStringHelper *Object_Name, uint8_t const &Channel);
    void Set_Grid_Width(const __FlashStringHelper *Object_Name, uint16_t const &Width);
    void Set_Grid_Heigh(const __FlashStringHelper *Object_Name, uint16_t const &Heigh);
    void Set_Data_Scalling(const __FlashStringHelper *Object_Name, uint16_t const &Scale);
    void Set_Picture(const __FlashStringHelper *Object_Name, uint8_t const &Picture_ID);
    void Set_Picture(String const &Object_Name, uint8_t const &Picture_ID);
    void Set_Time(const __FlashStringHelper *Object_Name, uint16_t const &Time);
    void Set_Trigger(const __FlashStringHelper *Object_Name, bool const &Enable);

    // Set System Global Variable
    void Set_Current_Page(uint8_t const &Page_ID);
    void Set_Current_Page(const __FlashStringHelper *Page_Name);
    uint8_t &Get_Current_Page();

    void Set_Brightness(uint16_t const &Brightness, bool const &Save = false);
    uint8_t Get_Backlight();

    void Set_Baud_Rate(uint32_t const &Baudrate, bool const &Save);
    void Set_Font_Spacing(uint16_t const &X_Spacing, uint16_t const &Y_Spacing);

    void Set_Draw_Color(uint16_t const &Color);
    void Set_Drawing(bool const &Enable);

    void Set_Random_Generator(uint32_t const &Minimum, uint32_t const &Maximum);

    void Set_Standby_Timer(uint16_t const &Timer_Value, uint8_t Type_Timer);
    void Set_Autowake(bool const &State);

    void Set_Adress(uint16_t Adress);
    uint16_t Get_Adress();

    uint16_t Get_Free_Buffer();

    void Sleep();
    void Wake_Up();

    void Set_Debugging(uint8_t Level);

    void Set_Globbal_Variable(uint8_t Selected_Variable, uint32_t Value);
    void Set_Protocol(uint8_t const &Protocol_Mode);
    void Set_Wake_Up_Page(uint8_t Page_ID);

    void Start_Sending_Realtime_Coordinate();
    void Stop_Sending_Realtime_Coordinate();

    void Send_Custom_Instruction(const __FlashStringHelper *Instruction);
    void Send_Custom_Instruction(String const &Intruction);

    //Command
    void Clear(uint16_t const &Color);
    void Refresh(uint16_t const &Component_ID);
    void Delay(uint16_t Delay_Time);
    void Click(uint16_t const &Component_ID, uint8_t const &Event_Type);
    void Start_Waveform_Refresh();
    void Stop_Waveform_Refresh();
    void Add_Value_Waveform(uint16_t const &Component_ID, uint8_t const &Channel, uint32_t *Data, uint32_t const &Quantity = 0);
    void Clear_Waveform(uint16_t const &Component_ID, uint8_t const &Channel);
    void Get(const __FlashStringHelper *Object_Name);
    void Calibrate();
    void Show(const __FlashStringHelper *Object_Name);
    void Show(String const &Object_Name);
    void Show(const char *Object_Name);
    void Hide(const __FlashStringHelper *Object_Name);
    void Hide(String const &Object_Name);
    void Hide(const char *Object_Name);
    void Disable_Touch_Event(const __FlashStringHelper *Object_Name);
    void Enable_Touch_Event(const __FlashStringHelper *Object_Name);
    void Stop_Execution();
    void Resume_Execution();
    void Refresh_Current_Page();

    void Reboot();
    uint8_t Update(String const &File_Path);

    friend void Nextion_Serial_Receive(void *pvParameters);
};

void Nextion_Serial_Receive(void *pvParameters);

#endif