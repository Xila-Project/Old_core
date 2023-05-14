#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_A767A263_A15B_4551_86F0_C74B82B4E664) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_F72E8220_4399_4308_B41A_FD664BA4ADDA) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_40DB55DF_51AB_4B50_BF49_F1DB272AE3BA) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_7D72FA28_2B79_48DD_9738_25776BFB77F4) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_D814E74F_F00B_4750_AD5E_5A5EF6C5A31D) },
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
