#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the migratoryBirds function below.
def migratoryBirds(arr):
    count = 0
    id = 1
    for i in range(1,6):
        if arr.count(i) > count :
            count = arr.count(i)
            id = i
    return id

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = migratoryBirds(arr)

    fptr.write(str(result) + '\n')

    fptr.close()


# Output Format
# Print the type number of the most common bird; if two or more types of birds are equally common, choose the type with the smallest ID number.

# Sample Input 0
# 6
# 1 4 4 4 5 3

# Sample Output 0
# 4

