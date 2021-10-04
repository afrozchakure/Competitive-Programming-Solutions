# You are given a function f(X) = X**2. You are also given K lists. The ith list consists of Ni elements.
# You have to pick one element from each list so that the value from the equation below is maximized:
# S = (f(x1) + f(x2) + .... + f(xk)) % M

# Xi denotes the element picked from the ith list. Find the maximized value Smax obtained.

# % denotes the modulo operator.

# Note that you need to take exactly one element from each list, not necessarily the largest element. 
# You add the squares of the chosen elements and perform the modulo operation. The maximum value that you can obtain, 
# will be the answer to the problem.

# Input Format
# The first line contains 2 space separated integers K and M.
# The next K lines each contains an integer Ni, denoting the number of elements in the ith list, 
# followed by Ni space separated integers denoting the elements in the list. 

from itertools import product # It gives the cartesian product of elements

K, M = list(map(int,input().split()))

N = (list(map(int, input().split()))[1:] for i in range(K))
# print(list(N))  # Printing elements in multiple lists
# print(list(product(*N)))  # Printing the Cartesian product of elements in N

results = map(lambda x: sum(i**2 for i in x)%M, product(*N))
# print(list(results)) # Printing the list of results
print(max(results))  # Taking the maximum out of the results

# Output Format
# Output a single integer denoting the value Smax.

# Sample Input
# 3 1000
# 2 5 4
# 3 7 8 9 
# 5 5 7 8 9 10 

# Sample Output
# 206

# Explanation
# Picking 5 from the 1st list, from the 2nd list and from the 3rd list gives the maximum S value 
# equal to (5^2 + 9^2 + 10^2) % 1000 = 206. 