#ifndef PAINT_H_INCLUDED
#define PAINT_H_INCLUDED

#include "Xila.hpp"

class Paint_Class : protected Software_Class
{
protected:


    static Paint_Class* Instance_Pointer;

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

    static Software_Class *Load();

    void Set_Variable(const void *, uint8_t , uint8_t , uint8_t  = 0);

    enum Picture_ID
    {
        Paint_32 = 7
    };

    static void Main_Task(void*);
};

Software_Handle_Class Paint_Handle("Paint", Paint_Class::Paint_32, Paint_Class::Load);

#endif