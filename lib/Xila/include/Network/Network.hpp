///
/// @file Communication.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Xila_Network_Hpp_Included
#define Xila_Network_Hpp_Included

#include "IP_Address.hpp"
#include "./WiFi/Client.hpp"
#include "./WiFi/Interface.hpp"
#include "HTTP_Client.hpp"

#include "Interface.hpp"

namespace Xila_Namespace
{
   namespace Network_Types
   {

   }

   /// @brief Communication module class.
   typedef class Network_Class
   {
   public:

      /// @brief Start the communication module and sub-modules.
      /// @return `Result_Type`
      Result_Type Start();

      /// @brief Stop the communication module and sub-modules.
      /// @return `Result_Type`
      Result_Type Stop();

      /// @brief 
      /// @param Index 
      /// @return 
      Network_Types::Interface_Type* Get_Interface(Natural_Type Index = 0);

       /// @brief 
       /// 
      Natural_Type Get_Interface_Count();

      /// @brief Get interface from the connected one's.
      /// @param Index 
      /// @return 
      Network_Types::Interface_Type* Get_Connected_Interface(Natural_Type Index = 0);

      /// @brief Get the count of the connected interfaces.
      /// @return Count of the connected interface.
      Natural_Type Get_Connected_Interface_Count();

      /// @brief Set host name of the device over all interfaces.
      /// @param Host_Name
      /// @return `Result_Type::Success` if the host name has been setted successfully.
      Result_Type Set_Host_Name(const char* Host_Name);

      /// @brief Get host name of the device over all interfaces.
      /// @param Host_Name 
      /// @return `Result_Type::Success` if the host name has been getted successfully.
      String_Type& Get_Host_Name(String_Type& Host_Name);

      
   } Network_Type;

   /// @brief Communication module instance.
   extern Network_Type Network;
}

#endif
