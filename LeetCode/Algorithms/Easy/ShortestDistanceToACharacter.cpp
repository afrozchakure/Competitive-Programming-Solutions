class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        int n = s.size();
        vector<int> result(n, n);

        int pos = -n;

        // Calculating the position from the left to right;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
                pos = i;
            result[i] = i - pos;
        }

        // Calculating distance from right side
        for (int i = pos - 1; i >= 0; i--)
        {
            if (s[i] == c)
                pos = i;
            result[i] = min(result[i], pos - i);
        }

        return result;
    }
};

// First find the distances from the left most found element
// Then find the distance from the right side, with pos - 1 as the starting point in reverse

// Time Complexity - O(N)
// Space Complexity - O(N)