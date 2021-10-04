// Iterative Solution

class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        int j = S.size() - 1;
        string result = "";
        for (int i = 0; i < S.size(); i++)
        {
            // When the element is alphanumeric
            if (isalpha(S[i]))
            {
                // Continue the loop till we find an alnumeric character
                while (!isalpha(S[j]))
                {
                    j--;
                }
                result += S[j];
                j--;
            }

            // When the element is not an alphanumeric element
            else
            {
                result += S[i];
            }
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)

// Using Stack
class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        stack<char> s;

        for (int i = 0; i < S.size(); i++)
        {
            if (isalpha(S[i]))
                s.push(S[i]);
        }

        string result = "";
        for (int i = 0; i < S.size(); i++)
        {
            if (!isalpha(S[i]))
            {
                result += S[i];
            }
            else
            {
                char temp = s.top();
                s.pop();
                result += temp;
            }
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)