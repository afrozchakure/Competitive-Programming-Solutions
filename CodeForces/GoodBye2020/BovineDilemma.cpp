#include <iostream>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> x_corr;
        int min_num = 0;
        int max_num = INT16_MIN;
        set<float> s;
        while (n--)
        {
            int x;
            cin >> x;
            x_corr.push_back(x);
        }
        float area = 0;

        // cout << "Area: " << endl;
        for (int i = 0; i < x_corr.size() - 1; i++)
        {
            for (int j = i + 1; j < x_corr.size(); j++)
            {
                int first = x_corr[i];
                int second = x_corr[j];
                area = 0.5 * (second - first) * 1;
                s.insert(area);
                // cout << area << " ";
            }
        }

        cout << s.size() << endl;
    }

    return 0;
}