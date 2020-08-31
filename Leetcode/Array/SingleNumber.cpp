/*-------------Using XOR Operation------------------------*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for(int i=0; i<nums.size(); i++)
            a = a^nums[i];
        return a;
    }
};

// Time Complexity - O(1) (Using XOR operation - a xor a xor b => 0 xor b => b)
// Space Complexity - O(1)

/*-------------Using Unordered Set iterator format--------*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set <int> s;
        for(int i=0; i<nums.size(); i++)  // 4 - 0,1,2,3
            s.insert(nums[i]);
        unordered_set<int> :: iterator itr;
        for(itr=s.begin(); itr!=s.end(); itr++) 
            if(count(nums.begin(), nums.end(), *itr) == 1) 
                return *itr;  
        return 0;
    }
};

// Time Complexity - O(n) (Time complexity of unordered set - O(1))
// Space Complexity - O(n)


