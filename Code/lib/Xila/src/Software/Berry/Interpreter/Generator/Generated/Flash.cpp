// This file is automatically generated by the Generate.py script.
#include "Software/Berry/Berry.hpp"
extern "C"
{
#include "be_constobj.h"
#include "be_mapping.h"
}
using namespace Xila_Namespace;
using namespace Flash_Types;

// - Functions
int Berry_Flash_Class_Get_Size_AE5F7EE1_F0F9_42FE_A5FE_AB90F20E5C8A()
{
return (int)Flash.Get_Size(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Flash_Class_Get_Size_AE5F7EE1_F0F9_42FE_A5FE_AB90F20E5C8A, "i", "");


int Berry_Flash_Class_Get_Speed_A7A5B7DA_C7DB_4080_B855_AA2AAE295C34()
{
return (int)Flash.Get_Speed(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Flash_Class_Get_Speed_A7A5B7DA_C7DB_4080_B855_AA2AAE295C34, "i", "");


int Berry_Flash_Class_Get_Mode_306364B6_60CF_455C_AF50_0A31D7CE0802()
{
return (int)Flash.Get_Mode(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Flash_Class_Get_Mode_306364B6_60CF_455C_AF50_0A31D7CE0802, "i", "");


const unsigned int* Berry_Flash_Class_Read_0C4E4706_6887_4E49_A55E_7C3EB65E069A(bvm* V, int A_0, int A_2)
{
unsigned int* S_1 = (unsigned int*)Berry_Class::Get_Instance(V)->Buffer;
Flash.Read((unsigned int)A_0, S_1, (A_2 > sizeof(Berry_Class::Buffer)) ? sizeof(Berry_Class::Buffer) : A_2); 
return S_1;
}
BE_FUNC_CTYPE_DECLARE(Berry_Flash_Class_Read_0C4E4706_6887_4E49_A55E_7C3EB65E069A, "s", "@ii");



int Berry_Flash_Class_Get_Sketch_Size_C4233A48_EF7B_4E9E_8FAB_6F0642F5D508()
{
return (int)Flash.Get_Sketch_Size(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Flash_Class_Get_Sketch_Size_C4233A48_EF7B_4E9E_8FAB_6F0642F5D508, "i", "");


const char* Berry_Flash_Class_Get_Sketch_MD5_BD570CDC_CC46_4406_8DCD_2E59486ABE73(bvm* V)
{
String_Type S_0;
S_0.Set_Buffer((char*)Berry_Class::Get_Instance(V)->Buffer, sizeof(Berry_Class::Buffer));
Flash.Get_Sketch_MD5(S_0); 
return S_0;
}
BE_FUNC_CTYPE_DECLARE(Berry_Flash_Class_Get_Sketch_MD5_BD570CDC_CC46_4406_8DCD_2E59486ABE73, "s", "@");


int Berry_Flash_Class_Get_Sketch_Free_Space_EB5732ED_3AB2_48CA_87DF_F04CE16355AC()
{
return (int)Flash.Get_Sketch_Free_Space(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Flash_Class_Get_Sketch_Free_Space_EB5732ED_3AB2_48CA_87DF_F04CE16355AC, "i", "");


void* Berry_Flash_Class_Get_Pointer()
{
	return (Module_Type*)&Flash;
}
BE_FUNC_CTYPE_DECLARE(Berry_Flash_Class_Get_Pointer, "c", "")

// - Berry declaration
/* @const_object_info_begin
module Flash (scope:global)
{
	Get_Size, ctype_func(Berry_Flash_Class_Get_Size_AE5F7EE1_F0F9_42FE_A5FE_AB90F20E5C8A)
	Get_Speed, ctype_func(Berry_Flash_Class_Get_Speed_A7A5B7DA_C7DB_4080_B855_AA2AAE295C34)
	Get_Mode, ctype_func(Berry_Flash_Class_Get_Mode_306364B6_60CF_455C_AF50_0A31D7CE0802)
	Read, ctype_func(Berry_Flash_Class_Read_0C4E4706_6887_4E49_A55E_7C3EB65E069A)
	Get_Sketch_Size, ctype_func(Berry_Flash_Class_Get_Sketch_Size_C4233A48_EF7B_4E9E_8FAB_6F0642F5D508)
	Get_Sketch_MD5, ctype_func(Berry_Flash_Class_Get_Sketch_MD5_BD570CDC_CC46_4406_8DCD_2E59486ABE73)
	Get_Sketch_Free_Space, ctype_func(Berry_Flash_Class_Get_Sketch_Free_Space_EB5732ED_3AB2_48CA_87DF_F04CE16355AC)
	Get_Pointer, ctype_func(Berry_Flash_Class_Get_Pointer)

	Partition_Subtype_Enumeration_Bootloader_Partition, int(0)
	Partition_Subtype_Enumeration_OTA_Minimum, int(16)
	Partition_Subtype_Enumeration_Xila_Partition, int(16)
	Partition_Subtype_Enumeration_OTA_1, int(17)
	Partition_Subtype_Enumeration_OTA_2, int(18)
	Partition_Subtype_Enumeration_OTA_3, int(19)
	Partition_Subtype_Enumeration_OTA_4, int(20)
	Partition_Subtype_Enumeration_OTA_5, int(21)
	Partition_Subtype_Enumeration_OTA_6, int(22)
	Partition_Subtype_Enumeration_OTA_7, int(23)
	Partition_Subtype_Enumeration_OTA_8, int(24)
	Partition_Subtype_Enumeration_OTA_9, int(25)
	Partition_Subtype_Enumeration_OTA_10, int(26)
	Partition_Subtype_Enumeration_OTA_11, int(27)
	Partition_Subtype_Enumeration_OTA_12, int(28)
	Partition_Subtype_Enumeration_OTA_13, int(29)
	Partition_Subtype_Enumeration_OTA_14, int(30)
	Partition_Subtype_Enumeration_OTA_15, int(31)
	Partition_Subtype_Enumeration_OTA_Maximum, int(32)
	Partition_Subtype_Enumeration_Application_Test, int(32)
	Partition_Subtype_Enumeration_Data_OTA, int(0)
	Partition_Subtype_Enumeration_Data_PHY, int(1)
	Partition_Subtype_Enumeration_Data_NVS, int(2)
	Partition_Subtype_Enumeration_Data_Core_Dump, int(3)
	Partition_Subtype_Enumeration_Data_NVS_Keys, int(4)
	Partition_Subtype_Enumeration_Data_eFuse, int(5)
	Partition_Subtype_Enumeration_Data_Undefined, int(6)
	Partition_Subtype_Enumeration_Data_ESPHTTPD, int(128)
	Partition_Subtype_Enumeration_Data_Fat, int(129)
	Partition_Subtype_Enumeration_Data_SPIFFS, int(130)
	Partition_Subtype_Enumeration_Any, int(255)

}
@const_object_info_end */


extern "C"
{
	#include "../generate/be_fixed_Flash.h"
}