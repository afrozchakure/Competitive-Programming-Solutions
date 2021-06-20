#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[0] < v2[0];
}

int main()
{
    int strength, n;
    cin >> strength >> n;

    vector<vector<int>> s_bonus(n, vector<int>(2, 0));

    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        s_bonus[i][0] = x;
        s_bonus[i][1] = y;
    }

    sort(s_bonus.begin(), s_bonus.end(), sortcol);

    for (int i = 0; i < n; i++)
    {
        if (strength > s_bonus[i][0])
            strength += s_bonus[i][1];
        else
            flag = false;
        // cout << s_bonus[i][0] << " " << s_bonus[i][1] << " " << strength << "\n";
    }

    if (flag == true)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}