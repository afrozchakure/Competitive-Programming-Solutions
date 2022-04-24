class Solution {
public:
    int longestPalindrome(string s) {
        
        vector<int> count(128, 0); 
        for(char a: s)
        {
            count[a]++; 
        }
        int ans = 0; 
        for(int a: count)
        {
            if(a % 2 == 0)
            {
                ans += a; 
            }
            else if(a % 2 == 1 && a > 1)
            {
                ans += a -1; 
            }
        }
        
        if(ans < s.size())
        {
            ans +=1; 
        }
        
        return ans; 
        // 97 - 122  - a - z 
        // 65 - 90 - 'A' - 'Z'
            
        
    }
};