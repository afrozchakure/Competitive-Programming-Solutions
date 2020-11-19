#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int count = 0;
    while (a <= b)
    {
        a = a * 3;
        b = b * 2;
        count++;
    }
    cout << count << endl;
    return 0;
}