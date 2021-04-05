#include <vector>
#include <iostream>
using namespace std;
#include <math.h>
class Solution
{
public:
    bool isIdealPermutation(vector<int> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if (abs(i - A[i]) > 1)
                return false;
        }
        return true;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)