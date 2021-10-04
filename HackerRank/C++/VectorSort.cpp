/*
You are given N integers.Sort the N integers and print the sorted order.
Store the N integers in a vector.Vectors are sequence containers representing arrays that can change in size.

1. Declaration:
vector<int>v; (creates an empty vector of integers)

2. Size:
int size=v.size();

3. Pushing an integer into a vector:
v.push_back(x);(where x is an integer.The size increases by 1 after this.)

4. Popping the last element from the vector:
v.pop_back(); (After this the size decreases by 1)

5. Sorting a vector:
sort(v.begin(),v.end()); (Will sort all the elements in the vector)

Input Format
The first line of the input contains N where N is the number of integers. 
The next line contains N integers.

Output Format
Print the integers in the sorted order one by one in a single line followed by a space.

Sample Input
5
1 6 10 8 4

Sample Output
1 4 6 8 10
*/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;  // Declaration of a vector
    int size, i, ele = 0;
    cin>>size;
    for(i = 0; i<size; i++)
    {
        cin>>ele;
        v.push_back(ele);
    }
    sort(v.begin(), v.end());  // Sorting a vector
    for(i=0; i<size; i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}
