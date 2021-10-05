#include <algorithm>
#include <map>
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int a_pointer = 0;
        int b_pointer = 0;

        int result = 0;

        map<int, int> map;

        while (b_pointer < s.size())
        {
            if (map.find(s[b_pointer] - 'a') == map.end())
            {
                map[s[b_pointer] - 'a'] += 1;
                b_pointer++;
                result = max((int)map.size(), result);
            }
            else
            {
                map.erase(s[a_pointer] - 'a');
                a_pointer++;
            }
        }
        return result;
    }
};

// Time Complexity : O(2n) -> O(n)
// Worst Case Each Character will be visited twice by a_pointer and b_pointer
// Space Complexity - O(26)
