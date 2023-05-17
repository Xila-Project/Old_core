#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_D55B93E1_0A04_4297_8954_928565474AA1) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_F9B807F8_FA68_4120_9534_47C984588EBA) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_DE25BA84_0C47_46E2_8006_59A0616F7EFB) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_957727C6_E328_4B72_BF79_04628D620DD5) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_3C13D280_576C_4B4B_8799_961B4B84FAA4) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_35E771B0_551E_4560_BD0A_AEA185868F2E) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_B921370B_73A0_4C1F_9D2C_DA10D76F8EDC) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_CAF5AF61_ED28_4C46_933A_8E5F387996B9) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_2AF08B9D_FC21_47A0_9710_3466C291BCBB) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_E9811AEF_53D0_4CAD_8712_E29F482E48E0) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_FC077259_02EF_4151_BD93_F69229BF1EBB) },
};

static be_define_const_map(
    Berry_Calendar_Type_map,
    12
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Calendar_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Calendar_Type
);
