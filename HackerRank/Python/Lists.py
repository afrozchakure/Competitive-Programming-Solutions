# Consider a list (list = []). You can perform the following commands:

# 1. insert i e: Insert integer e at position i.
# 2. print: Print the list.
# 3. remove e: Delete the first occurrence of integer.
# 4. append e: Insert integer e at the end of the list.
# 5. sort: Sort the list.
# 6. pop: Pop the last element from the list.
# 7. reverse: Reverse the list.

# Initialize your list and read in the value of n
# followed by n lines of commands where each command will be of the 7 types listed above. Iterate through each command in order and perform the corresponding operation on your list.


if __name__ == '__main__':
    N = int(input())
    l = []
    for i in range(N):
        a = input().split()
        if a[0] == 'insert':
           l.insert(int(a[1]), int(a[2]))
        elif a[0] == 'print':
            print(l)
        elif a[0] == 'remove':
            l.remove(int(a[1]))
        elif a[0] == 'append':
            l.append(int(a[1]))
        elif a[0] == 'sort':
            l.sort()
        elif a[0] == 'pop':
            l.pop()
        elif a[0] == 'reverse':
            l.reverse()

# Sample Input 0

# 12
# insert 0 5
# insert 1 10
# insert 0 6
# print
# remove 6
# append 9
# append 1
# sort
# print
# pop
# reverse
# print

# Sample Output 0

# [6, 5, 10]
# [1, 5, 9, 10]
# [9, 5, 1]

