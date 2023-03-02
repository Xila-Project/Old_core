///
/// @file Accounts.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Account_Hpp_Included
#define Account_Hpp_Included

#include "../Module/Module.hpp"
#include <list>

namespace Xila_Namespace
{
    // - Types

    typedef class Accounts_Class Accounts_Type;

    /// @brief Namespace that contains all accounts's types.
    namespace Accounts_Types
    {
        /// @brief Account instruction code type enumeration.
        enum class Instructions_Code_Type
        {
            // - User specific instructions code.
            Locked,
            Unlocked,
            Logged,
            Logout,
            Changed_Name
        };

        /// @brief Session state type enumeration.
        enum class User_State_Type
        {
            Undefined,
            Logged,
            Locked
        };

        /// @brief User class.
        typedef class User_Class
        {
        public:
            // - Methods
            // - - Constructor / destructor
            User_Class(const String_Type &Name, User_State_Type State = User_State_Type::Undefined);

            // - - Getters
            User_State_Type Get_State() const;
            void Get_Name(String_Type &Name) const;
            void Get_Home_Folder_Path(String_Type &Home_Folder_Path) const;

            // - - Setters

            void Login();
            void Lock();
            void Logout();

            // - - Operators
            bool operator==(const User_Class &User) const;
            bool operator!=(const User_Class &User) const;

        private:
            // - Methods

            void Set_Name(const String_Type &Name);

            // - Attributes
            Static_String_Type<16> Name;
            User_State_Type State;

            friend class Xila_Namespace::Accounts_Class;
        } User_Type;

    };

    /// @brief Account manager class
    typedef class Accounts_Class : public Module_Class
    {
    public:
        // - Methods

        Result_Type Start();
        Result_Type Stop();

        // - - Management

        Result_Type Create(const String_Type &User_Name, const String_Type &Password);
        Result_Type Delete(const String_Type &User_Name, const String_Type &Password);
        Result_Type Login(const String_Type &Username, const String_Type &Password = "", bool Lock_Other_User = true);
        Result_Type Change_Name(const String_Type &Current_Name, const String_Type &New_Name, const String_Type &Password);
        Result_Type Change_Password(const String_Type &User_Name, const String_Type &Old_Password, const String_Type &New_Password);
        Result_Type Check_Credentials(const String_Type &User_Name, const String_Type &Password = "");

        // - - Getters
        const Accounts_Types::User_Type *Get_Logged_User();
        const Accounts_Types::User_Type *Get_User(uint8_t Index);
        uint8_t Get_User_Count();
        uint8_t Find_User(const String_Type &Name);

        // - - Setters
        Result_Type Set_Autologin(bool Enable, const String_Type &Name, const String_Type &Password);
        const String_Type &Get_Autologin_User_Name();

    private:
        // - Methods
        // - - Registry
        Result_Type Load_Registry();
        Result_Type Save_Registry();
        Result_Type Create_Registry();
        // - Attributes
        std::list<Accounts_Types::User_Type> User_List;

        // - Friendships
        friend class Accounts_Types::User_Class;
    } Accounts_Type;

    extern Accounts_Type Accounts;
}

#endif