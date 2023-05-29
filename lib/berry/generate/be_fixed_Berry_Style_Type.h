#include "be_constobj.h"

static be_define_const_map_slots(Berry_Style_Type_map) {
    { be_const_key(Set_Opacity, 5), be_const_ctype_func(Berry_Style_Class_Set_Opacity_E42AC2D8_9BCD_4952_A585_3BAB9A391C4D) },
    { be_const_key(Set_Background_Opacity, 75), be_const_ctype_func(Berry_Style_Class_Set_Background_Opacity_C94BE840_5091_4598_9CA9_7AB7074CDB14) },
    { be_const_key(Set_Line_Width, 55), be_const_ctype_func(Berry_Style_Class_Set_Line_Width_20541CDE_411B_468E_B217_D3770B00C14C) },
    { be_const_key(Set_Base_Direction, -1), be_const_ctype_func(Berry_Style_Class_Set_Base_Direction_60D7F118_0E15_48C6_BF02_632D2572728A) },
    { be_const_key(Set_Line_Dash_Width, -1), be_const_ctype_func(Berry_Style_Class_Set_Line_Dash_Width_959CFB70_BF7E_4AFA_97D8_2CCE92940A83) },
    { be_const_key(Set_Line_Dash_Gap, 35), be_const_ctype_func(Berry_Style_Class_Set_Line_Dash_Gap_F78D57F5_A37D_44CD_BFA1_A34C9D27CBD9) },
    { be_const_key(Reset, -1), be_const_ctype_func(Berry_Style_Class_Reset_72F9E955_6DE9_4F15_B593_033FB345FCBA) },
    { be_const_key(Set_Pad_Gap, 78), be_const_ctype_func(Berry_Style_Class_Set_Pad_Gap_B5A36DB4_A3CA_43F1_81D8_B011CD17A237) },
    { be_const_key(Set_Translate_X_, -1), be_const_ctype_func(Berry_Style_Class_Set_Translate_X_75A56B98_9064_489B_A0F2_E8E2BB9AAA86) },
    { be_const_key(Set_Background_Color, -1), be_const_ctype_func(Berry_Style_Class_Set_Background_Color_725C14B6_9CDA_426C_B95F_A8106D624444) },
    { be_const_key(Set_Grid_Cell_Column_Position, 88), be_const_ctype_func(Berry_Style_Class_Set_Grid_Cell_Column_Position_7A4A23BE_D77E_4279_ABD8_5A3FB5368467) },
    { be_const_key(Set_Background_Image_Recolor, -1), be_const_ctype_func(Berry_Style_Class_Set_Background_Image_Recolor_42BD9265_F04B_450C_9B00_381599A75F05) },
    { be_const_key(Set_Flex_Main_Place, 48), be_const_ctype_func(Berry_Style_Class_Set_Flex_Main_Place_6DB28690_34E2_4C5C_890C_A1AA4317EC0F) },
    { be_const_key(Set_Animation_Time, -1), be_const_ctype_func(Berry_Style_Class_Set_Animation_Time_19A3C1E9_79AB_45F6_BCB0_C777B6176521) },
    { be_const_key(Set_Background_Image_Tiled, 76), be_const_ctype_func(Berry_Style_Class_Set_Background_Image_Tiled_BA7B1A77_0652_4DE9_A060_54120548E358) },
    { be_const_key(Set_Background_Gradient_Direction, -1), be_const_ctype_func(Berry_Style_Class_Set_Background_Gradient_Direction_2AEB4F29_57BC_4BA6_AC28_0EFD634AA521) },
    { be_const_key(Set_Outline_Color, -1), be_const_ctype_func(Berry_Style_Class_Set_Outline_Color_3D466E1A_48CE_4174_8F89_D708DC18D575) },
    { be_const_key(Set_Background_Main_Stop, 65), be_const_ctype_func(Berry_Style_Class_Set_Background_Main_Stop_84C5B8B1_381C_44FB_B5AA_52495303B6B9) },
    { be_const_key(Set_Outline_Opacity, 66), be_const_ctype_func(Berry_Style_Class_Set_Outline_Opacity_2EF299BE_BB15_41C4_8471_97AFC08192DA) },
    { be_const_key(Remove_Property, -1), be_const_ctype_func(Berry_Style_Class_Remove_Property_546F29F6_3462_4A37_BFE6_200838249E57) },
    { be_const_key(Set_Grid_Row_Descriptor_Array, 67), be_const_ctype_func(Berry_Style_Class_Set_Grid_Row_Descriptor_Array_D5EA5D1E_BB9B_43CC_92F9_B78E9D1A3CD6) },
    { be_const_key(Set_Background_Dither_Mode, 58), be_const_ctype_func(Berry_Style_Class_Set_Background_Dither_Mode_46154D27_5044_48B2_8D35_2E3929330259) },
    { be_const_key(Set_Border_Width, 93), be_const_ctype_func(Berry_Style_Class_Set_Border_Width_577F4880_F2DC_4E8C_B42E_F4F11F144635) },
    { be_const_key(Set_Color_Filter_Descriptor, 90), be_const_ctype_func(Berry_Style_Class_Set_Color_Filter_Descriptor_A3BA62C2_F261_475A_B455_FA8F43A80EC1) },
    { be_const_key(Register_Property, -1), be_const_ctype_func(Berry_Style_Class_Register_Property_E2CF1491_A0D1_4B77_B54A_F770B78D2364) },
    { be_const_key(Set_Arc_Opacity, -1), be_const_ctype_func(Berry_Style_Class_Set_Arc_Opacity_1E130EE8_B047_49E5_A3AD_88BBB8343BD1) },
    { be_const_key(Set_Transform_Height, 10), be_const_ctype_func(Berry_Style_Class_Set_Transform_Height_FE34FF7C_B617_4B57_B276_0A0D9063B844) },
    { be_const_key(Set_Border_Color, -1), be_const_ctype_func(Berry_Style_Class_Set_Border_Color_5D2390DB_82F9_4ACB_87FE_FE3E5A6AA94A) },
    { be_const_key(Set_Border_Opacity, -1), be_const_ctype_func(Berry_Style_Class_Set_Border_Opacity_D4C125CA_6130_43DD_A4E5_4F822E607FE1) },
    { be_const_key(Set_Maximum_Height, -1), be_const_ctype_func(Berry_Style_Class_Set_Maximum_Height_720E670F_BF7B_4237_BE51_87CC300EF35E) },
    { be_const_key(Set_Background_Gradient_Color, 0), be_const_ctype_func(Berry_Style_Class_Set_Background_Gradient_Color_5D029DEE_37B7_4F73_B9D0_C81541E42013) },
    { be_const_key(Set_Flex_Flow, -1), be_const_ctype_func(Berry_Style_Class_Set_Flex_Flow_90868E1D_94A3_4DE8_A7AC_27885CB04F8A) },
    { be_const_key(Set_Background_Image_Recolor_Opacity, -1), be_const_ctype_func(Berry_Style_Class_Set_Background_Image_Recolor_Opacity_781CCB2B_E2C3_49F1_8C79_A68262E6CE09) },
    { be_const_key(Set_Grid_Column_Descriptor_Array, 6), be_const_ctype_func(Berry_Style_Class_Set_Grid_Column_Descriptor_Array_7C344CAB_5EA9_4BD9_9250_2ECC03AF21D5) },
    { be_const_key(Set_Minimum_Width, -1), be_const_ctype_func(Berry_Style_Class_Set_Minimum_Width_38F8886D_E9C7_447E_ADB3_C8DFEDED3047) },
    { be_const_key(Initialize, -1), be_const_ctype_func(Berry_Style_Class_Initialize_086BD7F9_E41C_4D04_B24B_1F2AF8072AAB) },
    { be_const_key(Set_Border_Post, -1), be_const_ctype_func(Berry_Style_Class_Set_Border_Post_8BE257C6_6ACB_4CA4_A7EB_218B052213A5) },
    { be_const_key(Set_Grid_Cell_Column_Span, 69), be_const_ctype_func(Berry_Style_Class_Set_Grid_Cell_Column_Span_C46F91D1_09C8_4B66_AB7E_7593B6FC0596) },
    { be_const_key(Set_Line_Rounded, 14), be_const_ctype_func(Berry_Style_Class_Set_Line_Rounded_ACE6FD38_4F1B_4B84_9526_69069610C5C9) },
    { be_const_key(Set_Shadow_Offset_Y, 4), be_const_ctype_func(Berry_Style_Class_Set_Shadow_Offset_Y_B54E5C16_1229_4521_974D_95521D70236F) },
    { be_const_key(Set_Alignment, -1), be_const_ctype_func(Berry_Style_Class_Set_Alignment_B2B91E18_25D0_4A9D_A13B_40A0BD19D681) },
    { be_const_key(Set_Flex_Cross_Place, 32), be_const_ctype_func(Berry_Style_Class_Set_Flex_Cross_Place_9BB45323_700D_4630_844B_322308C1777C) },
    { be_const_key(Set_Image_Recolor_Opacity, -1), be_const_ctype_func(Berry_Style_Class_Set_Image_Recolor_Opacity_B1AA0C11_1827_4207_ADAC_989359F52FA4) },
    { be_const_key(Set_Grid_Row_Alignment, 97), be_const_ctype_func(Berry_Style_Class_Set_Grid_Row_Alignment_5E812959_0726_44E1_B393_D5F52702BD35) },
    { be_const_key(Set_Line_Color, 18), be_const_ctype_func(Berry_Style_Class_Set_Line_Color_D82F4E19_4313_4717_B408_C994E7BE5956) },
    { be_const_key(Set_Line_Opacity, 43), be_const_ctype_func(Berry_Style_Class_Set_Line_Opacity_8A5DF706_9C28_4A9F_82BA_D80D6506B81C) },
    { be_const_key(Set_Flex_Grow, 1), be_const_ctype_func(Berry_Style_Class_Set_Flex_Grow_67C8AA7E_25A8_4AA2_82FC_DC15953E38B0) },
    { be_const_key(Set_Y, 24), be_const_ctype_func(Berry_Style_Class_Set_Y_64EB2E29_A44C_45EB_972D_7782BF44423A) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Style_Class_Set_Height_3C1F2B90_1925_40AF_A989_1EEDCB5E52F7) },
    { be_const_key(Set_Pad_Top, -1), be_const_ctype_func(Berry_Style_Class_Set_Pad_Top_09BC59ED_7C8A_48D8_BC98_6BDD05E9F43A) },
    { be_const_key(Set_Arc_Rounded, -1), be_const_ctype_func(Berry_Style_Class_Set_Arc_Rounded_828E9936_B6D2_4DE5_B490_833A5A895777) },
    { be_const_key(Set_Clip_Corner, -1), be_const_ctype_func(Berry_Style_Class_Set_Clip_Corner_6FC20E91_3CC5_42D7_83E2_03C1CD8C701E) },
    { be_const_key(Set_Maximum_Width, 36), be_const_ctype_func(Berry_Style_Class_Set_Maximum_Width_B5133737_7B72_4ABB_9520_3FFC870896FE) },
    { be_const_key(Set_Text_Color, 50), be_const_ctype_func(Berry_Style_Class_Set_Text_Color_1C7DAD41_26F5_473C_AECB_DC80AA6313EF) },
    { be_const_key(Set_Transform_Width, -1), be_const_ctype_func(Berry_Style_Class_Set_Transform_Width_518AD76E_3E3A_48F1_988A_84BEB0B74F58) },
    { be_const_key(Set_Pad_Row, 84), be_const_ctype_func(Berry_Style_Class_Set_Pad_Row_509806D6_7CFC_4716_A0C3_BB861580F363) },
    { be_const_key(Set_Text_Line_Space, -1), be_const_ctype_func(Berry_Style_Class_Set_Text_Line_Space_50793E9B_8BD7_43DA_B1F9_D629BFF7DC14) },
    { be_const_key(Set_Arc_Color, -1), be_const_ctype_func(Berry_Style_Class_Set_Arc_Color_91341D8A_CEA6_4271_B032_508FD7DB41A0) },
    { be_const_key(Set_Translate_Y, 101), be_const_ctype_func(Berry_Style_Class_Set_Translate_Y_79366047_A948_486C_9E54_F2251E4A9E2C) },
    { be_const_key(Set_Radius, 21), be_const_ctype_func(Berry_Style_Class_Set_Radius_4A3EA245_2602_42F4_B233_DEAFB4A837B7) },
    { be_const_key(Set_Background_Gradient_Stop, -1), be_const_ctype_func(Berry_Style_Class_Set_Background_Gradient_Stop_A2FC87DA_FA2E_4DFA_93A6_AB75ED6EE65B) },
    { be_const_key(Set_Minimum_Height, -1), be_const_ctype_func(Berry_Style_Class_Set_Minimum_Height_91BE0442_C6E5_4A4C_9D67_444CAACA5DA4) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Style_Class_Set_Width_3D676013_BF2D_436C_875C_11D794811EB7) },
    { be_const_key(Set_Grid_Cell_X__Alignment, 27), be_const_ctype_func(Berry_Style_Class_Set_Grid_Cell_X_Alignment_B0B1B561_473B_46DA_AE8D_ABE3A3C3B969) },
    { be_const_key(Set_Pad_Bottom, -1), be_const_ctype_func(Berry_Style_Class_Set_Pad_Bottom_97B803F1_053E_47DD_B1CF_4E4C4AE0A972) },
    { be_const_key(Set_Transform_Zoom, -1), be_const_ctype_func(Berry_Style_Class_Set_Transform_Zoom_51A16CE4_6924_4286_92BE_B911316B1B23) },
    { be_const_key(Set_Shadow_Spread, -1), be_const_ctype_func(Berry_Style_Class_Set_Shadow_Spread_A6E7B0A6_C25B_46C4_83DA_3056413B1BDC) },
    { be_const_key(Set_Shadow_Width, -1), be_const_ctype_func(Berry_Style_Class_Set_Shadow_Width_717D13A9_DD84_4303_BAB6_FC65D165C0C6) },
    { be_const_key(Set_Grid_Column_Alignment, 13), be_const_ctype_func(Berry_Style_Class_Set_Grid_Column_Alignment_7778D922_17F5_4548_9068_532849777BD6) },
    { be_const_key(Set_Layout, 11), be_const_ctype_func(Berry_Style_Class_Set_Layout_6D5E1986_784C_4645_8E6A_B928B6380580) },
    { be_const_key(Set_Text_Alignment, -1), be_const_ctype_func(Berry_Style_Class_Set_Text_Alignment_D3F90792_51E7_43F7_B495_583923A016CA) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Style_Class_Initialize_1C3625E0_BED1_428A_9597_258924AF57A6) },
    { be_const_key(Set_Border_Side, -1), be_const_ctype_func(Berry_Style_Class_Set_Border_Side_78B68CA9_2141_44F0_AA8D_29F884461085) },
    { be_const_key(Set_Pad_All, -1), be_const_ctype_func(Berry_Style_Class_Set_Pad_All_5377D8B7_C592_41FB_B770_6A76AE1E7CF3) },
    { be_const_key(Set_Text_Letter_Space, -1), be_const_ctype_func(Berry_Style_Class_Set_Text_Letter_Space_9AFFDAB6_E254_4467_AC35_AAD206D7018F) },
    { be_const_key(Set_Color_Filter_Opacity, -1), be_const_ctype_func(Berry_Style_Class_Set_Color_Filter_Opacity_536B884C_27ED_48DD_83A2_A460B8176308) },
    { be_const_key(Set_Pad_Left, -1), be_const_ctype_func(Berry_Style_Class_Set_Pad_Left_FC5D8E51_F84A_4EB2_8A37_FC9E407A1DC2) },
    { be_const_key(Set_Image_Opacity, 56), be_const_ctype_func(Berry_Style_Class_Set_Image_Opacity_0AC0AE32_E592_4061_B80F_4FF2743FAB64) },
    { be_const_key(Set_Background_Image_Opacity, -1), be_const_ctype_func(Berry_Style_Class_Set_Background_Image_Opacity_8A0BF0BF_6341_4A04_A9C0_0EA251BD6ED2) },
    { be_const_key(Set_Grid_Cell_Row_Span, -1), be_const_ctype_func(Berry_Style_Class_Set_Grid_Cell_Row_Span_9EA90603_6258_41EE_AC49_69690B50857E) },
    { be_const_key(Set_Blend_Mode, 40), be_const_ctype_func(Berry_Style_Class_Set_Blend_Mode_34ED476A_0987_4373_ADEB_9574B0D97581) },
    { be_const_key(Set_Outline_Width, 3), be_const_ctype_func(Berry_Style_Class_Set_Outline_Width_12737876_D143_4465_83C4_7F6263504906) },
    { be_const_key(Set_Flex_Track_Place, 9), be_const_ctype_func(Berry_Style_Class_Set_Flex_Track_Place_4A0B9655_01E6_4225_B9C8_2952FDA1379C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Animation_Speed, -1), be_const_ctype_func(Berry_Style_Class_Set_Animation_Speed_5664A109_2C2B_4C34_8C1C_36B67E3920D3) },
    { be_const_key(Set_Pad_Column, -1), be_const_ctype_func(Berry_Style_Class_Set_Pad_Column_B87CFDD5_A1A6_44A4_AD62_3599A3F216B2) },
    { be_const_key(Set_Text_Decor, -1), be_const_ctype_func(Berry_Style_Class_Set_Text_Decor_C3A6C0E0_BC76_4963_A6EA_035B5D6285D7) },
    { be_const_key(Set_Shadow_Offset_X_, -1), be_const_ctype_func(Berry_Style_Class_Set_Shadow_Offset_X_394D97B2_B1B0_40AA_84F8_DB7A39F5C0FC) },
    { be_const_key(Set_Size, -1), be_const_ctype_func(Berry_Style_Class_Set_Size_4D9916B3_826D_4260_A9CB_C50AE03A11CE) },
    { be_const_key(Set_Shadow_Opacity, -1), be_const_ctype_func(Berry_Style_Class_Set_Shadow_Opacity_3FB1B866_120F_437B_BEDE_C9B57EF3E86D) },
    { be_const_key(deinit, 77), be_const_ctype_func(Berry_Style_Class_Deinitialize_D1246B58_5B2F_4CD6_979A_348680EC55A1) },
    { be_const_key(Set_Arc_Width, 87), be_const_ctype_func(Berry_Style_Class_Set_Arc_Width_3856C1AA_7B4D_41FA_8A73_7E251EC3732F) },
    { be_const_key(Set_Pad_Horizontal, 19), be_const_ctype_func(Berry_Style_Class_Set_Pad_Horizontal_838151DB_10A9_4D22_BAE2_C3CFDE543F55) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Style_Class_Set_X_043D388B_D894_4300_B728_7E7D604EA7F7) },
    { be_const_key(Set_Pad_Right, -1), be_const_ctype_func(Berry_Style_Class_Set_Pad_Right_C6D1C5AF_35D7_4481_8481_1B4F244694ED) },
    { be_const_key(Set_Shadow_Color, 73), be_const_ctype_func(Berry_Style_Class_Set_Shadow_Color_E1F9FF5E_775E_45D3_B53C_F87FC126E9BD) },
    { be_const_key(Set_Grid_Cell_Y_Alignment, -1), be_const_ctype_func(Berry_Style_Class_Set_Grid_Cell_Y_Alignment_055D61A6_5917_44D3_AAEC_1FB61C510498) },
    { be_const_key(Set_Image_Recolor, -1), be_const_ctype_func(Berry_Style_Class_Set_Image_Recolor_A4F7D3A4_4892_4BDE_AB17_3015909C6DCE) },
    { be_const_key(Set_Grid_Cell_Row_Position, 22), be_const_ctype_func(Berry_Style_Class_Set_Grid_Cell_Row_Position_4DA2AD0C_F05D_4AF8_A876_174B55F7BF9D) },
    { be_const_key(Set_Text_Opacity, -1), be_const_ctype_func(Berry_Style_Class_Set_Text_Opacity_DA1BC69A_A7E8_4C69_B2E6_EF592639BB51) },
    { be_const_key(Set_Transform_Angle, -1), be_const_ctype_func(Berry_Style_Class_Set_Transform_Angle_2EBEA37C_A3A2_432C_9B4D_8529195E67CA) },
    { be_const_key(Set_Outline_Pad, -1), be_const_ctype_func(Berry_Style_Class_Set_Outline_Pad_ABE8827B_E858_4546_8E00_80911CB514E6) },
    { be_const_key(Set_Pad_Vertical, -1), be_const_ctype_func(Berry_Style_Class_Set_Pad_Vertical_A474B863_2D6F_42B5_992F_4CC990E2F086) },
};

static be_define_const_map(
    Berry_Style_Type_map,
    103
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Style_Type,
    1,
    NULL,
    Style_Type
);
