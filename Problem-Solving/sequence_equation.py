# Given a sequence of n integers, p(1), p(2),..., p(n) where each element is distinct and satisfies 1<=p(x)<=n. 
# For each x where 1 <= x <= n, find any integer y such that p(p(y)) = x and print the value of y on a new line.

# For example, assume the sequence p = [5,2,1,3,4]. Each value of between 1 and 5, 
# the length of the sequence, is analyzed as follows:

# x = 1 = p[3], p[4] = 3, so p[p[4]] = 1, 
# x = 2 = p[2], p[2] = 2, so p[p[2]] = 2, 
# x = 3 = p[4], p[5] = 4, so p[p[5]] = 3, 
# x = 4 = p[5], p[1] = 5, so p[p[1]] = 4, 
# x = 5 = p[1], p[3] = 1, so p[p[3]] = 5, 

# The values for y are [4,2,5,1,3]

# Function Description

# Complete the permutationEquation function in the editor below. It should return an array of integers 
# that represent the values of y.
# permutationEquation has the following parameter(s):
#     p: an array of integers

# Input Format
# The first line contains an integer n, the number of elements in the sequence.
# The second line contains n space-separated integers p[i] where 1 <= i <= n.

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the permutationEquation function below.
def permutationEquation(p):
    p_i_index = []
    p_i_value = []
    for i in range(1, len(p)+1):
        p_i_index.append(p.index(i) + 1)
    # for i in p_i_index:
    print(p_i_index)
    for i in p_i_index:
        p_i_value.append(p.index(i) + 1)
    print(p_i_value)
    return p_i_value

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    p = list(map(int, input().rstrip().split()))

    result = permutationEquation(p)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

# Output Format
# For each x from 1 to n, print an integer denoting any y valid satisfying the equation p(p(y)) = x
# on a new line.

# Sample Input 0
# 3
# 2 3 1

# Sample Output 0
# 2
# 3
# 1

# Explanation 0
# Given the values of p(1) = 2, p(2) = 3, and p(3) = 1
# we calculate and print the following values for each x from 1 to n:

# x = 1 = p(3) = p(p(2)) = p(p(y)), so we print the value of y = 2 on a new line.
# x = 2 = p(1) = p(p(3)) = p(p(y)), so we print the value of y = 3 on a new line.
# x = 3 = p(2) = p(p(1)) = p(p(y)), so we print the value of y = 1 on a new line.