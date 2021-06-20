#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <iomanip>

int main()
{
    int n, l;
    cin >> n >> l;

    vector<double> lanterns(n);

    for (int i = 0; i < n; i++)
    {
        // d is some positive number
        cin >> lanterns[i];
    }

    sort(lanterns.begin(), lanterns.end());

    double first = lanterns[0] - 0;
    double second = l - lanterns[n - 1];
    double ans = max(first, second);
    // cout << first << " " << second << " " << endl;
    for (int i = 0; i < n - 1; i++)
    {
        double distance = lanterns[i + 1] - lanterns[i];
        distance /= 2.00;
        ans = max(distance, ans);
        // cout << distance << " " << ans << endl;
    }

    cout << fixed << setprecision(9) << ans << "\n";

    return 0;
}