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
        if (State > 1)
        {
            Memory += atof(Numbers[3]);
        }
        else
        {
            Memory += atof(Numbers[State])
        }
        break;
    case Memory_Substract:
        if (State > 1)
        {
            Memory -= atof(Numbers[3]);
        }
        else
        {
            Memory -= atof(Numbers[State]);
        }
        break;
    case Memory_Read:
        Clear_All();
        Numbers[State] = dtostrf(Memory);
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
            Instance_Pointer->Add_Number(Pi);
            break;

        case 0x4661: // Ne : exponential number
            Instance_Pointer->Add_Number(Neper_Constant);
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
    Primary_Operator = Opertor_To_Set;
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
        Numbers[State][0] == '0';
        ;
    }
    Display();
}

double Calculator_Class::Factorial(double Number)
{
    for (uint8_t i = Number - 1; i > 0; i--)
    {
        Number *= i;
    }
    return Number;
}

double Calculator_Class::asech(double Number)
{
    double Result = sq(Number);
    Result = 1 / Result;
    Reuslt -= 1;
    Result = sqrt(Result);
    Result += 1 / Number;
    Result = log_n(Number);
    return Number;
}

double Calculator_Class::acosh(double Number)
{
    double Result = sq(Number);
    Result -= 1;
    Result = sqrt(Result);
    Result += Number;
    Result = log_n(Result);
    return Result;
}

void Calculator_Class::Compute()
{
    double Temporary_Numbers[3];

    if (State == 0)
    {
        switch (Temporary_Numbers[0])
        {
        case Pi:
            Temporary_Numbers[0] = PI;
            break;
        case Neper_Constant:
            Temporary_Numbers[0] = Neper_Constant;
            break;
        default:
            Temporary_Numbers[0] = atof(Numbers[0]);
            break;
        }

        switch (Secondary_Operator[0])
        {
        case Factorial:
            Temporary_Numbers[0] = Factorial(Temporary_Numbers[0]);
            break;

        // Simple trigonometric function
        case Sine:
            Temporary_Numbers[0] = sin(Temporary_Numbers[0]);
            break;
        case Cosine:
            Temporary_Numbers[0] = cos(Temporary_Numbers[0]);
            break;
        case Tangent:
            Temporary_Numbers[0] = tan(Temporary_Numbers[0]);
            break;
        case Secant:
            Temporary_Numbers[0] = 1 / cos(Temporary_Numbers[0]);
            break;
        case Cosecant:
            Temporary_Numbers[0] = 1 / sin(Temporary_Numbers[0]);
            break;
        case Cotangent:
            Temporary_Numbers[0] = 1 / tan(Temporary_Numbers[0]);
            break;

        // Arc trigonometric function

        case Arc_Sine:
            if (Temporary_Numbers[0] < -1 || Temporary_Numbers[0] > 1)
            {
                Error();
                return;
            }
            Temporary_Numbers[0] = asin(Temporary_Numbers[0]);
            break;
        
        case Arc_Cosine:
            if (Temporary_Numbers[0] < -1 || Temporary_Numbers[0] > 1)
            {
                Error();
                return;
            }
            Temporary_Numbers[0] = acos(Temporary_Numbers[0]);
            break;
        
        case Arc_Cotangent:
            Temporary_Numbers[0] = atan(Temporary_Numbers[0]);
            break;

        // Hyperbolic trigonometric function
        case Hyperbolic_Sine:
            Temporary_Numbers[0] = sinh(Temporary_Numbers[0]);
            break;
        case Hyperbolic_Cosine:
            Temporary_Numbers[0] = cosh(Temporary_Numbers[0]);
            break;
        case Hyperbolic_Tangent:
            Temporary_Numbers[0] = tanh(Temporary_Numbers[0]);
            break;
        case Hyperbolic_Secant:
            Temporary_Numbers[0] = 1 / cosh(Temporary_Numbers[0]);
            break;
        case Hyperbolic_Cosecant:
            if (Temporary_Numbers[0] == 0)
            {
                Error();
                return;
            }
            Temporary_Numbers[0] = 1 / sinh(Temporary_Numbers[0]);
            break;
        case Hyperbolic_Cotangent:
            if (Temporary_Numbers[0] == 0)
            {
                Error();
                return;
            }
            Temporary_Numbers[0] = cosh(Temporary_Numbers[0]) / sinh(Temporary_Numbers[0]);
            break;

        // Arc Hyperbolic Function
        case Arc_Hyperbolic_Sine:
            Temporary_Numbers[0] = asinh(Temporary_Numbers[0]);
            break;
        case Arc_Hyperbolic_Cosine:
            Temporary_Numbers[0] = acosh(Temporary_Numbers[0]);
            break;
        case Arc_Hyperbolic_Tangent:
            Temporary_Numbers[0] = atanh(Temporary_Numbers[0]);
            break;
        case Arc_Hyperbolic_Secant:
            Temporary_Numbers[0] = asech(Temporary_Numbers[0]);
            break;
        case Arc_Hyperbolic_Cosecant:
            Temporary_Numbers[0] = acosh(Temporary_Numbers[0]);
            break;
        case Arc_Hyperbolic_Cotangent:
            Temporary_Numbers[0] = acsch(Temporary_Numbers[0]);
            break;
        case Logarithm:
            Temporary_Numbers[0] = log(Temporary_Numbers[0]);
            break;
        case Natural_Logarithm:
            Temporary_Numbers[0] = ln(Temporary_Numbers[0]);
            break;
        case Binary_Logarithm:
            Temporary_Numbers[0] = log2(Temporary_Numbers[0]);
            break;
        case Squared:
            Temporary_Numbers[0] = sq(Temporary_Numbers[0]);
            break;
        case Cube:
            Temporary_Numbers[0] = Temporary_Numbers[0] * Temporary_Numbers[0] * Temporary_Numbers[0];
            break;
        case Square_Root:
            Temporary_Numbers[0] = sqrt(Temporary_Numbers[0]);
            break;
        case Cubic_Root:
            Temporary_Numbers[0] = cbrt(Temporary_Numbers[0]);
            break;
        case Inverse:
            Temporary_Numbers[0] = 1 / Temporary_Numbers[0];
            break;
        case Absolute:
            Temporary_Numbers[0] = abs(Temporary_Numbers[0]);
            break;
        default:
            break;
        }
    }
    if (State > 0)
    {
        switch (Temporary_Numbers[1])
        {
        case Pi:
            Temporary_Numbers[1] = PI;
            break;
        case Neper_Constant:
            Temporary_Numbers[1] = Neper_Constant;
            break;
        default:
            Temporary_Numbers[1] = atof(Numbers[0]);
            break;
        }

        switch (Secondary_Operator[0])
        {
        case Factorial:
            Temporary_Numbers[1] = Factorial(Temporary_Numbers[1]);
            break;
        case Sine:
            Temporary_Numbers[1] = sin(Temporary_Numbers[1]);
            break;
        case Cosine:
            Temporary_Numbers[1] = cos(Temporary_Numbers[1]);
            break;
        case Tangent:
            Temporary_Numbers[1] = tan(Temporary_Numbers[1]);
            break;
        case Hyperbolic_Sine:
            Temporary_Numbers[1] = sinh(Temporary_Numbers[1]);
            break;
        case Hyperbolic_Cosine:
            Temporary_Numbers[1] = cosh(Temporary_Numbers[1]);
            break;
        case Hyperbolic_Tangent:
            Temporary_Numbers[1] = tanh(Temporary_Numbers[1]);
            break;
        case Arc_Hyperbolic_Sine:
            Temporary_Numbers[1] = asinh(Temporary_Numbers[1]);
            break;
        case Arc_Hyperbolic_Cosine:
            Temporary_Numbers[1] = acosh(Temporary_Numbers[1]);
            break;
        case Arc_Hyperbolic_Tangent:
            Temporary_Numbers[1] = atanh(Temporary_Numbers[1]);
            break;
        case Logarithm:
            Temporary_Numbers[1] = log(Temporary_Numbers[1]);
            break;
        case Natural_Logarithm:
            Temporary_Numbers[1] = ln(Temporary_Numbers[1]);
            break;
        case Binary_Logarithm:
            Temporary_Numbers[1] = log2(Temporary_Numbers[1]);
            break;
        case Squared:
            Temporary_Numbers[1] = sq(Temporary_Numbers[1]);
            break;
        case Cube:
            Temporary_Numbers[1] = Temporary_Numbers[1] * Temporary_Numbers[1] * Temporary_Numbers[1];
            break;
        case Square_Root:
            Temporary_Numbers[1] = sqrt(Temporary_Numbers[1]);
            break;
        case Cubic_Root:
            Temporary_Numbers[1] = cbrt(Temporary_Numbers[1]);
            break;
        case Inverse:
            Temporary_Numbers[1] = 1 / Temporary_Numbers[1];
            break;
        case Absolute:
            Temporary_Numbers[1] = abs(Temporary_Numbers[1]);
            break;
        default:
            break;
        }
    }

    switch (Operator)
    {
    case Addition:
        Temporary_Numbers[3] = Temporary_Numbers[0] + Temporary_Numbers[1];
        break;
    case Substraction:
        Temporary_Numbers[3] = Temporary_Numbers[0] - Temporary_Numbers[1];
        break;
    case Multiplication:
        Temporary_Numbers[3] = Temporary_Numbers[0] * Temporary_Numbers[1];
        break;
    case Division:
        Temporary_Numbers[3] = Temporary_Numbers[0] / Temporary_Numbers[1];
        break;
    case Modulo:
        Temporary_Number[0] = (long)Number[0];
        Temporary_Number[1] = (long)Number[1];
        Result = Temporary_Number[0] % Temporary_Number[1];
        break;
    }

    State = 2;
}

float Calculator_Class::Degree_To_Radian(float Angle)
{
    Angle *= PI;
    Angle /= 180;
    return Angle;
}

void Calculator_Class::Clear()
{
    if (State > 1)
    {
        Clear_All();
    }
    else
    {
        memset(Numbers[State], 0, sizeof(Numbers[State]));
        Current_Position[State] = 0;
        if (State == 0)
        {
            Primary_Operator = 0;
        }
        Secondary_Operator[State] = 0;
    }
}

void Calculator_Class::Clear_All()
{
    State = 0;

    memset(Numbers[0], 0, sizeof(Numbers[0]));
    memset(Numbers[1], 0, sizeof(Numbers[1]));
    memset(Numbers[2], 0, sizeof(Numbers[2]));

    Secondary_Operator[0] = 0xFF;
    Secondary_Operator[1] = 0xFF;
    Primary_Operator = 0xFF;
}

void Calculator_Class::Display()
{
    Temporary_Current_Position = 0;
    memset(Temporary_Char_Array, 0, sizeof(Temporary_Char_Array));
    if (State >= 0)
    {
        Ending_Character = 0;
        switch (Secondary_Operator[0])
        {
        case Sine:
            strcpy(Temporary_Char_Array, "Sin(");
            Temporary_Current_Position += 3;
            Ending_Character = ')';
            break;
        case Cosine:
            strcpy(Temporary_Char_Array, "Cos(");
            Temporary_Current_Position += 3;
            Ending_Character = ')';
            break;
        case Tangent:
            strcpy(Temporary_Char_Array, "Tan(");
            Temporary_Current_Position += 3;
            Ending_Character = ')';
            break;
        case Arc_Sine:
            strcpy(Temporary_Char_Array, "ASin(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Arc_Cosine:
            strcpy(Temporary_Char_Array, "ACos(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Arc_Tangent:
            strcpy(Temporary_Char_Array, "ATan(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Arc_Hyperbolic_Sine:
            strcpy(Temporary_Char_Array, "ASinH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Hyperbolic_Cosine:
            strcpy(Temporary_Char_Array, "ASinH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Hyperbolic_Tangent:
            strcpy(Temporary_Char_Array, "ATanH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Factorial:
            Temporary_Current_Position += 0;
            Ending_Character = '!';
            break;
        case Logarithm:
            strcpy(Temporary_Char_Array, "Log(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Natural_Logarithm:
            strcpy(Temporary_Char_Array, "Ln(");
            Temporary_Current_Position += 3;
            break;
        case Binary_Logarithm:
            strcpy(Temporary_Char_Array, "Log2(");
            Temporary_Current_Position += 5;
            break;
        case Squared:
            Temporary_Current_Position += 0;
            Ending_Character = '²';
            break;
        case Cube:
            Temporary_Current_Position += 0;
            Ending_Character = '³';
            break;
        case Square_Root:
            strcpy(Temporary_Char_Array, "Sqrt(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Cubic_Root:
            strcpy(Temporary_Char_Array, "Cbrt(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Inverse:
            strcpy(Temporary_Char_Array, "1/(");
            Temporary_Current_Position += 3;
            Ending_Character = ')';
            break;

        case Absolute:
            strcpy(Temporary_Char_Array, "|");
            Temporary_Current_Position += 1;
            Ending_Character = '|';
            break;
        default:
            Temporary_Current_Position = 0;
            break;
        }
        switch (Numbers[0][0])
        {
        case Pi:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Pi");
            Temporary_Current_Position += 2;
            break;
        case Neper_Constant:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "e");
            Temporary_Current_Position += 1;
            break;
        default:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, Numbers[0]);
            Temporary_Current_Position += strnlen(Numbers[0], sizeof(Numbers[0]));
            break;
        }
        Temporary_Char_Array[Temporary_Current_Position++] = Ending_Character;
        if (Primary_Operator != 0)
        {
            Temporary_Char_Array[Temporary_Current_Position++] = ' ';
            Temporary_Char_Array[Temporary_Current_Position++] = Primary_Operator;
            Temporary_Char_Array[Temporary_Current_Position++] = ' ';
        }
        if (State == 0)
        {
            Xila.Display.Set_Text(F("CALCULATRIO_TXT"), Temporary_Char_Array);
            Xila.Display.Set_Text(F("RESULT_TXT"), F(""));
        }
    }

    if (State > 0)
    {
        Ending_Character = 0;
        switch (Secondary_Operator[1])
        {
        case Sine:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Sin(");
            Temporary_Current_Position += 3;
            Ending_Character = ')';
            break;
        case Cosine:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Cos(");
            Temporary_Current_Position += 3;
            Ending_Character = ')';
            break;
        case Tangent:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Tan(");
            Temporary_Current_Position += 3;
            Ending_Character = ')';
            break;
        case Arc_Sine:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ASin(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Arc_Cosine:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ACos(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Arc_Tangent:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ATan(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Arc_Hyperbolic_Sine:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ASinH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Hyperbolic_Cosine:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ASinH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Hyperbolic_Tangent:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ATanH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Factorial:
            Temporary_Current_Position += 0;
            Ending_Character = '!';
            break;
        case Logarithm:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Log(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Natural_Logarithm:
            strcpy(Temporary_Char_Array, "Ln(");
            Temporary_Current_Position += 3;
            break;
        case Binary_Logarithm:
            strcpy(Temporary_Char_Array, "Log2(");
            Temporary_Current_Position += 5;
            break;
        case Squared:
            Temporary_Current_Position += 0;
            Ending_Character = '²';
            break;
        case Cube:
            Temporary_Current_Position += 0;
            Ending_Character = '³';
            break;
        case Square_Root:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Sqrt(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Cubic_Root:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Cbrt(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Inverse:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "1/(");
            Temporary_Current_Position += 3;
            Ending_Character = ')';
            break;

        case Absolute:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "|");
            Temporary_Current_Position += 1;
            Ending_Character = '|';
            break;
        default:
            break;
        }
        switch (Numbers[1][0])
        {
        case Pi:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Pi");
            Temporary_Current_Position += 2;
            break;
        case Neper_Constant:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "e");
            Temporary_Current_Position += 1;
            break;
        default:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, Numbers[1]);
            Temporary_Current_Position += strnlen(Numbers[1], sizeof(Numbers[1]));
            break;
        }
        Temporary_Char_Array[Temporary_Current_Position++] = Ending_Character;
        if (State == 1)
        {
            Xila.Display.Set_Text(F("CALCULATIO_TXT"), Temporary_Char_Array);
        }
    }
    if (State > 1)
    {
        Xila.Display.Set_Text(F("CALCULATIO_TXT"), Temporary_Char_Array);
        Xila.Display.Set_Text(F("RESULT_TXT"), Numbers[3]);
    }
}
