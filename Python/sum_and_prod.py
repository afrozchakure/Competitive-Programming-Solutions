import numpy as np

list_append = []

num, m = list(map(int, input().split()))
import pdb; pdb.set_trace()
for i in range(num):
    a_a = list(map(int, input().split()))
    list_append.append(a_a)
print(np.prod(np.sum(list_append,axis = 0), axis = None))


# n - next line
# c - full execute 
# l - whole code execute