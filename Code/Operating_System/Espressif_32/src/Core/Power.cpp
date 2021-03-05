#include "Core/Core.hpp"
#include "soc/rtc_wdt.h"

void Xila_Class::Hibernate()
{
    Create_Dump();
}

// Interrput function

void IRAM_ATTR Xila_Class::Power_Button_Handler()
{
    vTaskEnterCritical(&Xila.Power_Button_Mutex);
    Xila.Power_Button_Counter = 1;
    Verbose_Print_Line("Button triggered");
    vTaskExitCritical(&Xila.Power_Button_Mutex);
}

void Xila_Class::Check_Power_Button()
{
    if (Power_Button_Counter != 0)
    {
        Execute_Shell(Xila.Power);
        Maximize_Software(Shell_Handle);
        Power_Button_Counter = 0;
    }
}

void Xila_Class::First_Start_Routine()
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
    //attachInterrupt(digitalPinToInterrupt(POWER_BUTTON_PIN), Power_Button_Handler, FALLING);

    // -- Disable FreeRTOS watchdog and replace it with Xila watchdog

#if WATCHDOG == 0
    rtc_wdt_protect_off();
    rtc_wdt_disable();
#endif

    // -- Set serial

#if VERBOSE_MODE == 1
    Serial.begin(SERIAL_SPEED);
#endif

    //Print_Line("Flash : 1,310,720 Bytes - EEPROM : 512 Bytes - RAM : " + char(ESP.getFreeHeap()) + "/ 327680 Bytes");
    Print_Line(F("Xila Embedded Edition - Alix ANNERAUD - Alpha - 0.1.0"));
    Print_Line(F("Starting Xila ..."), 0);

    // -- Initialize display. -- //

    pinMode(DISPLAY_SWITCH_PIN, OUTPUT);
    digitalWrite(DISPLAY_SWITCH_PIN, HIGH);

    Display.Set_Callback_Function_Numeric_Data(&Incomming_Numeric_Data_From_Display);
    Display.Set_Callback_Function_String_Data(&Incomming_String_Data_From_Display);
    Display.Set_Callback_Function_Event(&Incomming_Event_From_Display);
    Display.Begin();

    Display.Wake_Up();
    Display.Set_Current_Page(F("Core_Load")); // Play animation
    Display.Set_Trigger(F("LOAD_TIM"), true);

    // -- Initialize drive. -- //

#if SD_MODE == 0
    pinMode(14, INPUT_PULLUP);
    //pinMode(15, INPUT_PULLUP);
    pinMode(2, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(12, INPUT_PULLUP);
    pinMode(13, INPUT_PULLUP);
    Drive = &SD_MMC;
#else
    Drive = &SD;
#endif

    if (!Drive->begin() || Drive->cardType() == CARD_NONE)
    {
        Display.Set_Text(F("EVENT_TXT"), F("Failed to initialize drive."));
    }
    while (!Drive->begin() || Drive->cardType() == CARD_NONE)
    {
        vTaskDelay(pdMS_TO_TICKS(50));
    }
    Display.Set_Text(F("EVENT_TXT"), F(""));

    System_State = Default;
    Xila_Event Returned_Data;

    // -- Load system registry -- //

    Returned_Data = Load_System_Registry();

    if (Returned_Data != Success)
    {

        if (Returned_Data == Error)
        {
            Panic_Handler(Damaged_System_Registry);
        }
        else if (Returned_Data == 2)
        {
            Panic_Handler(Installation_Conflict);
        }
        else if (Returned_Data == 3) // new installation
        {
            File Temporary_File = Drive->open(Display_Executable_Path);
            if (Display.Update(Temporary_File) != Display.Update_Succeed)
            {
                Verbose_Print("Display update failed");
                ESP.restart();
            }

            Display.Set_Callback_Function_Numeric_Data(&Incomming_Numeric_Data_From_Display);
            Display.Set_Callback_Function_String_Data(&Incomming_String_Data_From_Display);
            Display.Set_Callback_Function_Event(&Incomming_Event_From_Display);
            Display.Begin();
            Display.Wake_Up();
            Display.Set_Current_Page(F("Core_Load")); // Play animation
            Display.Set_Trigger(F("LOAD_TIM"), true);

            System_State = New_Installation;
        }
    }

    WiFi.setHostname(Device_Name); // Set hostname

    // -- Load sound registry --

    Returned_Data = Load_Sound_Registry();

    if (Returned_Data != Success)
    {
        Verbose_Print_Line("Failed to load sound registry");
    }

    // -- Play startup sound

    {
        File Temporary_File = Drive->open(Startup_Sound_Path);
        if (!Sound.Play(Temporary_File))
        {
            Verbose_Print_Line("Failed to play sound");
        }
        Temporary_File.close();
    }

    // -- Load display registry

    Returned_Data = Load_Display_Registry();

    if (Returned_Data != Success)
    {
        Verbose_Print_Line("Failed to load display registry");
    }

    // WiFi :

    Returned_Data = WiFi_Connect();

    if (Returned_Data != Success)
    {
        Verbose_Print_Line("Failed to connect to WiFi");
    }

    // -- Load Time Registry
    Returned_Data = Load_Time_Registry();

    if (Returned_Data != Success)
    {
        Verbose_Print_Line("Failed to load time registry");
    }

    // -- Load Keyboard Registry

    Returned_Data = Load_Keyboard_Registry();

    if (Returned_Data != Success)
    {
        Verbose_Print_Line("Failed to play keyboard registry");
    }
}

void Xila_Class::Second_Start_Routine()
{
    Load_Dump();

#if ANIMATION == 1
    vTaskDelay(pdMS_TO_TICKS(3000));
#endif
    Display.Set_Value(F("STATE_VAR"), 2);

#if ANNIMATION == 1
    vTaskDelay(pdMS_TO_TICKS(3000));
#endif

    Execute_Startup_Function();

    vTaskDelay(pdMS_TO_TICKS(500));

    if (System_State == New_Installation)
    {
        Open_Software_Pointer[1]->Send_Instruction(Install_Dialog);
    }

    Feed_Watchdog();
    xTaskCreatePinnedToCore(Xila_Class::Core_Task, "Core Task", Memory_Chunk(4), NULL, SYSTEM_TASK_PRIORITY, &Core_Task_Handle, tskNO_AFFINITY);
}

void Xila_Class::Start(Software_Handle_Class *Software_Package, uint8_t Size)
{
    First_Start_Routine();

    // Restore attribute

    for (uint8_t i = 0; i < Size; i++)
    {
        Add_Software_Handle(Software_Package[i]);
    }

    Second_Start_Routine();
}

void Xila_Class::Start()
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

    Add_Software_Handle(Calculator_Handle);
    Add_Software_Handle(Clock_Handle);
    Add_Software_Handle(Internet_Browser_Handle);
    Add_Software_Handle(Music_Player_Handle);
    Add_Software_Handle(Oscilloscope_Handle);
    Add_Software_Handle(Paint_Handle);
    Add_Software_Handle(Periodic_Handle);
    Add_Software_Handle(Piano_Handle);
    Add_Software_Handle(Picture_Viewer_Handle);
    Add_Software_Handle(Pong_Handle);
    Add_Software_Handle(Simon_Handle);
    Add_Software_Handle(Text_Editor_Handle);
    Add_Software_Handle(Tiny_Basic_Handle);

    Second_Start_Routine();
}

void Xila_Class::Shutdown()
{
    Execute_Shell(Shutting_down);
    Maximize_Shell();

    Xila_Task_Handle Temporary_Task_Handle;
    for (uint8_t i = 2; i < 8; i++)
    {
        if (Open_Software_Pointer[i] != NULL)
        {
            Temporary_Task_Handle = Open_Software_Pointer[i]->Task_Handle;
            Open_Software_Pointer[i]->Send_Instruction(Close);
            vTaskResume(Temporary_Task_Handle);
            // -- Waiting for the software to close
            for (uint8_t ii = 0; ii <= 200; ii++)
            {
                if (eTaskGetState(Temporary_Task_Handle) == eDeleted)
                {
                    break;
                }
                vTaskDelay(pdMS_TO_TICKS(20));
            }
            // -- Force closing the software, if not closed within 4000 ms
            if (eTaskGetState(Temporary_Task_Handle) != eDeleted)
            {
                delete Open_Software_Pointer[i];
                vTaskDelete(Temporary_Task_Handle);
            }
            Open_Software_Pointer[i] = NULL;
        }
    }

    // Shutdown screen
    Display.Sleep();

    // Disconnect wifi
    WiFi.disconnect(true);

    Set_Sound_Registry(Sound.Get_Volume());

    // 
    Drive->end();

    vTaskDelay(pdMS_TO_TICKS(4000));

    //Set deep sleep
    Deep_Sleep();
}

void Xila_Class::Deep_Sleep()
{
    esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
    esp_deep_sleep_start();
}

void Xila_Class::Restart()
{
    Execute_Shell(Close);
    Maximize_Shell();

    Xila_Task_Handle Temporary_Task_Handle;
    for (uint8_t i = 2; i < 8; i++)
    {
        if (Open_Software_Pointer[i] != NULL)
        {
            Temporary_Task_Handle = Open_Software_Pointer[i]->Task_Handle;
            Open_Software_Pointer[i]->Send_Instruction(Close);
            vTaskResume(Temporary_Task_Handle);
            // -- Waiting for the software to close
            for (uint8_t ii = 0; ii <= 200; ii++)
            {
                if (eTaskGetState(Temporary_Task_Handle) == eDeleted)
                {
                    break;
                }
                vTaskDelay(pdMS_TO_TICKS(20));
            }
            // -- Force closing the software, if not closed within 4000 ms
            if (eTaskGetState(Temporary_Task_Handle) != eDeleted)
            {
                delete Open_Software_Pointer[i];
                vTaskDelete(Temporary_Task_Handle);
            }
            Open_Software_Pointer[i] = NULL;
        }
    }

    Set_Sound_Registry(Sound.Get_Volume());

    Drive->end();

    vTaskDelay(pdMS_TO_TICKS(4000));

    esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
    esp_restart();
}

Xila_Event Xila_Class::Load_Dump()
{
    if (Drive->exists(Dump_Registry_Path))
    {
        File Dump_File = Drive->open(Dump_Registry_Path);
        char Temporary_Software_Name[24];
        for (uint8_t i = 0; i < 7; i++)
        {
            Dump_File.seek(i * 24);
            Dump_File.readBytes(Temporary_Software_Name, sizeof(Temporary_Software_Name));
            for (uint8_t ii = 0; ii < (sizeof(Software_Handle_Pointer) / sizeof(Software_Handle_Pointer[0])); ii++)
            {
                if (strcmp(Software_Handle_Pointer[ii]->Name, Temporary_Software_Name) == 0)
                {
                    Software_Open(*Software_Handle_Pointer[ii]);
                }
            }
        }

        Dump_File.seek(6 * 24);
        Dump_File.readBytes(Current_Username, sizeof(Current_Username));
        return Success;
    }
    else
    {
        return Error;
    }
}

Xila_Event Xila_Class::Create_Dump()
{
    Software_Minimize(*Open_Software_Pointer[0]->Handle_Pointer);

    File Dump_File = Drive->open(Dump_Registry_Path, FILE_WRITE);

    if (!Dump_File)
    {
        return Error;
    }

    Dump_File.seek(0 * 24);

    Dump_File.write((uint8_t *)Open_Software_Pointer[2]->Handle_Pointer->Name, sizeof(Open_Software_Pointer[2]->Handle_Pointer->Name));
    Dump_File.seek(1 * 24);
    Dump_File.write((uint8_t *)Open_Software_Pointer[3]->Handle_Pointer->Name, sizeof(Open_Software_Pointer[3]->Handle_Pointer->Name));
    Dump_File.seek(2 * 24);
    Dump_File.write((uint8_t *)Open_Software_Pointer[4]->Handle_Pointer->Name, sizeof(Open_Software_Pointer[4]->Handle_Pointer->Name));
    Dump_File.seek(3 * 24);
    Dump_File.write((uint8_t *)Open_Software_Pointer[5]->Handle_Pointer->Name, sizeof(Open_Software_Pointer[5]->Handle_Pointer->Name));
    Dump_File.seek(4 * 24);
    Dump_File.write((uint8_t *)Open_Software_Pointer[6]->Handle_Pointer->Name, sizeof(Open_Software_Pointer[6]->Handle_Pointer->Name));
    Dump_File.seek(5 * 24);
    Dump_File.write((uint8_t *)Open_Software_Pointer[7]->Handle_Pointer->Name, sizeof(Open_Software_Pointer[7]->Handle_Pointer->Name));
    Dump_File.seek(6 * 24);
    Dump_File.write((uint8_t *)Current_Username, sizeof(Current_Username));
    Dump_File.close();

    Xila_Task_Handle Temporary_Task_Handle;
    for (uint8_t i = 1; i < 8; i++)
    {
        if (Open_Software_Pointer[i] != NULL)
        {
            Temporary_Task_Handle = Open_Software_Pointer[i]->Task_Handle;
            Open_Software_Pointer[i]->Send_Instruction(Hibernating);
            Task_Resume(Temporary_Task_Handle);
            // -- Waiting for the software to close
            for (uint8_t ii = 0; ii <= 200; ii++)
            {
                if (eTaskGetState(Temporary_Task_Handle) == eDeleted)
                {
                    break;
                }
                vTaskDelay(pdMS_TO_TICKS(20));
            }
        }
    }

    return Success;
}