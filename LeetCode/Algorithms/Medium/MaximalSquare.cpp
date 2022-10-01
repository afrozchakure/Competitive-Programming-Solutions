// Think of repeated work or subproblems 

// we create cache for the subproblems 

// down -> diagonally -> right 

// cache - square-length 

// maxArea = 2 * 2 

// Time complexity - O(m * n) 
// dynamic programming - bottom up 

// recursive: top down  - Solved by Neetcode 

class Solution {
public:
    map<pair<int, int>, int> cache; 
    int rows, cols; 
    int maximalSquare(vector<vector<char>>& matrix) {
        rows = matrix.size(); 
        cols = matrix[0].size(); 
        // int cache = {} // map each (r, c) -> maxLength of square 
        // map<int, int> cache; 
        helper(0, 0, matrix); 

        int result = 0; 
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) { 
                result = max(result, cache[make_pair(i, j)]); 
            }
        }

        return pow(result, 2); 
    }
    int helper(int r, int c, vector<vector<char>> &matrix) {
        if(r >= rows || c >= cols) {
            return 0; 
        }

        if(cache.find(make_pair(r, c)) == cache.end()) {
            int down = helper(r + 1, c, matrix); 
            int right = helper(r, c+1, matrix); 
            int diagonal = helper(r+1, c+1, matrix); 

            cache[make_pair(r, c)] = 0; 
            if(matrix[r][c]== '1') {
                cache[make_pair(r, c)] = 1 + min(down, min(right, diagonal)); 
            }
        }
        return cache[make_pair(r, c)]; 
    }
};


