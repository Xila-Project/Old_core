// This file is automatically generated by the Generate.py script.
#include "Software/Berry/Berry.hpp"
extern "C"
{
#include "be_constobj.h"
#include "be_mapping.h"
}
using namespace Xila_Namespace;
using namespace Clipboard_Types;

// - Functions
int Berry_Clipboard_Class_Start_4857EB4D_DD6F_43F5_9E84_DB9384389A12()
{
return (int)Clipboard.Start(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Clipboard_Class_Start_4857EB4D_DD6F_43F5_9E84_DB9384389A12, "i", "");


int Berry_Clipboard_Class_Stop_0D5E7E16_51A1_4B5D_AD04_BA1C82009808()
{
return (int)Clipboard.Stop(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Clipboard_Class_Stop_0D5E7E16_51A1_4B5D_AD04_BA1C82009808, "i", "");


void Berry_Clipboard_Class_Clear_39E9B43F_C8A1_4A0B_8B5A_5E3F2A313FAC()
{
return Clipboard.Clear(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Clipboard_Class_Clear_39E9B43F_C8A1_4A0B_8B5A_5E3F2A313FAC, "", "");


void Berry_Clipboard_Class_Copy_5001071E_172E_47BD_BCBD_354CEFC21BE8(int A_0)
{
return Clipboard.Copy((long long unsigned int)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Clipboard_Class_Copy_5001071E_172E_47BD_BCBD_354CEFC21BE8, "", "i");


void Berry_Clipboard_Class_Copy_215303FE_8956_48E6_BAF1_EFADEE969C09(const char* A_0)
{
return Clipboard.Copy(A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Clipboard_Class_Copy_215303FE_8956_48E6_BAF1_EFADEE969C09, "", "s");



int Berry_Clipboard_Class_Paste_B3BCA7BC_762C_480A_A74F_13CDD70D9AB9()
{
return (int)Clipboard.Paste(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Clipboard_Class_Paste_B3BCA7BC_762C_480A_A74F_13CDD70D9AB9, "i", "");


const char* Berry_Clipboard_Class_Paste_696AB6CF_EE3C_49D0_A105_C8300AAB26A4(bvm* V, int A_1)
{
char* S_0 = (char*)Berry_Class::Get_Instance(V)->Buffer;
Clipboard.Paste(S_0, (A_1 > sizeof(Berry_Class::Buffer)) ? sizeof(Berry_Class::Buffer) : A_1); 
return S_0;
}
BE_FUNC_CTYPE_DECLARE(Berry_Clipboard_Class_Paste_696AB6CF_EE3C_49D0_A105_C8300AAB26A4, "s", "@i");


const char* Berry_Clipboard_Class_Paste_AC64F156_D583_475F_B19A_C5AA393ECB72(bvm* V)
{
String_Type S_0;
S_0.Set_Buffer((char*)Berry_Class::Get_Instance(V)->Buffer, sizeof(Berry_Class::Buffer));
Clipboard.Paste(S_0); 
return S_0;
}
BE_FUNC_CTYPE_DECLARE(Berry_Clipboard_Class_Paste_AC64F156_D583_475F_B19A_C5AA393ECB72, "s", "@");


void* Berry_Clipboard_Class_Get_Pointer()
{
	return (Module_Type*)&Clipboard;
}
BE_FUNC_CTYPE_DECLARE(Berry_Clipboard_Class_Get_Pointer, "c", "")

// - Berry declaration
/* @const_object_info_begin
module Clipboard (scope:global)
{
	Start, ctype_func(Berry_Clipboard_Class_Start_4857EB4D_DD6F_43F5_9E84_DB9384389A12)
	Stop, ctype_func(Berry_Clipboard_Class_Stop_0D5E7E16_51A1_4B5D_AD04_BA1C82009808)
	Clear, ctype_func(Berry_Clipboard_Class_Clear_39E9B43F_C8A1_4A0B_8B5A_5E3F2A313FAC)
	Copy, ctype_func(Berry_Clipboard_Class_Copy_5001071E_172E_47BD_BCBD_354CEFC21BE8)
	Copy, ctype_func(Berry_Clipboard_Class_Copy_215303FE_8956_48E6_BAF1_EFADEE969C09)
	Paste, ctype_func(Berry_Clipboard_Class_Paste_B3BCA7BC_762C_480A_A74F_13CDD70D9AB9)
	Paste, ctype_func(Berry_Clipboard_Class_Paste_696AB6CF_EE3C_49D0_A105_C8300AAB26A4)
	Paste, ctype_func(Berry_Clipboard_Class_Paste_AC64F156_D583_475F_B19A_C5AA393ECB72)
	Get_Pointer, ctype_func(Berry_Clipboard_Class_Get_Pointer)

}
@const_object_info_end */


extern "C"
{
	#include "../generate/be_fixed_Clipboard.h"
}