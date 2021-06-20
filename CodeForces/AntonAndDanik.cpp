#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string games;
    cin >> games;

    int count_a = 0;
    int count_d = 0;
    for (char &i : games)
    {
        if (i == 'A')
            count_a++;
        else
            count_d++;
    }

    if (count_a > count_d)
    {
        cout << "Anton" << endl;
    }
    else if (count_a < count_d)
    {
        cout << "Danik" << endl;
    }
    else
    {
        cout << "Friendship" << endl;
    }
    return 0;
}