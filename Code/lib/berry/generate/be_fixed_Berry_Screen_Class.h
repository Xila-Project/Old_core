#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Class_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_void) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_Graphics_TypesScreen_Class) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_void_Software_Type) },
    { be_const_key(Set_Pointer, 0), be_const_ctype_func(Berry_Screen_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Load, 7), be_const_ctype_func(Berry_Screen_Class_Load_void) },
    { be_const_key(Get_Active, 5), be_const_ctype_func(Berry_Screen_Class_Get_Active_void) },
    { be_const_key(Get_User_Screen, 2), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_void_Accounts_TypesUser_Type) },
    { be_const_key(Delete, 1), be_const_ctype_func(Berry_Screen_Class_Delete_void) },
};

static be_define_const_map(
    Berry_Screen_Class_map,
    9
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Screen_Class,
    1,
    NULL,
    Screen_Type
);
