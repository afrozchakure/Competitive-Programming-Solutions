#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "Tetrahedron")
            count += 4;
        else if (s == "Cube")
            count += 6;
        else if (s == "Octahedron")
            count += 8;
        else if (s == "Dodecahedron")
            count += 12;
        else
            count += 20;
    }

    cout << count << endl;
    return 0;
}