/*
Maps are a part of the C++ STL.Maps are associative containers that store elements formed by a combination of a key value and a mapped value, 
following a specific order.The mainly used member functions of maps are:

1. Map Template:

std::map <key_type, data_type>

2. Declaration:

map<string,int>m; //Creates a map m where key_type is of type string and data_type is of type int.

3. Size:

int length=m.size(); //Gives the size of the map.

4. Insert:

m.insert(make_pair("hello",9)); //Here the pair is inserted into the map where the key is "hello" and the value associated with it is 9.

5. Erasing an element:

m.erase(val); //Erases the pair from the map where the key_type is val.

6. Finding an element:

map<string,int>::iterator itr=m.find(val); //Gives the iterator to the element val if it is found otherwise returns m.end() .
Ex: map<string,int>::iterator itr=m.find("Maps"); //If Maps is not present as the key value then itr==m.end().

7. Accessing the value stored in the key:

To get the value stored of the key "MAPS" we can do m["MAPS"] or we can get the iterator using the find function and then by itr->second we can access the value.

You are appointed as the assistant to a teacher in a school and she is correcting the answer sheets of the students.Each student can have multiple answer sheets.
So the teacher has Q queries:

1 X Y :Add the marks Y to the student whose name is X.

2 X: Erase the marks of the students whose name is X.

3 X: Print the marks of the students whose name is X. (If X didn't get any marks print 0.)

Input Format
The first line of the input contains Q
where Q is the number of queries. The next Q lines contain 1 query each.The first integer, type of each query is the type of the query.
If query is of type 1, it consists of one string and an integer X and Y where X is the name of the student and Y is the marks of the student.
If query is of type 2 or 3,it consists of a single string X where X is the name of the student. 

Output Format
For queries of type 3 print the marks of the given student.

Sample Input
7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess

Sample Output
30
20
0

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    
    map<string, int> m;
    int n,i, opt, val = 0, marks = 0;
    cin>>n;
    string key;
    for(i=0; i<n; i++)
    {
        cin>>opt>>key;
        if(opt == 1)
        {
            cin>>val;
            map<string, int>::iterator itr = m.find(key);
            if(itr == m.end())
                m.insert(make_pair(key, val));
            else  {
                m[key] += val;
            }
        }
        else if(opt == 2)
        {
            m.erase(key);
        }
        else if(opt == 3)
        {
            map<string, int>::iterator itr = m.find(key);
            if(itr == m.end())
            {
                cout<<"0"<<endl;
            }
            else
                cout<<m[key]<<endl;
        }
    }
    return 0;
}



