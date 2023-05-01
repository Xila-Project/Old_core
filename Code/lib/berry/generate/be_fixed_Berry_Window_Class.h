#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Class_map) {
    { be_const_key(Create, 7), be_const_ctype_func(Berry_Window_Class_Create_void_Software_Type) },
    { be_const_key(Get_State, 4), be_const_ctype_func(Berry_Window_Class_Get_State_void) },
    { be_const_key(Set_Title, 13), be_const_ctype_func(Berry_Window_Class_Set_Title_void_char) },
    { be_const_key(Event_Callback, -1), be_const_ctype_func(Berry_Window_Class_Event_Callback_void_lv_event_t) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_void) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Window_Class_Initialize_Graphics_TypesWindow_Class) },
    { be_const_key(Get_Body, 8), be_const_ctype_func(Berry_Window_Class_Get_Body_void) },
    { be_const_key(Set_Pointer, -1), be_const_ctype_func(Berry_Window_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_State, -1), be_const_ctype_func(Berry_Window_Class_Set_State_void_Graphics_TypesWindow_State_Type) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Window_Class_Delete_void) },
    { be_const_key(Get_Owner_Software, 9), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_void) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_void) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_void_bool) },
};

static be_define_const_map(
    Berry_Window_Class_map,
    14
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Window_Class,
    1,
    NULL,
    Window_Type
);
