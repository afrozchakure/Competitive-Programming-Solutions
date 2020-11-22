# Function Description
# Complete the bonAppetit function in the editor below. It should print Bon Appetit if the bill is fairly split. Otherwise, it should print the integer amount of money that Brian owes Anna.
# bonAppetit has the following parameter(s):
#     bill: an array of integers representing the cost of each item ordered
#     k: an integer representing the zero-based index of the item Anna doesn't eat
#     b: the amount of money that Anna contributed to the bill

import math
import os
import random
import re
import sys

# Complete the bonAppetit function below.
def bonAppetit(bill, k, b):
    bill.remove(bill[k])
    b_actual = sum(x for x in bill) / 2
    b_charged = b
    if b_actual == b_charged:
        print('Bon Appetit', end = '')  # if Brian did not overcharge
    else:
        print(int(b_charged - b_actual), end = '')  # Brian must refund to Anna

if __name__ == '__main__':
    nk = input().rstrip().split()

    n = int(nk[0]) # no. of items ordered

    k = int(nk[1])  # Index of the item Anna doesn't eat

    bill = list(map(int, input().rstrip().split()))  # cost of each item

    b = int(input().strip())  # Amount Anna contributes (charged by Brian)

    bonAppetit(bill, k, b)


# Output Format
# If Brian did not overcharge Anna, print Bon Appetit on a new line; otherwise, print the difference (i.e. b_charged - b_actual) that Brian must refund to Anna. This will always be an integer.

# Sample Input 0
# 4 1
# 3 10 2 9
# 12

# Sample Output 0
# 5

# Sample Input 1
# 4 1
# 3 10 2 9
# 7

# Sample Output 1
# Bon Appetit


