#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    int s = a + b;
    int d = a - b;
    float a1, b1;
    scanf("%f", &a1);
    scanf("%f", &b1);
    float s1 = a1 + b1;
    float d1 = a1 - b1;
    printf("%d", s);
    printf("%s", " ");
    printf("%d\n", d);
    printf("%.1f", s1);
    printf("%s", " ");
    printf("%.1f", d1);

    return 0;
}
