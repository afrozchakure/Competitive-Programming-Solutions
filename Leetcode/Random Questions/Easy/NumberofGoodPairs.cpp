// Method - 1 (a)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        int cnt[101] = {};  // Storing all the duplicates in array
        
        // Counting the duplicated pairs
        for(int i=0; i<nums.size(); i++)
        {
            result += cnt[nums[i]]++;
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)

// Method 1 (b)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        int cnt[101] = {};  // Storing all the duplicates in array
        
        // Counting the duplicated pairs
        for(int i=0; i<nums.size(); i++)
        {
            cnt[nums[i]]++;
        }
        for(int i=0; i<101; i++)
        {
            result += (cnt[i]*(cnt[i]-1))/2;
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)

// Method - 2
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size()-1; i++)
            for(int j=i+1; j<nums.size();j++)
            {
                if(nums[j] == nums[i])
                    count += 1;
            }
        return count;
    }
};

// Time Complexity - O(n^2)
// Space Complexity - O(1)
