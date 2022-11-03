///
/// @file Account.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Account_Hpp_Included
#define Account_Hpp_Included

#include "../Module.hpp"

namespace Xila_Namespace
{

    ///
    /// @brief Account management class
    ///
    class Account_Class : public Module_Class
    {
    public:
        // -- Constructor
        Account_Class();

        ///
        /// @brief Session state type
        ///
        typedef enum Session_Enumeration
        {
            Disconnected,
            Logged,
            Locked
        } Session_State;

        Result::Type Check_Credentials(const char *, const char *);

        // -- Getter
        const char *Get_Current_Username();

        Session_State Get_State();

        // protected:
        ///
        /// @brief Loaded username.
        ///
        char Current_Username[9];

        ///
        /// @brief Session state.
        ///
        Session_State State;

        // -- Methods

        Result::Type Add(const char *Username, const char *Password);
        Result::Type Delete(const char *);
        Result::Type Change_Password(const char *, const char *);
        Result::Type Change_Username(const char *, const char *);
        Result::Type Set_Autologin(bool Enable);
        Result::Type Login(const char *Username_To_Check = NULL, const char *Password_To_Check = NULL);
        Result::Type Logout();
        Result::Type Lock();

        // -- Setter

        void Set_Current_Username(const char *Username);
        void Set_State(Session_State State);

        Result::Type Load_Registry();
    } Account;

}

#endif