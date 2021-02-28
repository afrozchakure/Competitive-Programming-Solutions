class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<vector<int>> myVector;

        vector<int> result;

        for (int i = 0; i < mat.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 1)
                    sum += 1;
            }
            myVector.push_back({sum, i});
        }

        sort(myVector.begin(), myVector.end());

        for (auto element : myVector)
        {
            if (k--)
                result.push_back(element[1]);
            else
            {
                break;
            }
        }
        return result;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)