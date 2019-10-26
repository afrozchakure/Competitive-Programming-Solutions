# inner
# The inner tool returns the inner product of two arrays.

# import numpy
# A = numpy.array([0, 1])
# B = numpy.array([3, 4])
# print numpy.inner(A, B)     #Output : 4

# outer
# The outer tool returns the outer product of two arrays.

# import numpy
# A = numpy.array([0, 1])
# B = numpy.array([3, 4])
# print numpy.outer(A, B)     #Output : [[0 0]
#                             #          [3 4]]

# Task :
# You are given two arrays:
# and .
# Your task is to compute their inner and outer product.

import numpy as np

a = list(map(int, raw_input().split()))
b = list(map(int, raw_input().split()))
a = np.array(a)
b = np.array(b)

print(np.inner(a,b))
print(np.outer(a,b))

# Sample Input
# 0 1
# 2 3

# Sample Output
# 3
# [[0 0]
#  [2 3]]
