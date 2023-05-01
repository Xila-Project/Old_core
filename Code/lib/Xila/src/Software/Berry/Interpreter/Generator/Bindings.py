from pygccxml import utils
from pygccxml import declarations as Declarations
from pygccxml import parser as Parser
import os
from Basics import *
import copy

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
    "bool": "b"
}

def Get_Binding_Function_Arguments(Declaration):
    Arguments = copy.deepcopy(Declaration.arguments)    # Make a copy of the arguments to avoid modifying the original declaration

    if Is_Function(Declaration) or Is_Destructor(Declaration):
        Arguments.insert(0, Declarations.argument_t("Instance", "void*"))

    return Arguments

def Get_Binding_Function_Name(Member):
    Class_Name = Get_Name(Member.parent)

    if Is_Constructor(Member):
        return "Berry_" + Class_Name + "_" + "Initialize"
    elif Is_Destructor(Member):
        return "Berry_" + Class_Name + "_" + "Deinitialize"
    elif Is_Function(Member):
        return "Berry_" + Class_Name + "_" + Get_Name(Member)

def Get_Binding_Function_Signature(Member):
    Class_Name = Get_Name(Member.parent)
    Member_Name = Get_Name(Member)

    if Is_Constructor(Member):
        Signature = "const void* " + Get_Binding_Function_Name(Member) + "("
    elif Is_Destructor(Member):
        Signature = "void " + Get_Binding_Function_Name(Member) + "("
    elif Is_Function(Member):
        Signature = Get_Return_Type(Member) + " " + Get_Binding_Function_Name(Member) + "("

    Arguments = Get_Binding_Function_Arguments(Member)
    for i, Argument in enumerate(Arguments):
        if i != 0:
            Signature += ", "
        Signature += str(Argument.decl_type) + " " + str(Argument.name)

    Signature += ")"
        
    return Signature

def Get_Binding_Function_Body(Declaration):
    Class_Name = Get_Name(Declaration.parent)
    
    if Is_Destructor(Declaration):
        return "{ delete static_cast<" + Class_Name + "*>(Instance); }"
    
    Body = "{ return "
    if Is_Constructor(Declaration):
        Body += "new " + Class_Name + "("
    elif Is_Function(Declaration):
        Body += "static_cast<" + Class_Name + "*>(Instance)->" + Get_Name(Declaration) + "("

    # Arguments
    Arguments = Get_Binding_Function_Arguments(Declaration)
    Length = len(Arguments)
    for i, Argument in enumerate(Arguments):
        Body += str(Argument.name)
        if i != Length - 1:
            Body += ", "

    Body += "); }"

    return Body

    
def Get_Binding_Function(Declaration):
    return Get_Binding_Function_Signature(Declaration) + " " + Get_Binding_Function_Body(Declaration)

def Convert_To_Berry_Types(Type):
    if Type_Bindings.get(Type) == None:
        print("Unknown type: " + Type)
        return "."  # Unknown type
    
    return Type_Bindings[Type]

def Get_Binding_Function_Declaration(Declaration):    
    Binding_Declaration = "BE_FUNC_CTYPE_DECLARE(" + Get_Binding_Function_Name(Declaration) + ", \"" 
    
    if Is_Constructor(Declaration):
        Binding_Declaration += "+_p"
    elif Is_Function(Declaration):
        Binding_Declaration += Convert_To_Berry_Types(Get_Return_Type(Declaration))           
   

    Binding_Declaration += "\", \""

    if Is_Destructor(Declaration):
        Binding_Declaration += ".\");"
        return Binding_Declaration

    Arguments = Get_Binding_Function_Arguments(Declaration)


    for i, Argument in enumerate(Arguments):
        # For the instance pointer
        if (i == 0) and Is_Function(Declaration):
            Binding_Declaration += "."
        else:
            Argument_Declaration_String = str(Argument.decl_type).lower()
            Argument_Declaration_String = Argument_Declaration_String.replace(" ", "")        # Delete spaces
            Argument_Declaration_String = Argument_Declaration_String.replace("const", "")    # Delete const (not supported by the binding system)
            Argument_Declaration_String = Argument_Declaration_String.replace("unsigned", "")     # Delete unsigned (not supported by the binding system)

            Binding_Declaration += Convert_To_Berry_Types(Argument_Declaration_String)
    
    Binding_Declaration += "\");"
    return Binding_Declaration

def Get_Class_Binding_Declaration(Class):
    if not(Is_Class(Class)):
        return nil

    Declaration = "/* @const_object_info_begin\n"
    Declaration += "class Berry_" + Get_Name(Class) + "(scope:global, name:" + Get_Name(Class) + ")\n"
    Declaration += "{\n"
    Declaration += "\t_p, var\n" # Instance pointer
    for Member in Class.get_members():
        if Is_Constructor(Member):
            Declaration += "\tinit, ctype_func(" + Get_Binding_Function_Name(Member) + ")\n"
        elif Is_Destructor(Member):
            Declaration += "\tdeinit, ctype_func(" + Get_Binding_Function_Name(Member) + ")\n"
        elif Is_Function(Member):
            Declaration += "\t" + Get_Name(Member) + ", ctype_func(" + Get_Binding_Function_Name(Member) + ")\n"

    Declaration  += "}\n@const_object_info_end */\n"
    return Declaration