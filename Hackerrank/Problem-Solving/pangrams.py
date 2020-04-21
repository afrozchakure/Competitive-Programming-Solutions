#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the pangrams function below.
def pangrams(s):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    count = 0
    for i in alphabet:
        if i not in s.lower():
            count = count + 1
    if count > 0:
        return 'not pangram'
    else:
        return 'pangram'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = pangrams(s)

    fptr.write(result + '\n')

    fptr.close()
