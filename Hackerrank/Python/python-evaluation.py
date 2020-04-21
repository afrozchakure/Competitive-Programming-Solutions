# It helps in evaluating an expression. 
# The expression can be a Python statement, or a code object. --->

# >>> eval("9 + 5")
# 14
# >>> x = 2
# >>> eval("x + 3")
# 5

# eval() can also be used to work with Python keywords or defined 
# functions and variables. These would normally be stored as strings.  -->

# >>> type(eval("len"))
# <type 'builtin_function_or_method'>

# Without eval() -- >

# >>> type("len")
# <type 'str'>

A = input()
eval(A)  # Don't use print() function since it prints None as well