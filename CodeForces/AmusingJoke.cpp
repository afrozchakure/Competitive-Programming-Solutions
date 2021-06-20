#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string guestName, residentHost, myString;
    cin >> guestName >> residentHost >> myString;

    int n1 = guestName.size();
    int n2 = residentHost.size();
    int n3 = myString.size();

    if (n3 < (n1 + n2))
    {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> myChar(26, 0);

    for (char &i : guestName)
    {
        myChar[i - 'A']++;
    }

    for (char &i : residentHost)
    {
        myChar[i - 'A']++;
    }

    vector<int> newChar(26, 0);

    for (char &i : myString)
    {
        newChar[i - 'A']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (newChar[i] != myChar[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}