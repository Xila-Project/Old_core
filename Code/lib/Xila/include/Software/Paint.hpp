#ifndef PAINT_H_INCLUDED
#define PAINT_H_INCLUDED

#include "Xila.hpp"

class Paint_Class : protected Xila_Class::Software
{
protected:


    static Paint_Class* Instance_Pointer;

    void Refresh_Interface();

    uint16_t Color_Palette[8];
    uint8_t Current_Color;

    /*volatile uint32_t Buffer[2][200];

    uint8_t Currrent_Buffer;
    uint8_t Buffer_Position;

    uint16_t Color_Palette[64];

    uint16_t 

    File Paint_File;

    void Export_To_Bitmap();*/
    
public:
    Paint_Class();
    ~Paint_Class();

    static Xila_Class::Software *Load();

    enum Image
    {
        Icon_32 = Xila.Display.Paint_Images
    };

    static Xila_Class::Task_Function Main_Task(void*);
};

Xila_Class::Software_Handle Paint_Handle("Paint", Paint_Class::Icon_32, Paint_Class::Load);

#endif