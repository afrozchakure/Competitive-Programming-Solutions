class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n= s.size();
        vector<int> dp_s(n+1, 0);
        
        dp_s[n] = 1;
        
        for(int i=n-1; i>=0; i--)
        {
            for(string &w: wordDict)
            {
                if((i + w.size()) <= s.size() && s.substr(i, w.size()) == w)
                {
                    cout<<w<<" "<<endl;
                    dp_s[i] = dp_s[i + w.size()];
                }
                if(dp_s[i])
                    break;
            }
        }
        
        return dp_s[0];
        
    }
};

// Time Complexity - O(N * M * N), since the maximum length of word in wordDict can be N
// Space Complexity - O(N)

// N - size of string s 
// M - size of wordDict
