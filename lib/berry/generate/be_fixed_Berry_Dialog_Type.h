#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_7C151864_B7D3_4C59_8D3E_61E4B41EED42) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_7F39A5F9_B5DE_4BF1_81CB_51BC68BBFA61) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_4C78D03E_2C72_4F94_8989_CEC71739897D) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_0742C718_7656_43A6_98F3_EEE032A02A0F) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_B8A9F7A3_CD0B_4D15_B33F_9A8B5B5D6D87) },
};

static be_define_const_map(
    Berry_Dialog_Type_map,
    6
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Dialog_Type,
    1,
    (bclass *)&Berry_Window_Type,
    Dialog_Type
);
