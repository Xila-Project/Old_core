#include "Arduino.h"

#ifndef BOOTLOADER_HPP_INCLUDED
#define BOOTLOADER_HPP_INCLUDED

class Xila_Loader_Class
{
private:
    static void Display_Numeric_Data_Handler(uint32_t);
    static void Display_String_Data_Handler(const char *, uint8_t);
    static void Display_Event_Handler(uint8_t);

    static void Loop(void *);

    void Boot();
    void Load();

    void Shutdown();

public:
    void Start();

};

extern Xila_Loader_Class Xila_Loader;

#endif