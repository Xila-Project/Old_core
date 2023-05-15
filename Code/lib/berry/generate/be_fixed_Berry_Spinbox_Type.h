#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_F5C22A82_6205_4437_826A_C68703ABBEDE) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_0B1786E9_FA68_4A81_BF08_0C964E8A8665) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_B9CFF065_CF50_4994_8651_AF1DA2628379) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_11B175A4_EF3F_420E_9AA9_CCF690894346) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_F8A88BE9_625E_4C4C_9778_E13520147C6F) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_7F250DC8_F67E_474F_AFB7_2311841C234A) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_D112115E_9377_440B_A1C4_8E83F4A3352B) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_D157A301_370A_4E2B_A7C6_F2C1716793ED) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_33293DE3_B6F4_48C8_B767_65B598AF2B48) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_17BB9CBF_249E_4E47_A2AF_24BA399997D4) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_F6DC0913_0080_4F41_ABC8_C472C905B080) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_62D5FB44_2B06_4C84_8D89_338DC8F4D45B) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_5C7F53CA_4BC0_4B47_9B1F_455AD98C847B) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_905C7B93_B051_494C_9864_2E7EF2CBEC06) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_C1FD90E8_6413_4AA0_8D90_028EB6BDC64D) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_20FF6B2A_443C_49BF_A754_52A2A9ACEB69) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_47B42B36_6555_422E_AA83_7D4F90B2687A) },
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
