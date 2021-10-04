#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the plusMinus function below.
def plusMinus(arr):
    pos = 0
    nega = 0
    zero = 0
    for x in arr:
        if x > 0 :
            pos += 1
        elif x < 0 :
            nega += 1
        else :
            zero +=1
    print("%.6f"%(pos/len(arr)))
    print("%.6f"%(nega/len(arr)))
    print("%.6f"%(zero/ len(arr)), end ='')    

if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
