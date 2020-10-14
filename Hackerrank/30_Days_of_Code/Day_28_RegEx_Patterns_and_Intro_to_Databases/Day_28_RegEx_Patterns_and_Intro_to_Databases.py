#!/bin/python3

# Task
# Consider a database table, Emails, which has the attributes First Name and Email ID.
# Given N rows of data simulating the Emails table,
# print an alphabetically-ordered list of people whose email address ends in @gmail.com.

import math
import os
import random
import re
import sys


def compute(firstName, emailID, result):
    # restricted to lowercase letters and first name limit is 20 characters and whole email id limit is 50 characters
    match = re.search(r'[a-z]{,20}@gmail.com{,50}', emailID)
    if match:
        result.append(firstName)

if __name__ == '__main__':
    N = int(input())

    result = []
    for N_itr in range(N):
        firstNameEmailID = input().split()

        firstName = firstNameEmailID[0]

        emailID = firstNameEmailID[1]

        compute(firstName, emailID, result)
    result = sorted(result);
    for i in result:
        print(i)


# Input Format
# The first line contains an integer, N, total number of rows in the table.
# Each of the N subsequent lines contains 2 space-separated strings
# denoting a person's first name and email ID, respectively.

# Output Format
# Print an alphabetically-ordered list of first names for every user with a gmail account.
# Each name must be printed on a new line

# Sample Input 1
"""
6
riya riya@gmail.com
julia julia@julia.me
julia sjulia@gmail.com
julia julia@gmail.com
samantha samantha@gmail.com
tanya tanya@gmail.com
"""

# Sample Output 1
"""
julia
julia
riya
samantha
tanya
"""
