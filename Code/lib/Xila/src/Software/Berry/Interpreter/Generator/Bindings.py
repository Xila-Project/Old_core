from pygccxml import utils
from pygccxml import declarations as Declarations
from pygccxml import parser as Parser
import os
from Basics import *
import copy
import re

# Function that convert function arguments to 
def Get_Binding_Function_Arguments(Declaration, Module):

    print('Function : ', Declaration, ' Module : ', Module)

    Arguments = Get_Function_Arguments(Declaration)

    S = ""
    StringD = ""
    R = ""
    ReturnD = ""
    Return_Conversion = ""

    Additional_Content = ""
    Passed_Arguments = ""


    Length = len(Arguments)

    if not(Module):
        if Is_Function(Declaration) or Is_Destructor(Declaration):
            S += Get_Name(Declaration.parent) + "* I, "
            StringD += "."

    for i, Raw_Argument in enumerate(Arguments):
        Argument = Remove_Alias(Raw_Argument.decl_type)
        if Is_Pointer_Type(Argument):
            Base_Type = Get_Base_Type(Argument)
            print("Base pointer type : ", Base_Type)
            if Is_Const(Argument):
                if (str(Base_Type) == "char") or (str(Base_Type) == "unsigned char"):
                    S += "const" + str(Base_Type) + "char* A_" + str(i) + ", "
                    StringD += "s"
            else:
                if (str(Base_Type) == "char") or (str(Base_Type) == "unsigned char"):
                    # Override return type
                    R += "const " + str(Base_Type) + "*"
                    ReturnD += "s"
                    Additional_Content += str(Base_Type) + "S_" + str(i) + "[256] = \{0\}\n"
                    Passed_Arguments += "S_" + str(i) + ", "
        else:
            if Is_Boolean_Type(Argument):
                S += "bool A_" + str(i) + ", "
                StringD += "b"
                Passed_Arguments += "A_" + str(i) + ", "
            elif Is_Integral_Type(Argument) or Is_Enumeration(Argument):
                Base_Type = Get_Base_Type(Argument)
                S += "int A_" + str(i) + ", "
                StringD += "i"
                Passed_Arguments += "(" + str(Base_Type) + ")A_" + str(i) + ", " # Conversion from int to desired type
            elif Is_Float_Type(Argument):
                Base_Type = Get_Base_Type(Argument)
                S += "float A_" + str(i) + ", "
                StringD += "f"
                Passed_Arguments += "(" + str(Base_Type) + ")A_" + str(i) + ", "
            elif Is_Class(Argument):
                S += Get_Name(Argument.base_type) + "* A_" + str(i) + ", "
                StringD += "."
            else:
                print("Unhandled type : ", Argument)
                S += "void* A_" + str(i) + ", "
                StringD += "."
                Passed_Arguments += "A_" + str(i) + ", "

    if S.endswith(", "):
        S = S[:-2]
    if Passed_Arguments.endswith(", "):
        Passed_Arguments = Passed_Arguments[:-2]

    # Return :
    if Is_Constructor(Declaration):
        R += "void *"
        ReturnD += "+_p"
    elif Is_Destructor(Declaration):
        R += "void"
        ReturnD += "empty"
    elif (R == "") and (ReturnD == ""):
        Return_Type = Remove_Alias(Get_Return_Type(Declaration))
        if Is_Pointer_Type(Return_Type):
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
            elif (Is_Integral_Type(Return_Type)) or (Is_Enumeration(Return_Type)):
                R = "int"
                ReturnD = "i"
                Return_Conversion = "(int)"
            elif Is_Float_Type(Return_Type):
                R = "float"
                ReturnD = "f"
                Return_Conversion = "(float)"
            elif Is_Class(Return_Type):
                R = Get_Name(Return_Type) + "*"
                ReturnD = Get_Name(Return_Type) + "."
            elif Is_Void_Type(Return_Type):
                R = "void"
                ReturnD = ""
            else:
                print("Unhandled return type : ", Return_Type)


    Function_Name = Get_Name(Declaration)

    # - Function name    
    Berry_Function_Name = "Berry_" + Get_Name(Declaration.parent) + "_"

    if Is_Constructor(Declaration):
        Berry_Function_Name += "Initialize"
    elif Is_Destructor(Declaration):
        Berry_Function_Name += "Deinitialize"
    else:
        Berry_Function_Name += Function_Name
    

    Complementary_Berry_Function_Name = re.sub(r"[^a-zA-Z0-9_]+", '', S.replace(" ", "_"))

    # - Function signature
    Berry_Function_Signature = R + " " + Berry_Function_Name + "(" + S + ")"

    # - Function body
    Berry_Function_Body = "{\n" + Additional_Content + "return " + Return_Conversion
    if Is_Constructor(Declaration):
        Berry_Function_Body += "new " + Get_Name(Declaration.parent)
    elif Is_Destructor(Declaration):
        Berry_Function_Body += "delete I;\n}\n"
    elif Is_Function(Declaration):
        if Module:   # Function but not module
            Berry_Function_Body += "Module." # TODO : Replace
        else:
            Berry_Function_Body += "I->"

    if not(Is_Destructor(Declaration)):
        Berry_Function_Body += Get_Name(Declaration) + "(" + Passed_Arguments + "); \n}"

    # - Function declaration
    Berry_Function_Declaration = "BE_FUNC_CTYPE_DECLARE(" + Berry_Function_Name + Complementary_Berry_Function_Name + ", \"" + ReturnD + "\", \"" + StringD + "\")" 

    print(Berry_Function_Signature)
    print(Berry_Function_Body)
    print(Berry_Function_Declaration)
    print("")


    return S

def Get_Binding_Function_Name(Member, Module):
    Class_Name = Get_Name(Member.parent)
    
    Function_Name = "Berry_" + Class_Name + "_"

    if Is_Constructor(Member):
        Function_Name += "Initialize"
    elif Is_Destructor(Member):
        Function_Name += "Deinitialize"
    elif Is_Function(Member):
        Function_Name += Get_Name(Member)

    Arguments = Get_Binding_Function_Arguments(Member, Module)

    for i, Argument in enumerate(Arguments):
        Function_Name += "_" + re.sub(r'[^\w\s]', '', Argument[0])

    return Function_Name

def Get_Binding_Function_Signature(Member, Module):
    Class_Name = Get_Name(Member.parent)
    Member_Name = Get_Name(Member)

    Arguments = Get_Binding_Function_Arguments(Member, Module)

    Signature = ""

    if Is_Constructor(Member):
        Signature = "const void* "
    elif Is_Destructor(Member):
        Signature = "void "
    elif Is_Function(Member):
        Signature = Get_Return_Type(Member) + " "

    Signature += Get_Binding_Function_Name(Member, Module) + "("

    for i, Argument in enumerate(Arguments):
        if i != 0:
            Signature += ", "
        Signature += Argument[0] + " " + Argument[1]

    Signature += ")"
        
    return Signature

def Get_Binding_Function_Body(Declaration, Module):
    Class_Name = Get_Name(Declaration.parent)

    if Module:

        Module_Name = Class_Name.replace("_Class", "")
        Body = "{ return " + Module_Name + "." + Get_Name(Declaration) + "("

    else:
        if Is_Destructor(Declaration):
            return "{ delete static_cast<" + Class_Name + "*>(Instance); }"
        
        Body = "{ return "
        if Is_Constructor(Declaration):
            Body += "new " + Class_Name + "("
        elif Is_Function(Declaration):
            Body += "static_cast<" + Class_Name + "*>(Instance)->" + Get_Name(Declaration) + "("

    # Arguments
    Arguments = Get_Binding_Function_Arguments(Declaration, Module)
    Length = len(Arguments)
    for i, Argument in enumerate(Arguments):
        if (i != 0) or Module:  # Skip the first argument (the instance pointer)
            Body += Argument[1]
            if i != Length - 1:
                Body += ", "

    Body += "); }"

    return Body

    
def Get_Binding_Function(Declaration, Module):
    return Get_Binding_Function_Signature(Declaration, Module) + " " + Get_Binding_Function_Body(Declaration, Module)

def Convert_To_Berry_Types(Type):
    if Type_Bindings.get(Type) == None:
        #print("Unknown type: " + Type)
        return "."  # Unknown type
    
    return Type_Bindings[Type]

def Get_Binding_Function_Declaration(Declaration, Module):    
    Arguments = Get_Binding_Function_Arguments(Declaration, Module)

    Binding_Declaration = "BE_FUNC_CTYPE_DECLARE(" + Get_Binding_Function_Name(Declaration, Module) + ", \"" 
    
    if Is_Constructor(Declaration):
        Binding_Declaration += "+_p"
    elif Is_Function(Declaration):
        Binding_Declaration += Convert_To_Berry_Types(Get_Return_Type(Declaration))           
   

    Binding_Declaration += "\", \""

    if Is_Destructor(Declaration):
        Binding_Declaration += ".\");"
        return Binding_Declaration


    for i, Argument in enumerate(Arguments):
        # For the instance pointer
        if (i == 0) and Is_Function(Declaration):
            Binding_Declaration += "."
        else:
            Argument_Declaration_String = Argument[1].lower()
            Argument_Declaration_String = Argument_Declaration_String.replace(" ", "")        # Delete spaces
            Argument_Declaration_String = Argument_Declaration_String.replace("const", "")    # Delete const (not supported by the binding system)
            Argument_Declaration_String = Argument_Declaration_String.replace("unsigned", "")     # Delete unsigned (not supported by the binding system)

            Binding_Declaration += Convert_To_Berry_Types(Argument_Declaration_String)
    
    Binding_Declaration += "\");"
    return Binding_Declaration

def Get_Class_Binding_Declaration(Class, Module, Namespace=None):
    if not(Is_Class(Class)):
        return nil

    Declaration = "/* @const_object_info_begin\n"

    if Module:
        Declaration += "module " + Get_Name(Class).replace("_Class", "") + " (scope:global)"
    else:
        Declaration += "class Berry_" + Get_Name(Class) + "(scope:global, name:" + Get_Name(Class).replace("_Class", "_Type") + ")"

    Declaration += "\n{\n"

    if not(Module):
        Declaration += "\t_p, var\n" # Instance pointer
    
    for Member in Class.get_members():
        if Is_Constructor(Member) and not(Module):
            Declaration += "\tinit, ctype_func(" + Get_Binding_Function_Name(Member, Module) + ")\n"
        elif Is_Destructor(Member) and not(Module):
            Declaration += "\tdeinit, ctype_func(" + Get_Binding_Function_Name(Member, Module) + ")\n"
        elif Is_Function(Member):
            Declaration += "\t" + Get_Name(Member) + ", ctype_func(" + Get_Binding_Function_Name(Member, Module) + ")\n"

    if Module:
        for Type in Namespace.declarations:
            Declaration += "\n"
            if Is_Enumeration(Type):
                Values = Type.get_name2value_dict()
                for Key, Value in Values.items():
                    Declaration += "\t" + Get_Name(Type).replace("_Type", "") + "_" + Key + ", int(" + str(Value) + ")\n"
            elif Is_Class(Type):
                Declaration += "\t" + Get_Name(Type).replace("_Class", "_Type") + ", class(Berry_" + Get_Name(Type) + ")\n"



    Declaration  += "}\n@const_object_info_end */\n"
    return Declaration