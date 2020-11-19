#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int inside_tram = 0;
    int max_inside_tram = 0;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;

        inside_tram = inside_tram - a;
        inside_tram += b;
        max_inside_tram = max(max_inside_tram, inside_tram);
    }
    cout << max_inside_tram << endl;
    return 0;
}