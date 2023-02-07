class Solution {
public:
    
    int maxLength(vector<string>& arr) {
        vector<string> ansList; 

        int ans = 0; 

        ansList.push_back(""); 
        for(auto &str: arr) {
            if(!checkUniqueCharString(str)) continue; 
            vector<string> newAnsListWithCurrStr; 
            for(string &candidate: ansList) {
                string temp = candidate + str; 
                if(checkUniqueCharString(temp)) {
                    newAnsListWithCurrStr.push_back(temp); 
                    ans = max(ans, temp.size()); 
                }
            }
            ansList.push_back(newAnsListWithCurrStr); 
        }
        return ans; 
    }

    bool checkUniqueCharString(String str) {
        if(str.size() > 26) return false; 
        vector<int> freq(26); 
        vector<char> arr(str.begin(), str.end()); 
        for(char ch: arr) {
            freq[ch - 'a']++; 
            if(freq[ch - 'a'] > 1) {
                return false; 
            }
        }
        return true; 
    }
};

// arr = ["un","iq","ue"]
// uniq -> all unique characters (so considered)
// unue -> not unique characters (so not considered) 

// leetcode -> here e is repeated and hence we need to ignore such strings 

