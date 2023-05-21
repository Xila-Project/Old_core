#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_1BEADD5D_1747_4E33_832A_42AB4C3C9555) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_24DAC4EA_9E6B_410B_B09D_7D045C2DAB81) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_57DDB31A_5771_4DA9_9453_863175696F14) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_E8CE7917_7ACC_45A0_9F30_9792EB27FE0B) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_6DC21B17_80FA_4A29_93B7_921A2EB96B3C) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_79FC25D8_20CC_4FDA_A8DC_9A2E729EAB13) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_890F8205_6EE6_4091_9D39_215BEC279263) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_CF9098F1_06B5_4A72_956E_D8AC7F782DD2) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_555D30A2_D9D5_4C8A_9A7E_9BA27F9F78A6) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_5100368E_EF70_49FB_AE0A_1DB40E215788) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_1C3FEC7C_4DDD_4A10_887D_E4E3F4A38C48) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_5A971BF3_8628_470A_81B5_3EDD8EEE63EB) },
};

static be_define_const_map(
    Berry_Bar_Type_map,
    13
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Bar_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Bar_Type
);
