class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        // 1 -> starting square 
        // 2 -> ending square 
        // 0 -> empty squares we can walk over 
        // -1 -> obstacles we cannot walk over 
        
        

    }
};

// 1. Count zeros that exist in the matrix 
// 2. If you see 0, reduce CountZero, update 0 with -1 
// 3. Make sure you have taken care of Visited condition 
// 4. Check the entire path again to see if all zero've been marked 
//     as -1.

