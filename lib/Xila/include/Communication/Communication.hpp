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

namespace Xila_Namespace
{
   namespace Communication_Types
   {

   }

   /// @brief Communication module class.
   typedef class Communication_Class
   {
   public:

      /// @brief Start the communication module and sub-modules.
      /// @return `Result_Type`
      Result_Type Start();

      /// @brief Stop the communication module and sub-modules.
      /// @return `Result_Type`
      Result_Type Stop();

      /// @brief WiFi sub-module instance.
      Communication_Types::WiFi_Type WiFi;
      
   } Communication_Type;

   /// @brief Communication module instance.
   extern Communication_Type Communication;
}

#endif
