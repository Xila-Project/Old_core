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

#include "../Configuration/Configuration.hpp"
#include <vector>
#include "../Module.hpp"

//==============================================================================//
///
/// @class Software_Handle
///
/// @brief Software handle used by Xila to manage each software.
///

namespace Xila_Namespace
{
    typedef class Software_Handle_Class : public Module_Class
    {
    public:

        // - Types

        typedef void (*Create_Instance_Function_Pointer)();

        // -- Constructors / Destructor
        Software_Handle_Class();
        Software_Handle_Class(const char *Software_Name, void (*Create_Instance_Function)());

        Result::Type Create_Instance();

        const char *Get_Name() const;
        Create_Instance_Function_Pointer Get_Pointer_Create_Instance() const;

        /// -- Methods -- //
        bool Is_Equal(Software_Handle_Class const &Software_Handle_To_Compare) const;

   // protected:
        static std::vector<Software_Handle_Class *> List;

        // - Attributes

        ///
        /// @brief Software string name.
        ///
        char Name[Default_Software_Name_Length]; // used to identify the software,

        ///
        /// @brief Function pointer called by Xila to load software.
        /// @details Function allocate memory and return allocated software memory pointer and then send an "Open" instruction in the queue.
        ///
        void (*Create_Instance_Pointer)();
    } Software_Handle_Type;

    bool operator==(Software_Handle_Class const &a, Software_Handle_Class const &b);

    bool operator!=(Software_Handle_Class const &a, Software_Handle_Class const &b);

}

#endif