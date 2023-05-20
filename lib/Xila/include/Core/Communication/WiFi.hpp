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

#include "IP_Address.hpp"
#include "WiFi_Client.hpp"

namespace Xila_Namespace
{

    /// @brief WiFi types
    namespace Communication_Types
    {
        /// @brief WiFi status type
        enum class Status_Type
        {
            No_Shield,
            Idle,
            No_SSID_Available,
            Scan_Completed,
            Connected,
            Connection_Failed,
            Connection_Lost,
            Disconnected
        };

        /// @brief WiFi mode type
        enum class Mode_Type
        {
            None,
            Station,
            Access_Point,
            Station_Access_Point
        };

        /// @brief WiFi authentication mode type
        enum class Authentication_Mode_Type
        {
            Open,
            WEP,
            WPA_PSK,         /**< authenticate mode : WPA_PSK */
            WPA2_PSK,        /**< authenticate mode : WPA2_PSK */
            WPA_WPA2_PSK,    /**< authenticate mode : WPA_WPA2_PSK */
            WPA2_ENTERPRISE, /**< authenticate mode : WPA2_ENTERPRISE */
            WPA3_PSK,        /**< authenticate mode : WPA3_PSK */
            WPA2_WPA3_PSK,   /**< authenticate mode : WPA2_WPA3_PSK */
            WAPI_PSK,        /**< authenticate mode : WAPI_PSK */
            MAX
        };

        /// @brief WPA2 authentication method type
        enum class WPA2_Authentication_Method_Type
        {
            TLS,
            PEAP,
            TTLS
        };

        /// @brief WiFi class
        typedef class WiFi_Class : public Module_Class
        {
        public:
            // - Methods
            // - - Constructors / destructors

            /// @brief Default constructor.
            WiFi_Class();

            /// @brief Start the WiFi module.
            /// @return `Result_Type::Success` if the module has been started, `Result_Type::Error` otherwise.
            Result_Type Start();

            /// @brief Stop (and turn off) the WiFi module.
            /// @return `Result_Type::Success` if the module has been stopped, `Result_Type::Error` otherwise.
            Result_Type Stop();

            // - - Managment

            /// @brief Turn on the WiFi module.
            void Turn_Off();

            // - - Getters

            /// @brief Get the channel of the current WiFi connection.
            /// @return Channel of the current WiFi connection.
            int32_t Get_Channel();

            /// @brief Get the current WiFi mode.
            /// @return `WiFi_Types::Mode_Type` of the current WiFi mode.
            Mode_Type Get_Mode();

            /// @brief Get the current WiFi transmission power.
            /// @return Current WiFi transmission power in dBm.
            int16_t Get_Transmission_Power();

            /// @brief Get the host name.
            /// @param Host_Name Reference to a `String_Type` where the host name will be stored.
            String_Type &Get_Host_Name(String_Type &Host_Name);

            // - - Setters

            /// @brief Set the WiFi long range mode.
            /// @param Enable `true` to enable long range mode, `false` to disable it.
            void Set_Long_Range(bool Enable);

            /// @brief Set the WiFi transmission power.
            /// @param Power Transmission power in dBm.
            /// @return `Result_Type::Success` if the transmission power has been set, `Result_Type::Error` otherwise.
            Result_Type Set_Transmission_Power(int16_t Power);

            /// @brief Set the host name.
            /// @param Host_Name Host name.
            /// @return `Result_Type::Success` if the host name has been set, `Result_Type::Error` otherwise.
            Result_Type Set_Host_Name(const char* Host_Name);

            // Result_Type Set_Antennas(uint8_t GPIO_1, uint8_t GPIO_2);
            // - -

            // - Sub classes

            /// @brief Station sub-module.
            class Station_Class
            {
            public:
                // - Methods
                // - - Constructors / destructors

                /// @brief Default constructor.
                Station_Class();

                /// @brief Turn on the station.
                void Turn_On();

                /// @brief Connect to a WiFi network (async).
                /// @param SSID SSID of the network to connect to.
                /// @param Password Password of the network to connect to.
                /// @param Channel Channel of the network to connect to.
                /// @param BSSID An array of 6 bytes containing the BSSID of the network to connect to.
                void Connect(const char*SSID, const char*Password = "", int32_t Channel = 0, const uint8_t *BSSID = NULL);

                // Result_Type Connect(const char* WPA2_SSID, WiFi_Types::WPA2_Authentication_Method_Type, const char* Identity = NULL, const char* Username = NULL, const char* Password = NULL, const char* CA_PEM = NULL, const char* Client_CRT = NULL, const char* Client_Key = NULL, int32_t Channel = 0, const uint8_t* BSSID = 0);

                /// @brief Disconnect from the current WiFi network.
                /// @return `Result_Type::Success` if the WiFi network has been disconnected, `Result_Type::Error` otherwise.
                Result_Type Disconnect();

                // - - Registry

                /// @brief Remove a network from the registry.
                /// @param SSID SSID of the network to remove.
                /// @param Channel Channel of the network to remove.
                /// @return `Result_Type::Success` if the network has been removed, `Result_Type::Error` otherwise.
                Result_Type Remove(const char*SSID, int32_t Channel = 0);

                /// @brief Add a network to the registry.
                /// @param SSID SSID of the network to add.
                /// @param Password Password of the network to add.
                /// @param Channel Channel of the network to add.
                /// @param BSSID An array of 6 bytes containing the BSSID of the network to add.
                /// @return `Result_Type::Success` if the network has been added, `Result_Type::Error` otherwise.
                Result_Type Add(const char*SSID, const char*Password, int32_t Channel = 0, const uint8_t *BSSID = NULL);

                /// @brief Check if a network is known in the registry.
                /// @param SSID SSID of the network to check.
                /// @param Password Password of the network to check.
                /// @param Channel Channel of the network to check.
                /// @return `true` if the network is known, `false` otherwise.
                bool Is_Known(const char*SSID, const char*Password = String_Type(), int32_t Channel = 0);

                // - - Getters

                /// @brief Get the current WiFi reconnection mode.
                /// @return `true` if the WiFi reconnection mode is automatic, `false` otherwise.
                bool Get_Automatic_Reconnection();

                /// @brief Get the current WiFi connection status.
                /// @param Wait_For_Connect `true` to wait for the connection to be established, `false` otherwise.
                /// @param Timeout Timeout in milliseconds.
                /// @return `WiFi_Types::Status_Type` of the current WiFi connection status.
                Status_Type Get_Status(bool Wait_For_Connect = false, uint32_t Timeout = 30000);

                // - - - Station

                /// @brief Get the SSID of the current WiFi connection.
                /// @param SSID Reference to a `String_Type` where the SSID will be stored.
                /// @return Reference to the `String_Type` containing the SSID.
                String_Type &Get_SSID(String_Type &SSID);

                /// @brief Get the pre-shared key of the current WiFi connection.
                /// @param Pre_Shared_Key Reference to a `String_Type` where the pre-shared key will be stored.
                String_Type &Get_Pre_Shared_Key(String_Type &Pre_Shared_Key);

                /// @brief Get the BSSID of the current WiFi connection.
                /// @param BSSID Pointer to a `uint8_t` array of 6 bytes where the BSSID will be stored.
                uint8_t *Get_BSSID();

                /// @brief Get the channel of the current WiFi connection.
                /// @return Channel of the current WiFi connection.
                int8_t Get_RSSI();

                // - - - Network configuration

                /// @brief Get the MAC address.
                /// @param MAC_Address Pointer to a `uint8_t` array of 6 bytes where the MAC address will be stored.
                uint8_t *Get_MAC_Address(uint8_t *MAC_Address);

                /// @brief Get the IP address.
                /// @param IPv6 `true` to get the IPv6 address, `false` to get the IPv4 address.
                IP_Address_Type Get_IP_Address(bool IPv6 = false);

                /// @brief Get the subnet mask.
                /// @return Subnet mask.
                IP_Address_Type Get_Subnet_Mask();

                /// @brief Get the gateway IP address.
                /// @return Gateway IP address.
                IP_Address_Type Get_Gateway_IP_Address();

                /// @brief Get the DNS IP address.
                /// @param Index Index of the DNS IP address to get.
                /// @return DNS IP address.
                IP_Address_Type Get_DNS_IP_Address(uint8_t Index);

                /// @brief Get the broadcast IP address.
                /// @return Broadcast IP address.
                IP_Address_Type Get_Broadcast_IP_Address();

                IP_Address_Type Get_Network_ID();

                /// @brief Get the subnet CIDR.
                /// @return Subnet CIDR.
                uint8_t Get_Subnet_CIDR();

                // - - Setters

                // - - - Network configuration

                /// @brief Set the network configuration.
                /// @param IP_Address IP address.
                /// @param Subnet_Mask Subnet mask.
                /// @param Gateway Gateway IP address.
                /// @param DNS_1_IP_Address First DNS IP address.
                /// @param DNS_2_IP_Address Second DNS IP address.
                /// @return `Result_Type::Success` if the network configuration has been set, `Result_Type::Error` otherwise.
                Result_Type Set_Configuration(IP_Address_Type IP_Address, IP_Address_Type Subnet_Mask, IP_Address_Type Gateway, IP_Address_Type DNS_1_IP_Address = static_cast<uint32_t>(0x00000000), IP_Address_Type DNS_2_IP_Address = static_cast<uint32_t>(0x00000000));

                /// @brief Set the automatic reconnection mode.
                /// @param Enable `true` to enable the automatic reconnection mode, `false` to disable it.
                /// @return `Result_Type::Success` if the automatic reconnection mode has been set, `Result_Type::Error` otherwise.
                bool Set_Automatic_Reconnection(bool Enable);

                /// @brief Set the WiFi scan method when connecting to a network.
                /// @param Fast `true` to use the fast scan method (the first network found will be used), `false` to use the normal scan method (all networks will be scanned and the best one will be used).
                void Set_Scan_Method(bool Fast);

                /// @brief Set the WiFi sort method when connecting to a network.
                /// @param Signal `true` to use the signal sort method (the network with the best signal will be used), `false` to use the normal sort method.
                void Set_Sort_Method(bool Signal);

            private:
                // - Attributes

                /// @brief Network IP version.
                bool IP_v6;

                IP_Address_Type IP_Address, Subnet_Mask, Gateway_IP_Address, DNS_1_IP_Address, DNS_2_IP_Address;

                friend class WiFi_Class;
            } Station;

            /// @brief Access point sub-module.
            class Access_Point_Class
            {
            public:
                // - Methods

                /// @brief Default constructor.
                Access_Point_Class();

                // - - Managment

                /// @brief Create an access point.
                /// @param SSID SSID of the access point.
                /// @param Password Password of the access point.
                /// @param Channel Channel of the access point.
                /// @param Hidden `true` to hide the access point, `false` otherwise.
                /// @param Maximum_Stations Maximum number of stations that can be connected to the access point.
                /// @param FTM_Responder `true` to enable FTM responder, `false` otherwise.
                Result_Type Create(const char*SSID, const char*Password = "", int32_t Channel = 1, bool Hidden = 0, uint8_t Maximum_Stations = 4, bool FTM_Responder = false);

                // - - Getters

                /// @brief Get the SSID of the access point.
                /// @param SSID Reference to a `String_Type` where the SSID will be stored.
                /// @return Reference to the `String_Type` containing the SSID.
                String_Type &Get_SSID(String_Type &SSID);

                /// @brief Get the password of the access point.
                /// @param Password Reference to a `String_Type` where the password will be stored.
                /// @return Reference to the `String_Type` containing the password.
                String_Type &Get_Password(String_Type &Password);

                /// @brief Get the channel of the access point.
                /// @return Channel of the access point.
                uint8_t Get_Channel();

                /// @brief Get the hidden state of the access point.
                /// @return `true` if the access point is hidden, `false` otherwise.
                bool Get_Hidden();

                /// @brief Get the maximum number of stations that can be connected to the access point.
                /// @return Maximum number of stations that can be connected to the access point.
                uint8_t Get_Maximum_Stations();

                /// @brief Get the current number of stations connected to the access point.
                /// @return Current number of stations connected to the access point.
                uint8_t Get_Station_Number();

                /// @brief Get the IP address of the access point.
                /// @return IP address of the access point.
                IP_Address_Type Get_IP_Address();

                /// @brief Get the subnet mask of the access point.
                /// @return Subnet mask of the access point.
                IP_Address_Type Get_Subnet_Mask();

                /// @brief Get the gateway IP address of the access point.
                /// @return Gateway IP address of the access point.
                IP_Address_Type Get_Gateway_IP_Address();

                /// @brief Get the DHCP lease start IP address.
                /// @return DHCP lease start IP address.
                IP_Address_Type Get_DHCP_Start_IP_Address();

                /// @brief Get the broadcast IP address.
                /// @return Broadcast IP address.
                IP_Address_Type Get_Broadcast_IP_Address();

                /// @brief Get the network ID.
                /// @return Network ID.
                IP_Address_Type Get_Network_ID();

                /// @brief Get the subnet CIDR.
                /// @return Subnet CIDR.
                uint8_t Get_Subnet_CIDR();

                // - - Setters

                /// @brief Set the use of the IP v6 protocol.
                /// @param Enable `true` to enable IP v6 protocol, `false` to disable it.
                Result_Type Set_IP_v6(bool Enable = true);

                /// @brief Get the MAC address of the access point.
                /// @param MAC_Address A pointer to an array of 6 byte where the MAC address will be stored.
                /// @return Pointer to the `uint8_t` array containing the MAC address.
                uint8_t *Get_MAC_Address(uint8_t *MAC_Address);

                /// @brief Set the network configuration of the access point.
                /// @param Local_IP Local IP address.
                /// @param Gateway Gateway IP address.
                /// @param Subnet Subnet mask.
                /// @param DHCP_Lease_Start_IP_Address DHCP lease start IP address.
                /// @return `Result_Type::Success` if the network configuration has been set, `Result_Type::Error` otherwise.
                Result_Type Set_Configuration(IP_Address_Type Local_IP, IP_Address_Type Gateway, IP_Address_Type Subnet, IP_Address_Type DHCP_Lease_Start_IP_Address = static_cast<uint32_t>(0));

            private:
                bool IP_v6;
                Static_String_Type<64> Password;
                int32_t Channel;
                bool Hidden;
                uint8_t Maximum_Stations;

                IP_Address_Type IP_Address, Subnet_Mask, Gateway_IP_Address, DHCP_Lease_Start_IP_Address;

                friend class WiFi_Class;

            } Access_Point;

            /// @brief Scan sub-module.
            class Scan_Class
            {
            public:
                // - Methods

                // - - Managment

                /// @brief Start a scan of the available networks.
                /// @param Asynchronous `true` to start the scan asynchronously, `false` to wait  for the result of the scan.
                /// @param Show_Hidden `true` to show hidden networks, `false` otherwise.
                /// @param Passive `true` to perform a passive scan, `false` otherwise.
                /// @param Maximum_Milliseconds_Per_Channel Maximum number of milliseconds to spend on each channel.
                /// @param Channel Channel to scan.
                /// @param SSID SSID to scan.
                /// @param BSSID BSSID to scan.
                /// @return The number of networks found or (-1) if the scan is not complete.
                int16_t Start(bool Asynchronous = false, bool Show_Hidden = false, bool Passive = false, uint32_t Maximum_Milliseconds_Per_Channel = 300, uint8_t Channel = 0, const char*SSID = NULL, const uint8_t *BSSID = NULL);

                /// @brief Check if the scan is complete.
                /// @return `true` if the scan is complete, `false` otherwise.
                bool Is_Complete();

                /// @brief Get the result of the scan.
                /// @return The number of networks found or (-1) if the scan is not complete.
                int16_t Get_Result();

                /// @brief Delete the cached scan result.
                void Delete();

                // - - Getters

                /// @brief Get all of the informations about a network.
                /// @param Index Index of the network.
                /// @param SSID Reference to a `String_Type` where the SSID will be stored.
                /// @param Encryption_Type Reference to a `WiFi_Types::Authentication_Mode_Type` where the encryption type will be stored.
                /// @param RSSI Reference to an `int32_t` where the RSSI will be stored.
                /// @param BSSID Reference to a `uint8_t` array where the BSSID will be stored.
                /// @param Channel Reference to an `int32_t` where the channel will be stored.
                /// @return `Result_Type::Success` if the informations have been retrieved, `Result_Type::Error` otherwise.
                Result_Type Get_Informations(uint8_t Index, String_Type &SSID, uint8_t &Encryption_Type, int32_t &RSSI, uint8_t *&BSSID, int32_t &Channel);

                /// @brief Get the SSID of a network.
                /// @param Index Index of the network.
                /// @param SSID Reference to a `String_Type` where the SSID will be stored.
                /// @return Reference to the `String_Type` containing the SSID.
                String_Type &Get_SSID(uint8_t Index, String_Type &SSID);

                /// @brief Get the encryption type of a network.
                /// @param Index Index of the network.
                /// @return The encryption type of the network.
                Authentication_Mode_Type Get_Encryption(uint8_t Index);

                /// @brief Get the RSSI of a network.
                /// @param Index Index of the network.
                /// @return The RSSI of the network in dBm.
                int32_t Get_RSSI(uint8_t Index);

                /// @brief Get the BSSID of a network.
                /// @param Index Index of the network.
                /// @return Pointer to an array of 6 byte containing the BSSID.
                uint8_t *Get_BSSID(uint8_t Index);

                /// @brief Get the channel of a network.
                /// @param Index Index of the network.
                /// @return The channel of the network.
                int32_t Get_Channel(uint8_t Index);
            } Scan;

        private:
            // - Attributes
            // - - Registry

            Result_Type Create_Registry();
            Result_Type Load_Registry();
            Result_Type Save_Registry();

            bool Long_Range;

        } WiFi_Type;

    }
}

#endif