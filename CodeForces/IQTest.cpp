#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> arr;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        arr.push_back(j);
    }

    int count_even = 0;
    int count_odd = 0;
    int last_even = 0;
    int last_odd = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count_even++;
            last_even = i;
        }
        else
        {
            count_odd++;
            last_odd = i;
        }
    }

    if (count_even < count_odd)
    {
        cout << last_even + 1 << endl;
    }
    else
    {
        cout << last_odd + 1 << endl;
    }

    return 0;
}