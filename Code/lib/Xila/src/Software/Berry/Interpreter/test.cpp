
#include "Software/Berry/Berry.hpp"

/* sum two ints */
int addint(int a, int b)
{
    Log_Verbose("Berry", "addint(%d, %d)", a, b);
    return a + b;
}

/* returns 'yes' or 'no' depending on v being true */
const char *yesno(bool v)
{
    Log_Information("Berry", "yesno(%d)", v);
    if (v)
        return "yes j'ai une grosse ";
    return "no";
}

/* fahrenheit to celsius, forcing to float to avoid using double libs */
const float f2c(float f)
{
    Log_Debug("Berry", "f2c(%f)", f);
    return (f - 32.0f) / 1.8f;
}

#include "mapping/be_mapping.h"

int f_addint(bvm *vm)
{
    return be_call_c_func(vm, (void *)&addint, "i", "ii");
}

int f_ftoc(bvm *vm)
{
    return be_call_c_func(vm, (void *)&f2c, "f", "f");
}

int f_yesno(bvm *vm)
{
    return be_call_c_func(vm, (void *)&yesno, "s", "b");
}

extern "C"
{
#include "be_constobj.h"
}

/* @const_object_info_begin
module test (scope: global) {
    addint, func(f_addint)
    ftoc, func(f_ftoc)
    yesno, func(f_yesno)
}
@const_object_info_end */
extern "C"
{
#include "../generate/be_fixed_test.h"
}