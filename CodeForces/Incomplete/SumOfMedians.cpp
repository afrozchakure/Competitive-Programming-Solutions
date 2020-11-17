#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int sum = 0;
        int n, k;
        cin >> n >> k;

        vector<vector<int>> arr(n, vector<int>(k));

        int size = n * k;
        int median;
        if (n % 2 == 1)
            median = floor(n / 2);
        else
            median = (n / 2) - 1;

        // cout << median << endl;
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];

                if (counter == median && counter < (size - 1))
                {
                    sum += arr[i][j];
                    cout << arr[i][j] << " " << endl;
                    median += n;
                    cout << "Counter :" << counter << " Median: " << median << endl;
                    ;
                }
                counter++;
            }
        }
        cout << endl;
        // cout << sum << endl;
    }

    return 0;
}