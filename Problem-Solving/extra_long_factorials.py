# Print factorial of given no.

# Note: Factorials of can't be stored even in a 64-bit
# long long variable. Big integers must be used for such calculations. 
# Languages like Java, Python, Ruby etc. can handle big integers, 
# but we need to write additional code in C/C++ to handle huge values.
# We recommend solving this challenge using BigIntegers. 

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the extraLongFactorials function below.
def extraLongFactorials(n):
    fact = 1
    if n == 1 or n == 0:
        fact = 1
    else:
        for i in range(1,n+1):
            fact *= i
    print(fact)
    return 
            

if __name__ == '__main__':
    n = int(input())

    extraLongFactorials(n)

# Output Format
# Print the factorial of n.

# Sample Input
# 25

# Sample Output
# 1551121004333098594000000