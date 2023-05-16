/********************************************************************
** Copyright (c) 2018-2020 Guan Wenliang
** This file is part of the Berry default interpreter.
** skiars@qq.com, https://github.com/Skiars/berry
** See Copyright Notice in the LICENSE file or at
** https://github.com/Skiars/berry/blob/master/LICENSE
********************************************************************/
#include "berry.h"

/* this file contains the declaration of the module table. */

/* default modules declare */
be_extern_native_module(string);
be_extern_native_module(json);
be_extern_native_module(math);
be_extern_native_module(time);
be_extern_native_module(os);
be_extern_native_module(global);
be_extern_native_module(sys);
be_extern_native_module(debug);
be_extern_native_module(gc);
be_extern_native_module(solidify);
be_extern_native_module(introspect);
be_extern_native_module(strict);
be_extern_native_module(undefined);

/* user-defined modules declare start */
be_extern_native_module(Drive);
be_extern_native_module(Memory);
be_extern_native_module(System);
be_extern_native_module(Graphics);
be_extern_native_module(This);
be_extern_native_module(Pin);
be_extern_native_module(Flash);
be_extern_native_module(Clipboard);
be_extern_native_module(Sound);
be_extern_native_module(Communication);
be_extern_native_module(Mathematics);
be_extern_native_module(Softwares);
/* user-defined modules declare end */

/* module list declaration */
BERRY_LOCAL const bntvmodule_t* const be_module_table[] = {
/* default modules register */
#if BE_USE_STRING_MODULE
    &be_native_module(string),
#endif
#if BE_USE_JSON_MODULE
    &be_native_module(json),
#endif
#if BE_USE_MATH_MODULE
    &be_native_module(math),
#endif
#if BE_USE_TIME_MODULE
    &be_native_module(time),
#endif
#if BE_USE_OS_MODULE
    &be_native_module(os),
#endif
#if BE_USE_GLOBAL_MODULE
    &be_native_module(global),
#endif
#if BE_USE_SYS_MODULE
    &be_native_module(sys),
#endif
#if BE_USE_DEBUG_MODULE
    &be_native_module(debug),
#endif
#if BE_USE_GC_MODULE
    &be_native_module(gc),
#endif
#if BE_USE_SOLIDIFY_MODULE
    &be_native_module(solidify),
#endif
#if BE_USE_INTROSPECT_MODULE
    &be_native_module(introspect),
#endif
#if BE_USE_STRICT_MODULE
    &be_native_module(strict),
#endif
    &be_native_module(undefined),
    /* user-defined modules register start */
    &be_native_module(Drive),

    &be_native_module(Memory),

    &be_native_module(Graphics),

    &be_native_module(System),
    
    &be_native_module(This),

    &be_native_module(Pin),

    &be_native_module(Flash),

    &be_native_module(Clipboard),

    &be_native_module(Sound),

    &be_native_module(Communication),

    &be_native_module(Mathematics),

    &be_native_module(Softwares),
    /* user-defined modules register end */
    NULL /* do not remove */
};

/* user-defined classes declare start */
be_extern_native_class(Berry_Instruction_Type);
be_extern_native_class(Berry_Time_Type);
be_extern_native_class(Berry_Date_Type);
be_extern_native_class(Berry_Module_Type);
be_extern_native_class(Berry_Long_Integer_Type);
be_extern_native_class(Berry_Long_Real_Type);
/* be_extern_native_class(my_class); */
/* user-defined classes declare end */

BERRY_LOCAL bclass_array be_class_table = {
    /* first list are direct classes */
    &be_native_class(Berry_Instruction_Type),
    &be_native_class(Berry_Time_Type),
    &be_native_class(Berry_Date_Type),
    &be_native_class(Berry_Module_Type),
    &be_native_class(Berry_Long_Integer_Type),
    &be_native_class(Berry_Long_Real_Type),
    /* &be_native_class(my_class), */
    NULL, /* do not remove */
};
