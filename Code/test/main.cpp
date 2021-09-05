#include "Unit_Test.hpp"
#include "Xila.hpp"

void setup()
{
  Xila.System.Start();

  Unit_Test.Run();
}

void loop()
{
    Xila.Task.Delete();
}
