// Method - 1 (follow method 1 -> it is intuitive)
class NumMatrix {
public:
    vector<vector<int>> result; 
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix.size() == 0) return; 
        
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        
        // 1st adding the respective columsn 
        for(int i=0; i<m; i++) {
            for(int j=1; j<n; j++) {
                matrix[i][j] += matrix[i][j-1]; 
            }
        }
        
        // then adding the rows
        for(int i=1; i<m; i++) {
            for(int j=0; j<n; j++) {
                matrix[i][j] += matrix[i-1][j];
            }
        }
        result = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = result[row2][col2]; 

        // these conditions when col1 or row1 is 0 is important
        int extra = (col1!=0 ? result[row2][col1-1]: 0) + (row1!=0 ? result[row1-1][col2]: 0) - ((row1 != 0 && col1 != 0) ? result[row1-1][col1-1] : 0); 
        return total - extra;
    }
};

// Time Complexity - O(M * N) 
// Space Complexity - O(N)

// Method 2 
- Refer Algorithms Made easy solution for the problem
- Time Complexity (Constructor) - O(N x M) 
- Space Complexity (Per query) - O(1)
class NumMatrix {
public:
    vector<vector<int>> result; 
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix.size() == 0) return; 
        
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        
        // declare a matrix with 1 size greater than the row and column
        result = vector<vector<int>>(m + 1, vector<int>(n + 1)); 
        
        // creating result matrix  -> This is key the matrix shoudl iterate from i=1 and j=1
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {	
                // here apply the same principle as sumRegion 
                // Add the top and left values and subtract the top left value since it has been included twice and add the matrix values for [i-1] and [j-1]
                result[i][j] = - result[i-1][j-1] + result[i-1][j] + result[i][j-1] + matrix[i-1][j-1]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // increasing the rows and cols by 1 is important since result matrix is 1 size bigger than matrix
        row1++; col1++; row2++; col2++; 
        
        int total = result[row2][col2]; 
        int extra = result[row2][col1-1] + result[row1-1][col2] - result[row1-1][col1-1]; 
        return total - extra;
    }
};