#include "SD.h"
#include "Xila.hpp"

//#include "unity.h"

void setup()
{

    // create custom software package
    /*
    Software_Handle_Class* Custom_Software_Package[12] =
    {
        
    };
    Xila.Start(Custom_Software_Package, 12);
    */

    // start with default software package
    Xila.System.Start();

    // External :
    // Xila.Start_External();
}

void loop()
{
    Xila.Task.Delete();
}
