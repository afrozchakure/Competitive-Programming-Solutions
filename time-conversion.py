#!/bin/python3

import os
import sys

#
# Complete the timeConversion function below.
#
def timeConversion(s):
    hours = s[0:2]
    hours_am = '00'
    hours_pm = '12'
    if s[8:] == 'PM':
        if s[:8] == '12:00:00':
            return '12:00:00'
        elif s[:2] == '12':
            return hours_pm + s[2:8] 
        else:
            hours = int(hours) + 12
            return str(hours) + s[2:8]
    elif s[8:] == 'AM':
        if s[:8] == '12:00:00':
            return '00:00:00'
        elif s[0:2] == '12':
            return hours_am + s[2:8] 
        else:
            return s[:8]

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    f.write(result + '\n')

    f.close()
