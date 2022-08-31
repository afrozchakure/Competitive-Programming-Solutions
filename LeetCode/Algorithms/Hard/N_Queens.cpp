// Method - 1 (Not optimized)
class Solution {
public:

    bool isSafe(int row, int col, vector<string> &board, int n) {
        int localrow = row; 
        int localcol = col; 

        // first check diagonally top left 
        while(localcol >= 0 && localrow >= 0) {
            if(board[localrow][localcol] == 'Q') return false; 
            localcol--; 
            localrow--; 
        }

        localrow = row; 
        localcol = col; 

        // check left value 
        while(localcol >= 0) {
            if(board[localrow][localcol] == 'Q') return false; 
            localcol--; 
        }

        localrow = row; 
        localcol = col; 
        // check bottom left 
        while(localrow < n && localcol >= 0) {
            if(board[localrow][localcol] == 'Q') return false; 
            localcol--; 
            localrow++; 
        }

        return true; 
    }

    void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n) {
        if(col == n) {
            ans.push_back(board); 
            return;
        }

        for(int row=0; row<n; row++) {
            if(isSafe(row, col, board, n)) {
                board[i][col] = 'Q'; 
                solve(col+1, ans, board, n); 
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);

        string s(n, '.'); 

        for(int i=0; i<n; i++) {
            board[i] = s; 
        }

        solve(0, ans, board, n); 
        return ans; 
    }
};

// Time Complexity - O(N*(N + N + N))


// Optimized solution 
// In this solution to optimize the finding of Queen in left, lowerDiagonal and UpperDiagonal, we will use hashing
// for the left diagonal setting left[row] = 1 is okay, while for lowerDiagonal it should be lowerDiagonal[row + col]
// And for upperDiagonal it is [n-1 + col - row] and the size of lowerDiagonal and upperDiagonal is (2 * n - 1)
// Try to remember the formula for both
class Solution {
public:

    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal) {
        if(n == col) {
            ans.push_back(ans); 
            return;
        }

        for(int row=0; row<n; row++) {
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1; 
                lowerDiagonal[row + col] = 1; 
                upperDiagonal[n - 1 + col - row] = 1; 
                solve(col + 1, n, board, ans, leftRow, lowerDiagonal, upperDiagonal);
                board[row][col] = '.';
                leftRow[row] = 0; 
                lowerDiagonal[row + col] = 0; 
                upperDiagonal[n - 1 + col - row] = 0; 
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);       

        string s(n, '.'); 

        for(int i=0; i<n; i++) {
            board[i] = s;
        }

        vector<int> leftRow(n, 0), lowerDiagonal(2*n - 1, 0), upperDiagonal(2 * n - 1, 0); 

        solve(0, n, board, ans, leftRow, lowerDiagonal, upperDiagonal);
        return ans;
    }
};