class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {

        if (n == 0)
            return vector<vector<int>>{{}};

        int row_start = 0;
        int row_end = n - 1;

        int col_start = 0;
        int col_end = n - 1;

        // We need to define a 2d vector with all the elements
        // equal to 0
        vector<vector<int>> result(n, vector<int>(n, 0));

        int cnt = 1;
        while (col_start <= col_end && row_start <= row_end && cnt <= (n * n))
        {
            for (int i = col_start; i <= col_end; i++)
            {
                result[row_start][i] = cnt++;
            }

            row_start++;

            for (int i = row_start; i <= row_end; i++)
            {
                result[i][col_end] = cnt++;
            }

            col_end--;

            if (row_start <= row_end)
            {
                for (int i = col_end; i >= col_start; i--)
                    result[row_end][i] = cnt++;
            }

            row_end--;

            if (col_start <= col_end)
            {
                for (int i = row_end; i >= row_start; i--)
                    result[i][col_start] = cnt++;
            }

            col_start++;
        }

        return result;
    }
};

// Time Complexity - O(n*n), where n is the length of one side of matrix
// Space Complextiy - O(1)