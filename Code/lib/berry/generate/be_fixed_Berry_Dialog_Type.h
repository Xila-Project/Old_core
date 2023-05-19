#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_B4D76C57_1DCA_40FC_AD85_0B0B57C8B018) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_42D5CB5F_A564_4B90_816A_F9ACBFC7DC44) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_D89355FC_1486_46B6_997C_2C98E7D4159F) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_D7C76028_B39C_45D0_B91A_E2DA2F705969) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_1CCE6682_15C3_4B41_A1F6_D98CC56514B4) },
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
