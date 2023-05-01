from pygccxml import utils
from pygccxml import declarations as Declarations
from pygccxml import parser as Parser
import os
from Basics import *
from Bindings import *
import json
import re
import shutil
import subprocess

def Get_Header_File_Paths(Folder_Path):
    Headers_File_Paths = []
    for Item in os.listdir(Folder_Path):
        Item_Path = os.path.join(Folder_Path, Item)
        if os.path.isdir(Item_Path):
            Headers_File_Paths.append(Get_Header_File_Paths(Item_Path))
        elif os.path.isfile(Item_Path) and Item_Path.endswith(".hpp"):
            if Item_Path.endswith(".hpp"):
                Headers_File_Paths.append(Item_Path)

def Generate_Class(Class, Module_Name):
    File_Path = os.path.join(Get_Generated_Folder_Path(), Get_Name(Class) + ".cpp")

    if os.path.exists(File_Path):
        os.remove(File_Path)

    Generated_File = open(File_Path, "w")

    # print(Get_Header_File_Paths(os.path.dirname(__file__)))

    Generated_File.write("// This file is automatically generated by the Generate.py script.\n")
    Generated_File.write("#include \"Software/Berry/Berry.hpp\"\n")
    Generated_File.write("extern \"C\"\n{\n#include \"be_constobj.h\"\n")
    Generated_File.write("#include \"be_mapping.h\"\n}\n")
    Generated_File.write("using namespace Xila_Namespace;\n")
    Generated_File.write("using namespace " + Module_Name + "_Types;\n")


    Generated_File.write("\n// - Functions\n")
    # Constructors
    Generated_File.write("\n// - - Constructors\n")
    for Member in Class.get_members():
        if (Is_Constructor(Member)):
             Generated_File.write(Get_Binding_Function(Member, False) + "\n")
             Generated_File.write(Get_Binding_Function_Declaration(Member, False) + "\n")

    Generated_File.write("\n// - - Destructors\n")

    # Destructor
    for Member in Class.get_members():
        if (Is_Destructor(Member)):
            Generated_File.write(Get_Binding_Function(Member, False) + "\n")
            Generated_File.write(Get_Binding_Function_Declaration(Member, False) + "\n")

    Generated_File.write("\n// - - Functions\n")

    # Function
    for Member in Class.get_members():
        if(Is_Function(Member)):
            Generated_File.write(Get_Binding_Function(Member, False) + "\n")
            Generated_File.write(Get_Binding_Function_Declaration(Member, False) + "\n")

    # Berry declaration part

    Generated_File.write("\n// - Berry declaration\n")
    Generated_File.write(Get_Class_Binding_Declaration(Class, False) + "\n")

    # Include the berry header

    Generated_File.write("\nextern \"C\"\n{\n")
 #   Generated_File.write("\t#include \"../generate/be_fixed_" + Module_Name + ".h\"\n")
    Generated_File.write("\t#include \"../generate/be_fixed_Berry_" + Get_Name(Class) + ".h\"\n")
    Generated_File.write("}")

    Generated_File.close()


def Generate_Module(Xila_Namespace, Module_Name):
    # Generate module class
    Module_Class = Find_Class(Xila_Namespace.declarations, Module_Name + "_Class")
    Module_Namespace = Xila_Namespace.namespace(Module_Name + "_Types")

    File_Path = os.path.join(Get_Generated_Folder_Path(), Module_Name + ".cpp")

    if os.path.exists(File_Path):
        os.remove(File_Path)

    Generated_File = open(File_Path, "w")

    # print(Get_Header_File_Paths(os.path.dirname(__file__)))

    Generated_File.write("// This file is automatically generated by the Generate.py script.\n")
    Generated_File.write("#include \"Software/Berry/Berry.hpp\"\n")
    Generated_File.write("extern \"C\"\n{\n#include \"be_constobj.h\"\n")
    Generated_File.write("#include \"be_mapping.h\"\n}\n")
    Generated_File.write("using namespace Xila_Namespace;\n")
    Generated_File.write("using namespace " + Module_Name + "_Types;\n")


    Generated_File.write("\n// - Functions\n")

    # Function
    for Member in Module_Class.get_members():
        if(Is_Function(Member)):
            Generated_File.write(Get_Binding_Function(Member, True) + "\n")
            Generated_File.write(Get_Binding_Function_Declaration(Member, True) + "\n")

    # Berry declaration part

    Generated_File.write("\n// - Berry declaration\n")
    Generated_File.write(Get_Class_Binding_Declaration(Module_Class, True, Module_Namespace) + "\n")

    # Include the berry header

    Generated_File.write("\nextern \"C\"\n{\n")

    # Generate module types

    for Type in Module_Namespace.declarations:
        if Is_Class(Type):
            Generate_Class(Type, Module_Name)
            Generated_File.write("\t#include \"../generate/be_fixed_Berry_" + Get_Name(Type) + ".h\"\n")

    Generated_File.write("\t#include \"../generate/be_fixed_" + Module_Name + ".h\"\n")
    Generated_File.write("}")
    Generated_File.close()

def Generate(Global_Namespace):
    Declarations = Global_Namespace.declarations()
    for Declaration in Declarations:
        if (Is_Namespace(Declaration)):
            print("Namespace : " + Get_Name(Declaration))
            Generate(Declaration)
        elif (Is_Class(Declaration)):    
            print("Class : " + Get_Name(Declaration))
            Generate_Class(Declaration)

    
# Find the location of the xml generator (castxml or gccxml)
generator_path, generator_name = utils.find_xml_generator()

shutil.rmtree(Get_Generated_Folder_Path(), ignore_errors=True)
os.makedirs(Get_Generated_Folder_Path())

# The C++ file we want to parse

compile_commands_path = os.path.join(os.path.dirname(__file__), "compile_commands.json")

Compile_Commands_File = open(compile_commands_path, "r")

Compile_Commands = json.load(Compile_Commands_File)

Commands = ""

for Command in Compile_Commands:
    Commands += Command["command"]

I_Flags_Raw = re.findall(r'-I([^\s]+)', Commands)

D_Flags_Raw = re.findall(r'-D([^\s]+)', Commands)

D_Flags = []

for Flag in D_Flags_Raw:
    if Flag not in D_Flags:
        D_Flags.append(Flag)

I_Flags = []

I_Flags_Raw.append(".pio/libdeps/wt32-sc01-plus/Battery Library/src")

for Flag in I_Flags_Raw:
    if Flag not in I_Flags:
        I_Flags.append(Flag)

for i in range(len(I_Flags)):
    if not(I_Flags[i].startswith("/home")):
        I_Flags[i] = os.path.join(Get_Code_Path(), I_Flags[i])
    
print(I_Flags)
    
# Configure the xml generator
xml_generator_config = Parser.xml_generator_configuration_t(
    xml_generator_path=generator_path,
    xml_generator=generator_name,
    compiler_path="/home/alix_anneraud/.platformio/packages/toolchain-xtensa-esp32s3/bin/xtensa-esp32s3-elf-g++",
    define_symbols=D_Flags,
    cflags="-m32 -fpermissive -fsyntax-only -ferror-limit=200 -std=gnu++11 -Wignored-attributes -fexceptions -fms-extensions -frtti  -mlong-calls -ffunction-sections -fdata-sections -Wno-error=unused-function -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-sign-compare -ggdb -freorder-blocks -Wwrite-strings -fstack-protector -Wno-error=unused-but-set-variable -fno-jump-tables -MMD -Og -g2 -ggdb2",
    include_paths=I_Flags
)

Header = [os.path.join(Get_Code_Path(), "lib", "Xila", "include", "Xila.hpp")]

# Parse the c++ file
Dec = Parser.parse(Header, xml_generator_config)

if os.path.exists(os.path.join(Get_Code_Path(), "Xila.d")):
    os.remove(os.path.join(Get_Code_Path(), "Xila.d"))

# Get access to the global namespace
Xila_Namespace = Declarations.get_global_namespace(Dec).namespace("Xila_Namespace")

#Generate_Module(Xila_Namespace, "System")
#Generate_Module(Xila_Namespace, "Memory")
Generate_Module(Xila_Namespace, "Drive")

Temporary_Folder_Path = os.path.join(Get_Code_Path(), "lib", "berry", "Temporary")

print(Temporary_Folder_Path)

# Delete temporary folder
shutil.rmtree(Temporary_Folder_Path, ignore_errors=True)
os.makedirs(Temporary_Folder_Path)

# Copy generated files to berry temporary folder


shutil.copytree(Get_Generated_Folder_Path(), Temporary_Folder_Path, dirs_exist_ok=True)

# Copy berry sources to temporary folder
Berry_Sources_Path = os.path.join(Get_Code_Path(), "lib", "berry", "src")
shutil.copytree(Berry_Sources_Path, Temporary_Folder_Path, dirs_exist_ok=True)

# Delete berry generate folder
Berry_Generate_Path = os.path.join(Get_Code_Path(), "lib", "berry", "generate")
shutil.rmtree(Berry_Generate_Path, ignore_errors=True)
os.makedirs(Berry_Generate_Path)

# Copy callback module to berry sources
Berry_Callback_Module_Path = os.path.join(Get_Code_Path(), "lib", "berry_mapping", "src", "be_cb_module.c")
shutil.copy(Berry_Callback_Module_Path, os.path.join(Temporary_Folder_Path, "be_cb_module.c"))

COC_Path = os.path.join(Get_Code_Path(), "lib", "berry", "tools", "coc", "coc")

Result = subprocess.run(["pwd"], stdout=subprocess.PIPE)

print(Result.stdout.decode("utf-8"))

Result = subprocess.run([COC_Path, '-o', 'generate', 'default', 'Temporary', '-c', 'default/berry_conf.h'], stdout=subprocess.PIPE)

shutil.rmtree(Temporary_Folder_Path, ignore_errors=True)

print(Result.stdout.decode("utf-8"))

print(Result.returncode)