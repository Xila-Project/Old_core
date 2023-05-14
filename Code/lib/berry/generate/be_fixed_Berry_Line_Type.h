#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_C2FBE02C_63CC_493F_9C31_7AA77DF4F3F7) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_3647695C_8599_40DE_AF0B_716FE88F6B7C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_95908CFD_75C9_47E5_8781_CEF2924209D6) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_44859A90_5823_4D40_AC1B_93FF17E61C96) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_0061CFE2_476B_4B54_BE2D_259A54C54C2D) },
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
