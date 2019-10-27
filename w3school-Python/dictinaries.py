# A dictionary is a collection which is unordered, changeable and indexed. 
# In Python dictionaries are written with curly brackets, and they have keys and values.

thisdict = {
    'brand': 'ford',
    'model': 'mustang',
    'year': '1964'
}
# print(thisdict)

# x = thisdict['model']
# x = thisdict.get('model')
# print(x)

# thisdict['year'] = 2018
# print(thisdict)

# for x in thisdict:  # Print all the key names in the dictinary
#     print(x)

# for x in thisdict:  # Print all the values in the dictionary
#     print(thisdict[x])

# for x in thisdict.values():  # You can also use the values() function to return values of a dictionary:
#     print(x)

# for x, y in thisdict.items():  # Loop through both keys and values by using the items() function
#     print(x, y)

# To determine if a specified key is present in a dictionary use the in keyword
# if 'model' in thisdict:
#     print("Yes, 'model' is one of the keys in the thisdict dictionary")

# print(len(thisdict))  # No. of items in the dictionary

# thisdict.pop('model')  # The pop() method removes the item with the specified key name
# print(thisdict)

# thisdict.popitem()  # The popitem() method removes the last inserted item
# print(thisdict)

# The del keyword removes the item with the specified key name:
# del thisdict['model']
# print(thisdict)

# del thisdict  # The del keyword can also delete the dictionary completely:

# thisdict.clear()  # The clear() keyword empties the dictionary:
# print(thisdict)


# You cannot copy a dictionary simply by typing dict2 = dict1, because: 
# dict2 will only be a reference to dict1, and changes made in dict1 will automatically also be made in dict2.
# There are ways to make a copy, one way is to use the built-in Dictionary method copy().
# mydict = thisdict.copy()
# print(mydict)

# Make a copy of a dictionary with the dict() method:
# mydict = dict(thisdict)
# print(mydict)


# A dictionary can also contain many dictionaries, 
# this is called nested dictionaries.
# myfamily = {
#     'child1': {
#         'name' : 'Emil',
#         'year' :  2004
#     },
#     'child2' : {
#         'name' : 'Tobias',
#         'year' : 2007
#     },
#     'child3' : {
#         'name' : 'Linus',
#         'year' : 2011
#     }
# }
# print(myfamily)


###### OR #######

# Create three dictionaries, than create one dictionary that will contain the other three dictionaries

# child1 = {
#     'name' : 'Emil',
#     'year' : 2004
# }
# child2 = {
#     'name' : 'Tobias',
#     'year' : 2007
# }
# child3 = {
#     'name ' : 'Linus',
#     'year' : 2011
# }

# myfamily = {
#     'child1' : child1,
#     'child2' : child2,
#     'child3' : child3
# }
# print(myfamily)

thisdict = dict(brand = 'Ford', model = 'Mustang', year = 2018)
print(thisdict)