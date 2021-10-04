#include <iostream>
using namespace std;
#include <vector>

int main()
{
    unsigned long long t;
    cin >> t;
    unsigned long long temp = t;
    while (t--)
    {
        if (t != temp - 1)
            cout << endl;
        unsigned long long N, K, x, y;
        cin >> N >> K >> x >> y;

        if (x == y)
            cout << N << " " << N;
        else if (x > y)
        {
            vector<vector<unsigned long long>> result = {{N, N - x + y}, {N + y - x, N}, {0, x - y}, {x - y, 0}};
            vector<unsigned long long> t = result[(K - 1) % 4];
            cout << t[0] << " " << t[1];
        }
        else if (y > x)
        {
            vector<vector<unsigned long long>> result = {{N - y + x, N}, {N, N - y + x}, {y - x, 0}, {0, y - x}};
            vector<unsigned long long> t = result[(K - 1) % 4];
            cout << t[0] << " " << t[1];
        }
    }
    return 0;
}