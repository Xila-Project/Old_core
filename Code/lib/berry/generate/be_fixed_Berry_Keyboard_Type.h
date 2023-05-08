#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_AF3A27B2_E987_405B_8799_E8645D34AC81) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_ADE0F679_1584_4558_88C9_4FC6358B5646) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_E08BAEAA_C23D_4213_A8EE_6DF4834EF49F) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_B4E5CFE8_41E5_48AD_B703_98CCFE4B2F4D) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_E694E9AB_83D0_4AE6_B69F_A92529E94F54) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_8A96553F_93CE_45C3_A957_EACDBE6F5020) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_1AC6DEA4_B722_4560_9DB5_4044CA0E5CCF) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_6C1A66B8_B7C7_4573_9DD6_16E5110825E0) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_C3EEC978_B4E3_4B57_8783_0E4801ACA53A) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_7AEC249A_DE19_41BD_8AFC_13ED14C23A97) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_04440B2B_59FA_4AAB_808E_9C591A134F14) },
};

static be_define_const_map(
    Berry_Keyboard_Type_map,
    12
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Keyboard_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Keyboard_Type
);
