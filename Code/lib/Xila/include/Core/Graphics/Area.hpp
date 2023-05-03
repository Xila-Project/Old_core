///
/// @file Area.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 09-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Area_Hpp_Included
#define Area_Hpp_Included

#include "lvgl.h"

#include "Types.hpp"

namespace Xila_Namespace
{
    namespace Graphics_Types
    {
        /// @brief Area class.
        typedef class Area_Class
        {
        public:
            // - Types
        

            /// @brief LVGL area type pointer.
            typedef lv_area_t LVGL_Area_Type;

            // - Methods

            // - - Management

            void Increase(Coordinate_Type Extra_Width, Coordinate_Type Extra_Height);
            void Move(Coordinate_Type X_Offset, Coordinate_Type Y_Offset);
            void Align(Area_Class To_Align_To, Alignment_Type Alignment, Coordinate_Type X_Offset, Coordinate_Type Y_Offset);

            // - - Setters

            void Set(LVGL_Area_Type Area);

            void Set(Coordinate_Type X_1, Coordinate_Type Y_1, Coordinate_Type X_2, Coordinate_Type Y_2);
            void Set_Width(Coordinate_Type Width);
            void Set_Height(Coordinate_Type Height);

            // - - Getters

            Coordinate_Type Get_Width();
            Coordinate_Type Get_Height();
            uint32_t Get_Size();

            const LVGL_Area_Type Get_LVGL_Area(); // For compatibility purpose.

            LVGL_Area_Type LVGL_Area;
        } Area_Type;

    } // namespace Graphics_Types
} // namespace Xila_Namespace

#endif