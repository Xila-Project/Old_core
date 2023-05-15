#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_0FEB73D0_35B8_44CE_8323_6736144D76EC) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_55EBEBE2_A025_4603_9CC1_362AF39AFE4F) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_F8EBE8DA_A32B_45C0_8C3B_F880E57CD1DF) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_9299D56A_9C48_4C84_AA6A_8275E78D34BE) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_DAC51AF4_33F1_412B_A9F0_47429DEBE36F) },
};

static be_define_const_map(
    Berry_Line_Type_map,
    6
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Line_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Line_Type
);
