class Solution {
public:

    vector<string> result; 
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> curr; 
        dfs(0, s, wordDict, curr);       

        return result; 
    }

    void dfs(int index, string s, vector<string> &wordDict, vector<string> &curr) {
        if(index = s.size()) {
            string sub = ""; 
            for(int i=0; i<curr.size(); i++) {
                sub += " " + curr; 
                break;
            }
            result.push_back(curr); 
        }

        for(int j=index; j<s.size(); j++) {
            string w = s.substr(index, j + 1 - index); 
            
            for(auto &ele: wordDict) {
                if(ele == w) {
                    curr.push_back(w); 
                    backtrack(j + 1); 
                    curr.pop(); 
                }
            }
        }
    }


};