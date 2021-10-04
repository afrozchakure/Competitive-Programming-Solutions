/*
An array is a container object that holds a fixed number of values of a single type. 
To create an array in C, we can do int arr[n];. Here, arr, is a variable array which holds up to 10 integers. 
The above array is a static array that has memory allocated at compile time. 
A dynamic array can be created in C, using the malloc function and the memory is allocated on the heap at runtime. 
To create an integer array, arr of size n, int *arr = (int*)malloc(n * sizeof(int)), 
where arr points to the base address of the array.
In this challenge, you have to create an array of size n dynamically, 
input the elements of the array, sum them and print the sum of the elements in a new line.

Input Format
The first line contains an integer, n.
The next line contains n space-separated integers.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
       
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int)*n);  // where arr points to the base address of the array
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for(int i = 0; i< n; i++)
    {
        sum = sum + arr[i];
    }
    printf("%d", sum);
    return 0;
}

/*
Output Format
Print in a single line the sum of the integers in the array.

Sample Input 0
6
16 13 7 2 1 12 

Sample Output 0
51

Sample Input 1
7
1 13 15 20 12 13 2 

Sample Output 1
76
*/
