/// @file Point.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 07-05-2023
///
/// @copyright Copyright (c) 2023

#ifndef Point_Hpp_Included
#define Point_Hpp_Included

#include "Types.hpp"
#include "lvgl.h"

namespace Xila_Namespace
{
    namespace Graphics_Types
    {
        typedef class Point_Class
        {
        public:
            Point_Class()
            {
                Point.x = 0;
                Point.y = 0;
            }
            Point_Class(Coordinate_Type X, Coordinate_Type Y)
            {
                Point.x = X;
                Point.y = Y;
            }

            void Set(Coordinate_Type X, Coordinate_Type Y)
            {
                this->Point.x = X;
                this->Point.y = Y;
            }

            void Set_X(Coordinate_Type X)
            {
                this->Point.x = X;
            }

            void Set_Y(Coordinate_Type Y)
            {
                this->Point.y = Y;
            }

            Coordinate_Type Get_X() const
            {
                return Point.x;
            }

            Coordinate_Type Get_Y() const
            {
                return Point.y;
            }

            operator lv_point_t() const
            {
                return Point;
            }

            operator lv_point_t *()
            {
                return &Point;
            }

        private:
            lv_point_t Point;
        } Point_Type;

    }
}

#endif // Point_Hpp_Included