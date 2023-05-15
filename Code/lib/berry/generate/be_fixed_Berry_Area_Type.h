#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_90B10ED6_71A6_40DE_8562_79632ABD6E65) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_722252EA_AECA_428B_BD0A_6906ED56C8F9) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_EB1DA68D_4741_4AE4_9F1A_FA284334EEE9) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_4C27F4A7_4FA6_4CD6_876B_B74516B0B96F) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_99B3A77C_70F0_4306_8BDB_98202DA1193F) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_97E67DB9_741A_44CF_BE43_857BE8B736F9) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_C7F14EAA_BF4C_4054_A163_9E3BAA9E2E44) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_C9E363FF_8A0E_4DE5_9E66_E815EBB40EE7) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_E689C183_FF79_4C53_B69C_F1421AB74D9E) },
};

static be_define_const_map(
    Berry_Area_Type_map,
    10
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Area_Type,
    1,
    NULL,
    Area_Type
);
