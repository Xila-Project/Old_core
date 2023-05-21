#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_BF77ED45_1642_4AC6_B1DA_2C6D08429563) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_130E1C44_BD31_474A_B32A_0FF9BEA7AC1C) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_AB047A65_1B9A_4621_BCED_47E6B87C8EB4) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_5E38C808_CF19_4A8E_9897_60EAA1578F3F) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_87E30C3D_98A6_4F59_BDDE_616D64B8884A) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_87932434_6CD0_4DAC_8A49_D60C151D10BF) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_088F6C77_FD1F_4816_876C_D30BCBE5D4AC) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_505AD4D0_27FF_4931_930B_94D485121151) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_D039745B_7312_4B08_9DAE_EC1F70790656) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_8CA5A531_3B1B_4C76_A2EE_353FF748180E) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_552FBF9B_310F_4DE7_B944_5C2E638614D3) },
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
