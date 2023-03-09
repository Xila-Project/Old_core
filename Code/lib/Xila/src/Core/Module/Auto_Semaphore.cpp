///
/// @file Auto_Semaphore.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 07-03-2023
///
/// @copyright Copyright (c) 2023
///

#include "Core/Module/Semaphore.hpp"

using namespace Xila_Namespace;

Auto_Semaphore_Class::Auto_Semaphore_Class(Semaphore_Type &Semaphore, uint32_t Timeout) : Semaphore(Semaphore)
{
    Semaphore.Take(Timeout);
}

Auto_Semaphore_Class::~Auto_Semaphore_Class()
{
    Semaphore.Give();
}