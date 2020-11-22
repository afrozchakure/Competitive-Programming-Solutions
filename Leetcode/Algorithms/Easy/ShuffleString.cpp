// Simple Character replacement in the string
class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        string result = s;
        for (int i = 0; i < s.size(); i++)
        {
            result[indices[i]] = s[i];
        }
        return result;
    }
};

// Time Complexity - O(n), n is the number of characters in the string
// Space Complexity- O(1)