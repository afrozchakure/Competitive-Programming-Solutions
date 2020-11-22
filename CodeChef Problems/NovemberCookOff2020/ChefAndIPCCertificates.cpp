#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    // n- students, k-lectures,

    int count = 0;
    for (int j = 0; j < n; j++)
    {
        int sum_time = 0;
        for (int i = 0; i < k; i++)
        {
            int time;
            cin >> time;
            sum_time += time;
        }

        int q;
        cin >> q;
        if (sum_time >= m && q <= 10)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}