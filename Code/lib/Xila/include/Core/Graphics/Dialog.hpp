#ifndef Dialog_Hpp_Included
#define Dialog_Hpp_Included

#include "Window.hpp"

namespace Xila_Namespace {
    typedef class Dialog_Class : public Window_Class {
    public:

        void Create();
        void Create(Object_Class Parent_Object);


    } Dialog_Type;
}

#endif