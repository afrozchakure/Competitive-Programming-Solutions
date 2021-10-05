#!/bin/python3

import math
import os
import random
import re
import sys

# Complete lesthe breakingRecords function below.
def breakingRecords(scores):
    count_high = 0
    count_low = 0
    highest_score = scores[0]
    lowest_score = scores[0]
    for i in range(1, len(scores)):
        if scores[i] > highest_score:
            highest_score = scores[i]
            count_high += 1
        elif scores[i] < lowest_score:
            lowest_score = scores[i]
            count_low += 1
    return count_high, count_low

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())  # No. of games

    scores = list(map(int, input().rstrip().split()))  # game scores

    result = breakingRecords(scores)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

# Output Format
# Print two space-seperated integers describing the respective 
# numbers of times her best (highest) score increased and her worst (lowest) score decreased.

# Sample Input 0
# 9
# 10 5 20 20 4 5 2 25 1

# Sample Output 0
# 2 4

