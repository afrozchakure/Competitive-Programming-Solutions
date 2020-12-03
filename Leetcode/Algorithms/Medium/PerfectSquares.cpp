// Method : Dynamic Programming

#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        if (n <= 0)
            return 0;

        vector<int> cntPerfectSquares(n + 1, INT_MAX);
        cntPerfectSquares[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                cntPerfectSquares[i] = min(cntPerfectSquares[i], cntPerfectSquares[i - (j * j)] + 1);
            }
        }

        return cntPerfectSquares.back();
    }
};
