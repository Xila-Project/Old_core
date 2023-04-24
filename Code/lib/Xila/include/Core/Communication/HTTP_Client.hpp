 /// @file HTTPS_Client.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 14-04-2023
 /// 
 /// @copyright Copyright (c) 2023
 
#include "HTTPClient.h"
#include "WiFiClientSecure.h"

 namespace Xila_Namespace
 {
    namespace Communication_Types
    {
        typedef class HTTPS_Client_Class
        {
        public:

            HTTPS_Client_Class();
            ~HTTPS_Client_Class();

        private:

            HTTPClient Client;
        } HTTPS_Client_Type;
    }
 }