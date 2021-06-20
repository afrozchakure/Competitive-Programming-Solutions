#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;

    count += n / 100;
    int remainder = n % 100;

    if (remainder == 0)
    {
        cout << count << endl;
        return 0;
    }

    count += remainder / 20;
    remainder = remainder % 20;

    if (remainder == 0)
    {
        cout << count << endl;
        return 0;
    }

    count += remainder / 10;
    remainder %= 10;

    if (remainder == 0)
    {
        cout << count << endl;
        return 0;
    }

    count += remainder / 5;
    remainder %= 5;

    if (remainder == 0)
    {
        cout << count << endl;
        return 0;
    }
    count += remainder / 1;
    remainder %= 1;

    cout << count << endl;
    return 0;
}