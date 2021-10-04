/*
Sets are a part of the C++ STL. Sets are containers that store unique elements following a specific order. Here are some of the frequently used member functions of sets:

1. Declaration:
set<int>s; //Creates a set of integers.

2. Size:
int length=s.size(); //Gives the size of the set.

3. Insert:
s.insert(x); //Inserts an integer x into the set s.

4. Erasing an element:
s.erase(val); //Erases an integer val from the set s.

5. Finding an element:
set<int>::iterator itr=s.find(val); //Gives the iterator to the element val if it is found otherwise returns s.end() .
Ex: set<int>::iterator itr=s.find(100); //If 100 is not present then it==s.end().

Coming to the problem, you will be given Q queries. Each query is of one of the following three types:

1 x: Add an element x to the set.
2 x: Delete an element x from the set. (If the number x is not present in the set, then do nothing).
3 x: If the number x is present in the set, then print "Yes"(without quotes) else print "No"(without quotes).

Input Format
The first line of the input contains Q where Q is the number of queries. 
The next Q lines contain 1 query each. Each query consists of two integers y and x where y is the type of the query 
and x is an integer.

Output Format
For queries of type 3 print "Yes"(without quotes) if the number x is present in the set and if the number is not present, then print "No"(without quotes).
Each query of type 3 should be printed in a new line.

Sample Input
8
1 9
1 6
1 10
1 4
3 6
3 14
2 6
3 6

Sample Output
Yes
No
No

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    set<int>s;
    // int length = s.size();
    // s.insert(x);
    // s.erase(val);
    // set<int>::iterator itr = s.find(val);

    int n, i, m, ele;
    cin>>n;
    for(i=0; i<n;i++)
    {
        cin>>m>>ele;
        if(m == 1)
        {
            s.insert(ele);
        }
        else if(m == 2)
        {
            s.erase(ele);
        }
        else if(m == 3)
        {
            set<int>::iterator itr = s.find(ele);
            if( itr == s.end())
            {
                cout<<"No"<<endl;
            }
            else
            {
                cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
}



