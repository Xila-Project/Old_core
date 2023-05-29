#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_0420DB67_3B27_44CB_82C8_90D2450C53AB) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_79D00185_8EDB_4EFE_B958_97F69BCB9096) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_AA627FA1_196C_424F_9C9C_F686FA67236B) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_0269C884_D187_4B43_A256_25D2DF551D14) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_42299C73_D72B_4DDC_AA9B_5ECC551126B4) },
};

static be_define_const_map(
    Berry_Dialog_Type_map,
    6
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Dialog_Type,
    1,
    (bclass *)&Berry_Window_Type,
    Dialog_Type
);
