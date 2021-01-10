#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int temp = t;
    while (t--)
    {
        if (t != temp - 1)
            cout << endl;
        unsigned long long w, h, n;

        cin >> w >> h >> n;
        unsigned long long count = 0;

        while (w % 2 == 0 || h % 2 == 0)
        {
            if (w > 1 && w % 2 == 0)
            {
                count += 2;
                w = w / 2;
            }
            else if (h > 1 && h % 2 == 0)
            {
                count += 2;
                h = h / 2;
            }
        }

        if (count == 0)
            count = 1;
        // cout << "Count : " << count << endl;
        if (count >= n)
            cout << "YES";
        else
            cout << "NO";
    }
    return 0;
}