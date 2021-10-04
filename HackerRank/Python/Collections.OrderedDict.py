# collections.OrderedDict

# An OrderedDict is a dictionary that remembers the order of the keys that were inserted first. If a new entry overwrites an existing entry, the original insertion position is left unchanged.

# Example

# Code

# >>> from collections import OrderedDict
# >>> 
# >>> ordinary_dictionary = {}
# >>> ordinary_dictionary['a'] = 1
# >>> ordinary_dictionary['b'] = 2
# >>> ordinary_dictionary['c'] = 3
# >>> ordinary_dictionary['d'] = 4
# >>> ordinary_dictionary['e'] = 5
# >>> 
# >>> print ordinary_dictionary
# {'a': 1, 'c': 3, 'b': 2, 'e': 5, 'd': 4}
# >>> 
# >>> ordered_dictionary = OrderedDict()
# >>> ordered_dictionary['a'] = 1
# >>> ordered_dictionary['b'] = 2
# >>> ordered_dictionary['c'] = 3
# >>> ordered_dictionary['d'] = 4
# >>> ordered_dictionary['e'] = 5
# >>> 
# >>> print ordered_dictionary
# OrderedDict([('a', 1), ('b', 2), ('c', 3), ('d', 4), ('e', 5)])

from collections import OrderedDict

N = int(input())
dictionary = OrderedDict()
for i in range(N):
    # print(dictionary)
    l = list(map(str, input().split()))
    if len(l) > 2:  # If l has more than 2 elements
        l[0] = ''.join(l[0]+' ' + l[1])
        l.remove(l[1]) # removing the 2nd element
        # print(l[0])
    if l[0] in dictionary:
        dictionary[l[0]] = int(dictionary[l[0]]) + int(l[1])  # Adding values in l to the dictionary
    else:
        dictionary[l[0]] = int(l[1])  # Adding values in l to dictionary
    
for keys in dictionary:
    print(keys, dictionary[keys])


# Sample Input
# 9
# BANANA FRIES 12
# POTATO CHIPS 30
# APPLE JUICE 10
# CANDY 5
# APPLE JUICE 10
# CANDY 5
# CANDY 5
# CANDY 5
# POTATO CHIPS 30

# Sample Output
# BANANA FRIES 12
# POTATO CHIPS 60
# APPLE JUICE 20
# CANDY 20
