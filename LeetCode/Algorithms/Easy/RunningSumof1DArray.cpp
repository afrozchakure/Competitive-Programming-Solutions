// Method - 1
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
        {
            if(i==0)
                continue;
            else
                nums[i] = nums[i-1] + nums[i];
        }
            
        return nums;
    }
};
// Time Complexity - O(n)
// Space Complexity - O(1)

// Method - 2
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            int sum = 0;
            for(int j=0; j<i+1; j++)
            {
               sum += nums[j];
            }
            result.push_back(sum);
        }
        return result;
    }
};

// Time Complexity - O(n^2)
// Space Complexity - O(n)
