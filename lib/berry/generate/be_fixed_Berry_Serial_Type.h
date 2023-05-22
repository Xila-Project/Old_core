#include "be_constobj.h"

static be_define_const_map_slots(Berry_Serial_Type_map) {
    { be_const_key(Set_Pins, -1), be_const_ctype_func(Berry_Serial_Class_Set_Pins_09930C56_8592_4DF1_9429_2F0CB9500EE2) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_Serial_Class_Read_String_7F8AF2B3_844A_4BB8_9214_091C5F0E5524) },
    { be_const_key(deinit, 20), be_const_ctype_func(Berry_Serial_Class_Deinitialize_D1632B96_2476_4843_A93D_870BBA3950B3) },
    { be_const_key(Get_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Get_Baud_Rate_63E5FBAE_B709_4D1E_A5CF_8D906919F5F3) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_Serial_Class_Write_Bytes_22792169_351F_4C35_8791_779CACEABDC2) },
    { be_const_key(Read_Bytes, 11), be_const_ctype_func(Berry_Serial_Class_Read_Bytes_1A0B571C_E210_4C16_967B_C63BB5788B3C) },
    { be_const_key(Set_Receive_Invert, 10), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Invert_49AAF0A0_9F21_47C4_B1F1_77AE39FB19C8) },
    { be_const_key(Set_Hardware_Flow_Control, 19), be_const_ctype_func(Berry_Serial_Class_Set_Hardware_Flow_Control_453B5627_203D_4256_954D_95E794FDFF0C) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_Serial_Class_Peek_ED4BF42A_425F_4A48_88BD_2EE70CF119EE) },
    { be_const_key(_p, 15), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_Serial_Class_Write_3B75067D_2946_4E38_B9C0_15BA2FDE843B) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Serial_Class_Set_Mode_3226982C_E162_4304_B897_C487D7483791) },
    { be_const_key(Begin, 9), be_const_ctype_func(Berry_Serial_Class_Begin_BF6329B4_AB40_4303_A837_9CF6B754FFCF) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_Serial_Class_Flush_38F2A6A5_E70F_4BB1_AF04_E28F2E1B5789) },
    { be_const_key(End, 8), be_const_ctype_func(Berry_Serial_Class_End_CF09593D_EAD5_4652_8F37_21C0B3B2812D) },
    { be_const_key(Set_Receive_Buffer_Size, -1), be_const_ctype_func(Berry_Serial_Class_Set_Receive_Buffer_Size_2D0D8A34_5804_437C_972D_1D39BF0EB3CA) },
    { be_const_key(Write_String, -1), be_const_ctype_func(Berry_Serial_Class_Write_String_33BCEC5A_B6F7_439C_9AA8_2BE8A3316E1F) },
    { be_const_key(Set_Transmit_Buffer_Size, 1), be_const_ctype_func(Berry_Serial_Class_Set_Transmit_Buffer_Size_83BA4501_12EE_4D77_B061_2C5C51A9F0FF) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_Serial_Class_Available_EFC0D778_F9D2_4397_9ECE_681A44A6B1EA) },
    { be_const_key(Set_Baud_Rate, -1), be_const_ctype_func(Berry_Serial_Class_Set_Baud_Rate_DCB8CECC_912A_416C_8238_8202A402DEBF) },
    { be_const_key(Available_For_Write, -1), be_const_ctype_func(Berry_Serial_Class_Available_For_Write_090F4DB2_4F35_40DE_8AA5_CCC55AFE4C36) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_Serial_Class_Read_7CC66DB6_93A7_4323_9ED4_DC65FD979B67) },
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
