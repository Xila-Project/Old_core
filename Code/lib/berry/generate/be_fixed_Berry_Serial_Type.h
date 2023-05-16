#include "be_constobj.h"

static be_define_const_map_slots(Berry_Serial_Type_map) {
    { be_const_key(Set_Pins, -1), be_const_ctype_func(Berry_Serial_Class_Set_Pins_DF6DF0D0_AB5E_4AA8_974A_846992597CCA) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_Serial_Class_Read_String_D3598437_3D49_4AEE_ACC7_B438615A22B9) },
    { be_const_key(deinit, 20), be_const_ctype_func(Berry_Serial_Class_Deinitialize_86F794D6_EDF7_41AD_995D_AFF2493799BC) },
    { be_const_key(Get_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Get_Baud_Rate_E828C3AE_E96A_4D2C_9A2D_ACE5D40C2251) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_Serial_Class_Write_Bytes_CB91B2EC_6A96_4E0E_8105_199B53AC7C0D) },
    { be_const_key(Read_Bytes, 11), be_const_ctype_func(Berry_Serial_Class_Read_Bytes_5FCE38CE_0B36_4BB8_9F57_55C33DA47103) },
    { be_const_key(Set_Receive_Invert, 10), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Invert_19328E5E_3DC3_4525_982F_E3999BC93673) },
    { be_const_key(Set_Hardware_Flow_Control, 19), be_const_ctype_func(Berry_Serial_Class_Set_Hardware_Flow_Control_7875500A_66BE_4B30_A92B_556510155A85) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_Serial_Class_Peek_ADBC9620_C25A_4A60_A5B5_DFBA88EB17B0) },
    { be_const_key(_p, 15), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_Serial_Class_Write_372B466C_A56B_46E5_B794_CA8307AE08D9) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Serial_Class_Set_Mode_1B133F25_70D5_4A9F_B2B5_02DBB2F4A87D) },
    { be_const_key(Begin, 9), be_const_ctype_func(Berry_Serial_Class_Begin_7B172760_613B_40E5_9275_BED31FA170D2) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_Serial_Class_Flush_90D5BDD0_24F8_4AB0_A712_254124356518) },
    { be_const_key(End, 8), be_const_ctype_func(Berry_Serial_Class_End_B04F1BF2_C45F_4361_9FAF_625BA5543F1E) },
    { be_const_key(Set_Receive_Buffer_Size, -1), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Buffer_Size_BDBF9EF9_2051_446A_A8C6_D81EE5CB185A) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_Serial_Class_Write_String_1A122C94_D83E_49E9_8A66_35897233A47E) },
    { be_const_key(Set_Transmit_Buffer_Size, 1), be_const_ctype_func(Berry_Serial_Class_Set_Transmit_Buffer_Size_45282E6A_3C58_4AB0_9C24_2CCE80257842) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_Serial_Class_Available_08EDA836_A789_42B5_9905_1B9128DF954E) },
    { be_const_key(Set_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Set_Baud_Rate_BBCD382C_D9EA_4218_8572_682E1D16602F) },
    { be_const_key(Available_For_Write, -1), be_const_ctype_func(Berry_Serial_Class_Available_For_Write_D8D0C54F_5CE0_47F1_82A0_53F3BF1047AF) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Serial_Class_Read_E572C813_C260_4887_BF34_F315BA831FB6) },
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
