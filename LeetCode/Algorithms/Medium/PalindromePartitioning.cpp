class Solution {
public:
    vector<vector<string>> result; 
    vector<string> part;     
    vector<vector<string>> partition(string s) {
        dfs(0, s); 
        return result; 
    }

    void dfs(int i, string s) {
        if(i >= s.size()) {
            result.push_back(part); 
            return; 
        } 
        for(int j=i; j<s.size(); j++) {
            if(isPali(s, i, j)) {
                part.push_back(s.substr(i, j + 1 - i)); 
                dfs(j + 1, s); 
                part.pop_back(); 
            }
        }
    }

    bool isPali(string s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) {
                return false; 
            }
            left = left + 1; 
            right = right - 1; 
        }
        return true; 
    }
};