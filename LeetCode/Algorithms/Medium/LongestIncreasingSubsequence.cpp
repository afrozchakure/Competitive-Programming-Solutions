class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        
        for(int i=n-1; i >= 0; i--)
        {
            for(int j=i+1; j < n; j++)
            {
                if(nums[i] < nums[j])
                {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
            }
        }
        return *max_element(lis.begin(), lis.end());
    }
};

// Time Complexity - O(N**2)
// Space Complexity - O(N), we require a vector of size n

// NeetCoding video

// Using for loop to find max element
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> lis(n, 1);
        for(int i=n-1; i >= 0; i--)
        {
            for(int j=i+1; j < n; j++)
            {
                if(nums[i] < nums[j])
                {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
            }
        }
        
        int result = INT_MIN;
        for(int &i: lis)
        {
            result = max(i, result);
        }
        // return *max_element(lis.begin(), lis.end());
        return result;
    }
};

// Time Complexity - O(N**2) 
// Space Complexity - O(N)
