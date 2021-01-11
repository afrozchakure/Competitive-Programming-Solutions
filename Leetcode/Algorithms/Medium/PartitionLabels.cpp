class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        int n = S.size();
        if (n == 0)
            return vector<int>{};

        int last_indices[26];

        vector<int> result;
        for (int i = 0; i < S.size(); i++)
            last_indices[S[i] - 'a'] = i;

        int start = 0;
        int end = 0;
        for (int i = 0; i < S.size(); i++)
        {
            end = max(end, last_indices[S[i] - 'a']);
            if (end == i)
            {
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(26)