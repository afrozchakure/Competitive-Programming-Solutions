/*
An array is a series of elements of the same type placed in contiguous memory locations 
that can be individually referenced by adding an index to a unique identifier.

You'll be given an array of N integers and you have to print the integers in the reverse order.

Input Format
The first line of the input contains N,where N is the number of integers. 
The next line contains N integers separated by a space.
*/

#include <cmath>
#include <cstdio>

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=n-1;i>=0;i--)
        cout<<a[i]<<" ";
    return 0;
}

/*
Output Format
Print the N integers of the array in the reverse order in a single line separated by a space.

Sample Input
4
1 4 3 2

Sample Output
2 3 4 1
*/