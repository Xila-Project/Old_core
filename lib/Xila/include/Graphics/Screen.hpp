/// @file Screen.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 30-03-2023
///
/// @copyright Copyright (c) 2023
///

#ifndef Screen_Hpp_Included
#define Screen_Hpp_Included

#include "Object.hpp"
#include <list>

namespace Xila_Namespace
{
    // - Forward declarations
    namespace Accounts_Types { typedef class User_Class User_Type; };

    namespace Softwares_Types
    {
        typedef class Software_Class Software_Type;
    };


    namespace Graphics_Types
    {
        typedef class Screen_Class : public Object_Class
        {
        public:
            // - Methods
            // - - Constructor / destructor
            Screen_Class();
            Screen_Class(const Softwares_Types::Software_Type* Owner_Software);
            Screen_Class(const Object_Class &Object_To_Copy);

            // - - Manipulation
            virtual void Create(Object_Class Parent_Object) override{};
            virtual void Create(const Softwares_Types::Software_Type *Owner_Software);
            virtual void Delete(bool Asynchronous = false) override;

            // - -
            void Load();

            // - - Setters
            virtual bool Set_Pointer(lv_obj_t* LVGL_Object_Pointer) override;

            // - - Static
            static Screen_Class Get_Active();
            static Screen_Class Get_User_Screen(const Accounts_Types::User_Type *User);

            // - Attributes
            static const Graphics_Types::Class_Type Class;

        protected:

        
            // - Attributes
            /// @brief
            static std::list<Screen_Class *> List;

        } Screen_Type;
    }
}

#endif // Screen_Hpp_Included