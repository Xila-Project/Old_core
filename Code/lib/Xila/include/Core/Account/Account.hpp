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

        enum State_Type {
        
            Logged,
            Locked
        };


        typedef class User_Class
        {
        public:
            User_Class(const char *Name);

            void Set_State(State_Type State);
            State_Type Get_State();

            void Logout();
            void Lock();

        private:
            char Name[16];
            State_Type State;
        

        } User_Type;

        static std::vector<User_Type> List;


        Result::Type Check_Credentials(const char *, const char *);

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

        Result::Type Load_Registry();
    } Account;

}

#endif