class Solution
{
public:
    bool validPalindrome(string s)
    {
        int start_pointer = 0;
        int end_pointer = s.size() - 1;
        while (start_pointer <= end_pointer)
        {
            if (s[start_pointer] != s[end_pointer])
            {
                return helperMethod(s, start_pointer + 1, end_pointer) || helperMethod(s, start_pointer, end_pointer - 1);
            }
            start_pointer++;
            end_pointer--;
        }
        return true;
    }
    bool helperMethod(string s, int i, int j)
    {
        int start_pointer = i;
        int end_pointer = j;
        while (start_pointer <= end_pointer)
        {
            if (s[start_pointer] != s[end_pointer])
            {
                return false;
            }
            start_pointer++;
            end_pointer--;
        }
        return true;
    }
};

// Time Complexity - O(n), n is the length of the string
// since we iterate over the string only when elements don't match,
// it is a O(n) time complexity problem
// Space Complexity - O(n)