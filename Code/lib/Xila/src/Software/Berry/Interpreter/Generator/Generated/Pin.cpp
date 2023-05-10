// This file is automatically generated by the Generate.py script.
#include "Software/Berry/Berry.hpp"
extern "C"
{
#include "be_constobj.h"
#include "be_mapping.h"
}
using namespace Xila_Namespace;
using namespace Pin_Types;

// - Functions
void Berry_Pin_Class_Set_Mode_E7220124_9777_47F3_B414_D0950DDC8DB1(int A_0, int A_1)
{
return Pin.Set_Mode((unsigned char)A_0, (Mode_Type)A_1); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Pin_Class_Set_Mode_E7220124_9777_47F3_B414_D0950DDC8DB1, "", "ii");


int Berry_Pin_Class_Valid_Output_Pin_354B35FE_D6BD_44C6_8FE2_CE66CACAC3DE(int A_0)
{
return (int)Pin.Valid_Output_Pin((unsigned char)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Pin_Class_Valid_Output_Pin_354B35FE_D6BD_44C6_8FE2_CE66CACAC3DE, "i", "i");


void Berry_Pin_Class_Digital_Write_FE40A826_6A1D_47D4_A8FB_F3F6A13A6CD8(int A_0, int A_1)
{
return Pin.Digital_Write((unsigned char)A_0, (Digital_State_Type)A_1); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Pin_Class_Digital_Write_FE40A826_6A1D_47D4_A8FB_F3F6A13A6CD8, "", "ii");


int Berry_Pin_Class_Digital_Read_D589C479_9BFC_46EE_9DD3_C2BF8AD1D88E(int A_0)
{
return (int)Pin.Digital_Read((unsigned char)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Pin_Class_Digital_Read_D589C479_9BFC_46EE_9DD3_C2BF8AD1D88E, "i", "i");


int Berry_Pin_Class_Valid_Digital_Pin_953B4502_8E3B_4D71_8A74_20981B0E942E(int A_0)
{
return (int)Pin.Valid_Digital_Pin((unsigned char)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Pin_Class_Valid_Digital_Pin_953B4502_8E3B_4D71_8A74_20981B0E942E, "i", "i");


int Berry_Pin_Class_Analog_Read_CADEA075_D9F7_414D_BE40_E6BD20502337(int A_0)
{
return (int)Pin.Analog_Read((unsigned char)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Pin_Class_Analog_Read_CADEA075_D9F7_414D_BE40_E6BD20502337, "i", "i");


int Berry_Pin_Class_Analog_Read_Milli_Volts_0251D9BC_7505_4D91_B6BF_FFB7D027B097(int A_0)
{
return (int)Pin.Analog_Read_Milli_Volts((unsigned char)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Pin_Class_Analog_Read_Milli_Volts_0251D9BC_7505_4D91_B6BF_FFB7D027B097, "i", "i");


void Berry_Pin_Class_Set_Voltage_Reference_Pin_4FBEC102_9E6A_4821_9BBA_04FD31411478(int A_0)
{
return Pin.Set_Voltage_Reference_Pin((unsigned char)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Pin_Class_Set_Voltage_Reference_Pin_4FBEC102_9E6A_4821_9BBA_04FD31411478, "", "i");


void Berry_Pin_Class_Set_Read_Resolutions_CAFA20EC_C2BD_4119_A3F4_CB8F33811880(int A_0)
{
return Pin.Set_Read_Resolutions((unsigned char)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Pin_Class_Set_Read_Resolutions_CAFA20EC_C2BD_4119_A3F4_CB8F33811880, "", "i");


void Berry_Pin_Class_Set_Width_9C60B1D8_EAF9_4EB1_8FF3_312D770CD444(int A_0)
{
return Pin.Set_Width((unsigned char)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Pin_Class_Set_Width_9C60B1D8_EAF9_4EB1_8FF3_312D770CD444, "", "i");


void Berry_Pin_Class_Set_Clock_Divider_1512BB2D_DF40_45F2_9C80_AA6D6FE6E025(int A_0)
{
return Pin.Set_Clock_Divider((unsigned char)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Pin_Class_Set_Clock_Divider_1512BB2D_DF40_45F2_9C80_AA6D6FE6E025, "", "i");


void Berry_Pin_Class_Set_Attenuation_2BFAD852_9483_4FA4_9AFA_5673568610A9(int A_0)
{
return Pin.Set_Attenuation((unsigned char)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Pin_Class_Set_Attenuation_2BFAD852_9483_4FA4_9AFA_5673568610A9, "", "i");


void Berry_Pin_Class_Set_Attenuation_E49F5627_5314_42E9_B8B7_910F29915C24(int A_0, int A_1)
{
return Pin.Set_Attenuation((unsigned char)A_0, (unsigned char)A_1); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Pin_Class_Set_Attenuation_E49F5627_5314_42E9_B8B7_910F29915C24, "", "ii");




void Berry_Pin_Class_Detach_Interrupt_EE515A90_27C2_4403_A913_CD5E0F7B6D31(int A_0)
{
return Pin.Detach_Interrupt((unsigned char)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Pin_Class_Detach_Interrupt_EE515A90_27C2_4403_A913_CD5E0F7B6D31, "", "i");



// - Berry declaration
/* @const_object_info_begin
module Pin (scope:global)
{
	Set_Mode, ctype_func(Berry_Pin_Class_Set_Mode_E7220124_9777_47F3_B414_D0950DDC8DB1)
	Valid_Output_Pin, ctype_func(Berry_Pin_Class_Valid_Output_Pin_354B35FE_D6BD_44C6_8FE2_CE66CACAC3DE)
	Digital_Write, ctype_func(Berry_Pin_Class_Digital_Write_FE40A826_6A1D_47D4_A8FB_F3F6A13A6CD8)
	Digital_Read, ctype_func(Berry_Pin_Class_Digital_Read_D589C479_9BFC_46EE_9DD3_C2BF8AD1D88E)
	Valid_Digital_Pin, ctype_func(Berry_Pin_Class_Valid_Digital_Pin_953B4502_8E3B_4D71_8A74_20981B0E942E)
	Analog_Read, ctype_func(Berry_Pin_Class_Analog_Read_CADEA075_D9F7_414D_BE40_E6BD20502337)
	Analog_Read_Milli_Volts, ctype_func(Berry_Pin_Class_Analog_Read_Milli_Volts_0251D9BC_7505_4D91_B6BF_FFB7D027B097)
	Set_Voltage_Reference_Pin, ctype_func(Berry_Pin_Class_Set_Voltage_Reference_Pin_4FBEC102_9E6A_4821_9BBA_04FD31411478)
	Set_Read_Resolutions, ctype_func(Berry_Pin_Class_Set_Read_Resolutions_CAFA20EC_C2BD_4119_A3F4_CB8F33811880)
	Set_Width, ctype_func(Berry_Pin_Class_Set_Width_9C60B1D8_EAF9_4EB1_8FF3_312D770CD444)
	Set_Clock_Divider, ctype_func(Berry_Pin_Class_Set_Clock_Divider_1512BB2D_DF40_45F2_9C80_AA6D6FE6E025)
	Set_Attenuation, ctype_func(Berry_Pin_Class_Set_Attenuation_2BFAD852_9483_4FA4_9AFA_5673568610A9)
	Set_Attenuation, ctype_func(Berry_Pin_Class_Set_Attenuation_E49F5627_5314_42E9_B8B7_910F29915C24)
	Detach_Interrupt, ctype_func(Berry_Pin_Class_Detach_Interrupt_EE515A90_27C2_4403_A913_CD5E0F7B6D31)

	Digital_State_Low, int(0)
	Digital_State_High, int(1)

	Mode_Input, int(0)
	Mode_Output, int(1)
	Mode_Pull_Up, int(2)
	Mode_Input_Pull_Up, int(3)
	Mode_Pull_Down, int(4)
	Mode_Input_Pull_Down, int(5)
	Mode_Open_Drain, int(6)
	Mode_Output_Open_Drain, int(7)
	Mode_Analog, int(8)

	Interrupt_Mode_Disabled, int(0)
	Interrupt_Mode_Rising, int(1)
	Interrupt_Mode_Falling, int(2)
	Interrupt_Mode_Change, int(3)
	Interrupt_Mode_On_Low, int(4)
	Interrupt_Mode_On_High, int(5)
	Interrupt_Mode_On_Low_WE, int(6)
	Interrupt_Mode_On_High_WE, int(7)

}
@const_object_info_end */


extern "C"
{
	#include "../generate/be_fixed_Pin.h"
}