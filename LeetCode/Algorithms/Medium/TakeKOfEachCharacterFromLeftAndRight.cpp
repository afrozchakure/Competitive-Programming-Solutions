class Solution {
public:
    int takeCharacters(string s, int k) {
        // minimum no . of minutes to take atleast k of each character

        // total counts
        int a=0, b=0, c =0; 
        int n = s.size(); 
        for(auto &ch: s) {
            if(ch == 'a') a++; 
            if(ch == 'b') b++; 
            if(ch == 'c') c++; 
        }

        if(min(a, min(b, c)) < k) {
            return -1; 
        }

        // Sliding Window 
        int l=0;
        int result = 0;
        int ans = INT_MAX;
        for(int r=0; r<s.size(); r++) {
            if(s[r] == 'a') a--; 
            if(s[r] == 'b') b--;  
            if(s[r] == 'c') c--; 

            while(min(a, min(b, c)) < k) {
                if(s[l] == 'a') a++; 
                if(s[l] == 'b') b++; 
                if(s[l] == 'c') c++; 
                l++; 
            }

            ans = min(ans, n - (r - l + 1));
        }
        return ans;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)