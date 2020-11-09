#include <iostream>
#include <math.h>
using namespace std;

int binarytodecimal(int num)
{
    int sum = 0;
    int counter = 0;
    while (num > 0)
    {
        int remainder = num % 10;
        sum += (remainder * pow(2, counter));
        num = num / 10;
        // cout << sum << " ";
        counter++;
    }
    return sum;
}
int main()
{
    int num;
    scanf("%d", &num);
    printf("%d", binarytodecimal(num));
}
