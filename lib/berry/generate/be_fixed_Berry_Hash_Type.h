#include "be_constobj.h"

static be_define_const_map_slots(Berry_Hash_Type_map) {
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(Is_Valid, 2), be_const_ctype_func(Berry_Hash_Class_Is_Valid_6BC5C7DC_6466_44E4_B544_7A2D5D646C5D) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Hash_Class_Delete_CF82D07B_747C_4FBD_824E_A8E6139335E5) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Hash_Class_Create_2C542860_C727_4604_BC16_EDDBD1FBA064) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Hash_Class_Deinitialize_80E1EDD7_9B02_4FB0_AF15_2CE8626DB49F) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Hash_Class_Get_Type_5603EB42_D6B6_4AB3_A601_5F7B43ECD96D) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_Hash_Class_Initialize_8AD02816_19B6_4297_A90C_7A31CBAD8CA4) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Hash_Class_Get_Size_3069670E_5AE9_4BB2_A6A8_261D8FE35833) },
    { be_const_key(Add, 0), be_const_ctype_func(Berry_Hash_Class_Add_A5E1AC11_15B6_4CB0_B480_9E24D7288560) },
};

static be_define_const_map(
    Berry_Hash_Type_map,
    9
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Hash_Type,
    1,
    NULL,
    Hash_Type
);
