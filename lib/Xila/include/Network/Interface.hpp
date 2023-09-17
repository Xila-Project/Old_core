/// @file Interface.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 04-08-2023
///
/// @copyright Copyright (c) 2023

#ifndef Xila_Network_Interface_Hpp_Included
#define Xila_Network_Interface_Hpp_Included

#include "IP_Address.hpp"
#include "Client.hpp"

namespace Xila_Namespace
{
    typedef class Network_Class Network_Type;

    namespace Network_Types
    {
        enum class State_Type
        {
            Disconnected,
            Connected,
            Connecting,
            Disconnecting,
            Error
        };

        enum class Interface_Type_Type
        {
            WiFi,
            Ethernet,
            Cellular
        };

        typedef class Interface_Class
        {
        protected:

            static Interface_Class* First_Instance_Pointer;
            Interface_Class* Next_Instance_Pointer;
            
        public:
            // - Methods

            // - - Constructor / Destructor
            
            Interface_Class();
            virtual ~Interface_Class();

            // - - 

            virtual Result_Type Start() = 0;
            virtual Result_Type Stop() = 0;

            // - - Getters

            virtual State_Type Get_State() = 0;

            // - - - IP

            virtual IP_Address_Type Get_IP_Address(bool IPv6 = false) = 0;
            virtual IP_Address_Type Get_Gateway_IP_Address() = 0;
            virtual IP_Address_Type Get_Subnet_Mask() = 0;
            virtual IP_Address_Type Get_DNS_IP_Address(Natural_Type Index) = 0;
            virtual Byte_Type Get_Subnet_CIDR() = 0;
            virtual bool Is_IPv6() = 0;

            virtual Client_Type& Create_Client() = 0;



            // - - Setters

            virtual void Set_State(State_Type State) = 0;

            /// @brief Set the network configuration.
            /// @param IP_Address IP address.
            /// @param Subnet_Mask Subnet mask.
            /// @param Gateway Gateway IP address.
            /// @param DNS_1_IP_Address First DNS IP address.
            /// @param DNS_2_IP_Address Second DNS IP address.
            /// @return `Result_Type::Success` if the network configuration has been set, `Result_Type::Error` otherwise.
            virtual Result_Type Set_Configuration(IP_Address_Type IP_Address, IP_Address_Type Subnet_Mask, IP_Address_Type Gateway, IP_Address_Type DNS_1_IP_Address = static_cast<uint32_t>(0x00000000), IP_Address_Type DNS_2_IP_Address = static_cast<uint32_t>(0x00000000)) = 0;

             /// @brief Set the host name of the device over the interface.
             /// @param Host_Name 
             /// @return Result_Type `Result_Type::Success` if the host name has been setted successfully. 
            virtual Result_Type Set_Host_Name(const char* Host_Name) = 0;

             /// @brief Get the host name of the device over the interface. 
             /// @param Host_Name String to store the host name.
             /// @return String_Type& Host name. 
            virtual String_Type& Get_Host_Name(String_Type& Host_Name) = 0;

            friend class Xila_Namespace::Network_Class;
        } Interface_Type;       
    }
}

#endif // Xila_Interface_Hpp_Included