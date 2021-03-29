///
/// @file Power.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Core.hpp"
#include "soc/rtc_wdt.h"

Xila_Class::Power_Class::Power_Class()
{
    Button_Mutex = portMUX_INITIALIZER_UNLOCKED;
    Button_Counter = false;
}

void IRAM_ATTR Xila_Class::Power_Class::Button_Handler()
{
    vTaskEnterCritical(&Xila.Power.Button_Mutex);
    Xila.Power.Button_Counter = 1;
    Verbose_Print_Line("Button triggered");
    vTaskExitCritical(&Xila.Power.Button_Mutex);
}

void Xila_Class::Power_Class::Check_Button()
{
    if (Button_Counter != 0)
    {
        Xila.Software.Execute_Shell(Software_Class::Power_Dialog);
        Xila.Software.Maximize(Shell_Handle);
        Button_Counter = 0;
    }
}

///
/// @brief
///
inline void Xila_Class::Power_Class::First_Start_Routine()
{
    // -- Check if the power button was press or the power supply plugged.
    esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
    esp_sleep_wakeup_cause_t Wakeup_Cause = esp_sleep_get_wakeup_cause();
    if (Wakeup_Cause != ESP_SLEEP_WAKEUP_EXT0 && Wakeup_Cause != ESP_SLEEP_WAKEUP_UNDEFINED)
    {
        Deep_Sleep();
    }

    // -- Check if the battery level is enough to start.

#if BATTERY_CHECKING == 1
    if (Battery.Get_Charge_Level() <= 3)
    {
        Deep_Sleep();
    }
#endif

    pinMode(POWER_BUTTON_PIN, INPUT);
    // Temporary disable power button interrupt due to disturbance caused maybe by WiFi
    attachInterrupt(digitalPinToInterrupt(POWER_BUTTON_PIN), Xila.Power.Button_Handler, FALLING);

    // -- Disable FreeRTOS watchdog and replace it with Xila watchdog
#if WATCHDOG == 0
    rtc_wdt_protect_off();
    rtc_wdt_disable();
#endif

#if USB_SERIAL == 1
    Serial.begin(USB_SERIAL_SPEED);
#endif

    // -- Initialize display. -- //

    pinMode(DISPLAY_SWITCH_PIN, OUTPUT);
    digitalWrite(DISPLAY_SWITCH_PIN, HIGH);

    Xila.Display.Set_Callback_Function_Numeric_Data(Xila.Display.Incomming_Numeric_Data_From_Display);
    Xila.Display.Set_Callback_Function_String_Data(Xila.Display.Incomming_String_Data_From_Display);
    Xila.Display.Set_Callback_Function_Event(Xila.Display.Incomming_Event_From_Display);
    Xila.Display.Begin();

    Xila.Display.Wake_Up();
    Xila.Display.Set_Current_Page(F("Core_Load")); // Play animation
    Xila.Display.Set_Trigger(F("LOAD_TIM"), true);

    // -- Initialize drive. -- //

#if SD_MODE == 0
    pinMode(14, INPUT_PULLUP);
    pinMode(2, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(12, INPUT_PULLUP);
    pinMode(13, INPUT_PULLUP);
#endif

    if (!Xila.Drive.begin() || Xila.Drive.cardType() == CARD_NONE)
    {
        Xila.Display.Set_Text(F("EVENT_TXT"), F("Failed to initialize drive."));
    }
    while (!Xila.Drive.begin() || Xila.Drive.cardType() == CARD_NONE)
    {
        Xila.Task.Delay(50);
    }
    Xila.Display.Set_Text(F("EVENT_TXT"), F(""));

    Xila_Event Returned_Data;

    // -- Check system integrity -- //

    if (!Xila.Drive.exists(Xila_Directory_Path) || !Xila.Drive.exists(Software_Directory_Path))
    {
        Xila.System.Panic_Handler(Xila.System.Missing_System_Files);
    }

    // -- Load system registry -- //

    Returned_Data = Xila.System.Load_Registry();

    if (Returned_Data != Success)
    {

        if (Returned_Data == Error)
        {
            Xila.System.Panic_Handler(Xila.System.Damaged_System_Registry);
        }
        else if (Returned_Data == 2)
        {
            Xila.System.Panic_Handler(Xila.System.Installation_Conflict);
        }
        else if (Returned_Data == 3) // new installation
        {
            File Temporary_File = Xila.Drive.open(Display_Executable_Path);
            if (Xila.Display.Update(Temporary_File) != Xila.Display.Update_Succeed)
            {
                Verbose_Print("Display update failed");
                ESP.restart();
            }

            Xila.Display.Set_Callback_Function_Numeric_Data(&Xila.Display.Incomming_Numeric_Data_From_Display);
            Xila.Display.Set_Callback_Function_String_Data(&Xila.Display.Incomming_String_Data_From_Display);
            Xila.Display.Set_Callback_Function_Event(&Xila.Display.Incomming_Event_From_Display);
            Xila.Display.Begin();
            Xila.Display.Wake_Up();
            Xila.Display.Set_Current_Page(F("Core_Load")); // Play animation
            Xila.Display.Set_Trigger(F("LOAD_TIM"), true);
        }
    }

    Xila.WiFi.setHostname(Xila.System.Device_Name); // Set hostname

    // -- Load sound registry --

    Returned_Data = Xila.Sound.Load_Registry();

    if (Returned_Data != Success)
    {
        Verbose_Print_Line("Failed to load sound registry");
    }

    Xila.Task.Create(Xila.Sound.Task, "Sound task", Memory_Chunk(3), NULL, Xila.Task.Driver_Task, &Xila.Sound.Task_Handle);

    // -- Play startup sound
    Xila.Sound.Play((Startup_Sound_Path));
    // -- Load display registry

    Returned_Data = Xila.Display.Load_Registry();

    if (Returned_Data != Success)
    {
        Verbose_Print_Line("Failed to load display registry");
    }

    // WiFi :

    Returned_Data = Xila.WiFi.Load_Registry();

    if (Returned_Data != Success)
    {
        Verbose_Print_Line("Failed to connect to WiFi");
    }

    // -- Load Time Registry
    Returned_Data = Xila.Time.Load_Registry();

    if (Returned_Data != Success)
    {
        Verbose_Print_Line("Failed to load time registry");
    }

    // -- Load Keyboard Registry

    Returned_Data = Xila.Keyboard.Load_Registry();

    if (Returned_Data != Success)
    {
        Verbose_Print_Line("Failed to play keyboard registry");
    }

    Xila.Task.Create(Xila.System.Task, "Core Task", Memory_Chunk(3), NULL, Xila.Task.System_Task, &Xila.System.Task_Handle);
}

///
/// @brief
///
inline void Xila_Class::Power_Class::Second_Start_Routine()
{
    Xila.System.Load_Dump();

#if ANIMATION == 1
    Xila.Task.Delay(3000);
#endif
    Xila.Display.Set_Value(F("STATE_VAR"), 2);

#if ANIMATION == 1
    Xila.Task.Delay(3000);
#endif

    Execute_Startup_Function();

    Xila.Task.Delay(500);

    if (!Xila.Drive.exists(Users_Directory_Path))
    {
        Xila.Software.Openned_Software[1]->Send_Instruction(Software_Class::Install_Dialog);
    }
}

/**
    * @brief Function handle deep-sleep wakeup, initialize the core, start software etc.
    * @param Software_Package Software that Xila need to load. 
    * @details Function steps :
    * 1) Check if the wakeup reasing is linked to a power button press, or undefined (power reset) and if not, go to sleep.
    * 2) Create an interrupt for the power button.
    * 3) Initalize display.
    * 4) Initalize system drive.
    * 5) Load registries (display, sound, keyboard, network, time).
    * 6) Play sound and animation.
    * 7) Load software handles.
    * 8) Execute software startup function (Shell and other software).
    */
void Xila_Class::Power_Class::Start(Software_Handle_Class *Software_Package, uint8_t Size)
{
    First_Start_Routine();

    // Restore attribute

    for (uint8_t i = 0; i < Size; i++)
    {
        Xila.Software.Add_Handle(Software_Package[i]);
    }

    Second_Start_Routine();
}

/**
     * @brief Function that handle deep-sleep wakeup, initialize the, start software etc.
     * @details Function steps :
     * 1) Cheeck if the wa
     */
void Xila_Class::Power_Class::Start()
{
    First_Start_Routine();

    // -- Load softwares -- //

    Verbose_Print_Line("> Load software ...");

    extern Software_Handle_Class Calculator_Handle;
    extern Software_Handle_Class Clock_Handle;
    extern Software_Handle_Class Internet_Browser_Handle;
    extern Software_Handle_Class Music_Player_Handle;
    extern Software_Handle_Class Oscilloscope_Handle;
    extern Software_Handle_Class Paint_Handle;
    extern Software_Handle_Class Periodic_Handle;
    extern Software_Handle_Class Piano_Handle;
    extern Software_Handle_Class Picture_Viewer_Handle;
    extern Software_Handle_Class Pong_Handle;
    extern Software_Handle_Class Simon_Handle;
    extern Software_Handle_Class Text_Editor_Handle;
    extern Software_Handle_Class Tiny_Basic_Handle;

    Xila.Software.Add_Handle(Calculator_Handle);
    Xila.Software.Add_Handle(Clock_Handle);
    Xila.Software.Add_Handle(Internet_Browser_Handle);
    Xila.Software.Add_Handle(Music_Player_Handle);
    Xila.Software.Add_Handle(Oscilloscope_Handle);
    Xila.Software.Add_Handle(Paint_Handle);
    Xila.Software.Add_Handle(Periodic_Handle);
    Xila.Software.Add_Handle(Piano_Handle);
    Xila.Software.Add_Handle(Picture_Viewer_Handle);
    Xila.Software.Add_Handle(Pong_Handle);
    Xila.Software.Add_Handle(Simon_Handle);
    Xila.Software.Add_Handle(Text_Editor_Handle);
    Xila.Software.Add_Handle(Tiny_Basic_Handle);

    Second_Start_Routine();
}

///
/// @brief
///
inline void Xila_Class::Power_Class::Execute_Startup_Function()
{
    (*Shell_Handle.Startup_Function_Pointer)();

    for (uint8_t i = 0; i < MAXIMUM_SOFTWARE; i++)
    {
        if (Xila.Software.Software_Handle_Pointer[i] != NULL)
        {
            if (Xila.Software.Software_Handle_Pointer[i]->Startup_Function_Pointer != NULL)
            {
                (*Xila.Software.Software_Handle_Pointer[i]->Startup_Function_Pointer)();
            }
        }
    }
}

/**
     * @brief Function shutdown the system.
     * @details Function that execute, before making 
     * 
     */
void Xila_Class::Power_Class::Shutdown()
{
    Verbose_Print_Line("Shutdown");
    Xila.Software.Execute_Shell(Software_Class::Shutdown);
    Xila.Software.Maximize_Shell();

    Xila_Task_Handle Temporary_Task_Handle;
    for (uint8_t i = 2; i < 8; i++)
    {
        if (Xila.Software.Openned_Software[i] != NULL)
        {
            Temporary_Task_Handle = Xila.Software.Openned_Software[i]->Task_Handle;
            Xila.Software.Openned_Software[i]->Send_Instruction(Software_Class::Shutdown);
            vTaskResume(Temporary_Task_Handle);
            // -- Waiting for the software to close
            for (uint8_t ii = 0; ii <= 200; ii++)
            {
                if (eTaskGetState(Temporary_Task_Handle) == eDeleted)
                {
                    break;
                }
                Xila.Task.Delay(20);
            }
            // -- Force closing the software, if not closed within 4000 ms
            if (eTaskGetState(Temporary_Task_Handle) != eDeleted)
            {
                delete Xila.Software.Openned_Software[i];
                vTaskDelete(Temporary_Task_Handle);
            }
            Xila.Software.Openned_Software[i] = NULL;
        }
    }

    // Shutdown screen
    Xila.Display.Sleep();

    // Disconnect wifi
    Xila.WiFi.disconnect(true);

    Xila.Sound.Save_Registry();

    //
    Xila.Drive.end();

    Xila.Task.Delay(4000);

    //Set deep sleep
    Deep_Sleep();
}

void Xila_Class::Power_Class::Hibernate()
{
    Xila.System.Create_Dump();
}

void Xila_Class::Power_Class::Deep_Sleep()
{
    esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
    esp_deep_sleep_start();
}

void Xila_Class::Power_Class::Restart()
{
    Xila.Software.Execute_Shell(Software_Class::Close);
    Xila.Software.Maximize_Shell();

    Xila_Task_Handle Temporary_Task_Handle;
    for (uint8_t i = 2; i < 8; i++)
    {
        if (Xila.Software.Openned_Software[i] != NULL)
        {
            Temporary_Task_Handle = Xila.Software.Openned_Software[i]->Task_Handle;
            Xila.Software.Openned_Software[i]->Send_Instruction(Software_Class::Close);
            vTaskResume(Temporary_Task_Handle);
            // -- Waiting for the software to close
            for (uint8_t ii = 0; ii <= 200; ii++)
            {
                if (eTaskGetState(Temporary_Task_Handle) == eDeleted)
                {
                    break;
                }
                Xila.Task.Delay(20);
            }
            // -- Force closing the software, if not closed within 4000 ms
            if (eTaskGetState(Temporary_Task_Handle) != eDeleted)
            {
                delete Xila.Software.Openned_Software[i];
                vTaskDelete(Temporary_Task_Handle);
            }
            Xila.Software.Openned_Software[i] = NULL;
        }
    }

    Xila.Sound.Save_Registry();

    Xila.Drive.end();

    Xila.Task.Delay(4000);

    esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
    esp_restart();
}
