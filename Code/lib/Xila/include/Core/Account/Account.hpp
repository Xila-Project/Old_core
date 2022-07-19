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

///
/// @brief Account management class
///
class Account_Class
{
public:

    

    // -- Constructor
    Account_Class();

    ///
    /// @brief Session state type
    ///
    typedef enum
    {
        Disconnected,
        Logged,
        Locked
    } Session_State;

    Xila_Class::Event Check_Credentials(const char *, const char *);

    // -- Getter
    const char *Get_Current_Username();
    uint8_t Get_State();

    friend class Xila_Class;
    friend class Shell_Class;
    friend class Unit_Test_Class;

protected:
    ///
    /// @brief Loaded username.
    ///
    char Current_Username[9];

    ///
    /// @brief Session state.
    ///
    Session_State State;

    // -- Methods

    static Xila_Class::Event Add(const char *Username, const char *Password);
    static Xila_Class::Event Delete(const char *);
    static Xila_Class::Event Change_Password(const char *, const char *);
    static Xila_Class::Event Change_Username(const char *, const char *);
    static Xila_Class::Event Set_Autologin(bool Enable);
    static Xila_Class::Event Login(const char *Username_To_Check = NULL, const char *Password_To_Check = NULL);
    static Xila_Class::Event Logout();
    static Xila_Class::Event Lock();

    // -- Setter

    void Set_Current_Username(const char *Username);
    void Set_State(Session_State State);

    Xila_Class::Event Load_Registry();

};

#endif