/*--By Sorting the vector and finding the element-------*/
#include<bits/stdc++.h>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {  // length = 4
        sort(nums.begin(), nums.end());  // Time taken - O(logn)
        for(int i=0; i<nums.size()-1; i++)  // 0, 1, 2, (Time taken - O(n))
            if(nums[i] == nums[i+1]) return true;
        return false;    
    }
};

// Time complexity - O(nlogn)
// Space Complexity - O(1)


/*-------------using Unordered Set----------------------*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> s;
        int n = nums.size();  // 4
        for(int i=0; i<n; i++){  // 3 - 0, 1, 2, 3
            s.insert(nums[i]);
        }
        if(s.size() != nums.size()) return true;
        return false;
    }
};

// Time complexity O(n)
// Space Complixity O(n)

