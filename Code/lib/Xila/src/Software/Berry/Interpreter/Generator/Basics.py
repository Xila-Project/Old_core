from pygccxml import utils
from pygccxml import declarations as Declarations
from pygccxml import parser as Parser
import os

def Is_Namespace(Declaration):
    return type(Declaration) == Declarations.namespace_t

def Is_Class(Declaration):
    return Declaration.name.endswith("_Class")

def Is_Function(Declaration):
    return type(Declaration) == Declarations.calldef_members.member_function_t

def Is_Constructor(Declaration):
    # Discard default copy constructor
    #for Argument in Declaration.arguments:
    #    if (Argument.name == "arg0"):
    #        return False
    return type(Declaration) == Declarations.calldef_members.constructor_t

def Is_Destructor(Declaration):
    return type(Declaration) == Declarations.calldef_members.destructor_t

def Get_Name(Declaration):
    return Declaration.name

def Get_Return_Type(Declaration):
    return str(Declaration.return_type)
