#!/bin/python3

# Task
# Given set S = {1, 2, 3,...,N}. Find two integers, A and B (where A < B),
# from set S such that the value of A&B is the maximum possible and also less than
# a given integer, K. In this case, & represents the bitwise AND operator.

def max_bit(num, limit):
    maximum_bit = 0
    if bin(limit)[-1] == '1':
        return limit - 1
    else:
        for i in range(1, num):
            for j in range(i + 1, num + 1):
                diff_bit = i & j
                if diff_bit >= limit:  # If the add operation gives diff_bit greater than k
                    return maximum_bit
                if diff_bit > maximum_bit:  # When diff_bit is greater than maxBit
                    maximum_bit = diff_bit
    return maximum_bit


t = int(input().strip())
for _ in range(t):
    n, k = input().strip().split(' ')
    n, k = [int(n), int(k)]
    print(max_bit(n, k))


# Output Format
# Print a single base-10 integer denoting the maximum number of 
# consecutive 1's in the binary representation of n.

# Sample Input 1
"""
3
5 2
8 5
2 2
"""
# Sample Output 1
"""
1
4
0
"""
