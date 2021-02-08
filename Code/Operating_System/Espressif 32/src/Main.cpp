#include "Xila.hpp"



//#include "unity.h" testing pup

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
    Xila.Start();

    // External :
    // Xila.Start_External();
}

void loop()
{
    vTaskDelete(NULL);
}
