#include <iostream>
using namespace std;
#include <vector>
class Solution
{
public:
    int smallestRangeI(vector<int> &A, int k)
    {
        int n = A.size();

        int min_val = A[0];
        int max_val = A[0];
        for (int i = 0; i < n; i++)
        {
            min_val = min(min_val, A[i]);
            max_val = max(max_val, A[i]);
        }

        if ((min_val + k) >= (max_val - k))
        {
            return 0;
        }
        else
        {
            return (max_val - k) - (min_val + k);
        }
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)