#!/bin/python3

import math
import os
import random
import re
import sys

# Function Description
# Complete the countingValleys function in the editor below. It must return an integer that denotes the number of valleys Gary traversed.
# countingValleys has the following parameter(s):
#     n: the number of steps Gary takes
#     s: a string describing his path

# Complete the countingValleys function below.
def countingValleys(n, s):
    count = 0
    count_valley = 0
    for i in s:       
        if i == 'U':
            count += 1
        elif i == 'D':
            count -= 1
        if count == 0 and i == 'U':
            count_valley += 1
    return count_valley
        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())  # No. of steps taken

    s = input()  # String describing Gary's path

    result = countingValleys(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()

# Output Format
# Print a single integer that denotes the number of valleys Gary walked through during his hike.

# Sample Input
# 8
# UDDDUDUU

# Sample Output
# 1

# Explanation
# If we represent _ as sea level, a step up as /, and a step down as \, Gary's hike can be drawn as:
# _/\      _
#    \    /
#     \/\/
# He enters and leaves one valley.
