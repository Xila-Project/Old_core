#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include "Arduino.h"
#include "HardwareSerial.h"
#include "FS.h"
#include "SD_MMC.h"

#define DISPLAY_POINTER Nextion_Display_Class::Display_Pointer

#define NEXTION_ERROR_INVALID_INSTRUCTION 0x00  //4 byte
#define NEXTION_ERROR_INVALID_COMPONENT_ID 0x02 //4 byte
#define NEXTION_ERROR_INVALID_PAGE_ID 0x03
#define NEXTION_ERROR_INVALID_PICTURE_ID 0x04
#define NEXTION_ERROR_INVALID_FONT_ID 0x05
#define NEXTION_ERROR_INVALID_FILE_OPERATION 0x06
#define NEXTION_ERROR_INVALID_CRC 0x09
#define NEXTION_ERROR_INVALID_BAUD_RATE_SETTING 0x11
#define NEXTION_ERROR_INVALID_WAVEFORM_ID_OR_CHANNEL 0x12
#define NEXTION_ERROR_INVALID_VARIABLE_NAME_OR_ATTRIBUTE 0x1A
#define NEXTION_ERROR_INVALID_VARIABLE_OPERATION 0x1B
#define NEXTION_ERROR_FAIL_TO_ASSIGN 0x1C
#define NEXTION_ERROR_FAIL_EEPROM_OPERATION 0x1D
#define NEXTION_ERROR_INVALID_QUANTITY_OF_PARAMETERS 0x1E
#define NEXTION_ERROR_IO_OPERATION_FAILED 0x1F
#define NEXTION_ERROR_INVALID_ESCAPE_CHARACTER 0x20
#define NEXTION_ERROR_TOO_LONG_VARIABLE_NAME 0x23
#define NEXTION_ERROR_SERIAL_BUFFER_OVERFLOW 0x24

#define NEXTION_INFORMATION_STARTUP 0x07 //custom
#define NEXTION_INFORMATION_INTRUCTION_SUCCESSFUL 0x01
#define NEXTION_INFORMATION_TOUCH_EVENT 0x65
#define NEXTION_INFORMATION_CURRENT_PAGE_NUMBER 0x66
#define NEXTION_INFORMATION_TOUCH_COORDINATE_AWAKE 0x67
#define NEXTION_INFORMATION_TOUCH_COOORDINATE_SLEEP 0x68
#define NEXTION_INFORMATION_STRING_DATA_ENCLOSED 0x70
#define NEXTION_INFORMATION_NUMERIC_DATA_ENCLOSED 0x71
#define NEXTION_INFORMATION_AUTO_ENTERED_SLEEP_MODE 0x86
#define NEXTION_INFORMATION_AUTO_WAKE_FROM_SLEEP_MODE 0x87
#define NEXTION_INFORMATION_READY 0x88
#define NEXTION_INFORMATION_START_UPGRADE_FROM_SD 0x89
#define NEXTION_INFORMATION_TRANSPARENT_DATA_FINISHED 0xFD
#define NEXTION_INFORMATION_TRANSPARENT_DATA_READY 0xFE

class Nextion_Display_Class
{
protected:
    HardwareSerial Nextion_Serial;

    xTaskHandle Nextion_Serial_Handle;

    void (*Callback_Function_String_Data)(String);
    void (*Callback_Function_Numeric_Data)(uint32_t);
    void (*Callback_Function_Event)(uint16_t);

    static uint8_t Number_Instance;

    uint16_t Cursor_X, Cursor_Y;

    File Temporary_File;

    uint16_t Adress;

    inline void Instruction_End();
    inline void Argument_Separator();

public:

    enum Color
    {
        Black = 0,
        Blue = 31,
        Green = 2016,
        Yellow = 65504,
        Red = 63488,
        White = 65535
    };

    uint8_t Page_History[5];

    static Nextion_Display_Class *Display_Pointer;

    //Class setup
    Nextion_Display_Class(uint32_t const &Baud_Rate = 921600, uint8_t const &RX_Pin = 16, uint8_t const &TX_Pin = 17);
    ~Nextion_Display_Class();

    void Set_Callback_Function_String_Data(void (*Function_Pointer)(String &));
    void Set_Callback_Function_Numeric_Data(void(*Function_Pointer(uint32_t &)));
    void Set_Callback_Function_Event(void(*Function_Pointer(uint16_t &)));

    // Basic Geometrical Drawing
    void Draw_Pixel(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Color);
    void Draw_Rectangle(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint16_t const &Color, bool const &Hollow);
    void Draw_Circle(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Radius, uint16_t const &, uint16_t const &Color, bool const &Hollow);
    void Draw_Fill(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint16_t const &Color);
    void Draw_Line(uint16_t const &X_Start, uint16_t const &Y_Start, uint16_t const &X_End, uint16_t const &Y_End, uint16_t const &Color);

    // Advanced Drawing
    void Draw_Picture(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Picture_ID);
    void Draw_Crop_Picture(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint16_t const &Picture_ID);
    void Draw_Advanced_Crop_Picture(uint16_t const &X_Destination, uint16_t const &Y_Destination, uint16_t const &Width, uint16_t const &Height, uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Picture_ID);
    void Draw_Text(uint16_t const &X_Coordinarte, uint16_t const &Y_Coordinate, uint16_t const &Width, uint16_t const &Height, uint8_t const &Font_ID, uint8_t const &Text_Color, uint16_t Backgroud, uint8_t const &Horizontal_Alignment, uint8_t const &Vertical_Alignment, uint16_t const &Background_Type, String const &Text);

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
    void Set_Value(const __FlashStringHelper *Object_Name, uint32_t const &Value);
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

    void Set_Backlight(uint8_t const &Brightness, bool const &Save);
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
    void Add_Value_Waveform(uint16_t const &Component_ID, uint8_t const &Channel, uint32_t const &Value, uint32_t const &Quantity, uint8_t *Array);
    void Clear_Waveform(uint16_t const &Component_ID, uint8_t const &Channel);
    void Get(const __FlashStringHelper *Object_Name);
    void Calibrate();
    void Show(const __FlashStringHelper *Object_Name);
    void Hide(const __FlashStringHelper *Object_Name);
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