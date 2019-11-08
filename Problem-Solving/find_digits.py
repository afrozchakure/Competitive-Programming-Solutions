#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the findDigits function below.
def findDigits(n):
    count = 0
    for i in str(n):
        if int(i) == 0:
            pass
        elif n%int(i) == 0:
            count += 1
    return count
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())  # 

        result = findDigits(n)

        fptr.write(str(result) + '\n')

    fptr.close()

# Output Format
# For every test case, count the number of digits in n
# that are divisors of n. Print each answer on a new line.

# Sample Input
# 2
# 12
# 1012

# Sample Output
# 2
# 3

# Explanation
# The number 12 is broken into two digits, 1 and 2. 
# When 12 is divided by either of those two digits, 
# the remainder is 0 so they are both divisors.
# The number 1012 is broken into four digits, 1, 0, 1, and 2. 
# 1012 is evenly divisible by its digits 1, 1, and 2, 
# but it is not divisible by 0 as division by zero is undefined.