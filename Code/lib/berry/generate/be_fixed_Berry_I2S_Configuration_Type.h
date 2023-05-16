#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Configuration_Type_map) {
    { be_const_key(Set_Bit_Clock_Pin, 2), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Bit_Clock_Pin_84DFDFA1_1AB6_4F58_B86E_C5A97677185B) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Mode_D5F37655_74D9_484F_B953_C21A5A55907D) },
    { be_const_key(Get_Format, 9), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Format_8AD6CBE7_946A_4722_8858_CBDFD1E44A7F) },
    { be_const_key(Get_Clock_Data_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Clock_Data_Pin_0C3FDE29_8DAA_4491_8758_A4F0B9F8E8EB) },
    { be_const_key(Get_Bit_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Bit_Clock_Pin_9611FB80_A4C3_49A7_85DE_7F63273FC8AE) },
    { be_const_key(Set_Word_Select_Clock_Pin, 1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Word_Select_Clock_Pin_523C92D0_9108_4D7F_8B7C_BD1823EEAE06) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Initialize_6702998C_753A_42F5_B216_6ABCE1F7AEAF) },
    { be_const_key(Get_Word_Select_Clock_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Get_Word_Select_Clock_Pin_BF6A431B_2231_4912_A954_08793E9D2C1F) },
    { be_const_key(Set_Mode, 3), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Mode_EEA1C49B_C023_4F00_8F32_D448E22F88F3) },
    { be_const_key(Set_Format, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Format_DFF52237_A3A5_44E4_9668_5BE2314A5F38) },
    { be_const_key(Set_Data_Pin, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Set_Data_Pin_C1D43567_BA43_4F72_A66E_885E3733B499) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_I2S_Configuration_Class_Deinitialize_580DB890_7D39_432A_80FB_4CF0EF5B82BD) },
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
