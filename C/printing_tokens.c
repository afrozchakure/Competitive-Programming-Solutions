/*
Given a sentence, s, print each word of the sentence in a new line.

Input Format
The first and only line contains a sentence, s.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    for(int i = 0; i<strlen(s); i++)
    {
        if (*(s+i) == ' ')
            *(s+i) = '\n';
    }
    /*
    This code works as well
    for(char *c =s; *c != NULL; c++ )  # We assign the pointer c to s and change value in c to '\n' every time a space occurs 
    if (*c == ' ') 
        *c = '\n';  # This changes the value in s as well
    printf("%s", s);
    */
    printf("%s", s);
    return 0;
}


/*
Output Format
Print each word of the sentence in a new line.

Sample Input 0
This is C 

Sample Output 0
This
is
C
*/ 

