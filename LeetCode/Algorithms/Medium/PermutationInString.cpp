class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(); 
        int n = s2.size(); 

        if(m > n) return false; 

        vector<int> s1_vec(26, 0); 

        for(auto c: s1) {
            s1_vec[c - 'a']++; 
        }

        vector<int> s2_vec(26, 0); 

        int left = 0, right = 0; 

        while(right < n) {
            s2_vec[s2[right] - 'a']++; 
            if((right - left + 1) == m) {
                if(s1_vec == s2_vec) {
                    return true; 
                }
            }

            if((right - left + 1) < m) {
                right++; 
            } else {
                s2_vec[s2[left] - 'a']--; 
                left++; 
                right++; 
            }
        }        
        return false; 
    }
};