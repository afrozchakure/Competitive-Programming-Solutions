# reduce() in Python :
# The reduce(fun,seq) function is used to apply a particular function passed in its argument to 
# all of the list elements mentioned in the sequence passed along.This function is defined in “functools” module.


# Tasks : 
# You will be given two arrays of integers and asked to determine all integers that satisfy the following two conditions:
#     1. The elements of the first array are all factors of the integer being considered
#     2. The integer being considered is a factor of all elements of the second array
# These numbers are referred to as being between the two arrays. You must determine how many such numbers exist.

from functools import reduce
import math 

def getTotalX(a, b):
    lcm_a = reduce(lambda x,y: x*y//math.gcd(x,y), a)  # Calculating the lcm for array a
    gcd_b = reduce(math.gcd, b)  # Calculating the GCD for array b
    return (sum(gcd_b%x==0 for x in range(lcm_a,gcd_b+gcd_b,lcm_a)))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])  # no. of elelments in a

    m = int(first_multiple_input[1])  # no. of elements in b

    arr = list(map(int, input().rstrip().split()))  # elements in a[i]

    brr = list(map(int, input().rstrip().split()))  # elements in b[j]

    total = getTotalX(arr, brr)  
    
    fptr.write(str(total) + '\n')

    fptr.close()

# Sample Input
# 2 3
# 2 4
# 16 32 96

# Sample Output
# 3

# Explanation
# 2 and 4 divide evenly into 4, 8, 12 and 16.
# 4, 8 and 16 divide evenly into 16, 32, 96.
# 4, 8 and 16 are the only three numbers for which each element of a is a factor and each is a factor of all elements of b. 