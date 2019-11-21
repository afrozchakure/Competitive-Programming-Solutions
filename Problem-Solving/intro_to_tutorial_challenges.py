# Sample Challenge
# This is a simple challenge to get things started. Given a sorted array (arr) and a number (V), 
# can you print the index location of V in the array?
# For example, if arr = [1,2,3] and V = 3, you would print 2 for a zero-based index array.
# If you are going to use the provided code for I/O, this next section is for you.

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the introTutorial function below.
def introTutorial(V, arr):
    return arr.index(V)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    V = int(input())  # Value to be searched

    n = int(input())  # No. of elements in the arr

    arr = list(map(int, input().rstrip().split()))

    result = introTutorial(V, arr)

    fptr.write(str(result) + '\n')

    fptr.close()

# Output Format
# Output the index of V in the array.
# The next section describes the constraints and ranges of the input. You should check this section to know the range of the input.

# Sample Input 0
# 4
# 6
# 1 4 5 7 9 12

# Sample Output 0
# 1

# Explanation 0
# V = 4 . The value 4 is the 2nd element in the array, but its index is 1 since in this case, 
# array indices start from 0(see array definition under Input Format).

