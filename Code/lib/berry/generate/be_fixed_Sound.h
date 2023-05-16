#include "be_constobj.h"

static be_define_const_map_slots(m_libSound_map) {
    { be_const_key(Format_Most_Significant_Bit, 1), be_const_int(2) },
    { be_const_key(Format_Pulse_Code_Modulation, -1), be_const_int(6) },
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Sound_Class_Get_Volume_5B3A7A0F_EFA4_40C8_A9EF_662F00A7A91C) },
    { be_const_key(Configuration_Type, -1), be_const_class(Berry_Configuration_Type) },
    { be_const_key(I2S_Configuration_Type, -1), be_const_class(Berry_I2S_Configuration_Type) },
    { be_const_key(Get_Pointer, 2), be_const_ctype_func(Berry_Sound_Class_Get_Pointer) },
    { be_const_key(Format_Standard, 14), be_const_int(0) },
    { be_const_key(Format_Right_Justified, -1), be_const_int(4) },
    { be_const_key(Format_Philips, -1), be_const_int(3) },
    { be_const_key(Stream_Type, -1), be_const_class(Berry_Stream_Type) },
    { be_const_key(I2S_Type, -1), be_const_class(Berry_I2S_Type) },
    { be_const_key(Save_Registry, -1), be_const_ctype_func(Berry_Sound_Class_Save_Registry_6A8ECB9B_835A_4401_A534_36A514D4677B) },
    { be_const_key(Volume_Type, -1), be_const_class(Berry_Volume_Type) },
    { be_const_key(Mode_Receive_Transmit, 12), be_const_int(3) },
    { be_const_key(Mode_Receive, -1), be_const_int(2) },
    { be_const_key(Set_Volume, 20), be_const_ctype_func(Berry_Sound_Class_Set_Volume_506F4C7E_A290_4CA9_AA54_1AE33BA8B834) },
    { be_const_key(Mode_Undefined, -1), be_const_int(0) },
    { be_const_key(Format_Left_Justified, 24), be_const_int(5) },
    { be_const_key(Volume_Configuration_Type, 8), be_const_class(Berry_Volume_Configuration_Type) },
    { be_const_key(File_Player_Type, 7), be_const_class(Berry_File_Player_Type) },
    { be_const_key(Load_Registry, -1), be_const_ctype_func(Berry_Sound_Class_Load_Registry_663888C2_8A87_4643_ACE4_80E4595D0DFF) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Sound_Class_Start_E5EDCED3_F561_4062_A0D3_CE4008963BD7) },
    { be_const_key(Create_Registry, 23), be_const_ctype_func(Berry_Sound_Class_Create_Registry_E7ADC17E_BE8F_4248_94D4_E9A667DE5F4C) },
    { be_const_key(WAV_Decoder_Type, -1), be_const_class(Berry_WAV_Decoder_Type) },
    { be_const_key(Mode_Transmit, 27), be_const_int(1) },
    { be_const_key(Stop, 16), be_const_ctype_func(Berry_Sound_Class_Stop_73C0E32B_52A4_4AB5_94E7_E66247EE6FE6) },
    { be_const_key(Decoder_Type, 17), be_const_class(Berry_Decoder_Type) },
    { be_const_key(Format_Least_Significant_Bit, -1), be_const_int(1) },
    { be_const_key(Get_Current_Output_Stream, -1), be_const_ctype_func(Berry_Sound_Class_Get_Current_Output_Stream_59A72941_3AF3_45FA_86EA_8CE06BD045CB) },
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
