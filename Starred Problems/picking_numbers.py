# Given an array of integers, find and print the maximum number of 
# integers you can select from the array such that the absolute difference between 
# any two of the chosen integers is less than or equal to 1. 
# For example, if your array is a = [1,1,2,2,4,4,5,5,5], you can create two subarrays meeting the criterion:
# [1,1,2,2] and [4,4,5,5,5]. The maximum length subarray has elements.

#!/bin/python3

import math
import os
import random
import re
import sys

from collections import defaultdict  # This step is important
def pickingNumbers(a):
    d = defaultdict(int)
    r_val = 0
    for val in a:
        d[val] += 1
        r_val = max(r_val, d[val]+d[val+1], d[val]+d[val-1])
        print(d)
    return r_val

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = pickingNumbers(a)

    fptr.write(str(result) + '\n')

    fptr.close()


# Output Format
# A single integer denoting the maximum number of integers you can choose from the array such that the absolute difference between any two of the chosen integers is <= 1.

# Sample Input 0
# 6
# 4 6 5 3 3 1

# Sample Output 0
# 3

# Explanation 0
# We choose the following multiset of integers from the array:
# {4,3,3}. Each pair in the multiset has an absolute difference <= 1 
# (i.e.|4-3| = 1 and |3-3| = 0), so we print the number of chosen integers 3, as our answer/
