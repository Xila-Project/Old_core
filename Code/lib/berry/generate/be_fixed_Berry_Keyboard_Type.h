#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_F7E41EB9_4022_43B2_9401_DC3CB1D5A91D) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_0D09F7E6_0B04_49A5_A02D_16B576D5A2C2) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_72FD1ED1_8A7A_4EDF_ACF8_F96E1AF8A5E5) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_87A703B5_8CC9_445D_BF4D_FE87EB965342) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_9EEE5663_2D18_4385_8433_D38269616EF8) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_26D17A0E_1109_4EA9_ABB5_2F30FC2F442B) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_456890DE_B5DB_4288_A9B1_4D6CD09D46B4) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_DA9D96C6_C3EC_4181_BA28_D30C2484C50A) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_B2DDC38F_E648_4CBC_8EBF_FC832BFEA40D) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_85CDFDD1_3FD2_4DDA_8ED4_31389D0607F8) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_F8098880_29DA_44B0_847C_31A370260D11) },
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
