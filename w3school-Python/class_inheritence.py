class Person:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname
    def printname(self):
        print(self.firstname, self.lastname)

# The child's __init__() function overrides the 
# inheritance of the parent's __init__() function.

# To keep the inheritance of the parent's __init__() 
# function, add a call to the parent's __init__() function:

class Student(Person):
    def __init__(self, fname, lname):
        Person.__init__(self, fname, lname)  # Person takes self parameter
        self.graduationyear = 2019

# By using the super() function, you do not have to use the name 
# of the parent element, it will automatically inherit the methods and properties from its parent.

class Student1(Person):
    def __init__(self, fname, lname, year):
        super().__init__(fname, lname) # super doesn't take self parameter
        self.graduationyear = year
    def welcome(self):
        print("Welcome",self.firstname,self.lastname, 'to the class of', self.graduationyear)

if __name__ == '__main__':
    p1 = Person('Afroz', 'Chakure')
    p1.printname()
    x = Student('Whatever', 'Man')
    x.printname()
    y = Student1('Sam', 'Walton', 2021)
    y.welcome()

# If you add a method in the child class with the same name as a function in the parent class, the inheritance 
# of the parent method will be overridden.