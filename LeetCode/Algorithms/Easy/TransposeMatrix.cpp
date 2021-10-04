class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {
        int rows = A.size();
        int cols = A[0].size();
        vector < vector<int> result(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i != j)
                {
                    result[j][i] = A[i][j];
                }

                result[i][j] = result[i][j];
            }
        }
        return result;
    }
};

// Time Complexity - O(R x C), where R is the no. of rows
// C is the number of columns
// Space Complexity - O(R x C)