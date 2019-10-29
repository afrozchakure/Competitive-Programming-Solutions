#!/bin/python3

# Function Description
# Complete the pageCount function in the editor below. It should return the minimum number of pages Brie must turn.
# pageCount has the following parameter(s):
#     n: the number of pages in the book
#     p: the page number to turn to

import os
import sys

def pageCount(n, p):
    if n//2 - p// 2 >  p//2 :  # Page_count from last is greater
        return (p//2)
    else:
        return (n//2 - p//2)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())  # Total no. of pages

    p = int(input())  # Page she wants to arrive

    result = pageCount(n, p)

    fptr.write(str(result) + '\n')

    fptr.close()

# Output Format

# Print an integer denoting the minimum number of pages Brie must turn to get to page p. 

# Sample Input 0
# 6
# 2

# Sample Output 0
# 1

# Sample Input 1
# 5
# 4

# Sample Output 1
# 0


