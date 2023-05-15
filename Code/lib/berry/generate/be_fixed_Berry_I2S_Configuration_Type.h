#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Configuration_Type_map) {
    { be_const_key(Set_Bit_Clock_Pin, 2), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Bit_Clock_Pin_F9E3943C_E01A_464B_AF51_66F05F23D62F) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Mode_C3C9BEA5_DB8A_4142_AA7F_F3CAD2BD154F) },
    { be_const_key(Get_Format, 9), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Format_4C3117F9_E396_4394_BB93_9DE123859D4B) },
    { be_const_key(Get_Clock_Data_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Clock_Data_Pin_BA92C2C6_CA47_4AE8_B02D_1BE24339EB5D) },
    { be_const_key(Get_Bit_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Bit_Clock_Pin_A8CF1261_56AB_408F_9AA3_B1FF9C48CAAA) },
    { be_const_key(Set_Word_Select_Clock_Pin, 1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Word_Select_Clock_Pin_F0875157_9CC1_418F_BA66_F705E70DBE38) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Initialize_0C1909D6_261B_4BE8_84EF_35091D24F3D6) },
    { be_const_key(Get_Word_Select_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Word_Select_Clock_Pin_E265476E_C8C9_4079_B33C_5ED4B8258050) },
    { be_const_key(Set_Mode, 3), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Mode_E1A6980D_45E7_461E_BC31_A3F14D2D8C43) },
    { be_const_key(Set_Format, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Format_58FCDEF9_A802_4BE6_89EB_3AC022D4A669) },
    { be_const_key(Set_Data_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Data_Pin_5A974BFB_DD39_4875_A765_434A1AADB65E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Deinitialize_68BFC5C3_EBAA_4D31_8F8E_095173778C4F) },
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
