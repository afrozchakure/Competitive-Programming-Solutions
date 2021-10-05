class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        
        int count = 1;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == s[i+1] && count != 2)
            {
                result += s[i];
                count++;
            }
            else if(s[i] != s[i+1])
            {
                result += s[i];
                count = 1;
            }
        }
        
        return result;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)
