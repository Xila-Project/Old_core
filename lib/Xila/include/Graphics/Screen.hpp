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

            /// @brief Default constructor.
            Screen_Class();

            /// @brief Constructor.
            /// @param Owner_Software Pointer to the software that owns the screen (usually Shell).
            Screen_Class(const Softwares_Types::Software_Type* Owner_Software);

            /// @brief Copy constructor to allow conversion from object.
            /// @param Object_To_Copy Object to copy.
            Screen_Class(const Object_Class &Object_To_Copy);

            // - - Manipulation

            /// @brief Create a new window with a parent object.
            /// @note This method has no use for screen, it's just here to override the parent method.
            /// @param Parent_Object Parent object.
            virtual void Create(Object_Class Parent_Object) override{};

            /// @brief Create a new screen.
            /// @param Owner_Software Pointer to the software that owns the screen (usually `this`).
            virtual void Create(const Softwares_Types::Software_Type *Owner_Software);
            
            /// @brief Delete the screen.
            /// @param Asynchronous `true` if the deletion should be asynchronous.
            virtual void Delete(bool Asynchronous = false) override;

            // - -

            /// @brief Load the screen (show it and hide the others).
            void Load();

            // - - Setters

            /// @brief Set the screen pointer.
            virtual bool Set_Pointer(lv_obj_t* LVGL_Object_Pointer) override;

            // - - Static

            /// @brief Get the active screen.
            /// @return `Screen_Type`.
            static Screen_Class Get_Active();

            /// @brief Get the screen of a software.
            /// @param User Pointer to the software.
            /// @return `Screen_Type`.
            static Screen_Class Get_User_Screen(const Accounts_Types::User_Type *User);

            // - Attributes

            /// @brief Custom LVGL class for Screen (almost identical to object class).
            static const Graphics_Types::Class_Type Class;

        protected:

        
            // - Attributes

            /// @brief Linked list of all screens.
            static std::list<Screen_Class *> List;

        } Screen_Type;
    }
}

#endif // Screen_Hpp_Included