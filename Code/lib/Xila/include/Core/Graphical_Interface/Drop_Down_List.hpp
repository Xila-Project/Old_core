///
 /// @file Drop_Down_List.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 30-06-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

 #ifndef Drop_Down_List_Hpp_Included
 #define Drop_Down_List_Hpp_Included

#define Class Xila_Class::Display_Class::Drop_Down_List_Class // Shortcut

Class::Drop_Down_List_Class(Object_Type& Parent_Object)
{
    Set_Pointer(lv_dropdown_list_create(&Parent_Object));
}

void Class::Add_Option(const char* Option, uint32_t Position)
{
    lv_dropdown_add_option(Get_Pointer(), Option, Position);
}

void Class::Clear_Options()
{
    lv_dropdown_clear_options(Get_Pointer());
}

void Class::Open()
{
    lv_dropdown_open(Get_Pointer());
}

void Class::Close()
{
    lv_dropdown_close(Get_Pointer());
}

void Class::Set_Text(const char* Text)
{
    lv_dropdown_set_text(Get_Pointer(), Text);
} 

void Class::Set_Options(const char* Options)
{
    lv_dropdown_set_options(Get_Pointer(), Options);
}

void Class::Set_Options_Static(const char* Options)
{
    lv_dropdown_set_options_static(Get_Pointer(), Options);
}

void Class::Set_Selected(uint32_t Selected_Options)
{
    lv_dropdown_set_selected(Get_Pointer(), Position);
}

void Class::Set_Direction(Direction_Type Direction)
{
    lv_dropdown_set_direction(Get_Pointer(), Direction);
}

void Class::Set_Symbol(const void* Symbol)
{
    lv_dropdown_set_symbol(Get_Pointer(), Symbol);
}

void Set_Selected_Highlight(bool Enabled)
{
    lv_dropdown_set_selected_highlight(Get_Pointer(), Enabled);
}

Object_Class* Class::Get_List()
{
    lv_dropdown_get_list(Get_Pointer());
    lv_dropdown_class
}

#endif