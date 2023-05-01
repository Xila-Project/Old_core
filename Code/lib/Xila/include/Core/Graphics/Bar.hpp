///
/// @file Bar.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 04-05-2022
///
/// @copyright Copyright (c) 2022
///

///
/// @brief Create a new bar.
///
/// @param Parent Parent object of the new bar.
/// @param Copy Object to copy from.
/// @return Object

#include "Object.hpp"

#ifndef Bar_Hpp_Included
#define Bar_Hpp_Included

namespace Xila_Namespace
{
    namespace Graphics_Types
    {
    /// @brief Bar class.
    typedef class Bar_Class : public Object_Class
    {
    public:
        // -- Types

        class Mode
        {
        public:
            /// @brief Bar mode type.
            typedef lv_bar_mode_t Type;

            /// @brief Bar mode enumeration.
            enum Enumeration
            {
                Normal = LV_BAR_MODE_NORMAL,
                Symmetrical = LV_BAR_MODE_SYMMETRICAL,
                Range = LV_BAR_MODE_RANGE
            };
        };

        class Draw_Part
        {
        public:
            /// @brief Draw part type and enumeration.
            typedef enum Enumeration
            {
                Indicator = LV_BAR_DRAW_PART_INDICATOR
            } Type;
        };

        // - Methods

        // - - Constructors / destructors

        /// @brief Default constructor.
        Bar_Class();

        /// @brief Copy constructor to allow conversion from object.
        Bar_Class(const Object_Class &Object_To_Copy);

        // - - Manipulation

        /// @brief Create a bar object.
        /// @param Parent_Object Parent object of the new bar.
        virtual void Create(Object_Class Parent_Object) override;

        // - - Setters.

        /// @brief Set the LVGL object pointer.
        /// @param LVGL_Object_Pointer Pointer to the LVGL object.
        /// @return True if the pointer is valid, false otherwise.
        virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

        /// @brief Set the value of the bar.
        /// @param Value Value to set.
        /// @param Enable_Animation Enable animation.
        void Set_Value(int32_t Value, bool Enable_Animation = true);

        /// @brief Set the start value of the bar.
        /// @param Value Value to set.
        /// @param Enable_Animation Enable animation.
        void Set_Start_Value(int32_t Value, bool Enable_Animation = true);

        /// @brief Set the range of the bar.
        /// @param Minimum_Value Minimum value.
        /// @param Maximum_Value Maximum value.
        void Set_Range(int32_t Minimum_Value, int32_t Maximum_Value);

        /// @brief Set the mode of the bar.
        /// @param Mode Mode to set.
        void Set_Mode(Mode::Type Mode);

        // - - Getters.

        /// @brief Get the value of the bar.
        /// @return Value of the bar.
        int32_t Get_Value();

        /// @brief Get the start value of the bar.
        /// @return Start value of the bar.
        int32_t Get_Start_Value();

        /// @brief Get the minimum value of the bar.
        /// @return Minimum value of the bar.
        int32_t Get_Minimum_Value();

        /// @brief Get the maximum value of the bar.
        /// @return Maximum value of the bar.
        int32_t Get_Maximum_Value();

        /// @brief Get the mode of the bar.
        /// @return Mode of the bar.
        Mode::Type Get_Mode();

        // - - Attributes

        /// @brief Bar class.
        static const Class_Type &Class;

    } Bar_Type;
    
        } // namespace Graphics_Types
}   // namespace Xila_Namespace

#endif
