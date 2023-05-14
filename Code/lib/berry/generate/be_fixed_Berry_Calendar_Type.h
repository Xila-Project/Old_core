#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_28E86DCA_D5F9_4625_A756_EA5CCCE414BD) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_1158C536_B453_4643_9E1A_B7600D94D1D6) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_87C5568C_ADC9_46C2_8319_11F81C7AC7C8) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_DB37765A_BDB8_4D11_8525_292493A7461E) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_516F9FB4_0B91_48C9_88C7_E4995ADBC3B3) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_10D865B6_F1E2_4335_93D9_89079432CC74) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_C7B7B43E_208D_4E46_84B8_8BB0DCF424A8) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_80242DC7_8A5D_4F61_9E61_23E081BC0EF7) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_8FD17C3C_0ACA_4725_9A00_FBAE52537992) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_EBF02405_8BD1_4D2B_ADA0_E9E687569503) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_26839B4C_2C8C_4DFE_8ABE_ECD0A13DF84B) },
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
