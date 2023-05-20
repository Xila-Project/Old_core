// This file is automatically generated by the Generate.py script.
#include "Software/Berry/Berry.hpp"
extern "C"
{
#include "be_constobj.h"
#include "be_mapping.h"
}
using namespace Xila_Namespace;
using namespace Communication_Types;

// - Functions

// - - Constructors
void * Berry_IP_Address_Class_Initialize_7AF7249D_DB5B_4B5F_84C6_6B397CCD32ED(bvm* V)
{
void* Pointer = be_malloc(V, sizeof(Communication_Types::IP_Address_Class));
return new (Pointer) Communication_Types::IP_Address_Class(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_IP_Address_Class_Initialize_7AF7249D_DB5B_4B5F_84C6_6B397CCD32ED, "+_p", "@");

void * Berry_IP_Address_Class_Initialize_9EB824C1_5BE8_466C_9775_51C435C2C9FA(bvm* V, bool A_0)
{
void* Pointer = be_malloc(V, sizeof(Communication_Types::IP_Address_Class));
return new (Pointer) Communication_Types::IP_Address_Class(A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_IP_Address_Class_Initialize_9EB824C1_5BE8_466C_9775_51C435C2C9FA, "+_p", "@b");

void * Berry_IP_Address_Class_Initialize_B6FBE2F3_4E44_4AB0_A371_24C6BA1806C1(bvm* V, int A_0)
{
void* Pointer = be_malloc(V, sizeof(Communication_Types::IP_Address_Class));
return new (Pointer) Communication_Types::IP_Address_Class((unsigned int)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_IP_Address_Class_Initialize_B6FBE2F3_4E44_4AB0_A371_24C6BA1806C1, "+_p", "@i");

void * Berry_IP_Address_Class_Initialize_1ED6B7F1_9B20_4210_8742_BBFE58BAC1E6(bvm* V, const unsigned char* A_0, bool A_1 = true)
{
void* Pointer = be_malloc(V, sizeof(Communication_Types::IP_Address_Class));
return new (Pointer) Communication_Types::IP_Address_Class(A_0, A_1); 
}
BE_FUNC_CTYPE_DECLARE(Berry_IP_Address_Class_Initialize_1ED6B7F1_9B20_4210_8742_BBFE58BAC1E6, "+_p", "@s[b");

void * Berry_IP_Address_Class_Initialize_E712392C_21B9_41E0_9917_0010985FAA67(bvm* V, int A_0, int A_1, int A_2, int A_3)
{
void* Pointer = be_malloc(V, sizeof(Communication_Types::IP_Address_Class));
return new (Pointer) Communication_Types::IP_Address_Class((unsigned char)A_0, (unsigned char)A_1, (unsigned char)A_2, (unsigned char)A_3); 
}
BE_FUNC_CTYPE_DECLARE(Berry_IP_Address_Class_Initialize_E712392C_21B9_41E0_9917_0010985FAA67, "+_p", "@iiii");

void * Berry_IP_Address_Class_Initialize_AE0A9C39_3699_4F6C_96D7_7D1E3D8F6077(bvm* V)
{
void* Pointer = be_malloc(V, sizeof(Communication_Types::IP_Address_Class));
return new (Pointer) Communication_Types::IP_Address_Class(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_IP_Address_Class_Initialize_AE0A9C39_3699_4F6C_96D7_7D1E3D8F6077, "+_p", "@");

void * Berry_IP_Address_Class_Initialize_F66CB07E_9E21_4547_8F50_6E0C649FD7AA(bvm* V)
{
void* Pointer = be_malloc(V, sizeof(Communication_Types::IP_Address_Class));
return new (Pointer) Communication_Types::IP_Address_Class(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_IP_Address_Class_Initialize_F66CB07E_9E21_4547_8F50_6E0C649FD7AA, "+_p", "@");


// - - Destructors
void Berry_IP_Address_Class_Deinitialize_4508D52F_BE93_4952_8672_F9763009B880(bvm* V, Xila_Namespace::Communication_Types::IP_Address_Class* I)
{
if (!I) { return; }
I->~IP_Address_Class();
be_free(V, I, sizeof(Communication_Types::IP_Address_Class));
}
BE_FUNC_CTYPE_DECLARE(Berry_IP_Address_Class_Deinitialize_4508D52F_BE93_4952_8672_F9763009B880, "", "@.");


// - - Functions
const char* Berry_IP_Address_Class_To_E4F6C607_489C_41F0_8020_A9A397673EC2(bvm* V, Xila_Namespace::Communication_Types::IP_Address_Class* I)
{
String_Type S_0;
S_0.Set_Buffer((char*)Berry_Class::Get_Instance(V)->Buffer, sizeof(Berry_Class::Buffer));
I->To(S_0); 
return S_0;
}
BE_FUNC_CTYPE_DECLARE(Berry_IP_Address_Class_To_E4F6C607_489C_41F0_8020_A9A397673EC2, "s", "@.");

bool Berry_IP_Address_Class_Is_IP_v4_1FACCF7E_B810_4101_B2CF_E792CA0F5AF4(Xila_Namespace::Communication_Types::IP_Address_Class* I)
{
return I->Is_IP_v4(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_IP_Address_Class_Is_IP_v4_1FACCF7E_B810_4101_B2CF_E792CA0F5AF4, "b", ".");

void Berry_IP_Address_Class_Set_IP_Version_CF5B9FBB_8473_4321_846E_9F69EE81C566(Xila_Namespace::Communication_Types::IP_Address_Class* I, bool A_0)
{
return I->Set_IP_Version(A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_IP_Address_Class_Set_IP_Version_CF5B9FBB_8473_4321_846E_9F69EE81C566, "", ".b");

// - - Operators
bool Berry_IP_Address_Class_Operator_5F888E65_F034_47FB_998B_4D9BA8D43E36(Xila_Namespace::Communication_Types::IP_Address_Class* I, Xila_Namespace::Communication_Types::IP_Address_Class* A_0)
{
return *I == *A_0;
}
BE_FUNC_CTYPE_DECLARE(Berry_IP_Address_Class_Operator_5F888E65_F034_47FB_998B_4D9BA8D43E36, "b", "..")

bool Berry_IP_Address_Class_Operator_B2EDC75F_A93F_422E_93C9_3FC06874D0C9(Xila_Namespace::Communication_Types::IP_Address_Class* I, Xila_Namespace::Communication_Types::IP_Address_Class* A_0)
{
return *I == *A_0;
}
BE_FUNC_CTYPE_DECLARE(Berry_IP_Address_Class_Operator_B2EDC75F_A93F_422E_93C9_3FC06874D0C9, "b", "..")


// - Berry declaration
/* @const_object_info_begin
class Berry_IP_Address_Type(scope:global, name:IP_Address_Type)
{
	_p, var
	init, ctype_func(Berry_IP_Address_Class_Initialize_7AF7249D_DB5B_4B5F_84C6_6B397CCD32ED)
	init, ctype_func(Berry_IP_Address_Class_Initialize_9EB824C1_5BE8_466C_9775_51C435C2C9FA)
	init, ctype_func(Berry_IP_Address_Class_Initialize_B6FBE2F3_4E44_4AB0_A371_24C6BA1806C1)
	init, ctype_func(Berry_IP_Address_Class_Initialize_1ED6B7F1_9B20_4210_8742_BBFE58BAC1E6)
	init, ctype_func(Berry_IP_Address_Class_Initialize_E712392C_21B9_41E0_9917_0010985FAA67)
	init, ctype_func(Berry_IP_Address_Class_Initialize_AE0A9C39_3699_4F6C_96D7_7D1E3D8F6077)
	init, ctype_func(Berry_IP_Address_Class_Initialize_F66CB07E_9E21_4547_8F50_6E0C649FD7AA)
	deinit, ctype_func(Berry_IP_Address_Class_Deinitialize_4508D52F_BE93_4952_8672_F9763009B880)
	To, ctype_func(Berry_IP_Address_Class_To_E4F6C607_489C_41F0_8020_A9A397673EC2)
	Is_IP_v4, ctype_func(Berry_IP_Address_Class_Is_IP_v4_1FACCF7E_B810_4101_B2CF_E792CA0F5AF4)
	Set_IP_Version, ctype_func(Berry_IP_Address_Class_Set_IP_Version_CF5B9FBB_8473_4321_846E_9F69EE81C566)
	==, ctype_func(Berry_IP_Address_Class_Operator_5F888E65_F034_47FB_998B_4D9BA8D43E36)
	==, ctype_func(Berry_IP_Address_Class_Operator_B2EDC75F_A93F_422E_93C9_3FC06874D0C9)

}
@const_object_info_end */


extern "C"
{
	#include "../generate/be_fixed_Berry_IP_Address_Type.h"
}
// - Functions

// - - Constructors
void * Berry_HTTPS_Client_Class_Initialize_EDBF3719_F362_4BC1_8102_78E4E1EFDA51(bvm* V)
{
void* Pointer = be_malloc(V, sizeof(Communication_Types::HTTPS_Client_Class));
return new (Pointer) Communication_Types::HTTPS_Client_Class(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Initialize_EDBF3719_F362_4BC1_8102_78E4E1EFDA51, "+_p", "@");


// - - Destructors
void Berry_HTTPS_Client_Class_Deinitialize_02DAEE61_963B_4E90_ABC7_2CD7137AC322(bvm* V, Xila_Namespace::Communication_Types::HTTPS_Client_Class* I)
{
if (!I) { return; }
I->~HTTPS_Client_Class();
be_free(V, I, sizeof(Communication_Types::HTTPS_Client_Class));
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Deinitialize_02DAEE61_963B_4E90_ABC7_2CD7137AC322, "", "@.");


// - - Functions
int Berry_HTTPS_Client_Class_Begin_60DE9498_38B0_458E_8943_58B53857D047(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, ::Xila_Namespace::Communication_Types::WiFi_Client_Class* A_0, const char* A_1, int A_2, const char* A_3 = __null, bool A_4 = false)
{
return (int)I->Begin(*A_0, A_1, (short unsigned int)A_2, A_3, A_4); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Begin_60DE9498_38B0_458E_8943_58B53857D047, "i", "..si[sb");

void Berry_HTTPS_Client_Class_End_28798F66_C3A5_47A5_B59C_E633F55162ED(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I)
{
return I->End(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_End_28798F66_C3A5_47A5_B59C_E633F55162ED, "", ".");

bool Berry_HTTPS_Client_Class_Connected_A1E182C6_5451_4D75_A988_1BE88323A505(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I)
{
return I->Connected(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Connected_A1E182C6_5451_4D75_A988_1BE88323A505, "b", ".");

int Berry_HTTPS_Client_Class_Get_49D15286_B551_4537_8EA2_DF814BDF06BC(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I)
{
return (int)I->Get(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Get_49D15286_B551_4537_8EA2_DF814BDF06BC, "i", ".");

int Berry_HTTPS_Client_Class_Patch_F9C6E175_015C_4652_9E48_E1CC9F0D89DA(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, const char* A_0)
{
return (int)I->Patch(A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Patch_F9C6E175_015C_4652_9E48_E1CC9F0D89DA, "i", ".s");

int Berry_HTTPS_Client_Class_Post_19384BC3_8D0A_4362_8F34_A3F1C186A4BC(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, const char* A_0)
{
return (int)I->Post(A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Post_19384BC3_8D0A_4362_8F34_A3F1C186A4BC, "i", ".s");

int Berry_HTTPS_Client_Class_Put_B18C5D45_984C_4A22_B079_2C6A7A0CF3DE(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, const char* A_0)
{
return (int)I->Put(A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Put_B18C5D45_984C_4A22_B079_2C6A7A0CF3DE, "i", ".s");

int Berry_HTTPS_Client_Class_Send_Request_D83E691E_73D1_4A4B_AF26_57610B0233A8(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, const char* A_0, const char* A_1 = __null)
{
return (int)I->Send_Request(A_0, A_1); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Send_Request_D83E691E_73D1_4A4B_AF26_57610B0233A8, "i", ".s[s");

void Berry_HTTPS_Client_Class_Add_Header_D2588710_EAFF_420E_97B1_8D32C74D91EE(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, const char* A_0, const char* A_1, bool A_2 = false, bool A_3 = true)
{
return I->Add_Header(A_0, A_1, A_2, A_3); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Add_Header_D2588710_EAFF_420E_97B1_8D32C74D91EE, "", ".ss[bb");

bool Berry_HTTPS_Client_Class_Has_Header_69E005BF_74C7_4BB9_97CE_16AF9838DE74(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, const char* A_0)
{
return I->Has_Header(A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Has_Header_69E005BF_74C7_4BB9_97CE_16AF9838DE74, "b", ".s");

void Berry_HTTPS_Client_Class_Use_HTTP_1_0_16235078_C0E9_4485_B927_5D2BAF73189C(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, bool A_0)
{
return I->Use_HTTP_1_0(A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Use_HTTP_1_0_16235078_C0E9_4485_B927_5D2BAF73189C, "", ".b");

void Berry_HTTPS_Client_Class_Reset_Cookie_Jar_60430A77_3B15_4A9D_93B5_16B82323A581(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I)
{
return I->Reset_Cookie_Jar(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Reset_Cookie_Jar_60430A77_3B15_4A9D_93B5_16B82323A581, "", ".");

void Berry_HTTPS_Client_Class_Clear_All_Cookies_28C886AB_D0B5_4AA3_BB9C_C37847875E37(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I)
{
return I->Clear_All_Cookies(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Clear_All_Cookies_28C886AB_D0B5_4AA3_BB9C_C37847875E37, "", ".");

void Berry_HTTPS_Client_Class_Set_Reuse_45AE5B7E_2569_4D8D_B221_E661576EC2FC(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, bool A_0)
{
return I->Set_Reuse(A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Set_Reuse_45AE5B7E_2569_4D8D_B221_E661576EC2FC, "", ".b");

void Berry_HTTPS_Client_Class_Set_User_Agent_302ABE05_6FF6_4F19_B609_72D4DBEF4F1A(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, const char* A_0)
{
return I->Set_User_Agent(A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Set_User_Agent_302ABE05_6FF6_4F19_B609_72D4DBEF4F1A, "", ".s");

void Berry_HTTPS_Client_Class_Set_Authorization_F72246A1_1019_4085_8ED0_6138837C2AD7(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, const char* A_0, const char* A_1 = __null)
{
return I->Set_Authorization(A_0, A_1); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Set_Authorization_F72246A1_1019_4085_8ED0_6138837C2AD7, "", ".s[s");

void Berry_HTTPS_Client_Class_Set_Authorization_Type_8FE17A70_5558_47D7_B949_A8AD25343D3B(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, const char* A_0)
{
return I->Set_Authorization_Type(A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Set_Authorization_Type_8FE17A70_5558_47D7_B949_A8AD25343D3B, "", ".s");

void Berry_HTTPS_Client_Class_Set_Connect_Timeout_5E0B873A_72C5_4609_9B0A_8B54F08F0FEE(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, int A_0)
{
return I->Set_Connect_Timeout((unsigned int)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Set_Connect_Timeout_5E0B873A_72C5_4609_9B0A_8B54F08F0FEE, "", ".i");

void Berry_HTTPS_Client_Class_Set_Timeout_1606879B_3218_4B52_AB9C_274CC414A388(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, int A_0)
{
return I->Set_Timeout((unsigned int)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Set_Timeout_1606879B_3218_4B52_AB9C_274CC414A388, "", ".i");

void Berry_HTTPS_Client_Class_Set_Follow_Redirects_FFCE3E36_9209_433E_9A63_09A3AC99733C(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, bool A_0, bool A_1 = false)
{
return I->Set_Follow_Redirects(A_0, A_1); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Set_Follow_Redirects_FFCE3E36_9209_433E_9A63_09A3AC99733C, "", ".b[b");

void Berry_HTTPS_Client_Class_Set_Redirect_Limit_129E2F25_41BB_498C_9AD8_1DE5D6FADD9E(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, int A_0)
{
return I->Set_Redirect_Limit((short unsigned int)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Set_Redirect_Limit_129E2F25_41BB_498C_9AD8_1DE5D6FADD9E, "", ".i");

int Berry_HTTPS_Client_Class_Set_URL_E04F34F5_FDDA_4816_A67C_DFC1FBD4DED3(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, const char* A_0)
{
return (int)I->Set_URL(A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Set_URL_E04F34F5_FDDA_4816_A67C_DFC1FBD4DED3, "i", ".s");

const char* Berry_HTTPS_Client_Class_Get_Header_7C082763_3610_4D43_BEA3_D362E2B23293(bvm* V, Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, const char* A_1)
{
String_Type S_0;
S_0.Set_Buffer((char*)Berry_Class::Get_Instance(V)->Buffer, sizeof(Berry_Class::Buffer));
I->Get_Header(S_0, A_1); 
return S_0;
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Get_Header_7C082763_3610_4D43_BEA3_D362E2B23293, "s", "@.s");

const char* Berry_HTTPS_Client_Class_Get_Header_Name_808E3BB9_E63C_471A_B98D_1AEE366980E2(bvm* V, Xila_Namespace::Communication_Types::HTTPS_Client_Class* I, int A_1)
{
String_Type S_0;
S_0.Set_Buffer((char*)Berry_Class::Get_Instance(V)->Buffer, sizeof(Berry_Class::Buffer));
I->Get_Header_Name(S_0, (unsigned int)A_1); 
return S_0;
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Get_Header_Name_808E3BB9_E63C_471A_B98D_1AEE366980E2, "s", "@.i");

int Berry_HTTPS_Client_Class_Get_Header_Count_1897E38D_092F_44A5_A2EF_99CF97799431(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I)
{
return (int)I->Get_Header_Count(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Get_Header_Count_1897E38D_092F_44A5_A2EF_99CF97799431, "i", ".");

int Berry_HTTPS_Client_Class_Get_Size_83633558_12C4_48B2_A22F_42015EFB31ED(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I)
{
return (int)I->Get_Size(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Get_Size_83633558_12C4_48B2_A22F_42015EFB31ED, "i", ".");

const char* Berry_HTTPS_Client_Class_Get_Location_50C1B44E_6A57_4AD5_9394_357AD8C0FA70(Xila_Namespace::Communication_Types::HTTPS_Client_Class* I)
{
return I->Get_Location(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Get_Location_50C1B44E_6A57_4AD5_9394_357AD8C0FA70, "s", ".");

const char* Berry_HTTPS_Client_Class_Get_String_9CFC19E6_7633_49F2_A129_0EF7A9BE76E0(bvm* V, Xila_Namespace::Communication_Types::HTTPS_Client_Class* I)
{
String_Type S_0;
S_0.Set_Buffer((char*)Berry_Class::Get_Instance(V)->Buffer, sizeof(Berry_Class::Buffer));
I->Get_String(S_0); 
return S_0;
}
BE_FUNC_CTYPE_DECLARE(Berry_HTTPS_Client_Class_Get_String_9CFC19E6_7633_49F2_A129_0EF7A9BE76E0, "s", "@.");

// - - Operators

// - Berry declaration
/* @const_object_info_begin
class Berry_HTTPS_Client_Type(scope:global, name:HTTPS_Client_Type)
{
	_p, var
	init, ctype_func(Berry_HTTPS_Client_Class_Initialize_EDBF3719_F362_4BC1_8102_78E4E1EFDA51)
	deinit, ctype_func(Berry_HTTPS_Client_Class_Deinitialize_02DAEE61_963B_4E90_ABC7_2CD7137AC322)
	Begin, ctype_func(Berry_HTTPS_Client_Class_Begin_60DE9498_38B0_458E_8943_58B53857D047)
	End, ctype_func(Berry_HTTPS_Client_Class_End_28798F66_C3A5_47A5_B59C_E633F55162ED)
	Connected, ctype_func(Berry_HTTPS_Client_Class_Connected_A1E182C6_5451_4D75_A988_1BE88323A505)
	Get, ctype_func(Berry_HTTPS_Client_Class_Get_49D15286_B551_4537_8EA2_DF814BDF06BC)
	Patch, ctype_func(Berry_HTTPS_Client_Class_Patch_F9C6E175_015C_4652_9E48_E1CC9F0D89DA)
	Post, ctype_func(Berry_HTTPS_Client_Class_Post_19384BC3_8D0A_4362_8F34_A3F1C186A4BC)
	Put, ctype_func(Berry_HTTPS_Client_Class_Put_B18C5D45_984C_4A22_B079_2C6A7A0CF3DE)
	Send_Request, ctype_func(Berry_HTTPS_Client_Class_Send_Request_D83E691E_73D1_4A4B_AF26_57610B0233A8)
	Add_Header, ctype_func(Berry_HTTPS_Client_Class_Add_Header_D2588710_EAFF_420E_97B1_8D32C74D91EE)
	Has_Header, ctype_func(Berry_HTTPS_Client_Class_Has_Header_69E005BF_74C7_4BB9_97CE_16AF9838DE74)
	Use_HTTP_1_0, ctype_func(Berry_HTTPS_Client_Class_Use_HTTP_1_0_16235078_C0E9_4485_B927_5D2BAF73189C)
	Reset_Cookie_Jar, ctype_func(Berry_HTTPS_Client_Class_Reset_Cookie_Jar_60430A77_3B15_4A9D_93B5_16B82323A581)
	Clear_All_Cookies, ctype_func(Berry_HTTPS_Client_Class_Clear_All_Cookies_28C886AB_D0B5_4AA3_BB9C_C37847875E37)
	Set_Reuse, ctype_func(Berry_HTTPS_Client_Class_Set_Reuse_45AE5B7E_2569_4D8D_B221_E661576EC2FC)
	Set_User_Agent, ctype_func(Berry_HTTPS_Client_Class_Set_User_Agent_302ABE05_6FF6_4F19_B609_72D4DBEF4F1A)
	Set_Authorization, ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_F72246A1_1019_4085_8ED0_6138837C2AD7)
	Set_Authorization_Type, ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_Type_8FE17A70_5558_47D7_B949_A8AD25343D3B)
	Set_Connect_Timeout, ctype_func(Berry_HTTPS_Client_Class_Set_Connect_Timeout_5E0B873A_72C5_4609_9B0A_8B54F08F0FEE)
	Set_Timeout, ctype_func(Berry_HTTPS_Client_Class_Set_Timeout_1606879B_3218_4B52_AB9C_274CC414A388)
	Set_Follow_Redirects, ctype_func(Berry_HTTPS_Client_Class_Set_Follow_Redirects_FFCE3E36_9209_433E_9A63_09A3AC99733C)
	Set_Redirect_Limit, ctype_func(Berry_HTTPS_Client_Class_Set_Redirect_Limit_129E2F25_41BB_498C_9AD8_1DE5D6FADD9E)
	Set_URL, ctype_func(Berry_HTTPS_Client_Class_Set_URL_E04F34F5_FDDA_4816_A67C_DFC1FBD4DED3)
	Get_Header, ctype_func(Berry_HTTPS_Client_Class_Get_Header_7C082763_3610_4D43_BEA3_D362E2B23293)
	Get_Header_Name, ctype_func(Berry_HTTPS_Client_Class_Get_Header_Name_808E3BB9_E63C_471A_B98D_1AEE366980E2)
	Get_Header_Count, ctype_func(Berry_HTTPS_Client_Class_Get_Header_Count_1897E38D_092F_44A5_A2EF_99CF97799431)
	Get_Size, ctype_func(Berry_HTTPS_Client_Class_Get_Size_83633558_12C4_48B2_A22F_42015EFB31ED)
	Get_Location, ctype_func(Berry_HTTPS_Client_Class_Get_Location_50C1B44E_6A57_4AD5_9394_357AD8C0FA70)
	Get_String, ctype_func(Berry_HTTPS_Client_Class_Get_String_9CFC19E6_7633_49F2_A129_0EF7A9BE76E0)

}
@const_object_info_end */


extern "C"
{
	#include "../generate/be_fixed_Berry_HTTPS_Client_Type.h"
}
// - Functions

// - - Constructors
void * Berry_WiFi_Client_Class_Initialize_D1325362_E30E_4617_861A_1D7CC817CDA2(bvm* V)
{
void* Pointer = be_malloc(V, sizeof(Communication_Types::WiFi_Client_Class));
return new (Pointer) Communication_Types::WiFi_Client_Class(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Initialize_D1325362_E30E_4617_861A_1D7CC817CDA2, "+_p", "@");


// - - Destructors
void Berry_WiFi_Client_Class_Deinitialize_82997744_0414_4D77_8B08_FDBF6D12AF2C(bvm* V, Xila_Namespace::Communication_Types::WiFi_Client_Class* I)
{
if (!I) { return; }
I->~WiFi_Client_Class();
be_free(V, I, sizeof(Communication_Types::WiFi_Client_Class));
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Deinitialize_82997744_0414_4D77_8B08_FDBF6D12AF2C, "", "@.");


// - - Functions
int Berry_WiFi_Client_Class_Connect_0320BCEA_8AF0_4DF8_9A78_3DEA67D4B0BE(Xila_Namespace::Communication_Types::WiFi_Client_Class* I, const char* A_0, int A_1, int A_2 = 30000)
{
return (int)I->Connect(A_0, (short unsigned int)A_1, (int)A_2); 
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Connect_0320BCEA_8AF0_4DF8_9A78_3DEA67D4B0BE, "i", ".si[i");

void Berry_WiFi_Client_Class_Stop_F61B0014_EB18_4512_BC33_2566C595B350(Xila_Namespace::Communication_Types::WiFi_Client_Class* I)
{
return I->Stop(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Stop_F61B0014_EB18_4512_BC33_2566C595B350, "", ".");

bool Berry_WiFi_Client_Class_Connected_C4617B37_92DE_4967_A2BB_0BF1C04CEEF9(Xila_Namespace::Communication_Types::WiFi_Client_Class* I)
{
return I->Connected(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Connected_C4617B37_92DE_4967_A2BB_0BF1C04CEEF9, "b", ".");

const char* Berry_WiFi_Client_Class_Last_Error_5C1F3DAD_577A_4D77_B776_B07838A2610F(bvm* V, Xila_Namespace::Communication_Types::WiFi_Client_Class* I)
{
String_Type S_0;
S_0.Set_Buffer((char*)Berry_Class::Get_Instance(V)->Buffer, sizeof(Berry_Class::Buffer));
I->Last_Error(S_0); 
return S_0;
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Last_Error_5C1F3DAD_577A_4D77_B776_B07838A2610F, "s", "@.");

void Berry_WiFi_Client_Class_Set_Insecure_61C4F9A8_05F1_47E9_AE56_E6E264FB9728(Xila_Namespace::Communication_Types::WiFi_Client_Class* I)
{
return I->Set_Insecure(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Set_Insecure_61C4F9A8_05F1_47E9_AE56_E6E264FB9728, "", ".");

void Berry_WiFi_Client_Class_Set_Handshake_Timeout_9BDD8EFB_8828_4324_A8C6_70F9713BEF72(Xila_Namespace::Communication_Types::WiFi_Client_Class* I, int A_0)
{
return I->Set_Handshake_Timeout((unsigned int)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Set_Handshake_Timeout_9BDD8EFB_8828_4324_A8C6_70F9713BEF72, "", ".i");

void Berry_WiFi_Client_Class_Set_Timeout_161F7F8B_119D_42CE_8239_A724B507DABF(Xila_Namespace::Communication_Types::WiFi_Client_Class* I, int A_0)
{
return I->Set_Timeout((unsigned int)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Set_Timeout_161F7F8B_119D_42CE_8239_A724B507DABF, "", ".i");

int Berry_WiFi_Client_Class_Available_9FB22C4D_8049_4508_9E42_3E16FA6B73A6(Xila_Namespace::Communication_Types::WiFi_Client_Class* I)
{
return (int)I->Available(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Available_9FB22C4D_8049_4508_9E42_3E16FA6B73A6, "i", ".");

int Berry_WiFi_Client_Class_Peek_5B88FF4B_920A_4443_B3B1_B61EB2F9E92A(Xila_Namespace::Communication_Types::WiFi_Client_Class* I)
{
return (int)I->Peek(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Peek_5B88FF4B_920A_4443_B3B1_B61EB2F9E92A, "i", ".");

int Berry_WiFi_Client_Class_Read_15B4E9CB_C8EE_473E_A3A4_A83828E8AB81(Xila_Namespace::Communication_Types::WiFi_Client_Class* I)
{
return (int)I->Read(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Read_15B4E9CB_C8EE_473E_A3A4_A83828E8AB81, "i", ".");

const unsigned char* Berry_WiFi_Client_Class_Read_Bytes_C3F60A04_D3D1_4950_9ECB_6461B6D9E248(bvm* V, Xila_Namespace::Communication_Types::WiFi_Client_Class* I, int A_1)
{
unsigned char* S_0 = (unsigned char*)Berry_Class::Get_Instance(V)->Buffer;
I->Read_Bytes(S_0, (A_1 > sizeof(Berry_Class::Buffer)) ? sizeof(Berry_Class::Buffer) : A_1); 
return S_0;
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Read_Bytes_C3F60A04_D3D1_4950_9ECB_6461B6D9E248, "s", "@.i");

const char* Berry_WiFi_Client_Class_Read_String_102F120D_9777_45C2_84D8_F25F81E92D5C(bvm* V, Xila_Namespace::Communication_Types::WiFi_Client_Class* I)
{
String_Type S_0;
S_0.Set_Buffer((char*)Berry_Class::Get_Instance(V)->Buffer, sizeof(Berry_Class::Buffer));
I->Read_String(S_0); 
return S_0;
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Read_String_102F120D_9777_45C2_84D8_F25F81E92D5C, "s", "@.");

void Berry_WiFi_Client_Class_Flush_49D312B2_E1DC_4582_8BB1_F5C2267330B6(Xila_Namespace::Communication_Types::WiFi_Client_Class* I)
{
return I->Flush(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Flush_49D312B2_E1DC_4582_8BB1_F5C2267330B6, "", ".");

int Berry_WiFi_Client_Class_Write_7CC3F2AD_558F_4A84_B233_01C969E63924(Xila_Namespace::Communication_Types::WiFi_Client_Class* I, int A_0)
{
return (int)I->Write((unsigned char)A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Write_7CC3F2AD_558F_4A84_B233_01C969E63924, "i", ".i");

int Berry_WiFi_Client_Class_Write_Bytes_F7CAA55F_6EC4_4283_B02B_740CE9940587(Xila_Namespace::Communication_Types::WiFi_Client_Class* I, const unsigned char* A_0, int A_1)
{
return (int)I->Write_Bytes(A_0, (unsigned int)A_1); 
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Write_Bytes_F7CAA55F_6EC4_4283_B02B_740CE9940587, "i", ".si");

int Berry_WiFi_Client_Class_Write_String_1CA38511_E715_4AE0_B2DA_7C7B56284B46(Xila_Namespace::Communication_Types::WiFi_Client_Class* I, const char* A_0)
{
return (int)I->Write_String(A_0); 
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Write_String_1CA38511_E715_4AE0_B2DA_7C7B56284B46, "i", ".s");

// - - Operators
bool Berry_WiFi_Client_Class_Operator_5D39B95C_C5C3_40D7_AE87_D141426897B3(Xila_Namespace::Communication_Types::WiFi_Client_Class* I, Xila_Namespace::Communication_Types::WiFi_Client_Class* A_0)
{
return *I == *A_0;
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Operator_5D39B95C_C5C3_40D7_AE87_D141426897B3, "b", "..")

bool Berry_WiFi_Client_Class_Operator_5A8AD354_8C18_4261_88B5_1AE5BE2401E6(Xila_Namespace::Communication_Types::WiFi_Client_Class* I, Xila_Namespace::Communication_Types::WiFi_Client_Class* A_0)
{
return *I != *A_0;
}
BE_FUNC_CTYPE_DECLARE(Berry_WiFi_Client_Class_Operator_5A8AD354_8C18_4261_88B5_1AE5BE2401E6, "b", "..")


// - Berry declaration
/* @const_object_info_begin
class Berry_WiFi_Client_Type(scope:global, name:WiFi_Client_Type)
{
	_p, var
	init, ctype_func(Berry_WiFi_Client_Class_Initialize_D1325362_E30E_4617_861A_1D7CC817CDA2)
	deinit, ctype_func(Berry_WiFi_Client_Class_Deinitialize_82997744_0414_4D77_8B08_FDBF6D12AF2C)
	Connect, ctype_func(Berry_WiFi_Client_Class_Connect_0320BCEA_8AF0_4DF8_9A78_3DEA67D4B0BE)
	Stop, ctype_func(Berry_WiFi_Client_Class_Stop_F61B0014_EB18_4512_BC33_2566C595B350)
	Connected, ctype_func(Berry_WiFi_Client_Class_Connected_C4617B37_92DE_4967_A2BB_0BF1C04CEEF9)
	Last_Error, ctype_func(Berry_WiFi_Client_Class_Last_Error_5C1F3DAD_577A_4D77_B776_B07838A2610F)
	Set_Insecure, ctype_func(Berry_WiFi_Client_Class_Set_Insecure_61C4F9A8_05F1_47E9_AE56_E6E264FB9728)
	Set_Handshake_Timeout, ctype_func(Berry_WiFi_Client_Class_Set_Handshake_Timeout_9BDD8EFB_8828_4324_A8C6_70F9713BEF72)
	Set_Timeout, ctype_func(Berry_WiFi_Client_Class_Set_Timeout_161F7F8B_119D_42CE_8239_A724B507DABF)
	Available, ctype_func(Berry_WiFi_Client_Class_Available_9FB22C4D_8049_4508_9E42_3E16FA6B73A6)
	Peek, ctype_func(Berry_WiFi_Client_Class_Peek_5B88FF4B_920A_4443_B3B1_B61EB2F9E92A)
	Read, ctype_func(Berry_WiFi_Client_Class_Read_15B4E9CB_C8EE_473E_A3A4_A83828E8AB81)
	Read_Bytes, ctype_func(Berry_WiFi_Client_Class_Read_Bytes_C3F60A04_D3D1_4950_9ECB_6461B6D9E248)
	Read_String, ctype_func(Berry_WiFi_Client_Class_Read_String_102F120D_9777_45C2_84D8_F25F81E92D5C)
	Flush, ctype_func(Berry_WiFi_Client_Class_Flush_49D312B2_E1DC_4582_8BB1_F5C2267330B6)
	Write, ctype_func(Berry_WiFi_Client_Class_Write_7CC3F2AD_558F_4A84_B233_01C969E63924)
	Write_Bytes, ctype_func(Berry_WiFi_Client_Class_Write_Bytes_F7CAA55F_6EC4_4283_B02B_740CE9940587)
	Write_String, ctype_func(Berry_WiFi_Client_Class_Write_String_1CA38511_E715_4AE0_B2DA_7C7B56284B46)
	==, ctype_func(Berry_WiFi_Client_Class_Operator_5D39B95C_C5C3_40D7_AE87_D141426897B3)
	!=, ctype_func(Berry_WiFi_Client_Class_Operator_5A8AD354_8C18_4261_88B5_1AE5BE2401E6)

}
@const_object_info_end */


extern "C"
{
	#include "../generate/be_fixed_Berry_WiFi_Client_Type.h"
}
// - Functions
int Berry_Communication_Class_Start_958EAF9F_0497_4DFC_8586_4CE3B143DDBA()
{
return (int)Communication.Start(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Communication_Class_Start_958EAF9F_0497_4DFC_8586_4CE3B143DDBA, "i", "");


int Berry_Communication_Class_Stop_ADB46A2F_20C0_4B82_95D1_967312A36044()
{
return (int)Communication.Stop(); 
}
BE_FUNC_CTYPE_DECLARE(Berry_Communication_Class_Stop_ADB46A2F_20C0_4B82_95D1_967312A36044, "i", "");


void* Berry_Communication_Class_Get_Pointer()
{
	return (Module_Type*)&Communication;
}
BE_FUNC_CTYPE_DECLARE(Berry_Communication_Class_Get_Pointer, "c", "")

// - Berry declaration
/* @const_object_info_begin
module Communication (scope:global)
{
	Start, ctype_func(Berry_Communication_Class_Start_958EAF9F_0497_4DFC_8586_4CE3B143DDBA)
	Stop, ctype_func(Berry_Communication_Class_Stop_ADB46A2F_20C0_4B82_95D1_967312A36044)
	Get_Pointer, ctype_func(Berry_Communication_Class_Get_Pointer)

	IP_Address_Type, class(Berry_IP_Address_Type)

	HTTPS_Client_Type, class(Berry_HTTPS_Client_Type)

	WiFi_Client_Type, class(Berry_WiFi_Client_Type)

	HTTP_Code_Continue, int(100)
	HTTP_Code_Switching_Protocols, int(101)
	HTTP_Code_Processing, int(102)
	HTTP_Code_OK, int(200)
	HTTP_Code_Created, int(201)
	HTTP_Code_Accepted, int(202)
	HTTP_Code_Non_Authoritative_Information, int(203)
	HTTP_Code_No_Content, int(204)
	HTTP_Code_Reset_Content, int(205)
	HTTP_Code_Partial_Content, int(206)
	HTTP_Code_Multi_Status, int(207)
	HTTP_Code_Already_Reported, int(208)
	HTTP_Code_I_M_Used, int(226)
	HTTP_Code_Multiple_Choices, int(300)
	HTTP_Code_Moved_Permanently, int(301)
	HTTP_Code_Found, int(302)
	HTTP_Code_See_Other, int(303)
	HTTP_Code_Not_Modified, int(304)
	HTTP_Code_Use_Proxy, int(305)
	HTTP_Code_Temporary_Redirect, int(307)
	HTTP_Code_Permanent_Redirect, int(308)
	HTTP_Code_Bad_Request, int(400)
	HTTP_Code_Unauthorized, int(401)
	HTTP_Code_Payment_Required, int(402)
	HTTP_Code_Forbidden, int(403)
	HTTP_Code_Not_Found, int(404)
	HTTP_Code_Method_Not_Allowed, int(405)
	HTTP_Code_Not_Acceptable, int(406)
	HTTP_Code_Proxy_Authentication_Required, int(407)
	HTTP_Code_Request_Timeout, int(408)
	HTTP_Code_Conflict, int(409)
	HTTP_Code_Gone, int(410)
	HTTP_Code_Length_Required, int(411)
	HTTP_Code_Precondition_Failed, int(412)
	HTTP_Code_Payload_Too_Large, int(413)
	HTTP_Code_URI_Too_Long, int(414)
	HTTP_Code_Unsupported_Media_Type, int(415)
	HTTP_Code_Range_Not_Satisfiable, int(416)
	HTTP_Code_Expectation_Failed, int(417)
	HTTP_Code_Misdirected_Request, int(421)
	HTTP_Code_Unprocessable_Entity, int(422)
	HTTP_Code_Locked, int(423)
	HTTP_Code_Failed_Dependency, int(424)
	HTTP_Code_Upgrade_Required, int(426)
	HTTP_Code_Precondition_Required, int(428)
	HTTP_Code_Too_Many_Requests, int(429)
	HTTP_Code_Request_Header_Fields_Too_Large, int(431)
	HTTP_Code_Internal_Server_Error, int(500)
	HTTP_Code_Not_Implemented, int(501)
	HTTP_Code_Bad_Gateway, int(502)
	HTTP_Code_Service_Unavailable, int(503)
	HTTP_Code_Gateway_Timeout, int(504)
	HTTP_Code_HTTP_Version_Not_Supported, int(505)
	HTTP_Code_Variant_Also_Negotiates, int(506)
	HTTP_Code_Insufficient_Storage, int(507)
	HTTP_Code_Loop_Detected, int(508)
	HTTP_Code_Not_Extended, int(510)
	HTTP_Code_Network_Authentication_Required, int(511)

	Status_No_Shield, int(0)
	Status_Idle, int(1)
	Status_No_SSID_Available, int(2)
	Status_Scan_Completed, int(3)
	Status_Connected, int(4)
	Status_Connection_Failed, int(5)
	Status_Connection_Lost, int(6)
	Status_Disconnected, int(7)

	Mode_None, int(0)
	Mode_Station, int(1)
	Mode_Access_Point, int(2)
	Mode_Station_Access_Point, int(3)

	Authentication_Mode_Open, int(0)
	Authentication_Mode_WEP, int(1)
	Authentication_Mode_WPA_PSK, int(2)
	Authentication_Mode_WPA2_PSK, int(3)
	Authentication_Mode_WPA_WPA2_PSK, int(4)
	Authentication_Mode_WPA2_ENTERPRISE, int(5)
	Authentication_Mode_WPA3_PSK, int(6)
	Authentication_Mode_WPA2_WPA3_PSK, int(7)
	Authentication_Mode_WAPI_PSK, int(8)
	Authentication_Mode_MAX, int(9)

	WPA2_Authentication_Method_TLS, int(0)
	WPA2_Authentication_Method_PEAP, int(1)
	WPA2_Authentication_Method_TTLS, int(2)

}
@const_object_info_end */


extern "C"
{
	#include "../generate/be_fixed_Communication.h"
}