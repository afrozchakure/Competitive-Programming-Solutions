class MyClass:
    x = 5

# Use the __init__() function to assign values to object properties

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def myfunc(self):
        print("Hello my name is " + self.name)

# The self parameter is a reference to the current instance 
# of the class, and is used to access variables that belongs to the class.

# It does not have to be named self , you can call it whatever you like, 
# but it has to be the first parameter of any function in the class:

class Person_1:
    def __init__(mysillyobject, name, age):   
        mysillyobject.name = name
        mysillyobject.age = age

    def myfunc(abc):
        print("Hello my name is " + abc.name)
if __name__ == '__main__':
    p1 = MyClass()
    print(p1.x)
    p2 = Person('John', 36)
    print(p2.name)
    print(p2.age)
    p2.myfunc()
    # Objects can also contain methods. Methods in objects are functions that belong to the object.
    p3 = Person_1('Monty', 12)
    p3.myfunc()
    p3.age = 50 # Modifying the age property of object
    del p3.age  # Deleting the age property
    del p3  # Deleting the object
    