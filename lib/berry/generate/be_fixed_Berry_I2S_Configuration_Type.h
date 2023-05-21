#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Configuration_Type_map) {
    { be_const_key(Set_Bit_Clock_Pin, 2), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Bit_Clock_Pin_A3A223FC_613C_4988_BC80_89A764A5C4F0) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Mode_ACDEC10F_F605_4D08_9A61_4AE0A3D97FB9) },
    { be_const_key(Get_Data_Pin, 3), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Data_Pin_6938C0FC_908D_4614_B772_E56108E4DD73) },
    { be_const_key(Get_Format, 9), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Format_DF47FDBB_1A2E_40D3_B918_6EA0AE94D4F4) },
    { be_const_key(Get_Bit_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Bit_Clock_Pin_AF494BFC_B6EB_4E16_8C62_40A92AD19E14) },
    { be_const_key(Set_Word_Select_Clock_Pin, 1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Word_Select_Clock_Pin_5D4F6327_3554_408E_8020_11288CADCB8B) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Initialize_06B7F58A_5A6C_4906_A547_FFCB005B8ABC) },
    { be_const_key(Get_Word_Select_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Word_Select_Clock_Pin_1291CD43_3D88_4904_B3A2_1218AD9C8417) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Mode_80966563_9BC9_42AD_A05A_7B504C065A4F) },
    { be_const_key(Set_Format, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Format_99CA1EBE_035C_4DF3_AD71_D5A812084725) },
    { be_const_key(Set_Data_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Data_Pin_8E9E8933_C7C9_4BEA_B92B_3A7612E18FC4) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Deinitialize_82EB8B2A_04AD_410D_86CD_FE4124800F7E) },
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
