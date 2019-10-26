# dot
# The dot tool returns the dot product of two arrays.

# import numpy
# A = numpy.array([ 1, 2 ])
# B = numpy.array([ 3, 4 ])
# print numpy.dot(A, B)       #Output : 11

# cross
# The cross tool returns the cross product of two arrays.

# import numpy
# A = numpy.array([ 1, 2 ])
# B = numpy.array([ 3, 4 ])
# print numpy.cross(A, B)     #Output : -2

# Task:
# You are given two arrays
# and . Both have dimensions of X.
# Your task is to compute their matrix product.

import numpy as np

N = int(raw_input())
A = []
B = []
for i in range(N):
    A.append(map(int,raw_input().split()))
A = np.array(A).reshape(N, N)
for i in range(N):
    B.append(map(int,raw_input().split()))
B = np.array(B).reshape(N, N)
C = []
for i in range(N*N):
    C.append(0)
C = np.array(C).reshape(N,N)
for i in range(N):
    for j in range(N):
        for k in range(N):
            C[i][j] += A[i][k] * B[k][j]
print(C)

# Sample Input
# 2
# 1 2
# 3 4
# 1 2
# 3 4

# Sample Output
# [[ 7 10]
#  [15 22]]

