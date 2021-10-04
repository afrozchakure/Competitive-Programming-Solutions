class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        // Here we're using only 26 character space in our map
        // Hence, constant space
        unordered_map<int, int> word_count(26);
        int good_word_length_count = 0;

        for (char &element : chars)
        {
            word_count[element - 'a'] += 1;
        }

        for (string &element : words)
        {
            unordered_map<int, int> temp = word_count;
            int temp_sum = 0;
            for (char &c : element)
            {
                if (temp[c - 'a'] > 0)
                {
                    temp_sum++;
                    temp[c - 'a']--;
                }
            }
            if (temp_sum == element.size())
            {
                good_word_length_count += temp_sum;
            }
        }
        return good_word_length_count;
    }
};

// Time Complexity - O(M + N), M is the number of characters in 'words' array,
// N is the number of characters in chars array
// Space Complexity - O(26), since we're using constant space