#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Dialog_Type_map) {
    { be_const_key(Get_Color, -1), be_const_ctype_func(Berry_Color_Dialog_Class_Get_Color_5DACF9B4_5CA3_41D1_B65E_C89D1DE7A00A) },
    { be_const_key(Set_Color, -1), be_const_ctype_func(Berry_Color_Dialog_Class_Set_Color_76A8AECF_8496_494F_8F5D_14441AD57983) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_Color_Dialog_Class_Deinitialize_5270EC91_8870_48FF_8AD2_C637217B3EDC) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Color_Dialog_Class_Create_3D869CDB_85B2_4EF1_9586_19C86ADCA716) },
};

static be_define_const_map(
    Berry_Color_Dialog_Type_map,
    5
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Color_Dialog_Type,
    1,
    (bclass *)&Berry_Dialog_Type,
    Color_Dialog_Type
);
