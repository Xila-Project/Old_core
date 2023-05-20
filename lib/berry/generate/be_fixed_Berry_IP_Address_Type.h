#include "be_constobj.h"

static be_define_const_map_slots(Berry_IP_Address_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_IP_Address_Class_Initialize_124412B2_62CA_43D1_B42E_A13064216739) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_IP_v4, -1), be_const_ctype_func(Berry_IP_Address_Class_Is_IP_v4_64ED0E3D_E87E_4A9C_B022_F814310D94AE) },
    { be_const_key(To, 0), be_const_ctype_func(Berry_IP_Address_Class_To_CD83D91F_1680_454B_893A_17C14E0176DD) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_IP_Address_Class_Operator_AF24A191_EA52_4136_9259_F7192A660177) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_IP_Address_Class_Deinitialize_06453CD5_7FCE_4883_8F30_D2AFD603EE4D) },
    { be_const_key(Set_IP_Version, 1), be_const_ctype_func(Berry_IP_Address_Class_Set_IP_Version_E98CDEFC_495C_44F2_A9B2_9F15B2DDEAC9) },
};

static be_define_const_map(
    Berry_IP_Address_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_IP_Address_Type,
    1,
    NULL,
    IP_Address_Type
);
