class Solution
{
public:
    vector<string> wordSubsets(vector<string> &A, vector<string> &B)
    {
        vector<string> result;

        // Contains the maximum frequencies in the array
        vector<int> max_b_frequencies(26, 0);

        for (int i = 0; i < B.size(); i++)
        {
            string current_word = B[i];
            vector<int> char_frequencies = count(current_word);

            for (int j = 0; j < 26; j++)
            {
                max_b_frequencies[j] = max(max_b_frequencies[j], char_frequencies[j]);
            }
        }

        for (int i = 0; i < A.size(); i++)
        {
            string current_word = A[i];
            vector<int> char_counts = count(current_word);
            bool valid = true;
            for (int j = 0; j < 26; j++)
            {
                if (char_counts[j] < max_b_frequencies[j])
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
                result.push_back(current_word);
        }
        return result;
    }
    vector<int> count(string S)
    {
        vector<int> result(26);

        for (char &c : S)
        {
            result[c - 'a']++;
        }
        return result;
    }
};

// Time Complexity - O(M+N), where M and N is the total amount of information in A and B
// Space Complexity - O(A.size() + B.size())