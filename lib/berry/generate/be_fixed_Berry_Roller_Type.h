#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_87772B39_89BB_4B48_8D9D_3B15F899291A) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_D287390C_7B1F_4C44_AEA3_FF0C8CF85849) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_D0080FE3_C377_4EA6_86AB_28219DEE5D31) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_C24B8455_FFF4_4B94_808D_7D654F8F3F33) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_DCD177B9_62D5_495E_9701_9FABFA8B6389) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_5EE1825E_ABD3_40CF_A295_EE81B5CC7E50) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_845FC1B4_6E97_4833_B4BB_30B0B906FC59) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_1AB525CC_3419_4CA1_89EE_A719844AF21D) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_BECC4391_CC4D_429F_92FA_0E0DBBA0560D) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_E42652EF_CF3C_4E3D_963E_FFA47D28FD5A) },
};

static be_define_const_map(
    Berry_Roller_Type_map,
    11
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Roller_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Roller_Type
);
