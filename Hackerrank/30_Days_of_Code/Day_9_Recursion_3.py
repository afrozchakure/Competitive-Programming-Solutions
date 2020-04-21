# Task
# Write a factorial function that takes a positive integer, 
# N as a parameter and prints the result of N!(N factorial).

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the factorial function below.
def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n-1)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    result = factorial(n)

    fptr.write(str(result) + '\n')

    fptr.close()

# Output Format
# Print a single integer denoting N!.

# Sample Input
# 3

# Sample Output
# 6
