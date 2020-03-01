import numpy as np

l = []
n, m = (map(int, input().split()))
for i in range(n):
    a = list(map(int, input().split()))
    l.append(a)
print(np.prod(np.sum(l,axis = 0), axis = None))
