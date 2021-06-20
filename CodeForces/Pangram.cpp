#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string myString;

    cin >> myString;

    int size = myString.size();
    if (size < 26)
    {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> charCount(26, 0);

    transform(myString.begin(), myString.end(), myString.begin(), ::tolower);
    for (char &myChar : myString)
    {
        charCount[myChar - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (charCount[i] == 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}