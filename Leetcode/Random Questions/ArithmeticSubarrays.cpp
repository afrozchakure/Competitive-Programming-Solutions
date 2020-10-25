// Brute Force Approach

class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &v, vector<int> &l, vector<int> &r)
    {
        int n = l.size();
        vector<bool> result;

        for (int i = 0; i < n; ++i)
        {
            int right = r[i];
            int left = l[i];
            vector<int> temp;
            for (int j = left; j <= right; ++j)
            {
                temp.push_back(v[j]);
            }
            sort(temp.begin(), temp.end());
            int diff = v[1] - v[0];
            int size_temp = temp.size();
            bool flag = 0;
            for (int j = 1; j < size_temp - 1; j++)
            {
                int val = temp[i + 1] - temp[i];
                if (val != diff)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                result.push_back(false);
            else
                result.push_back(true);
        }
        return result;
    }
};

// Time Complexity - O(M*N) where M is the size of l and r and N is maximum len of temp which can be N
// Space Complexity - O(m) - len of resulting vector