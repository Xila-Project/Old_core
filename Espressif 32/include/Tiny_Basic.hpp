#ifndef TINYBASIC_H_INCLUDED
#define TINYBASIC_H_INCLUDED

#include "GalaxOS.hpp"

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
// https://github.com/hoopsurfer/TinyBasicESP32
// Target IDE:       Arduino
// Target hardware:  Adafruit ESP32 Feather
//                   https://learn.adafruit.com/adafruit-huzzah32-esp32-feather/pinouts
//                   Adafruit 2.4" TFT Touchscreen Featherwing
//                   https://learn.adafruit.com/adafruit-2-4-tft-touch-screen-featherwing/pinouts
//

#define INSTANCE_POINTER TinyBasic_Class::Instance_Pointer

class TinyBasic_Class : public Software_Class
{
private:
////////////////////////////////////////////////////////////////////////////////
// Feature option configuration - comment out to minimize dependencies

// Enable LOAD, SAVE, FILES commands through the Arduino SD Library
#define ENABLE_FILEIO 1
#define AUTORUN_FILE "/hello.bas"

// Enable TFT color display and touchscreen
//#define ENABLE_TFT 1
#define ENABLE_TFT

// Enable EEPROM-based program storage with autorun to store a program during powerdown
//#define ENABLE_EEPROM 1

// Enable TONE, NOTONE commands to support audio
//#define ENABLE_TONES 1
#define kPiezoPin 5

// Enable WiFi support to read/write information from the network.
//#define ENABLE_WIFI 1

// Set defailt serial speed for support serial input/output
#define CONSOLE_BAUD 115200

/////////////////////////////////////////////////////////////////////////////////
// enable incremental hardware capabilities, not required for simple programs

// Set max space to allow for BASIC programs in memory less hardware related buffers
//#define PROG_MAX 32768 - 1
#define PROG_MAX 65535

#ifdef ENABLE_FILEIO
#define FILEIO_RAM (1030) /* buffer */
#else
#define FILEIO_RAM (0)
#endif

#define TBE_VERSION "0.15"

#define SCK_PIN 5   // SPI
#define MISO_PIN 18 // SPI
#define MOSI_PIN 19 // SPI
#define SD_CS 14    // SD Card Chip Select
#define RT_CS 32    // Touchscreen Chip Select
#define TFT_CS 15   // TFT Display Chip Select
#define TFT_DC 33   // TFT Display Data/Command Select

    const static unsigned char keywords[] PROGMEM = {
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

    boolean inhibitOutput = false;
    static boolean runAfterLoad = false;
    static boolean triggerRun = false;

////////////////////////////////////////////////////////////////////////////////
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

    static unsigned char program[PROG_RAM];
    static unsigned char *txtpos, *list_line, *tmptxtpos;
    static unsigned char expression_error;
    static unsigned char *tempsp;

    TaskHandle_t TinyBasic_Socket_Handle;

    static TinyBasic_Class *TinyBasic_Pointer;

    // This is calibration data for the raw touch data to the screen coordinates
#define TS_MINX 3800
#define TS_MAXX 100
#define TS_MINY 100
#define TS_MAXY 3750
#define PENRADIUS 3


// EEPROM


    int eepos = 0;

#define TONE_RAM (40) /* I/O buffer */

#define PROG_RAM (PROG_MAX - FILEIO_RAM - TONE_RAM)


    // Stream files source : these will select, at runtime, where IO happens through for load/save
    enum
    {
        kStreamSerial = 0,
        kStreamEEProm,
        kStreamFile
    };
    static unsigned char inStream;
    static unsigned char outStream;

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
        ENABLE_TONES,
        KW_TONEW,
        KW_TONE,
        KW_NOTONE,
        ENABLE_EEPROM,
        KW_ECHAIN,
        KW_ELIST,
        KW_ELOAD,
        KW_EFORMAT,
        KW_ESAVE,
        ENABLE_WIFI,
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

    static const unsigned char func_tab[];

#define FUNC_PEEK 0
#define FUNC_ABS 1
#define FUNC_AREAD 2
#define FUNC_DREAD 3
#define FUNC_RND 4
#define FUNC_UNKNOWN 5

    const static unsigned char to_tab[];

    const static unsigned char step_tab[] = {
        'S', 'T', 'E', 'P' + 0x80,
        0};

    const static unsigned char relop_tab[] = {
        '>', '=' + 0x80,
        '<', '>' + 0x80,
        '>' + 0x80,
        '=' + 0x80,
        '<', '=' + 0x80,
        '<' + 0x80,
        '!', '=' + 0x80,
        0};

#define RELOP_GE 0
#define RELOP_NE 1
#define RELOP_GT 2
#define RELOP_EQ 3
#define RELOP_LE 4
#define RELOP_LT 5
#define RELOP_NE_BANG 6
#define RELOP_UNKNOWN 7

    const static unsigned char highlow_tab[] = {
        'H', 'I', 'G', 'H' + 0x80,
        'H', 'I' + 0x80,
        'L', 'O', 'W' + 0x80,
        'L', 'O' + 0x80,
        0};

#define HIGHLOW_HIGH 1
#define HIGHLOW_UNKNOWN 4

#define STACK_SIZE (sizeof(struct stack_for_frame) * 5)
#define VAR_SIZE sizeof(short int) // Size of variables in bytes

    static unsigned char *stack_limit;
    static unsigned char *program_start;
    static unsigned char *program_end;
    static unsigned char *variables_begin;
    static unsigned char *current_line;
    static unsigned char *sp;

#define STACK_GOSUB_FLAG 'G'
#define STACK_FOR_FLAG 'F'

    static unsigned char table_index;
    static LINENUM linenum;

    static const unsigned char okmsg[] PROGMEM = "OK";
    static const unsigned char whatmsg[] PROGMEM = "What? ";
    static const unsigned char howmsg[] PROGMEM = "How?";
    static const unsigned char sorrymsg[] PROGMEM = "Sorry!";
    static const unsigned char initmsg[] PROGMEM = "TinyBasic ESP32 " TBE_VERSION;
    static const unsigned char memorymsg[] PROGMEM = " bytes free.";
#ifdef ENABLE_EEPROM
    static const unsigned char eeprommsg[] PROGMEM = " EEProm bytes total.";
    static const unsigned char eepromamsg[] PROGMEM = " EEProm bytes available.";
#endif
    static const unsigned char breakmsg[] PROGMEM = "break!";
    static const unsigned char unimplimentedmsg[] PROGMEM = "Unimplemented";
    static const unsigned char backspacemsg[] PROGMEM = "\b \b";
    static const unsigned char indentmsg[] PROGMEM = "    ";
    static const unsigned char sderrormsg[] PROGMEM = "SD card error.";
    static const unsigned char sdfilemsg[] PROGMEM = "SD file error.";
    static const unsigned char dirextmsg[] PROGMEM = "(dir)";
    static const unsigned char slashmsg[] PROGMEM = "/";
    static const unsigned char spacemsg[] PROGMEM = " ";

    File fp;

public:
    TinyBasic_Class(Software_Handle_Class*);
    ~TinyBasic_Class();

    void cmd_Files(void);
    unsigned char *filenameWord(void);
    static boolean sd_is_initialized = false;

    static int
    inchar(void);
    static void outchar(unsigned char c);
    static void line_terminator(void);
    static short int expression(void);
    static unsigned char breakcheck(void);

    static void ignore_blanks(void);
    static void scantable(const unsigned char *table);
    static void pushb(unsigned char b);
    static unsigned char popb();
    void printnum(int num);
    void printUnum(unsigned int num);
    static unsigned short testnum(void);
    static unsigned char print_quoted_string(void);
    void printmsgNoNL(const unsigned char *msg);
    void printmsg(const unsigned char *msg);
    static void getln(char prompt);
    static unsigned char *findline(void);
    static void toUppercaseBuffer(void);
    void printline();
    static short int expr4(void);
    static short int expr3(void);
    static short int expr2(void);
    static short int expression(void);

    static int isValidFnChar(char c);
    unsigned char *filenameWord(void);
    static void line_terminator(void);
    static unsigned char breakcheck(void);
    static int inchar();
    static void outchar(unsigned char c);
    static int initSD(void);

    friend void TinyBasic_Task(void *pvParameters);
};

void TinyBasic_Task(void*);

#endif