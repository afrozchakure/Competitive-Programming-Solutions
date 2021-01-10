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
        {
            cout << endl;
        }
        int n;
        cin >> n;
        int odd_count = 0;
        int even_count = 0;
        unsigned long long sum = 0;
        while (n--)
        {
            int num;
            cin >> num;
            if (num % 2 == 0)
                even_count += 1;
            else
                odd_count += 1;
            sum += num;
        }

        // cout << "Sum : " << sum << endl;
        if (sum % 2 == 0 && (odd_count == even_count || even_count == 0 && odd_count != 0 && odd_count % 2 == 0 || even_count != 0 && odd_count == 0 && even_count % 2 == 0))
            cout << "YES";
        else
            cout << "NO";
    }
    return 0;
}
