#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Configuration_Type_map) {
    { be_const_key(Set_Bit_Clock_Pin, 2), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Bit_Clock_Pin_501A115A_DBDC_4E74_85FF_B5A92F1C81BB) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Mode_7F6EE819_E73F_4639_9298_9315481B67DA) },
    { be_const_key(Get_Data_Pin, 3), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Data_Pin_01E08EDF_FB33_4AA5_8C4B_38B83BD2866C) },
    { be_const_key(Get_Format, 9), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Format_D61141E1_DB1C_49A5_BB5D_FC1C4341F1C5) },
    { be_const_key(Get_Bit_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Bit_Clock_Pin_01EAB406_C974_48D9_8F5C_0E0B9E8F48D5) },
    { be_const_key(Set_Word_Select_Clock_Pin, 1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Word_Select_Clock_Pin_AD29B68F_AE36_4D3D_BAE4_D5B57AC5C9B9) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Initialize_85D4BCE5_1DB0_4AC7_8B66_420C6B2DDB7F) },
    { be_const_key(Get_Word_Select_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Word_Select_Clock_Pin_1E5E854F_CC08_4806_8627_E9230FD98B8C) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Mode_2E443C7F_DBDE_4F25_B021_53471998E236) },
    { be_const_key(Set_Format, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Format_259BB53C_9BDF_47E3_BEE1_C8B26A5ACAEB) },
    { be_const_key(Set_Data_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Data_Pin_BBB00ED2_0404_4991_A2EE_04D7766B7BFC) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Deinitialize_4B348B2D_4760_4366_905C_AFB36349A8F0) },
};

static be_define_const_map(
    Berry_I2S_Configuration_Type_map,
    13
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_I2S_Configuration_Type,
    1,
    NULL,
    I2S_Configuration_Type
);
