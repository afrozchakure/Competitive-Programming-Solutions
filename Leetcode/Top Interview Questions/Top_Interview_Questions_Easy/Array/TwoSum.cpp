// M-1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> s; // empty map container 
        int diff = 0;
        vector <int> result;
        for(int i=0; i<nums.size(); i++)
        {
            diff = target-nums[i];
            if(s.find(diff) != s.end()){
                result.push_back(i);
                result.push_back(s[diff]);
                return result;         
            }
            else
                s[nums[i]] = i;   // s[nums] , <value in list, i is position>
        }
        return result; 
    }
};


// Time Complexity - O(n)
// Space Complexity - O(n)

// M-2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++)    
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j] == target - nums[i])
                    return {i, j};
            }
        return {};
    }
};

// Time Complexity - O(n^2)
// Space Complexity - O(1)

