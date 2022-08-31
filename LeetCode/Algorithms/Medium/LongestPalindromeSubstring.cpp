// Brute Force - 

// babad 
// the time complexity for scanning the entire string will be O(N) and for checking for each substring will be O(N**2) 
// hence total time complexity will be O(N**3)

// O(N**2) time complexity solution  -- Neetcode solution (Better solution)
class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size(); 
        string res = ""; 
        int resLen = 0; 
        for(int i=0; i<n; i++) {
            int start = i; 
            int end = i; 
            while(start >= 0 && end < n && s[start] == s[end]) {
                if(end - start + 1 > resLen) {
                    res = s.substr(start, end-start+1); 
                    resLen = end-start + 1; 
                }
                start--; 
                end++; 
            }
            
            // odd case 
            start = i; 
            end = i+1; 
            while(start >= 0 && end < n && s[start] == s[end]) {
                if(end - start + 1 > resLen) {
                    res = s.substr(start, end - start + 1); 
                    resLen = end - start + 1; 
                }
                start--; 
                end++; 
            }
        }
        return res;
    }
};

// O(N) time complexity solution  - Nick White's solution
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

// Time Complexity - O(N**2)
// Space Complexity - O(1)