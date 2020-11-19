#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string b = "hello";
    int j = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == b[j])
        {
            j++;
            if (j == 5)
                break;
        }
    }
    if (j == 5)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}