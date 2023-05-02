from pygccxml import utils
from pygccxml import declarations as Declarations
from pygccxml import parser as Parser
import os

def Is_Namespace(Declaration):
    return type(Declaration) == Declarations.namespace_t

def Is_Class(Declaration):
    return Declaration.name.endswith("_Class") and (type(Declaration) == Declarations.class_declaration.class_t)

def Is_Function(Declaration):
    return (type(Declaration) == Declarations.calldef_members.member_function_t) and (Declaration.access_type == "public")

def Is_Constructor(Declaration):
    # Discard default copy constructor
    #for Argument in Declaration.arguments:
    #    if (Argument.name == "arg0"):
    #        return False
    return type(Declaration) == Declarations.calldef_members.constructor_t

def Is_Enumeration(Declaration):
    return type(Declaration) == Declarations.enumeration.enumeration_t

def Is_Typedef(Declaration):
    return type(Declaration) == Declarations.typedef.typedef_t

def Is_Destructor(Declaration):
    return type(Declaration) == Declarations.calldef_members.destructor_t

def Get_Name(Declaration):
    return Declaration.name

def Get_Return_Type(Declaration):
    
    #print("For : ", Get_Name(Declaration), " return type : ", str(Declaration.return_type))
    #if (Is_Typedef(Declaration.return_type)):
    #    print("Typedef !")
    #    print("Top level: " + Get_Name(Declaration.return_type.top_parent))

    return str(Declaration.return_type).replace("Xila_Namespace::", "")

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


def Find_Class(Declarations, Name):
    for Declaration in Declarations:
        if Is_Class(Declaration) and (Get_Name(Declaration) == Name):
            return Declaration

def Find_Namespace(Declarations, Name):
    for Declaration in Declarations:
        if Is_Namespace(Declaration) and (Get_Name(Declaration) == Name):
            return Declaration