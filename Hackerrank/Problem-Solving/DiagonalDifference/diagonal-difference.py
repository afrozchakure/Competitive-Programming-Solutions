#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'diagonalDifference' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#


def diagonalDifference(arr):
    # Write your code here
    prim_diagonal = 0
    secondary_diagonal = 0
    for i in range(len(arr)):
        prim_diagonal = prim_diagonal + arr[i][i]

    for j in range(len(arr)):
        secondary_diagonal = secondary_diagonal + arr[len(arr)-j-1][j]
    return int(abs(prim_diagonal - secondary_diagonal))


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
