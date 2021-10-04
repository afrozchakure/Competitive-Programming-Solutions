# mean

# The mean tool computes the arithmetic mean along the specified axis.
# import numpy
# my_array = numpy.array([ [1, 2], [3, 4] ])
# print numpy.mean(my_array, axis = 0)        #Output : [ 2.  3.]
# print numpy.mean(my_array, axis = 1)        #Output : [ 1.5  3.5]
# print numpy.mean(my_array, axis = None)     #Output : 2.5
# print numpy.mean(my_array)                  #Output : 2.5

# var
# The var tool computes the arithmetic variance along the specified axis.
# import numpy
# my_array = numpy.array([ [1, 2], [3, 4] ])
# print numpy.var(my_array, axis = 0)         #Output : [ 1.  1.]
# print numpy.var(my_array, axis = 1)         #Output : [ 0.25  0.25]
# print numpy.var(my_array, axis = None)      #Output : 1.25
# print numpy.var(my_array)                   #Output : 1.25

# By default, the axis is None. Therefore, it computes the variance of the flattened array.

# std
# The std tool computes the arithmetic standard deviation along the specified axis.
# import numpy
# my_array = numpy.array([ [1, 2], [3, 4] ])
# print numpy.std(my_array, axis = 0)         #Output : [ 1.  1.]
# print numpy.std(my_array, axis = 1)         #Output : [ 0.5  0.5]
# print numpy.std(my_array, axis = None)      #Output : 1.11803398875
# print numpy.std(my_array)                   #Output : 1.11803398875

# By default, the axis is None. Therefore, it computes the standard deviation of the flattened array.

# Problem Statement:

# You are given a 2-D array of size X.
# Your task is to find:
# The mean along axis 
# The var along axis
# The std along axis 

import numpy as np

np.set_printoptions(legacy='1.13')
row, cols = map(int, raw_input().split())

l = []
for i in range(row):
    arr = list(map(float,raw_input().split()))
    l.append(arr)    
l = np.array(l).reshape(row, cols)
print(np.array(np.mean(l, axis = 1)))
print(np.array(np.var(l, axis = 0)))
a = np.array(np.std(l, axis = None))
print(a)

# Input :

# 2 2
# 1 2
# 3 4

# Output :

# [ 1.5  3.5]
# [ 1.  1.]
# 1.11803398875