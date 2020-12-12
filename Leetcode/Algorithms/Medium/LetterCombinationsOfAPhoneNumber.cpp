#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return vector<string>{};

        vector<string> mapping = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> result;

        letterCombinationsRecursive(result, digits, "", 0, mapping);

        return result;
    }

    void letterCombinationsRecursive(vector<string> &result, string digits, string current, int index, vector<string> &mapping)
    {
        if (digits.size() == index)
        {
            result.push_back(current);
            return;
        }

        string letter = mapping[digits[index] - '0'];
        for (int i = 0; i < letter.size(); i++)
        {
            letterCombinationsRecursive(result, digits, current + letter[i], index + 1, mapping);
        }
    }
};

// Time Complexity - O(3**N x 3**M), where N is the number of digits in
// the input that maps to 3 letters (2, 3, 4, 5, 6, 8) and M is the number of digits
// that in the input that maps to 4 letters (7, 9), and N + M is the total number digits in the input
// Space Complexity - O(3**N x 4**M) since on has to keep 3**N x 4**M solution

// Refer Kevin Naughton Jr's Video