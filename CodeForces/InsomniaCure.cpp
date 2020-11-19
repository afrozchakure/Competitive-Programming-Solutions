#include <iostream>
using namespace std;

int main()
{
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    // kth got punched in the face with frying pan
    // lth got shut in the balcony door
    // mmeth got his paws trampled
    // nth to call her mom

    int count = d;

    if (l == 1 || k == 1 || m == 1 || n == 1)
        cout << count << endl;
    else
    {
        for (int i = 1; i <= d; i++)
        {
            // we are subtracting the ones where all are not divisible by
            // any of k, l, m and n
            if (i % k != 0 && i % l != 0 && i % m != 0 && i % n != 0)
                count--;
        }

        cout << count << endl;
    }
    return 0;
}