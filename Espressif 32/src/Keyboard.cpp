#include "Keyboard.hpp"

Keyboard_Class* Keyboard_Class::Keyboard_Pointer;

const char Keyboard_Class::chrsNS[]={
    0,    249,  0,    245,  243,  241,  242,  252,  0,    250,  248,  246,  244,  '\t', '`',  0,
    0,    0,    0,    0,    0,    'q',  '1',  0,    0,    0,    'z',   's',  'a',  'w',  '2',  0,
    0,    'c',  'x',  'd',  'e',  '4',  '3',  0,    0,    ' ',  'v',  'f',  't',  'r',  '5',  0,
    0,    'n',  'b',  'h',  'g',  'y',  '6',  0,    0,    0,    'm',  'j',  'u',  '7',  '8',  0,
    0,    ',',  'k',  'i',  'o',  '0',  '9',  0,    0,    '.',  '/',  'l',  ';',  'p',  '-',  0,
    0,    0,    '\'', 0,    '[',  '=',  0,    0,    0,    0,    '\n', ']',  0,    '\\', 0,    0,
    0,    0,    0,    0,    0,    0,    '\b', 0,    0,    '1',  0,    '4',  '7',  0,    0,    0,
    '0',  '.',  '2',  '5',  '6',  '8',  '\033',0,   251,  '+',  '3',  '-',  '*',  '9',  0,    0,
    0,    0,    0,    247,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0};

const char Keyboard_Class::chrsSH[]={
    0,    249,  0,    245,  243,  241,  242,  252,  0,    250,  248,  246,  244,  '\t', '~',  0,
    0,    0,    0,    0,    0,    'Q',  '!',  0,    0,    0,    'Z',  'S',  'A',  'W',  '@',  0,
    0,    'C',  'X',  'D',  'E',  '$',  '#',  0,    0,    ' ',  'V',  'F',  'T',  'R',  '%',  0,
    0,    'N',  'B',  'H',  'G',  'Y',  '^',  0,    0,    0,    'M',  'J',  'U',  '&',  '*',  0,
    0,    '<',  'K',  'I',  'O',  ')',  '(',  0,    0,    '>',  '?',  'L',  ':',  'P',  '_',  0,
    0,    0,    '\"', 0,    '{',  '+',  0,    0,    0,    0,    '\n', '}',  0,    '|',  0,    0,
    0,    0,    0,    0,    0,    0,    '\b', 0,    0,    '1',  0,    '4',  '7',  0,    0,    0,
    '0',  '.',  '2',  '5',  '6',  '8',  '\033',0,   0,    '+',  '3',  '-',  '*',  '9',  0,    0,
    0,    0,    0,    247,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0};


Keyboard_Class::Keyboard_Class(uint8_t Data_Pin, uint8_t Clock_Pin)
    :clkPin(Clock_Pin),
    dataPin(Data_Pin),
    shift(0),
    modifs(0),
    cpslk(false),
    scrlk(false),
    numlk(false),
    dirOUT(false),
    kstate(0),
    skipCount(0),
    rc(0),
    CHARS(0x90),
    fromRaw(0),
    toRaw(0),
    fromChar(0),
    toChar(0),
    ACK(false),
    updLEDs(false)

{
    
}

Keyboard_Class::~Keyboard_Class() {
    detachInterrupt(clkPin);
}

uint8_t Keyboard_Class::getModifiers() {
    return modifs;
}

void Keyboard_Class::send(uint8_t x) {
    bool d=true;
    dirOUT=true;
    for(uint8_t i=0;i<8;i++) {
        if((x&(1<<i))!=0) {
            d=!d;
        }
    }
    uint16_t shift=x|(0x200)|(0x100*d);
    digitalWrite(clkPin,LOW);
    delayMicroseconds(60);
    digitalWrite(dataPin,LOW);
    delayMicroseconds(1);
    digitalWrite(clkPin,HIGH);
    for(uint8_t i=0;i<10;i++)
    {
        while(digitalRead(clkPin));
        while(!digitalRead(clkPin));
        digitalWrite(dataPin,shift&1);
        shift>>=1;
    }
    digitalWrite(dataPin,HIGH);
    while(digitalRead(clkPin));
    while(!digitalRead(clkPin));
    dirOUT=false;
}

uint8_t Keyboard_Class::available() {
    return toChar-fromChar;
}

unsigned char Keyboard_Class::read() {
    if(fromChar>=toChar)return '\0';
    return charBuffer[fromChar++];
}

uint8_t Keyboard_Class::availableRaw() {
    return toRaw-fromRaw;
}

unsigned char Keyboard_Class::readRaw() {
    if(fromRaw>=toRaw)return '\0';
    return keyScancodeBuffer[fromRaw++];
}

void Keyboard_Class::waitACK() {
    while(!ACK);
    ACK=false;
}


void Keyboard_Class::tryUpdateLEDs() {
    if(!updLEDs)return;
    updLEDs=false;
    kstate=0;
    send(0xed);
    delay(100);
    send(scrlk|(numlk<<1)|(cpslk<<2));
}

void Keyboard_Class::bufferWriteScancode(uint8_t scc) {
    if(toRaw + 1 >= sizeof(keyScancodeBuffer)) {
        toRaw = 0;
        fromRaw = 0;
    }
    keyScancodeBuffer[toRaw++]=scc;
}

void Keyboard_Class::bufferWriteChar(char ch) {
    if(toChar + 1 >= sizeof(charBuffer)) {
        toChar = 0;
        fromChar = 0;
    }
    charBuffer[toChar++]=ch;
}

void Keyboard_Class::setLeds(uint8_t d) {
    send(0xed);
    send(d&7);
}

void Keyboard_Class::interruptHandler() {
    if(dirOUT)
    {
        return;
    }
    shift>>=1;
    shift|=(digitalRead(dataPin)<<10);
    if(++rc==11){
        rc=0;
        if((shift&0x401)==0x400){
            uint8_t data=(shift>>1)&0xff;
            bufferWriteScancode(data);
            switch(kstate) {
                case 0:
                    //pressed key (nothing special expected)
                    switch(data) {
                        case 0xE0:
                            kstate = 1;
                            break;
                        case 0xE1:
                            /*
                            * Don't care about this code...
                            * ...or...
                            * well, key Pause/Break has 8 bytes (not bits!) long scancode.
                            * Luckily it's the only key (as far as I know) starting with 0xE1 so it can skip next 7 bytes.
                            * The whole scancode is: E1 14 77 E1 F0 14 F0 77
                            */
                            kstate = 2;
                            skipCount = 7;
                            break;
                        case 0xF0:
                            //code meaning next byte will be key which was released
                            kstate = 3;
                            break;
                        case 0x58:
                            //caps lock
                            cpslk = !cpslk;
                            break;
                        case 0x7E:
                            //num lock
                            numlk = !numlk;
                            break;
                        case 0x77:
                            //scroll lock
                            scrlk = !scrlk;
                            break;
                        case 0x11:
                            //left alt
                            modifs|=L_ALT;
                            break;
                        case 0x12:
                            //left shift
                            modifs|=L_SHIFT;
                            break;
                        case 0x14:
                            //left ctrl
                            modifs|=L_CTRL;
                            break;
                        case 0x59:
                            //rght shift
                            modifs|=R_SHIFT;
                            kstate = 0; 
                            break;
                        default:
                            if(modifs&SHIFT) {
                                bufferWriteChar(chrsSH[data]);
                            }
                            else if (cpslk && chrsNS[data] < 127){
                                bufferWriteChar(toUpperCase(chrsNS[data]));
                            }
                            else {
                                bufferWriteChar(chrsNS[data]);
                            }
                            break;
                    }
                    break;
                case 1:
                    //pressed (or released) extended code key (first byte was 0xE0)
                    switch(data) {
                        case 0xF0:
                            kstate = 4;
                            break;
                        case 0x11:
                            //rght alt
                            modifs|=R_ALT;
                            kstate = 0; 
                            break;
                        case 0x14:
                            //rght ctrl
                            modifs|=R_CTRL;
                            kstate = 0; 
                            break;
                        case 0x4a:
                            //slash on numpad
                            bufferWriteChar('/');
                            kstate = 0; 
                            break;
                        case 0x5a:
                            //home
                            bufferWriteChar('\n');
                            kstate = 0; 
                            break;
                        case 0x6b:
                            //left arrow
                            bufferWriteChar('\x80');
                            kstate = 0; 
                            break;
                        case 0x6c:
                            //home
                            bufferWriteChar('\r');
                            kstate = 0; 
                            break;
                        case 0x69:
                            //end
                            bufferWriteChar('\x88');
                            kstate = 0; 
                            break;
                        case 0x70:
                            //page down
                            bufferWriteChar('\x85');
                            kstate = 0; 
                            break;
                        case 0x71:
                            //delete
                            bufferWriteChar('\x7F');
                            kstate = 0; 
                            break;
                        case 0x72:
                            //down arrow
                            bufferWriteChar('\x81');
                            kstate = 0; 
                            break;
                        case 0x74:
                            //right arrow
                            bufferWriteChar('\x82');
                            kstate = 0; 
                            break;
                        case 0x75:
                            //up arrow
                            bufferWriteChar('\x83');
                            kstate = 0; 
                            break;
                        case 0x7a:
                            //page down
                            bufferWriteChar('\x87');
                            kstate = 0; 
                            break;
                        case 0x7d:
                            //page up
                            bufferWriteChar('\x86');
                            kstate = 0; 
                            break;
                        default:
                            kstate = 0; 
                    }
                    break;
                case 2:
                    //pressed key starting with 0xE1 - should be Pause/Break 
                    if(skipCount <= 0) {
                        kstate = 0;
                        bufferWriteChar('\x89');
                    }
                    else {
                        skipCount--;
                    }
                    break;
                case 3:
                    //released key
                    switch(data) {
                        case 0x11:
                            //left alt
                            modifs&=!L_ALT;
                            break;
                        case 0x12:
                            //left shift
                            modifs&=!L_SHIFT;
                            break;
                        case 0x14:
                            //left ctrl
                            modifs&=!L_CTRL;
                            break;
                        case 0x59:
                            //right shift
                            modifs&=!R_SHIFT;
                            break;
                    }
                    kstate = 0;
                    break;
                case 4:
                    //released extended code key
                    switch(data) {
                        case 0x11:
                            //right alt
                            modifs&=!R_ALT;
                            break;
                        case 0x14:
                            //right ctrl
                            modifs&=!R_CTRL;
                            break;
                    }   
                    kstate = 0;
                    break;
            }
        }
        shift=0;
    }
}

void Keyboard_Class::clearBuffers() {
    toRaw = 0;
    fromRaw = 0;
    toChar = 0;
    fromChar = 0;
}

void Keyboard_Class::begin() {
    pinMode(dataPin,OUTPUT_OPEN_DRAIN);
    pinMode(clkPin,OUTPUT_OPEN_DRAIN);
    digitalWrite(dataPin,true);
    digitalWrite(clkPin,true);
    if (Keyboard_Pointer == nullptr) {
        Keyboard_Pointer = this;
        attachInterrupt(digitalPinToInterrupt(clkPin), Keyboard_Interrupt, FALLING);
    }
}



void Keyboard_Class::Keyboard_Interrupt() {
    Keyboard_Pointer->interruptHandler();
}

