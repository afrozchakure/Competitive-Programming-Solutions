# Lily likes to play games with integers. She has created a new game where she determines the difference between a number and its reverse. 
# For instance, given the number 12, its reverse is 21. Their difference is 9. The number 120 reversed is 21, and their difference is 99.

# She decides to apply her game to decision making. She will look at a numbered range of days and will only go to a movie on a beautiful day.
# Given a range of numbered days, [i...j]
# and a number k, determine the number of days in the range that are beautiful. Beautiful numbers are defined as numbers where |i - reverse(i)| is evenly divisible by k. If a day's value is a beautiful number, it is a beautiful day. Print the number of beautiful days in the range.

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the beautifulDays function below.
def beautifulDays(i, j, k):
    count = 0
    for m in range(i, j+1):
        temp = list(str(m))
        temp.reverse()
        temp = int(''.join(temp))
        print(temp)
        if ((m - temp)/k ) == int((m - temp)/k):
            count += 1
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ijk = input().split()

    i = int(ijk[0])

    j = int(ijk[1])

    k = int(ijk[2])

    result = beautifulDays(i, j, k)

    fptr.write(str(result) + '\n')

    fptr.close()

# Output Format
# Print the number of beautiful days in the inclusive range between i and j.

# Sample Input
# 20 23 6

# Sample Output
# 2

