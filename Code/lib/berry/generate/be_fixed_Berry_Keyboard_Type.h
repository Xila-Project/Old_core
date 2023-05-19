#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_F8F2AAD2_F68E_44EC_945D_E46012BE5E26) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_B135AC04_40A0_4D3A_B413_4C0CE08CE0E2) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_5F61BEAE_7B77_4008_9166_3DCC30FB0B36) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_3A805DE4_790A_4C49_B8FD_12A75DDA290E) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_00D97013_AA81_424E_B5B9_D6E2464E0DA7) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_CDDDA37C_4828_4DC0_B619_B71ACE15C911) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_66D299D3_A1F9_4C65_911B_BB65331ABC86) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_3137EAB6_3CFA_4ED1_B11E_8FAA0B66BA51) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_FAF4A338_20F1_479A_974A_E15BA2F6CD0B) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_5D3DAE17_B9C7_4EE0_9778_63EE3B1BE242) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_73CF21BC_7DB3_40C4_9099_B15B22BCFC61) },
};

static be_define_const_map(
    Berry_Keyboard_Type_map,
    12
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Keyboard_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Keyboard_Type
);
