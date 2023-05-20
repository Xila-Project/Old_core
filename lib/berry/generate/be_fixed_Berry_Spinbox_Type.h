#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_A9141027_B2FE_44E9_9559_96962A5577DA) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_1E3C447E_C3B5_4C35_8E36_0511BBD7C9A4) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_FDF64DAD_83CA_41CA_9D46_18110C42360B) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_70552667_BD48_45B2_9B05_35C6C1F81551) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_4BBF6B86_1827_4456_8709_2AB32CE9CD86) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_C1964DB3_CE30_4D36_9F38_CB5E4289D09C) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_CF4E5E07_A1CD_45F1_981E_2399292FE51C) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_A38DB964_15AB_4D6C_8553_8178DBBDD94B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_CA7239C1_24CF_4B2F_9BD9_B10229A4F830) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_44DAB2B8_A336_4C21_85F5_333C53C82A3D) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_09542B6E_2A72_4184_93F0_46CCEE058A68) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_BFAB3B06_F923_4C64_8074_22C1CB65A763) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_0842A0C2_DF0E_49E2_B9BC_83C8C813D759) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_FBF71693_CDCE_45EF_935B_166415710961) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_5BC620F5_9178_41FB_815C_378D7492F0A5) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_18ED5F8F_7334_4642_9F17_57BE33EE4311) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_7F41D91C_334B_4268_842E_2D219CDB8258) },
};

static be_define_const_map(
    Berry_Spinbox_Type_map,
    18
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Spinbox_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Spinbox_Type
);
