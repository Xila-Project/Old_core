#ifndef Dialog_Hpp_Included
#define Dialog_Hpp_Included

#include "Window.hpp"
#include "Color_Wheel.hpp"
#include "Object.hpp"
#include "Button.hpp"
#include "Label.hpp"
#include "Object.hpp"

namespace Xila_Namespace
{

    namespace Graphics_Types
    {
        typedef class Dialog_Class : public Window_Class
        {
        public:
            // - Methods
            
            Dialog_Class();
            Dialog_Class(const Object_Class &Object_To_Copy);

            virtual void Create(const Softwares_Types::Software_Type* Owner_Software) override;
            virtual void Create(Object_Class Parent_Object) override;

            // - - Getters

            bool Is_Overlay();

            // - - Setters

            void Set_Overlay(bool Enable);

        private:
            Object_Type Overlay;

            /// @brief Custom LVGL class for Window (almost identical to object class).
            static const Class_Type Class;
        } Dialog_Type;

        typedef class Color_Dialog_Class : public Dialog_Class
        {
        public:
            // - Methods
            virtual void Create(Object_Class Parent_Object) override;

            // - - Getters

            Color_Type Get_Color();

            // - - Setters

            void Set_Color(Color_Type Color);

        private:
            Color_Wheel_Type Color_Wheel;

        } Color_Dialog_Type;

        typedef class Progress_Dialog_Class : public Dialog_Class
        {
        public:
            virtual void Create(Object_Class Parent_Object) override;

        } Progress_Dialog_Type;

        typedef class Message_Dialog_Class : public Dialog_Class
        {
        public:
            virtual void Create(Object_Class Parent_Object) override;

        } Message_Dialog_Type;

    };

}

#endif