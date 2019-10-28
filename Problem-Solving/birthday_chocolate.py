#!/bin/python3

import math
import os
import random
import re
import sys

# Function Description

# Complete the birthday function in the editor below. It should return an integer denoting the number of ways Lily can divide the chocolate bar.

# birthday has the following parameter(s):

#     s: an array of integers, the numbers on each of the squares of chocolate
#     d: an integer, Ron's birth day
#     m: an integer, Ron's birth month


# Complete the birthday function below.
def birthday(s, d, m):
    count = 0
    sum_l = 0
    if len(s) == 1:
        sum_l = s[0] 
        if sum_l == d:  # if sum is equal Ron's day
            count += 1
    elif len(s) == 2:
        sum_l = s[0] + s[1]
        if sum_l == d:  # if sum is equal Ron's day
            count += 1
    elif len(s) > 2:
        for i in range(len(s) - m+1):
            sum_l = sum(s[i:i+m])  # Adding values each time
            if sum_l == d:  # if sum is equal to Ron's day
                count += 1
                sum_l = 0
    return count      

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())  # no. of squares in the chocolate bar

    s = list(map(int, input().rstrip().split()))  # no. on each of the squares of chocolate

    dm = input().rstrip().split()

    d = int(dm[0])  # birth day

    m = int(dm[1])  # birth month

    result = birthday(s, d, m)

    fptr.write(str(result) + '\n')

    fptr.close()


# Output Format
# Print an integer denoting the total number of ways that Lily can portion her chocolate bar to share with Ron.

# Sample Input 0
# 5
# 1 2 1 3 2
# 3 2

# Sample Output 0
# 2

