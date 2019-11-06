# The Utopian Tree goes through 2 cycles of growth every year. Each spring, it doubles in height. Each summer, its height increases by 1 meter.
# Laura plants a Utopian Tree sapling with a height of 1 meter at the onset of spring. How tall will her tree be after n growth cycles?
# For example, if the number of growth cycles is n = 5, the calculations are as follows:

# Period  Height
# 0          1
# 1          2
# 2          3
# 3          6
# 4          7
# 5          14


import math
import os
import random
import re
import sys

# Complete the utopianTree function below.
def utopianTree(n):
    # Each spring it doubles in height
    # Each summer, its height increases by 1 meter
    height = 0
    for i in range(n+1):
        if i == 0:
            height = 1
        elif i%2 == 1:  # 1,3,5
            height =  height * 2 
        else:
            height += 1
    return height

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())  # The no. of test cases

    for t_itr in range(t):
        n = int(input())  # no. of cycles for test case

        result = utopianTree(n)

        fptr.write(str(result) + '\n')

    fptr.close()

# Output Format
# For each test case, print the height of the Utopian Tree after n
# cycles. Each height must be printed on a new line.

# Sample Input
# 3
# 0
# 1
# 4

# Sample Output
# 1
# 2
# 7
