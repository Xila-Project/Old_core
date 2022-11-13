///
/// @file Image.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 14-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Image_Hpp_Included
#define Image_Hpp_Included

#include "Arduino.h"
#include "Object.hpp"

/// @brief image class

namespace Xila_Namespace
{
    typedef class Image_Class : public Object_Class
    {
    public:
        /// @brief Image color format enumeration.
        enum Color_Format_Enumeration
        {
            Unknow = LV_IMG_CF_UNKNOWN,

            Raw = LV_IMG_CF_RAW,                           /**< Contains the file as it is. Needs custom decoder function*/
            Raw_Alpha = LV_IMG_CF_RAW_ALPHA,               /**< Contains the file as it is. The image has alpha. Needs custom decoder
                                                  function*/
            Raw_Chroma_Keyed = LV_IMG_CF_RAW_CHROMA_KEYED, /**< Contains the file as it is. The image is chroma keyed. Needs
                                           custom decoder function*/

            True_Color = LV_IMG_CF_TRUE_COLOR,                           /**< Color format and depth should match with LV_COLOR settings*/
            True_Color_Alpha = LV_IMG_CF_TRUE_COLOR_ALPHA,               /**< Same as `LV_IMG_CF_TRUE_COLOR` but every pixel has an alpha byte*/
            True_Color_Chroma_Keyed = LV_IMG_CF_TRUE_COLOR_CHROMA_KEYED, /**< Same as `LV_IMG_CF_TRUE_COLOR` but LV_COLOR_TRANSP pixels
                                                  will be transparent*/

            Indexed_1_Bit = LV_IMG_CF_INDEXED_1BIT,  /**< Can have 2 different colors in a palette (always chroma keyed)*/
            Indexed_2_Bits = LV_IMG_CF_INDEXED_2BIT, /**< Can have 4 different colors in a palette (always chroma keyed)*/
            Indexed_4_Bits = LV_IMG_CF_INDEXED_4BIT, /**< Can have 16 different colors in a palette (always chroma keyed)*/
            Indexed_8_Bits = LV_IMG_CF_INDEXED_8BIT, /**< Can have 256 different colors in a palette (always chroma keyed)*/

            Alpha_1_Bit = LV_IMG_CF_ALPHA_1BIT,  /**< Can have one color and it can be drawn or not*/
            Alpha_2_Bits = LV_IMG_CF_ALPHA_2BIT, /**< Can have one color but 4 different alpha value*/
            Alpha_4_Bits = LV_IMG_CF_ALPHA_4BIT, /**< Can have one color but 16 different alpha value*/
            Alpha_8_Bits = LV_IMG_CF_ALPHA_8BIT, /**< Can have one color but 256 different alpha value*/

            Reserved_15 = LV_IMG_CF_RESERVED_15, /**< Reserved for further use.*/
            Reserved_16 = LV_IMG_CF_RESERVED_16, /**< Reserved for further use.*/
            Reserved_17 = LV_IMG_CF_RESERVED_17, /**< Reserved for further use.*/
            Reserved_18 = LV_IMG_CF_RESERVED_18, /**< Reserved for further use.*/
            Reserved_19 = LV_IMG_CF_RESERVED_19, /**< Reserved for further use.*/
            Reserved_20 = LV_IMG_CF_RESERVED_20, /**< Reserved for further use.*/
            Reserved_21 = LV_IMG_CF_RESERVED_21, /**< Reserved for further use.*/
            Reserved_22 = LV_IMG_CF_RESERVED_22, /**< Reserved for further use.*/
            Reserved_23 = LV_IMG_CF_RESERVED_23, /**< Reserved for further use.*/

            User_Encoded_0 = LV_IMG_CF_USER_ENCODED_0, /**< User holder encoding format.*/
            User_Encoded_1 = LV_IMG_CF_USER_ENCODED_1, /**< User holder encoding format.*/
            User_Encoded_2 = LV_IMG_CF_USER_ENCODED_2, /**< User holder encoding format.*/
            User_Encoded_3 = LV_IMG_CF_USER_ENCODED_3, /**< User holder encoding format.*/
            User_Encoded_4 = LV_IMG_CF_USER_ENCODED_4, /**< User holder encoding format.*/
            User_Encoded_5 = LV_IMG_CF_USER_ENCODED_5, /**< User holder encoding format.*/
            User_Encoded_6 = LV_IMG_CF_USER_ENCODED_6, /**< User holder encoding format.*/
            User_Encoded_7 = LV_IMG_CF_USER_ENCODED_7, /**< User holder encoding format.*/
        };

        /// @brief Image color format type.
        typedef lv_img_cf_t Color_Format_Type;

        typedef lv_img_size_mode_t Size_Mode_Type;

        enum Size_Mode_Enumeration
        {
            Virtual = LV_IMG_SIZE_MODE_VIRTUAL,
            Real = LV_IMG_SIZE_MODE_REAL
        };

        // -- Methods
        void Create(Object_Class Parent_Object);

        // -- Setters
        bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer);

        void Set_Source(const void *Source);
        void Set_Offset_X(Coordinate_Type X_Offset);
        void Set_Offset_Y(Coordinate_Type Y_Offset);
        void Set_Angle(int16_t Angle);
        void Set_Pivot(Coordinate_Type X, Coordinate_Type Y);
        void Set_Zoom(uint16_t Zoom);
        void Set_Antialias(bool Enable);
        void Set_Size_Mode(Size_Mode_Type Size_Mode);

        // -- Getters
        Coordinate_Type Get_Offset_X();
        Coordinate_Type Get_Offset_Y();
        uint16_t Get_Angle();
        void Get_Pivot(Point_Type &Pivot);
        uint16_t Get_Zoom();
        const void *Get_Source();
        bool Get_Antialias();
        Size_Mode_Type Get_Size_Mode();
    } Image_Type;
}

#endif