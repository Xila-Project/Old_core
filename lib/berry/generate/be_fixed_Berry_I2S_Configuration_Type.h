#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Configuration_Type_map) {
    { be_const_key(Set_Bit_Clock_Pin, 2), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Bit_Clock_Pin_2647CB61_1F76_4370_959D_1685F6445940) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Mode_41BB0993_E798_4A3C_909F_0131462594DF) },
    { be_const_key(Get_Data_Pin, 3), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Data_Pin_4BBA004F_378F_4AB6_856A_3435A167F818) },
    { be_const_key(Get_Format, 9), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Format_D0544575_50B1_4B8B_A3C8_3F8324332FC7) },
    { be_const_key(Get_Bit_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Bit_Clock_Pin_EA3EF429_0F13_4E1C_9B8C_F55B7A877D96) },
    { be_const_key(Set_Word_Select_Clock_Pin, 1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Word_Select_Clock_Pin_9801562E_15B2_4D67_9ECB_B320F9CB5606) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Initialize_92D7C47D_9273_40F6_85A2_D96FC6B5DF3E) },
    { be_const_key(Get_Word_Select_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Word_Select_Clock_Pin_B4FD06E7_9E8A_42A3_8CD7_49B238BDC84D) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Mode_450AE48A_71FB_48A8_B9E6_7EEB605E7457) },
    { be_const_key(Set_Format, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Format_285FA871_5171_417E_8B7C_1E8F2BAB97AA) },
    { be_const_key(Set_Data_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Data_Pin_CFD36D65_695F_418C_9623_5EDC2D67D72B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Deinitialize_EFF9C3E7_AE82_48EB_8D56_6B2ABEDF942C) },
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
