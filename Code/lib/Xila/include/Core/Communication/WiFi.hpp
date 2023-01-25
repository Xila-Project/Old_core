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

#include "../Module/Module.hpp"

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
     
        enum class Status_Type : uint8_t {
            No_Shield,
            Idle,
            No_SSID_Available,
            Scan_Completed,
            Connected,
            Connection_Failed,
            Connection_Lost,
            Disconnected
        };
     
        // - Constructors / Destructors
        WiFi_Class();

        // - Methods

        Status_Type Connect(const char* SSID, const char* Password = NULL, int32_t Channel = 0, const uint8_t* BSSID = NULL, bool Connect = true);
        Status_Type Connect(char* SSID, char* Password = NULL, int32_t Channel = 0, const uint8_t* BSSID = NULL, bool Connect = true);

        // - - Getters

        Status_Type Get_Status();

        bool Get_Automatic_Reconnection();

        // - - - Network configuration

        uint8_t* Get_MAC_Address();

        IP_Address_Type Get_IP_Address(bool IPv6 = false);
        IP_Address_Type Get_Subnet_Mask();
        IP_Address_Type Get_Gateway_IP_Address();
        IP_Address_Type Get_DNS_IP_Address(uint8_t Index);
             

        IP_Address_Type Get_Broadcast_IP_Address();
        IP_Address_Type Get_Network_ID();
        uint8_t Get_Subnet_CIDR();

        const char* Get_SSID();
        const char* Get_Password();
        uint8_t* Get_BSSID();
        int8_t Get_RSSI();

        // - - Setters

        // - - - Network configuration

        Result_Type Set_Configuration(IP_Address_Type IP_Address, IP_Address_Type Subnet_Mask, IP_Address_Type Gateway);
        Result_Type Set_Configuration(IP_Address_Type IP_Address, IP_Address_Type Subnet_Mask, IP_Address_Type Gateway, IP_Address_Type DNS_1, IP_Address_Type DNS_2);

        void Set_IP_Address(IP_Address_Type IP_Address);
        void Set_Subnet_Mask(IP_Address_Type Subnet_Mask);
        void Set_Gateway(IP_Address_Type Gateway);
        void Set_DNS(IP_Address_Type DNS);

        void Set_Hostname(const char* Hostname);

        void Use_Static_Buffers(bool Status);


        int16_t Scan_Networks(bool Async = false, bool Show_Hidden = false, bool Passive = false, uint32_t Max_Ms_Per_Channel = 300, uint8_t Channel = 0);
        int16_t Scan_Complete();
        void Scan_Delete();
        void Get_Network_Informations(uint8_t Network_Item, String& SSID, uint8_t& Encryption_Type, int32_t& RSSI, uint8_t* BSSID, int32_t& Channel);
        
        
        void Set_Automatic_Reconnection(bool Enable);
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