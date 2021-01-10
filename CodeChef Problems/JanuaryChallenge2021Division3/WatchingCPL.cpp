#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int t;
    cin >> t;
    int temp = t;
    while (t--)
    {
        if (t != temp - 1)
            cout << endl;

        int N, K;
        cin >> N >> K;
        // K is height
        // ith box has height Hi

        // height of each tower is the sum of height of all the boxes that form it

        vector<int> H;

        for (int i = 0; i < N; i++)
        {
            int num;
            cin >> num;
            H.push_back(num);
        }
    }
    return 0;
}