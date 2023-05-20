 /// @file test_String.hpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief String unit test header file.
 /// @version 0.1.0
 /// @date 05-04-2023
 /// 
 /// @copyright Copyright (c) 2023
 
#ifndef Unit_Test_String_Hpp_Included
#define Unit_Test_String_Hpp_Included

#include "Core/Module/String.hpp"

#include "unity.h"

namespace Xila_Namespace
{
    typedef class Unit_Test_Class
    {
        // - Methods

       void Constructors();
       void Capacity();   

        void Operators();
        void Concatenation();

    public:
        void Run();
    } Unit_Test_Type;
}

#endif // Unit_Test_String_Hpp_Included

