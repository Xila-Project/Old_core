#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_EF8C8D2C_DB6E_4E12_8BCD_5B80810004A4) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_728F4CBE_4BD4_40FE_8557_3B16059C00EC) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_85764803_2891_466C_B10F_532C839957DA) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_78372ABC_94BF_4170_8FA2_A84C5249662A) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_6FAD8645_5453_450A_96A4_648FD4E8C45A) },
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
