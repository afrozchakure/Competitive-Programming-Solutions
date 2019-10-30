# Function Description

# Complete the getMoneySpent function in the editor below. It should return the maximum total price for the two items within Monica's budget, or
# - 1 if she cannot afford both items.

# getMoneySpent has the following parameter(s):

#     keyboards: an array of integers representing keyboard prices
#     drives: an array of integers representing drive prices
#     b: the units of currency in Monica's budget

#!/bin/python3

import os
import sys

#
# Complete the getMoneySpent function below.
#
def getMoneySpent(keyboards, drives, b):
    sum = 0
    for i in keyboards:
        for j in drives:
            if (i + j) <= b  and (i + j) > sum:
                sum = i + j
    if sum == 0:
        return -1
    return sum
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    bnm = input().split()

    b = int(bnm[0])  # amount she has

    n = int(bnm[1])  # prices for keyboards
 
    m = int(bnm[2])  # prices for drives

    keyboards = list(map(int, input().rstrip().split()))  # prices for keyboards

    drives = list(map(int, input().rstrip().split()))  # prices for drives

    #
    # The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
    #

    moneySpent = getMoneySpent(keyboards, drives, b)

    fptr.write(str(moneySpent) + '\n')

    fptr.close()


# Sample Input 0
# 10 2 3
# 3 1
# 5 2 8

# Sample Output 0
# 9

# Explanation 0
# She can buy the 2nd keyboard and the 3rd USB drive for a total cost of 8 + 1 = 9.

# Sample Input 1
# 5 1 1
# 4
# 5

# Sample Output 1
# -1

# Explanation 1
# There is no way to buy one keyboard and one USB drive because
# 4 + 5 > 5, so we print -1.
