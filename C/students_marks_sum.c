/*
Complete the function, marks_summation(int* marks, char gender, int number_of_students) which returns the total sum of:

1. marks of boys if gender = b

2. marks of girls if gender = g

The locked code stub reads the elements of marks along with gender. 
Then, it calls the function marks_summation(marks, gender, number_of_students) to get the sum of alternate elements as explained above and then prints the sum.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int n, char gender) {
  //Write your code here.
    int sum = 0;
    if (gender == 'b')
    {
        for(int i=0; i<n; i+=2)
        {
            sum += marks[i];
        }
    }
    else
    {
        for(int i=1; i<n; i+=2)
        {
            sum += marks[i];
        }
    }
    
    return sum;
}

int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}

/*
Sample Input 0
3
3
2
5
b

Sample Output 0
8

Explanation 0
marks = [3, 2, 5] and gender = b.
So,marks0 + marks2 = 3 + 5 = 8.

Sample Input 1
5
1
2
3
4
5
g

Sample Output 1
6

Explanation 1
marks = [1, 2, 3, 4, 5] and gender = g 
So, sum = marks1 + marks3 = 2 + 5 = 8.
*/
