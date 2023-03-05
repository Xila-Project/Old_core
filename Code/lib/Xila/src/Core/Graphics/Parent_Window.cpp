///
 /// @file Parent_Window.cpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 27-02-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

#include "Core/Graphics/Window.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

Class_Type Parent_Window_Class::Class(Window_Class::Class);

// - Methods

Parent_Window_Class::~Parent_Window_Class()
{
    if (this->Is_Valid())
    {
        this->Delete();
    }
}

void Parent_Window_Class::Create(const Software_Type* Owner_Module)
{
    this->Owner_Software = Owner_Software; 
    this->Set_Pointer(lv_obj_create(lv_scr_act()));
    this->Set_Interface();

    List.push_back(this);
}

void Parent_Window_Class::Delete()
{
    List.remove(this);
}

Parent_Window_Class Parent_Window_Class::Get_User_Parent_Window(const Accounts_Types::User_Type* User)
{
    for (auto& Parent_Window : List)
    {
        if (Parent_Window->Owner_Software->Get_Owner_User() == User)
        {
            return *Parent_Window;
        }
    }
    return Parent_Window_Class();
}

const Class_Type* Parent_Window_Class::Get_Class() const
{
    return &Class;
}