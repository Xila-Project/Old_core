#include "be_constobj.h"

static be_define_const_map_slots(Berry_Serial_Type_map) {
    { be_const_key(Set_Pins, -1), be_const_ctype_func(Berry_Serial_Class_Set_Pins_B512B990_F39E_48A3_96AE_5D02FFB6A81B) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_Serial_Class_Read_String_E8877C34_A1A7_4BCC_9315_4AE895F47A00) },
    { be_const_key(deinit, 20), be_const_ctype_func(Berry_Serial_Class_Deinitialize_98E4B7C6_79D0_49CD_9CCD_22E532425C11) },
    { be_const_key(Get_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Get_Baud_Rate_85E939BA_AE0F_4E7B_A3B6_1F114D15974E) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_Serial_Class_Write_Bytes_B4641B92_246A_45BF_9321_8086B40B5883) },
    { be_const_key(Read_Bytes, 11), be_const_ctype_func(Berry_Serial_Class_Read_Bytes_1ED9044D_18BF_4A71_A7C5_9E57BA1C2DD1) },
    { be_const_key(Set_Receive_Invert, 10), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Invert_6A291C06_4133_405E_9D33_E3AFC8E1663C) },
    { be_const_key(Set_Hardware_Flow_Control, 19), be_const_ctype_func(Berry_Serial_Class_Set_Hardware_Flow_Control_14C7C3DE_108E_4623_87F4_B5CA22556B52) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_Serial_Class_Peek_1F96E306_4B7F_447C_BDFA_B23845D5BEAB) },
    { be_const_key(_p, 15), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_Serial_Class_Write_EBD69D97_25D3_4418_BC70_E87A1B88925A) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Serial_Class_Set_Mode_462A5EC7_AB8C_4A62_9D70_9C91502A6A3A) },
    { be_const_key(Begin, 9), be_const_ctype_func(Berry_Serial_Class_Begin_873AD614_915F_4330_B60F_5B459543BA3A) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_Serial_Class_Flush_3AF35B1B_E1B2_4560_8C15_16FCB6FF7E94) },
    { be_const_key(End, 8), be_const_ctype_func(Berry_Serial_Class_End_B0FD87E9_66FD_4A39_BC87_4714E8468CD0) },
    { be_const_key(Set_Receive_Buffer_Size, -1), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Buffer_Size_68C8A051_299A_4EF2_80BC_4E4E62841959) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_Serial_Class_Write_String_97D4AAB2_F476_4D56_89F3_F186B291BCB3) },
    { be_const_key(Set_Transmit_Buffer_Size, 1), be_const_ctype_func(Berry_Serial_Class_Set_Transmit_Buffer_Size_71EBADE4_6131_4A03_8076_D55CDCE69BA0) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_Serial_Class_Available_7602440F_1705_4C2A_96FB_E31F165B327A) },
    { be_const_key(Set_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Set_Baud_Rate_4F767AF9_80F0_465E_9C26_F9DFF0931324) },
    { be_const_key(Available_For_Write, -1), be_const_ctype_func(Berry_Serial_Class_Available_For_Write_54877D7A_15D6_4BDE_95AC_CE097899070F) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Serial_Class_Read_2B6A90F9_65A9_48D2_9AE6_FAE8074477EF) },
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
