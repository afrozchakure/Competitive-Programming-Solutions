#include <iostream>
using namespace std;

int main()
{
    unsigned long long n;
    unsigned long long t;
    cin >> t;
    unsigned long long temp = t;
    while (t--)
    {
        if (temp - 1 != t)
        {
            cout << endl;
        }
        cin >> n;

        unsigned long long first = 1;
        unsigned long long mul = 3;
        for (unsigned long long i = 0; i < n; i++)
        {
            if (i == n - 1)
                cout << first;
            else
                cout << first << " ";
            first = first + mul;
            mul = 2 * mul;
        }
        cout << endl;

        first = 2;
        mul = 3;
        for (unsigned long long i = 0; i < n; i++)
        {
            if (i == n - 1)
                cout << first;
            else
                cout << first << " ";
            first = first + mul;
            mul = 2 * mul;
        }
        cout << endl;

        first = 4;
        mul = 6;
        for (unsigned long long i = 0; i < n; i++)
        {
            if (i == n - 1)
                cout << first;
            else
                cout << first << " ";
            first = first + mul;
            mul = 2 * mul;
        }
        cout << endl;

        first = 3;
        mul = 3;
        for (unsigned long long i = 0; i < n; i++)
        {
            if (i == n - 1)
                cout << first;
            else
                cout << first << " ";
            first = first + mul;
            mul = 2 * mul;
        }
    }
    return 0;
}