class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int count = 0;
        int result_count = 0;
        for (char &c : s)
        {
            if (c == 'R')
                count += 1;
            else if (c == 'L')
                count -= 1;

            if (count == 0)
                result_count += 1;
        }
        return result_count;
    }
};

// Time complexity - O(N), N is the number of letters in string s
// Space Complexity - O(1)