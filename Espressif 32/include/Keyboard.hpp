#include "Arduino.h"

#define L_SHIFT 1
#define R_SHIFT 2
#define L_ALT 4
#define R_ALT 8
#define L_CTRL 16
#define R_CTRL 32

#define SHIFT 3
#define ALT 12
#define CTRL 48

class Keyboard
{
    private:
        static Keyboard* keyboard0Ptr;
        static Keyboard* keyboard1Ptr;
        static Keyboard* keyboard2Ptr;
        static Keyboard* keyboard3Ptr;
        static Keyboard* keyboard4Ptr;
        static Keyboard* keyboard5Ptr;
        static Keyboard* keyboard6Ptr;
        static Keyboard* keyboard7Ptr;

        int clkPin;
        int dataPin;

        volatile uint16_t shift;
        volatile uint16_t modifs;
        
        bool cpslk;
        bool scrlk;
        bool numlk;
        bool dirOUT;
        
        uint8_t kstate;
        uint8_t skipCount;
        uint8_t rc;
        
        const uint8_t CHARS;
        
        volatile uint8_t keyScancodeBuffer[256];
        volatile uint16_t fromRaw;
        volatile uint16_t toRaw;

        volatile char charBuffer[256];
        volatile uint16_t fromChar;
        volatile uint16_t toChar;

        static const char chrsNS[];
        static const char chrsSH[];
        
        volatile bool ACK;
        
        bool updLEDs;

        void waitACK();
        void tryUpdateLEDs();
        void setLeds(uint8_t);
        void send(uint8_t);

        static void kbdInterrupt0();
        static void kbdInterrupt1();
        static void kbdInterrupt2();
        static void kbdInterrupt3();
        static void kbdInterrupt4();
        static void kbdInterrupt5();
        static void kbdInterrupt6();
        static void kbdInterrupt7();
        void bufferWriteScancode(uint8_t);
        void bufferWriteChar(char);

    public:
        
        Keyboard(uint8_t, uint8_t);
        ~Keyboard();
        
        void begin();
        void interruptHandler();
        unsigned char read();
        uint8_t available();
        unsigned char readRaw();
        uint8_t availableRaw();
        uint8_t getModifiers();
        void clearBuffers();
};