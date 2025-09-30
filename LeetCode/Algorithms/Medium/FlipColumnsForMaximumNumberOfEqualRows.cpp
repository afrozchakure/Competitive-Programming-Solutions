class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> m; 
        int count = 0; 
        for(auto &mat: matrix) {
            string s = "";
            for(auto &ele: mat) {
                s += to_string(ele); 
            }

            if(s[0] == '1') {
                for(int i=0; i<s.size(); i++) {
                    if(s[i] == '0') {
                        s[i] = '1';
                    } else {
                        s[i] = '0';
                    }
                }
            }

            m[s] += 1; 
        }

        for(auto &ele: m) {
            count = max(count, ele.second); 
        }
        return count; 
    }
};