class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> result;
        for (string &word : words)
        {
            string temp = "";
            for (char &letter : word)
            {
                temp += morse[letter - 'a'];
            }
            result.insert(temp);
        }
        return result.size();
    }
};

// Simple make use of unordered_set as it stores unique values only
// Time Complexity - O(S), S is the sum of lengths of words in 'words' as
// we iterate each and every word in words
// Space Complexity - O(S)