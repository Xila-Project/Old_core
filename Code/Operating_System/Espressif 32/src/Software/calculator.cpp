#include "Software/Calculator.hpp"

Calculator_Class *Calculator_Class::Instance_Pointer = NULL;

Calculator_Class::Calculator_Class() : Software_Class(8),
                                       State(0xFF)
{
    Xila.Task_Create(Main_Task, "Calculator", 4 * 1024, NULL, &Task_Handle);
    Execute(Xila.Maximize);
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

uint16_t Calculator_Class::Numbers_After_Point(double Number) //usefull to know how many number to display, currently unused
{
    return 0;
}

void Calculator_Class::Memory_Operation(uint8_t Operation)
{
    switch (Operation)
    {
    case Memory_Add:
        if (State == 2)
        {
            Memory += atof(Numbers[2]);
        }
        else if (State == 0)
        {
            Memory += atof(Numbers[State]);
        }
        break;
    case Memory_Substract:
        if (State == 2)
        {
            Memory -= atof(Numbers[2]);
        }
        else if (State == 0)
        {
            Memory -= atof(Numbers[State]);
        }
        break;
    case Memory_Read:
        Clear_All();
        dtostrf(Memory, sizeof(Numbers[0]), POINT_PRECISION, Numbers[0]);
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

void Calculator_Class::Refresh_Keys()
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
        case Xila.Close:
            delete Instance_Pointer;
            vTaskDelete(NULL);
            break;
        case Xila.Maximize:
            Xila.Display.Set_Current_Page(F("Calculator"));
            break;
        case Xila.Minimize:
            vTaskSuspend(NULL);
            break;

        // Number editing keys
        case 0x4E30: //Nx
            Instance_Pointer->Add_Number('0');
            break;

        case 0x4E31:
            Instance_Pointer->Add_Number('1');
            break;

        case 0x4E32:
            Instance_Pointer->Add_Number('2');
            break;

        case 0x4E33:
            Instance_Pointer->Add_Number('3');
            break;

        case 0x4E34:
            Instance_Pointer->Add_Number('4');
            break;

        case 0x4E35:
            Instance_Pointer->Add_Number('5');
            break;

        case 0x4E36:
            Instance_Pointer->Add_Number('6');
            break;

        case 0x4E37:
            Instance_Pointer->Add_Number('7');
            break;
        case 0x4E38:
            Instance_Pointer->Add_Number('8');
            break;

        case 0x4E39:
            Instance_Pointer->Add_Number('9');
            break;

        case 0x506F: // Po
            Instance_Pointer->Add_Number('.');
            break;

        case 0x5069: // Pi
            Instance_Pointer->Add_Number(Pi);
            break;

        case 0x5261: // Ra : random
            Instance_Pointer->Add_Number(Random);
            break;

        case 0x5353: // SS : switch symbol
            Instance_Pointer->Add_Number(Symbol);
            break;

        case 0x4571: //Eq
            Instance_Pointer->Compute();

        case 0x436C: //Cl
            Instance_Pointer->Clear();
            break;

            // Primary Operator keys

        case 0x4164: //Ad
            Instance_Pointer->Set_Primary_Operator(Addition);
            break;

        case 0x5375: //Su
            Instance_Pointer->Set_Primary_Operator(Substraction);
            break;

        case 0x4D75: //Mu
            Instance_Pointer->Set_Primary_Operator(Multiplication);
            break;

        case 0x4469: //Di
            Instance_Pointer->Set_Primary_Operator(Division);
            break;

        case 0x4D6F: // Mo
            Instance_Pointer->Set_Primary_Operator(Modulo);
            break;
        case 0x5077: // Pw
            Instance_Pointer->Set_Primary_Operator(Power);
            break;
        case 0x526F: // Ro
            Instance_Pointer->Set_Primary_Operator(Root);
            break;
        // Memory keys
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

            // Secondary operator keys

        case 0x4661: // Fa : factorial
            Instance_Pointer->Set_Secondary_Operator(Factorial);
            break;

        case 0x4162: // Ab
            Instance_Pointer->Set_Secondary_Operator(Absolute);
            break;

        case 0x5371: // Sq
            Instance_Pointer->Set_Secondary_Operator(Squared);
            break;

        case 0x4375: // Cu
            Instance_Pointer->Set_Secondary_Operator(Cube);
            break;

        case 0x5352: // SR
            Instance_Pointer->Set_Secondary_Operator(Square_Root);
            break;

        case 0x4352: // CR
            Instance_Pointer->Set_Secondary_Operator(Cubic_Root);
            break;

        case 0x496E: // In
            Instance_Pointer->Set_Secondary_Operator(Inverse);
            break;

        // Keys switch
        case 0x5332: //S2
            if (bitRead(Instance_Pointer->Keys_Mode, 1) == 1)
            {
                bitWrite(Instance_Pointer->Keys_Mode, 1, 0);
            }
            else
            {
                bitWrite(Instance_Pointer->Keys_Mode, 1, 1);
            }
            Instance_Pointer->Refresh_Keys();
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
            Instance_Pointer->Refresh_Keys();
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

        // Dual function keys
        case 0x6578: // ex : exp(x) / e (neper constant)
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 1)
            {
                Instance_Pointer->Add_Number(Neper_Constant);
            }
            else
            {
                Instance_Pointer->Set_Secondary_Operator(Exponential);
            }
            break;

        case 0x4545: // EE : 10^x / 2^x
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 1)
            {
                Instance_Pointer->Add_Number(Power_10);
            }
            else
            {
                Instance_Pointer->Set_Secondary_Operator(Power_2);
            }
            break;
        case 0x4C6E: // Ln : Ln / LogY
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 1)
            {
                Instance_Pointer->Set_Secondary_Operator(Natural_Logarithm);
            }
            else
            {
                Instance_Pointer->Set_Primary_Operator(Power_2);
            }
            break;

        case 0x4C31: // L1 : log10 / log2
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 1)
            {
                Instance_Pointer->Set_Secondary_Operator(Decimal_Logarithm);
            }
            else
            {
                Instance_Pointer->Set_Secondary_Operator(Binary_Logarithm);
            }
            break;

        case 0x5369: // Si:
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 1)
            {
                if (bitRead(Instance_Pointer->Keys_Mode, Hyperbolic) == 1)
                {
                    Instance_Pointer->Set_Secondary_Operator(Arc_Hyperbolic_Sine);
                }
                else
                {
                    Instance_Pointer->Set_Secondary_Operator(Arc_Sine);
                }
            }
            else
            {
                if (bitRead(Instance_Pointer->Keys_Mode, Hyperbolic) == 1)
                {
                    Instance_Pointer->Set_Secondary_Operator(Hyperbolic_Sine);
                }
                else
                {
                    Instance_Pointer->Set_Secondary_Operator(Sine);
                }
            }
            break;
        case 0x436F: // Co:
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 1)
            {
                if (bitRead(Instance_Pointer->Keys_Mode, Hyperbolic) == 1)
                {
                    Instance_Pointer->Set_Secondary_Operator(Arc_Hyperbolic_Cosine);
                }
                else
                {
                    Instance_Pointer->Set_Secondary_Operator(Arc_Cosine);
                }
            }
            else
            {
                if (bitRead(Instance_Pointer->Keys_Mode, Hyperbolic) == 1)
                {
                    Instance_Pointer->Set_Secondary_Operator(Hyperbolic_Cosine);
                }
                else
                {
                    Instance_Pointer->Set_Secondary_Operator(Cosine);
                }
            }
            break;
        case 0x5461: // Ta
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 1)
            {
                if (bitRead(Instance_Pointer->Keys_Mode, Hyperbolic) == 1)
                {
                    Instance_Pointer->Set_Secondary_Operator(Arc_Hyperbolic_Tangent);
                }
                else
                {
                    Instance_Pointer->Set_Secondary_Operator(Arc_Tangent);
                }
            }
            else
            {
                if (bitRead(Instance_Pointer->Keys_Mode, Hyperbolic) == 1)
                {
                    Instance_Pointer->Set_Secondary_Operator(Hyperbolic_Tangent);
                }
                else
                {
                    Instance_Pointer->Set_Secondary_Operator(Tangent);
                }
            }
            break;

        case 0x5365: // Se :
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 1)
            {
                if (bitRead(Instance_Pointer->Keys_Mode, Hyperbolic) == 1)
                {
                    Instance_Pointer->Set_Secondary_Operator(Arc_Hyperbolic_Secant);
                }
                else
                {
                    Instance_Pointer->Set_Secondary_Operator(Arc_Secant);
                }
            }
            else
            {
                if (bitRead(Instance_Pointer->Keys_Mode, Hyperbolic) == 1)
                {
                    Instance_Pointer->Set_Secondary_Operator(Hyperbolic_Secant);
                }
                else
                {
                    Instance_Pointer->Set_Secondary_Operator(Secant);
                }
            }
            break;

        case 0x4373: // Cs :
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 1)
            {
                if (bitRead(Instance_Pointer->Keys_Mode, Hyperbolic) == 1)
                {
                    Instance_Pointer->Set_Secondary_Operator(Arc_Hyperbolic_Cosecant);
                }
                else
                {
                    Instance_Pointer->Set_Secondary_Operator(Arc_Cosecant);
                }
            }
            else
            {
                if (bitRead(Instance_Pointer->Keys_Mode, Hyperbolic) == 1)
                {
                    Instance_Pointer->Set_Secondary_Operator(Hyperbolic_Cosecant);
                }
                else
                {
                    Instance_Pointer->Set_Secondary_Operator(Cosecant);
                }
            }
            break;

        case 0x4374: // Ct:
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 1)
            {
                if (bitRead(Instance_Pointer->Keys_Mode, Hyperbolic) == 1)
                {
                    Instance_Pointer->Set_Secondary_Operator(Arc_Hyperbolic_Cotangent);
                }
                else
                {
                    Instance_Pointer->Set_Secondary_Operator(Arc_Cotangent);
                }
            }
            else
            {
                if (bitRead(Instance_Pointer->Keys_Mode, Hyperbolic) == 1)
                {
                    Instance_Pointer->Set_Secondary_Operator(Hyperbolic_Cotangent);
                }
                else
                {
                    Instance_Pointer->Set_Secondary_Operator(Cotangent);
                }
            }
            break;

        default:
            break;
        }
        Xila.Delay(20);
    }
}

void Calculator_Class::Add_Number(char const &Number_To_Add)
{
    switch (Number_To_Add)
    {
    case Pi:
        Clear();
        Numbers[State][0] = 'P';
        break;
    case Neper_Constant:
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
    case Power_10:
        if (Exponent[State] != 0)
        {
            Numbers[State][Current_Position[State]++] = 'E';
            Exponent[State] = Current_Position[State];
            Numbers[State][Current_Position[State]++] = '0';
        }
        break;
    case Symbol:
        if (Exponent[State] != 0)
        {
            if (Numbers[State][Exponent[State]] == '0')
            {
                Numbers[State][Exponent[State]] = '-';
            }
            else
            {
                Numbers[State][Exponent[State]] = '0';
            }
        }
        else
        {
            if (Numbers[State][0] == '0')
            {
                Numbers[State][0] = '-';
            }
            else
            {
                Numbers[State][0] = '0';
            }
        }
        break;
    default:
        if (isDigit(Numbers[State][0]))
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

void Calculator_Class::Set_Secondary_Operator(char const &Operator_To_Set)
{
    if (State > 1)
    {
        memset(Numbers[0], 0, sizeof(Numbers[0]));
        memset(Numbers[1], 0, sizeof(Numbers[1]));
        strcpy(Numbers[0], Numbers[2]);
        Exponent[0] = Exponent[2];
        Decimal_Point[0] = Decimal_Point[2];
        Current_Position[0] = Current_Position[2];
        Secondary_Operator[1] = 0;
        Primary_Operator = 0;
        State = 0;
    }
    Secondary_Operator[State] = Operator_To_Set;
    Display();
}

void Calculator_Class::Set_Primary_Operator(char const &Opertor_To_Set)
{
    if (State > 1)
    {
        memset(Numbers[0], 0, sizeof(Numbers[0]));
        memset(Numbers[1], 0, sizeof(Numbers[1]));
        strcpy(Numbers[0], Numbers[2]);
        Exponent[0] = Exponent[2];
        Decimal_Point[0] = Decimal_Point[2];
        Current_Position[0] = Current_Position[2];
        Secondary_Operator[1] = 0;
    }
    Primary_Operator = Opertor_To_Set;
    State = 1;
    Display();
}

double Calculator_Class::fact(double Number)
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
    Result -= 1;
    Result = sqrt(Result);
    Result += 1 / Number;
    Result = log(Number);
    return Result;
}

double Calculator_Class::acsch(double Number)
{
    double Result = sq(Number);
    Result = 1 / Result;
    Result += 1;
    Result = sqrt(Result);
    Result += 1 / Number;
    Result = log(Number);
    return Result;
}

double Calculator_Class::acoth(double Number)
{
    double Result = Number + 1;
    Result /= Number - 1;
    Result = log(Result);
    Result /= 2;
    return Result;
}

double Calculator_Class::asec(double Number)
{
    Number = acos(1 / Number);
    return Number;
}

double Calculator_Class::acsc(double Number)
{
    Number = asin(1 / Number);
    return Number;
}

double Calculator_Class::acot(double Number)
{
    Number = atan(Number);
    Number = (PI / 2) - Number;
    return Number;
}

void Calculator_Class::Compute_Secondary(uint8_t Selected_Number)
{
    switch (Numbers[Selected_Number][0]) // Set number
    {
    case Pi:
        Temporary_Numbers[Selected_Number] = PI;
        break;
    case Neper_Constant:
        Temporary_Numbers[Selected_Number] = EULER;
        break;
    default:
        Temporary_Numbers[Selected_Number] = atof(Numbers[Selected_Number]);
        break;
    }

    switch (Secondary_Operator[Selected_Number]) // Apply secondary operator
    {
    case Factorial:
        Temporary_Numbers[Selected_Number] = fact(Temporary_Numbers[Selected_Number]);
        break;

    // Simple trigonometric function
    case Sine:
        Degree_To_Radian(Selected_Number);
        Temporary_Numbers[Selected_Number] = sin(Temporary_Numbers[Selected_Number]);
        break;
    case Cosine:
        Degree_To_Radian(Selected_Number);
        Temporary_Numbers[Selected_Number] = cos(Temporary_Numbers[Selected_Number]);
        break;
    case Tangent:
        Degree_To_Radian(Selected_Number);
        Temporary_Numbers[Selected_Number] = tan(Temporary_Numbers[Selected_Number]);
        break;
    case Secant:
        Degree_To_Radian(Selected_Number);
        Temporary_Numbers[Selected_Number] = 1 / cos(Temporary_Numbers[Selected_Number]);
        break;
    case Cosecant:
        Degree_To_Radian(Selected_Number);
        Temporary_Numbers[Selected_Number] = 1 / sin(Temporary_Numbers[Selected_Number]);
        break;
    case Cotangent:
        Degree_To_Radian(Selected_Number);
        Temporary_Numbers[Selected_Number] = 1 / tan(Temporary_Numbers[Selected_Number]);
        break;

        // Arc trigonometric function

    case Arc_Sine:
        if (Temporary_Numbers[Selected_Number] < -1 || Temporary_Numbers[Selected_Number] > 1)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = asin(Temporary_Numbers[Selected_Number]);
        break;

    case Arc_Cosine:
        if (Temporary_Numbers[Selected_Number] < -1 || Temporary_Numbers[Selected_Number] > 1)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = acos(Temporary_Numbers[Selected_Number]);
        break;

    case Arc_Tangent:
        Temporary_Numbers[Selected_Number] = atan(Temporary_Numbers[Selected_Number]);
        break;

    case Arc_Secant:
        Temporary_Numbers[Selected_Number] = asec(Temporary_Numbers[Selected_Number]);
        break;
    case Arc_Cosecant:
        Temporary_Numbers[Selected_Number] = acsc(Temporary_Numbers[Selected_Number]);
        break;
    case Arc_Cotangent:
        Temporary_Numbers[Selected_Number] = acot(Temporary_Numbers[Selected_Number]);
        break;
    // Hyperbolic trigonometric function
    case Hyperbolic_Sine:
        Temporary_Numbers[Selected_Number] = sinh(Temporary_Numbers[Selected_Number]);
        break;
    case Hyperbolic_Cosine:
        Temporary_Numbers[Selected_Number] = cosh(Temporary_Numbers[Selected_Number]);
        break;
    case Hyperbolic_Tangent:
        Temporary_Numbers[Selected_Number] = tanh(Temporary_Numbers[Selected_Number]);
        break;
    case Hyperbolic_Secant:
        Temporary_Numbers[Selected_Number] = 1 / cosh(Temporary_Numbers[Selected_Number]);
        break;
    case Hyperbolic_Cosecant:
        if (Temporary_Numbers[Selected_Number] == 0)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = 1 / sinh(Temporary_Numbers[Selected_Number]);
        break;
    case Hyperbolic_Cotangent:
        if (Temporary_Numbers[Selected_Number] == 0)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = cosh(Temporary_Numbers[Selected_Number]) / sinh(Temporary_Numbers[Selected_Number]);
        break;

    // Arc Hyperbolic Function
    case Arc_Hyperbolic_Sine:
        Temporary_Numbers[Selected_Number] = asinh(Temporary_Numbers[Selected_Number]);
        break;
    case Arc_Hyperbolic_Cosine:
        Temporary_Numbers[Selected_Number] = acosh(Temporary_Numbers[Selected_Number]);
        break;
    case Arc_Hyperbolic_Tangent:
        Temporary_Numbers[Selected_Number] = atanh(Temporary_Numbers[Selected_Number]);
        break;
    case Arc_Hyperbolic_Secant:
        Temporary_Numbers[Selected_Number] = asech(Temporary_Numbers[Selected_Number]);
        break;
    case Arc_Hyperbolic_Cosecant:
        Temporary_Numbers[Selected_Number] = acsch(Temporary_Numbers[Selected_Number]);
        break;
    case Arc_Hyperbolic_Cotangent:
        if (Temporary_Numbers[Selected_Number] <= -1 || Temporary_Numbers[Selected_Number] >= 1)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = acsch(Temporary_Numbers[Selected_Number]);
        break;

    case Decimal_Logarithm:
        if (Temporary_Numbers[Selected_Number] <= 0)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = log10(Temporary_Numbers[Selected_Number]);
        break;
    case Natural_Logarithm:
        if (Temporary_Numbers[Selected_Number] <= 0)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = log(Temporary_Numbers[Selected_Number]);
        break;
    case Binary_Logarithm:
        if (Temporary_Numbers[Selected_Number] <= 0)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = log2(Temporary_Numbers[Selected_Number]);
        break;
    case Squared:
        Temporary_Numbers[Selected_Number] = sq(Temporary_Numbers[Selected_Number]);
        break;
    case Cube:
        Temporary_Numbers[Selected_Number] = Temporary_Numbers[Selected_Number] * Temporary_Numbers[Selected_Number] * Temporary_Numbers[Selected_Number];
        break;
    case Square_Root:
        Temporary_Numbers[Selected_Number] = sqrt(Temporary_Numbers[Selected_Number]);
        break;
    case Cubic_Root:
        Temporary_Numbers[Selected_Number] = cbrt(Temporary_Numbers[Selected_Number]);
        break;
    case Inverse:
        if (Temporary_Numbers[Selected_Number] == 0)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = 1 / Temporary_Numbers[Selected_Number];
        break;
    case Absolute:
        Temporary_Numbers[Selected_Number] = abs(Temporary_Numbers[Selected_Number]);
        break;
    case Exponential:
        Temporary_Numbers[Selected_Number] = exp(Temporary_Numbers[Selected_Number]);
        break;
    default:
        break;
    }
}

void Calculator_Class::Compute()
{

    Compute_Secondary(0);
    Compute_Secondary(1);

    switch (Primary_Operator)
    {
    case Addition:
        Temporary_Numbers[2] = Temporary_Numbers[0] + Temporary_Numbers[1];
        break;
    case Substraction:
        Temporary_Numbers[2] = Temporary_Numbers[0] - Temporary_Numbers[1];
        break;
    case Multiplication:
        Temporary_Numbers[2] = Temporary_Numbers[0] * Temporary_Numbers[1];
        break;
    case Division:
        Temporary_Numbers[2] = Temporary_Numbers[0] / Temporary_Numbers[1];
        break;
    case Modulo:
        Temporary_Numbers[2] = fmod(Temporary_Numbers[0], Temporary_Numbers[1]);
        break;
    case Power:
        Temporary_Numbers[2] = pow(Temporary_Numbers[0], Temporary_Numbers[1]);
        break;
    case Root:
        Temporary_Numbers[2] = pow(Temporary_Numbers[0], 1 / Temporary_Numbers[1]);
        break;
    default: // No primary operator
        Temporary_Numbers[2] = Temporary_Numbers[0];
        break;
    }
    dtostrf(Temporary_Numbers[2], sizeof(Numbers[2]), POINT_PRECISION, Numbers[2]);
    State = 2;
    Display();
}

void Calculator_Class::Degree_To_Radian(uint8_t Selected_Number)
{
    if (bitRead(Keys_Mode, Angle) == Degree)
    {
        Temporary_Numbers[Selected_Number] *= DEG_TO_RAD;
    }
}

void Calculator_Class::Clear()
{
    if (State == 1)
    {
        if (Numbers[1][0] == 0)
        {
            Primary_Operator = 0;
            State = 0;
        }
        else
        {
            memset(Numbers[1], 0, sizeof(Numbers[1]));
            Current_Position[1] = 0;
            Exponent[1] = 0;
            Decimal_Point[1] = 0;
            Secondary_Operator[1] = 0;
        }
    }
    else
    {
        Clear_All();
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

    Exponent[0] = 0;
    Exponent[1] = 0;
    Exponent[2] = 0;

    Decimal_Point[0] = 0;
    Decimal_Point[1] = 0;
    Decimal_Point[2] = 0;

    Current_Position[0] = 0;
    Current_Position[1] = 0;
    Current_Position[2] = 0;

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
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Cosine:
            strcpy(Temporary_Char_Array, "Cos(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Tangent:
            strcpy(Temporary_Char_Array, "Tan(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Secant:
            strcpy(Temporary_Char_Array, "Sec(");
            Temporary_Current_Position += 4;
            break;
        case Cosecant:
            strcpy(Temporary_Char_Array, "Csc(");
            Temporary_Current_Position += 4;
            break;
        case Cotangent:
            strcpy(Temporary_Char_Array, "Cot(");
            Temporary_Current_Position += 4;
            break;
        case Arc_Sine:
            strcpy(Temporary_Char_Array, "ASin(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Cosine:
            strcpy(Temporary_Char_Array, "ACos(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Tangent:
            strcpy(Temporary_Char_Array, "ATan(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Secant:
            strcpy(Temporary_Char_Array, "ASec(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Cosecant:
            strcpy(Temporary_Char_Array, "ACsc(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Cotangent:
            strcpy(Temporary_Char_Array, "ACot(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Hyperbolic_Sine:
            strcpy(Temporary_Char_Array, "SinH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Hyperbolic_Cosine:
            strcpy(Temporary_Char_Array, "CosH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Hyperbolic_Tangent:
            strcpy(Temporary_Char_Array, "TanH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Hyperbolic_Secant:
            strcpy(Temporary_Char_Array, "SecH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Hyperbolic_Cosecant:
            strcpy(Temporary_Char_Array, "CscH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Hyperbolic_Cotangent:
            strcpy(Temporary_Char_Array, "CotH(");
            Temporary_Current_Position += 5;
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
        case Arc_Hyperbolic_Secant:
            strcpy(Temporary_Char_Array, "ASecH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Hyperbolic_Cotangent:
            strcpy(Temporary_Char_Array, "ACotH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Hyperbolic_Cosecant:
            strcpy(Temporary_Char_Array, "ACscH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Factorial:
            //Temporary_Current_Position += 0;
            Ending_Character = '!';
            break;
        /*case Logarithm:
            strcpy(Temporary_Char_Array, "Log(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;*/
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
            Ending_Character = 0xB2;
            break;
        case Cube:
            Temporary_Current_Position += 0;
            Ending_Character = 0xB3;
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
        case Exponential:
            strcpy(Temporary_Char_Array, "Exp(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Power_2:
            strcpy(Temporary_Char_Array, "2^(");
            Temporary_Current_Position += 4;
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
            //Temporary_Current_Position = 0;
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
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Cosine:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Cos(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Tangent:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Tan(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Secant:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Sec(");
            Temporary_Current_Position += 4;
            break;
        case Cosecant:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Csc(");
            Temporary_Current_Position += 4;
            break;
        case Cotangent:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Cot(");
            Temporary_Current_Position += 4;
            break;
        case Arc_Sine:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ASin(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Cosine:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ACos(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Tangent:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ATan(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Secant:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ASec(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Cosecant:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ACsc(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Cotangent:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ACot(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Hyperbolic_Sine:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "SinH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Hyperbolic_Cosine:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "CosH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Hyperbolic_Tangent:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "TanH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Hyperbolic_Secant:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "SecH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Hyperbolic_Cosecant:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "CscH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Hyperbolic_Cotangent:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "CotH(");
            Temporary_Current_Position += 5;
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
        case Arc_Hyperbolic_Secant:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ASecH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Hyperbolic_Cotangent:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ACotH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Arc_Hyperbolic_Cosecant:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "ACscH(");
            Temporary_Current_Position += 5;
            Ending_Character = ')';
            break;
        case Factorial:
            //Temporary_Current_Position += 0;
            Ending_Character = '!';
            break;
        /*case Logarithm:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Log(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;*/
        case Natural_Logarithm:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Ln(");
            Temporary_Current_Position += 3;
            break;
        case Binary_Logarithm:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Log2(");
            Temporary_Current_Position += 5;
            break;
        case Squared:
            Temporary_Current_Position += 0;
            Ending_Character = 0xB2;
            break;
        case Cube:
            Temporary_Current_Position += 0;
            Ending_Character = 0xB3;
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
        case Exponential:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "Exp(");
            Temporary_Current_Position += 4;
            Ending_Character = ')';
            break;
        case Power_2:
            strcpy(Temporary_Char_Array + Temporary_Current_Position, "2^(");
            Temporary_Current_Position += 4;
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
            //Temporary_Current_Position = 0;
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
        Xila.Display.Set_Text(F("CALCULATIO_TXT"), Temporary_Char_Array);
    }
    if (State > 1)
    {
        Xila.Display.Set_Text(F("RESULT_TXT"), Numbers[0]);
    }
}
