#include <iostream>
using namespace std;
#include <unordered_map>

int main()
{
    string s, t;
    cin >> s >> t;
    if (s.size() != t.size())
    {
        cout << "NO" << endl;
        return 0;
    }
    int n = s.size();

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[n - i - 1])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}