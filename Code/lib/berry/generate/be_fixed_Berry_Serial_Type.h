#include "be_constobj.h"

static be_define_const_map_slots(Berry_Serial_Type_map) {
    { be_const_key(Set_Pins, -1), be_const_ctype_func(Berry_Serial_Class_Set_Pins_7B63B4DB_D6CB_4430_983D_C15726A8F9D0) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_Serial_Class_Read_String_D3EEB771_08A2_4C1E_B864_7BE48218195F) },
    { be_const_key(deinit, 20), be_const_ctype_func(Berry_Serial_Class_Deinitialize_17547971_766E_44CB_94F6_56FC451447CF) },
    { be_const_key(Get_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Get_Baud_Rate_FDE92C97_5EF2_41BC_880C_5A2C1DA14195) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_Serial_Class_Write_Bytes_21F8201E_2C15_46A6_BF97_632D2017BE49) },
    { be_const_key(Read_Bytes, 11), be_const_ctype_func(Berry_Serial_Class_Read_Bytes_CC8D3AF5_E1FA_4DFB_875F_DB426AE1DDFE) },
    { be_const_key(Set_Receive_Invert, 10), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Invert_CF3C8D0B_8373_44A6_B2A4_E81F8A1BE4A6) },
    { be_const_key(Set_Hardware_Flow_Control, 19), be_const_ctype_func(Berry_Serial_Class_Set_Hardware_Flow_Control_7F2145FF_3EDA_4C59_BD2E_AA3940A815A7) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_Serial_Class_Peek_9C971DB5_0516_47D2_BF3E_245A5D3B1071) },
    { be_const_key(_p, 15), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_Serial_Class_Write_3BBA1401_DB83_47B7_8BBA_FB27D73646DF) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Serial_Class_Set_Mode_AA56FCA2_354F_4283_B827_E1D1266F8861) },
    { be_const_key(Begin, 9), be_const_ctype_func(Berry_Serial_Class_Begin_992D90FA_A673_46B6_A93C_6B2EC7C28870) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_Serial_Class_Flush_22A98F46_254F_4453_A3E5_D9D8EB444337) },
    { be_const_key(End, 8), be_const_ctype_func(Berry_Serial_Class_End_FE683779_ECB3_4457_B562_634B2E98C5B9) },
    { be_const_key(Set_Receive_Buffer_Size, -1), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Buffer_Size_DDE29F60_0E0E_4E1D_A149_8B24A31248CA) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_Serial_Class_Write_String_5E011500_10BB_461F_A26B_7941B2D7CC6B) },
    { be_const_key(Set_Transmit_Buffer_Size, 1), be_const_ctype_func(Berry_Serial_Class_Set_Transmit_Buffer_Size_62CAD6AD_2B83_41B0_B07F_00AC5ABF69CD) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_Serial_Class_Available_9861FDAF_84DA_4744_9488_B1AC69E9A342) },
    { be_const_key(Set_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Set_Baud_Rate_3D273D15_1D1F_4AA0_BE8E_CCB6990881DF) },
    { be_const_key(Available_For_Write, -1), be_const_ctype_func(Berry_Serial_Class_Available_For_Write_0EEA4F1E_120E_4333_B432_4EBC960D4156) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Serial_Class_Read_502FD7FD_7EB4_4C19_83FB_DD2048B41FFA) },
};

static be_define_const_map(
    Berry_Serial_Type_map,
    22
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Serial_Type,
    1,
    NULL,
    Serial_Type
);
