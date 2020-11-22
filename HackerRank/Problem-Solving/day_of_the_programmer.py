#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the dayOfProgrammer function below.
def dayOfProgrammer(year):
    a = '12.09.'
    b = '13.09.'
    c = '26.09.'
    if year > 1918:
        if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
            print(a, year, sep = '' )
            return a + str(year)
        else:
            print(b, year, sep = '' )
            return b + str(year)
    elif year < 1918:
        if (year % 4 == 0):  # for leap year in gregorian calendar
            print(a, year, sep = '' )
            return a + str(year)
        else:
            print(b, year, sep = '' )
            return b + str(year)
    elif year == 1918:
        return c + str(year)
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    year = int(input().strip())

    result = dayOfProgrammer(year)

    fptr.write(result + '\n')

    fptr.close()

# Output Format
# Print the full date of Day of the Programmer during year
# in the format dd.mm.yyyy, where dd is the two-digit day, mm is the two-digit month, and yyyy is.

# Sample Input 0
# 2017

# Sample Output 0
# 13.09.2017

# Sample Input 1
# 2016

# Sample Output 1
# 12.09.2016

# Sample Input 2
# 1800

# Sample Output 2
# 12.09.1800

# Explanation 2
# Since 1800 is leap year. Day lies on 12 September.