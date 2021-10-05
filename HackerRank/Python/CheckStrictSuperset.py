def is_superset(A, B, count):
    if A == B or len(A) < len(B):
        count = count
    elif A.issuperset(B):
        count = count + 1
    return count

if __name__ == '__main__':
    A = set(map(int, input().split()))  # Set A elements
    n = int(input())  # no. of other sets
    count = 0
    for i in range(n):
        set_B = set(map(int, input().split()))
        count = is_superset(A, set_B, count)
    if count == n:
        print(True, end = '')
    else:
        print(False, end = '')

# Input
# 1 2 3 4 5 6 7 8 9 10 11 12 23 45 84 78
# 2
# 1 2 3 4 5
# 100 11 12

# Output
# False

# Strict superset
# Set([1,3,4]) is a strict superset of set([1,3]).
# Set([1,3,4]) is not a strict superset of set([1,3,4]).
# Set([1,3,4]) is not a strict superset of set([1,3,5]).