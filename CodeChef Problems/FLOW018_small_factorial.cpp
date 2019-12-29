/*
Small Factorial

Write a program to find the factorial value of any number entered by the user.

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

Output
Display the factorial of the given number N .

Constraints
    1 ≤ T ≤ 1000
    0 ≤ N ≤ 20

Example

Input
3 
3 
4
5

Output
6
24
120

*/

#include <iostream>
using namespace std;

int factorial(int n)
{
    if(n == 1 || n == 0)
    {
        return 1;
    }
    else if(n > 1)
    {
        return n * factorial(n-1);
    }
}
int main() {
	// your code goes here
	int n,i, n2 = 0;
	cin>>n;
	for(i=0;i<n;i++)
	{
	    cin>>n2;
        cout<<factorial(n2)<<endl;	    
	}
	return 0;
}
