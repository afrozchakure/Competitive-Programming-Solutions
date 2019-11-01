# Output Format
# Print the three most common characters along with their occurrence count each on a separate line.
# Sort output in descending order of occurrence count.
# If the occurrence count is the same, sort the characters in alphabetical order.

#!/bin/python3

import math
import os
import random
import re
import sys

# Three most common characters repeated in lowercase letters
# Sort in descending order of occurence count
# if occurrence count is same, sort the character in alphabetical order
def takeSecond(elem):
    return elem[1]

if __name__ == '__main__':
    s = list(input())
    # print(s)
    s_set = set(s)
    s_set = sorted(s_set)  # To sort values in a set <-- Use this <------
    # print(s_set)
    s_list = [[x,s.count(x)] for x in s_set]
    s_list.sort(key = takeSecond, reverse = True)  # It applies the takeSecond function to it to sort using the 2nd element in array
    
    for x, y in s_list[0:3]:
        print(x, y)
        
    
# Sample Input 0
# aabbbccde

# Sample Output 0
# b 3
# a 2
# c 2

