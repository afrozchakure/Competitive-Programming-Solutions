// Objective

// In order to get the last digit of a number, we use modulo operator \%. 
// When the number is modulo divided by 10 we get the last digit.

// To find first digit of a number we divide the given number by 10
// until number is greater than 10. At the end we are left with the first digit. 

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    int sum = 0;
    int temp = n;
    while(temp > 0)
    {
        sum = sum + temp % 10;
        temp = (temp - (temp %10)) / 10;
    }
    printf("%d", sum);
    return 0;
}

// Output Format

// Print the sum of the digits of the five digit number.

// Sample Input 0
// 10564

// Sample Output 0
// 16

