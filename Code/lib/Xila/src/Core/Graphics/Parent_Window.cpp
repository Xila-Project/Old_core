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
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Methods

Parent_Window_Class::~Parent_Window_Class()
{
    this->Delete();
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
    if (!this->Is_Valid())
    {
        return;
    }
    Auto_Semaphore_Class Semaphore = Graphics.Take_Semaphore_Auto();
    lv_obj_del_async(this->Get_Pointer());
}

Parent_Window_Class* Parent_Window_Class::Get_User_Parent_Window(const Accounts_Types::User_Type* User)
{
    for (auto& Parent_Window : List)
    {
        if (Parent_Window->Owner_Software->Get_Owner_User() == User)
        {
            return &(*Parent_Window);
        }
    }
    return NULL;
}

