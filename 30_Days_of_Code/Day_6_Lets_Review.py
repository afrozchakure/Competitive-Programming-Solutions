# Task
# Given a string, S, of length N that is indexed from 0 to N-1, print its even-indexed and odd-indexed characters 
# as 2 space-separated strings on a single line (see the Sample below for more detail).
# Note: 0 is considered to be an even index.

# Input Format
# The first line contains an integer, T (the number of test cases).
# Each line i of the subsequent lines contain a String, S. 

T = int(input())
for i in range(T):
    s = str(input())
    even = [s[i] for i in range(0,len(s), 2)]
    odd = [s[i] for i in range(1, len(s), 2)]
    even = ''.join(even)
    odd = ''.join(odd)
    print("{} {}".format(even, odd))

# Sample Input
# 2
# Hacker
# Rank

# Sample Output
# Hce akr
# Rn ak

