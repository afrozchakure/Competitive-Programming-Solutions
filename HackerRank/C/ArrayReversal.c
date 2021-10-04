/*
Given an array, of size n, reverse it.

Example: If array, arr = [1,2,3,4,5], after reversing it, 
the array should be, arr = [5,4,3,2,1].

Input Format

The first line contains an integer, n, denoting the size of the array. 
The next line contains n space-separated integers denoting the elements of the array.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    /* Write the logic to reverse the array. */

    for(i = num - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    return 0;
}

// Sample Input 0

// 6
// 16 13 7 2 1 12 

// Sample Output 0

// 12 1 2 7 13 16 

