# Alice wrote a sequence of words in CamelCase as a string 
# of letters, s, having the following properties:

# 1. It is a concatenation of one or more words consisting of English letters.
# 2. All letters in the first word are lowercase.
# 3. For each of the subsequent words, the first letter is uppercase and rest of the letters are lowercase.

# Given s, print the number of words in s on a new line.

# For example, s = oneTwoThree. There are 3 words in the string.

# Function Description
# Complete the camelcase function in the editor below. 
# It must return the integer number of words in the input string.
# camelcase has the following parameter(s):

# s: the string to analyze

# Input Format
# A single line containing string s.

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the camelcase function below.
def camelcase(s):
    count = 0
    if s =="":
        return count
    else:
        count += 1
    for i in s:
        if i.isupper() == True:
            count += 1
    return count
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = camelcase(s)

    fptr.write(str(result) + '\n')

    fptr.close()

# Output Format
# Print the number of words in string s.

# Sample Input
# saveChangesInTheEditor

# Sample Output
# 5

# Explanation
# String s contains five words:

# 1. save
# 2. Changes
# 3. In
# 4. The
# 5. Editor

# Thus, we print 5 on a new line.