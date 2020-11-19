#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int n, t;

    cin >> n >> t;
    string s;
    cin >> s;
    while (t--)
    {
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == 'B' && s[i + 1] == 'G')
            {
                char temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
                i++;
            }
        }
    }
    cout << s << endl;
    return 0;
}