#include <iostream>
#include <algorithm>
using namespace std;

void minCoins()
{
    int ans = 0;

    int c0, c1, h, n;
    string s;

    cin >> n >> c0 >> c1 >> h;
    cin >> s;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
            ans += min(c0, c1 + h);
        if (s[i] == '1')
            ans += min(c1, c0 + h);
    }
    cout << ans << endl;
}

int main()
{

    // h - no. of coins to pay for each change
    int t;
    cin >> t;
    while (t--)
    {
        cout << "here" << endl;
        minCoins();
    }

    return 0;
}