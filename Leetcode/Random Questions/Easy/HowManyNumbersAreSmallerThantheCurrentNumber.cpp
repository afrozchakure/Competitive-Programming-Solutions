// Method - 1
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector <int> freq(101, 0);
        vector <int> pref(101, 0);
        // Calculating frequency of all elements of array
        for(auto &val: nums){
            freq[val] += 1;  // 8 - 1
        }
        
        // Take prefix sum of frequency array and frequency array 
        // will tell us how many elements are less than that in nums array
        for(int j=1; j<101; j++){
            pref[j] = pref[j-1] + freq[j-1];
        }
        int n = nums.size();
        vector <int> result(n);
        for(int i=0; i<n; i++)
        {
            result[i] = pref[nums[i]];  
        }
            
        return result;
    }
};
// Time Complexity - O(n)
// Space Complexity - O(n)

// Method - 2
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++)
        {
            int count = 0;
            for(int j=0; j<nums.size(); j++)
            {
                if(nums[j] < nums[i])
                {
                    count++;
                }
            }
            result.push_back(count);
        }
            
          return result;      
    }
};

// Time Complexity - O(n^2)
// Space Complexity - O(n)
