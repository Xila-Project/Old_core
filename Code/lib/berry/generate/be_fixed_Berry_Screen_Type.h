#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_E5CA9EE0_8CFF_4805_ABA5_845D3C1F6479) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_1831D3CF_BE31_4C84_AF30_513D3833CAD9) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_7AE06E01_9B19_4B07_BF5D_5CB0CC519B09) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_92031701_0D9F_4B8B_89CB_8E685C6EDF6A) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_A2214EBA_5B98_4053_962B_FA6815977B25) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_7739C98A_D307_4680_817E_D9448F72AA11) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_B06E66C4_4AF7_4096_B01E_0BBF650F2FF9) },
};

static be_define_const_map(
    Berry_Screen_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Screen_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Screen_Type
);
