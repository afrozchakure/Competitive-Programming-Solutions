#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the catAndMouse function below.
def catAndMouse(x, y, z):
    x_z = abs(x - z)
    y_z = abs(y - z)
    
    if x_z < y_z:
        return 'Cat A'
    elif y_z < x_z :
        return 'Cat B'
    else:
        return 'Mouse C'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())  # No. of queries

    for q_itr in range(q):
        xyz = input().split()  # Coordinates

        x = int(xyz[0]) # Cat A's location

        y = int(xyz[1])  # Cat B's location
 
        z = int(xyz[2])  # Mouse C's location

        result = catAndMouse(x, y, z)

        fptr.write(result + '\n')

    fptr.close()

# Sample Input 0
# 2
# 1 2 3
# 1 3 2

# Sample Output 0
# Cat B
# Mouse C

