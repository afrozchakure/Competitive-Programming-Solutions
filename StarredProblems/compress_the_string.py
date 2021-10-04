# In this task, we would like for you to appreciate the usefulness of 
# the groupby() function of itertools.

# You are given a string S. Suppose a character 'c' occurs consecutively X times 
# in the string. Replace these consecutive occurrences of the character 'c' with (X, c) 
# in the string. 

# Input Format
# A single line of input consisting of the string S.

# Output Format
# A single line of output consisting of the modified string.

from itertools import groupby
S = str(input())

x = [(len(list(g)), int(k)) for k, g in groupby(S)]
for i in x:
    print(i, end = " ")

# Sample Input
# 1222311

# Sample Output
# (1, 1) (3, 2) (1, 3) (2, 1)

# Explanation
# First, the character 1 occurs only once. It is replaced by (1,1). Then the character 2 occurs three times, and it 
# is replaced by (3,2) and so on.

# Also, note the single space within each compression and between the compressions. 