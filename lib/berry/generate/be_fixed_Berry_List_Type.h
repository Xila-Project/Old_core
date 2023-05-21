#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_D742DAC7_F8BE_4A46_A0E6_EC7A1F3DB8AA) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_B69EA0A3_BEDC_4D3F_93E5_B4CE60EFD65E) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_7485A03A_0AC7_43E3_8C74_7F090C6CCC38) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_F5E90F27_0560_41AC_A3FB_79C105B061A5) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_79F13842_3972_4D42_B257_3686B697ECF5) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_F4399F2D_BD74_4436_AD6D_7E909FCF0D87) },
    { be_const_key(_p, 0), be_const_var(0) },
};

static be_define_const_map(
    Berry_List_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_List_Type,
    1,
    (bclass *)&Berry_Object_Type,
    List_Type
);
