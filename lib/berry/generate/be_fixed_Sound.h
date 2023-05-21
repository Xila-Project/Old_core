#include "be_constobj.h"

static be_define_const_map_slots(m_libSound_map) {
    { be_const_key(Format_Most_Significant_Bit, 1), be_const_int(2) },
    { be_const_key(Format_Pulse_Code_Modulation, -1), be_const_int(6) },
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Sound_Class_Get_Volume_02221774_3AB9_44AE_B822_6D683A1111E2) },
    { be_const_key(Configuration_Type, -1), be_const_class(Berry_Configuration_Type) },
    { be_const_key(I2S_Configuration_Type, -1), be_const_class(Berry_I2S_Configuration_Type) },
    { be_const_key(Get_Pointer, 2), be_const_ctype_func(Berry_Sound_Class_Get_Pointer) },
    { be_const_key(Format_Standard, 14), be_const_int(0) },
    { be_const_key(Format_Right_Justified, -1), be_const_int(4) },
    { be_const_key(Format_Philips, -1), be_const_int(3) },
    { be_const_key(Stream_Type, -1), be_const_class(Berry_Stream_Type) },
    { be_const_key(I2S_Type, -1), be_const_class(Berry_I2S_Type) },
    { be_const_key(Save_Registry, -1), be_const_ctype_func(Berry_Sound_Class_Save_Registry_738867BC_16D5_40DC_8E0C_F2BA104CEDE0) },
    { be_const_key(Volume_Type, -1), be_const_class(Berry_Volume_Type) },
    { be_const_key(Mode_Receive_Transmit, 12), be_const_int(3) },
    { be_const_key(Mode_Receive, -1), be_const_int(2) },
    { be_const_key(Set_Volume, 20), be_const_ctype_func(Berry_Sound_Class_Set_Volume_F4FB64C8_726B_4EE7_85D8_60A2A1D7222B) },
    { be_const_key(Mode_Undefined, -1), be_const_int(0) },
    { be_const_key(Format_Left_Justified, 24), be_const_int(5) },
    { be_const_key(Volume_Configuration_Type, 8), be_const_class(Berry_Volume_Configuration_Type) },
    { be_const_key(File_Player_Type, 7), be_const_class(Berry_File_Player_Type) },
    { be_const_key(Load_Registry, -1), be_const_ctype_func(Berry_Sound_Class_Load_Registry_55D2B963_AEFB_4064_842D_640F394FC66F) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Sound_Class_Start_78A2F7C3_A0BD_41E8_844B_58B4982127F2) },
    { be_const_key(Create_Registry, 23), be_const_ctype_func(Berry_Sound_Class_Create_Registry_27E1EE46_CBCB_4F48_91A3_641063DDD436) },
    { be_const_key(WAV_Decoder_Type, -1), be_const_class(Berry_WAV_Decoder_Type) },
    { be_const_key(Mode_Transmit, 27), be_const_int(1) },
    { be_const_key(Stop, 16), be_const_ctype_func(Berry_Sound_Class_Stop_AB1B1F4F_74F5_4D4D_8999_73A60B2D3253) },
    { be_const_key(Decoder_Type, 17), be_const_class(Berry_Decoder_Type) },
    { be_const_key(Format_Least_Significant_Bit, -1), be_const_int(1) },
    { be_const_key(Get_Current_Output_Stream, -1), be_const_ctype_func(Berry_Sound_Class_Get_Current_Output_Stream_9B2E75BC_55CB_41E1_8F6D_AFCF6483A604) },
};

static be_define_const_map(
    m_libSound_map,
    29
);

static be_define_const_module(
    m_libSound,
    "Sound"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Sound);
