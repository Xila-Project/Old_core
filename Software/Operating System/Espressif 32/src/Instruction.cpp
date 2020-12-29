#include "Instruction.hpp"

Core_Instruction::Core_Instruction(void (*Function)(Core_Instruction*), void** Arguments, uint8_t Arguments_Size)
{
    Function_Pointer = Function;
    //Function_Arguments = new void*[Arguments_Size];
    Function_Arguments = Arguments;
    Executed = xSemaphoreCreateMutex();
}