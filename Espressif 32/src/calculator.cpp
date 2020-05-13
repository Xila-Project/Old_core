#include "calculator.hpp"

Calculator_Class::Calculator_Class()
{
    if(Number_Instance > 0) {
        delete this;
    }

    ++Number_Instance;

    
}