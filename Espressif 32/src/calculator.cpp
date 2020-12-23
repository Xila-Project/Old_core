#include "Calculator.hpp"

Calculator_Class *Calculator_Class::Instance_Pointer = NULL;

Calculator_Class::Calculator_Class() : Software_Class(8),
                                       State(0xFF)
{
    xTaskCreatePinnedToCore(Main_Task, "Calculator", 4 * 1024, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
    Execute(Software_Code::Maximize);
}

Calculator_Class::~Calculator_Class()
{
    Instance_Pointer = NULL;
}

Software_Class *Calculator_Class::Load()
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Calculator_Class();
    }
    return Instance_Pointer;
}

void Calculator_Class::Memory_Operation(uint8_t Operation)
{
    switch (Operation)
    {
    case Memory_Add:
        if (State >= 2)
        {
            Memory += Result;
        }
        else
        {
            Memory += Number[State];
        }
        break;
    case Memory_Substract:
        if (State >= 2)
        {
            Memory -= Result;
        }
        else
        {
            Memory -= Number[State];
        }
        break;
    case Memory_Read:
        State = 0;
        Number[State] = Memory_Read;
        Display();
        break;
    case Memory_Clear:
        Memory = 0;
        break;
    }
}

void Calculator_Class::Switch_Angle_Unity()
{
    if (bitRead(Keys_Mode, 3) == 1)
    {
        bitWrite(Keys_Mode, 3, 0);
        Xila.Display.Set_Text(F("ANGLE_BUT"), F("Rad"));
    }
    else
    {
        bitWrite(Keys_Mode, 3, 1);
        Xila.Display.Set_Text(F("ANGLE_BUT"), F("Deg"));
    }
}

void Calculator_Class::Switch_Keys()
{
    if (bitRead(Keys_Mode, 1) == 1) // Second enabled
    {

        if (bitRead(Keys_Mode, 2) == 1) // all enabled
        {
            Xila.Display.Click(F("SS_HOT"), 1);
        }
        else // hyperbolic disabled
        {
            Xila.Display.Click(F("SH_HOT"), 0);
        }
    }
    else // second disabled
    {
        if (bitRead(Keys_Mode, 2) == 1) // hyperbolic enabled
        {
            Xila.Display.Click(F("SH_HOT"), 1);
        }
        else // all disabled
        {
            Xila.Display.Click(F("SS_HOT"), 0);
        }
    }
}

void Calculator_Class::Main_Task(void *pvParameters)
{
    while (1)
    {
        switch (Instance_Pointer->Get_Command())
        {
        case 0: //idle
            break;
        case Software_Code::Close:
            delete Instance_Pointer;
            vTaskDelete(NULL);
            break;
        case Software_Code::Maximize:
            Xila.Display.Set_Current_Page(F("Calculator"));
            break;
        case Software_Code::Minimize:
            vTaskSuspend(NULL);
            break;
        case 0x4230: //B0
            Instance_Pointer->Add_Number(0);
            break;

        case 0x4231: //B1
            Instance_Pointer->Add_Number(1);
            break;

        case 0x4232: //B2
            Instance_Pointer->Add_Number(2);
            break;

        case 0x4233: //B3
            Instance_Pointer->Add_Number(3);
            break;

        case 0x4234: //B4
            Instance_Pointer->Add_Number(4);
            break;

        case 0x4235: //B5
            Instance_Pointer->Add_Number(5);
            break;

        case 0x4236: //B6
            Instance_Pointer->Add_Number(6);
            break;

        case 0x4237: //B7
            Instance_Pointer->Add_Number(7);
            break;
        case 0x4238: //B8
            Instance_Pointer->Add_Number(8);
            break;

        case 0x4239: //B9
            Instance_Pointer->Add_Number(9);
            break;

        case 0x423D: //B=
            Instance_Pointer->Compute();

        case 0x4243: //BC
            Instance_Pointer->Clear();
            break;

        case 0x4D43: // MC
            Instance_Pointer->Memory_Operation(Memory_Clear);
            break;
        case 0x4D52: // MR
            Instance_Pointer->Memory_Operation(Memory_Read);
            break;
        case 0x4D2B: // M+
            Instance_Pointer->Memory_Operation(Memory_Add);
            break;
        case 0x4D2D: // M-
            Instance_Pointer->Memory_Operation(Memory_Substract);
            break;

        case 0x5332: //S2
            if (bitRead(Instance_Pointer->Keys_Mode, 1) == 1)
            {
                bitWrite(Instance_Pointer->Keys_Mode, 1, 0);
            }
            else
            {
                bitWrite(Instance_Pointer->Keys_Mode, 1, 1);
            }
            Instance_Pointer->Switch_Keys();
            break;

        case 0x5348: //SH
            if (bitRead(Instance_Pointer->Keys_Mode, 1) == 1)
            {
                bitWrite(Instance_Pointer->Keys_Mode, 1, 0);
            }
            else
            {
                bitWrite(Instance_Pointer->Keys_Mode, 1, 1);
            }
            Instance_Pointer->Switch_Keys();
            break;
        case 0x5341: // SA : switch Angle unity to Radian
            if (bitRead(Instance_Pointer->Keys_Mode, 3) == 1)
            {
                bitWrite(Instance_Pointer->Keys_Mode, 3, 0);
                Xila.Display.Set_Text(F("ANGLE_BUT"), F("Rad"));
            }
            else
            {
                bitWrite(Instance_Pointer->Keys_Mode, 3, 1);
                Xila.Display.Set_Text(F("AGNLE_BUT"), F("Deg"));
            }
            break;
        case 0x4661: // FA
            Instance_Pointer->Set_Operator(Factorial);
            break;

        case 0x5069: // Pi
            if (Instance_Pointer->State >= 2)
            {
                Instance_Pointer->Clear_All();
            }
            Instance_Pointer->Number[Instance_Pointer->State] = Pi;
            Instance_Pointer->Display();
            break;

        case 0x4661: // Ne : exponential number
            if (Instance_Pointer->State >= 2)
            {
                Clear_All();
            }

            Instance_Pointer->Number[State] = Exponential;

            Instance_Pointer->Display();
            break;

        case 0x4661: // Fe : exponential function
            Instance_Pointer->Set_Operator(Exponential);
            break;

        case 0x422B: //B+
            Instance_Pointer->Set_Operator(Addition);
            break;

        case 0x422D: //B-
            Instance_Pointer->Set_Operator(Substraction);
            break;

        case 0x422A: //B*
            Instance_Pointer->Set_Operator(Multiplication);
            break;

        case 0x422F: //B/
            Instance_Pointer->Set_Operator(Division);
            break;

        case 0x4225: //B
            Instance_Pointer->Set_Operator(Modulo);
            break;

        case:
            if (Keys_Mode = 1)
            {
                Instance_Pointer->Set_Operator(Sine);
            }
            else
            {
                Instance_Pointer->Set_Operator(Arc_Sine)
            }
            break;

        case 0x42B2: //B²
            pow(Instance_Pointer->Number[Instance_Pointer->State], 2);
            break;

        default:
            break;
        }
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}

void Calculator_Class::Add_Number(uint8_t const &Number_To_Add)
{
    switch (Number_To_Add)
    {
    case Pi:
        Clear();
        Numbers[State][0] = 'P';
        break;
    case Exponential:
        Clear();
        Numbers[State][0] = 'N';
        break;
    case Random:
        Clear();
        dtostrf(esp_random(), sizeof(Numbers[State]), 0, Numbers[State]);
        Decimal_Point[State] = false;
        break;
    case Point:
        if (Decimal_Point[State] != true)
        {
            Numbers[State][Current_Position[State]++] = '.';
            Decimal_Point[State] = true;
        }
        break;
    default:
        if (!isAlpha(Numbers[State][0]))
        {
            if (Current_Position[State] == 0)
            {
            }
            Numbers[State][Current_Position[State]++] = Number_To_Add + 48;
        }
        break;
    }

    Display();
}

void Calculator_Class::Delete_Number()
{
    if (Current_Position[State] > 0)
    {
        switch (Numbers[State][--Current_Position[State]])
        {
        case 'P':
            Clear();
            break;
        case 'N':
            Clear();
            break;
        case '.':
            Decimal_Point[State] = false;
            break;
        }
    }
    Display();
}

void Calculator_Class::Set_Operator(char const &Opertor_To_Set)
{
    Main_Operator = Opertor_To_Set;
    if (State > 1)
    {
        Number[0] = Result;
        Number[1] = 0;
        Result = 0;
        State = 0;
    }
    else
    {
        State = 1;
    }

    Display();
}

void Calculator_Class::Switch_Symbol()
{
    if (Numbers[State][0] == '0')
    {
        Numbers[State][0] = '-';
    }
    else
    {
        Numbers[State][0] == '0';;
    }
    Display();
}

void Calculator_Class::Compute()
{
    uint32_t Temporary_Number[2];

    //1st secondary operator :

    // 2nd secondary operator :

    switch (Operator)
    {
    case Addition:
        Result = Number[0] + Number[1];
        break;
    case Substraction:
        Result = Number[0] - Number[1];
        break;
    case Multiplication:
        Result = Number[0] * Number[1];
        break;
    case Division:
        Result = Number[0] / Number[1];
        break;
    case Modulo:
        Temporary_Number[0] = (long)Number[0];
        Temporary_Number[1] = (long)Number[1];
        Result = Temporary_Number[0] % Temporary_Number[1];
        break;
    case Factorial:
        Result = 1;
        for (uint8_t i = 1; i <= Number; i++)
        {
            Result *= Number;
        }
        break;
    case Sine:
        if (bitRead(Keys_Mode, Angle) == Degree)
        {
            Result = sinf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = sinf(Number[0]);
        }
        break;
    case Cosine:
        if (bitRead(Keys_Mode, Angle) == Degree)
        {
            Result = cosf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = cosf(Number[0]);
        }
        break;
    case Tangent:
        if (bitRead(Keys_Mode, Angle) == Degree)
        {
            Result = tanf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = tanf(Number[0]);
        }
        break;
    case Arc_Sine:
        if (bitRead(Keys_Mode, Angle) == Degree)
        {
            Result = asinf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = asinf(Number[0]);
        }
        break;
    case Arc_Cosine:
        if (bitRead(Keys_Mode, Angle) == Degree)
        {
            Result = acosf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = acosf(Number[0]);
        }
        break;
    case Arc_Tangent:
        if (bitRead(Keys_Mode, Angle) == Degree)
        {
            Result = atanf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = atanf(Number[0]);
        }
        break;
    case Hyperbolic_Sine:
        if (bitRead(Keys_Mode, Angle) == Degree)
        {
            Result = sinhf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = sinhf(Number[0]);
        }
        break;
    case Hyperbolic_Cosine:
        if (bitRead(Keys_Mode, Angle) == Degree)
        {
            Result = coshf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = coshf(Number[0]);
        }
        break;
    case Hyperbolic_Tangent:
        if (bitRead(Keys_Mode, Angle) == Degree)
        {
            Result = tanhf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = tanhf(Number[0]);
        }
        break;
    case Arc_Hyperbolic_Sine:
        if (bitRead(Keys_Mode, Angle) == Degree)
        {
            Result = asinhf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = asinhf(Number[0]);
        }
        break;
    case Arc_Hyperbolic_Cosine:
        if (bitRead(Keys_Mode, Angle) == Degree)
        {
            Result = acoshf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = acoshf(Number[0]);
        }
        break;
    case Arc_Hyperbolic_Tangent:
        if (bitRead(Keys_Mode, Angle) == Degree)
        {
            Result = atanhf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = atanhf(Number[0]);
        }
        break;
    }
    State = 2;
    Display();
}

float Calculator_Class::Degree_To_Radian(float Angle)
{
    Angle *= PI;
    Angle /= 180;
    return Angle;
}

void Calculator_Class::Clear()
{
    memset(Numbers[State], 0, sizeof(Numbers[State]));
    Current_Position[State] = 0;
}

void Calculator_Class::Clear_All()
{
    State = 0;

    memset(Numbers[0], 0, sizeof(Numbers[0]));
    memset(Numbers[1], 0, sizeof(Numbers[1]));
    memset(Numbers[2], 0, sizeof(Numbers[2]));

    Secondary_Operator[0] = 0xFF;
    Secondary_Operator[1] = 0xFF;
    Main_Operator = 0xFF;
}

void Calculator_Class::Display()
{
    switch (State)
    {
    case 0:

        Xila.Display.Set_Text(F("CALCULATIO_TXT"), F(""));
        Temporary_String = String(Number[State]);
        Xila.Display.Set_Text("NUMBER_TXT", Temporary_String);
        break;
    case 1:
        Temporary_String = String(Number[0]);
        Temporary_String += " ";
        Temporary_String += String(Operator);
        Xila.Display.Set_Text(F("CALCULATIO_TXT"), Temporary_String);
        Temporary_String = String(Number[1]);
        Xila.Display.Set_Text(F("NUMBER_TXT"), Temporary_String);
        break;
    case 2:
        Temporary_String = String(Number[0]);
        Temporary_String += " ";
        Temporary_String += String(Operator);
        Temporary_String += " ";
        Temporary_String += String(Number[1]);
        Xila.Display.Set_Text(F("CALCULATIO_TXT"), Temporary_String);
        Temporary_String = String(Result);
        Xila.Display.Set_Text(F("NUMBER_TXT"), Temporary_String);

    default:
        break;
    }
    Xila.Display.Set_Text("NUMBER_TXT", Temporary_String);
}
