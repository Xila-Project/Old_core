#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_21C31403_DCDE_4A57_A96E_F1EAFB43165B) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_52CDC3A6_DF5C_4C4F_8B29_0D4F5832B08A) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_A5694E46_C592_4D72_AC74_8069B1E108D8) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_D7544E8D_FD4C_432F_84F1_CC0BD7DAD3B4) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_F6100A29_8A56_4786_B86C_4FDC0C52A557) },
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
