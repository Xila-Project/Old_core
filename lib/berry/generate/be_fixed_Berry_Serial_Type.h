#include "be_constobj.h"

static be_define_const_map_slots(Berry_Serial_Type_map) {
    { be_const_key(Set_Pins, -1), be_const_ctype_func(Berry_Serial_Class_Set_Pins_AC542A36_0836_4178_81E0_B6B9108B29FC) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_Serial_Class_Read_String_ACD7E2BB_92A3_4914_A6FF_849DECF3554C) },
    { be_const_key(deinit, 20), be_const_ctype_func(Berry_Serial_Class_Deinitialize_3FFF8CF3_09C1_40B8_8C7F_BCECA361C8ED) },
    { be_const_key(Get_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Get_Baud_Rate_6BD33AC3_2BFD_46CE_95E9_90BE4EC77513) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_Serial_Class_Write_Bytes_3665BFEB_3378_4E7B_BE63_F3CA957500D8) },
    { be_const_key(Read_Bytes, 11), be_const_ctype_func(Berry_Serial_Class_Read_Bytes_700DBA59_6AD1_4814_9BA9_4F7A0257DF0A) },
    { be_const_key(Set_Receive_Invert, 10), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Invert_AB226B80_92BA_400A_9D7B_319D343C0DBF) },
    { be_const_key(Set_Hardware_Flow_Control, 19), be_const_ctype_func(Berry_Serial_Class_Set_Hardware_Flow_Control_ACF86193_A90E_4C8C_9BEC_502A6C46BF95) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_Serial_Class_Peek_5B91A889_7FFB_4060_8BFC_3BB65FF8BC74) },
    { be_const_key(_p, 15), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_Serial_Class_Write_C38BBEF2_AA22_43F7_B177_788F651CF87F) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Serial_Class_Set_Mode_11CC310B_51B7_46C0_8C3C_0293D4849C45) },
    { be_const_key(Begin, 9), be_const_ctype_func(Berry_Serial_Class_Begin_3A022746_F4D4_4BE4_A9CC_F7ED3198DAEA) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_Serial_Class_Flush_451D698A_A11F_4892_A0CC_EE14FB550883) },
    { be_const_key(End, 8), be_const_ctype_func(Berry_Serial_Class_End_DB1DDB44_9D4C_459A_BC4B_DB102BAA2320) },
    { be_const_key(Set_Receive_Buffer_Size, -1), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Buffer_Size_3912FC92_F702_4727_BA8C_F2B92B428AF5) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_Serial_Class_Write_String_97E35AD3_B42B_4125_A86F_86C14E68C6D1) },
    { be_const_key(Set_Transmit_Buffer_Size, 1), be_const_ctype_func(Berry_Serial_Class_Set_Transmit_Buffer_Size_373BF1A4_660D_4953_84DE_0B5425BF9762) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_Serial_Class_Available_C7C84EF9_9FD0_4E18_ADE0_62E4C27F7A99) },
    { be_const_key(Set_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Set_Baud_Rate_22D02035_DDAC_4506_B9C3_2D81413274FB) },
    { be_const_key(Available_For_Write, -1), be_const_ctype_func(Berry_Serial_Class_Available_For_Write_E584C620_B15C_4515_BD67_4510D3BC9185) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Serial_Class_Read_95776A55_961E_4660_91C0_0DDABE6C64B1) },
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
