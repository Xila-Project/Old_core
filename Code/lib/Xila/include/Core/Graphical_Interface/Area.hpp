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

class Area_Class
{
public:
    // - Types

    /// @brief Coordinate type.
    typedef lv_coord_t Coordinate_Type;

    /// @brief Alignment type.
    typedef lv_align_t Alignment_Type;

    /// @brief Alignment enumeration.
    enum Alignment_Enumeration
    {
        Default = LV_ALIGN_DEFAULT,
        Top_Left = LV_ALIGN_TOP_LEFT,
        Top_Middle = LV_ALIGN_TOP_MID,
        Top_Right = LV_ALIGN_TOP_RIGHT,
        Middle_Left = LV_ALIGN_LEFT_MID,
        Center = LV_ALIGN_CENTER,
        Middle_Right = LV_ALIGN_RIGHT_MID,
        Bottom_Left = LV_ALIGN_BOTTOM_LEFT,
        Bottom_Middle = LV_ALIGN_BOTTOM_MID,
        Bottom_Right = LV_ALIGN_BOTTOM_RIGHT,

        Out_Top_Left = LV_ALIGN_OUT_TOP_LEFT,
        Out_Top_Middle = LV_ALIGN_OUT_TOP_MID,
        Out_Top_Right = LV_ALIGN_OUT_TOP_RIGHT,
        Out_Bottom_Left = LV_ALIGN_OUT_BOTTOM_LEFT,
        Out_Bottom_Middle = LV_ALIGN_OUT_BOTTOM_MID,
        Out_Bottom_Right = LV_ALIGN_OUT_BOTTOM_RIGHT,
        Out_Left_Top = LV_ALIGN_OUT_LEFT_TOP,
        Out_Left_Middle = LV_ALIGN_OUT_LEFT_MID,
        Out_Left_Bottom = LV_ALIGN_OUT_LEFT_BOTTOM,
        Out_Right_Top = LV_ALIGN_OUT_RIGHT_TOP,
        Out_Right_Middle = LV_ALIGN_OUT_RIGHT_MID,
        Out_Right_Bottom = LV_ALIGN_OUT_RIGHT_BOTTOM,
    };

    /// @brief Direction enumeration.
    enum Direction_Enumeration
    {
        None = LV_DIR_NONE,
        Left = LV_DIR_LEFT,
        Right = LV_DIR_RIGHT,
        Top = LV_DIR_TOP,
        Bottom = LV_DIR_BOTTOM,
        Horizontal = LV_DIR_HOR,
        Vertical = LV_DIR_VER,
        All = LV_DIR_ALL
    };

    /// @brief Direction type.
    typedef uint8_t lv_dir_t;

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

    const LVGL_Area_Type Get_LVGL_Area();   // For compatibility purpose.

    LVGL_Area_Type LVGL_Area;
};

#endif