#include "Core/Graphics/Dialog.hpp"

using namespace Xila_Namespace;

void Dialog_Class::Create(Object_Class Parent_Object)
{
    if (!Parent_Object)
    {
        return;
    }

    this->Set_Pointer(lv_obj_create(Parent_Object.Get_Pointer()));
    this->Set_Interface();
    this->Set_Size(Percentage(75), Percentage(75));
}
