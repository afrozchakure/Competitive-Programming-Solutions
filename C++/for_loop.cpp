/*
Input Format
You will be given two positive integers,a
and b(a <= b), separated by a newline.

Output Format
For each integer n in the interval [a,b]:
If 1 <= n <= 9, then print the English representation of it in lowercase. That is "one" for 1, "two" for 2, and so on.
Else if n > 9 and it is an even number, then print "even".
Else if n > 9 and it is an odd number, then print "odd".
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    string a[11] = {"odd","one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "even"};
    int start, end;
    cin >> start;
    cin >> end;
    for(int i=start; i<=end; i++)
    {
    if(i >= 1 and i <= 9)
        cout<< a[i] << endl;
    else if(i%2 == 1)
        cout<< a[0] << endl;
    else if(i%2 == 0)
        cout<< a[10] << endl;
    }
    return 0;
}

/*
Sample Input
8
11

Sample Output
eight
nine
even
odd
*/

