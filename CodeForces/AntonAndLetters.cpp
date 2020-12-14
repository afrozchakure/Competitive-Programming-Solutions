#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int length, count = 0, i, x = 0;

    length = s.size();
    sort(s.begin(), s.end());

    for (int i = 0; i < length - 1; i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            count++;
            if (s[i] == s[i + 1])
                count--;
        }
    }
    cout << count << endl;

    return 0;
}