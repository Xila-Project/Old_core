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


void Parent_Window_Class::Create(const Accounts_Types::User_Type* Owner_User)
{
    this->Owner_User = Owner_User; 
    this->Set_Pointer(lv_obj_create(lv_scr_act()));
    this->Set_Interface();
}

const Accounts_Types::User_Type* Parent_Window_Class::Get_Owner_User()
{
    return Owner_User;
}

Parent_Window_Class Parent_Window_Class::Get_User_Parent_Window(const Accounts_Types::User_Type* Owner_User)
{
    for (Parent_Window_Class Parent_Window : Parent_List)
    {
        if (Parent_Window.Get_Owner_User() == Owner_User)
        {
            return Parent_Window;
        }
    }
}

Parent_Window_Class Parent_Window_Class::Get_Parent_Window(uint16_t Index)
{
    if (Index <= Parent_List.size())
    {
        return Parent_List[Index];
    }
    return Parent_Window_Class();
}
