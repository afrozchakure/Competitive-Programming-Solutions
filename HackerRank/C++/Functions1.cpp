/*
Task:
You have to write a function int max_of_four(int a, int b, int c, int d) which reads 
four arguments and returns the greatest of them. 
*/

#include <iostream>
#include <cstdio>
using namespace std;

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max_of_four(int a, int b, int c, int d)
{
    if(a > b && a > c && a > d)
        return a;
    if(b > a && b > c && b > d)
        return b;
    if(c > b && c > a && c > d)
        return c;
    // if(d > b && d > c && d > a) // not necessary directly return
    return d;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}

/*
Input Format
Input will contain four integers - a, b, c, d, one in each line.

Output Format
Print the greatest of the four integers.
PS: I/O will be automatically handled.

Sample Input
3
4
6
5

Sample Output
6
*/
