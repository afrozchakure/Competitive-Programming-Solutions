#include <iostream>
using namespace std;

int main()
{
    int k, n, w;
    cin >> k >> n >> w;
    int sum = 0;
    for (int i = 1; i <= w; i++)
    {
        sum += i * k;
    }
    if (sum > n)
        cout << sum - n << endl;
    else
        cout << 0 << endl;
    return 0;
}