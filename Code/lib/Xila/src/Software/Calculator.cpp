#include "Software/Calculator.hpp"

Calculator_Class *Calculator_Class::Instance_Pointer = NULL;

Calculator_Class::Calculator_Class() : Xila_Class::Software(Calculator_Handle),
                                       State(0xFF),
                                       Keys_Mode(0)
{
    Xila.Task.Create(Main_Task, "Calculator", Memory_Chunk(4), NULL, &Task_Handle);
}

Calculator_Class::~Calculator_Class()
{
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
}

Xila_Class::Software *Calculator_Class::Load()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Calculator_Class();
    return Instance_Pointer;
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
        Xila.Mathematics.Float_To_String(Memory, -1, POINT_PRECISION, Numbers[0]);
        Send_Instruction('R', 'I');
        break;
    case Memory_Clear:
        Memory = 0;
        break;
    }
}

void Calculator_Class::Switch_Angle_Unity()
{
    if (bitRead(Keys_Mode, Angle) == 1)
    {
        bitWrite(Keys_Mode, Angle, 0);
        Xila.Display.Set_Text(F("ANGLE_BUT"), F("Rad"));
    }
    else
    {
        bitWrite(Keys_Mode, Angle, 1);
        Xila.Display.Set_Text(F("ANGLE_BUT"), F("Deg"));
    }
}

void Calculator_Class::Refresh_Keys()
{
    if (bitRead(Keys_Mode, Second) == 1) // Second enabled
    {

        if (bitRead(Keys_Mode, Hyperbolic) == 1) // all enabled
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
        if (bitRead(Keys_Mode, Hyperbolic) == 1) // hyperbolic enabled
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
        switch (Instance_Pointer->Get_Instruction())
        {
        case Xila.Idle: //idle
            if (Xila.Software_Management.Get_State(Calculator_Handle) == Xila.Minimized)
            {
                Xila.Task.Delay(90);
            }
            else
            {
                while (Xila.Keyboard.Available())
                {
                    switch (Xila.Keyboard.Read())
                    {
                    case '0':
                        Instance_Pointer->Send_Instruction('N', '0');
                        break;
                    case '1':
                        Instance_Pointer->Send_Instruction('N', '1');
                        break;
                    case '2':
                        Instance_Pointer->Send_Instruction('N', '2');
                        break;
                    case '3':
                        Instance_Pointer->Send_Instruction('N', '3');
                        break;
                    case '4':
                        Instance_Pointer->Send_Instruction('N', '4');
                        break;
                    case '5':
                        Instance_Pointer->Send_Instruction('N', '5');
                        break;
                    case '6':
                        Instance_Pointer->Send_Instruction('N', '6');
                        break;
                    case '7':
                        Instance_Pointer->Send_Instruction('N', '7');
                        break;
                    case '8':
                        Instance_Pointer->Send_Instruction('N', '8');
                        break;
                    case '9':
                        Instance_Pointer->Send_Instruction('N', '9');
                        break;
                    case '=':
                    case Xila.Keyboard.Enter:
                        Instance_Pointer->Send_Instruction('E', 'q');
                        break;
                    case Xila.Keyboard.Backspace:
                        Instance_Pointer->Send_Instruction('C', 'E');
                        break;
                    case '-':
                        Instance_Pointer->Send_Instruction('S', 'u');
                        break;
                    case '+':
                        Instance_Pointer->Send_Instruction('A', 'd');
                        break;
                    case '*':
                        Instance_Pointer->Send_Instruction('M', 'u');
                        break;
                    case ':':
                    case '/':
                        Instance_Pointer->Send_Instruction('D', 'i');
                        break;
                    case 'S':
                        Instance_Pointer->Send_Instruction('S', 'i');
                        break;
                    case 'C':
                        Instance_Pointer->Send_Instruction('C', 'o');
                        break;
                    case 'T':
                        Instance_Pointer->Send_Instruction('T', 'a');
                        break;
                    case 's':
                        Instance_Pointer->Send_Instruction('S', 'e');
                        break;
                    case 'c':
                        Instance_Pointer->Send_Instruction('C', 's');
                        break;
                    case 't':
                        Instance_Pointer->Send_Instruction('C', 't');
                        break;
                    case '.':
                        Instance_Pointer->Send_Instruction('P', 'o');
                        break;
                    case 'f':
                    case 'F':
                        Instance_Pointer->Send_Instruction('F', 'a');
                        break;
                    case '^':
                        Instance_Pointer->Send_Instruction('P', 'w');
                        break;
                    case '%':
                        Instance_Pointer->Send_Instruction('M', 'o');
                        break;
                    case 'r':
                    case 'R':
                        Instance_Pointer->Send_Instruction('R', 'a');
                        break;
                    case 'i':
                    case 'I':
                        Instance_Pointer->Send_Instruction('I', 'n');
                        break;
                    case 'a':
                    case 'A':
                        Instance_Pointer->Send_Instruction('R', 'a');
                        break;
                    case 'h':
                    case 'H':
                        Instance_Pointer->Send_Instruction('S', 'H');
                        break;
                    case 'p':
                    case 'P':
                        Instance_Pointer->Send_Instruction('P', 'i');
                        break;
                    case 'E':
                    case 'e':
                        Instance_Pointer->Send_Instruction('e', 'x');
                        break;
                    default:
                        break;
                    }
                }
            }
            Xila.Task.Delay(10);
            break;

        case Xila.Hibernate:
        case Xila.Shutdown:
        case Xila.Restart:
        case Instruction('C', 'l'):
            Xila.Software_Management.Close(Calculator_Handle);
            break;
        case Instruction('M', 'i'):
            Xila.Software_Management.Minimize(Calculator_Handle);
            break;

        case Xila.Close:
            delete Instance_Pointer;
            Xila.Task.Delete();
            break;
        case Xila.Maximize:
            Xila.Display.Set_Current_Page(F("Calculator"));
            Instance_Pointer->Send_Instruction('R', 'I');
            Instance_Pointer->Send_Instruction('R', 'K');
            break;
        case Xila.Minimize:
            break;
        case Xila.Open:
            Instance_Pointer->Clear_All();
            Xila.Display.Set_Current_Page(F("Calculator"));
            Instance_Pointer->Send_Instruction('R', 'I');
            Instance_Pointer->Send_Instruction('R', 'K');
            break;
        case Instruction('R', 'I'):
            Instance_Pointer->Refresh_Interface();
            break;
        case Instruction('R', 'K'):
            Instance_Pointer->Refresh_Keys();
            break;
        // Number editing keys
        case Instruction('N', '0'): //Nx
            Instance_Pointer->Add_Number('0');
            break;

        case Instruction('N', '1'):

            Instance_Pointer->Add_Number('1');
            break;

        case Instruction('N', '2'):
            Instance_Pointer->Add_Number('2');
            break;

        case Instruction('N', '3'):
            Instance_Pointer->Add_Number('3');
            break;

        case Instruction('N', '4'):
            Instance_Pointer->Add_Number('4');
            break;

        case Instruction('N', '5'):
            Instance_Pointer->Add_Number('5');
            break;

        case Instruction('N', '6'):
            Instance_Pointer->Add_Number('6');
            break;

        case Instruction('N', '7'):
            Instance_Pointer->Add_Number('7');
            break;
        case Instruction('N', '8'):
            Instance_Pointer->Add_Number('8');
            break;

        case Instruction('N', '9'):
            Instance_Pointer->Add_Number('9');
            break;

        case Instruction('P', 'o'): // Po
            Instance_Pointer->Add_Number('.');
            break;

        case Instruction('P', 'i'): // Pi
            Instance_Pointer->Add_Number(Pi);
            break;

        case Instruction('R', 'a'): // Ra : random
            Instance_Pointer->Add_Number(Random);
            break;

        case Instruction('S', 'S'): // SS : switch symbol
            Instance_Pointer->Add_Number(Symbol);
            break;

        case Instruction('E', 'q'): //Eq
            Instance_Pointer->Compute();

            break;
        case Instruction('C', 'E'): // Clear
            Instance_Pointer->Clear();
            Instance_Pointer->Send_Instruction('R', 'I');
            break;

            // Primary Operator keys

        case Instruction('A', 'd'): //Ad
            Instance_Pointer->Set_Primary_Operator(Addition);
            break;

        case Instruction('S', 'u'): //Su
            Instance_Pointer->Set_Primary_Operator(Substraction);
            break;

        case Instruction('M', 'u'): //Mu
            Instance_Pointer->Set_Primary_Operator(Multiplication);
            break;

        case Instruction('D', 'i'): //Di
            Instance_Pointer->Set_Primary_Operator(Division);
            break;

        case Instruction('M', 'o'): // Mo
            Instance_Pointer->Set_Primary_Operator(Modulo);
            break;
        case Instruction('P', 'w'): // Pw
            Instance_Pointer->Set_Primary_Operator(Power);
            break;
        case Instruction('R', 'o'): // Ro
            Instance_Pointer->Set_Primary_Operator(Root);
            break;
        // Memory keys
        case Instruction('M', 'C'): // MC
            Instance_Pointer->Memory_Operation(Memory_Clear);
            break;
        case Instruction('M', 'R'): // MR
            Instance_Pointer->Memory_Operation(Memory_Read);
            break;
        case Instruction('M', '+'): // M+
            Instance_Pointer->Memory_Operation(Memory_Add);
            break;
        case Instruction('M', '-'): // M-
            Instance_Pointer->Memory_Operation(Memory_Substract);
            break;

            // Secondary operator keys

        case Instruction('F', 'a'): // Fa : factorial
            Instance_Pointer->Set_Secondary_Operator(Factorial);
            break;

        case Instruction('A', 'b'): // Ab
            Instance_Pointer->Set_Secondary_Operator(Absolute);
            break;

        case Instruction('S', 'q'): // Sq
            Instance_Pointer->Set_Secondary_Operator(Squared);
            break;

        case Instruction('C', 'u'): // Cu
            Instance_Pointer->Set_Secondary_Operator(Cube);
            break;

        case Instruction('S', 'R'): // SR
            Instance_Pointer->Set_Secondary_Operator(Square_Root);
            break;

        case Instruction('C', 'R'): // CR
            Instance_Pointer->Set_Secondary_Operator(Cubic_Root);
            break;

        case Instruction('I', 'n'): // In
            Instance_Pointer->Set_Secondary_Operator(Inverse);
            break;

        // Keys switch
        case Instruction('S', '2'): // Enable second
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 1)
            {
                bitWrite(Instance_Pointer->Keys_Mode, Second, 0);
            }
            else
            {
                bitWrite(Instance_Pointer->Keys_Mode, Second, 1);
            }
            Instance_Pointer->Send_Instruction('R', 'K');
            break;

        case Instruction('S', 'H'): // Enable hyperbolic
            if (bitRead(Instance_Pointer->Keys_Mode, Hyperbolic) == 1)
            {
                bitWrite(Instance_Pointer->Keys_Mode, Hyperbolic, 0);
            }
            else
            {
                bitWrite(Instance_Pointer->Keys_Mode, Hyperbolic, 1);
            }
            Instance_Pointer->Send_Instruction('R', 'K');
            break;

        case Instruction('S', 'A'): // SA : switch Angle unity to Radian
            if (bitRead(Instance_Pointer->Keys_Mode, Angle) == 1)
            {
                bitWrite(Instance_Pointer->Keys_Mode, Angle, 0);
                Xila.Display.Set_Text(F("ANGLE_BUT"), F("Rad"));
            }
            else
            {
                bitWrite(Instance_Pointer->Keys_Mode, Angle, 1);
                Xila.Display.Set_Text(F("ANGLE_BUT"), F("Deg"));
            }
            break;

        // Dual function keys
        case Instruction('e', 'x'): // ex : exp(x) / e (neper constant)
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 0)
            {
                Instance_Pointer->Set_Secondary_Operator(Exponential);
            }
            else
            {
                Instance_Pointer->Add_Number(Neper_Constant);
            }
            break;

        case Instruction('E', 'E'): // EE : 10^x / 2^x
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 0)
            {
                Instance_Pointer->Set_Secondary_Operator(Power_10);
            }
            else
            {
                Instance_Pointer->Set_Secondary_Operator(Power_2);
            }
            break;
        case Instruction('L', 'n'): // Ln : Ln / LogY
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 0)
            {
                Instance_Pointer->Set_Secondary_Operator(Natural_Logarithm);
            }
            else
            {
                Instance_Pointer->Set_Primary_Operator(Logarithm);
            }
            break;

        case Instruction('L', '1'): // L1 : log10 / log2
            if (bitRead(Instance_Pointer->Keys_Mode, Second) == 0)
            {
                Instance_Pointer->Set_Secondary_Operator(Decimal_Logarithm);
            }
            else
            {
                Instance_Pointer->Set_Secondary_Operator(Binary_Logarithm);
            }
            break;

        case Instruction('S', 'i'): // Si:
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
        case Instruction('C', 'o'): // Co:
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
        case Instruction('T', 'a'): // Ta
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

        case Instruction('S', 'e'): // Se :
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

        case Instruction('C', 's'): // Cs :
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

        case Instruction('C', 't'): // Ct:
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
    }
}

void Calculator_Class::Add_Number(char const &Number_To_Add)
{
    if (State > 1) // -- If there's a result computed
    {
        // -- Clear calculation
        memset(Numbers[0], '\0', sizeof(Numbers[0]));
        memset(Numbers[1], '\0', sizeof(Numbers[1]));
        Secondary_Operator[1] = None;
        Secondary_Operator[0] = None;

        Decimal_Point[1] = 0;
        Current_Position[1] = 1;
        Exponent[1] = 0;
        // -- Copy result data

        if (Numbers[2][0] == '-')
        {
            memcpy(Numbers[0], Numbers[2], sizeof(Numbers[0]));
        }
        else
        {
            memcpy(Numbers[0] + 1, Numbers[2], sizeof(Numbers[0]));
            Numbers[0][0] = '0';
        }

        Decimal_Point[0] = Decimal_Point[2];
        Exponent[0] = Exponent[2];
        Current_Position[0] = Current_Position[2];
        // -- Clear result
        memset(Numbers[2], '\0', sizeof(Numbers[2]));
        Exponent[2] = 0;
        Decimal_Point[2] = 0;
        Current_Position[2] = 0;

        Primary_Operator = None;
        State = 0;
    }

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
        Xila.Mathematics.Float_To_String(Xila.System.Random(), -1, 0, Numbers[State]);
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
        switch (Numbers[State][0])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '-':

            break;
        default:
            memset(Numbers[State], '\0', sizeof(Numbers[State]));
            Numbers[State][0] = '0';
            Current_Position[State] = 1;
            break;
        }
        Numbers[State][Current_Position[State]++] = Number_To_Add;
        break;
    }

    Send_Instruction('R', 'I');
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
    Send_Instruction('R', 'I');
}

void Calculator_Class::Set_Secondary_Operator(char const &Operator_To_Set)
{
    if (State > 1)
    {
        memset(Numbers[0], '\0', sizeof(Numbers[0]));
        memset(Numbers[1], '\0', sizeof(Numbers[1]));
        Secondary_Operator[1] = None;
        Secondary_Operator[0] = None;

        Decimal_Point[1] = 0;
        Current_Position[1] = 1;
        Exponent[1] = 0;

        if (Numbers[2][0] == '-')
        {
            memcpy(Numbers[0], Numbers[2], sizeof(Numbers[0]));
        }
        else
        {
            memcpy(Numbers[0] + 1, Numbers[2], sizeof(Numbers[0]));
            Numbers[0][0] = '0';
        }

        Decimal_Point[0] = Decimal_Point[2];
        Exponent[0] = Exponent[2];
        Current_Position[0] = Current_Position[2];
        // -- Clear result
        memset(Numbers[2], '\0', sizeof(Numbers[2]));
        Exponent[2] = 0;
        Decimal_Point[2] = 0;
        Current_Position[2] = 0;

        Primary_Operator = None;
        State = 0;
    }
    Secondary_Operator[State] = Operator_To_Set;
    Send_Instruction('R', 'I');
}

void Calculator_Class::Set_Primary_Operator(char const &Opertor_To_Set)
{
    if (State > 1)
    {
        // -- Clear calculation
        memset(Numbers[0], '\0', sizeof(Numbers[0]));
        memset(Numbers[1], '\0', sizeof(Numbers[1]));
        Secondary_Operator[1] = None;
        Secondary_Operator[0] = None;

        Decimal_Point[1] = 0;
        Current_Position[1] = 1;
        Exponent[1] = 0;
        // -- Copy result data

        if (Numbers[2][0] == '-')
        {
            memcpy(Numbers[0], Numbers[2], sizeof(Numbers[0]));
        }
        else
        {
            memcpy(Numbers[0] + 1, Numbers[2], sizeof(Numbers[0]));
            Numbers[0][0] = '0';
        }

        Decimal_Point[0] = Decimal_Point[2];
        Exponent[0] = Exponent[2];
        Current_Position[0] = Current_Position[2];
        // -- Clear result
        memset(Numbers[2], '\0', sizeof(Numbers[2]));
        Exponent[2] = 0;
        Decimal_Point[2] = 0;
        Current_Position[2] = 0;
    }
    Primary_Operator = Opertor_To_Set;
    State = 1;
    Send_Instruction('R', 'I');
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
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.String_To_Float(Numbers[Selected_Number]);
        break;
    }

    switch (Secondary_Operator[Selected_Number]) // Apply secondary operator
    {
    case Factorial:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Factorial(Temporary_Numbers[Selected_Number]);
        break;

    // Simple trigonometric function
    case Sine:
        Degree_To_Radian(Selected_Number);
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Sine(Temporary_Numbers[Selected_Number]);
        break;
    case Cosine:
        Degree_To_Radian(Selected_Number);
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Cosine(Temporary_Numbers[Selected_Number]);
        break;
    case Tangent:
        Degree_To_Radian(Selected_Number);
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Tangent(Temporary_Numbers[Selected_Number]);
        break;
    case Secant:
        Degree_To_Radian(Selected_Number);
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Secant(Temporary_Numbers[Selected_Number]);
        break;
    case Cosecant:
        Degree_To_Radian(Selected_Number);
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Cosecant(Temporary_Numbers[Selected_Number]);
        break;
    case Cotangent:
        Degree_To_Radian(Selected_Number);
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Cotangeant(Temporary_Numbers[Selected_Number]);
        break;

        // Arc trigonometric function

    case Arc_Sine:
        if (Temporary_Numbers[Selected_Number] < -1 || Temporary_Numbers[Selected_Number] > 1)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Arc_Sine(Temporary_Numbers[Selected_Number]);
        break;

    case Arc_Cosine:
        if (Temporary_Numbers[Selected_Number] < -1 || Temporary_Numbers[Selected_Number] > 1)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Arc_Cosine(Temporary_Numbers[Selected_Number]);
        break;

    case Arc_Tangent:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Arc_Tangent(Temporary_Numbers[Selected_Number]);
        break;

    case Arc_Secant:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Arc_Secant(Temporary_Numbers[Selected_Number]);
        break;
    case Arc_Cosecant:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Arc_Cosecant(Temporary_Numbers[Selected_Number]);
        break;
    case Arc_Cotangent:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Arc_Cotangent(Temporary_Numbers[Selected_Number]);
        break;
    // Hyperbolic trigonometric function
    case Hyperbolic_Sine:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Hyperbolic_Sine(Temporary_Numbers[Selected_Number]);
        break;
    case Hyperbolic_Cosine:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Hyperbolic_Cosine(Temporary_Numbers[Selected_Number]);
        break;
    case Hyperbolic_Tangent:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Hyperbolic_Tangent(Temporary_Numbers[Selected_Number]);
        break;
    case Hyperbolic_Secant:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Hyperbolic_Secant(Temporary_Numbers[Selected_Number]);
        break;
    case Hyperbolic_Cosecant:
        if (Temporary_Numbers[Selected_Number] == 0)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Hyperbolic_Cosecant(Temporary_Numbers[Selected_Number]);
        break;
    case Hyperbolic_Cotangent:
        if (Temporary_Numbers[Selected_Number] == 0)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Hyperbolic_Cotangent(Temporary_Numbers[Selected_Number]);
        break;

    // Arc Hyperbolic Function
    case Arc_Hyperbolic_Sine:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Arc_Hyperbolic_Sine(Temporary_Numbers[Selected_Number]);
        break;
    case Arc_Hyperbolic_Cosine:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Arc_Hyperbolic_Cosine(Temporary_Numbers[Selected_Number]);
        break;
    case Arc_Hyperbolic_Tangent:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Arc_Hyperbolic_Tangent(Temporary_Numbers[Selected_Number]);
        break;
    case Arc_Hyperbolic_Secant:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Arc_Hyperbolic_Secant(Temporary_Numbers[Selected_Number]);
        break;
    case Arc_Hyperbolic_Cosecant:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Arc_Hyperbolic_Cosecant(Temporary_Numbers[Selected_Number]);
        break;
    case Arc_Hyperbolic_Cotangent:
        if (Temporary_Numbers[Selected_Number] <= -1 || Temporary_Numbers[Selected_Number] >= 1)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Arc_Hyperbolic_Cotangent(Temporary_Numbers[Selected_Number]);
        break;

        //

    case Power_2:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Power(2, Temporary_Numbers[Selected_Number]);
        break;

    case Power_10:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Power(10, Temporary_Numbers[Selected_Number]);
        break;

        // Logarithm

    case Decimal_Logarithm:
        if (Temporary_Numbers[Selected_Number] <= 0)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Decimal_Logarithm(Temporary_Numbers[Selected_Number]);
        break;
    case Natural_Logarithm:
        if (Temporary_Numbers[Selected_Number] <= 0)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Natural_Logarithm(Temporary_Numbers[Selected_Number]);
        break;
    case Binary_Logarithm:
        if (Temporary_Numbers[Selected_Number] <= 0)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Binary_Logarithm(Temporary_Numbers[Selected_Number]);
        break;
    case Squared:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Square(Temporary_Numbers[Selected_Number]);
        break;
    case Cube:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Cube(Temporary_Numbers[Selected_Number]);
        break;
    case Square_Root:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Square_Root(Temporary_Numbers[Selected_Number]);
        break;
    case Cubic_Root:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Cubic_Root(Temporary_Numbers[Selected_Number]);
        break;
    case Inverse:
        if (Temporary_Numbers[Selected_Number] == 0)
        {
            Error();
            return;
        }
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Inverse(Temporary_Numbers[Selected_Number]);
        break;
    case Absolute:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Absolute(Temporary_Numbers[Selected_Number]);
        break;
    case Exponential:
        Temporary_Numbers[Selected_Number] = Xila.Mathematics.Exponential(Temporary_Numbers[Selected_Number]);
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
        Temporary_Numbers[2] = Xila.Mathematics.Modulo(Temporary_Numbers[0], Temporary_Numbers[1]);
        break;
    case Power:
        Temporary_Numbers[2] = Xila.Mathematics.Power(Temporary_Numbers[0], Temporary_Numbers[1]);
        break;
    case Root:
        Temporary_Numbers[2] = Xila.Mathematics.Root(Temporary_Numbers[0], Temporary_Numbers[1]);
        break;
    case Logarithm:
        Temporary_Numbers[2] = Xila.Mathematics.Logarithm(Temporary_Numbers[0], Temporary_Numbers[1]);
        break;
    default: // No primary operator
        Temporary_Numbers[2] = Temporary_Numbers[0];
        break;
    }

    Xila.Mathematics.Float_To_String(Temporary_Numbers[2], -1, POINT_PRECISION, Numbers[2]);

    // --
    State = 2;
    Send_Instruction('R', 'I');
}

void Calculator_Class::Error()
{
    Xila.Dialog.Event(F("Cannot calculate, please check input calculation."), Xila.Error);
    Clear();
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
            Primary_Operator = None;
            State = 0;
        }
        else
        {
            memset(Numbers[1], 0, sizeof(Numbers[1]));
            Current_Position[1] = 1;
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

    memset(Numbers, '\0', sizeof(Numbers));

    Secondary_Operator[0] = None;
    Secondary_Operator[1] = None;

    Exponent[0] = None;
    Exponent[1] = None;
    Exponent[2] = None;

    Decimal_Point[0] = 0;
    Decimal_Point[1] = 0;
    Decimal_Point[2] = 0;

    Current_Position[0] = 1;
    Current_Position[1] = 1;
    Current_Position[2] = 0;

    Primary_Operator = None;
}

void Calculator_Class::Refresh_Interface()
{
    // -- Clear the entire char array
    memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));

    // -- Display 1st number and it's secondary operator + display primary operator
    if (State >= 0)
    {
        Ending_Character[0] = '\0';
        Ending_Character[1] = '\0';
        switch (Secondary_Operator[0])
        {
        case Sine:
            strcpy(Temporary_Char_Array, "Sin(");

            Ending_Character[0] = ')';
            break;
        case Cosine:
            strcpy(Temporary_Char_Array, "Cos(");

            Ending_Character[0] = ')';
            break;
        case Tangent:
            strcpy(Temporary_Char_Array, "Tan(");

            Ending_Character[0] = ')';
            break;
        case Secant:
            strcpy(Temporary_Char_Array, "Sec(");
            Ending_Character[0] = ')';
            break;
        case Cosecant:
            strcpy(Temporary_Char_Array, "Csc(");
            Ending_Character[0] = ')';
            break;
        case Cotangent:
            strcpy(Temporary_Char_Array, "Cot(");
            Ending_Character[0] = ')';
            break;
        case Arc_Sine:
            strcpy(Temporary_Char_Array, "ASin(");
            Ending_Character[0] = ')';
            break;
        case Arc_Cosine:
            strcpy(Temporary_Char_Array, "ACos(");
            Ending_Character[0] = ')';
            break;
        case Arc_Tangent:
            strcpy(Temporary_Char_Array, "ATan(");
            Ending_Character[0] = ')';
            break;
        case Arc_Secant:
            strcpy(Temporary_Char_Array, "ASec(");
            Ending_Character[0] = ')';
            break;
        case Arc_Cosecant:
            strcpy(Temporary_Char_Array, "ACsc(");

            Ending_Character[0] = ')';
            break;
        case Arc_Cotangent:
            strcpy(Temporary_Char_Array, "ACot(");

            Ending_Character[0] = ')';
            break;
        case Hyperbolic_Sine:
            strcpy(Temporary_Char_Array, "SinH(");

            Ending_Character[0] = ')';
            break;
        case Hyperbolic_Cosine:
            strcpy(Temporary_Char_Array, "CosH(");

            Ending_Character[0] = ')';
            break;
        case Hyperbolic_Tangent:
            strcpy(Temporary_Char_Array, "TanH(");

            Ending_Character[0] = ')';
            break;
        case Hyperbolic_Secant:
            strcpy(Temporary_Char_Array, "SecH(");

            Ending_Character[0] = ')';
            break;
        case Hyperbolic_Cosecant:
            strcpy(Temporary_Char_Array, "CscH(");

            Ending_Character[0] = ')';
            break;
        case Hyperbolic_Cotangent:
            strcpy(Temporary_Char_Array, "CotH(");

            Ending_Character[0] = ')';
            break;
        case Arc_Hyperbolic_Sine:
            strcpy(Temporary_Char_Array, "ASinH(");

            Ending_Character[0] = ')';
            break;
        case Arc_Hyperbolic_Cosine:
            strcpy(Temporary_Char_Array, "ACosH(");

            Ending_Character[0] = ')';
            break;
        case Arc_Hyperbolic_Tangent:
            strcpy(Temporary_Char_Array, "ATanH(");

            Ending_Character[0] = ')';
            break;
        case Arc_Hyperbolic_Secant:
            strcpy(Temporary_Char_Array, "ASecH(");

            Ending_Character[0] = ')';
            break;
        case Arc_Hyperbolic_Cotangent:
            strcpy(Temporary_Char_Array, "ACotH(");

            Ending_Character[0] = ')';
            break;
        case Arc_Hyperbolic_Cosecant:
            strcpy(Temporary_Char_Array, "ACscH(");
            Ending_Character[0] = ')';
            break;
        case Factorial:
            Ending_Character[0] = '!';
            break;
        case Natural_Logarithm:
            strcpy(Temporary_Char_Array, "Ln(");
            Ending_Character[0] = ')';
            break;
        case Binary_Logarithm:
            strcpy(Temporary_Char_Array, "Log2(");
            Ending_Character[0] = ')';
            break;
        case Decimal_Logarithm:
            strcpy(Temporary_Char_Array, "Log10(");
            Ending_Character[0] = ')';
            break;
        case Squared:
            Ending_Character[0] = 0xB2;
            break;
        case Cube:
            Ending_Character[0] = 0xB3;
            break;
        case Square_Root:
            strcpy(Temporary_Char_Array, "Sqrt(");

            Ending_Character[0] = ')';
            break;
        case Cubic_Root:
            strcpy(Temporary_Char_Array, "Cbrt(");

            Ending_Character[0] = ')';
            break;
        case Exponential:
            strcpy(Temporary_Char_Array, "Exp(");

            Ending_Character[0] = ')';
            break;
        case Power_2:
            strcpy(Temporary_Char_Array, "2^(");
            Ending_Character[0] = ')';
            break;
        case Power_10:
            strcpy(Temporary_Char_Array, "10^(");
            Ending_Character[0] = ')';
            break;
        case Inverse:
            strcpy(Temporary_Char_Array, "1/(");
            ;
            Ending_Character[0] = ')';
            break;

        case Absolute:
            strcpy(Temporary_Char_Array, "|");
            Ending_Character[0] = '|';
            break;
        case None:

            break;
        default:

            break;
        }
        switch (Numbers[0][0])
        {
        case Pi:
            strlcat(Temporary_Char_Array, "Pi", sizeof(Temporary_Char_Array));
            break;
        case Neper_Constant:
            strlcat(Temporary_Char_Array, "e", sizeof(Temporary_Char_Array));
            break;
        case '-':
            strlcat(Temporary_Char_Array, Numbers[0], sizeof(Temporary_Char_Array));
            break;
        default:
            strlcat(Temporary_Char_Array, Numbers[0] + 1, sizeof(Temporary_Char_Array));
            break;
        }

        strlcat(Temporary_Char_Array, Ending_Character, sizeof(Temporary_Char_Array));

        if (Primary_Operator != None)
        {
            strcpy(Ending_Character, "   ");
            Ending_Character[1] = Primary_Operator;
            strlcat(Temporary_Char_Array, Ending_Character, sizeof(Temporary_Char_Array));
        }
        if (State == 0)
        {
            Xila.Display.Set_Text(F("CALCULATIO_TXT"), Temporary_Char_Array);
            Xila.Display.Set_Text(F("RESULT_TXT"), F(""));
        }
    }

    if (State > 0)
    {
        Ending_Character[0] = 0;
        Ending_Character[1] = '\0';
        switch (Secondary_Operator[1])
        {
        case Sine:
            strlcat(Temporary_Char_Array, "Sin(", sizeof(Temporary_Char_Array));

            Ending_Character[0] = ')';
            break;
        case Cosine:
            strlcat(Temporary_Char_Array, "Cos(", sizeof(Temporary_Char_Array));

            Ending_Character[0] = ')';
            break;
        case Tangent:
            strlcat(Temporary_Char_Array, "Tan(", sizeof(Temporary_Char_Array));

            Ending_Character[0] = ')';
            break;
        case Secant:
            strlcat(Temporary_Char_Array, "Sec(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Cosecant:
            strlcat(Temporary_Char_Array, "Csc(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Cotangent:
            strlcat(Temporary_Char_Array, "Cot(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Arc_Sine:
            strlcat(Temporary_Char_Array, "ASin(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Arc_Cosine:
            strlcat(Temporary_Char_Array, "ACos(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Arc_Tangent:
            strlcat(Temporary_Char_Array, "ATan(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Arc_Secant:
            strlcat(Temporary_Char_Array, "ASec(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Arc_Cosecant:
            strlcat(Temporary_Char_Array, "ACsc(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Arc_Cotangent:
            strlcat(Temporary_Char_Array, "ACot(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Hyperbolic_Sine:
            strlcat(Temporary_Char_Array, "SinH(", sizeof(Temporary_Char_Array));

            Ending_Character[0] = ')';
            break;
        case Hyperbolic_Cosine:
            strlcat(Temporary_Char_Array, "CosH(", sizeof(Temporary_Char_Array));

            Ending_Character[0] = ')';
            break;
        case Hyperbolic_Tangent:
            strlcat(Temporary_Char_Array, "TanH(", sizeof(Temporary_Char_Array));

            Ending_Character[0] = ')';
            break;
        case Hyperbolic_Secant:
            strlcat(Temporary_Char_Array, "SecH(", sizeof(Temporary_Char_Array));

            Ending_Character[0] = ')';
            break;
        case Hyperbolic_Cosecant:
            strlcat(Temporary_Char_Array, "CscH(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Hyperbolic_Cotangent:
            strlcat(Temporary_Char_Array, "CotH(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Arc_Hyperbolic_Sine:
            strlcat(Temporary_Char_Array, "ASinH(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Arc_Hyperbolic_Cosine:
            strlcat(Temporary_Char_Array, "ACosH(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Arc_Hyperbolic_Tangent:
            strlcat(Temporary_Char_Array, "ATanH(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Arc_Hyperbolic_Secant:
            strlcat(Temporary_Char_Array, "ASecH(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Arc_Hyperbolic_Cotangent:
            strlcat(Temporary_Char_Array, "ACotH(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Arc_Hyperbolic_Cosecant:
            strlcat(Temporary_Char_Array, "ACscH(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Factorial:
            Ending_Character[0] = '!';
            break;

        case Decimal_Logarithm:
            strlcat(Temporary_Char_Array, "Log10(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Natural_Logarithm:
            strlcat(Temporary_Char_Array, "Ln(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Binary_Logarithm:
            strlcat(Temporary_Char_Array, "Log2(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Squared:
            Ending_Character[0] = 0xB2;
            break;
        case Cube:
            Ending_Character[0] = 0xB3;
            break;
        case Square_Root:
            strlcat(Temporary_Char_Array, "Sqrt(", sizeof(Temporary_Char_Array));

            Ending_Character[0] = ')';
            break;
        case Cubic_Root:
            strlcat(Temporary_Char_Array, "Cbrt(", sizeof(Temporary_Char_Array));

            Ending_Character[0] = ')';
            break;
        case Exponential:
            strlcat(Temporary_Char_Array, "Exp(", sizeof(Temporary_Char_Array));

            Ending_Character[0] = ')';
            break;
        case Power_2:
            strlcat(Temporary_Char_Array, "2^(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Power_10:
            strlcat(Temporary_Char_Array, "10^(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;
        case Inverse:
            strlcat(Temporary_Char_Array, "1/(", sizeof(Temporary_Char_Array));
            Ending_Character[0] = ')';
            break;

        case Absolute:
            strlcat(Temporary_Char_Array, "|", sizeof(Temporary_Char_Array));
            Ending_Character[0] = '|';
            break;
        default:
            break;
        }
        switch (Numbers[1][0])
        {
        case Pi:
            strlcat(Temporary_Char_Array, "Pi", sizeof(Temporary_Char_Array));
            break;
        case Neper_Constant:
            strlcat(Temporary_Char_Array, "e", sizeof(Temporary_Char_Array));
            break;
        case '-':
            strlcat(Temporary_Char_Array, Numbers[1], sizeof(Temporary_Char_Array));
            break;
        default:
            strlcat(Temporary_Char_Array, Numbers[1] + 1, sizeof(Temporary_Char_Array));
            break;
        }

        strlcat(Temporary_Char_Array, Ending_Character, sizeof(Temporary_Char_Array));

        if (State == 1)
        {
            Xila.Display.Set_Text(F("CALCULATIO_TXT"), Temporary_Char_Array);
            Xila.Display.Set_Text(F("RESULT_TXT"), "");
        }
    }

    if (State > 1)
    {
        Xila.Display.Set_Text(F("CALCULATIO_TXT"), Temporary_Char_Array);
        Xila.Display.Set_Text(F("RESULT_TXT"), Numbers[2]);
    }
}
