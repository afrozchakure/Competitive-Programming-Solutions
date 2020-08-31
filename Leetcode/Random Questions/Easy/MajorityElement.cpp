class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, res;
        for(int i=0; i<nums.size(); i++)
        {
            if(cnt == 0) res = nums[i];
            if(res == nums[i]) ++cnt;
            else --cnt;
        }
        return res;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int, int> s;
        for(int i=0; i<nums.size(); i++)
        {
            s[nums[i]] += 1;
        }
        int count = 0;
        int value = 0;
        for(auto x: s)
            if(count < x.second)
            {
                count = x.second;
                value = x.first;
            }
        return value;
        
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
        
    }
};

// Time Complexity - O(nlogn)
// Space Complexity - O(1)
