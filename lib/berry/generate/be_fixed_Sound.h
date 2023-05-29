#include "be_constobj.h"

static be_define_const_map_slots(m_libSound_map) {
    { be_const_key(Format_Most_Significant_Bit, 1), be_const_int(2) },
    { be_const_key(Format_Pulse_Code_Modulation, -1), be_const_int(6) },
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Sound_Class_Get_Volume_D3C993CB_5DC7_4667_81BF_9E728D1C0EA9) },
    { be_const_key(Configuration_Type, -1), be_const_class(Berry_Configuration_Type) },
    { be_const_key(I2S_Configuration_Type, -1), be_const_class(Berry_I2S_Configuration_Type) },
    { be_const_key(Get_Pointer, 2), be_const_ctype_func(Berry_Sound_Class_Get_Pointer) },
    { be_const_key(Format_Standard, 14), be_const_int(0) },
    { be_const_key(Format_Right_Justified, -1), be_const_int(4) },
    { be_const_key(Format_Philips, -1), be_const_int(3) },
    { be_const_key(Stream_Type, -1), be_const_class(Berry_Stream_Type) },
    { be_const_key(I2S_Type, -1), be_const_class(Berry_I2S_Type) },
    { be_const_key(Save_Registry, -1), be_const_ctype_func(Berry_Sound_Class_Save_Registry_9ED549A9_D5F9_4266_8381_B13A11CEB67D) },
    { be_const_key(Volume_Type, -1), be_const_class(Berry_Volume_Type) },
    { be_const_key(Mode_Receive_Transmit, 12), be_const_int(3) },
    { be_const_key(Mode_Receive, -1), be_const_int(2) },
    { be_const_key(Set_Volume, 20), be_const_ctype_func(Berry_Sound_Class_Set_Volume_D888EAF1_4E34_4E7F_AE46_5A6A34E94A4B) },
    { be_const_key(Mode_Undefined, -1), be_const_int(0) },
    { be_const_key(Format_Left_Justified, 24), be_const_int(5) },
    { be_const_key(Volume_Configuration_Type, 8), be_const_class(Berry_Volume_Configuration_Type) },
    { be_const_key(File_Player_Type, 7), be_const_class(Berry_File_Player_Type) },
    { be_const_key(Load_Registry, -1), be_const_ctype_func(Berry_Sound_Class_Load_Registry_ACE58335_6849_48A3_AC17_38EBFE2EB6FD) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Sound_Class_Start_E80724BF_E45C_4A34_B08F_82CC28B702A2) },
    { be_const_key(Create_Registry, 23), be_const_ctype_func(Berry_Sound_Class_Create_Registry_C9E55E3C_A13E_41CE_B0B6_DD1A94EEA50F) },
    { be_const_key(WAV_Decoder_Type, -1), be_const_class(Berry_WAV_Decoder_Type) },
    { be_const_key(Mode_Transmit, 27), be_const_int(1) },
    { be_const_key(Stop, 16), be_const_ctype_func(Berry_Sound_Class_Stop_1F8AE700_59DE_4555_993F_02F95ABCCD6E) },
    { be_const_key(Decoder_Type, 17), be_const_class(Berry_Decoder_Type) },
    { be_const_key(Format_Least_Significant_Bit, -1), be_const_int(1) },
    { be_const_key(Get_Current_Output_Stream, -1), be_const_ctype_func(Berry_Sound_Class_Get_Current_Output_Stream_AFFB4925_636D_4C59_83F5_467F06633A8F) },
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
