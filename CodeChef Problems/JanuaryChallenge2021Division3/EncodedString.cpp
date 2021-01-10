#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    map<string, char> map = {
        {"0000", 'a'},
        {"0001", 'b'},
        {"0010", 'c'},
        {"0011", 'd'},
        {"0100", 'e'},
        {"0101", 'f'},
        {"0110", 'g'},
        {"0111", 'h'},
        {"1000", 'i'},
        {"1001", 'j'},
        {"1010", 'k'},
        {"1011", 'l'},
        {"1100", 'm'},
        {"1101", 'n'},
        {"1110", 'o'},
        {"1111", 'p'}};
    int temp = t;
    while (t--)
    {
        if (t != temp - 1)
            cout << endl;
        unsigned long long n;
        cin >> n;
        string s;
        cin >> s;

        string result = "";
        for (unsigned long long i = 0; i < s.size(); i += 4)
        {
            // cout << "\ni Value: " << i;
            string val = s.substr(i, 4);
            // cout << "\nValue: " << val;
            result += map[val];
        }

        cout << result;
    }
    return 0;
}