class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s == "" || s.size() == 0)
            return s;

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int len1 = expandFromMiddle(s, i, i);     // this is the case like "racecar", with e in the middle
            int len2 = expandFromMiddle(s, i, i + 1); // this is the case where every element has a match like "aabba"
            int len = max(len1, len2);

            if (len > end - start)
            {
                start = i - ((len - 1) / 2); // Its reseting our start and end, so current index - (half of len)
                end = i + (len / 2);
            }
        }
        // cout << end - start;

        return s.substr(start, end - start + 1);
    }
    int expandFromMiddle(string s, int left, int right)
    {
        if (s == "" || left > right)
            return 0;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return right - left - 1;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)