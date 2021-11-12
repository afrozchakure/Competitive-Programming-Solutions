// Method - 1 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(); 
        
        int max_length = 0;
        int l = 0; 
        
        unordered_set<int> mySet; 
        for(int r=0; r<n; r++)
        {
            while(mySet.find(s[r]) != mySet.end())
            {
                mySet.erase(s[l]); 
                l++;
            }
            max_length = max(max_length, r - l + 1); 
            mySet.insert(s[r]); 
        }
        return max_length;
    }
};
// Time Complexity - O(N), It will iterate N times to get the result
// Space Complexity - O(N), since we're using an unordered_set

// Method - 2
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
