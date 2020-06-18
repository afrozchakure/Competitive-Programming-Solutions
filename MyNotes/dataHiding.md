### Data Hiding

Many programming languages that support OOP also support data hiding by allowing methods and attributes—"class members"—to be declared private or protected. Private class members can be accessed from inside an object but not from outside the object. 

Protected class members can be accessed inside an object and inside objects that are subclassed from it (more on this later), but not from outside.

Python doesn't support data hiding—at least not in the same sense that other languages do. Guido van Rossum, the creator of Python, felt that data hiding makes languages harder to use. Consequently, you can't hide class members in Python.

But you can use well-established conventions to let others know that certain class members are for internal use only and should not be accessed from the outside. Prefacing a class member name with an underscore, as in _myProtectedVar, indicates that the class member is protected. Using two underscores (for example, __cleanup()) indicates that the class member is private.

### Static methods vs Instance method

Python objects support two types of methods: static methods and instance methods. Static methods apply to all objects of a certain type and can be called without instantiating the class to which the methods belong. Instance methods apply to a specific object or class instance. A get_age() method should be an instance method because one person's age doesn't necessarily equal another person's age.