/********************************************************************
** Copyright (c) 2018-2020 Guan Wenliang - Stephan Hadinger
** This file is part of the Berry default interpreter.
** skiars@qq.com, https://github.com/Skiars/berry
** See Copyright Notice in the LICENSE file or at
** https://github.com/Skiars/berry/blob/master/LICENSE
********************************************************************/

extern "C"
{
#include "be_object.h"
#include "be_string.h"
#include "be_strlib.h"
#include "be_list.h"
#include "be_func.h"
#include "be_exec.h"
#include "be_vm.h"
#include "be_mem.h"
#include "be_constobj.h"
#include <string.h>
#include <ctype.h>
}

#include "Xila.hpp"

int m_Hello(bvm *vm)
{
  
    Log_Verbose("Berry", "Hello World from Test class!");
    be_return_nil(vm);
}

int m_init(bvm *vm)
{
    Log_Verbose("Berry", "Init Test class!");
    be_return_nil(vm);
}

/* @const_object_info_begin
class Test_class (scope: global, name: bytes) {
    .test_var, var
    init, func(m_init)
    Hello, func(m_Hello)
}

module Test (scope: global) {
    Test, class(Test_class)
}
@const_object_info_end */

extern "C"
{
#include "generate/be_fixed_Test_class.h"
#include "generate/be_fixed_Test.h"
}