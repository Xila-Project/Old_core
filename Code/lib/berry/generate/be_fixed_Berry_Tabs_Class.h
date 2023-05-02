#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Class_map) {
    { be_const_key(Rename_Tab, -1), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_void_uint32_t_String_Type) },
    { be_const_key(Set_Pointer, -1), be_const_ctype_func(Berry_Tabs_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Get_Content, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Content_void) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_void_Graphics_TypesObject_Class_Graphics_TypesDirection_Type_Graphics_TypesCoordinate_Type) },
    { be_const_key(Set_Active_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_void_uint32_t_bool) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_void) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_Graphics_TypesTabs_Class) },
    { be_const_key(Get_Tab_Count, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Count_void) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Animation_Time, 4), be_const_ctype_func(Berry_Tabs_Class_Get_Animation_Time_void) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_void) },
    { be_const_key(Add_Tab, 8), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_void_String_Type) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_void) },
};

static be_define_const_map(
    Berry_Tabs_Class_map,
    13
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Tabs_Class,
    1,
    NULL,
    Tabs_Type
);
