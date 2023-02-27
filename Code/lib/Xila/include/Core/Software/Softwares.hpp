///
 /// @file Software_Managment.hpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 25-02-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

#ifndef Software_Managment_Hpp_Included
#define Software_Managment_Hpp_Included

#include "../Module/Module.hpp"

#include "Software.hpp"
#include <vector>

namespace Xila_Namespace
{

    namespace Softwares_Types
    {
        enum class Event_Code_Type : uint8_t
        {
            Open,
            Close
        };

    };

    typedef class Softwares_Class : public Module_Class
    {
    public:
        // - Methods

        Result_Type Start();
        Result_Type Stop();

        Result_Type Open(const Software_Handle_Type* Handle);
        Result_Type Open(const String_Type& Name);

        Result_Type Close(Software_Type* Software);
        Result_Type Kill(Software_Type* Software);

        const std::vector<Software_Handle_Type*> Get_Handle_List();
        const std::vector<Software_Type*> Get_List();

        const Software_Handle_Type* Find_Handle(const String_Type& Name);

    } Softwares_Type;

    extern Softwares_Type Softwares;

}

#endif