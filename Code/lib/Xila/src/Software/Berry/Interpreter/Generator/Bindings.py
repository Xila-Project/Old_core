from pygccxml import utils
from pygccxml import declarations as Declarations
from pygccxml import parser as Parser
import os
from Basics import *
import copy
import re
import uuid

Binding_Function_Table = []

# Function that convert function arguments to 
def Generate_Binding_Function(Declaration, Module_Name, Is_Module):
    print("Declaration : ", Get_Name(Declaration))
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
        if Is_Function(Declaration) or Is_Destructor(Declaration):
            S += Module_Name + "_Types::" + Get_Name(Declaration.parent) + "* I, "
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
            if "const" in str(Raw_Argument):    # Not ideal, but works (strange behavior of pygccxml)
                if (str(Base_Type) == "char") or (str(Base_Type) == "unsigned char"):
                    S += "const " + str(Base_Type) + "* A_" + str(i)
                    StringD += "s"
                    Passed_Arguments += "A_" + str(i)
                elif Is_Class(Base_Type.declaration):
                    S += Get_Name(Base_Type.declaration) + "* A_" + str(i)
                    StringD += "(" + str(Base_Type) + ")"
                    if Is_Reference_Type(Argument):
                        Passed_Arguments += "*"
                    Passed_Arguments += "A_" + str(i)
                    print("Ptr Class : ", Base_Type, " type : ", type(Base_Type))
            else:
                if (str(Base_Type) == "char") or (str(Base_Type) == "unsigned char"):
                    # Override return type
                    R += "const " + str(Base_Type) + "*"
                    ReturnD += "s"
                    Pre_Additional_Content += str(Base_Type) + " S_" + str(i) + "[256] = {0};\n"
                    Post_Additional_Content += "return S_" + str(i) + ";\n"
                    Passed_Arguments += "S_" + str(i)
                    Next_May_Be_Buffer_Size = True
                elif Is_Class(Base_Type.declaration):
                    S += Get_Name(Base_Type.declaration) + "* A_" + str(i)
                    StringD += "(" + str(Base_Type) + ")"
                    if Is_Reference_Type(Argument):
                        Passed_Arguments += "*"
                    Passed_Arguments += "A_" + str(i)
                    print("Ptr Class : ", Base_Type, " type : ", type(Base_Type))
                
        else:
            if Is_Boolean_Type(Argument):
                S += "bool A_" + str(i)
                StringD += "b"
                Passed_Arguments += "A_" + str(i) + ", "
            elif Is_Integral_Type(Argument):
                if Next_May_Be_Buffer_Size:
                    S += "int A_" + str(i) + " = 0"
                    StringD += "[i"
                    Passed_Arguments += "(A_" + str(i) + " == 0) ? sizeof(S_" + str(i - 1) + ")" + " : A_" + str(i)
                    Next_May_Be_Buffer_Size = False            
                    Optional_Already_Defined = True
                    
                else:
                    Base_Type = Get_Base_Type(Argument)
                    S += "int A_" + str(i)
                    StringD += "i"
                    Passed_Arguments += "(" + str(Base_Type) + ")A_" + str(i) # Conversion from int to desired type
            elif Is_Float_Type(Argument):
                Base_Type = Get_Base_Type(Argument)
                S += "float A_" + str(i)
                StringD += "f"
                Passed_Arguments += "(" + str(Base_Type) + ")A_" + str(i)
            elif Is_Class(Argument):
                S += Get_Name(Argument.base_type) + "* A_" + str(i)
                StringD += "."
            elif Is_Declarated_Type(Argument):
                if Is_Enumeration_Type(Argument.declaration):
                    S += "int A_" + str(i)
                    StringD += "i"
                    Passed_Arguments += "(" + Get_Name(Argument.declaration) + ")A_" + str(i)
                else:
                    print("Unhandled type : ", Argument, " type : ", Argument.declaration)
            else:
                print("Unhandled type : ", Argument, " type : ", Argument.declaration)
                S += "void* A_" + str(i)
                StringD += "."
                Passed_Arguments += "A_" + str(i)

        if Is_Optional(Raw_Argument):
            S += " = " + str(Raw_Argument.default_value)

        if not(S.endswith(", ")):
            S += ", "

        if not(Passed_Arguments.endswith(", ")):
            Passed_Arguments += ", "


    if S.endswith(", "):
        S = S[:-2]


    if Passed_Arguments.endswith(", "):
        Passed_Arguments = Passed_Arguments[:-2]

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
            else:
                R = "void*"
                ReturnD = "p"
        else:
            if (Is_Boolean_Type(Return_Type)):
                R = "bool"
                ReturnD = "b"
            elif (Is_Integral_Type(Return_Type)):
                R = "int"
                ReturnD = "i"
                Return_Conversion = "(int)"
            elif Is_Float_Type(Return_Type):
                R = "float"
                ReturnD = "f"
                Return_Conversion = "(float)"
            elif Is_Class(Return_Type):
                Pre_Additional_Content += Get_Name(Return_Type) + "* R = new " + Get_Name(Return_Type) + "();\n *R = "
                Post_Additional_Content += "return R;\n"
                R = Get_Name(Return_Type) + "*"
                ReturnD = Get_Name(Return_Type) + "."
            elif Is_Void_Type(Return_Type):
                R = "void"
                ReturnD = ""
            elif Is_Declarated_Type(Return_Type):
                if Is_Enumeration_Type(Return_Type.declaration):
                    R = "int"
                    ReturnD = "i"
                    Return_Conversion = "(int)"
                elif Is_Class(Return_Type.declaration):
                    Pre_Additional_Content += Get_Name(Return_Type.declaration) + "* R = new " + Get_Name(Return_Type.declaration) + "();\n *R = "
                    ReturnD = "(" + Module_Name + "." + Get_Name(Return_Type.declaration).replace("_Class", "_Type") + ")"
                    Post_Additional_Content += "return R;\n"
                    R = "void *"
                else:
                    print("Unhandled return type : ", Return_Type, " type : ", type(Return_Type))
            else:
                print("Unhandled return type : ", Return_Type, " type : ", type(Return_Type))



    # - Function name  
    Function_Name = Get_Name(Declaration)

    
    Berry_Function_Name = "Berry_" + Get_Name(Declaration.parent) + "_"

    if Is_Constructor(Declaration):
        Berry_Function_Name += "Initialize"
    elif Is_Destructor(Declaration):
        Berry_Function_Name += "Deinitialize"
    else:
        Berry_Function_Name += Function_Name
    
    Berry_Function_Name += "_" + str(uuid.uuid4()).replace("-", "_") # Add an unique id to allow overloading


    # - Function signature
    Berry_Function_Signature = R + " " + Berry_Function_Name + "(" + S + ")\n"

    # - Function body
    Berry_Function_Body = "{\n" + Pre_Additional_Content 

    if Post_Additional_Content == "":
        Berry_Function_Body += "return " + Return_Conversion

    if Is_Constructor(Declaration):
        Berry_Function_Body += "new " + Module_Name + "_Types::" + Get_Name(Declaration.parent)
    elif Is_Destructor(Declaration):
        Berry_Function_Body += "delete I;\n}\n"
    elif Is_Function(Declaration):
        if Is_Module:   # Function but not module
            Berry_Function_Body += Module_Name + "." + Function_Name
        else:
            Berry_Function_Body += "I->" + Function_Name

    if not(Is_Destructor(Declaration)):
        Berry_Function_Body += "(" + Passed_Arguments + "); \n" + Post_Additional_Content + "}\n"

    # - Function declaration
    Berry_Function_Declaration = "BE_FUNC_CTYPE_DECLARE(" + Berry_Function_Name + ", \"" + ReturnD + "\", \"" + StringD + "\");\n" 

    #print(Berry_Function_Signature)
    #print(Berry_Function_Body)
    #print(Berry_Function_Declaration)
    #print("")

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

def Get_Class_Binding_Declaration(Class, Module, Namespace=None):
    if not(Is_Class(Class)):
        return nil

    Declaration = "/* @const_object_info_begin\n"

    if Module:
        Declaration += "module " + Get_Name(Class).replace("_Class", "") + " (scope:global)"
    else:
        Declaration += "class Berry_" + Get_Name(Class).replace("_Class", "_Type") + "(scope:global, name:" + Get_Name(Class).replace("_Class", "_Type") + ")"

    Declaration += "\n{\n"

    if not(Module):
        Declaration += "\t_p, var\n" # Instance pointer
    
    for Binding in Binding_Function_Table:
        Declaration += "\t" + Binding[0] + ", ctype_func(" + Binding[1] + ")\n"

    Declaration += "\n"

    if Module:
        for Class in Namespace.classes():
            Name = Get_Name(Class).replace("_Class", "_Type")
            Declaration += "\t" + Name + ", class(Berry_" + Name + ")\n\n"

        for Type in Namespace.enumerations():

            Values = Type.get_name2value_dict()
            for Key, Value in Values.items():
                Declaration += "\t" + Get_Name(Type).replace("_Type", "") + "_" + Key + ", int(" + str(Value) + ")\n"
            Declaration += "\n"



    Declaration  += "}\n@const_object_info_end */\n"
    return Declaration