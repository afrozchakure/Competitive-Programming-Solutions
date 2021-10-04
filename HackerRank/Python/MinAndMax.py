import numpy as np

l = []
n, m = list(map(int, input().split()))
for i in range(n):
    j = list(map(int, input().split()))
    l.append(j)
l = np.array(l)
# print(l)
print(np.max(np.min(l, axis=1)))
