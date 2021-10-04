/*
Given a string, s, consisting of alphabets and digits, find the frequency of each digit in the given string.

Input Format
The first line contains a string, num which is the given number.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    char s;
    int a[] = {0,0,0,0,0,0,0,0,0,0};  // An empty array
    while(scanf("%c", &s) == 1)  // It keeps on scaning the next value inline (continue while it is true)
    {
        if(s >= '0' && s <= '9')  // If value is between 0 and 9
        {
            a[s-'0'] += 1;  // Subtracting 0 from s to get the ASCII value
        }
    }
    for(int i=0; i<10; i++)
        printf("%d ", a[i]);  // Printing the array
    return 0;
}


/*
Sample Input 1
lw4n88j12n1

Sample Output 1
0 2 1 0 1 0 0 0 2 0 

Sample Input 2
1v88886l256338ar0ekk

Sample Output 2
1 1 1 2 0 1 2 0 5 0 
*/

