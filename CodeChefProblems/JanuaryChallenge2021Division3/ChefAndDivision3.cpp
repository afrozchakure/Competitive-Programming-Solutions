#include <iostream>
#include <vector>
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
        unsigned long long n, k, d;
        cin >> n >> k >> d;
        vector<unsigned long long> A;
        unsigned long long sum = 0;
        for (unsigned long long i = 0; i < n; i++)
        {
            unsigned long long val;
            cin >> val;
            sum += val;
            A.push_back(val);
        }
        // Exactly K problem
        // ith setter has made Ai problmes

        unsigned long long result = sum / k;

        if (result > d)
            result = d;

        cout << result;
    }
    return 0;
}