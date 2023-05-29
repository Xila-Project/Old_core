#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_984AD78F_DA9E_43C2_8E0B_2765D70D7997) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_259B3430_7F0C_4C90_AA30_5A81413C9080) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_E5CC4012_B3B6_4483_8417_617D473A44C2) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_4717FA36_B995_4481_9898_13775E96A408) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_F6162007_501F_4E13_AC17_A6635989F0FC) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_C40F7141_3BBD_4653_B616_BE8554E35BDA) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_AADE68FD_7A0B_48F4_AB83_0DEB74620CDA) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_7692D459_C3ED_4F82_84FD_F32A932376FB) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_13955574_21A2_464C_8531_B5C28838C284) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_48C39DD1_B4B4_4DC6_9F27_99A890114395) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_63408B65_7BBA_4E1E_B6B5_67144D59B841) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_C2E5780B_AC7A_4931_A006_43F89D9BA446) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_E90E0B31_9081_459F_ABB3_851CFD03DD61) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_C55747F6_9C34_47FC_B2BF_44676BCDCA9E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_A2B5DD09_DD6E_464C_B4E7_2C4ED55CF405) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_35BD7943_F5C0_4634_81CA_86C4FBB9677B) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_B550B84D_4E0F_40FE_83EA_DA9994317886) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_9A89125E_C903_4E47_8DCB_B181C337C9DC) },
};

static be_define_const_map(
    Berry_Image_Type_map,
    19
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Image_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Image_Type
);
