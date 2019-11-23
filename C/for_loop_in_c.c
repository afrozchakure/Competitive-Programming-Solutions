#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    for(int i = a; i<b+1; i++)
    {
        if (i < 9)
        {
            if (i == 1) printf('one');
            if (i == 2) printf('two');
            if (i == 3) printf('three');
            if (i == 4) printf('four');
            if (i == 5) printf('five');
            if (i == 6) printf('six');
            if (i == 7) printf('seven');
            if (i == 8) printf('eight');
            if (i == 9) printf('nine');

        }
        if (i > 9 && i % 2 == 0)
            print("even");
        else if (i > 9 && i % 2 == 1)
            printf("odd");
    }
    return 0;
}

