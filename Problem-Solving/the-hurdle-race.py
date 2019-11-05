#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the hurdleRace function below.
def hurdleRace(k, height):
    max_height = max(height)
    if k > max_height:
        return 0
    return (max_height - k)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    nk = input().split()
    n = int(nk[0])
    k = int(nk[1])
    height = list(map(int, input().rstrip().split()))
    result = hurdleRace(k, height)
    fptr.write(str(result) + '\n')
    fptr.close()

# Output Format
# Print an integer denoting the minimum doses of magic potion Dan must drink to complete the hurdle race.

# Sample Input 0
# 5 4
# 1 6 3 5 2

# Sample Output 0
# 2

