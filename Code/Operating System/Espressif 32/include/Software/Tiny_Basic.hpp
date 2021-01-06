#ifndef TINYBASIC_H_INCLUDED
#define TINYBASIC_H_INCLUDED

#include "Xila.hpp"

#include <SPI.h>
#include <SD_MMC.h>
#include <FS.h>

#include <EEPROM.h> /* NOTE: case sensitive */

////////////////////////////////////////////////////////////////////////////////
// TinyBasic for ESP32
////////////////////////////////////////////////////////////////////////////////
//
// Author: hoopsurfer, based on Tiny Basic Plus from Mike Field, Scott Lawrence and Brian O'Dell
//
// TODO: many changes to add language to support ESP32 hardware and remove any extranious code
// TODO: add support for SPI-based SD card, color TFT display and Touchscreen
//
// Target IDE:       Arduino
// Target hardware:  Adafruit ESP32 Feather
//                   https://learn.adafruit.com/adafruit-huzzah32-esp32-feather/pinouts
//                   Adafruit 2.4" TFT Touchscreen Featherwing
//                   https://learn.adafruit.com/adafruit-2-4-tft-touch-screen-featherwing/pinouts
//
#define TBE_VERSION "0.15"
//
// 0.15 Initial ESP32 Support - tictactoe works
//      Changes to support ESP32 programming
//      implemented peek/poke within program space (code destructive)
//      implemented SD file access with root path
//
// 0.16 Enabled TFT display
//

// custom const
#define E2END 0x1FF // last eeprom adress  = 512 (max default eeprom size on esp32) - 1 (adresses start at 0)

#define ANALOG_WRITE_CHANEL 7

#define DISPLAY_X_RESOLUTION 480
#define DISPLAY_Y_RESOLUTION 272

///////////////////////////////////////////////////////////////////////////////


// Adafruit ESP32 Feather PINS used for TFT Featherwing components
#define SCK_PIN 5   // SPI
#define MISO_PIN 18 // SPI
#define MOSI_PIN 19 // SPI
#define SD_CS 14    // SD Card Chip Select
#define RT_CS 32    // Touchscreen Chip Select
#define TFT_CS 15   // TFT Display Chip Select
#define TFT_DC 33   // TFT Display Data/Command Select

////////////////////////////////////////////////////////////////////////////////
// Feature option configuration - comment out to minimize dependencies

// Enable LOAD, SAVE, FILES commands through the Arduino SD Library
#define ENABLE_FILEIO 1
#define AUTORUN_FILE "/SOFTWARE/TINYBASI/AUTORUN.XEF"

// Enable TFT color display and touchscreen
#define ENABLE_TFT 1
//#undef ENABLE_TFT

// Enable EEPROM-based program storage with autorun to store a program during powerdown
//#define ENABLE_EEPROM 1

// Enable TONE, NOTONE commands to support audio
//#define ENABLE_TONES 1
#define kPiezoPin 25

// Enable WiFi support to read/write information from the network.
//#define ENABLE_WIFI 1

// Set defailt serial speed for support serial input/output
#define CONSOLE_BAUD 115200

/////////////////////////////////////////////////////////////////////////////////
// enable incremental hardware capabilities, not required for simple programs

// Set max space to allow for BASIC programs in memory less hardware related buffers
#define PROG_MAX 32768 - 1

#ifdef ENABLE_FILEIO
#define FILEIO_RAM (1030) /* buffer */
#else
#define FILEIO_RAM (0)
#endif

#include <SPI.h>
#include <SD.h>
#include <FS.h>

#include <EEPROM.h> /* NOTE: case sensitive */
int eepos = 0;

#ifdef ENABLE_WIFI
#include <WiFi.h>
#endif

#ifdef ENABLE_TONES
#define TONE_RAM (40) /* I/O buffer */
#else
#define TONE_RAM (0)
#endif

#define PROG_RAM (PROG_MAX - FILEIO_RAM - TONE_RAM)

// ASCII Characters
#define CR '\r'
#define NL '\n'
#define LF 0x0a
#define TAB '\t'
#define BELL '\b'
#define SPACE ' '
#define SQUOTE '\''
#define DQUOTE '\"'
#define CTRLC 0x03
#define CTRLH 0x08
#define CTRLS 0x13
#define CTRLX 0x18

typedef short unsigned LINENUM;
#define ECHO_CHARS 1

#define FUNC_PEEK 0
#define FUNC_ABS 1
#define FUNC_AREAD 2
#define FUNC_DREAD 3
#define FUNC_RND 4
#define FUNC_UNKNOWN 5

#define RELOP_GE 0
#define RELOP_NE 1
#define RELOP_GT 2
#define RELOP_EQ 3
#define RELOP_LE 4
#define RELOP_LT 5
#define RELOP_NE_BANG 6
#define RELOP_UNKNOWN 7

#define HIGHLOW_HIGH 1
#define HIGHLOW_UNKNOWN 4

#define STACK_SIZE (sizeof(struct stack_for_frame) * 5)
#define VAR_SIZE sizeof(short int) // Size of variables in bytes

#define STACK_GOSUB_FLAG 'G'
#define STACK_FOR_FLAG 'F'

class Tiny_Basic_Class : public Software_Class
{
protected:
    static Tiny_Basic_Class* Instance_Pointer;

    ////////////////////

    boolean inhibitOutput = false;
    boolean runAfterLoad = false;
    boolean triggerRun = false;

    // these will select, at runtime, where IO happens through for load/save
    enum
    {
        kStreamSerial = 0,
        kStreamEEProm,
        kStreamFile,
        kStreamXila,
    };
    unsigned char inStream = kStreamXila;
    unsigned char outStream = kStreamXila;



    ////////////////////////////////////////////////////////////////////////////////

    unsigned char program[PROG_RAM];
    unsigned char *txtpos, *list_line, *tmptxtpos;
    unsigned char expression_error;
    unsigned char *tempsp;

    /***********************************************************/
    // Keyword table and constants - the last character has 0x80 added to it

    // by moving the command list to an enum, we can easily remove sections
    // above and below simultaneously to selectively obliterate functionality.
    enum
    {
        KW_LIST = 0,
        KW_LOAD,
        KW_NEW,
        KW_RUN,
        KW_SAVE,
        KW_NEXT,
        KW_LET,
        KW_IF,
        KW_GOTO,
        KW_GOSUB,
        KW_RETURN,
        KW_REM,
        KW_FOR,
        KW_INPUT,
        KW_PRINT,
        KW_POKE,
        KW_STOP,
        KW_BYE,
        KW_FILES,
        KW_DELETE,
        KW_MEM,
        KW_QMARK,
        KW_QUOTE,
        KW_AWRITE,
        KW_DWRITE,
        KW_DELAY,
        KW_END,
        KW_RSEED,
        KW_CHAIN,
        KW_CLEAR,
        KW_SERCOM,
        KW_NLIST,
        KW_DRAWPIX,
        KW_DRAWLINE,
        KW_DRAWROW,
        KW_DRAWCOL,
        KW_DRAWRECT,
        KW_DRAWCIRC,
        KW_DRAWCHAR,
        KW_GETPIX,
        KW_TONEW,
        KW_TONE,
        KW_NOTONE,
        KW_ECHAIN,
        KW_ELIST,
        KW_ELOAD,
        KW_EFORMAT,
        KW_ESAVE,
        KW_WIFI,
        KW_DEFAULT /* always the final one*/
    };

    struct stack_for_frame
    {
        char frame_type;
        char for_var;
        short int terminal;
        short int step;
        unsigned char *current_line;
        unsigned char *txtpos;
    };

    struct stack_gosub_frame
    {
        char frame_type;
        unsigned char *current_line;
        unsigned char *txtpos;
    };

    const unsigned char func_tab[] = {
        'P', 'E', 'E', 'K' + 0x80,
        'A', 'B', 'S' + 0x80,
        'A', 'R', 'E', 'A', 'D' + 0x80,
        'D', 'R', 'E', 'A', 'D' + 0x80,
        'R', 'N', 'D' + 0x80,
        0};

    File fp;
    void cmd_Files();
    unsigned char *filenameWord();
    boolean sd_is_initialized = false;

    const unsigned char keywords[90] = {
        'L', 'I', 'S', 'T' + 0x80,
        'L', 'O', 'A', 'D' + 0x80,
        'N', 'E', 'W' + 0x80,
        'R', 'U', 'N' + 0x80,
        'S', 'A', 'V', 'E' + 0x80,
        'N', 'E', 'X', 'T' + 0x80,
        'L', 'E', 'T' + 0x80,
        'I', 'F' + 0x80,
        'G', 'O', 'T', 'O' + 0x80,
        'G', 'O', 'S', 'U', 'B' + 0x80,
        'R', 'E', 'T', 'U', 'R', 'N' + 0x80,
        'R', 'E', 'M' + 0x80,
        'F', 'O', 'R' + 0x80,
        'I', 'N', 'P', 'U', 'T' + 0x80,
        'P', 'R', 'I', 'N', 'T' + 0x80,
        'P', 'O', 'K', 'E' + 0x80,
        'S', 'T', 'O', 'P' + 0x80,
        'B', 'Y', 'E' + 0x80,
        'F', 'I', 'L', 'E', 'S' + 0x80,
        'D', 'E', 'L', 'E', 'T', 'E' + 0x80,
        'M', 'E', 'M' + 0x80,
        '?' + 0x80,
        '\'' + 0x80,
        'A', 'W', 'R', 'I', 'T', 'E' + 0x80,
        'D', 'W', 'R', 'I', 'T', 'E' + 0x80,
        'D', 'E', 'L', 'A', 'Y' + 0x80,
        'E', 'N', 'D' + 0x80,
        'R', 'S', 'E', 'E', 'D' + 0x80,
        'C', 'H', 'A', 'I', 'N' + 0x80,
        'C', 'L', 'E', 'A', 'R' + 0x80,
        'S', 'E', 'R', 'C', 'O', 'M' + 0x80,
        'N', 'L', 'I', 'S', 'T' + 0x80,
        'D', 'R', 'A', 'W', 'P', 'I', 'X' + 0x80,
        'D', 'R', 'A', 'W', 'L', 'I', 'N', 'E' + 0x80,
        'D', 'R', 'A', 'W', 'R', 'O', 'W' + 0x80,
        'D', 'R', 'A', 'W', 'C', 'O', 'L' + 0x80,
        'D', 'R', 'A', 'W', 'R', 'E', 'C', 'T' + 0x80,
        'D', 'R', 'A', 'W', 'C', 'I', 'R', 'C' + 0x80,
        'D', 'R', 'A', 'W', 'C', 'H', 'A', 'R' + 0x80,
        'G', 'E', 'T', 'P', 'I', 'X' + 0x80,
        'T', 'O', 'N', 'E', 'W' + 0x80,
        'T', 'O', 'N', 'E' + 0x80,
        'N', 'O', 'T', 'O', 'N', 'E' + 0x80,
        'E', 'C', 'H', 'A', 'I', 'N' + 0x80,
        'E', 'L', 'I', 'S', 'T' + 0x80,
        'E', 'L', 'O', 'A', 'D' + 0x80,
        'E', 'F', 'O', 'R', 'M', 'A', 'T' + 0x80,
        'E', 'S', 'A', 'V', 'E' + 0x80,
        'W', 'I', 'F', 'I' + 0x80,
        0};

    const unsigned char to_tab[3] PROGMEM = {
        'T', 'O' + 0x80,
        0};

    const unsigned char step_tab[5] PROGMEM = {
        'S', 'T', 'E', 'P' + 0x80,
        0};

    const unsigned char relop_tab[12] PROGMEM = {
        '>', '=' + 0x80,
        '<', '>' + 0x80,
        '>' + 0x80,
        '=' + 0x80,
        '<', '=' + 0x80,
        '<' + 0x80,
        '!', '=' + 0x80,
        0};

    const unsigned char highlow_tab[12] PROGMEM = {
        'H', 'I', 'G', 'H' + 0x80,
        'H', 'I' + 0x80,
        'L', 'O', 'W' + 0x80,
        'L', 'O' + 0x80,
        0};

    unsigned char *stack_limit;
    unsigned char *program_start;
    unsigned char *program_end;
    unsigned char *variables_begin;
    unsigned char *current_line;
    unsigned char *sp;

    unsigned char table_index;

    LINENUM linenum;

    const unsigned char okmsg[3] = "OK";
    const unsigned char whatmsg[7] = "What? ";
    const unsigned char howmsg[5] = "How?";
    const unsigned char sorrymsg[7] = "Sorry!";
    const unsigned char initmsg[21] = "TinyBasic ESP32 " TBE_VERSION;
    const unsigned char lameName[5] = "Xila";
    const unsigned char memorymsg[13] = " bytes free.";

    const unsigned char eeprommsg[21] = " EEProm bytes total.";
    const unsigned char eepromamsg[25] = " EEProm bytes available.";

    const unsigned char breakmsg[7] = "break!";
    const unsigned char unimplimentedmsg[14] = "Unimplemented";
    const unsigned char backspacemsg[4] = "\b \b";
    const unsigned char indentmsg[5] = "    ";
    const unsigned char sderrormsg[15] = "SD card error.";
    const unsigned char sdfilemsg[15] = "SD file error.";
    const unsigned char dirextmsg[6] = "(dir)";
    const unsigned char slashmsg[2] = "/";
    const unsigned char spacemsg[2] = " ";

    

    void Set_Variable(const void *, uint8_t, uint8_t, uint8_t = 0);

    // custom function

    void Read_Command();

    char Temporary_Input[193];

    void Clear(); // uniplemented yet

    uint8_t Current_Line;
    uint8_t Current_Column;
    
    void Write(uint8_t Char);
    uint8_t Read();
    uint8_t Available();

    void Analog_Write(uint8_t, int16_t); // uniplemented yet
    
    void Draw_Rectangle(uint16_t const& X_Coordinate, uint16_t const& Y_Coordinate, uint16_t const& Heigh, uint16_t const& Widht, uint16_t const& Color, uint16_t const& Fill_Color); //interface between xila display lib and tinybasic
    void Draw_Line(uint16_t const& X_Start, uint16_t const &Y_Start, uint16_t const &X_End, uint16_t const &Y_End, uint16_t const &Color);
    void Draw_Row(uint16_t const& X_Start, uint16_t const& Y_Coordinate, uint16_t const& X_End, uint16_t const& Color);
    void Draw_Column(uint16_t const& X_Coordinate, uint16_t const& Y_Start, uint16_t const& Y_End, uint16_t const& Color);
    void Draw_Pixel(uint16_t const& X_Coordinate, uint16_t const& Y_Coordinate, uint16_t const& Color);
    void Draw_Circle(uint16_t const& X_Coordinate, uint16_t const& Y_Coordinate, uint16_t const Radius, uint16_t const& Color, uint16_t const& Fill_Color);
    void Draw_Char(uint16_t const& X_Coordinate, uint16_t const& Y_Coordinate, char const* Char);
    
    // base function

    int inchar();
    void outchar(unsigned char c);
    void line_terminator();
    short int expression();
    unsigned char breakcheck();

    void ignore_blanks();
    void scantable(const unsigned char *);
    void pushb(unsigned char);
    unsigned char popb();
    void printnum(int);
    void printUnum(unsigned int);
    unsigned short testnum();
    unsigned char print_quoted_string();
    void printmsgNoNL(const unsigned char *);
    void printmsg(const unsigned char *);
    void getln(char prompt);
    unsigned char *findline();
    void toUppercaseBuffer();
    void printline();
    short int expr4();
    short int expr3();
    short int expr2();
    short int expression();
    int isValidFnChar(char);
    unsigned char *filenameWord();
    void line_terminator();
    void setup();
    unsigned char breakcheck();
    int inchar();
    void outchar(unsigned char);
    bool initSD();
    void cmd_Files();

    void Loop();
    void Setup();

public:
    Software_Class *Load();

    enum Picture_ID
    {
        Tiny_Basic_32 = 48 //currently empty
    };

    static void Main_Task(void *pvParameters);

    Tiny_Basic_Class();
    ~Tiny_Basic_Class();
};

void Tiny_Basic_Task(void *);

Software_Handle_Class TinyBasic_Handle("Tiny Basic", Tiny_Basic_Class::Tiny_Basic_32, Tiny_Basic_Class::Load);

#endif