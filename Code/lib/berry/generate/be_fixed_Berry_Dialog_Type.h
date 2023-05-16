#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_279CF3A0_8D95_48ED_9067_AB65C7D65CE7) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_DF86B761_C585_4C43_AEB7_BF9BFC361260) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_4EED2060_4440_4068_967E_8389A35AD2A9) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_F36520D8_7103_4FE2_9F8B_6FEB9A556FAF) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_66F1EF97_0FA8_4D45_B8E3_346D896AC89F) },
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
