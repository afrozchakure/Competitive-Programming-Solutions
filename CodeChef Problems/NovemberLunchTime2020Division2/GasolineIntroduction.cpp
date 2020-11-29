#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int temp = T;
    while (T--)
    {
        if (T != temp - 1)
            cout << endl;
        int N;
        cin >> N;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            int gas;
            cin >> gas;
            if (sum < i)
                break;
            else
                sum += gas;
            sum--;
        }
        cout << sum;
    }
    return 0;
}