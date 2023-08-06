/// @file Interface.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 04-08-2023
///
/// @copyright Copyright (c) 2023

#include "Network/Interface.hpp"

using namespace Xila_Namespace; 
using namespace Network_Types;

Interface_Class* Interface_Class::First_Instance_Pointer = NULL;

Interface_Class::Interface_Class()
{
    if (First_Instance_Pointer == NULL)
    {
        First_Instance_Pointer = this;
        Next_Instance_Pointer = NULL;
    }
    else
    {
        Next_Instance_Pointer = First_Instance_Pointer;
        First_Instance_Pointer = this;
    }
}

Interface_Class::~Interface_Class()
{
    if (First_Instance_Pointer == this)
    {
        First_Instance_Pointer = Next_Instance_Pointer;
    }
    else
    {
        Interface_Class* Previous_Instance_Pointer = First_Instance_Pointer;
        while (Previous_Instance_Pointer->Next_Instance_Pointer != this)
        {
            Previous_Instance_Pointer = Previous_Instance_Pointer->Next_Instance_Pointer;
        }
        Previous_Instance_Pointer->Next_Instance_Pointer = Next_Instance_Pointer;
    }
}