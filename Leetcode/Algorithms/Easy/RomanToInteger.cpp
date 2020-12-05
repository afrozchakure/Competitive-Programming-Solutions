#include <unordered_map>
class Solution
{
public:
    int romanToInt(string s)
    {
        // Pay attention because unordered_map doesn't have ":",
        // between key and value pairs
        unordered_map<char, int> symbols = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        int sum = symbols[s[s.size() - 1]];

        for (int i = s.size() - 2; i >= 0; i--)
        {
            // This step is important
            // remember we are comparing the values of characters from the
            // symbols map, not the actual values of those characters
            if (symbols[s[i]] < symbols[s[i + 1]])
                sum -= symbols[s[i]];
            else
                sum += symbols[s[i]];
        }
        return sum;
    }
};

// Here we iterate from the end of the unordered_map and see
// if the number to the left of it is has value less than it or not
// if it does, we subtract that value from our sum or else we add its value from the
// symbol map