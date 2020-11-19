#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main()
{
    string s;
    cin >> s;
    int upper = 0;
    int lower = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (isupper(s[i]))
            upper++;
        if (islower(s[i]))
            lower++;
    }
    if (upper > lower)
    {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    }

    else
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;
    return 0;
}