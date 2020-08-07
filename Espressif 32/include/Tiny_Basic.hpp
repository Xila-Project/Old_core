#ifndef TINYBASIC_H_INCLUDED
#define TINYBASIC_H_INCLUDED

#include "GalaxOS.hpp"

class TinyBasic_Class : public Software_Class
{
    private:

    const static unsigned char keywords[] =
    {
    'L','I','S','T'+0x80,
    'L','O','A','D'+0x80,
    'N','E','W'+0x80,
    'R','U','N'+0x80,
    'S','A','V','E'+0x80,
    'N','E','X','T'+0x80,
    'L','E','T'+0x80,
    'I','F'+0x80,
    'G','O','T','O'+0x80,
    'G','O','S','U','B'+0x80,
    'R','E','T','U','R','N'+0x80,
    'R','E','M'+0x80,
    'F','O','R'+0x80,
    'I','N','P','U','T'+0x80,
    'P','R','I','N','T'+0x80,
    'P','O','K','E'+0x80,
    'S','T','O','P'+0x80,
    'B','Y','E'+0x80,
    'F','I','L','E','S'+0x80,
    'M','E','M'+0x80,
    '?'+ 0x80,
    '\''+ 0x80,
    'A','W','R','I','T','E'+0x80,
    'D','W','R','I','T','E'+0x80,
    'D','E','L','A','Y'+0x80,
    'E','N','D'+0x80,
    'R','S','E','E','D'+0x80,
    'C','H','A','I','N'+0x80,
    'T','O','N','E','W'+0x80, //tone
    'T','O','N','E'+0x80,
    'N','O','T','O','N','E'+0x80,
    'E','C','H','A','I','N'+0x80, //eeprom -> replace with SD
    'E','L','I','S','T'+0x80,
    'E','L','O','A','D'+0x80,
    'E','F','O','R','M','A','T'+0x80,
    'E','S','A','V','E'+0x80,
    };




    TaskHandle_t TinyBasic_Socket_Handle;

    static TinyBasic_Class* TinyBasic_Pointer;


    public:

    TinyBasic_Class();
    ~TinyBasic_Class();

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


    static int isValidFnChar( char c );
    unsigned char * filenameWord(void);
    static void line_terminator(void);
    static unsigned char breakcheck(void);
    static int inchar();
    static void outchar(unsigned char c);
    static int initSD( void );

    friend void TinyBasic_Socket(void *pvParameters);
    
};

void TinyBasic_Socket(void *pvParameters);

#endif