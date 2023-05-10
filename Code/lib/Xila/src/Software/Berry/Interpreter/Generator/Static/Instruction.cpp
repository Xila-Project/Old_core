#include "Software/Berry/Berry.hpp"
extern "C"
{
#include "be_constobj.h"
#include "be_mapping.h"
}

using namespace Xila_Namespace;

void *Berry_Instruction_Class_Initialize(Module_Class *Sender = NULL, Module_Class *Receiver = NULL)
{
    if ((Sender == NULL) && (Receiver == NULL))
        return new Instruction_Class();
    else
        return new Instruction_Class(Sender, Receiver);
}
BE_FUNC_CTYPE_DECLARE(Berry_Instruction_Class_Initialize, "+_p", "[..");

void Berry_Instruction_Class_Deinitialize(Instruction_Class *Instruction)
{
    delete Instruction;
}
BE_FUNC_CTYPE_DECLARE(Berry_Instruction_Class_Deinitialize, "", ".");

void Berry_Instruction_Class_Set_Sender(Instruction_Class *Instruction, Module_Class *Sender)
{
    Instruction->Set_Sender(Sender);
}
BE_FUNC_CTYPE_DECLARE(Berry_Instruction_Class_Set_Sender, "", "..");

void Berry_Instruction_Class_Set_Receiver(Instruction_Class *Instruction, Module_Class *Receiver)
{
    Instruction->Set_Receiver(Receiver);
}
BE_FUNC_CTYPE_DECLARE(Berry_Instruction_Class_Set_Receiver, "", "..");

void *Berry_Instruction_Class_Get_Sender(Instruction_Class *Instruction)
{
    return Instruction->Get_Sender();
}
BE_FUNC_CTYPE_DECLARE(Berry_Instruction_Class_Get_Sender, "Module_Type", ".");

Void *Berry_Instruction_Class_Get_Receiver(Instruction_Class *Instruction)
{
    return Instruction->Get_Receiver();
}
BE_FUNC_CTYPE_DECLARE(Berry_Instruction_Class_Get_Receiver, "Module_Type", ".");

int Berry_Instruction_Class_Graphics_Get_Code(Instruction_Class *Instruction)
{
    return (int)Instruction->Graphics.Get_Code();
}
BE_FUNC_CTYPE_DECLARE(Berry_Instruction_Class_Graphics_Get_Code, "i", ".");

void *Berry_Instruction_Class_Graphics_Get_Target(Instruction_Class *Instruction)
{
    Graphics_Types::Object_Type *Object = new Graphics_Types::Object_Type();
    *Object = Instruction->Graphics.Get_Target();
    return Object;
}
BE_FUNC_CTYPE_DECLARE(Berry_Instruction_Class_Graphics_Get_Target, "Graphics.Object_Type", ".");

void *Berry_Instruction_Class_Graphics_Get_Current_Target(Instruction_Class *Instruction)
{
    Graphics_Types::Object_Type *Object = new Graphics_Types::Object_Type();
    *Object = Instruction->Graphics.Get_Current_Target();
    return Object;
}
BE_FUNC_CTYPE_DECLARE(Berry_Instruction_Class_Graphics_Get_Current_Target, "Graphics.Object_Type", ".");

int Berry_Instruction_Class_Softwares_Get_Code(Instruction_Class *Instruction)
{
    return (int)Instruction->Softwares.Get_Code();
}
BE_FUNC_CTYPE_DECLARE(Berry_Instruction_Class_Softwares_Get_Code, "i", ".");

/* @const_object_info_begin
class be_class_Berry_Instruction_Type(scope:global, name:Instruction_Type)
{
    _p, var
    init, ctype_func(Berry_Instruction_Class_Initialize)
    deinit, ctype_func(Berry_Instruction_Class_Deinitialize)
    Set_Sender, ctype_func(Berry_Instruction_Class_Set_Sender)
    Set_Receiver, ctype_func(Berry_Instruction_Class_Set_Receiver)
    Get_Sender, ctype_func(Berry_Instruction_Class_Get_Sender)
    Get_Receiver, ctype_func(Berry_Instruction_Class_Get_Receiver)
    Graphics_Get_Code, ctype_func(Berry_Instruction_Class_Graphics_Get_Code)
    Graphics_Get_Target, ctype_func(Berry_Instruction_Class_Graphics_Get_Target)
    Graphics_Get_Current_Target, ctype_func(Berry_Instruction_Class_Graphics_Get_Current_Target)
    Softwares_Get_Code, ctype_func(Berry_Instruction_Class_Softwares_Get_Code)
}
@const_object_info_end */

extern "C"
{
#include "../generate/be_fixed_be_class_Berry_Instruction_Type.h"
}