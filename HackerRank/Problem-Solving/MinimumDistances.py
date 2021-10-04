# We define the distance between two array values as the number of indices between the two values. 
# Given a, find the minimum distance between any pair of equal elements in the array. If no such 
# value exists, print -1.

# For example, if a = [3,2,1,2,3], there are two matching pairs of values: 3 and 2. 
# The indices of the 3's are i = 0 and j = 4, so their distance is d[i,j] = |j - i| = 4. 
# The indices of the 2's are i = 1 and j = 3, so their distance is d[i, j] = |j - i| = 2.

# Function Description

# Complete the minimumDistances function in the editor below. It should return 
# the minimum distance between any two matching elements.
# minimumDistances has the following parameter(s):

# 1. a: an array of integers

# Input Format

# The first line contains an integer n, the size of array a.
# The second line contains n space-separated integers a[i].

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumDistances function below.
def minimumDistances(a):
    min = 1000
    for i in range(len(a)):
        for j in range(i+1, len(a)):
            if a[i] == a[j]:
                print(i," ", j)
                diff = abs(j - i)
                if min > diff:
                    min = diff 
    if min == 1000:
        return -1
    return min

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    a = list(map(int, input().rstrip().split()))

    result = minimumDistances(a)

    fptr.write(str(result) + '\n')

    fptr.close()

# Output Format
# Print a single integer denoting the minimum d[i, j] in a. If no such value exists, print -1.

# Sample Input
# 6
# 7 1 3 4 1 7

# Sample Output
# 3

# Explanation
# Here, we have two options:
# a[1] and a[4] are both 1, so d[1,4] = |1 - 4| = 3.
# a[0] and a[5] are both 7, so d[0,5] = |0 - 5| = 5.

# The answer is min(3, 5) = 3.