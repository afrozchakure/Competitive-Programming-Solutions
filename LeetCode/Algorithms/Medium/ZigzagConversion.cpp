class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s; 

        string result = ""; 
        for(int r=0; r<numRows; r++) {
            int increment = 2 * (numRows - 1); 
            for(int i=r; i<s.size(); i += increment) {
                result += s[i]; 
                if(r > 0 && r < (numRows - 1) && ((i + increment) - (2 * r)) < s.size()) {
                    result += s[(i + increment) - (2 * r)]; 
                }
            }
        }
        return result; 
    }
};

// Time Complexity - O(N) 
// Space Complexity - O(1)