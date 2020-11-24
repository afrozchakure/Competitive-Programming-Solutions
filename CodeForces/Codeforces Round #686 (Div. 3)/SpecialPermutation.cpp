#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> elements(n);
        for (int i = 2; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << 1 << endl;
    }
    return 0;
}