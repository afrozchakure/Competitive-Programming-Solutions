#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countApplesAndOranges function below.
def countApplesAndOranges(s, t, a, b, apples, oranges):
    count_apples = count_oranges = 0
    for i in range(len(apples)):
        apples[i] += a
    for j in range(len(oranges)):
        oranges[j] += b 
    for i in apples:
        if i in range(s,t+1):
            count_apples += 1
    for j in oranges:
        if j in range(s,t+1):
            count_oranges += 1
    
    print(count_apples)
    print(count_oranges, end = '')
    

if __name__ == '__main__':
    st = input().split()  # respective values of s and t

    s = int(st[0])  # location of san's house

    t = int(st[1])  # ending location of house

    ab = input().split()

    a = int(ab[0])  # location of apple tree

    b = int(ab[1])  # location of orange tree

    mn = input().split()

    m = int(mn[0])  # no. of apples falling from point a
 
    n = int(mn[1])  # no. of oranges falling from point b

    apples = list(map(int, input().rstrip().split()))  # distances of apples
    
    oranges = list(map(int, input().rstrip().split()))
    
    countApplesAndOranges(s, t, a, b, apples, oranges)


# Input :

# 7 11
# 5 15
# 3 2
# -2 2 1
# 5 -6

# Output :

# 1
# 1