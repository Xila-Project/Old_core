#include "test.hpp"
#include "Software/Berry/Berry.hpp"
#include "be_constobj.h"
#include "be_mapping.h"

/* sum two ints */
int addint(int a, int b)
{
    Log_Verbose("Berry", "addint(%d, %d)", a, b);
    return a + b;
}

BE_FUNC_CTYPE_DECLARE(addint, "i", "ii")

/* returns 'yes' or 'no' depending on v being true */
const char *yesno(bool v)
{
    Log_Information("Berry", "yesno(%d)", v);
    if (v)
        return "yes j'ai une grosse ";
    return "no";
}

BE_FUNC_CTYPE_DECLARE(yesno, "s", "b")

/* fahrenheit to celsius, forcing to float to avoid using double libs */
const float ftoc(float f)
{
    Log_Debug("Berry", "f2c(%f)", f);
    return (f - 32.0f) / 1.8f;
}

BE_FUNC_CTYPE_DECLARE(ftoc, "f", "f")

Foo_Class::Foo_Class(const char *Name)
{
    strlcpy(this->Name, Name, sizeof(this->Name));
    Log_Verbose("Berry", "Foo() with name : %s", Name);
}

Foo_Class::~Foo_Class()
{
    Log_Verbose("Berry", "~Foo() with name : %s", Name);
}

bool Foo_Class::Clap(int Test)
{
    Log_Verbose("Berry", "Foo::Clap() with name : %s", Name);
    return true;
}





const void *Be_Foo_Init(const char *Name)
{
    return new Foo_Class(Name);
}

BE_FUNC_CTYPE_DECLARE(Be_Foo_Init, "+_p", "s")

void Be_Foo_Deinit(void *Instance)
{
    delete static_cast<Foo_Class *>(Instance);
}

BE_FUNC_CTYPE_DECLARE(Be_Foo_Deinit, "", ".")

bool Be_Foo_Clap(void *Instance, int Test)
{
    return static_cast<Foo_Class *>(Instance)->Clap(Test);
}

BE_FUNC_CTYPE_DECLARE(Be_Foo_Clap, "b", ".i")

extern "C"
{
#include "be_constobj.h"
}

/* @const_object_info_begin
class be_class_foo (scope:global, name:Foo)
{
    _p, var
    init, ctype_func(Be_Foo_Init)
    deinit, ctype_func(Be_Foo_Deinit)

    Clap, ctype_func(Be_Foo_Clap)
}
@const_object_info_end

@const_object_info_begin
module test (scope: global) {
    Foo, class(be_class_foo)
    addint, ctype_func(addint)
    ftoc, ctype_func(ftoc)
    yesno, ctype_func(yesno)
}
@const_object_info_end */
extern "C"
{
#include "../generate/be_fixed_be_class_foo.h"
#include "../generate/be_fixed_test.h"
}