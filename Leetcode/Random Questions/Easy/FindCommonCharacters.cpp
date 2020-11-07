class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {
        vector<string> result;
        vector<int> cnt(26, INT_MAX);

        for (string &element : A)
        {
            vector<int> cnt1(26, 0);

            for (char &c : element)
                ++cnt1[c - 'a'];
            for (int i = 0; i < 26; i++)
                cnt[i] = min(cnt[i], cnt1[i]);
        }

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < cnt[i]; j++)
            {
                // The string will be inserted once into result vector
                result.push_back(string(1, i + 'a'));
            }
        }
        return result;
    }
};

// Time Complexity - O(n), n is the total number of characters
// Space Complexity - O(1), we use two fixed size vectors