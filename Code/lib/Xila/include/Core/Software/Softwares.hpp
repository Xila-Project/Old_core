///
 /// @file Software_Managment.hpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 25-02-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

#ifndef Software_Managment_Hpp_Included
#define Software_Managment_Hpp_Included

#include "../Module/Module.hpp"

#include "Software.hpp"
#include "Software_Handle.hpp"

#include "Software.hpp"
#include <vector>

namespace Xila_Namespace
{

    namespace Softwares_Types
    {
        enum class Event_Code_Type : uint8_t
        {
            Open,
            Close
        };

    };

    typedef class Softwares_Class : public Module_Class
    {
    public:
        // - Methods

        Result_Type Start();
        Result_Type Stop();

        // - - Operations

        Result_Type Open(const Softwares_Types::Software_Handle_Type* Handle, const Accounts_Types::User_Type* Owner_User = NULL);
        Result_Type Open(const char* Name, const Accounts_Types::User_Type* Owner_User = NULL);
        Result_Type Close(Softwares_Types::Software_Type* Software);
        Result_Type Kill(Softwares_Types::Software_Type* Software);

        Softwares_Types::Software_Type* Find(const Softwares_Types::Software_Handle_Type* Handle);
        Softwares_Types::Software_Handle_Type* Find_Handle(const char* Name);  

        Softwares_Types::Software_Type* Get(uint8_t Index);
        const Softwares_Types::Software_Handle_Type* Get_Handle(uint8_t Index);

        uint8_t Get_Count();
        uint8_t Get_Handle_Count();

        void Close_User_Softwares(const Accounts_Types::User_Type* User);
        void Kill_User_Softwares(const Accounts_Types::User_Type* User);
        void Send_Instruction_User_Softwares(const Accounts_Types::User_Type* User, const Instruction_Type& Instruction);
        void Send_Instruction_Softwares(const Instruction_Type& Instruction);
        uint8_t Get_User_Softwares_Count(const Accounts_Types::User_Type* User);
        const Softwares_Types::Software_Type* Get_User_Softwares(const Accounts_Types::User_Type* User, uint8_t Index);
    } Softwares_Type;

    extern Softwares_Type Softwares;

}

#endif