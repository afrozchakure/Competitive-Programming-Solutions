class Solution {
public:
    int maxPower(string s) {
        if(s.size() == 1)
            return 1;
        
        int max_count = 1;
        int count = 1;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == s[i+1])
                count++;
            if(count > max_count)
                max_count = count;
            if(s[i] != s[i+1])
                count = 1;
        }
        return max_count;
    }
};
// Time Complexity - O(N), N is the number of characters in the string
// Space Complexity - O(1), constant space
