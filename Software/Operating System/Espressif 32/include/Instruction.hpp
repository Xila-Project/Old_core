#ifndef INSTRUCTION_HPP_INCLUDED
#define INSTRUCTION_HPP_INCLUDED

#include "Arduino.h"

class Core_Instruction
{
public:
    void (*Function_Pointer)(Core_Instruction*);
    void** Function_Arguments;
    void *Return_Pointer;
    SemaphoreHandle_t Executed;
    Core_Instruction(void (*)(Core_Instruction*), void**, uint8_t);
    ~Core_Instruction();
};

#endif