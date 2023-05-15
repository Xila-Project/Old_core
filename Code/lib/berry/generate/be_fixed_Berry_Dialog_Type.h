#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_3809D9F8_7B31_423B_BB8D_E03C9027217E) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_EC197190_77FF_462D_B5D4_32A5CF73EAE5) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_C151E041_4CD5_4692_BD0D_F37200914091) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_E0452C4A_E974_4738_A70C_4D824C155DCA) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_2D5DEF70_D3F1_4031_AB47_CD24A115A3F2) },
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
