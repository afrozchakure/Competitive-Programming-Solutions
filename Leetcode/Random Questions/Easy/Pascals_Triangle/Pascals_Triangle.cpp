class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        
        for(int i=0; i<numRows; i++)
        {
            res[i].resize(i+1);
            res[i][0] = res[i][i] = 1;
            for(int j=1; j < i; j++)
            {
            // Addition of up (i-1)(j) and corner (i-1)(j-1)
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};

// Time Complexity - O(n**2)
// Space Complexity - O(n)


// [1]
// [1,1]
// [1,2,1]
// [1,3,3,1]
// [1,4,6,4,1]
