#include "Software/Berry/Berry.hpp"
extern "C"
{
#include "be_constobj.h"
#include "be_mapping.h"
}

using namespace Xila_Namespace;

void *Berry_Module_Type_Initialize()
{
    return new Module_Type();
}
BE_FUNC_CTYPE_DECLARE(Berry_Module_Type_Initialize, "+_p", "");

void Berry_Module_Type_Deinitialize(Module_Type *Module)
{
    delete Module;
}
BE_FUNC_CTYPE_DECLARE(Berry_Module_Type_Deinitialize, "", ".");

/*
@const_object_info_begin
class be_class_Berry_Module_Type(scope:global, name:Module_Type)
{
    _p, var
    init, ctype_func(Berry_Module_Type_Initialize)
    deinit, ctype_func(Berry_Module_Type_Deinitialize)
}
@const_object_info_end
*/

extern "C"
{
    #include "../generate/be_fixed_be_class_Berry_Module_Type.h"
}