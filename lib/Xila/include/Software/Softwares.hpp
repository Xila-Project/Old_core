/// @file Software_Managment.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 25-02-2023
///
/// @copyright Copyright (c) 2023

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

        /// @brief Start the module.
        /// @return Result_Type
        Result_Type Start();

        /// @brief Stop the module.
        /// @return Result_Type
        Result_Type Stop();

        // - - Operations

        /// @brief Register a software handle.
        /// @param Software_Handle Software handle.
        void Register_Handle(Softwares_Types::Software_Handle_Type &Software_Handle);

        /// @brief Open a software.
        /// @param Handle Handle of the software to open.
        /// @param Owner_User Owner of the software.
        /// @return Result_Type
        Result_Type Open(const Softwares_Types::Software_Handle_Type *Handle, const Accounts_Types::User_Type *Owner_User = NULL);

        /// @brief Open a software.
        /// @param Name Name of the software to open.
        /// @param Owner_User Owner of the software.
        /// @return Result_Type
        Result_Type Open(const char *Name, const Accounts_Types::User_Type *Owner_User = NULL);

        /// @brief Close a software.
        /// @param Software Software instance pointer to close.
        /// @return Result_Type
        Result_Type Close(Softwares_Types::Software_Type *Software);

        /// @brief Kill a software (directly call its destructor)
        /// @param Software Software instance pointer to close.
        /// @return Result_Type
        Result_Type Kill(Softwares_Types::Software_Type *Software);

        /// @brief Get the software instance pointer from its handle.
        /// @param Handle Handle of the software to get.
        /// @return NULL if not found, software instance pointer if found.
        Softwares_Types::Software_Type *Find(const Softwares_Types::Software_Handle_Type *Handle);

        /// @brief Get the software handle pointer from its name.
        /// @param Name Name of the software to get.
        /// @return NULL if not found, software instance pointer if found.
        Softwares_Types::Software_Handle_Type *Find_Handle(const char *Name);

        /// @brief Close all opened softwares of a user.
        /// @param User User to close softwares.
        void Close_User_Softwares(const Accounts_Types::User_Type *User);

        /// @brief Kill all opened softwares of a user.
        /// @param User User to kill softwares.
        void Kill_User_Softwares(const Accounts_Types::User_Type *User);

        /// @brief Send an instruction to all opened softwares owned by a given user.
        /// @param User Owner of the softwares.
        /// @param Instruction Instruction to send to softwares.
        void Send_Instruction_User_Softwares(const Accounts_Types::User_Type *User, const Instruction_Type &Instruction);

        /// @brief Send an instruction to all opened softwares.
        /// @param Instruction Instruction to send to softwares.
        void Send_Instruction_Softwares(const Instruction_Type &Instruction);

        // - - Getters

        /// @brief Get the opened software instance pointer from its index.
        /// @param Index Index of the software to get.
        /// @return NULL if out of range, software instance pointer if found.
        Softwares_Types::Software_Type *Get(uint8_t Index);

        /// @brief Get the opened software instance pointer owned by a user from its index.
        /// @param User Owner of the software.
        /// @param Index Index of the software to get.
        /// @return NULL if out of range, software instance pointer if found.
        const Softwares_Types::Software_Type *Get_User_Softwares(const Accounts_Types::User_Type *User, uint8_t Index);
        const Softwares_Types::Software_Handle_Type *Get_Handle(Size_Type Index);

        /// @brief Get the total count of opened softwares.
        /// @return uint8_t Softwares count.
        uint8_t Get_Count();

        /// @brief Get the total count of opened softwares owned by a given user.
        /// @param User Owner of the softwares.
        /// @return uint8_t Softwares count.
        uint8_t Get_Handle_Count();

        /// @brief Get the total count of registered software handles.
        /// @return uint8_t Software handles count.
        uint8_t Get_User_Softwares_Count(const Accounts_Types::User_Type *User);

    } Softwares_Type;

    extern Softwares_Type Softwares;

}

#endif