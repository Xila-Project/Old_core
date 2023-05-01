from pygccxml import utils
from pygccxml import declarations as Declarations
from pygccxml import parser as Parser
import os
from Basics import *
import copy
import re

Type_Bindings = {
    "uint8_t": "i",
    "uint16_t": "i",
    "uint32_t": "i",
    "uint64_t": "i",
    "int8_t": "i",
    "int16_t": "i",
    "int32_t": "i",
    "int64_t": "i",
    "int": "i",
    "float": "f",
    "double": "f",
    "char*": "s",
    "bool": "b",
    "void": "",
    "void*": "p",
    "bool": "b",
    "String_Type": "s",
    "String_Type&": "s",
    "Size_Type": "i"
}

def Get_Binding_Function_Arguments(Declaration, Module):

    Arguments = []

    # Just copy the arguments names and types (faster than deepcopy since we don't need to copy the whole tree)
    for Argument in Declaration.arguments:
        Arguments.append([str(Argument.decl_type).replace("Xila_Namespace::", ""), Get_Name(Argument)])

    # Clean types
    for i in range(len(Arguments)):
        Arguments[i][0] = Arguments[i][0].replace(" ", "")
        Arguments[i][0] = Arguments[i][0].replace("const", "")

    if not(Module):
        if Is_Function(Declaration) or Is_Destructor(Declaration):
            Arguments.insert(0, ["void*", "Instance"])

    return Arguments

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