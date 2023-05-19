/// @file File_Explorer.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 18-05-2023
///
/// @copyright Copyright (c) 2023

#ifndef Xila_Graphics_File_Explorer_Hpp_Included
#define Xila_Graphics_File_Explorer_Hpp_Included

#include "Object.hpp"

namespace Xila_Namespace
{
    namespace Graphics_Types
    {
        typedef class File_Explorer_Class : public Object_Type
        {
        public:
            // - Methods

            // - - Constructors / destructors
            
            File_Explorer_Class();
            File_Explorer_Class(const Object_Class &Object_To_Copy);

            // - - Manipulation

            virtual void Create(Object_Class Parent_Object) override;
            virtual void Delete() override;

            void Refresh();
            void Go_Parent_Folder();
            void Clear_Selection();

            // - - Getters

            const char* Get_Path();
            const char* Get_Selected_Name(Size_Type Index);
            Size_Type Get_Selected_Count();
            const char* Get_Focused_Name();
            bool Get_Selection_State();

            // - - Setters

            void Set_Selection_State(bool Enabled);
            virtual void Set_Path(const char *Path);
            static void Event_Callback(lv_event_t* Event);

            // - - Attributes

            static const Class_Type Class;
        private:
            typedef struct Data_Structure
            {
                Static_String_Type<256> Path;
                bool Selection_State;
                Static_String_Type<32> Focused_Name;
            } Data_Type;

            Data_Type *Data;

        } File_Explorer_Type;
    }
}

#endif