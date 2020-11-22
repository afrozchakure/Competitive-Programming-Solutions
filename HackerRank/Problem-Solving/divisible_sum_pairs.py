#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the divisibleSumPairs function below.
def divisibleSumPairs(n, k, ar):
    count = 0
    for i in range(len(ar)):
        for j in range(len(ar)):
            if i != j and i < j :
                if (ar[i] + ar[j]) % k == 0:
                    count += 1
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])  # value of n

    k = int(nk[1])  # value of k

    ar = list(map(int, input().rstrip().split()))  # The array

    result = divisibleSumPairs(n, k, ar)

    fptr.write(str(result) + '\n')

    fptr.close()

# Sample Input
# 6 3
# 1 3 2 6 1 2

# Sample Output
# 5
