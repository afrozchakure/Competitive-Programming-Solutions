/*
Task

Given a positive integer denoting n, do the following:

1. If 1 <= n <= 9, then print the lowercase English word corresponding to the number 
(e.g., one for 1, two for 2, etc.).
2. If n > 9, print Greater than 9.
*/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Write Your Code Here
    int no;
    scanf("%d", &no);
    if(no == 1) 
        printf("one");
    else if (no == 2) 
        printf("two");
    else if (no == 3)
        printf("three");
    else if (no == 4) 
        printf("four");
    else if (no == 5) 
        printf("five");
    else if (no == 6) 
        printf("six");
    else if (no == 7) 
        printf("seven");
    else if (no == 8) 
        printf("eight");
    else if (no == 9) 
        printf("nine");
    else if (no > 9) 
        printf("Greater than 9");
    
    /*
    Easier Method - 2
    char *string[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int no;
    scanf("%d", &no);
    if(no <= 9 && no > 0)
    {
        printf("%s", string[no-1]);
    }
    else if(no>9)
    {
        printf("Greater than 9");
    }
    */

    return 0;
}

/*
Output Format
If 1 <= n <= 9, then print the lowercase English word corresponding to the number 
(e.g., one for 1, two for 2, etc.); otherwise, print Greater than 9 instead.

Sample Input
5

Sample Output
five

*/

