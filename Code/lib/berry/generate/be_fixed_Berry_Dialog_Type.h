#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_3C463E11_B373_412A_93B0_3733140178C4) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_F4FAA918_4352_4D26_B10C_0DA4A7ECBB70) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_FC9D15B8_C962_4D3A_B0DB_F46733D55DB7) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_A0CCA7E9_D420_437D_8DD8_F9790E35E166) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_EF9A2201_BC15_4F98_A0FE_D594C4FC92B2) },
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
