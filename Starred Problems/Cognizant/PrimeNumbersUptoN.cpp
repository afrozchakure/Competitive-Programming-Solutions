#include <iostream>
using namespace std;

int isprime(int num)
{
    // type your code here
    if (num <= 1)
        return 0;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            cout << "Is prime" << endl;
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n, m, arr[100], size = 0, i;
    scanf("%d", &n);
    for (m = 2; m <= n; m++)
    {
        if (isprime(m))
        {
            arr[size++] = m;
        }
    }
    for (i = 0; i < size; i++)
    {
        printf("%dn", arr[i]);
    }
    return 0;
}