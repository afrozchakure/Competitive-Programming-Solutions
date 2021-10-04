class Solution
{
public:
    int countHomogenous(string s)
    {
        int count = 0;
        int result = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && s[i - 1] == s[i])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            result = (result + count) % (1000000007);
        }
        return result;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)