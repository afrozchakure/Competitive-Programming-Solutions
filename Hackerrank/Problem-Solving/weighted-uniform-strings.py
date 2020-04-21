#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the weightedUniformStrings function below.
def weightedUniformStrings(s, queries):
    prev = -1
    length = 0
    weights = set()
    for x in s:
        weight = ord(x) - ord('a') + 1
        weights.add(weight)
        if x == prev:
            length += 1
            weights.add(weight * length)
        else:
            prev = x
            length = 1

    list_l = []
    for c in queries:
        if c in weights:
            list_l.append('Yes')
        else:
            list_l.append('No')
    
    return list_l

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    queries_count = int(input())

    queries = []

    for _ in range(queries_count):
        queries_item = int(input())
        queries.append(queries_item)

    result = weightedUniformStrings(s, queries)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()


# Input

# abccddde
# 6
# 1
# 3
# 12
# 5
# 9
# 10

# Output

# Yes
# Yes
# Yes
# Yes
# No
# No