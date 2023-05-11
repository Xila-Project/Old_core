#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_20DFC57F_55BD_4882_8391_475FEC45F19C) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_E7F432FD_94CA_4F41_A4C8_B8358BF5918F) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_116BA4C8_53C9_4D1A_8D1D_8CAC24A9D528) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_2DB05979_B9A9_49F6_9B67_C6690514F8C4) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_2D6DA281_7E07_4835_A7C3_EE92F633EF38) },
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
