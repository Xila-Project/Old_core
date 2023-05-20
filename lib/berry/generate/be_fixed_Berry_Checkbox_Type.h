#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_503E3119_9171_4F0B_A2A2_0102E36535DD) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_56C05182_58B5_40F0_B3D1_26E3849E1719) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_9E61D55A_C458_4DB5_B119_AE76DA612ACA) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_D37BDC2B_A7FD_43B7_9862_A4EC5E52BA5D) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_A9326CAB_053C_4DDD_8A3D_B1F72920DB13) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_630205AB_5536_4506_9E43_81DC4F159C13) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Checkbox_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Checkbox_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Checkbox_Type
);
