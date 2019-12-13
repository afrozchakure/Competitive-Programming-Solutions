# Julius Caesar protected his confidential information by encrypting it using a cipher. 
# Caesar's cipher shifts each letter by a number of letters. If the shift takes you past the 
# end of the alphabet, just rotate back to the front of the alphabet. 
# In the case of a rotation by 3, w, x, y and z would map to z, a, b and c.

# Original alphabet:      abcdefghijklmnopqrstuvwxyz
# Alphabet rotated +3:    defghijklmnopqrstuvwxyzabc

# Function Description
# Complete the caesarCipher function in the editor below. It should return the encrypted string.

# caesarCipher has the following parameter(s):
# 1. s: a string in cleartext
# 2. k: an integer, the alphabet rotation factor

# Input Format
# The first line contains the integer, n, the length of the unencrypted string.
# The second line contains the unencrypted string, s.
# The third line contains k, the number of letters to rotate the alphabet by.

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the caesarCipher function below.
def caesarCipher(s, k):
    a = "abcdefghijklmnopqrstuwvxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    l = []
    k = k % 26
    for i in s:
        if(i in a and ord(i) in range(97, 123)) :
            mod_val = 96 + ((ord(i) + k) % 96 )
            if mod_val > 122:
                mod_val = 96 + (mod_val % 122)
                l.append(chr(mod_val))
            else:
                l.append(chr(mod_val))
        if(i in a and ord(i) in range(65, 91)):
            mod_val = 64 + ((ord(i) + k ) % 64)
            if mod_val > 90:
                mod_val = 64 + (mod_val % 90)
                l.append(chr(mod_val))
            else:
                l.append(chr(mod_val))
        if(i not in a):
            l.append(i)
    str = ''.join(l)
    return str


            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    k = int(input())

    result = caesarCipher(s, k)

    fptr.write(result + '\n')

    fptr.close()

# Output Format
# For each test case, print the encoded string.

# Sample Input
# 11
# middle-Outz
# 2

# Sample Output
# okffng-Qwvb

# Explanation
# Original alphabet:      abcdefghijklmnopqrstuvwxyz
# Alphabet rotated +2:    cdefghijklmnopqrstuvwxyzab

# m -> o
# i -> k
# d -> f
# d -> f
# l -> n
# e -> g
# -    -
# O -> Q
# u -> w
# t -> v
# z -> b