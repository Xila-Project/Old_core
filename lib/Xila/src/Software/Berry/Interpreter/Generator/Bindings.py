from pygccxml import utils
from pygccxml import declarations as Declarations
from pygccxml import parser as Parser
import os
from Basics import *
import copy
import re
import uuid
import Exclusion

Binding_Function_Table = []

# Function that convert function arguments to 
def Generate_Binding_Function(Declaration, Module_Name, Is_Module):
    print("Binding : ", Declaration)

    # - Remove variadic functions
    if Declaration.has_ellipsis:    
        return ""

    # - Remove excluded functions
    if Exclusion.Is_Function_Excluded(Declaration):   
        return ""

    # - Remove copy constructors
    if Is_Constructor(Declaration):
        if Declaration.is_artificial:
            return ""



    # - Declarations
    S = ""
    StringD = ""
    R = ""
    ReturnD = ""
    Return_Conversion = ""

    Pre_Additional_Content = ""
    Post_Additional_Content = ""
    Passed_Arguments = ""
    Optional_Already_Defined = False
    Next_May_Be_Buffer_Size = False

    # - Arguments

    Arguments = Get_Function_Arguments(Declaration)
    Length = len(Arguments)

    if not(Is_Module):
        if Is_Operator(Declaration):
            Berry_Function_Name = "Berry_" + Get_Name(Declaration.parent) + "_Operator_" + str(uuid.uuid4()).replace("-", "_").upper()
            Binding = "bool " + Berry_Function_Name + "(" + Declaration.parent.decl_string.replace("::Xila_Namespace", "Xila_Namespace") + "* I, " + Declaration.parent.decl_string.replace("::Xila_Namespace", "Xila_Namespace") + "* A_0)\n"
            Binding += "{\nreturn *I " + Declaration.symbol + " *A_0;\n}\n"
            Binding += "BE_FUNC_CTYPE_DECLARE(" + Berry_Function_Name + ", \"b\", \"..\")\n\n"
            Binding_Function_Table.append([str(Declaration.symbol), Berry_Function_Name])
            return Binding
        if Is_Function(Declaration) or Is_Destructor(Declaration):
            S += Declaration.parent.decl_string.replace("::Xila_Namespace", "Xila_Namespace") + "* I, "
            StringD += "."

    for i, Raw_Argument in enumerate(Arguments): 
        # Check if it's an optional argument
        if Is_Optional(Raw_Argument) and not(Optional_Already_Defined):
            StringD += "["
            Optional_Already_Defined = True

        Argument = Remove_Alias(Raw_Argument.decl_type)

        if not(Is_Integral_Type(Argument)):
            Next_May_Be_Buffer_Size = False

        if Is_Pointer_Type(Argument) or Is_Reference_Type(Argument):
            Base_Type = Get_Base_Type(Argument)
            #print("Pointer : ", Raw_Argument)
            if Is_Integral_Type(Base_Type):
                if "const" in str(Raw_Argument):     # Not ideal, but works (strange behavior of pygccxml)
                    # Add support for byte buffer

                    S += "const " + str(Base_Type) + "* A_" + str(i)
                    StringD += "s"
                    Passed_Arguments += "A_" + str(i)
                else:
                    # Override return type
                    S = "bvm* V, " + S
                    StringD = "@" + StringD
                    R += "const " + str(Base_Type) + "*"
                    ReturnD += "s"
                    Pre_Additional_Content += str(Base_Type) + "* S_" + str(i) + " = (" + str(Base_Type) + "*)Berry_Class::Get_Instance(V)->Buffer;\n"
                    Post_Additional_Content += "return S_" + str(i) + ";\n"
                    Passed_Arguments += "S_" + str(i)
                    Next_May_Be_Buffer_Size = True
            elif ("String_Type" in str(Base_Type)) or ("String_Class" in str(Base_Type)):
                S = "bvm* V, " + S
                StringD = "@" + StringD
                R += "const char*"
                ReturnD += "s"
                Pre_Additional_Content += "String_Type S_" + str(i) + ";\nS_" + str(i) + ".Set_Buffer((char*)Berry_Class::Get_Instance(V)->Buffer, sizeof(Berry_Class::Buffer));\n"
                Post_Additional_Content += "return S_" + str(i) + ";\n"
                Passed_Arguments += "S_" + str(i)
           
            elif Is_Function_Pointer(Argument):
                print("Function pointer in : ", str(Declaration))
                S += str(Argument).replace("(*", "(* " + " A_" + str(i))
                StringD += "^^"
                Passed_Arguments += "A_" + str(i)

            elif Is_Class(Base_Type.declaration):
                S += Base_Type.declaration.decl_string + "* A_" + str(i)
                StringD += "."#"(" + str(Base_Type) + ")"
                if Is_Reference_Type(Argument):
                    Passed_Arguments += "*"
                Passed_Arguments += "A_" + str(i)
                
        else:

            if Is_Boolean_Type(Argument):
                S += "bool A_" + str(i)
                StringD += "b"
                Passed_Arguments += "A_" + str(i) + ", "
            elif Is_Integral_Type(Argument):
                print("Integral : ", str(Argument.byte_size))
                if Get_Size(Argument) > 4:
                    S += str(Get_Base_Type(Argument)) + "*A_" + str(i)
                    StringD += "."
                    Passed_Arguments += "*A_" + str(i)
                elif Next_May_Be_Buffer_Size:
                    S += "int A_" + str(i)
                    StringD += "i"
                    Passed_Arguments += "(A_" + str(i) + " > sizeof(Berry_Class::Buffer)) ? sizeof(Berry_Class::Buffer)" + " : A_" + str(i)
                    Next_May_Be_Buffer_Size = False            
                    Optional_Already_Defined = False
                else:
                    Base_Type = Get_Base_Type(Argument)
                    S += "int A_" + str(i)
                    StringD += "i"
                    Passed_Arguments += "(" + str(Base_Type) + ")A_" + str(i) # Conversion from int to desired type
            elif Is_Float_Type(Argument):
                if Get_Size(Argument) > 4:
                    S += str(Get_Base_Type(Argument)) + "* A_" + str(i)
                    StringD += "."
                    Passed_Arguments += "*A_" + str(i)
                else:
                    Base_Type = Get_Base_Type(Argument)
                    S += "float A_" + str(i)
                    StringD += "f"
                    Passed_Arguments += "(" + str(Base_Type) + ")A_" + str(i)
            elif Is_Declarated_Type(Argument):
                if Is_Enumeration_Type(Argument.declaration):
                    S += "int A_" + str(i)
                    StringD += "i"
                    Passed_Arguments += "(" + Get_Name(Argument.declaration) + ")A_" + str(i)
                elif Is_Class(Argument.declaration):
                    S += Get_Name(Argument.declaration) + "* A_" + str(i)
                    StringD += "."
                    Passed_Arguments += "*A_" + str(i)
                else:
                    print("Unhandled type : ", Argument, " type : ", Argument.declaration)
            else:
                print("Unhandled type : ", Argument, " type : ", Argument.declaration)
                S += "void* A_" + str(i)
                StringD += "."
                Passed_Arguments += "A_" + str(i)


        # - - Default arguments
        if Is_Optional(Raw_Argument) and not(S.endswith(", ")):
            S += " = " 
            if (Is_Declarated_Type(Argument) and Is_Enumeration_Type(Argument.declaration)):
                S += "(int)"    # Add explicit cast for enum (enum class doesn't allow implicit cast)
            S += str(Raw_Argument.default_value).replace("::Xila_Namespace", "Xila_Namespace")

        # - - Add comma separator to arguments and passed arguments
        if not(S.endswith(", ")):
            S += ", "
        if not(Passed_Arguments.endswith(", ")):
            Passed_Arguments += ", "


   
    # - Return
    if Is_Constructor(Declaration):
        R += "void *"
        ReturnD += "+_p"
    elif Is_Destructor(Declaration):
        R += "void"
        ReturnD += ""
    elif (R == "") and (ReturnD == ""):
        Return_Type = Remove_Alias(Get_Return_Type(Declaration))
        if Is_Pointer_Type(Return_Type) or Is_Reference_Type(Return_Type):
            Base_Type = Get_Base_Type(Return_Type)
            if (str(Base_Type) == "char") or (str(Base_Type) == "unsigned char"):
                R = "const char*"
                ReturnD = "s"
           # if Is_Declarated_Type(Base_Type):
           #     if Is_Class(Base_Type.declaration):
           #         R = "const void*"
           #         ReturnD =  Base_Type.declaration.decl_string.replace("::Xila_Namespace::", "").replace("_Types", "").replace("_Class", "_Type").replace("::", ".")
           #     else:
           #         R = "const void*"
           #         ReturnD = "c"
            else:
                R = "const void*"
                ReturnD = "c"
            
            if Is_Reference_Type(Return_Type):
                Return_Conversion = "&"
        else:
            if (Is_Boolean_Type(Return_Type)):
                R = "bool"
                ReturnD = "b"
            elif (Is_Integral_Type(Return_Type)):
                if Get_Size(Return_Type) > 4:
                    S = "bvm* V, " + S
                    StringD = "@" + StringD
                    Pre_Additional_Content += "int64_t* R = (int64_t*) be_malloc(V, sizeof(int64_t));\n *R = "
                    Post_Additional_Content += "return R;\n"
                    R = "void *"
                    ReturnD = "Long_Integer_Type"
                else:
                    R = "int"
                    ReturnD = "i"
                    Return_Conversion = "(int)"
            elif Is_Float_Type(Return_Type):
                if Get_Size(Return_Type) > 4:
                    S = "bvm* V, " + S
                    StringD = "@" + StringD
                    Pre_Additional_Content += "double* R = (double*) be_malloc(V, sizeof(double));\n *R = "
                    Post_Additional_Content += "return R;\n"
                    R = "void *"
                    ReturnD = "Long_Real_Type"
                else:
                    R = "float"
                    ReturnD = "f"
                    Return_Conversion = "(float)"
            
            elif Is_Void_Type(Return_Type):
                R = "void"
                ReturnD = ""
            elif Is_Declarated_Type(Return_Type):
                if Is_Enumeration_Type(Return_Type.declaration):
                    R = "int"
                    ReturnD = "i"
                    Return_Conversion = "(int)"
                elif Is_Class(Return_Type.declaration):
                    Return_Type_Declaration = Return_Type.declaration.decl_string.replace("::Xila_Namespace::", "Xila_Namespace::")
                    S = "bvm* V, " + S
                    StringD = "@" + StringD
                    Pre_Additional_Content += Return_Type_Declaration + "* R = (" + Return_Type_Declaration + "*) be_malloc(V, sizeof(" + Return_Type_Declaration + "));\n *R = "
                    ReturnD = Return_Type.declaration.decl_string.replace("_Types", "").replace("_Class", "_Type").replace("::Xila_Namespace::", "").replace("::", ".")
                    Post_Additional_Content += "return R;\n"
                    R = "void *"
                else:
                    print("Unhandled return type : ", Return_Type, " type : ", type(Return_Type))
            else:
                print("Unhandled return type : ", Return_Type, " type : ", type(Return_Type))


    while S.endswith(" ") or S.endswith(","):
        S = S[:-1]

    while Passed_Arguments.endswith(",") or Passed_Arguments.endswith(" "):
        Passed_Arguments = Passed_Arguments[:-1]


    # - Function name  
    Function_Name = Get_Name(Declaration)

    
    Berry_Function_Name = "Berry_" + Get_Name(Declaration.parent) + "_"

    if Is_Constructor(Declaration):
        if not(StringD.startswith("@")):
            StringD = "@" + StringD
            S = "bvm* V, " + S
            if S.endswith(", "):
                S = S[:-2]
        Pre_Additional_Content += "void* Pointer = be_malloc(V, sizeof(" + Module_Name + "_Types::" + Get_Name(Declaration.parent) + "));\n"
        Berry_Function_Name += "Initialize"
    elif Is_Destructor(Declaration):
        if not(StringD.startswith("@")):
            StringD = "@" + StringD
            S = "bvm* V, " + S
            if S.endswith(", "):
                S = S[:-2]
        Berry_Function_Name += "Deinitialize"
    else:
        Berry_Function_Name += Function_Name
    
    Berry_Function_Name += "_" + str(uuid.uuid4()).replace("-", "_").upper() # Add an unique id to allow overloading


    # - Function signature
    Berry_Function_Signature = R + " " + Berry_Function_Name + "(" + S + ")\n"

    # - Function body
    Berry_Function_Body = "{\n" + Pre_Additional_Content 

    if Post_Additional_Content == "" and not(Is_Destructor(Declaration)):
        Berry_Function_Body += "return " + Return_Conversion

    if Is_Constructor(Declaration):
        Berry_Function_Body += "new (Pointer) " + Module_Name + "_Types::" + Get_Name(Declaration.parent);
    elif Is_Destructor(Declaration):
        Berry_Function_Body += "if (!I) { return; }\n"
        Berry_Function_Body += "I->~" + Get_Name(Declaration.parent) + "();\n"
        Berry_Function_Body += "be_free(V, I, sizeof(" + Module_Name + "_Types::" + Get_Name(Declaration.parent) + "));\n}\n"
    elif Is_Function(Declaration):
        if Is_Module:   # Function but not module
            Berry_Function_Body += Module_Name + "." + Function_Name
        else:
            Berry_Function_Body += "I->" + Function_Name

    if not(Is_Destructor(Declaration)):
        Berry_Function_Body += "(" + Passed_Arguments + "); \n" + Post_Additional_Content + "}\n"

    # - Function declaration
    Berry_Function_Declaration = "BE_FUNC_CTYPE_DECLARE(" + Berry_Function_Name + ", \"" + ReturnD + "\", \"" + StringD + "\");\n" 

    if Is_Constructor(Declaration):
        Binding_Function_Table.append(["init", Berry_Function_Name])
    elif Is_Destructor(Declaration):
        Binding_Function_Table.append(["deinit", Berry_Function_Name])
    elif Is_Function(Declaration):
        Binding_Function_Table.append([Function_Name, Berry_Function_Name])


    return Berry_Function_Signature + Berry_Function_Body + Berry_Function_Declaration + "\n"

def Clear_Binding_Function_Table():
    global Binding_Function_Table
    Binding_Function_Table = []

def Add_Custom_Binding_Function(Name, Berry_Name):
    global Binding_Function_Table
    Binding_Function_Table.append([Name, Berry_Name])

def Get_Class_Binding_Declaration(Class, Module, Namespace):

    if not(Is_Class(Class)):
        return ""

    Declaration = ""

    if Get_Name(Namespace) == "Graphics_Types":
        try:
            Declaration += "BE_EXPORT_VARIABLE const bclass Berry_" + Get_Name(Class.bases[0].related_class).replace("_Class", "_Type") + ";\n"
        except:
            pass

    Declaration += "/* @const_object_info_begin\n"

    if Module:
        Declaration += "module " + Get_Name(Class).replace("_Class", "") + " (scope:global)"
    else:
        Declaration += "class Berry_" + Get_Name(Class).replace("_Class", "_Type") + "(scope:global, name:" + Get_Name(Class).replace("_Class", "_Type")

        if Get_Name(Namespace) == "Graphics_Types":
            try:
                Declaration += ", super: Berry_" + Get_Name(Class.bases[0].related_class).replace("_Class", "_Type")
            except:
                pass

        Declaration += ")"
    
    Declaration += "\n{\n"

    if not(Module):
        Declaration += "\t_p, var\n" # Instance pointer
    
    for Binding in Binding_Function_Table:
        Declaration += "\t" + Binding[0] + ", ctype_func(" + Binding[1] + ")\n"

    Declaration += "\n"

    if Module:
        try:
            for Class in Namespace.classes(recursive=False):
                if not(Exclusion.Is_Class_Excluded(Class)):
                    Name = Get_Name(Class).replace("_Class", "_Type")
                    Declaration += "\t" + Name + ", class(Berry_" + Name + ")\n\n"
        except:
            pass


        try:
            for Type in Namespace.enumerations():
                Values = Type.get_name2value_dict()
                for Key, Value in Values.items():
                    Declaration += "\t" + Get_Name(Type).replace("_Type", "")
                    if Get_Name(Type) != "":
                        Declaration += "_"
                    Declaration += Key + ", int(" + str(Value) + ")\n"
                Declaration += "\n"
        except:
            pass


    Declaration  += "}\n@const_object_info_end */\n"


    return Declaration