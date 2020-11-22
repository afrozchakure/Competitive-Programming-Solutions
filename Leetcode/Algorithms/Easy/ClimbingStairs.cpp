// Apply Fibonacci Series algorithm

// M1- Without extra Space

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int a0 = 1, a1 = 2, temp;
        int an;
        for (int i = 3; i <= n; i++)
        {
            an = a0 + a1;
            temp = an;
            a0 = a1;
            a1 = an;
        }
        return temp;
    }
};

// Time Complexity - O(n) -> Similar to fibonacci
// Space Complexity - O(1)

// M2 - With Extra Space
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> v(47, -1);
        v[0] = 1, v[1] = 2;
        v[2] = v[0] + v[1];
        for (int i = 2; i < n; i++)
            v[i] = v[i - 1] + v[i - 2];
        return v[n - 1];
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n) -> Used vector