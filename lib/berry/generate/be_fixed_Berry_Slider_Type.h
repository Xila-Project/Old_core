#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_77210162_CB77_45AD_9FD7_7BA938BB9668) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_053BFD2A_9F86_4A68_8837_7085B70B0184) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_50FBA89D_4901_4722_AE67_1F24C128185F) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_ADF2E215_C168_48AD_A5CD_6D4D1C388591) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_09353F09_71B1_45BC_971A_A2021A99EB0F) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_4EB93925_387C_4C7D_9430_3BA8B3C3BE26) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_1508F0A5_2826_4D7E_BADE_25DE39540FB3) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_4DDCC051_6C99_4272_BADD_85FB175E0DC6) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_22063933_2ABF_4FC9_AD83_8A09D4188BE7) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_5DF4FE97_041F_48F5_B6CA_F2CBFEE5244B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_E6CB8F91_9755_48F9_97AC_8E643763E9C6) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_A6C20255_94A8_4EE5_B3D5_CF2CF24D4975) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_173CD94E_34AA_4888_91B1_73ABECF94292) },
};

static be_define_const_map(
    Berry_Slider_Type_map,
    14
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Slider_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Slider_Type
);
