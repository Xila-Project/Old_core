#ifndef PAINT_H_INCLUDED
#define PAINT_H_INCLUDED

#include "GalaxOS.hpp"

class Paint_Class : protected Software_Class
{
protected:


    static Paint_Class* Instance_Pointer;

public:
    Paint_Class();
    ~Paint_Class();

    static Software_Class *Load();

    friend void Paint_Task(void*);
};

void Paint_Task(void*);

Software_Handle_Class Paint_Handle("Paint", 12, Paint_Class::Load);

#endif