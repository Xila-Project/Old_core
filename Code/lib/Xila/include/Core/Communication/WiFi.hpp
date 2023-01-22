///
/// @file WiFi.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef WiFi_Hpp_Included
#define WiFi_Hpp_Included

#include "../Module.hpp"

//==============================================================================//
///
/// @brief WiFi class
///

namespace Xila_Namespace
{
    

    typedef class WiFi_Class : public Module_Class
    {
    public:
        // - Types
     
        enum class Status_Type {
            Ready,
            Scan_Done,
            Station_Start,
            Station_Stop,
            Station_Connect,
            Station_Disconnected,
            Station_Authentication_Mode_Changed,
            Station_Got_IP,
            Station_Got_IP_V6,
            Station_Lost_IP,
            Station_WPS_Enrolment_Success,
            Station_WPS_Enrolment_Failed,
            Station_WPS_Enrolment_Timeout,
            Station_WPS_Enrolment_Pin,
            Access_Point_Start,
            Access_Point_Stop,
            Access_Point_Station_Connected,
            Access_Point_Station_IP_Assigned,
            Access_Point_Probe_Request_Received,
            Access_Point_Got_IP_V6
        };
     
        // - Constructors / Destructors
        WiFi_Class();

        // - Methods

        Status_Type Connect(const char* SSID, const char* Password = NULL, int32_t Channel = 0, const uint8_t* BSSID = NULL, bool Connect = true);
        Status_Type Connect(char* SSID, char* Password = NULL, int32_t Channel = 0, const uint8_t* BSSID = NULL, bool Connect = true)

        // - - Getters

        // - - - Network configuration

        IP_Address_Type Get_IP_Address();
        //IP_Address_Type Get_Subnet_Mask();
        //IP_Address_Type Get_Gateway();
        //IP_Address_Type Get_DNS();
             

        // - - Setters

        void Set_Credentials(const char *Name, const char *Password);

        // - - - Network configuration

        Result_Type Set_Configuration(IP_Address_Type IP_Address, IP_Address_Type Subnet_Mask, IP_Address_Type Gateway);
        Result_Type Set_Configuration(IP_Address_Type IP_Address, IP_Address_Type Subnet_Mask, IP_Address_Type Gateway, IP_Address_Type DNS_1, IP_Address_Type DNS_2);

        void Set_IP_Address(IP_Address_Type IP_Address);
        void Set_Subnet_Mask(IP_Address_Type Subnet_Mask);
        void Set_Gateway(IP_Address_Type Gateway);
        void Set_DNS(IP_Address_Type DNS);


        void Use_Static_Buffers(bool Status);


        int16_t Scan_Networks(bool Async = false, bool Show_Hidden = false, bool Passive = false, uint32_t Max_Ms_Per_Channel = 300, uint8_t Channel = 0);
        int16_t Scan_Complete();
        void Scan_Delete();
        void Get_Network_Informations(uint8_t Network_Item, String& SSID, uint8_t& Encryption_Type, int32_t& RSSI, uint8_t* BSSID, int32_t& Channel);
        
        
        void Set_Mode(uint8_t Mode);
        
        void Set_Channel(uint8_t Channel);
        void Set_Power(uint8_t Power);
        void Set_Power_Save(bool Status);
        void Set_Sleep(bool Status);
        void Set_Sleep_Type(uint8_t Type);
        void Set_Max_TX_Power(uint8_t Power);
        void Set_Phy_Mode(uint8_t Mode);
        void Set_Phy_Rate(uint8_t Rate);
        void Set_Phy_Bandwidth(uint8_t Bandwidth);
        void Set_Phy_Coding_Rate(uint8_t Coding_Rate);
        void Set_Phy_Tx_Power(uint8_t Power);
        void Set_Phy_Tx_Power_Level(uint8_t Level);


        static Result_Type Load_Registry();
        static Result_Type Save_Registry();

    protected:
        ///
        /// @brief Access point password.
        ///
        char Password[82];

        friend class Shell_Class;
    } WiFi_Type;

    extern WiFi_Type WiFi;

}

#endif