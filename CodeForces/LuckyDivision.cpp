#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[] = {4, 7, 47, 74, 744, 474, 447, 774, 747, 477};
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (n == a[i] || n % a[i] == 0)
        {
            cout << "YES" << endl;
            return 0;
        }
        count++;
    }
    if (count == 10)
        cout << "NO" << endl;
    return 0;
}