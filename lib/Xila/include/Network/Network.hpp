///
/// @file Communication.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Communication_Hpp_Included
#define Communication_Hpp_Included

#include "IP_Address.hpp"
#include "WiFi.hpp"
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
      /// @param Index 
      /// @return 
      Network_Types::Interface_Type* Get_Connected_Interface(Natural_Type Index = 0);

      
   } Network_Type;

   /// @brief Communication module instance.
   extern Network_Type Network;
}

#endif
