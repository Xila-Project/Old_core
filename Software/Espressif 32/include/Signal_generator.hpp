#ifndef SIGNAL_GENERATOR_INCLUDED
#define SIGNAL_GENERATOR_INCLUDED

#include "Xila.hpp"

#define INSTANCE_POINTER Signal_Generator_Class::Instance_Pointer

class Signal_Generator_Class : private Software_Class
{
protected:
    static Signal_Generator_Class* Instance_Pointer;

    static Software_Handle_Class* Handle_Pointer;

    Signal_Generator_Class();
    ~Signal_Generator_Class();

    friend void Signal_Generator_Task(void*);

public:
    enum Picture_ID
    {
        Signal_Generator_32 = 18
    };

    static Software_Class* Load();
};

void Signal_Generator_Task(void*);

Software_Handle_Class Signal_Generator_Handle("Signal Generator", Signal_Generator_Class::Signal_Generator_32, Signal_Generator_Class::Load);

#endif