from pygccxml import utils
from pygccxml.declarations import type_traits as Type_Traits
from pygccxml import declarations as Declarations
from pygccxml import parser as Parser
from pygccxml.declarations import type_traits_classes as Type_Traits_Classes
import os

def Is_Namespace(Declaration):
    return type(Declaration) == Declarations.namespace_t

def Is_Class(Declaration):
    return (type(Declaration) == Declarations.class_declaration.class_t) and Declaration.name.endswith("_Class") 

def Is_Function(Declaration):
    return (type(Declaration) == Declarations.calldef_members.member_function_t) and (Declaration.access_type == "public")

def Is_Constructor(Declaration):
    # Discard default copy constructor
    #for Argument in Declaration.arguments:
    #    if (Argument.name == "arg0"):
    #        return False
    return type(Declaration) == Declarations.calldef_members.constructor_t and (Declaration.access_type == "public")

def Is_Operator(Declaration):
    return (type(Declaration) == Declarations.calldef_members.operator_t) or (type(Declaration) == Declarations.calldef_members.member_operator_t)

def Is_Copy_Constructor(Declaration):
    return Type_Traits_Classes.is_copy_constructor(Declaration)

def Is_Enumeration_Type(Declaration):
    return type(Declaration) == Declarations.enumeration.enumeration_t

def Is_Typedef(Declaration):
    return type(Declaration) == Declarations.typedef.typedef_t

def Is_Destructor(Declaration):
    return type(Declaration) == Declarations.calldef_members.destructor_t and (Declaration.access_type == "public")

def Is_Declarated_Type(Declaration):
    return type(Declaration) == Declarations.declarated_t

def Get_Name(Declaration):
    return Declaration.name

def Is_Function_Pointer(Declaration):
    return Declarations.is_calldef_pointer(Declaration)

def Get_Return_Type(Declaration):
    
    #print("For : ", Get_Name(Declaration), " return type : ", str(Declaration.return_type))
    #if (Is_Typedef(Declaration.return_type)):
    #    print("Typedef !")
    #    print("Top level: " + Get_Name(Declaration.return_type.top_parent))

   # print("Declaration : ", Declaration.return_type, " base : ", Type_Traits.base_type(Ty), " is fund", Type_Traits.is_fundamental(Ty) )

    return Declaration.return_type

def Get_Function_Arguments(Declaration):
    return Declaration.arguments

def Get_Base_Type(Declaration):
    return Type_Traits.base_type(Declaration)

def Is_Void_Type(Declaration):
    return Type_Traits.is_void(Declaration)

def Is_Fundamental_Type(Declaration):
    return Type_Traits.is_fundamental(Declaration)

def Is_Boolean_Type(Declaration):
    return Type_Traits.is_bool(Declaration)

def Is_Optional(Declaration):
    return Declaration.default_value != None

def Is_Integral_Type(Declaration):
    return Type_Traits.is_integral(Declaration)

def Is_Elaborated_Type(Declaration):
    return Type_Traits.is_elaborated(Declaration)

def Is_Float_Type(Declaration):
    return Type_Traits.is_floating_point(Declaration)

def Is_Pointer_Type(Declaration):
    return Type_Traits.is_pointer(Declaration)

def Is_Reference_Type(Declaration):
    return Type_Traits.is_reference(Declaration)

def Is_Const(Declaration):
    return Type_Traits.is_const(Declaration)

def Remove_Alias(Declaration):
    return Type_Traits.remove_alias(Declaration)

def Remove_Const_Volatile(Declaration):
    return Type_Traits.remove_cv(Declaration)

def Get_Project_Path():
    Path = os.path.dirname(__file__)
    Path = Path.split("Xila/Code")[0]
    Path = os.path.join(Path, "Xila")
    return Path

def Get_Code_Path():
    return os.path.join(Get_Project_Path(), "Code")


def Get_Modules_List():
    Path = os.path.join(Get_Code_Path(), "lib", "Xila", "include", "Core")

    Folders = os.listdir(Path)

    Modules = []

    for Item in Folders:
        if os.path.isdir(os.path.join(Path, Item)) and Item != "Configuration":
            if Item == "Software":
                Modules.append("Softwares")
            else:
                Modules.append(Item)

    return Modules

def Get_Generated_Folder_Path():
    Path = os.path.join(os.path.dirname(__file__), "Generated")
    if not os.path.exists(Path):
        os.mkdir(Path)
    return Path

def Get_Static_Folder_Path():
    Path = os.path.join(os.path.dirname(__file__), "Static")
    if not os.path.exists(Path):
        os.mkdir(Path)
    return Path

def Find_Class(Declarations, Name):
    for Declaration in Declarations:
        if Is_Class(Declaration) and (Get_Name(Declaration) == Name):
            return Declaration

def Find_Namespace(Declarations, Name):
    for Declaration in Declarations:
        if Is_Namespace(Declaration) and (Get_Name(Declaration) == Name):
            return Declaration