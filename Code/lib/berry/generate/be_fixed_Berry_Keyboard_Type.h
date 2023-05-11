#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_039E8084_0744_4305_8563_68FBC9E1AE98) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_ACA9D3B3_8AB1_4786_84A8_C2733132503A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_FC714294_C3F8_4DA2_BD21_C97965EA0782) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_86041B60_078D_4F31_9006_81C1FF6DF718) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_1A5414CA_9082_4BDE_90C5_8094AB79DD5E) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_FBE7A966_F917_4F9F_B658_37DE0D2EF689) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_24E34BCC_3E1B_473F_9E0F_00A9961160B2) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_A433743A_C6FA_4E6A_8418_2E030CE3D7C2) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_8F453D24_2105_49A4_8E95_7E941DAD891E) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_ECA83EFB_BD44_4462_9A9B_5E6921EEDB78) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_8A624446_6488_43A5_ADAA_9A8A453D56F3) },
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
