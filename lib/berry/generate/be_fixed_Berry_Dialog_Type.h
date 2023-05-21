#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_D5243F66_C1F9_4C15_83BC_87B4FA6F1AE6) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_D07A7D2A_732A_49A8_8CED_DFF6E6218751) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_CD424472_598D_470D_AA72_9DA7DE9E2237) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_42E8E89E_8CE7_4904_8702_18804D2C2E2F) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_513686AC_94C7_49F8_9E32_490B200AFCEE) },
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
