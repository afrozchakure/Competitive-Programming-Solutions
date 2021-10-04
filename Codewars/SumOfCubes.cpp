#include <math.h>
unsigned int sum_cubes(unsigned int n)
{
    // write your code here
    int n1 = n;
    int k = 0, s = 0;
    for (int i = 1; i <= n1; i++)
    {
        k = pow(i, 3);
        s += k;
    }
    return (s);
}