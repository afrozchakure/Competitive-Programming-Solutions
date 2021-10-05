class Solution {
    public boolean isValidSudoku(char[][] board) {
        HashSet<String> seen = new HashSet();

        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                char current_val = board[i][j];

                if(char != '.')
                {
                    if(!seen.add(current_val + " found in row " + i) ||
                    !seen.add(current_val + " found in column " + j) ||
                    !seen.add(current_val + " found in sub box " + i/3 + "." + j/3)) return false;
                }
            }
        }
        return true;
    }
}

// Time Complexity - O(1)
// Space Complexity - O(1)