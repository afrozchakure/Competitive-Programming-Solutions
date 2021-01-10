#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
    int t;
    cin >> t;
    int temp = t;
    while (t--)
    {
        if (t != temp - 1)
            cout << endl;

        int n, m;
        cin >> n >> m;

        unsigned long long A[n];
        unsigned long long B[m];
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            A[i] = num;
            sum1 += num;
        }
        for (int i = 0; i < m; i++)
        {
            int num;
            cin >> num;
            B[i] = num;
            sum2 += num;
        }

        // A - John Jackson
        // B - Jack Jackson

        sort(A, A + n);
        sort(B, B + m);
        int count = 0;
        int i = 0;
        int j = m - 1;
        for (int m = 0; i < n; i++)
        {
            if (sum1 > sum2)
                break;
            if (A[i] > B[j])
                break;

            sum1 = sum1 - A[i] + B[j];
            sum2 = sum2 - B[j] + A[i];
            count++;
            j--;
        }
        if (sum1 > sum2)
            cout << count;
        else
            cout << -1;
    }

    return 0;
}