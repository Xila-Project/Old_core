#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_C5C783C0_FEF1_4F3D_A423_AA68CC402558) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_ABDBCF33_F94E_4810_8726_A02E3F97EB45) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_B5E0741E_6BB1_43DF_9670_393B50489CE2) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_6E8DB53F_0168_41E6_9B18_9E7D011AFCD5) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_60F59B19_3C45_473B_A139_D452353C71CD) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_24654096_FE76_4828_9617_25EC0727C557) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_6CBECC7B_B8E9_4AFA_8570_E0EA81552425) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_3DDDB0B0_D8CD_46A5_977E_FDC7921AA3F5) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_21F79487_A7DB_4CD5_BC5E_ED91C9E79966) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_2380BC1A_A1F1_4EF0_92DE_6EF6097B2FD0) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_6229628A_9F66_44CE_8CEE_166E56B18386) },
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
