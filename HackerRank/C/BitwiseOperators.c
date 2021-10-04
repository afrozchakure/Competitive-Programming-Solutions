/*
Objective

This challenge will let you learn about bitwise operators in C.

Inside the CPU, mathematical operations like addition, subtraction, multiplication and division are done in bit-level. 
To perform bit-level operations in C programming, bitwise operators are used which are explained below.

    Bitwise AND operator & The output of bitwise AND is 1 if the corresponding bits of two operands is 1. 
    If either bit of an operand is 0, the result of corresponding bit is evaluated to 0. It is denoted by &.
    
    Bitwise OR operator | The output of bitwise OR is 1 if at least one corresponding bit of two operands is 1. 
    It is denoted by |.
    
    Bitwise XOR (exclusive OR) operator ^ The result of bitwise XOR operator is 1 if the corresponding bits of two operands are opposite. 
    It is denoted by (+).

For example, for integers 3 and 5,
3 = 00000011 (In Binary)
5 = 00000101 (In Binary)

AND operation        OR operation        XOR operation
  00000011             00000011            00000011
& 00000101           | 00000101          ^ 00000101
  ________             ________            ________
  00000001  = 1        00000111  = 7       00000110  = 6

Task
Given set S = {1,2,3,..., n}, find:

1. the maximum value of a & b which is less than a given integer k, where a and b (where a < b) are two integers from set S.
2. the maximum value of a | b which is less than a given integer k, where a and b (where a < b) are two integers from set S.
3. the maximum value of a (+) b which is less than a given integer k, where a and b (where a < b) are two integers from set S. 

Input Format
The only line contains 2 space-separated integers, n and k, respectively.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int a_and_b = 0, a_or_b = 0, a_xor_b = 0;
  for(int i=1; i<=k; i++)
  {
      for(int j=i+1; j<=n; j++)
      {
        //   printf("%d %d\n", i, j);
          if((i & j) > a_and_b && (i & j) < k)
            a_and_b = i & j;
          if((i | j) > a_or_b && (i | j) < k)
            a_or_b = i | j;
          if((i ^ j) > a_xor_b && (i ^ j) < k)
            a_xor_b = i ^ j;
      }
  }
  printf("%d\n%d\n%d", a_and_b, a_or_b, a_xor_b);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}

/*
Sample Input 0
5 4

Sample Output 0
2
3
3
*/

