#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the staircase function below.
def staircase(n):
    for i in range(n):
        print(' '*(n-i-1),end='')
        print("#"* (1+i)) 
            
if __name__ == '__main__':
    n = int(input())

    staircase(n)

# Staircase to return 

   #
  ##
 ###
####
