class Solution {
public:
    int ans = 0; 

    // return the count if the row is covered meaning all values are 0
    int covered(vector<vector<int>> &mat) {
        int count = 0; 

        for(int i=0; i<mat.size(); i++) {
            int flag = 1; 
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j] == 1) {
                    flag = 0; 
                }
                if(flag) {
                    count++; 
                }
            }
        }
        return count; 
    }

    int solver(vector<vector<int>>& mat, int col, int i) {
        if(i == mat[0].size() || col == 0) {
            int c = covered(mat); 
            ans = max(ans, c); 
            return c; 
        } 

        // select 
        int x = solver(mat, col, i+1); 
        vector<vector<int>> cmat = mat; 
        // If selected set all values in the column as 0 
        for(int j=0; j<cmat.size(); j++) {
            cmat[j][i] = 0; 
        }
        // now decrement the value of column col and increment the pointer i for col
        int y = solver(cmat, col-1, i+1); 

        return max(x, y); 
    }

    int maximumRows(vector<vector<int>>& mat, int cols) {
        solver(mat, cols, 0); 
        return ans; 
    }
};
