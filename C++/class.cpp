/*
Classes in C++ are user defined types declared with keyword class that has data and functions . 
Although classes and structures have the same type of functionality, there are some basic differences. 
The data members of a class are private by default and the members of a structure are public by default. 
Along with storing multiple data in a common block, it also assigns some functions (known as methods) to manipulate/access them. 
It serves as the building block of Object Oriented Programming.
It also has access specifiers, which restrict the access of member elements. The primarily used ones are the following:

    public: Public members (variables, methods) can be accessed from anywhere the code is visible.
    private: Private members can be accessed only by other member functions, and it can not be accessed outside of class.

Class can be represented in the form of

class ClassName {
    access_specifier1:
        type1 val1;
        type2 val2;
        ret_type1 method1(type_arg1 arg1, type_arg2 arg2,...)
        ...
    access_specifier2:
        type3 val3;
        type4 val4;
        ret_type2 method2(type_arg3 arg3, type_arg4 arg4,...)
        ...
};

It's a common practice to make all variables private, and set/get them using public methods. For example:

class SampleClass {
    private:
        int val;
    public:
        void set(int a) {
            val = a;
        }
        int get() {
            return val;
        }
};

We can store details related to a student in a class consisting of his age (int), first_name (string), last_name (string) and standard (int).

You have to create a class, named Student, representing the student's details, as mentioned above, and store the data of a student. Create setter and getter functions for each element; that is, the class should at least have following functions:

    get_age, set_age
    get_first_name, set_first_name
    get_last_name, set_last_name
    get_standard, set_standard

Also, you have to create another method to_string() which returns the string consisting of the above elements, separated by a comma(,). You can refer to stringstream for this.


*/


#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student
{
    int age,standard;
    string first_name, last_name;
    public:
    void set_age(int a){
        age = a;
    }
    int get_age(){
        return age;
    }
    void set_first_name(string a){
        first_name = a;
    }
    string get_first_name(){
        return first_name;
    }
    void set_last_name(string a){
        last_name = a;
    }
    string get_last_name(){
        return last_name;
    }
    void set_standard(int a){
        standard = a;
    }
    int get_standard(){
        return standard;
    }
    string to_string()
    {
        stringstream ss;
        ss << age<<","<<first_name<<","<<last_name<<","<<standard;
        return ss.str();
        // return stringstream(age, first_name, last_name, standard);
    }
    


};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}

/*
Sample Input
15
john
carmack
10

Sample Output
15
carmack, john
10

15,john,carmack,10

*/

/*
Note : 
Because if we just returned something like :

return age+","+first_name+","+last_name+","+standard;

then the code wouldn't compile because age and standard are integers, 
while first_name and last_name are strings and we can't just concenate strings with integers. 
StringStream handels this for us and just automatically turns age and standard into part of the 
string when they're apprehended to stringstream using the << operator.
*/