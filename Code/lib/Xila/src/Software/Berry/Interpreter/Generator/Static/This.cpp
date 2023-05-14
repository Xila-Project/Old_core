#include "Software/Berry/Berry.hpp"
extern "C"
{
#include "be_constobj.h"
#include "be_mapping.h"
}

using namespace Xila_Namespace;

void *Berry_This_Get_Instruction(bvm *Virtual_Machine_Instance)
{
    Log_Verbose("This", "VM : %p", Virtual_Machine_Instance);

    void* Pointer = be_malloc(Virtual_Machine_Instance, sizeof(Instruction_Type));

    Log_Verbose("This", "Get_Instruction : %p ", Pointer);

    return new (Pointer) Instruction_Type(Berry_Class::Get_Instance(Virtual_Machine_Instance)->Get_Instruction());
}
BE_FUNC_CTYPE_DECLARE(Berry_This_Get_Instruction, "Instruction_Type", "@");

int Berry_This_Instruction_Available(bvm *Instance)
{
    return (int)Berry_Class::Get_Instance(Instance)->Instruction_Available();
}
BE_FUNC_CTYPE_DECLARE(Berry_This_Instruction_Available, "i", "@");

Graphics_Types::Window_Type *Berry_This_Get_Window(bvm *Virtual_Machine)
{
    void* Pointer = be_malloc(Virtual_Machine, sizeof(Graphics_Types::Window_Type));
    Log_Verbose("This", "Get_Window : %p / %p", Berry_Class::Get_Instance(Virtual_Machine), &Berry_Class::Get_Instance(Virtual_Machine)->Window);
    return new (Pointer) Graphics_Types::Window_Type(Berry_Class::Get_Instance(Virtual_Machine)->Window);
}
BE_FUNC_CTYPE_DECLARE(Berry_This_Get_Window, "Graphics.Window_Type", "@")

void Berry_This_Delay(bvm* Instance, int Delay)
{
    Berry_Class::Get_Instance(Instance)->Main_Task.Delay(Delay);
}
BE_FUNC_CTYPE_DECLARE(Berry_This_Delay, "", "@i");


void* Berry_This_Get_This(bvm* Instance)
{
    Module_Class* Pointer = (Module_Class*)Berry_Class::Get_Instance(Instance);
    Log_Verbose("This", "Get_This : %p", Pointer);
    return Pointer;
}
BE_FUNC_CTYPE_DECLARE(Berry_This_Get_This, "c", "@");


void Berry_This_Delay_Microseconds(int Delay)
{
    Task_Type::Delay_Microseconds(Delay);
}
BE_FUNC_CTYPE_DECLARE(Berry_This_Delay_Microseconds, "", "i");

/*
@const_object_info_begin
module This (scope:global)
{
    Get_Instruction, ctype_func(Berry_This_Get_Instruction)
    Instruction_Available, ctype_func(Berry_This_Instruction_Available)
    Get_Window, ctype_func(Berry_This_Get_Window)
    Get_This, ctype_func(Berry_This_Get_This)
    Delay, ctype_func(Berry_This_Delay)
    Delay_Microseconds, ctype_func(Berry_This_Delay_Microseconds)
}
@const_object_info_end
*/

extern "C"
{
    #include "../generate/be_fixed_This.h"
}