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

// - Constants

#ifndef Maximum_Password_Length
    #define Maximum_Password_Length 32
#endif
#ifndef Maximum_Username_Length
    #define Maximum_Username_Length 16
#endif

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
            User_Class(const char*Name, User_State_Type State = User_State_Type::Undefined);
            User_Class(const User_Class &User);
            User_Class(User_Class&& User);


            // - - Getters
            User_State_Type Get_State() const;
            String_Type& Get_Name(String_Type &Name) const;
            String_Type& Get_Home_Folder_Path(String_Type &Home_Folder_Path) const;

            // - - Setters

            void Login();
            void Lock();
            void Logout();

            // - - Operators
            bool operator==(const User_Class &User) const;
            bool operator!=(const User_Class &User) const;

            Static_String_Type<16> Name;
        private:
            // - Methods

            void Set_Name(const char*Name);

            // - Attributes
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

        Result_Type Create(const char*User_Name, const char*Password);
        Result_Type Delete(const char*User_Name, const char*Password);
        Result_Type Login(const char*Username, const char*Password = "", bool Lock_Other_User = true);
        Result_Type Change_Name(const char*Current_Name, const char*New_Name, const char*Password);
        Result_Type Change_Password(const char*User_Name, const char*Old_Password, const char*New_Password);
        Result_Type Check_Credentials(const char*User_Name, const char*Password = "");

        // - - Getters
        const Accounts_Types::User_Type *Get_Logged_User();
        const Accounts_Types::User_Type *Get_User(uint8_t Index);
        uint8_t Get_User_Count();
        uint8_t Find_User(const char*Name);

        // - - Setters
        Result_Type Set_Autologin(bool Enable, const char*Name, const char*Password);
        const char*Get_Autologin_User_Name();

    private:
        // - Methods
        // - - Encryption

        /// @brief Function that hash a password 10 times in SHA-512 format.
        /// @param Password Password to hash.
        /// @param Hash Hash output (must have a size of 64 bytes).
        /// @return 'Result_Type::Success' if the password has been hashed, 'Result_Type::Error' otherwise.
        Result_Type Hash_Password(const char*Password, uint8_t* Hash);
       
        /// @brief A method that salt a password (add a pepper character and a string at it's end).
        /// @param Password Password input and output string.
        /// @param Pepper_Character Pepper character that will be added at the end of the password.
        /// @return 'Result_Type::Success' if the password has been salted, 'Result_Type::Error' if the password is too long.
        String_Type& Salt_Password(String_Type &Password, char Pepper_Character);

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