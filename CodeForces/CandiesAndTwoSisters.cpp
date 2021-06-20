#include <iostream>
#include <cmath>
using namespace std;

unsigned long long fact(int i, int limit)
{
    if (i == limit)
        return 1;
    else if (i <= 1)
        return 1;
    else
        return i * fact(i - 1, limit);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        unsigned long long n;
        cin >> n;

        // unsigned long long result = tgamma(n + 1) / (n * tgamma(n - 2 + 1) * 2);
        // unsigned long long x = tgamma(n + 1);
        // unsigned long long y = tgamma(n - 2 + 1);

        // cout << x << " " << y << " " << x / y << endl;
        // cout << "result: " << result << endl;
        unsigned long long result = fact(n, n - 2) / (n * 2);

        cout << result << endl;
    }
    return 0;
}