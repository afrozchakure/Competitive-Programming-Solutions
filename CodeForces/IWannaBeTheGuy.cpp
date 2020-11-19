#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p;
    cin >> p;

    int array[250];
    int count = 0;

    for (int i = 0; i < p; i++)
    {
        int x;
        cin >> x;
        array[i] = x;
    }

    int q;
    cin >> q;

    for (int i = p; i < (q + p); i++)
    {
        int x;
        cin >> x;
        array[i] = x;
    }

    sort(array, array + p + q);

    for (int i = 0; i < (p + q); i++)
    {
        if (array[i] != array[i + 1])
            count++;
    }
    if (count == n)
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;
    return 0;
}