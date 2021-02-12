class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        int a[26] = {};
        for (int i = 0; i < s.size(); i++)
        {
            a[s[i] % 26]++;
            a[t[i] % 26]--;
        }
        for (int i = 0; i < 26; i++) // It will iterate till it checks the 26 values in the array
            if (a[i] != 0)
                return false;
        return true;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)

// Using Sort
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(t.begin(), t.end());
        sort(s.begin(), s.end());
        return s == t;
    }
};

// Time Complexity - O(nlogn)
// Space Complexity - O(1)
