#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x;
    cin >> x;

    int count;
    float result = (float)x / 5;
    count = ceil(result);
    cout << count << endl;

    return 0;
}