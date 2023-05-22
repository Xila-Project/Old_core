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

#include <list>
#include "../Module/Module.hpp"

/// @class Software_Handle
///
/// @brief Software handle used by Xila to manage each software.
namespace Xila_Namespace
{

    typedef class Softwares_Class Softwares_Type;

    // - Forward declaration
    namespace Accounts_Types
    {
        typedef class User_Class User_Type;
    };

    namespace Softwares_Types
    {

        typedef class Software_Handle_Class
        {
        public:
            // - Methods

            // - - Constructors / destructor

            Software_Handle_Class() = delete;

            /// @brief Construct a new Software_Handle_Class object
            /// @param Name 
            Software_Handle_Class(const char *Name);

             /// @brief Destroy the Software_Handle_Class object
            ~Software_Handle_Class();

            // - - Getters

            /// @brief Get the software name.
            /// @param Name 
            /// @return String_Type String
            String_Type &Get_Name(String_Type &Name) const;

            /// @brief Create a new instance of software.
            /// @details This function is called by the Accounts module to open a software.
            /// @param Owner_User 
            virtual void Create_Instance(const Accounts_Types::User_Type *Owner_User) const;

        private:
            // - Attributes

            /// @brief A linked list that contains all of the registered softwares handle.
            static std::list<Software_Handle_Class*> List;

            /// @brief Software string name.
            Static_String_Type<Default_Software_Name_Length> Name; // used to identify the software,

            friend class Xila_Namespace::Softwares_Class;
            friend class Software_Class;
        } Software_Handle_Type;

    }

}

#endif