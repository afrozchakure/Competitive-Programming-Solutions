#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the viralAdvertising function below.
def viralAdvertising(n):
    # floor(5/2) 
    liked = math.floor(5/2)
    cumu = math.floor(5/2)
    shared = 5
    print(shared)
    for i in range(2,n+1):
        shared = math.floor(shared/2) * 3
        liked = math.floor(shared/2)
        cumu += liked
        print('Liked:',liked)
        print('shared', shared)
        print('cumu:',cumu)
    return cumu

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    result = viralAdvertising(n)

    fptr.write(str(result) + '\n')

    fptr.close()

# Day Shared Liked Cumulative
# 1      5     2       2
# 2      6     3       5
# 3      9     4       9
# 4     12     6      15
# 5     18     9      24

# Output Format
# Print the number of people who liked the advertisement during the first n days.

# Sample Input
# 3

# Sample Output
# 9
