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

#include <array>
#include "../Module/Module.hpp"

//==============================================================================//
///
/// @class Software_Handle
///
/// @brief Software handle used by Xila to manage each software.
///

namespace Xila_Namespace
{
    // - Forward declaration
    namespace Accounts_Types
    {
        typedef class User_Class User_Type;
    };

    typedef class Software_Handle_Class : public Module_Class
    {
    public:

        // - Methods

        // - - Constructors / destructor
        Software_Handle_Class(const String_Type& Software_Name);
        ~Software_Handle_Class();

        // - - Getters
        void Get_Name(String_Type& Name) const;

        virtual void Create_Instance() const;
        bool Is_Equal(const Software_Handle_Class &Software_Handle_To_Compare) const;

        // - - Operators
        bool operator==(const Software_Handle_Class &Software_Handle_To_Compare) const;
        bool operator!=(const Software_Handle_Class &Software_Handle) const;


    private:
        // - Attributes

        /// @brief Array containing all of the software handles.
        /// @details This is a static array in order to avoid dynamic allocation since it's modified at early startup (when static Software handle constructor are called) before dynamic allocation system is initialized. 
        static std::array<Software_Handle_Class*, 40> List;

        /// @brief Software string name.        
        Static_String_Type<Default_Software_Name_Length> Name; // used to identify the software,

        friend class Softwares_Class;
    } Software_Handle_Type;


}

#endif