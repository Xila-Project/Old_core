#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_ED23D831_3258_4055_863A_8ADFDB766A5D) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_B9DD596D_C162_411E_B760_ED08AAE89BE6) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_66EFD8F2_FBA4_4531_8708_2E469B7E3793) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_22EDDD42_8963_4C0C_B116_2054144D9325) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_68E96DFD_C235_417F_B338_69FC87325A36) },
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
