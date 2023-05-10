#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_DF618F73_325D_453A_B96D_6E428BE54C1E) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_6DA866D7_0494_48F2_9EAB_FD8408B8F519) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_C4999AAF_8E0F_431E_9C60_48D64BC10E57) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_2E799BD5_7767_4E1D_BBC1_24D89B8DE067) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_1494948F_CAEA_44C4_A8E0_B9B82064CA09) },
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
