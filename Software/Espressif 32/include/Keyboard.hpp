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

class Keyboard_Class
{
    private:
        static Keyboard_Class* Keyboard_Pointer;

        int clkPin, dataPin;

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
        volatile uint16_t fromRaw = 0;
        volatile uint16_t toRaw = 0;

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

        static void Keyboard_Interrupt();

        void bufferWriteScancode(uint8_t);
        void bufferWriteChar(char);

    public:
        
        Keyboard_Class(uint8_t Data_Pin, uint8_t Clock_Pin);
        ~Keyboard_Class();
        
        void begin();
        void interruptHandler();
        unsigned char read();
        uint8_t available();
        unsigned char readRaw();
        uint8_t availableRaw();
        uint8_t getModifiers();
        void clearBuffers();
};