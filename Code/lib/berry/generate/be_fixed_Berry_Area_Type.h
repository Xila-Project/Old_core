#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_1053E595_A5D1_43E9_9FDB_E4D3FB7617BE) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_5B5BDDED_3A6A_4C2E_9C53_07F32C7B4705) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_42378EBE_4614_4D9E_907E_E163B0D49315) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_A38E80C8_E1F2_4164_835D_F578C5EC34A2) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_0EF29A3A_2F58_422A_ACCD_4CFC877A22DD) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_38CA9D36_01CE_425B_AB12_D2A95B6F13CC) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_8B2FDAF4_2D12_4CE3_8A1A_846AA1A3C178) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_68DAEC50_8F27_4FBD_A633_3C0E0129CAEE) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_7A7F8B7D_6BF0_4932_9CDB_2127F11C8D47) },
};

static be_define_const_map(
    Berry_Area_Type_map,
    10
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Area_Type,
    1,
    NULL,
    Area_Type
);
