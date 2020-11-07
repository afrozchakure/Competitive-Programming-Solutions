class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int start = 0;
        int end = mat.size() - 1;
        int sum = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            if (start > (mat.size() - 1) && end < 0)
                break;
            sum += mat[start++][i];
            sum += mat[end--][i];
        }
        if (mat.size() % 2 != 0)
        {
            int mid = (mat.size() - 1) / 2;
            sum -= mat[mid][mid];
        }

        return sum;
    }
};