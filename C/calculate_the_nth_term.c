/*
There is a series, S, where the next term is the sum of pervious three terms. Given the first three terms of the series, a, b, c andrespectively, 
you have to output the nth term of the series using recursion.
Recursive method for calculating nth term is given below.

S(n) = a if n == 1;
       b if n == 2;
       c if n == 3;
       S(n-1) + S(n-2) + S(n-3) otherwise;

Input Format

1. The first line contains a single integer, n.
2. The next line contains 3 space-separated integers, a, b, and c.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c) 
{
  //Write your code here.
      if( n== a)
          return a;
      else if (n == b)
          return b;
      else if (n == c)
          return c;
      else 
          return (int)(find_nth_term(n-1, a, b, c)+find_nth_term(n-2, a, b, c)+ find_nth_term(n-3, a, b, c));
}

int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}

/*
Output Format
Print the nth term of the series, S(n).

Sample Input 0
5
1 2 3

Sample Output 0
11

Explanation 0
Consider the following steps:
S(1) = 1
S(2) = 2
S(3) = 3
S(4) = S(3) + S(2) + S(1)
S(5) = S(4) + S(3) + S(2)
From steps 1, 2, 3, and 4, we can say s(4) = 3 + 2 + 1; then using the values from step 2, 3, 4, and 5, we get S(5) = 6 + 3 + 2 = 11. 
Thus, we print 11 as our answer.
*/