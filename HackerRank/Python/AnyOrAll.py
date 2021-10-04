
# any()

# This expression returns True if any element of the iterable is true.
# If the iterable is empty, it will return False.

# Code

# >>> any([1>0,1==0,1<0])
# True
# >>> any([1<0,2<1,3<2])
# False

# -------------------------------------------

# all()

# This expression returns True if all of the elements of the iterable are true. 
# If the iterable is empty, it will return True. 

# Code

# >>> all(['a'<'b','b'<'c'])
# True
# >>> all(['a'<'b','c'<'b'])
# False

def check_palindrome(n):
    rev = 0  # check the reverse of the no.
    t = int(n)  # assigning n to temp
    while t > 0:
        rev = rev * 10 + t % 10
        t = int(t / 10)
    if rev == n:
        return True
    return False

if __name__ == '__main__':        
    N = int(input())  # N is total no. of integers in list
    N_elements = set(map(int, input().split()))  # set of elements
    count = 0
    for x in N_elements:  # Iterating through list
        if x <= 0:  # If x is less than 0
            count = - 999
        if all([check_palindrome(x) == True, x >= 0] ):
            count += 1
    if count > 0:
        print(True, end = '')
    else:
        print(False, end = '')  # Prints false

# Input:
# 5
# 12 9 61 5 14

# Output:
# True

# Alternate solution (Much faster execution)

# n = int(input())
# arr = input().split(" ")
# print(all(int(i)>=0 for i in arr) and any(i == i[::-1]for i in arr))

