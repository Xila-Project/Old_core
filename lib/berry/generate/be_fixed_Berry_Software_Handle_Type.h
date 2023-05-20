#include "be_constobj.h"

static be_define_const_map_slots(Berry_Software_Handle_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Software_Handle_Class_Deinitialize_73083E8A_BFA3_4EA6_BDB4_8A00E3A1933E) },
    { be_const_key(Create_Instance, -1), be_const_ctype_func(Berry_Software_Handle_Class_Create_Instance_0A0D4EF8_9803_4053_A411_8AD056A76634) },
    { be_const_key(Is_Equal, 6), be_const_ctype_func(Berry_Software_Handle_Class_Is_Equal_4C0B126E_6AC5_402C_AC8A_51F36AA8FF82) },
    { be_const_key(Get_Name, 5), be_const_ctype_func(Berry_Software_Handle_Class_Get_Name_CB2BBE09_C0B8_422D_8F2E_E40E1FA27085) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Software_Handle_Class_Initialize_4CE0BE03_2CB6_4BE8_9C70_AE0F476EFAA8) },
    { be_const_key(_X21_X3D, 4), be_const_ctype_func(Berry_Software_Handle_Class_Operator_9CB6D069_C3C2_4076_ADC3_DF85899ADEA8) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Software_Handle_Class_Operator_94A49035_145C_46C3_B049_89B757176CA2) },
};

static be_define_const_map(
    Berry_Software_Handle_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Software_Handle_Type,
    1,
    NULL,
    Software_Handle_Type
);
