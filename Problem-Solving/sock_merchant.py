#!/bin/python3

# Function Description
# Complete the sockMerchant function in the editor below. It must return an integer representing the number of matching pairs of socks that are available.
# sockMerchant has the following parameter(s):
#     n: the number of socks in the pile
#     ar: the colors of each sock

import math
import os
import random
import re
import sys

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    set_ar = set(ar)
    count = 0
    for i in set_ar:
        if ar.count(i) > 1:
            count += int(ar.count(i) / 2)
    return count
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())  # No. of socks in the pile

    ar = list(map(int, input().rstrip().split()))  # Color of each sock

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()

# Sample Input
# 9
# 10 20 20 10 10 30 50 10 20

# Sample Output
# 3
