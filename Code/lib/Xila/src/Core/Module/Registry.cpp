///
 /// @file Registry.cpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 05-03-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

 #include "Core/Module/Registry.hpp"

using namespace Xila_Namespace;

bool convertToJson(const String_Type &String, JsonVariant variant)
{
    return variant.set(String);
}