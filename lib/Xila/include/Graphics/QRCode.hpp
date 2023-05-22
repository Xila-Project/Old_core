/// @file QRCode.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 23-03-2023
///
/// @copyright Copyright (c) 2023
///

#if LV_USE_QRCODE != 0
#ifndef QRCode_Hpp_Included
#define QRCode_Hpp_Included

#include "Object.hpp"

namespace Xila_Namespace
{
    namespace Graphics_Types
    {
        typedef class QRCode_Class : public Object_Class
        {
        public:
            // - Methods

            // - - Constructor / destructor
            QRCode_Class();
            QRCode_Class(const Object_Type &Object);
            ~QRCode_Class();

            // - - Manipulation
            virtual void Create(Object_Type Parent_Object) override;
            void Create(Object_Type Parent_Object, const void* Data, uint32_t Length, Coordinate_Type Size, Color_Type Dark_Color = Color_Type::Black, Color_Type Light_Color = Color_Type::White);

            void Update(const void* Data, uint32_t Length);

            // - Attributes

            /// @brief QRCode class type.
            static const Class_Type &Class;
        } QRCode_Type;
    } // namespace Graphics_Namespace

} // namespace Xila_Namespace

#endif  // QRCode_Hpp_Included
#endif  // LV_USE_QRCODE != 0