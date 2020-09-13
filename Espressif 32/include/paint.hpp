#ifndef PAINT_H_INCLUDED
#define PAINT_H_INCLUDED

#include "GalaxOS.hpp"

class Paint_Class : public Software_Class
{
protected:
    Software_Class *Load(Software_Handle_Class *);

    static Paint_Class* Instance_Pointer;

    static const uint8_t Page_Paint = 25;
public:
    Paint_Class(Software_Handle_Class*);
    ~Paint_Class();

    friend void Paint_Task(void*);
};

void Paint_Task(void*);

#endif