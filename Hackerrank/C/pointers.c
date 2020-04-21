#include<stdio.h>
void increment(int *v)
{
    (*v)++;
}
int main()
{
    int a;
    scanf("%d", &a);
    increment(&a);
    printf("%d", a);
    return 0;
}

// Input:
// 12

// Output:
// 13