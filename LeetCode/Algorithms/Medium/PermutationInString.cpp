class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(); 
        int n = s2.size(); 

        if(m > n) return false; 

        vector<int> s1_vec(26, 0); 

        for(auto c: s1) {
            s1_vec(c - 'a')++; 
        }
        
        vector<int> s2_vec(26, 0); 

        int left = 0, right = 0; 

        while(right < n) {

            if((right - left + 1) < m) {

            }
        }        
    }
};