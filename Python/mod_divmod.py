# One of the built-in functions of Python is divmod, which takes two arguments a and b and returns a tuple containing the quotient of a/b first and then the remainder a.

# For example:
# >>> print divmod(177,10)
# (17, 7)

# Here, the integer division is 177/10 => 17 and the modulo operator is 177%10 => 7.

# Task
# Read in two integers, a and b, and print three lines.
# The first line is the integer division a//b (While using Python2 remember to import division from __future__).
# The second line is the result of the modulo operator: a%b.
# The third line prints the divmod of a and b.

# Input Format
# The first line contains the first integer, a, and the second line contains the second integer,b.

# Output Format
# Print the result as described above.

# Sample Input
# 177
# 10

# Sample Output
# 17
# 7
# (17, 7)

# Code
a = int(input())
b = int(input())
print(a//b)
print(a%b)
print(divmod(a,b))
