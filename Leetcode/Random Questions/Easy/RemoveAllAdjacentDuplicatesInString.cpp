class Solution
{
public:
    string removeDuplicates(string S)
    {
        int n = S.size();
        char stack[n];
        int i = 0;

        for (int j = 0; j < S.size(); j++)
        {
            char currentChar = S[j];
            if (i > 0 && currentChar == stack[i - 1])
            {
                i--;
            }
            else
            {
                stack[i] = currentChar;
                i++;
            }
        }
        string result = "";
        for (int j = 0; j < i; j++)
        {
            result += stack[j];
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)