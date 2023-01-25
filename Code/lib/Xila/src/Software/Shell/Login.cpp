///
/// @file Login.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief 
/// @version 0.1.0
/// @date 13-01-2023
/// 
/// @copyright Copyright (c) 2023
/// 

#include "Software/Shell/Shell.hpp"

Shell_Class::Login_Class::Login_Class(Shell_Class* Shell_Pointer) : Shell_Pointer(Shell_Pointer)
{
    Dialog.Create();
    Dialog.Set_Title("Login");

    Name.Create(E);
    
}

Shell_Class::Login_Class::~Login_Class()
{
}

void Shell_Class::Login_Class::Open(Shell_Class* Shell_Pointer)
{
    Shell_Pointer->Login_Pointer = new Login_Class(Shell_Pointer);
}

void Shell_Class::Login_Class::Close(Shell_Class* Shell_Pointer)
{
    delete Shell_Pointer->Login_Pointer;
    Shell_Pointer->Login_Pointer = NULL;
}

bool Shell_Class::Login_Class::Is_Openned(Shell_Class* Shell_Pointer)
{
    if (Shell_Pointer->Login_Pointer != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}