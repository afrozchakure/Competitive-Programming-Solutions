class Solution
{
public:
    int kthFactor(int n, int k)
    {
        vector<int> factors;

        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
                factors.push_back(i);
            if (factors.size() == k)
                return factors.back();
        }
        return -1;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N), A is the number of factors of N