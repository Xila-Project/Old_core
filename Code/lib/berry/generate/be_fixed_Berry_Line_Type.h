#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_6F91D24E_B202_4EB1_83F3_CF6EE65166C0) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_A6A173FD_2E4E_4060_92E8_C3DC0B981A50) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_4BD33FAD_DB26_4A59_937A_B129EAF989BE) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_DDCAD771_E61B_40D7_8724_2DF271225056) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_F3896893_DBFB_4CDA_8309_1EF598AF9903) },
};

static be_define_const_map(
    Berry_Line_Type_map,
    6
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Line_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Line_Type
);
