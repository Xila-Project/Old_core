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
        /// @brief Session state type enumeration.
        enum class User_State_Type
        {
            Undefined, ///< Undefined state.
            Logged,    ///< Logged
            Locked     ///< Locked
        };

        /// @brief User class.
        typedef class User_Class
        {
        public:
            // - Methods
            // - - Constructor / destructor

            /// @brief Construct a new User_Class object.
            /// @param Name User name.
            /// @param State User state.
            User_Class(const char *Name, User_State_Type State = User_State_Type::Undefined);

            /// @brief Copy constructor.
            /// @param User User to copy.
            User_Class(const User_Class &User);

            /// @brief Move constructor.
            /// @param User User to move.
            User_Class(User_Class &&User);

            // - - Getters

            /// @brief Get the state of the user.
            /// @return User_State_Type User state.
            User_State_Type Get_State() const;

            /// @brief Get the name of the user.
            /// @param Name Name output string.
            /// @return String_Type& Name output string.
            String_Type &Get_Name(String_Type &Name) const;

            /// @brief Get the home folder path of the user.
            /// @param Home_Folder_Path Home folder path output string.
            /// @return String_Type& Home folder path output string.
            String_Type &Get_Home_Folder_Path(String_Type &Home_Folder_Path) const;

            // - - Setters

            /// @brief Log the user and lock the system user.
            void Login();

            /// @brief Lock the user and log the system user.
            void Lock();

            /// @brief Logout the user and log the system user.
            void Logout();

            // - - Operators

            /// @brief Equality operator.
            /// @param User User to compare.
            /// @return true if the users are equals.
            bool operator==(const User_Class &User) const;

            /// @brief Inequality operator.
            /// @param User User to compare.
            /// @return true if the users are not equals.
            bool operator!=(const User_Class &User) const;

            Static_String_Type<16> Name;

        private:
            // - Methods

            /// @brief Set the name of the user.
            /// @param Name Name to set.
            void Set_Name(const char *Name);

            // - Attributes

            /// @brief User state.
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

        /// @brief Create a new user.
        /// @param User_Name User name to create.
        /// @param Password User password to create.
        /// @return Result_Type 'Result_Type::Success' if the user has been created, 'Result_Type::Error' otherwise.
        Result_Type Create(const char *User_Name, const char *Password);

        /// @brief Delete a user.
        /// @param User_Name User name to delete.
        /// @param Password User password to delete.
        /// @return Result_Type 'Result_Type::Success' if the user has been deleted, 'Result_Type::Error' otherwise.
        Result_Type Delete(const char *User_Name, const char *Password);

        /// @brief Login a user.
        /// @param Username User name to login.
        /// @param Password User password to login.
        /// @param Lock_Other_User Lock other user if true.
        /// @return Result_Type 'Result_Type::Success' if the user has been logged, 'Result_Type::Error' otherwise.
        Result_Type Login(const char *Username, const char *Password = "", bool Lock_Other_User = true);

        /// @brief Change the name of a user.
        /// @param Current_Name Current user name.
        /// @param New_Name New user name.
        /// @param Password User password.
        /// @return Result_Type 'Result_Type::Success' if the user name has been changed, 'Result_Type::Error' otherwise.
        Result_Type Change_Name(const char *Current_Name, const char *New_Name, const char *Password);
      
        /// @brief Change the password of a user.
        /// @param User_Name User name to change the password.
        /// @param Old_Password Old password.
        /// @param New_Password New password.
        /// @return Result_Type 'Result_Type::Success' if the password has been changed, 'Result_Type::Error' otherwise.
        Result_Type Change_Password(const char *User_Name, const char *Old_Password, const char *New_Password);

        /// @brief Check credentials of a user.
        /// @param User_Name User name to check.
        /// @param Password User password to check.
        /// @return Result_Type 'Result_Type::Success' if the credentials are correct, 'Result_Type::Error' otherwise.
        Result_Type Check_Credentials(const char *User_Name, const char *Password = "");

        // - - Getters

        /// @brief Get the logged user.
        /// @return const Accounts_Types::User_Type* Pointer to the logged user.
        const Accounts_Types::User_Type *Get_Logged_User();

        /// @brief Get connected user from index.
        /// @param Index Index of the user to get.
        /// @return const Accounts_Types::User_Type* Pointer to the user.
        const Accounts_Types::User_Type *Get_User(uint8_t Index);

        /// @brief Get the number of connected users.
        /// @return uint8_t Number of users.
        uint8_t Get_User_Count();

        /// @brief Find index of a user.
        /// @param Name Name of the user to find.
        /// @return uint8_t Index of the user.
        uint8_t Find_User(const char *Name);

        // - - Setters

        /// @brief Set autologin for a user.
        /// @param Enable Autologin enable.
        /// @param Name User name.
        /// @param Password User password.
        /// @return Result_Type 'Result_Type::Success' if the autologin has been set, 'Result_Type::Error' otherwise.
        Result_Type Set_Autologin(bool Enable, const char *Name, const char *Password);
        
        /// @brief Set autologin for a user.
        /// @return Result_Type 'Result_Type::Success' if the autologin has been set, 'Result_Type::Error' otherwise.
        const char *Get_Autologin_User_Name();

    private:
        // - Methods

        // - - Encryption

        /// @brief Function that hash a password 10 times in SHA-512 format.
        /// @param Password Password to hash.
        /// @param Hash Hash output (must have a size of 64 bytes).
        /// @return 'Result_Type::Success' if the password has been hashed, 'Result_Type::Error' otherwise.
        Result_Type Hash_Password(const char *Password, uint8_t *Hash);

        /// @brief A method that salt a password (add a pepper character and a string at it's end).
        /// @param Password Password input and output string.
        /// @param Pepper_Character Pepper character that will be added at the end of the password.
        /// @return 'Result_Type::Success' if the password has been salted, 'Result_Type::Error' if the password is too long.
        String_Type &Salt_Password(String_Type &Password, char Pepper_Character);

        // - - Registry

        /// @brief Load the module registry.
        /// @return Result_Type 'Result_Type::Success' if the registry has been loaded, 'Result_Type::Error' otherwise.
        Result_Type Load_Registry();

        /// @brief Save the module registry.
        /// @return Result_Type 'Result_Type::Success' if the registry has been saved, 'Result_Type::Error' otherwise.
        Result_Type Save_Registry();

        /// @brief Create the module registry.
        /// @return Result_Type 'Result_Type::Success' if the registry has been created, 'Result_Type::Error' otherwise.
        Result_Type Create_Registry();

        // - Attributes
        
        /// @brief Linked list of users.
        std::list<Accounts_Types::User_Type> User_List;

        // - Friendships
        friend class Accounts_Types::User_Class;
    } Accounts_Type;

    extern Accounts_Type Accounts;
}

#endif