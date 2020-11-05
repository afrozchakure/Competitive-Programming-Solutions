class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int left = s.size() - 1;
        int result = 0;

        // The loop will contine till will find the first NonSpace Character
        while (left >= 0 && s[left] == ' ')
            left--;

        // This will continue till we find the next space character
        //
        while (left >= 0 && s[left] != ' ')
        {
            result++;
            left--;
        }
        return result;
    }
};

// Time Complexity - O(n), if all the characters are ' ' spaces
// Space Complexity - O(1), constant space