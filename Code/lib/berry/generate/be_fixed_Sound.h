#include "be_constobj.h"

static be_define_const_map_slots(m_libSound_map) {
    { be_const_key(Format_Most_Significant_Bit, 1), be_const_int(2) },
    { be_const_key(Format_Pulse_Code_Modulation, -1), be_const_int(6) },
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Sound_Class_Get_Volume_FCE0F807_B6E9_4F7B_95DB_86C6D5781E77) },
    { be_const_key(Configuration_Type, -1), be_const_class(Berry_Configuration_Type) },
    { be_const_key(I2S_Configuration_Type, -1), be_const_class(Berry_I2S_Configuration_Type) },
    { be_const_key(Get_Pointer, 2), be_const_ctype_func(Berry_Sound_Class_Get_Pointer) },
    { be_const_key(Format_Standard, 14), be_const_int(0) },
    { be_const_key(Format_Right_Justified, -1), be_const_int(4) },
    { be_const_key(Format_Philips, -1), be_const_int(3) },
    { be_const_key(Stream_Type, -1), be_const_class(Berry_Stream_Type) },
    { be_const_key(I2S_Type, -1), be_const_class(Berry_I2S_Type) },
    { be_const_key(Save_Registry, -1), be_const_ctype_func(Berry_Sound_Class_Save_Registry_1E9A53A2_F668_4497_8017_7A34352B5881) },
    { be_const_key(Volume_Type, -1), be_const_class(Berry_Volume_Type) },
    { be_const_key(Mode_Receive_Transmit, 12), be_const_int(3) },
    { be_const_key(Mode_Receive, -1), be_const_int(2) },
    { be_const_key(Set_Volume, 20), be_const_ctype_func(Berry_Sound_Class_Set_Volume_E91F373D_B1FB_4C4A_A888_22F5E75DC147) },
    { be_const_key(Mode_Undefined, -1), be_const_int(0) },
    { be_const_key(Format_Left_Justified, 24), be_const_int(5) },
    { be_const_key(Volume_Configuration_Type, 8), be_const_class(Berry_Volume_Configuration_Type) },
    { be_const_key(File_Player_Type, 7), be_const_class(Berry_File_Player_Type) },
    { be_const_key(Load_Registry, -1), be_const_ctype_func(Berry_Sound_Class_Load_Registry_36905BC8_E740_4735_802B_C0756185BA7E) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Sound_Class_Start_E1DCFB56_5816_4405_8546_F5DE581BE553) },
    { be_const_key(Create_Registry, 23), be_const_ctype_func(Berry_Sound_Class_Create_Registry_9100AC52_85EB_4D78_A4DE_055CD1109321) },
    { be_const_key(WAV_Decoder_Type, -1), be_const_class(Berry_WAV_Decoder_Type) },
    { be_const_key(Mode_Transmit, 27), be_const_int(1) },
    { be_const_key(Stop, 16), be_const_ctype_func(Berry_Sound_Class_Stop_49A95EED_6845_4B4C_8547_AF5FC61BC859) },
    { be_const_key(Decoder_Type, 17), be_const_class(Berry_Decoder_Type) },
    { be_const_key(Format_Least_Significant_Bit, -1), be_const_int(1) },
    { be_const_key(Get_Current_Output_Stream, -1), be_const_ctype_func(Berry_Sound_Class_Get_Current_Output_Stream_8A2E6161_1628_4341_B93F_354435958765) },
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
