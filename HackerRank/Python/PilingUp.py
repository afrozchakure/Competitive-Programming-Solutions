# There is a horizontal row of n cubes. The length of each cube is given. 
# You need to create a new vertical pile of cubes. The new pile should follow these directions: 
# if cube_i is on top of cube_j then sideLength_j >- sideLength_i.

# When stacking the cubes, you can only pick up either the leftmost or the rightmost cube each time. 
# Print "Yes" if it is possible to stack the cubes. Otherwise, print "No". Do not print the quotation marks. 


# Enter your code here. Read input from STDIN. Print output to STDOUT

# vertical pile of cubes
# sidelength_j >= sidelength_i (if cube_i on top of cube_j)  
# larger length cube down

# Actual Solution (Does not require a deque() )

for _ in range(int(input())): 
    m, l = int(input()), [int(x) for x in input().split()]
    left = True
    valid = True
    
    for x in range(1,m):
        if left:
            if l[x] > l[x-1]:
                left = False
        else:
            if l[x] < l[x-1]:
                valid = False
    
    print("Yes" if valid else "No")

# Every valid input is going to look like a valley. 
# The center has to be the smallest number and the numbers before and after it all have to ascend.
# So, simply put, you traverse the list until you find the first number that is bigger than its predecessor. 
# This means the trend is now going up. If you find another that breaks this trend and is smaller than its predecessor, it's an invalid input.
# More technically, if you have any local minima, the case fails and if you have more than one local maximum it will fail as well.


# Fake Solution (Will work for the given Test Cases but not the actual solution)
from collections import deque

def stack(d,n):
    
    # for i in range(int(n/2)+1):
    if max(d) > d[0] and max(d) > d[-1]:
        return 'No'
    elif d[0] >=  d[-1] and max(d) <= d[0]:
        d.popleft() 
    elif d[-1] > d[0] and max(d) <= d[-1]:
        d.pop() 
    else:
        return ('No')
        # print(d)
    return ('Yes')

T = int(input())  # No. of test cases
for i in range(T):
    n = int(input())  # No. of cubes
    n_integers = list(map(int, input().split()))
    n_integers = deque(n_integers)
    status = stack(n_integers, n)
    print(status)

# Output Format
# For each test case, output a single line containing either "Yes" or "No" without the quotes.

# Sample Input
# 2
# 6
# 4 3 2 1 3 4
# 3
# 1 3 2

# Sample Output
# Yes
# No
