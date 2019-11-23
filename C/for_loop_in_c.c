/*Task

For each integer n in the interval [a,b] (given as input) :

If 1 <= n <= 9, then print the English representation of it in lowercase. 
That is "one" for 1, "two" for 2, and so on.
Else if n > 9 and it is an even number, then print "even".
Else if n > 9 and it is an odd number, then print "odd".
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// int main() 
// {
//     int a, b;
//     scanf("%d\n%d", &a, &b);
//   	// Complete the code.
//     for(int i = a; i<b+1; i++)
//     {
//         if (i <= 9)
//         {
//             if (i == 1) 
//                 printf("one\n");
//             if (i == 2) 
//                 printf("two\n");
//             if (i == 3) 
//                 printf("three\n");
//             if (i == 4) 
//                 printf("four\n");
//             if (i == 5) 
//                 printf("five\n");
//             if (i == 6) 
//                 printf("six\n");
//             if (i == 7) 
//                 printf("seven\n");
//             if (i == 8) 
//                 printf("eight\n");
//             if (i == 9) 
//                 printf("nine\n");

//         }
//         if (i > 9 && i % 2 == 0)
//             printf("even\n");
//         else if (i > 9 && i % 2 == 1)
//             printf("odd\n");
//     }
//     return 0;
// }


// OR Method 2

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    char *str[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "even", "odd"};
    for(int i = a; i<b+1; i++)
    {
        if (i <= 9)
            printf("%s\n", str[i-1]);
        if (i > 9)
            printf("%s\n", str[9+(i%2)]);
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

