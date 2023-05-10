#include "Software/Berry/Berry.hpp"
extern "C"
{
#include "be_constobj.h"
#include "be_mapping.h"
}

using namespace Xila_Namespace;

void *Berry_This_Get_Instruction(bvm *Instance)
{
    Instruction_Type *Instruction = new Instruction_Type();
    *Instruction = Berry_Class::Get_Instance(Instance)->Get_Instruction();
    return Instruction;
}
BE_FUNC_CTYPE_DECLARE(Berry_This_Get_Instruction, "Instruction_Type", "@");

int Berry_This_Instruction_Available(bvm *Instance)
{
    return (int)Berry_Class::Get_Instance(Instance)->Instruction_Available();
}
BE_FUNC_CTYPE_DECLARE(Berry_This_Instruction_Available, "i", "@");

Graphics_Types::Window_Type *Berry_This_Get_Window(bvm *Virtual_Machine)
{
    return &Berry_Class::Get_Instance(Virtual_Machine)->Window;
}
BE_FUNC_CTYPE_DECLARE(Berry_This_Get_Window, "Graphics.Window_Type", "@")

void Berry_This_Delay(bvm* Instance, int Delay)
{
    Berry_Class::Get_Instance(Instance)->Main_Task.Delay(Delay);
}
BE_FUNC_CTYPE_DECLARE(Berry_This_Delay, "", "@i");

/*
@const_object_info_begin
module This(scope:global)
{
    Get_Instruction, ctype_func(Berry_This_Get_Instruction)
    Instruction_Available, ctype_func(Berry_This_Instruction_Available)
    Get_Window, ctype_func(Berry_This_Get_Window)
    Delay, ctype_func(Berry_This_Delay)
}
@const_object_info_end
*/

extern "C"
{
    #include "../generate/be_fixed_This.h"
}