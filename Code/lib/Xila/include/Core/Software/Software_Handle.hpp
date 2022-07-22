///
/// @file Software_Handle.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Software_Handle_Hpp_Included
#define Software_Handle_Hpp_Included

#include "Configuration.hpp"
#include "vector"
#include "../Module.hpp"

class Software_Class;

//==============================================================================//
///
/// @class Software_Handle
///
/// @brief Software handle used by Xila to manage each software.
///
class Software_Handle : public Module_Class
{
public:
    // -- Constructors / Destructor
    Software_Handle();
    Software_Handle(const char *Software_Name, Software_Class* (*Load_Function_Pointer)(), void (*Startup_Function_Pointer)() = NULL);



    Result_Type Open(Software_Handle const &Software_Handle);
    void Minimize(Software_Handle const &Software_Handle);
    Result_Type Maximize(Software_Handle const &);
    void Close(Software_Handle const &Software_Handle);

    Result_Type Force_Close(Software_Handle const &Software_Handle);

    uint8_t Get_Software_Handle(Software_Handle const &);
    void Add_Handle(Software_Handle &);

    void Feed_Watchdog(Software_Handle const &Software_Handle);

    /// -- Methods -- //
    bool Is_Equal(Software_Handle const &Software_Handle_To_Compare) const;

protected:

    // - Attributes
   
    ///
    /// @brief Software string name.
    ///
    char Name[Default_Software_Name_Length]; // used to identify the software,


    ///
    /// @brief Function pointer called by Xila to load software.
    /// @details Function allocate memory and return allocated software memory pointer and then send an "Open" instruction in the queue.
    ///
    Software_Class *(*Load_Function_Pointer)();

    ///
    /// @brief Function pointer that is called by Xila at startup.
    /// @details That is usefull to start a background task, or launch your application at the startup.
    ///
    void (*Startup_Function_Pointer)();

    // -- Friendship 
    friend class Xila_Class;
    friend class Shell_Class;
    friend class Unit_Test_Class;
};

bool operator==(Software_Handle const &a, Software_Handle const &b);

#endif