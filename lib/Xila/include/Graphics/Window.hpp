/// @file Window.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 06-05-2022
///
/// @copyright Copyright (c) 2022

#ifndef Window_Hpp_Included
#define Window_Hpp_Included

#include <list>

#include "Object.hpp"
#include "Button.hpp"
#include "Label.hpp"

#include "Software/Software.hpp"
#include "Account/Accounts.hpp"

namespace Xila_Namespace
{

    namespace Graphics_Types
    {
        /// @brief Window event codes.
        enum class Window_State_Type
        {
            Minimized,  ///< Window is minimized.
            Windowed,   ///< Window is windowed.
            Maximized,  ///< Window is maximized.
            Full_screen ///< Window is full screen.
        };

        typedef class Window_Class : public Object_Class
        {
        public:
            // - Methods
            // - - Constructors / destructors

            /// @brief Default constructor.
            Window_Class();

            /// @brief Copy constructor to allow conversion from object.
            Window_Class(const Object_Class &Object_To_Copy);

            // - - Manipulation

            /// @brief Create a new window with a parent object.
            virtual void Create(Object_Class Parent_Object) override;

            /// @brief Create a new parent window for software.
            /// @param Owner_Module Pointer to the software that owns the window (usually `this`).
            virtual void Create(const Softwares_Types::Software_Type *Owner_Module);

            /// @brief Delete the window.
            /// @param Asynchronous If true, the deletion will be asynchronous.
            virtual void Delete(bool Asynchronous = false) override;

            // - - Setters

            /// @brief Set the title of the window.
            /// @param Title Title of the window.
            void Set_Title(const char *Title);

            /// @brief Set the pointer of the object.
            /// @param LVGL_Object_Pointer
            /// @return
            virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

            /// @brief Set the state of the window.
            /// @param State State of the window.
            virtual void Set_State(Window_State_Type State);

            // - - Getters

            /// @brief Set the state of the minimize button.
            /// @param Hidden State of the minimize button.
            void Set_Minimize_Button_Hidden(bool Hidden);

            /// @brief Set the state of the close button.
            /// @param Hidden State of the close button.
            void Set_Close_Button_Hidden(bool Hidden);

            /// @brief Get the state of the window.
            /// @return State of the window.
            Window_State_Type Get_State();

            /// @brief Get the body of the window.
            /// @return Body of the window.
            Object_Type Get_Body();

            /// @brief Get the header of the window.
            /// @return Header of the window.
            Object_Type Get_Header();

            /// @brief Get the close button of the window.
            /// @return Close button of the window.
            Button_Type Get_Close_Button();

            /// @brief Get the minimize button of the window.
            /// @return Minimize button of the window.
            Button_Type Get_Minimize_Button();

            /// @brief Get the title label of the window.
            /// @return Title label of the window.
            const Softwares_Types::Software_Type *Get_Owner_Software() const;

            /// @brief Window event callback.
            /// @param Event Pointer to the event.
            static void Event_Callback(lv_event_t *Event);

            // - Attributes

            /// @brief Custom LVGL class for Window (almost identical to object class).
            static const Class_Type Class;

        protected:
            // - Methods
            // - - Setters

            /// @brief Set the interface of the object.
            void Set_Interface();

            /// @brief Custom data structure for window that contains all the data.
            /// @note This structure is registered in the LVGL user data.
            typedef struct Data_Structure
            {
                Object_Type Header;
                Object_Type Body;
                Label_Type Title_Label;
                Button_Type Close_Button;
                Button_Type Minimize_Button;
                const Softwares_Types::Software_Type *Owner_Software;
            } Data_Type;

            /// @brief Pointer to the data structure.
            Data_Type *Data;
        } Window_Type;

    };
}

#endif