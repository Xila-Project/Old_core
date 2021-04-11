#include "Xila.hpp"

void setup()
{
  extern Software_Handle_Class Calculator_Handle;
  extern Software_Handle_Class Clock_Handle;
  extern Software_Handle_Class Internet_Browser_Handle;
  extern Software_Handle_Class Music_Player_Handle;
  extern Software_Handle_Class Oscilloscope_Handle;
  extern Software_Handle_Class Paint_Handle;
  extern Software_Handle_Class Periodic_Handle;
  extern Software_Handle_Class Piano_Handle;
  extern Software_Handle_Class Pong_Handle;
  extern Software_Handle_Class Simon_Handle;
  extern Software_Handle_Class Text_Editor_Handle;
  extern Software_Handle_Class Tiny_Basic_Handle;

  Software_Handle_Class* Custom_Software_Package[12] =
  {
    Calculator_Handle,
    Clock_Handle,
    Internet_Browser_Handle,
    Music_Player_Handle,
    Oscilloscope_Handle,
    Paint_Handle,
    Periodic_Handle,
    Piano_Handle,
    Pong_Handle,
    Simon_Handle,
    Text_Editor_Handle,
    Tiny_Basic_Handle
  };

  Xila.Start(Custom_Software_Package, 12);

  Xila.System.Start();
}

void loop()
{
  Xila.Task.Delete();
}
