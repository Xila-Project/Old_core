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
        // - Types

        /// @brief Account instruction code type enumeration.
        enum class Instructions_Code
        {
            // - User specific instructions code.
            Locked,
            Unlocked,
            Logged,
            Logout,
            Changed_Name
        };

        /// @brief Session state type enumeration.
        enum class State_Type
        {
            Logged,
            Locked
        };

        /// @brief User class.
        typedef class User_Class
        {
        public:
            User_Class(const char *Name, State_Type State);

            State_Type Get_State() const;
            const char *Get_Name() const;

        private:
            void Set_State(State_Type State);
            void Set_Name(const char *Name);

            static std::vector<User_Class> List;

            char Name[16];
            State_Type State;

            friend class Account_Class;

        } User_Type;

        // -- Constructor
        Account_Class();

        // -- Methods

        Result_Type Create(const char *User_Name, const char *Password);
        Result_Type Delete(const char *User_Name, const char *Password);
        Result_Type Change_Name(const char *Current_Name, const char *New_Name, const char *Password);
        Result_Type Change_Password(const char *User_Name, const char *Old_Password, const char *New_Password);

        Result_Type Check_Credentials(const char *User_Name, const char *Password);
        Result_Type Login(const char *Username, const char *Password, bool Lock_Other_User);

        // - - - Getters
        const User_Type *Get_Logged_User();
        const User_Type *Get_User(uint8_t Index);

        // - - - Setters

        Result_Type Set_Autologin(bool Enable, const char *Name, const char *Password);
        const char *Get_Autologin_User_Name();

        Result_Type Login(const char *Username_To_Check = NULL, const char *Password_To_Check = NULL);
        Result_Type Logout(const char *Name);
        Result_Type Lock(const char *Name);

        // -- Setter

        Result_Type Load_Registry();
    } Account;

}

#endif