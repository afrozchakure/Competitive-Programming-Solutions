#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int count = 0;
        if (a % b != 0)
            count = b - a % b;
        cout << count << endl;
    }
    return 0;
}