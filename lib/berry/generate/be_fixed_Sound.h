#include "be_constobj.h"

static be_define_const_map_slots(m_libSound_map) {
    { be_const_key(Format_Most_Significant_Bit, 1), be_const_int(2) },
    { be_const_key(Format_Pulse_Code_Modulation, -1), be_const_int(6) },
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Sound_Class_Get_Volume_3641B2E3_B499_465D_84C6_44622FC32B23) },
    { be_const_key(Configuration_Type, -1), be_const_class(Berry_Configuration_Type) },
    { be_const_key(I2S_Configuration_Type, -1), be_const_class(Berry_I2S_Configuration_Type) },
    { be_const_key(Get_Pointer, 2), be_const_ctype_func(Berry_Sound_Class_Get_Pointer) },
    { be_const_key(Format_Standard, 14), be_const_int(0) },
    { be_const_key(Format_Right_Justified, -1), be_const_int(4) },
    { be_const_key(Format_Philips, -1), be_const_int(3) },
    { be_const_key(Stream_Type, -1), be_const_class(Berry_Stream_Type) },
    { be_const_key(I2S_Type, -1), be_const_class(Berry_I2S_Type) },
    { be_const_key(Save_Registry, -1), be_const_ctype_func(Berry_Sound_Class_Save_Registry_55F9A34E_CF7A_4B1D_8260_6E04180A80D4) },
    { be_const_key(Volume_Type, -1), be_const_class(Berry_Volume_Type) },
    { be_const_key(Mode_Receive_Transmit, 12), be_const_int(3) },
    { be_const_key(Mode_Receive, -1), be_const_int(2) },
    { be_const_key(Set_Volume, 20), be_const_ctype_func(Berry_Sound_Class_Set_Volume_322EB305_D996_4906_80E8_8661C0F20E35) },
    { be_const_key(Mode_Undefined, -1), be_const_int(0) },
    { be_const_key(Format_Left_Justified, 24), be_const_int(5) },
    { be_const_key(Volume_Configuration_Type, 8), be_const_class(Berry_Volume_Configuration_Type) },
    { be_const_key(File_Player_Type, 7), be_const_class(Berry_File_Player_Type) },
    { be_const_key(Load_Registry, -1), be_const_ctype_func(Berry_Sound_Class_Load_Registry_0E54BA79_D694_4F2F_A429_60A3C5861562) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Sound_Class_Start_A2824055_B11D_456D_ABCE_54F61021EC97) },
    { be_const_key(Create_Registry, 23), be_const_ctype_func(Berry_Sound_Class_Create_Registry_6171A40E_CCB2_4648_87BB_3A9D1C079CC7) },
    { be_const_key(WAV_Decoder_Type, -1), be_const_class(Berry_WAV_Decoder_Type) },
    { be_const_key(Mode_Transmit, 27), be_const_int(1) },
    { be_const_key(Stop, 16), be_const_ctype_func(Berry_Sound_Class_Stop_299D67A5_E109_43EF_8FF5_739D33844B54) },
    { be_const_key(Decoder_Type, 17), be_const_class(Berry_Decoder_Type) },
    { be_const_key(Format_Least_Significant_Bit, -1), be_const_int(1) },
    { be_const_key(Get_Current_Output_Stream, -1), be_const_ctype_func(Berry_Sound_Class_Get_Current_Output_Stream_E656A5D2_2E87_4467_89B2_7A40F8C53EA4) },
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
