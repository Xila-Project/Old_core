# 📖 Syntax

The Berry syntax is simple (similar to Python). Here you will find a fast description of the syntax. You can find the full documentation [here](https://berry.readthedocs.io/en/latest/source/en/Reference.html).

## Comments

To comment a line, use `# ...` at the beginning of the line. To comment multiple lines, use `#- ... -#` at the beginning and the end of the comment.

```python
# Comment to end of line.
#- Multiline 
comment -#
```

## Identifier

An identifier is a name used to identify a variable, function, class, module or any other user-defined item.

:::{note}
    An identifier starts with a letter an underscore, followed by zero or more letters, underscores and digits (0 to 9). Identifiers are case sensitive.
:::

:::{note}
    The following identifiers are reserved for internal use and therefore cannot be used :
`if` `elif` `else` `while` `for` `def` `end` `class` `break` `continue` `return` `true` `false` `nil` `var` `do` `import` `as`
:::

## Operators

Operators are special symbols that represent operations like addition, multiplication and division. The following table lists the operators in order of precedence (from highest to lowest) :

1. `()`(call) `[]`(index) `.`(field)
2. `!` `~` `-`(negative)
3. `*` `/` `%`
4. `+` `-`
5. `<<` `>>` (bitwise shift operators)
6. `&` (bitwise and)
7. `^` (bitwise xor)
8. `|` (bitwise or)
9. `..` (connect or range)
10. `<` `<=` `>` `>=`
11. `==` `!=`
12. `&&` (stops on false, returns last evaluated value)
13. `||` (stops on true, returns last evaluated value)
14. `+` `-`
15. `? :` (conditional expression)
16. `=` (`=` and other assignment operators)

## Variables

Variables are used to store information to be referenced and manipulated in a program. They are referred to by an `identifier`.

```python
a = 1 # Simple assignment (implicit declaration)
var b # Explicit declaration (initialized to nil)
var c, d # Declare multiple variables
var e=0, f=1 # Declare multiple variables and initialize
a = 1 + 3 # Operation and assignment
```

## Types

Here is the list of the types that are supported by Berry:

- `nil` : Means no value (written as nil).
- `boolean` : Contains `true` or `false`.
- `integer` : Signed integer number.
- `real` : Floating point number.
- `string` : Can include any character (and zero).
- `function` : First class type, can be assigned as a value.
- `class` : Instance template, read only.
- `instance` : Object constructed by class.
- `module` : Read-write key-value pair table.
- `list` : Variable-length ordered container class.
- `map` : Read-write hash key-value container class.
- `range` : Integer range class.

### Class

Like other oriented programming languages, a class consists of :
- Constructor / destructor : Special methods that are called when an instance is created or destroyed. They are used to initialize or release resources.
- Attributes : members variables.
- Methods : member functions.
- Inheritance.
- Methods and operators overloading.

:::{note}
     Berry only supports single inheritance, that is, a class can only have one base class, and the base class uses the operator : to declare :
:::

```python
import string   # Import string module.

class Parent_Class
    # - Attributes
    var Parent_Name
    var Child_Name

    # - Constructor
    def init()
        self.Parent_Name = "Darth vader"
        self.Child_Name = ""
    end

    # - Methods
    def Say()
        return string.format(
            "%s say\n%s %s", self.Parent_Name,
            self.Child_Name, "i'm your father"
        )
    end
end

Parent = Parent_Class()
print(Parent.Say()) # "Darth vader say i'm your father" (since Child_Name is empty) 

class Child_Class : Parent_Class    # Child_Class inherits from Parent_Class
    # - Constructor
    def init(Name)
        self.Parent_Name = Parent_Class().Parent_Name
        self.Child_Name = Name
    end
end

Child = Child_Class("Luke")
print(Child.Say())  # "Darth vader say Luke i'm your father"
```

### List

List are arrays that can contain any type of value.

```python
List = [] # New empty list value.
List = [0] # The list has a value “0”.
# - Different types of values can be stored in the list.
List = [[],nil] # Here, List[0] == [] (empty list) and List[1] == nil.
```

### Map

Map is a key-value pair container : `Map[key] = value`.

```python
Map = {} # New empty map value.
Map = [0:'ok','k':nil] # Here, Map[0] == 'ok' and Map['k'] == nil.
Value = Map['k'] # Get value from map, here Value == 'ok'.
```

:::{note}
The key can be any value that is not `nil`.
:::

## Range

Range is a range of integer values.

```python
Range = 0..5 # New range from 0 to 5.
```

## Special delimiters

Special characters need to be escaped:

- `\a` : bell.
- `\b` : backspace.
- `\f` : form feed
- `\n` : newline
- `\r` : return
- `\t` : tab
- `\v` : vert. tab 
- `\\` : backslash
- `\'` : single quote
- `\"` : double quote
- `\?` : question
- `\0` : NULL
- `\ooo` : character represented octal number.
- `\xhh` : character represented hexadecimal number.

## Expression and Statement

- Expression : Consist of operators, operands, and group-
ing symbols (brackets), etc. All expressions
are evaluable.

- Statement : The most basic execution unit. Consists of
an assignment expression or function call
expression.

### Conditional expression

```python
condition ? expression1 : expression2
```

If the value of condition is true, then expression1 will
be executed, otherwise expression2 will be executed. The
conditional expression return the the last evaluated value.

```python
4.5  # A simple expression, just an operand.
!true # Logical not expression, unary operation.
1+2 # An addition expression, binary operation.
print(12) # Function call expression.
```

Logical operations and Boolean
The condition detection operation require a Boolean value,
and non-boolean type will do the following conversion:
nil Convert to false.
number 0 is converted to false, others are converted to
true.
instance Try to use the result of the tobool() method,
otherwise it will be converted to true.
other Convert to true.

## Scope, blocks and chunks

- Block : Is the body of a control structure, body of a function
or a chunk. The block consists of several statements.

- Chunk : A file or string of script.

Variables defined in the chunk have a global scope, and
those defined in other blocks have a local scope.

## Control structures

### If statement

```python
if #condition
    #block
elif #condition
    #block
else 
    #block
end
```
### Loops

```python
while #cond
#block
end
```

```python
for #id in #expr
#block
end
```

```python
do block end
while cond block end
for id : expr block end iterative statement.
for id = expr, cond[, expr] block end loop for statement,
(not support now).
break exits loop (must be in while or for statement).
continue start the next iteration of the loop (must be in
while or for statement).
return [expr] exit function and return a (nil) value.
NOTE: expression aka. expr; identifier aka. id; and con-
dition aka. cond.
```

### Function and Lambda expression

A named function is a statement, the name is a identifier :

```python
def name (args)
    #block
end
```
An anonymous function is an expression:

```python
def (args)
    #block 
end
```

Lambda expression, the return value is `expr`:

```python
/args-> expr
```

Arguments list (aka. args), Lambda expression arguments list can omit “,”. :

```python
id {, id}
```

## Exception handling

```python
throw exception [, message]
Thorw a exception value and unnecessary message value.
try
block {
except ((expr {, expr} | ..) [as id [, id]] | ..)
block
} end
```

One or more except blocks must exist. Only runtime exceptions can be catch.
Some except statements examples:

```python
except .. # Catch all exceptions, but no exception variables.
except 0,1 as .. # Capture 0 and 1, no exception variables.
except .. as e # Capture all exception to variable e.
except 0 as e # Capture exception 0 to variable e.
except .. as e,m # Capture all exception to variable e, and save the message to variable m.
```