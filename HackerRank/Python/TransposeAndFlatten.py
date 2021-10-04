# Transpose
# We can generate the transposition of an array using the tool numpy.transpose.
# It will not affect the original array, but it will create a new array.

# import numpy
# my_array = numpy.array([[1,2,3],
#                         [4,5,6]])
# print numpy.transpose(my_array)

# #Output
# [[1 4]
#  [2 5]
#  [3 6]]

# Flatten
# The tool flatten creates a copy of the input array flattened to one dimension.

# import numpy
# my_array = numpy.array([[1,2,3],
#                         [4,5,6]])
# print my_array.flatten()

# #Output
# [1 2 3 4 5 6]

# Task
# You are given a N X M integer array matrix with space separated elements ( N = rows and M = columns).
# Your task is to print the transpose and flatten results.


# Method 1:
import numpy

N, M = list(map(int, input().split()))

final_list = [input().split() for i in range(N)]
# print(final_list)
my_array = numpy.array(final_list, int)
print(numpy.transpose(my_array))
print(my_array.flatten())

# Method 2:
import numpy as np

N, M = list(map(int, input().split()))
my_array = np.array([input().split() for x in range(N)], int)  # Creating an array of input nos.
print(np.transpose(my_array))
print(my_array.flatten())

# Input Format
# The first line contains the space separated values of N and M.
# The next N lines contains the space separated elements of M columns.

# Output Format
# First, print the transpose array and then print the flatten.

# Sample Input
# 2 2
# 1 2
# 3 4

# Sample Output
# [[1 3]
#  [2 4]]
# [1 2 3 4]


