#!/bin/python3

import math
import os
import random
import re
import sys
  
# M # No of attributes
# K # Sort the data on Kth attribute

if __name__ == '__main__':
    nm = input().split()

    n = int(nm[0])  # No. of rows

    m = int(nm[1])  # No. of columns (no. of attributes)

    arr = []  # For making a nested Lists

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split()))) # Stores in a nested list

    k = int(input())  # sort the data of kth column

    arr.sort(key = lambda x: x[k])  # for sorting the nested list based on a specific column 

    for i in range(n):
        for j in range(m):
            print(arr[i][j], end = ' ')
        print('\n', end = '')

    
# Input :

# 5 3
# 10 2 5
# 7 1 0
# 9 9 9
# 1 23 12
# 6 5 9
# 1

# Output :

# 7 1 0
# 10 2 5
# 6 5 9
# 9 9 9
# 1 23 12