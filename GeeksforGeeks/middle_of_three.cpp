#include <iostream>
using namespace std;

int main()
{

    int n, j = 0;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << ",";
    return 0;
}