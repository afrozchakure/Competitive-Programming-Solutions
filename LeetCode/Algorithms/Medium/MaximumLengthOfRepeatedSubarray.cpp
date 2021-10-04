class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int myresult = 0;
        vector<vector<int>> result(m , vector<int>(n, 0));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(nums1[i] == nums2[j])
                {
                    if((i-1) >= 0 && (j -1) >= 0 && result[i-1][j-1] != 0)
                    {
                        result[i][j] = result[i-1][j-1] + 1;
                    }
                    else
                    {
                        result[i][j] = 1;
                    }
                    myresult = max(myresult, result[i][j]);
                }
            }
        }
        return myresult;
    }
};

// Time Complexity - O(N * M)
// Space Complexity - O(N * M)
