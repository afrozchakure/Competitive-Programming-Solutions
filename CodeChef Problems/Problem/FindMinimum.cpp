#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int temp = t;
    while (t--)
    {
        if (temp - 1 != t)
            cout << endl;
        unsigned long long n;
        cin >> n;
        unsigned long long sum = INT16_MAX;

        for (unsigned long long i = 1; i < n; i++)
        {
            unsigned long long x = i;
            unsigned long long y = (n % x != 0) ? -1 : n / x;
            if (y == -1 || x == y)
                continue;
            sum = min(x + y, sum);
        }
        cout << sum;
    }
    return 0;
}