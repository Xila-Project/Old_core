#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_55014262_DC2F_4A2A_9DFB_28FDDBB632BA) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_421F8A78_EA3C_4835_A571_DA7226C45992) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_8B22A3F3_5B9C_4ADE_8B40_07B92E5783AA) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_29A2A45D_B55A_470E_8CDB_A103371AC1BF) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_6991D908_C27E_4DA7_B6E3_666D7B936824) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_69F997FB_2D2D_45A6_AFB5_33A08268171F) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_B532FE0B_BA04_4E3C_8110_3C7EEBC70FDA) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_8D728161_3358_41E4_860C_E27AA60C0D4B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_CE903334_C8E4_4A99_8C63_E3F2E5246461) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_C721CB67_3B19_4AFC_AFDF_83D78CD69126) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_10F18112_9701_4E3A_967C_18334BEE1A32) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_78D4FEA7_4865_430A_9301_113A636CBA73) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_5D8B5A4A_EF05_40D6_9BE5_8F9C84D6CA49) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_2E47496A_475F_45DE_A06A_07B2CA232CE9) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_D203A4A9_D10A_404E_B656_9E1594B3E15B) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_636D4640_CBC6_4151_9DCF_C7B4B4BF08DE) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_10332C58_D174_4623_84BA_D95C86E2C183) },
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
